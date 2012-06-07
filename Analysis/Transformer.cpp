#include <map>
#include <iostream>
#include <cstdio>
using namespace std;

#include <clang/Basic/SourceManager.h>
#include <clang/Analysis/Visitors/CFGRecStmtDeclVisitor.h>
#include <clang/AST/DeclVisitor.h>
#include <clang/Analysis/AnalysisDiagnostic.h>
#include <clang/AST/ASTContext.h>
#include <clang/Analysis/FlowSensitive/DataflowSolver.h>
#include <llvm/ADT/SmallPtrSet.h>
using namespace clang;

#include "Transformer.h" 
#include "../Defines.h"
#include "../Utils.h"
using namespace differential;

#define DEBUGCons   0
#define DEBUGExp    0
#define DEBUGGuard  0

//===----------------------------------------------------------------------===//
// Dataflow initialization logic.
//===----------------------------------------------------------------------===//
/*
namespace {
 
    class RegisterDecls : public CFGRecStmtDeclVisitor<RegisterDecls> {

        APAbstractDomain::AnalysisDataTy& AD;
    public:
        RegisterDecls(APAbstractDomain::AnalysisDataTy& ad) :  AD(ad) {
        }

        void VisitVarDecl(VarDecl* VD) {
            AD.Register(VD);
        }
        CFG& getCFG() {
            return AD.getCFG();
        }
    };

} // end anonymous namespace 

void APAbstractDomain::InitializeValues(const CFG& cfg) {
    RegisterDecls R(getAnalysisData());
    cfg.VisitBlockStmts(R);
}
*/ 
 
//===----------------------------------------------------------------------===//
// Transfer functions.
//===----------------------------------------------------------------------===//

namespace {


    struct Expression {
        texpr1 * expression_ptr;
        Expression(): expression_ptr(0) {
            expression_ptr = new texpr1(texpr1::builder(environment(),top()));
        }
        Expression(const Expression& expression) : expression_ptr(0) {
            if ( expression.expression_ptr ) expression_ptr = new texpr1(*expression.expression_ptr);
        }
        Expression& operator=(const Expression& expression_or_constraint) {
            expression_ptr = (expression_or_constraint.expression_ptr) ? new texpr1(*expression_or_constraint.expression_ptr) : 0;
            return *this;
        } 

        void setExpression(const texpr1& expression) {
            delete expression_ptr; 
            expression_ptr = new texpr1(expression);
        }

        operator texpr1() {
            return *expression_ptr;
        }

        friend ostream& operator<<(ostream& os, const Expression& expression);
        ~Expression() {
            delete expression_ptr;
        }
    };

    ostream& operator<<(ostream& os, const Expression& expression) {
        os << "{";
        if ( expression.expression_ptr ) os << *expression.expression_ptr;
        os << "}\n";
        return os;
    }

    class TransferFuncs : public CFGStmtVisitor<TransferFuncs,Expression> {

        typedef APAbstractDomain::ValTy::AbstractRefSet AbstractRefSet;

        APAbstractDomain::ValTy state_, nstate_; 
        APAbstractDomain::AnalysisDataTy& AD;
        map<Expr*,Expression> expr_map_;
        map<Expr*,pair<APAbstractDomain::ValTy,APAbstractDomain::ValTy> > state_map_;
        map<string,pair<APAbstractDomain::ValTy,APAbstractDomain::ValTy> > guard_map_;
        string current_guard_;
        bool report_;  

        Expression GetVarExpression(Expr* node, const QualType type, const string& name);
        Expression ApplyExpressionToState(BinaryOperator *node, const texpr1 &expression);
        void SetGuard(const set<abstract1> &expr_abs, const set<abstract1> &neg_expr_abs);
        void AssumeTagEquivalence(string name);
        void AssumeGuardEquivalence(string name);

    public:

        TransferFuncs(APAbstractDomain::AnalysisDataTy& ad, bool reportResults = false) : AD(ad), report_(reportResults), current_guard_("") {
        }

        APAbstractDomain::ValTy& getVal() {
            return state_;
        }
        APAbstractDomain::ValTy& getNVal() {
            return nstate_;
        }

        CFG& getCFG() {
            return AD.getCFG();
        }

        void SetTopValue(APAbstractDomain::ValTy& V) {
            V.setValues(AD);
        }

        typedef CFGStmtVisitor<TransferFuncs,Expression> BaseStmtVisitor;

        using BaseStmtVisitor::Visit;


        Expression VisitDeclRefExpr(DeclRefExpr* node);
        Expression VisitBinaryOperator(BinaryOperator* node);
        Expression VisitUnaryOperator(UnaryOperator* node);
        Expression VisitDeclStmt(DeclStmt* node);
        Expression VisitIntegerLiteral(IntegerLiteral * node);
        Expression VisitImplicitCastExpr(ImplicitCastExpr * node);
        Expression VisitArraySubscriptExpr(ArraySubscriptExpr *node);
        Expression VisitReturnStmt(ReturnStmt * node);
        Expression VisitCallExpr(CallExpr * node);
        Expression VisitMemberExpr(MemberExpr * node);
        void VisitTerminator(CFGBlock* node) { } 
        
    };

    void TransferFuncs::AssumeTagEquivalence(string name){
        environment &env = state_.env;
        string tagged_name;
        Utils::Names(name,tagged_name);
        var v(name),v_tag(tagged_name);
        if ( !env.contains(v) )
            env = env.add(&v,1,0,0);
        if ( !env.contains(v_tag) )
            env = env.add(&v_tag,1,0,0);
        tcons1 equal_cons(texpr1(env,v) == texpr1(env,v_tag));
        state_ &= equal_cons;
        nstate_ &= equal_cons;
        
    }

    /// forget all guard information and assume equivalence.
    void TransferFuncs::AssumeGuardEquivalence(string name){
        environment &env = state_.env;
        string tagged_name;
        Utils::Names(name,tagged_name);
        var v(name),v_tag(tagged_name);
        if ( !env.contains(v) )
            env = env.add(&v,1,0,0);
        if ( !env.contains(v_tag) )
            env = env.add(&v_tag,1,0,0);
        tcons1 equal_cons(texpr1(env,v) == texpr1(env,v_tag));

        state_.Forget(name);
        state_.Forget(tagged_name);
        nstate_.Forget(name);
        nstate_.Forget(tagged_name);

        state_ &= equal_cons;
        nstate_ &= equal_cons;
    }
 
    Expression TransferFuncs::GetVarExpression(Expr* node, const QualType type, const string& name) {
        Expression result;
        if ( type.getTypePtr()->isIntegerType() && type.getAsString() != Defines::kGuardType ) { // Don't track the guard variables
            var variable(name);
            
            environment& env = state_.env;
            if ( !env.contains(variable) ) { 
                // if the variables is not already in the environment, add it
                env = env.add(&variable,1,0,0);
                // and assume equality to its tagged\untagged version
                //AssumeTagEquivalence(name);
            }
            result.setExpression(texpr1(env,variable));
            texpr1 var_expr(env,variable);
            set<abstract1> as; 
            as.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,var_expr > AnalysisUtils::kZero));
            if ( type->isSignedIntegerType() ) { // only signed integers need the < 0 constraint
                as.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,var_expr < AnalysisUtils::kZero));
            }

            state_map_[node].first = state_;
            state_map_[node].first.Assume(as);
            state_map_[node].second = state_;
            state_map_[node].second &= AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,var_expr == AnalysisUtils::kZero);
        }
        return result;
    }

    Expression TransferFuncs::VisitDeclRefExpr(DeclRefExpr* node) {
        Expression result;
        if ( VarDecl* decl = dyn_cast<VarDecl>(node->getDecl()) ) {
            string type = decl->getType().getAsString(), name = decl->getNameAsString();
            result = GetVarExpression(node, decl->getType(), name);
            if ( type == Defines::kGuardType &&
                 name.find(Defines::kRetGuard) == name.npos ) { // don't treat Ret flags as guards.
                var guard(name);
                environment& env = state_.env;
                if ( !env.contains(guard) ) 
                    env = env.add(&guard,1,0,0);
                nstate_ = state_;
                state_ &= tcons1(texpr1(env,guard) == AnalysisUtils::kOne);
                //state_ &= guard_map_[name].first;
                nstate_ &= tcons1(texpr1(env,guard) == AnalysisUtils::kZero); 
                //nstate_ &= guard_map_[name].second;
                
#if (DEBUGGuard)
                cerr << "\n------\nEncountered: " << name << "->" << guard_map_[name].first << ", State = " << state_ << ", NState = " << nstate_ << "\n------\n"; 
#endif
            }
        }
        expr_map_[node] = result;
        return result;
    }

    Expression TransferFuncs::VisitMemberExpr(MemberExpr *node) {
        Expression result;
        if ( FieldDecl * FD = dyn_cast<FieldDecl>(node->getMemberDecl()) ) {
            Stmt::child_iterator I = node->child_begin();
            if ( ImplicitCastExpr * CE = dyn_cast<ImplicitCastExpr>(*I) )
                I = CE->child_begin();
            DeclRefExpr * DR = dyn_cast<DeclRefExpr>(*I);
            result = GetVarExpression(node, FD->getType(), DR->getDecl()->getNameAsString() + "." + FD->getNameAsString());
        }
        expr_map_[node] = result;
        return result;
    }

    Expression TransferFuncs::VisitCallExpr(CallExpr *node) {
        llvm::outs() << "Encountered function call: ";
        node->printPretty(llvm::outs(),AD.getContext(),0, PrintingPolicy(LangOptions()));
        llvm::outs() << ", all results regarding variables affected by this call are unsound.\n";
        /*
        for ( unsigned i = 0 ; i < node->getNumArgs(); i++ )
            Visit(node->getArg(i));
        // Everything is possible for the return value 
        */ 
        return Expression(); 
         
    }

    Expression TransferFuncs::VisitReturnStmt(ReturnStmt *node) {
        if ( Expr * RV = node->getRetValue() )
            return Visit(RV);
        // Everything is possible for the return value
        return Expression();
    }

    Expression TransferFuncs::VisitArraySubscriptExpr(ArraySubscriptExpr *node) {
        return Visit(node->getIdx());
    }

    Expression TransferFuncs::VisitImplicitCastExpr(ImplicitCastExpr * node) {
        return Visit(node->getSubExpr());
    }

    static VarDecl* FindBlockVarDecl(Expr* node) {
        // Blast through casts and parentheses to find any DeclRefExprs that
        // refer to a block VarDecl.
        if ( DeclRefExpr* DR = dyn_cast<DeclRefExpr>(node->IgnoreParenCasts()) )
            if ( VarDecl* VD = dyn_cast<VarDecl>(DR->getDecl()) )
                return VD;
        return NULL;
    }

    Expression TransferFuncs::VisitUnaryOperator(UnaryOperator* node) {
        VarDecl* decl = FindBlockVarDecl(node->getSubExpr());
        string name = (decl) ? decl->getNameAsString() : "";
        string type = (decl) ? decl->getType().getAsString() : "";
        Expression expr = Visit(node->getSubExpr());
        environment& env = state_.env;
        texpr1 sub_expr(env);
        var v("");

        if ( decl ) {
            v = decl->getNameAsString();
            if ( !env.contains(v) && 
                 type != Defines::kGuardType) // don't add guards to the environment.
                env = env.add(&v,1,0,0);
        }

        if ( expr.expression_ptr )
            sub_expr = expr;

        switch ( node->getOpcode() ) {
        case UO_PostInc:
            state_.Assign(env,v,sub_expr+AnalysisUtils::kOne);
            nstate_.Assign(env,v,sub_expr+AnalysisUtils::kOne);
            break;
        case UO_PreInc:
            state_.Assign(env,v,sub_expr+AnalysisUtils::kOne);
            nstate_.Assign(env,v,sub_expr+AnalysisUtils::kOne);
            sub_expr = (texpr1)(sub_expr+AnalysisUtils::kOne);
            break;
        case UO_PostDec:
            state_.Assign(env,v,sub_expr-AnalysisUtils::kOne);
            nstate_.Assign(env,v,sub_expr-AnalysisUtils::kOne);
            break;
        case UO_PreDec:
            state_.Assign(env,v,sub_expr-AnalysisUtils::kOne);
            nstate_.Assign(env,v,sub_expr-AnalysisUtils::kOne);
            sub_expr = (texpr1)(sub_expr-AnalysisUtils::kOne);
            break;
        case UO_Minus:
            sub_expr = (texpr1)(-sub_expr);
            break;
        case UO_LNot: 
            {   
                nstate_ = state_; //NState should start off as State on conditionals           
                if ( type == Defines::kGuardType ) {
                    /*
                    if (name == Defines::kRetGuard || name == Defines::kTagPrefix + Defines::kRetGuard) {
                        texpr1 var_texpr(env,v);
                        state_ &= tcons1(var_texpr == kZeroTExpr);
                        nstate_ &= tcons1(var_texpr == kOneTExpr); 
                    } else {
                        texpr1 var_texpr(env,v);
                        //state_ &= guard_map_[name].second;
                        //nstate_ &= guard_map_[name].first;
                        state_ &= tcons1(var_texpr == kZeroTExpr);
                        nstate_ &= tcons1(var_texpr == kOneTExpr); 
                    } 
                    */
                    state_ &= tcons1(texpr1(env,v) == AnalysisUtils::kZero);
                    //state_ &= guard_map_[name].second;
                    nstate_ &= tcons1(texpr1(env,v) == AnalysisUtils::kOne);
                    //nstate_ &= guard_map_[name].first; 
                } else {
                    state_ = state_map_[node->getSubExpr()].second;
                    nstate_ = state_map_[node->getSubExpr()].first;
                    /*
                    state_map_[node].first = state_map_[node->getSubExpr()].second;
                    state_map_[node].second = state_map_[node->getSubExpr()].first; 
                    */ 
                } 
                if ( sub_expr.is_zero() )
                    sub_expr = AnalysisUtils::kOne;
                else
                    sub_expr = ((expr.expression_ptr) ? (texpr1)expr : (texpr1)texpr1::builder(sub_expr.get_environment(),interval(0,1)));
            }
            break;
        default:
            break; 
        }
        expr_map_[node].setExpression(sub_expr);
        return expr_map_[node];
    }

    Expression TransferFuncs::ApplyExpressionToState(BinaryOperator *node, const texpr1 &expression) {
        set<abstract1> expr_abs;
        expr_map_[node].setExpression(expression);
        /*
        // Create constraints to reflect the assignment as a logical condition
        expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,expression > kZeroTExpr));
        expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,expression < kZeroTExpr));
        // Set it to the state map
        state_map[node].first = state_;
        state_map[node].first.Assume(expr_abs);
        
        set<abstract1> neg_expr_abs;
        // Do the same for negation
        neg_expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,expression == kZeroTExpr));
        state_map[node].second = state_;
        state_map[node].second.Assume(neg_expr_abs); 
        */ 
        return expr_map_[node];
    }

    /** 
     * 
     * 
     * @param expr_abs
     * @param neg_expr_abs
     */
    void TransferFuncs::SetGuard(const set<abstract1> &expr_abs, const set<abstract1> &neg_expr_abs) {
        //APAbstractDomain::ValTy guard_state, guard_nstate; 
        //guard_state.Assume(expr_abs);
        //guard_nstate.Assume(neg_expr_abs);
        guard_map_[current_guard_].first.Assume(expr_abs);
        guard_map_[current_guard_].second.Assume(neg_expr_abs);
#if (DEBUGGuard)
        cerr << current_guard_ << "->" << guard_map_[current_guard_].first << "\n";
        cerr << "~" << current_guard_ << "->" << guard_map_[current_guard_].second << "\n";
#endif
        current_guard_ = "";               
    }

    Expression TransferFuncs::VisitBinaryOperator(BinaryOperator* node) {
        Expr *lhs = node->getLHS()->IgnoreParenCasts(), *rhs = node->getRHS()->IgnoreParenCasts();

        if ( node->getOpcode() != BO_Assign && expr_map_.count(lhs) == 0 )
            Visit(lhs);

        if ( expr_map_.count(rhs) == 0 )
            Visit(rhs);

        Expression &left_expr = expr_map_[lhs], &right_expr = expr_map_[rhs];                      
        environment &env = state_.env;

        texpr1 left_texpr(env), right_texpr(env);
        if ( 0 != left_expr.expression_ptr )
            left_texpr = left_expr;
        if ( 0 != right_expr.expression_ptr )
            right_texpr = right_expr;

        try {
            left_texpr.extend_environment(env);
        } catch ( ... ) {
        }
        try {
            right_texpr.extend_environment(env);
        } catch ( ... ) {
        }
#if (DEBUGExp)
        cerr << left_texpr << " " << node->getOpcodeStr() << " " << right_texpr << endl;
#endif      
        VarDecl * left_var_decl_ptr = FindBlockVarDecl(lhs);                       
        var left_var("");
        string left_var_name(""); 
        if ( left_var_decl_ptr ) {
            left_var_name = left_var_decl_ptr->getNameAsString();
            left_var = left_var_name;
            if ( !env.contains(left_var) &&
                 left_var_decl_ptr->getType().getAsString() != Defines::kGuardType) { // don't add guards into the environment.
                env = env.add(&left_var,1,0,0);
            }
        }

        if ( node->getOpcode() >= BO_Assign ) { // Making sure we are assigning to an integer
            if ( !left_var_decl_ptr || !left_var_decl_ptr->getType().getTypePtr()->isIntegerType() ) { // Array? or non Integer
                expr_map_[node].setExpression(left_texpr);
                return expr_map_[node];
            }
        }

        set<abstract1> expr_abs, neg_expr_abs;
        // Our analysis should produce somwthing like this:
        //         [x>0]
        //  {x<=0} |    \  {x>0}
        //         |     [y>0]
        //         | {x>0,|  \  {x>0,
        //         | y<=0}|   \  y>0}
        //         |     /    [z:=0]
        //         |    /       |
        //         |   /        / {x>0,y>0,z==0}
        //         [end]-------/
        // 
        // Conslusions:
        // 1. NState should start off as State on conditionals
        // 2. we can ignore NState for assignments (since the solver will ignore it anyway)
        nstate_ = state_;

        switch ( node->getOpcode() ) {
        case BO_Assign:
            state_.Assign(env,left_var,right_texpr); 
            nstate_.Assign(env,left_var,right_texpr); 

            if ( left_var_decl_ptr->getType().getAsString() == Defines::kGuardType &&
                 left_var_name.find(Defines::kRetGuard) == left_var_name.npos ) { // Ret flag should inserted into state
                /* if (left_var_name.find(Defines::kRetGuard) == left_var_name.npos) {
                guard_map_[left_var_name].first.Assign(env,variable,right_texpr);
                guard_map_[left_var_name].second.Assign(env,variable,kOneTExpr - right_texpr); } else {
                */
                guard_map_[left_var_name] = state_map_[rhs];
#if (DEBUGGuard)
                cerr << "\n------\nAssigning: " << left_var_name << "->[" << guard_map_[left_var_name].first << "," << guard_map_[left_var_name].second << "]\n------\n";
                getchar();
#endif
                AssumeGuardEquivalence(left_var_name);
            }            
            return ApplyExpressionToState(node,right_texpr);
            break;

        case BO_AddAssign:
            // Var += Exp --> Substitute Var with (Var + Exp)
            state_.Assign(env,left_var,left_texpr+right_texpr);
            nstate_.Assign(env,left_var,left_texpr+right_texpr);
        case BO_Add:
            return ApplyExpressionToState(node,left_texpr+right_texpr);
            break;

        case BO_SubAssign:
            // Var -= Exp --> Substitute Var with (Var - Exp)
            state_.Assign(env,left_var,left_texpr-right_texpr);
            nstate_.Assign(env,left_var,left_texpr-right_texpr);
        case BO_Sub:
            return ApplyExpressionToState(node,left_texpr-right_texpr);
            break;
 
        case BO_MulAssign:
            // Var *= Exp --> Substitute Var with (Var * Exp)
            state_.Assign(env,left_var,left_texpr*right_texpr);
            nstate_.Assign(env,left_var,left_texpr*right_texpr);
        case BO_Mul:
            return ApplyExpressionToState(node,left_texpr*right_texpr);
            break;

        case BO_DivAssign:
            // Var /= Exp --> Substitute Var with (Var / Exp)
            state_.Assign(env,left_var,left_texpr/right_texpr);
            nstate_.Assign(env,left_var,left_texpr/right_texpr);
        case BO_Div:
            return ApplyExpressionToState(node,left_texpr/right_texpr);
            break;

        case BO_EQ:
            {
                expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr == right_texpr));
                // Negate the constraint for the false path
                neg_expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr > right_texpr));
                neg_expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr < right_texpr));

                if ( !current_guard_.empty() )
                    SetGuard(expr_abs, neg_expr_abs);

                //state_.Assume(expr_abs);
                //NState.Assume(neg_expr_abs);

#if (DEBUGCons)
                cerr << "state_: " << state_ << endl;
#endif                              
                //state_map_[node].first = state_;
                //state_map_[node].second = NState;
                state_map_[node].first.Assume(expr_abs);
                state_map_[node].second.Assume(neg_expr_abs);
                return expr_map_[node];
                break;
            }  
        case BO_NE:
            {
                // X != Y --> X < Y or X > Y
                expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr > right_texpr));
                expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr < right_texpr));
                // Negate the constraint for the false path
                neg_expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr == right_texpr));

                if ( !current_guard_.empty() )
                    SetGuard(expr_abs, neg_expr_abs);

                //state_.Assume(expr_abs);
                //NState.Assume(neg_expr_abs);

#if (DEBUGCons)
                cerr << "state_: " << state_ << endl;
#endif 
                //state_map_[node].first = state_;
                //state_map_[node].second = NState;
                state_map_[node].first.Assume(expr_abs);
                state_map_[node].second.Assume(neg_expr_abs);
                return expr_map_[node];
                break;
            }
        case BO_GE:
            {
                expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr >= right_texpr));
                // Negate the constraint for the false path
                neg_expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr < right_texpr));

                if ( !current_guard_.empty() )
                    SetGuard(expr_abs, neg_expr_abs);

                //state_.Assume(expr_abs);
                //NState.Assume(neg_expr_abs);

#if (DEBUGCons)
                cerr << "state_: " << state_ << endl;
#endif 
                //state_map_[node].first = state_;
                //state_map_[node].second = NState;
                state_map_[node].first.Assume(expr_abs);
                state_map_[node].second.Assume(neg_expr_abs);
                return expr_map_[node];
                break;
            }
        case BO_GT:
            {
                expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr > right_texpr));
                // Negate the constraint for the false path
                neg_expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr <= right_texpr));

                if ( !current_guard_.empty() )
                    SetGuard(expr_abs, neg_expr_abs);

                //state_.Assume(expr_abs);
                //NState.Assume(neg_expr_abs);

#if (DEBUGCons)
                cerr << "state_: " << state_ << endl;
#endif 
                //state_map_[node].first = state_;
                //state_map_[node].second = NState;
                state_map_[node].first.Assume(expr_abs);
                state_map_[node].second.Assume(neg_expr_abs);
                return expr_map_[node];
                break;
            }
        case BO_LE:
            {
                expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr <= right_texpr));
                // Negate the constraint for the false path
                neg_expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr > right_texpr));

                if ( !current_guard_.empty() )
                    SetGuard(expr_abs, neg_expr_abs);

                //state_.Assume(expr_abs);
                //NState.Assume(neg_expr_abs);

#if (DEBUGCons)
                cerr << "state_: " << state_ << endl;
#endif 
                //state_map_[node].first = state_;
                //state_map_[node].second = NState;
                state_map_[node].first.Assume(expr_abs);
                state_map_[node].second.Assume(neg_expr_abs);
                return expr_map_[node];
                break;
            } 
        case BO_LT:
            {
                expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr < right_texpr));
                // Negate the constraint for the false path
                neg_expr_abs.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr,left_texpr >= right_texpr));

                if ( !current_guard_.empty() )
                    SetGuard(expr_abs, neg_expr_abs);

                //NState.Assume(neg_expr_abs);
                //state_.Assume(expr_abs);

#if (DEBUGCons)
                cerr << "state_: " << state_ << endl;
#endif 
                //state_map_[node].first = state_;
                //state_map_[node].second = NState;
                state_map_[node].first.Assume(expr_abs);
                state_map_[node].second.Assume(neg_expr_abs);
                return expr_map_[node];
                break;
            }
        case BO_LAnd:
            {
                state_map_[node].first = state_map_[lhs].first;
                state_map_[node].first &= state_map_[rhs].first;

                // !(A && B) = ~A or (A and ~B)
                // start off with (A and ~B)
                state_map_[node].second = state_map_[lhs].first;
                state_map_[node].second &= state_map_[rhs].second;
                // now do ~A
                state_map_[node].second |= state_map_[lhs].second;


                /*
                if (!current_guard_.empty()) {
                   guard_map_[current_guard_].first = state_map_[lhs].first;
                   guard_map_[current_guard_].first.UpdateEnvironment(state_map_[rhs].first.env);
                   guard_map_[current_guard_].first &= state_map_[rhs].first;
                   guard_map_[current_guard_].second = state_map_[rhs].second;
                   guard_map_[current_guard_].second.UpdateEnvironment(state_map_[lhs].second.env);
                   guard_map_[current_guard_].second |= state_map_[lhs].second;
                   current_guard_ = "";
                } 
                */ 

                /*
               state_ = state_map_[lhs].first;
               state_.UpdateEnvironment(state_map_[rhs].first.env);
               state_ &= state_map_[rhs].first;
   
               // !(A && node) = ~A and ~node
               NState = state_map_[rhs].second;
               NState.UpdateEnvironment(state_map_[lhs].second.env);
               NState &= state_map_[lhs].second;
               */
                /*
                // !(A && node) = ~A or (A and ~node)
                NState.UpdateEnvironment(state_map[lhs].first.env);
                NState &= state_map[lhs].first;
                NState.UpdateEnvironment(state_map[rhs].second.env);
                NState &= state_map[rhs].second;
                NState.UpdateEnvironment(state_map[lhs].second.env);
                NState |= state_map[lhs].second;
                */

#if (DEBUGCons)
                cerr << "LHS state_ = " << state_map_[lhs].first << "\nLHS ~state_ = " << state_map_[lhs].second;
                cerr << "RHS state_ = " << state_map_[rhs].first << "\nRHS ~state_ = " << state_map_[rhs].second;
                cerr << "state_: " << state_ << "\n~state_ = " << nstate_ << endl;
#endif 
                //state_map_[node].first = state_;
                //state_map_[node].second = NState;
                return expr_map_[node];
                break;
            }
        case BO_LOr:
            {

                state_map_[node].first = state_map_[lhs].first;
                state_map_[node].first |= state_map_[rhs].first;

                // !(A || B) = ~A and ~B
                state_map_[node].second = state_map_[lhs].second;
                state_map_[node].second &= state_map_[rhs].second;

                /*
               if (!current_guard_.empty()) {
                   guard_map_[current_guard_].first = state_map_[lhs].first;
                   guard_map_[current_guard_].first.UpdateEnvironment(state_map_[rhs].first.env);
                   guard_map_[current_guard_].first |= state_map_[rhs].first;
                   guard_map_[current_guard_].second = state_map_[rhs].second;
                   guard_map_[current_guard_].second.UpdateEnvironment(state_map_[lhs].second.env);
                   guard_map_[current_guard_].second &= state_map_[lhs].second;
                   current_guard_ = "";
               }  
                */ 

                /*
                state_ = state_map_[lhs].first;
                state_.UpdateEnvironment(state_map_[rhs].first.env);
                state_ |= state_map_[rhs].first;
    
                // !(A || node) = ~A and ~node
                NState = state_map_[lhs].second;
                NState.UpdateEnvironment(state_map_[rhs].second.env);
                NState &= state_map_[rhs].second;
                */
#if (DEBUGCons)
                cerr << "LHS state_ = " << state_map_[lhs].first << "\nLHS ~state_ = " << state_map_[lhs].second;
                cerr << "RHS state_ = " << state_map_[rhs].first << "\nRHS ~state_ = " << state_map_[rhs].second;
                cerr << "state_: " << state_ << "\n~state_ = " << nstate_ << endl;
#endif 
                /*
                state_map_[node].first = state_;
                state_map_[node].first.Assume(expr_abs);
                state_map_[node].second = NState;
                state_map_[node].second.Assume(neg_expr_abs);
                */
                return expr_map_[node];
                break;
            }
        case BO_And:
        case BO_AndAssign:
        case BO_Or:
        case BO_OrAssign:
        case BO_Rem:
        case BO_RemAssign:
        case BO_Shl:
        case BO_ShlAssign:
        case BO_Shr:
//	{
//		if (!ExpRight.is_scalar())
//			break;
//		long Factor = 1;
//		manager Mgr = state_.Abs.get_manager();
//		while (state_.Abs.bound(Mgr,ExpRight) != interval(0,0)) {
//			Factor *= 2;
//			ExpRight = ExpRight - texpr1(state_.Abs.get_environment(),1);
//		}
//		return (texpr1)(ExpLeft * texpr1(state_.Abs.get_environment(),Factor));
//		break;
//	}
        case BO_ShrAssign:
        case BO_Xor:
        case BO_XorAssign:
        default:
            break;
        }

        return expr_map_[node];
    }

    Expression TransferFuncs::VisitDeclStmt(DeclStmt* node) {
        Expression result;
        for ( DeclStmt::const_decl_iterator iter = node->decl_begin(), end = node->decl_end(); iter != end; ++iter ) {
            if ( VarDecl *decl = cast<VarDecl>(*iter) ) {
                string name = decl->getNameAsString();
                // diffPoint variable - defined only to identify a point where the differential 
                // need be checked.
                if ( name.find(Defines::kDiffPointPrefix) == 0 ) {
                    AD.Observer->ObserveAll(state_, node->getLocStart());
                    // implement the canonicalize-at-diff-point strategy
                    if ( state_.canonization_point == APAbstractDomain_ValueTypes::ValTy::AT_DIFF_POINT ||
                         state_.canonization_strategy ==  APAbstractDomain_ValueTypes::ValTy::EQUIV )
                        state_.JoinAll();
                }
                if ( decl->getType().getTypePtr()->isIntegerType() /* &&
                     (decl->getType().getAsString() != Defines::kGuardType ||
                      name.find(Defines::kRetGuard) != name.npos)*/ ) {
                    // add the newly declared integer variable to the environment
                    var v(name);
                    environment &env = state_.env;
                    if ( !env.contains(v) )
                        env = env.add(&v,1,0,0);
                    if ( Stmt* init = decl->getInit() ) {
                        texpr1 expr = Visit(init);
                        // visit the subexpression to check for uses of other known ranged values
                        state_.Assign(env,v,expr);
                        result.setExpression(expr);
                    }
                    // add the v == v' constraint
                    AssumeTagEquivalence(name);
                }
            }
        }
        return result;
    }

    Expression TransferFuncs::VisitIntegerLiteral(IntegerLiteral * node) {
        int value = (int)node->getValue().getLimitedValue();
        texpr1 expr(state_.env,value);
        expr_map_[node].setExpression(expr);
        set<abstract1> abs_set;
        abs_set.insert(abstract1(*(state_.mgr_ptr),state_.env,apron::top()));
        if ( value )
            state_map_[node].first.Assume(abs_set);
        else
            state_map_[node].second.Assume(abs_set);
        return expr_map_[node];
    }

    struct Merge {
        void operator()(APAbstractDomain::ValTy& Dst, APAbstractDomain::ValTy& Src) {
            Dst |= Src;
        }
    };

    struct LowerOrEqual {
        bool operator()(APAbstractDomain::ValTy& Dst, APAbstractDomain::ValTy& Src) {
            //cerr << Dst << " <= " << Src << " = " << (Dst <= Src);
            return(Dst <= Src);
        }
    };
    typedef DataflowSolver<APAbstractDomain,TransferFuncs,Merge,LowerOrEqual> Solver;
}

APAbstractDomain_ValueTypes::ValTy::CanonizationPoint APAbstractDomain_ValueTypes::ValTy::canonization_point = APAbstractDomain_ValueTypes::ValTy::AT_JOIN;
APAbstractDomain_ValueTypes::ValTy::CanonizationStrategy APAbstractDomain_ValueTypes::ValTy::canonization_strategy = APAbstractDomain_ValueTypes::ValTy::EQUIV;
unsigned APAbstractDomain_ValueTypes::ValTy::canonization_threshold = 1;


namespace clang {
    ostream& operator<<(ostream& os, const APAbstractDomain_ValueTypes::ValTy & V) {
        os << (string)V;
        return os;
    }

    manager * APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = 0;
    APAbstractDomain_ValueTypes::ValTy::AbstractDictionary APAbstractDomain_ValueTypes::ValTy::abstract_dictionary;

    void CheckLinEq(CFG& cfg, ASTContext &contex, DiagnosticsEngine &diagnostics_engine, Preprocessor * preprocessor_ptr, unsigned &report_ctr) {
        // Compute the ranges information.
        APAbstractDomain Dom(cfg);
        Dom.InitializeValues(cfg);
        APChecker Observer(contex,diagnostics_engine, preprocessor_ptr);
        Dom.getAnalysisData().Observer = &Observer;
        Dom.getAnalysisData().setContext(contex);
        Solver S(Dom);
        S.runOnCFG(cfg, true);
        Observer.ObserveFixedPoint(true, report_ctr);
    } 
} // end namespace clang 

