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

#include "APAbstractDomain.h" 
#include "../Defines.h" 
#include "../Utils.h"
using namespace differential;

#define DEBUGCons   0
#define DEBUGExp    0
#define DEBUGGuard  0

//===----------------------------------------------------------------------===//
// Dataflow initialization logic.
//===----------------------------------------------------------------------===//

namespace {
 
    class RegisterDecls
    : public CFGRecStmtDeclVisitor<RegisterDecls> {

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

//===----------------------------------------------------------------------===//
// Transfer functions.
//===----------------------------------------------------------------------===//

namespace {

	typedef APAbstractDomain::ValTy State;
	typedef apron::texpr1 Expression;

	struct ExpressionState {
        Expression e_;
		State s_, ns_;

        ExpressionState() : e_(texpr1::builder(environment(),top())) {   }

        ExpressionState& operator=(const ExpressionState& lhs) {
            e_ = lhs.e_;
			s_ = lhs.s_;
			ns_ = lhs.ns_;
            return *this;
        }

		ExpressionState(const Expression& lhs) : e_(lhs) {  }

        operator Expression() const {
            return e_;
        }

        friend ostream& operator<<(ostream& os, const ExpressionState &es);
        virtual ~ExpressionState() { }
    };

    ostream& operator<<(ostream& os, const ExpressionState &es) {
        os << es.e_ << es.s_ << es.ns_;
        return os;
    }

    class TransferFuncs : public CFGStmtVisitor<TransferFuncs,ExpressionState> {

        State state_, nstate_;
        APAbstractDomain::AnalysisDataTy& AD;
        map<Expr*,ExpressionState> expr_map_;
        string current_guard_;
        bool report_;

        ExpressionState GetVarExpression(Expr* node, const QualType type, const string& name);
        ExpressionState ApplyExpressionToState(BinaryOperator *node, const texpr1 &expression);
        void SetGuard(const set<abstract1> &expr_abs, const set<abstract1> &neg_expr_abs);
        void AssumeTagEquivalence(environment &env, const string &name);
        void AssumeGuardEquivalence(environment &env, string name);

    public:

        TransferFuncs(APAbstractDomain::AnalysisDataTy& ad, bool reportResults = false) : AD(ad), report_(reportResults), current_guard_("") { }

        typedef CFGStmtVisitor<TransferFuncs,ExpressionState> BaseStmtVisitor;
        using BaseStmtVisitor::Visit;

        ExpressionState VisitDeclRefExpr(DeclRefExpr* node);
        ExpressionState VisitBinaryOperator(BinaryOperator* node);
        ExpressionState VisitUnaryOperator(UnaryOperator* node);
        ExpressionState VisitDeclStmt(DeclStmt* node);
        ExpressionState VisitIntegerLiteral(IntegerLiteral * node);
        ExpressionState VisitImplicitCastExpr(ImplicitCastExpr * node);
        ExpressionState VisitCallExpr(CallExpr * node);
		ExpressionState VisitParenExpr(ParenExpr *node);
		void VisitTerminator(CFGBlock* B) { }
		VarDecl*   FindBlockVarDecl(Expr* node);

		State& getVal() {
            return state_;
        }
        State& getNVal() {
            return nstate_;
        }

        CFG& getCFG() {
            return AD.getCFG();
        }

    };

    void TransferFuncs::AssumeTagEquivalence(environment &env, const string &name){
        tcons1 equal_cons = AnalysisUtils::GetEquivCons(env,name);
        state_ &= equal_cons;
        nstate_ &= equal_cons;
    }

    // forget all guard information and assume equivalence.
    void TransferFuncs::AssumeGuardEquivalence(environment &env, string name){
        string tagged_name;
        Utils::Names(name,tagged_name);
        tcons1 equal_cons = AnalysisUtils::GetEquivCons(env,name);

        state_.Forget(name);
        state_.Forget(tagged_name);
        nstate_.Forget(name);
        nstate_.Forget(tagged_name);

        state_ &= equal_cons;
        nstate_ &= equal_cons;
    }

    ExpressionState TransferFuncs::VisitDeclRefExpr(DeclRefExpr* node) {
        ExpressionState result;

        if ( VarDecl* decl = dyn_cast<VarDecl>(node->getDecl()) ) {
            string type = decl->getType().getAsString(), name = decl->getNameAsString();
			var v(name);
            result = texpr1(environment().add(&v,1,0,0),v);
        }

        return result;
    }

    ExpressionState TransferFuncs::VisitCallExpr(CallExpr *node) {
        llvm::outs() << "Encountered function call: ";
        node->printPretty(llvm::outs(),AD.getContext(),0, PrintingPolicy(LangOptions()));
        llvm::outs() << ", all results regarding variables affected by this call are unsound.\n";
        return ExpressionState();

    }

	ExpressionState TransferFuncs::VisitParenExpr(ParenExpr *node) {
		return Visit(node->getSubExpr());
	}


    ExpressionState TransferFuncs::VisitImplicitCastExpr(ImplicitCastExpr * node) {
		ExpressionState sub_expr = Visit(node->getSubExpr());
		if ( VarDecl* decl = FindBlockVarDecl(node) ) {
            string type = decl->getType().getAsString(), name = decl->getNameAsString();
			if (node->getCastKind() == CK_IntegralToBoolean && type == Defines::kGuardType) { // if (guard)
                var guard(name);
#if (DEBUGGuard)
                cerr << "\n------\nEncountered: " << name << "\n";
#endif
				// nstate_should only matter in VisitImplicitCastExpr and in VisitUnaryOperator
				// as they are the actual way that the fixed point algorithm sees conditionals
				// in the union program (eithre as (!Ret) <- unary not, or as (g) <- cast from integral to boolean)
                nstate_ = state_;
				environment env = sub_expr.e_.get_environment();
                state_.MeetGuard(tcons1(texpr1(env,guard) == AnalysisUtils::kOne));
                nstate_.MeetGuard(tcons1(texpr1(env,guard) == AnalysisUtils::kZero));
#if (DEBUGGuard)
                cerr << "State = " << state_ << ", NState = " << nstate_ << "\n------\n";
#endif
            }
        }
		return sub_expr;
    }

    VarDecl* TransferFuncs::FindBlockVarDecl(Expr* node) {
        // Blast through casts and parentheses to find any DeclRefExprs that
        // refer to a block VarDecl.
        if ( DeclRefExpr* DR = dyn_cast<DeclRefExpr>(node->IgnoreParenCasts()) )
            if ( VarDecl* VD = dyn_cast<VarDecl>(DR->getDecl()) )
                return VD;
        return NULL;
    }

    ExpressionState TransferFuncs::VisitUnaryOperator(UnaryOperator* node) {
		Expr * sub = node->getSubExpr();
		texpr1 sub_expr = Visit(sub);
        VarDecl* decl = FindBlockVarDecl(sub);
        string name = (decl) ? decl->getNameAsString() : "";
        string type = (decl) ? decl->getType().getAsString() : "";
        var v(name);
		environment env = sub_expr.get_environment();

        switch ( node->getOpcode() ) {
        case UO_PostInc:
            state_.Assign(env,v,sub_expr + AnalysisUtils::kOne);
            nstate_.Assign(env,v,sub_expr + AnalysisUtils::kOne);
            break;
        case UO_PreInc:
            state_.Assign(env,v,sub_expr+AnalysisUtils::kOne);
            nstate_.Assign(env,v,sub_expr+AnalysisUtils::kOne);
            return (texpr1)(sub_expr+AnalysisUtils::kOne);
            break;
        case UO_PostDec:
            state_.Assign(env,v,sub_expr-AnalysisUtils::kOne);
            nstate_.Assign(env,v,sub_expr-AnalysisUtils::kOne);
            break;
        case UO_PreDec:
            state_.Assign(env,v,sub_expr-AnalysisUtils::kOne);
            nstate_.Assign(env,v,sub_expr-AnalysisUtils::kOne);
            return (texpr1)(sub_expr-AnalysisUtils::kOne);
            break;
        case UO_Minus:
            return (texpr1)(-sub_expr);
            break;
        case UO_LNot:
            {
				// nstate_should only matter in VisitImplicitCastExpr and in VisitUnaryOperator
				// as they are the actual way that the fixed point algorithm sees conditionals
				// in the union program (eithre as (!Ret) <- unary not, or as (g) <- cast from integral to boolean)
				assert(type == Defines::kGuardType);
				State tmp = nstate_;
				nstate_ = state_;
				state_ = tmp;
				return sub_expr;
            }
            break;
        default:
            break;
        }
        return sub_expr;
    }

    ExpressionState TransferFuncs::VisitBinaryOperator(BinaryOperator* node) {
		manager mgr = *(state_.mgr_ptr_);
		environment &env = state_.env_;
        Expr *lhs = node->getLHS(), *rhs = node->getRHS();

		// since the visit operations produces the same output for every visit
		// (only thing that changes are state_ and nstate_), save them in a map

        if ( expr_map_.count(lhs) == 0 )
            expr_map_[lhs] = Visit(lhs);

        if ( expr_map_.count(rhs) == 0 )
            expr_map_[rhs] = Visit(rhs);

        ExpressionState left = expr_map_[lhs], right = expr_map_[rhs], result;
        texpr1 left_texpr = left, right_texpr = right;

#if (DEBUGExp)
        cerr << "Left = " << left << " \nRight = " << right << endl;
#endif

        VarDecl * left_var_decl_ptr = FindBlockVarDecl(lhs);
        var left_var("");
        string left_var_name("");
        if ( left_var_decl_ptr ) {
            left_var_name = left_var_decl_ptr->getNameAsString();
            left_var = left_var_name;
        }

        if ( node->getOpcode() >= BO_Assign ) { // Making sure we are assigning to an integer
            if ( !left_var_decl_ptr || !left_var_decl_ptr->getType().getTypePtr()->isIntegerType() ) { // Array? or non Integer
                return left_texpr;
            }
        }

		left_texpr.extend_environment(AnalysisUtils::JoinEnvironments(left_texpr.get_environment(),right_texpr.get_environment()));
		right_texpr.extend_environment(AnalysisUtils::JoinEnvironments(left_texpr.get_environment(),right_texpr.get_environment()));

        set<abstract1> expr_abs_set, neg_expr_abs_set;
        switch ( node->getOpcode() ) {
        case BO_Assign:
		{
			bool is_guard = (left_var_decl_ptr->getType().getAsString() == Defines::kGuardType);
			state_.Assign(env,left_var,right_texpr,is_guard);
			// Assigning to a guard variables needs special handling
            if ( is_guard ) {
                State tmp = right.s_;
				tmp.MeetGuard(tcons1((texpr1)left == AnalysisUtils::kOne));
				State ntmp = right.ns_;
				ntmp.MeetGuard(tcons1((texpr1)left == AnalysisUtils::kZero));
				state_ &= (tmp |= ntmp);
#if (DEBUGGuard)
                cerr << "State = " << state_ << " NState = " << nstate_ << "\n";
#endif
            }

            return right_texpr;
            break;
		}

        case BO_AddAssign:
            // Var += Exp --> Substitute Var with (Var + Exp)
            state_.Assign(env,left_var,left_texpr+right_texpr);
        case BO_Add:
            return texpr1(left_texpr+right_texpr);
            break;

        case BO_SubAssign:
            // Var -= Exp --> Substitute Var with (Var - Exp)
            state_.Assign(env,left_var,left_texpr-right_texpr);
        case BO_Sub:
            return texpr1(left_texpr-right_texpr);
            break;

        case BO_MulAssign:
            // Var *= Exp --> Substitute Var with (Var * Exp)
            state_.Assign(env,left_var,left_texpr*right_texpr);
        case BO_Mul:
            return texpr1(left_texpr*right_texpr);
            break;

        case BO_DivAssign:
            // Var /= Exp --> Substitute Var with (Var / Exp)
            state_.Assign(env,left_var,left_texpr/right_texpr);
        case BO_Div:
            return texpr1(left_texpr/right_texpr);
            break;

        case BO_EQ:
		{
			tcons1 constraint = (left_texpr == right_texpr);
			expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr_,constraint));
			AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
			result.s_.Assume(expr_abs_set);
			result.ns_.Assume(neg_expr_abs_set);
			return result;
			break;
		}
        case BO_NE:
		{
			tcons1 constraint = (left_texpr == right_texpr);
			AnalysisUtils::NegateConstraint(mgr,constraint,expr_abs_set);
			neg_expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
			result.s_.Assume(expr_abs_set);
			result.ns_.Assume(neg_expr_abs_set);
			return result;
			break;
		}
        case BO_GE:
		{
			tcons1 constraint = (left_texpr >= right_texpr);
			expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
			AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
			result.s_.Assume(expr_abs_set);
			result.ns_.Assume(neg_expr_abs_set);
			return result;
			break;
		}
        case BO_GT:
		{
			tcons1 constraint = (left_texpr >= right_texpr + AnalysisUtils::kOne);
			expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
			AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
			result.s_.Assume(expr_abs_set);
			result.ns_.Assume(neg_expr_abs_set);
			return result;
			break;
		}
        case BO_LE:
		{
			tcons1 constraint = (left_texpr <= right_texpr);
			expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
			AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
			result.s_.Assume(expr_abs_set);
			result.ns_.Assume(neg_expr_abs_set);
			return result;
			break;
		}
        case BO_LT:
		{
			tcons1 constraint = (left_texpr <= right_texpr - AnalysisUtils::kOne);
			expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
			AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
			result.s_.Assume(expr_abs_set);
			result.ns_.Assume(neg_expr_abs_set);
			return result;
			break;
		}
        case BO_LAnd:
		{
			result.s_ = left.s_;
			result.s_ &= right.s_;

			// !(L && R) = ~L or (A and ~B)
			// start off with (L and ~R)
			result.ns_ = left.s_;
			result.ns_ &= right.ns_;
			// now do ~L
			result.ns_ |= left.ns_;

			return result;
			break;
		}
        case BO_LOr:
		{
			result.s_ = left.s_;
			result.s_ |= right.s_;

			// !(L || R) = ~L and ~R
			result.ns_ = left.ns_;
			result.ns_ &= right.ns_;

			return result;
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
		{
			/*
			if (!ExpRight.is_scalar())
				break;
			long Factor = 1;
			manager Mgr = state_.Abs.get_manager();
			while (state_.Abs.bound(Mgr,ExpRight) != interval(0,0)) {
				Factor *= 2;
				ExpRight = ExpRight - texpr1(state_.Abs.get_environment(),1);
			}
			return (texpr1)(ExpLeft * texpr1(state_.Abs.get_environment(),Factor));
			break;
			*/
		}
        case BO_ShrAssign:
        case BO_Xor:
        case BO_XorAssign:
        default:
            break;
        }

        return result;
    }

    ExpressionState TransferFuncs::VisitDeclStmt(DeclStmt* node) {
        for ( DeclStmt::const_decl_iterator iter = node->decl_begin(), end = node->decl_end(); iter != end; ++iter ) {
            if ( VarDecl *decl = cast<VarDecl>(*iter) ) {
                string name = decl->getNameAsString(), type = decl->getType().getAsString();
                // diffPoint variable - defined only to identify a point where the differential need be checked.
                if ( name.find(Defines::kDiffPointPrefix) == 0 ) {
                    AD.Observer->ObserveAll(state_, node->getLocStart());
                    // implement the canonicalize-at-diff-point strategy
                    if ( state_.canonization_point == APAbstractDomain_ValueTypes::ValTy::AT_DIFF_POINT) {
                        state_.Canonicalize();
					}
                }
                if ( decl->getType().getTypePtr()->isIntegerType() ) { // apply to integers alone (this iscludes guards)
                    // add the newly declared integer variable to the environment
					// this should be the ONLY place this is needed!
                    var v(name);
                    environment &env = state_.env_;
                    if ( !env.contains(v) )
                        env = env.add(&v,1,0,0);
                    if ( Stmt* init = decl->getInit() ) {  // visit the subexpression to try and create an abstract expression
                        state_.Assign(env,v,Visit(init), (type == Defines::kGuardType));
                    } else { // if no init, assume that v == v'
						AssumeTagEquivalence(env,name);
					}
                }
            }
        }
		return ExpressionState();
    }

    ExpressionState TransferFuncs::VisitIntegerLiteral(IntegerLiteral * node) {
        int value = (int)node->getValue().getLimitedValue();
        return texpr1(environment(), value);
    }

    struct Merge {
        void operator()(State& Dst, State& Src) {
            Dst |= Src;
        }
    };

    struct LowerOrEqual {
        bool operator()(State& Dst, State& Src) {
            //cerr << Dst << " <= " << Src << " = " << (Dst <= Src);
            return(Dst <= Src);
        }
    };
    typedef DataflowSolver<APAbstractDomain,TransferFuncs,Merge,LowerOrEqual> Solver;
}

APAbstractDomain_ValueTypes::ValTy::CanonizationPoint APAbstractDomain_ValueTypes::ValTy::canonization_point = APAbstractDomain_ValueTypes::ValTy::AT_JOIN;
APAbstractDomain_ValueTypes::ValTy::CanonizationStrategy APAbstractDomain_ValueTypes::ValTy::canonization_strategy = APAbstractDomain_ValueTypes::ValTy::JOIN_EQUIV;
unsigned APAbstractDomain_ValueTypes::ValTy::canonization_threshold = 1;
APAbstractDomain_ValueTypes::ValTy::WideningStrategy APAbstractDomain_ValueTypes::ValTy::widening_strategy = APAbstractDomain_ValueTypes::ValTy::WIDEN_GUARDS;


namespace clang {
    ostream& operator<<(ostream& os, const APAbstractDomain_ValueTypes::ValTy & V) {
        os << (string)V;
        return os;
    }

    manager * APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = 0;

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

