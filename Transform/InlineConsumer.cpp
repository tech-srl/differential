
#include "InlineConsumer.h"

namespace differential {

unsigned Inliner::replacements_ = 0;

void Inliner::VisitFunctionDecl(FunctionDecl *node) {
    FunctionDecl * caller_func = current_func_;
    current_func_ = node;
	if (node->isThisDeclarationADefinition()) {
        replacements_++;
		Visit(node->getBody());
        stringstream ss;
        ss << rewriter_.getRewrittenText(node->getSourceRange());
        // balance the parenthesis added by the return guards
        while (balance_-- > 0)
            ss << "\n}";
        // save the inlined function for external use
        string function = ss.str();
        body_ = function.substr(function.find("{")); // remove the prototype
	}
    current_func_ = caller_func;
}


// Replace function calls with body
void Inliner::VisitCallExpr(CallExpr *node) {
    FunctionDecl * calee_ptr = node->getDirectCallee();
    if (!calee_ptr || !calee_ptr->hasBody()) {
        return;
    }

    // Visit the body and prefix all DeclRefs and Labels
    //string prefixed_body = PrefixFunc(fd);

    // Replace returns with goto + assignment

    // replace the prototype with locals and connect to the call arguments
    //if (functions_.count(calee_ptr) == 0) {
    Inliner inliner(rewriter_,source_manager_,contex_);
    inliner.VisitFunctionDecl(calee_ptr);
    //}


    stringstream ss;
    string calee_name = calee_ptr->getNameAsString();
    // add a start label (just for readability)
    ss << "{\n/*" << Defines::kLabelStart << calee_name << replacements_ << ":*/\n";
    // put in the arguments, start with RetVal and Ret
    string result_type = calee_ptr->getResultType().getAsString();
    if (result_type != "void") 
        ss << result_type << " " << Defines::kRetVal << "_" << calee_name << replacements_ << ";\n";
    ss << Defines::kGuardType << " " << Defines::kRetGuard << "_" << calee_name << replacements_ << " = 0;\n";
    // use temporary variables to transfer arguments to avoid this: 
    //  double foo(int x) { // foo body } main() { y = foo(x); }
    // turning into this:
    //  main () {
    //      {
    //          int tmp_x = x;
    //          double retval;
    //          {
    //              int x = tmp_x;
    //              // foo body
    //          }
    //          y = retval;
    //      }
    //  }
    stringstream temps, params;
    for (size_t i = 0; i < calee_ptr->getNumParams() ; ++i) {
        ParmVarDecl * param_ptr = calee_ptr->getParamDecl(i);
        string decl = Utils::PrintDecl(param_ptr,contex_);
        string name = param_ptr->getNameAsString();
        string type = decl.substr(0,decl.find_last_of(name) - name.size() + 1);
        temps << type << Defines::kTempPrefix << calee_name << "_" << name << replacements_<< " = " << Utils::PrintStmt(node->getArg(i),contex_) << ";\n";
        params << decl << " = " << Defines::kTempPrefix << calee_name << "_" << name << replacements_ << ";\n";
    }
    ss << temps.str() << "{\n" << params.str();
    // put in the inlined body
    ss << inliner.body_;
    ss << "\n}\n";
    // add the end label (just for readability)
    ss << "/*" << Defines::kLabelEnd << calee_name << replacements_ << ":*/\n";
    // connect the return value
    if (!return_vars_.empty()) {
        ss << return_vars_.back() << " = " << Defines::kRetVal << "_" << calee_name << replacements_;
    }
    ss << ";\n";
    ss << "}\n";

    SourceLocation start = node->getSourceRange().getBegin();
    Rewriter &rw = (current_func_->isMain()) ? main_rewriter_ : rewriter_;
    rw.ReplaceText(start, Utils::GetStmtLength(node),ss.str());
}

void Inliner::VisitReturnStmt(ReturnStmt *node)
{
    // Visit the return value
    Visit(node->getRetValue());
    // No handling for main
    if (current_func_->isMain())
        return;
    string calee_name = current_func_->getNameAsString();
    stringstream ss;
    ss << "{" << Defines::kRetVal << "_" << calee_name << replacements_ << " = " << Utils::PrintStmt(node->getRetValue(),contex_) << ";";
    ss << Defines::kRetGuard << "_" << calee_name << replacements_  << " = 1;}\n";
    // guard the rest of the function
    ss << "if (!" << Defines::kRetGuard << "_" << calee_name << replacements_ << ") {\n";
    balance_++;
    SourceLocation start = node->getSourceRange().getBegin();
    Rewriter &rewriter = (current_func_->isMain()) ? main_rewriter_ : rewriter_;
    rewriter.ReplaceText(start, Utils::GetStmtLength(node), ss.str());
}

void Inliner::VisitBinaryOperator(BinaryOperator * node) {
    Expr * lhs = node->getLHS(), * rhs = node->getRHS();
    CallExpr * call = dyn_cast<CallExpr>(rhs);
    if (call && call->getDirectCallee()->isThisDeclarationADefinition()) { // replace: x = foo(y); with: /*x = */ { //inlined foo }
        Rewriter &rewriter = (current_func_->isMain()) ? main_rewriter_ : rewriter_;
        rewriter.InsertText(lhs->getLocStart(),"/*");
        rewriter.InsertText(rhs->getLocStart(),"*/"); 
    }
    return_vars_.push_back(Utils::PrintStmt(lhs,contex_));
    VisitChildren(node);
    return_vars_.pop_back();
}


void Inliner::VisitStmt(Stmt *node) {
	VisitChildren(node);
}

void Inliner::VisitChildren(Stmt *node) {
	for(Stmt::child_iterator I = node->child_begin(), E = node->child_end();I != E;++I)
		if(*I) Visit(*I);
}

/*

void Inliner::Visit(Decl *node) {
	if (!node)
		return;
	BaseDeclVisitor::Visit(node);
}


void Inliner::VisitDeclaratorDecl(DeclaratorDecl *node) {
	BaseDeclVisitor::VisitDeclaratorDecl(node);
	if (TypeSourceInfo *TInfo = node->getTypeSourceInfo())
		Visit(TInfo->getTypeLoc());
}



void Inliner::VisitBlockDecl(BlockDecl *node) {
	BaseDeclVisitor::VisitBlockDecl(node);
	Visit(node->getBody());
}

void Inliner::VisitVarDecl(VarDecl *node) {
	BaseDeclVisitor::VisitVarDecl(node);
}

void Inliner::VisitParmVarDecl(ParmVarDecl * P) {

}

void Inliner::VisitDeclRefExpr(DeclRefExpr* E) {

}

void Inliner::VisitDecl(Decl *node) {
	if (isa<FunctionDecl>(node) || isa<ObjCMethodDecl>(node) || isa<BlockDecl>(node))
		return;

	if (DeclContext *DC = dyn_cast<DeclContext>(node))
		VisitDeclContext(DC);
}
 
void Inliner::VisitDeclContext(DeclContext *DC) {
	for (DeclContext::decl_iterator
			I = DC->decls_begin(), E = DC->decls_end(); I != E; ++I)
		Visit(*I);

}
 
//===--------------------------------------------------------------------===//
// StmtVisitor
//===--------------------------------------------------------------------===//



void Inliner::VisitDeclStmt(DeclStmt *node) {
	for (DeclStmt::decl_iterator
			I = node->decl_begin(), E = node->decl_end(); I != E; ++I)
		Visit(*I);
}

void Inliner::VisitBlockExpr(BlockExpr *node) {
	// The BlockDecl is also visited by 'VisitDeclContext()'.
	// No need to visit it twice.
}

void Inliner::VisitForStmt(ForStmt *node) {
    VisitChildren(node);
}

void Inliner::VisitWhileStmt(WhileStmt *node) {
	VisitChildren(node);
}

void Inliner::VisitDoStmt(DoStmt *node) {
	VisitChildren(node);
}

void Inliner::VisitContinueStmt(ContinueStmt* node) {

}

void Inliner::VisitBreakStmt(BreakStmt* node) {

}

void Inliner::VisitSwitchStmt(SwitchStmt *node) {
	VisitChildren(node);
}

void Inliner::VisitSwitchCase(SwitchCase *node) {
	VisitChildren(node);
}

void Inliner::VisitDefaultStmt(DefaultStmt *node) {
	VisitChildren(node);
}


void Inliner::VisitIfStmt(IfStmt *node)
{
    VisitChildren(node);
}

void Inliner::VisitLabelStmt(LabelStmt * node) {
	Visit(node->getSubStmt());
}

void Inliner::VisitCompoundAssignOperator(CompoundAssignOperator *node) {
	VisitChildren(node);
}

void Inliner::VisitCompoundStmt(CompoundStmt *node) {
	VisitChildren(node);
}



void Inliner::VisitConditionalOperator(ConditionalOperator* node) {
		VisitChildren(node);
}

void Inliner::VisitChooseExpr(ChooseExpr * node) {
        VisitChildren(node);
}

void Inliner::VisitBinaryOperator(BinaryOperator * node) {
    //return_vars_.push_back(Utils::PrintStmt(node->getLHS(),contex_));
    VisitChildren(node);
    //return_vars_.pop_back();
}
void Inliner::VisitUnaryOperator(UnaryOperator * node) {
		VisitChildren(node);
}
void Inliner::VisitGotoStmt(GotoStmt * node) {
		VisitChildren(node);
}

//===--------------------------------------------------------------------===//
// TypeLocVisitor
//===--------------------------------------------------------------------===//

void Inliner::Visit(TypeLoc TL) {
	for (; TL; TL = TL.getNextTypeLoc())
		BaseTypeLocVisitor::Visit(TL);
}

void Inliner::VisitArrayLoc(ArrayTypeLoc TL) {
	BaseTypeLocVisitor::VisitArrayTypeLoc(TL);
	if (TL.getSizeExpr())
		Visit(TL.getSizeExpr());
}

void Inliner::VisitFunctionTypeLoc(FunctionTypeLoc TL) {
	BaseTypeLocVisitor::VisitFunctionTypeLoc(TL);
	for (unsigned i = 0; i != TL.getNumArgs(); ++i)
		Visit(TL.getArg(i));
}


*/
}
