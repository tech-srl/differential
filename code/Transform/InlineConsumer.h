#ifndef ANALYZER_INLINE_CONSUMER_H
#define ANALYZER_INLINE_CONSUMER_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclGroup.h>
#include <clang/AST/DeclarationName.h>
#include <clang/AST/StmtVisitor.h>
#include <clang/AST/DeclVisitor.h>
#include <clang/AST/TypeLocVisitor.h>
#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Rewrite/Rewriter.h>
using namespace clang;
using namespace llvm;

#include "../Utils.h"
#include "../Defines.h"

namespace differential {

class Inliner : public DeclVisitor<Inliner>,
public StmtVisitor<Inliner>,
public TypeLocVisitor<Inliner>
{

public:

	SourceManager  &source_manager_;
	ASTContext     &contex_;
	Rewriter       &main_rewriter_;
   Rewriter       rewriter_;

    vector<string> return_vars_; // a stack of return value accepters (i.e. x = foo(...))
    string        body_;
    unsigned      balance_;

    static unsigned  replacements_; // count the number of inline replacements made so far
    FunctionDecl     *current_func_;
    Stmt             *current_stmt_;

	Inliner(Rewriter &rewriter, SourceManager &source_manager,ASTContext &contex) :
		source_manager_(source_manager), contex_(contex), main_rewriter_(rewriter), rewriter_(source_manager_,contex.getLangOptions()), 
        balance_(0), current_func_(0), current_stmt_(0) { }

	virtual ~Inliner() { }

	typedef DeclVisitor<Inliner> BaseDeclVisitor;
	typedef StmtVisitor<Inliner> BaseStmtVisitor;
	typedef TypeLocVisitor<Inliner> BaseTypeLocVisitor;

   using BaseDeclVisitor::Visit;
	using BaseStmtVisitor::Visit;
   using BaseTypeLocVisitor::Visit;

   void VisitFunctionDecl(FunctionDecl *node);
   void VisitCallExpr(CallExpr *node);
   void VisitReturnStmt(ReturnStmt *node);
   void VisitBinaryOperator(BinaryOperator * node);
   void VisitStmt(Stmt *node);
   void VisitChildren(Stmt *node);
/*
	void Visit(Decl *node);
	void VisitDeclaratorDecl(DeclaratorDecl *node);
	void VisitBlockDecl(BlockDecl *node);
	void VisitVarDecl(VarDecl *node);
	void VisitParmVarDecl(ParmVarDecl * node) ;
	void VisitDeclRefExpr(DeclRefExpr* node);
	void VisitDecl(Decl *node) ;
	void VisitDeclContext(DeclContext *node);

	//===--------------------------------------------------------------------===//
	// StmtVisitor
	//===--------------------------------------------------------------------===//

	
	void VisitDeclStmt(DeclStmt *node);
	void VisitBlockExpr(BlockExpr *node);
	void VisitForStmt(ForStmt *node);
	void VisitWhileStmt(WhileStmt *node);
	void VisitDoStmt(DoStmt *node);
	void VisitContinueStmt(ContinueStmt* node);
	void VisitBreakStmt(BreakStmt* node);
	void VisitSwitchStmt(SwitchStmt *node);
	void VisitSwitchCase(SwitchCase *node) ;
	void VisitDefaultStmt(DefaultStmt *node) ;

	void VisitIfStmt(IfStmt *node);
	void VisitCallExpr(CallExpr *node);
    void VisitChooseExpr(ChooseExpr * node);
	void VisitLabelStmt(LabelStmt * node);
	void VisitCompoundAssignOperator(CompoundAssignOperator *node);
	void VisitCompoundStmt(CompoundStmt *node);
	void VisitReturnStmt(ReturnStmt *node);
	void VisitConditionalOperator(ConditionalOperator* node);
	
	void VisitUnaryOperator(UnaryOperator * node);
	void VisitGotoStmt(GotoStmt * node);

	//===--------------------------------------------------------------------===//
	// TypeLocVisitor
	//===--------------------------------------------------------------------===//

	void Visit(TypeLoc node);
	void VisitArrayLoc(ArrayTypeLoc node);
	void VisitFunctionTypeLoc(FunctionTypeLoc node);

*/
};

class InlinerASTConsumer : public ASTConsumer {
	SourceManager  *source_manager_ptr_;
	Rewriter       &rewriter_;

public:

	InlinerASTConsumer(Rewriter& rewriter) : rewriter_(rewriter) {}

	virtual ~InlinerASTConsumer() {}

	virtual void Initialize(ASTContext &contex) {
		source_manager_ptr_ = &contex.getSourceManager();
	}

	virtual void HandleTranslationUnit(ASTContext &contex) {
		// called when everything is done
		string filename = Defines::kInlinedFilenamePrefix + source_manager_ptr_->getFileEntryForID(source_manager_ptr_->getMainFileID())->getName();
		Inliner inliner(rewriter_, *source_manager_ptr_, contex);
		TranslationUnitDecl *unit = contex.getTranslationUnitDecl();
		for (DeclContext::decl_iterator iter = unit->decls_begin(), end = unit->decls_end(); iter != end; ++iter) {
			FunctionDecl *node = dyn_cast<FunctionDecl>(*iter);
            if (node && node->isMain()) { // start from main and recursivly visit all calls
                inliner.Visit(node);
            }
			
		}
		Utils::WriteFiles(rewriter_,filename);
	}
};

}

#endif
