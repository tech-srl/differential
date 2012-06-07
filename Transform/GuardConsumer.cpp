/*
 * GuardedConsumer.cpp
 *
 *  Created on: Mar 10, 2011
 *      Author: nimrod
 */

#include "GuardConsumer.h"

namespace differential {
    void GuardedInstructions::VisitFunctionDecl(FunctionDecl *node) {
        if ( !source_manager_.isFromMainFile(node->getLocation()) ||
             source_manager_.isInExternCSystemHeader(node->getLocation()) || // ignore printf, etc.
             source_manager_.isInSystemHeader(node->getLocation()) ) {
            return;
        }
        if ( node->isThisDeclarationADefinition() ) {
            string Prototype = Utils::PrintDecl(node,contex_);
            delete ss_ptr_;
            label_ctr_ = guard_ctr_ = diff_point_ctr_ = 0;
            ss_ptr_ = new stringstream();
            (*ss_ptr_) << "{\n";
            // X0 handling
            if ( save_initial_ ) {
                for ( unsigned i = 0 ; i < node->getNumParams() ; i++ ) {
                    ParmVarDecl * param_decl_ptr = node->getParamDecl(i);
                    string decl = Utils::PrintDecl(param_decl_ptr,contex_);
                    string name = param_decl_ptr->getNameAsString();
                    unsigned l = decl.find_last_of(name) - name.size() + 1;
                    string x0_decl = decl;
                    x0_decl.insert(l,Defines::kInitPrefix);
                    (*ss_ptr_) << Defines::kTagParamDef << x0_decl << " = " << name << ";\n";
                }
            } 
            // RetVal handling
            if ( ret_guard_ ) {
                (*ss_ptr_) << Defines::kTagParamDef << Defines::kRetGuardType << " " << Defines::kRetGuard << " = 0;\n";
                // TODO: this assumes that the return type has a default constructor
                return_type_ = node->getResultType().getAsString();
                if ( return_type_ != "void" ) {
                    (*ss_ptr_) << Defines::kTagParamDef << return_type_ << " " << Defines::kRetVal << /*" = (" << type << ")0" <<*/ ";\n";
                }
                stringstream ss;
                ss << "!" << Defines::kRetGuard;
                guards_.push_back(ss.str());
            }
            Visit(node->getBody());
            if ( ret_guard_ && node->getResultType().getAsString() != "void" ) {
                (*ss_ptr_) << "return " << Defines::kRetVal << ";\n";
            }
            (*ss_ptr_) << "}\n";

            SourceLocation SLoc = node->getBody()->getLocStart(),
                                  ELoc = node->getBodyRBrace().getLocWithOffset(1);
            unsigned Length = ELoc.getRawEncoding() - SLoc.getRawEncoding();
            rewriter_.ReplaceText(SLoc,Length,ss_ptr_->str());
            if ( ret_guard_ ) {
                PopCondition();
            }
        }

    }

    void GuardedInstructions::VisitVarDecl(VarDecl *node) {
        string decl = Utils::PrintDecl(node,contex_);
        (*ss_ptr_) << decl << ";\n";
        if ( save_initial_ ) { // X0 handling
            string name = node->getNameAsString();
            string x0_decl = decl.substr(0,min(decl.find("="), decl.size()));
            unsigned l = x0_decl.find_last_of(name) - name.size() + 1;
            x0_decl.insert(l,Defines::kInitPrefix);
            (*ss_ptr_) << x0_decl << " = " << name << ";\n";
        }
    }

    void GuardedInstructions::VisitDeclStmt(DeclStmt *node) {
        for ( DeclStmt::decl_iterator iter = node->decl_begin(), end = node->decl_end(); iter != end; ++iter ) {
            if ( isa<VarDecl>(*iter) )
                Visit(*iter);
            else {
                (*ss_ptr_) << Utils::PrintDecl(*iter,contex_);
                //string enum_decl = Utils::PrintDecl(*iter,contex_);
                ////string enum_body = enum_decl.substr(enum_decl.find("{"));
                ////(*ss_ptr_) << "enum " << Utils::ReplaceAll(enum_body,"\n","") << ";\n";
                //(*ss_ptr_) << enum_decl << "\n";
            } 
        }
    }


    void GuardedInstructions::VisitForStmt(ForStmt *node) {
        Stmt * Init = node->getInit(), *Body = node->getBody();
        Expr * Cond = node->getCond(), *Inc = node->getInc();
        if ( Init )
            Visit(Init);
        unsigned Label = ++label_ctr_;
        label_ctr_ += 2;
        (*ss_ptr_) << label_prefix_ << Label << ":;" << '\n';
        if ( Cond )
            PushCondition(Cond);
        PushLabel(Label);

        if ( Body )
            Visit(Body);
        PopLabel();
        // for continue
        (*ss_ptr_) << label_prefix_ << Label + 1 << ":;" << '\n';
        if ( Inc )
            Visit(Inc);
        (*ss_ptr_) << GetGuard() << "goto " << label_prefix_ << Label << ';' << '\n';
        // for break
        (*ss_ptr_) << label_prefix_ << Label + 2 << ":;" << '\n';
        if ( Cond )
            PopCondition();
    }

    void GuardedInstructions::VisitWhileStmt(WhileStmt *node) {
        Stmt * Body = node->getBody();
        Expr * Cond = node->getCond();
        unsigned Label = ++label_ctr_;
        label_ctr_ += 2;
        (*ss_ptr_) << label_prefix_ << Label << ":;" << '\n';
        if ( Cond )
            PushCondition(Cond);
        PushLabel(Label);
        if ( Body )
            Visit(Body);
        PopLabel();        // for continue
        (*ss_ptr_) << label_prefix_ << Label + 1 << ":;" << '\n';
        (*ss_ptr_) << GetGuard() << "goto " << label_prefix_ << Label << ';' << '\n';
        // for break
        (*ss_ptr_) << label_prefix_ << Label + 2 << ":;" << '\n';
        if ( Cond )
            PopCondition();
    }

    /** 
     * transforming: 
     * ------------- 
     *  
     * do { 
     *  ...
     * } while (c); 
     *  
     * to:
     * --- 
     *  
     * Guard guard = true; 
     * l: 
     * if (guard) ... 
     * guard = c; 
     * goto l; 
     *  
     */

    void GuardedInstructions::VisitDoStmt(DoStmt *node) {
        Stmt * body = node->getBody();
        Expr * cond = node->getCond();
        unsigned label = ++label_ctr_;
        label_ctr_ += 2;
        if ( cond )
            PushCondition(cond,false,false); // not negated, initialized to true (instead of cond)
        (*ss_ptr_) << label_prefix_ << label << ":;" << '\n'; // goto label should be after the init
        PushLabel(label);
        if ( body )
            Visit(body);
        PopLabel();        
        // for continue
        (*ss_ptr_) << label_prefix_ << label + 1 << ":;\n";
        if ( cond )// set the guard
            (*ss_ptr_) << GetGuard() << guards_.back() << " = " << Utils::PrintStmt(cond,contex_) << ";\n";
        (*ss_ptr_) << GetGuard() << "goto " << label_prefix_ << label << ';' << '\n';
        // for break
        (*ss_ptr_) << label_prefix_ << label + 2 << ":;\n";
        if ( cond )
            PopCondition();
    }

    void GuardedInstructions::VisitContinueStmt(ContinueStmt* node) {
        (*ss_ptr_) << GetGuard() << "goto " << label_prefix_ << labels_.back() + 1 << ';' << '\n';
    }

    void GuardedInstructions::VisitBreakStmt(BreakStmt* node) {
        // handle the case where the break comes after a switch case
        if ( !switch_vars_.empty() )
            guards_.push_back(case_guard_);
        (*ss_ptr_) << GetGuard() << "goto " << label_prefix_ << labels_.back() + 2 << ';' << '\n';
        if ( !switch_vars_.empty() )
            guards_.pop_back();
    }

    void GuardedInstructions::VisitSwitchStmt(SwitchStmt *node) {
        unsigned label = ++label_ctr_;
        label_ctr_ += 2;
        PushLabel(label);
        switch_vars_.push_back(Utils::PrintStmt(node->getCond(),contex_));
        VisitChildren(node);
        switch_vars_.pop_back();
        PopLabel();        
        // for break
        (*ss_ptr_) << label_prefix_ << label + 2 << ":;\n";
    }

    void GuardedInstructions::VisitSwitchCase(SwitchCase *node) {
        // find the case condition
        Stmt::child_iterator iter = node->child_begin(), end = node->child_end(), last, last2;
        // The condition is the previous-to-last child
        while ( iter != end ) {
            last2 = last;
            last = iter;
            ++iter;
        }
        if ( *last2 ) {
            stringstream ss;
            ss << switch_vars_.back() << " == " << Utils::PrintStmt(*last2,contex_);
            case_guard_ = ss.str();
            guards_.push_back(case_guard_);
            VisitChildren(node);
            guards_.pop_back();
        }
    }

    void GuardedInstructions::VisitDefaultStmt(DefaultStmt *node) {
        case_guard_ = "1";
        VisitChildren(node);
    }


    void GuardedInstructions::VisitIfStmt(IfStmt *node) {
        Stmt * Then = node->getThen(), *Else = node->getElse();
        Expr * Cond = node->getCond();
        if ( Cond )
            PushCondition(Cond);
        if ( Then )
            Visit(Then);
        // Negate the condition for the else
        if ( Else ) {
            if ( Cond ) {
                PushCondition(Cond,true);
            }
            Visit(Else);
        }
        if ( Cond )
            PopCondition();
    }

    void GuardedInstructions::VisitCallExpr(CallExpr *node) {
        GuardAndPrint(node);
    }

    void GuardedInstructions::VisitLabelStmt(LabelStmt * node) {
        (*ss_ptr_) << node->getName() << ":\n";
        Visit(node->getSubStmt());
    }

    void GuardedInstructions::VisitCompoundAssignOperator(CompoundAssignOperator *node) {
        GuardAndPrint(node);
    }

    void GuardedInstructions::VisitCompoundStmt(CompoundStmt *node) {
        (*ss_ptr_) << "{\n";
        VisitChildren(node);
        (*ss_ptr_) << "}\n";
    }

    void GuardedInstructions::VisitReturnStmt(ReturnStmt *node) {
        if ( ret_guard_ ) {
            if ( return_type_ != "void" )  // it's not void
                (*ss_ptr_) << GetGuard() << Defines::kRetVal << " = " << Utils::PrintStmt(node->getRetValue(),contex_) << ";\n";
            (*ss_ptr_) << GetGuard() << Defines::kRetGuard << " = 1;\n";
        } else {
            GuardAndPrint(node);
        }
    }

    void GuardedInstructions::VisitConditionalOperator(ConditionalOperator* node) {
        GuardAndPrint(node);
    }

    void GuardedInstructions::VisitBinaryOperator(BinaryOperator * node) {
        GuardAndPrint(node);
    }

    void GuardedInstructions::VisitUnaryOperator(UnaryOperator * node) {
        GuardAndPrint(node);
    }

    void GuardedInstructions::VisitGotoStmt(GotoStmt * node) {
        GuardAndPrint(node);
    }


    void GuardedInstructions::VisitChildren(Stmt *node) {
        for ( Stmt::child_iterator I = node->child_begin(), E = node->child_end();I != E;++I )
            if ( *I ) Visit(*I);
    }

    void GuardedInstructions::GuardAndPrint(Stmt * node) {
        (*ss_ptr_) << GetGuard() << Utils::PrintStmt(node,contex_) << ";\n";
    }

    string GuardedInstructions::GetGuard() {
        stringstream GuardSS;
        for ( unsigned i = 0;i < guards_.size();i++ ) {
            GuardSS << "if (" << guards_[i] << ") ";
        }
        return GuardSS.str();
    }

    void GuardedInstructions::PushCondition(Expr * node, bool negate, bool init) {
        if ( negate ) { // negatation of a condition is done by negating the last guard
            guards_.back() = "!" + guards_.back();
            return;
        }

        string condition = Utils::PrintStmt(node,contex_);

        if ( isa<DeclRefExpr>(node->IgnoreParenCasts()) ) { // The condition is "if (var)" change it to "if (var != 0)"
            stringstream ss;
            ss << '(' << condition << " != 0)";
            condition = ss.str();
        }

        stringstream guard_ss;
        guard_ss << Defines::kGuardPrefix << Utils::ConditionToGuard(condition);
        (*ss_ptr_) << "{\n" << Defines::kGuardType << " " << guard_ss.str() << " = 1;\n";
        // consider initialize flags
        if ( init )
            (*ss_ptr_) << GetGuard() << guard_ss.str() << " = (" << condition << ");\n";
        guards_.push_back(guard_ss.str());
        

//      (*ss_ptr_) << "{\n" << Defines::kGuardType << " " << Defines::kGuardPrefix << ++guard_ctr_ << " = 1;\n";
//
//      // consider initialize flags
//      if ( init )
//          (*ss_ptr_) << GetGuard() << Defines::kGuardPrefix << guard_ctr_ << " = (" << condition << ");\n";
//
//      stringstream guard_ss;
//      guard_ss << "/*" << condition << "*/" << Defines::kGuardPrefix << guard_ctr_;
//      guards_.push_back(guard_ss.str());
    }


    void GuardedInstructions::PopCondition() {
        guards_.pop_back();
        (*ss_ptr_) << "}\n";
    }

    void GuardedInstructions::PushLabel(unsigned l) {
        labels_.push_back(l);
    }

    void GuardedInstructions::PopLabel() {
        labels_.pop_back();
    }


/*

    void GuardedInstructions::Visit(Decl *node) {
        if (!node)
            return;
        BaseDeclVisitor::Visit(node);
    }


    void GuardedInstructions::VisitDeclaratorDecl(DeclaratorDecl *node) {
        BaseDeclVisitor::VisitDeclaratorDecl(node);
        if (TypeSourceInfo *TInfo = node->getTypeSourceInfo())
            Visit(TInfo->getTypeLoc());
    }


    void GuardedInstructions::VisitBlockDecl(BlockDecl *node) {
        BaseDeclVisitor::VisitBlockDecl(node);
        Visit(node->getBody());
    }



    void GuardedInstructions::VisitParmVarDecl(ParmVarDecl * P) {

    }

    void GuardedInstructions::VisitDeclRefExpr(DeclRefExpr* E) {

    }

    void GuardedInstructions::VisitDecl(Decl *node) {
        if (isa<FunctionDecl>(node) || isa<ObjCMethodDecl>(node) || isa<BlockDecl>(node))
            return;

        if (DeclContext *DC = dyn_cast<DeclContext>(node))
            VisitDeclContext(DC);
    }

    void GuardedInstructions::VisitDeclContext(DeclContext *DC) {
        for (DeclContext::decl_iterator
             I = DC->decls_begin(), E = DC->decls_end(); I != E; ++I)
            Visit(*I);

    }

//===--------------------------------------------------------------------===//
// StmtVisitor
//===--------------------------------------------------------------------===//

    void GuardedInstructions::VisitStmt(Stmt *node) {
        VisitChildren(node);
    }



    void GuardedInstructions::VisitBlockExpr(BlockExpr *node) {
        // The BlockDecl is also visited by 'VisitDeclContext()'.
        // No need to visit it twice.
    }

//===--------------------------------------------------------------------===//
// TypeLocVisitor
//===--------------------------------------------------------------------===//

    void GuardedInstructions::Visit(TypeLoc TL) {
        for (; TL; TL = TL.getNextTypeLoc())
            BaseTypeLocVisitor::Visit(TL);
    }

    void GuardedInstructions::VisitArrayLoc(ArrayTypeLoc TL) {
        BaseTypeLocVisitor::VisitArrayTypeLoc(TL);
        if (TL.getSizeExpr())
            Visit(TL.getSizeExpr());
    }

    void GuardedInstructions::VisitFunctionTypeLoc(FunctionTypeLoc TL) {
        BaseTypeLocVisitor::VisitFunctionTypeLoc(TL);
        for (unsigned i = 0; i != TL.getNumArgs(); ++i)
            Visit(TL.getArg(i));
    }
*/
}
