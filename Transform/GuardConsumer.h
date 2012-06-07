#ifndef ANALYZER_GUARD_CONSUMER_H
#define ANALYZER_GUARD_CONSUMER_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
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

class GuardedInstructions : public DeclVisitor<GuardedInstructions>,
public StmtVisitor<GuardedInstructions>,
public TypeLocVisitor<GuardedInstructions>
{
	SourceManager  &source_manager_;
	ASTContext     &contex_;
    Rewriter      &rewriter_;

    bool ret_guard_;
    bool save_initial_;

    unsigned guard_ctr_;
    unsigned label_ctr_;
    unsigned diff_point_ctr_;

    string label_prefix_;
    string case_guard_;
    string return_type_;

    stringstream * ss_ptr_;

	vector<string> guards_;
    vector<unsigned> labels_;
    vector<string> switch_vars_;

	void GuardAndPrint(Stmt * node);
	string GetGuard();
	void VisitExtract(Expr * node);
	void PushCondition(Expr * node, bool negate = false, bool init = true);
	void PopCondition();
	void PushLabel(unsigned l);
	void PopLabel();

public:

	GuardedInstructions(Rewriter& rewriter, SourceManager& source_manager,ASTContext &contex, bool ret_guard, bool save_initial) :
		source_manager_(source_manager), contex_(contex), ret_guard_(ret_guard), save_initial_(save_initial), guard_ctr_(0), 
        label_prefix_(Defines::kLabelPrefix), label_ctr_(0), ss_ptr_(new stringstream()), rewriter_(rewriter), diff_point_ctr_(0) {
		if (!source_manager_.getFileEntryForID(source_manager_.getMainFileID()))
			return;
	}

	virtual ~GuardedInstructions() { delete ss_ptr_; }

	typedef DeclVisitor<GuardedInstructions> BaseDeclVisitor;
	typedef StmtVisitor<GuardedInstructions> BaseStmtVisitor;
	typedef TypeLocVisitor<GuardedInstructions> BaseTypeLocVisitor;

   using BaseDeclVisitor::Visit;
	using BaseStmtVisitor::Visit;
   using BaseTypeLocVisitor::Visit;

   void VisitFunctionDecl(FunctionDecl *D);
   void VisitVarDecl(VarDecl *D);

   /*
	void Visit(Decl *D);
	void VisitDeclaratorDecl(DeclaratorDecl *D);
	void VisitBlockDecl(BlockDecl *D);
	void VisitParmVarDecl(ParmVarDecl * P) ;
	void VisitDeclRefExpr(DeclRefExpr* E);
	void VisitDecl(Decl *D) ;
	void VisitDeclContext(DeclContext *DC);
   */

	//===--------------------------------------------------------------------===//
	// StmtVisitor
	//===--------------------------------------------------------------------===//

	void VisitDeclStmt(DeclStmt *node);
	void VisitForStmt(ForStmt *node);
	void VisitWhileStmt(WhileStmt *node);
	void VisitDoStmt(DoStmt *node);
	void VisitContinueStmt(ContinueStmt* node);
	void VisitBreakStmt(BreakStmt* node);
	void VisitSwitchStmt(SwitchStmt *node);
	void VisitSwitchCase(SwitchCase *node) ;
	void VisitDefaultStmt(DefaultStmt *node) ;
//	void VisitStmt(Stmt *node);
//	void VisitBlockExpr(BlockExpr *node); 
 
	void VisitIfStmt(IfStmt *node);
	void VisitCallExpr(CallExpr *node);
	void VisitLabelStmt(LabelStmt * node);
	void VisitCompoundAssignOperator(CompoundAssignOperator *node);
	void VisitCompoundStmt(CompoundStmt *node);
	void VisitReturnStmt(ReturnStmt *node);
	void VisitConditionalOperator(ConditionalOperator* node);
	void VisitBinaryOperator(BinaryOperator * node);
	void VisitUnaryOperator(UnaryOperator * node);
	void VisitGotoStmt(GotoStmt * node);
   void VisitChildren(Stmt *node);

   /* 
	//===--------------------------------------------------------------------===//
	// TypeLocVisitor
	//===--------------------------------------------------------------------===//

	void Visit(TypeLoc TL);
	void VisitArrayLoc(ArrayTypeLoc TL);
	void VisitFunctionTypeLoc(FunctionTypeLoc TL);
   */
};

class GuardedInstructionsASTConsumer : public ASTConsumer {
	Rewriter       &rewriter_;
    bool          ret_guard_;
    bool          save_initial_;

public:

	GuardedInstructionsASTConsumer(Rewriter& rewriter, bool ret_guard, bool save_initial) : rewriter_(rewriter), ret_guard_(ret_guard), save_initial_(save_initial) {}

	virtual ~GuardedInstructionsASTConsumer() {}

	virtual void Initialize(ASTContext &context) { }

	virtual void HandleTranslationUnit(ASTContext &Ctx) {
		// called when everything is done
        SourceManager &source_manager = Ctx.getSourceManager();
		string filename = source_manager.getFileEntryForID(source_manager.getMainFileID())->getName();
        GuardedInstructions guarder(rewriter_, source_manager, Ctx, ret_guard_, save_initial_);
		TranslationUnitDecl *tu = Ctx.getTranslationUnitDecl();

        // add the guards typedef
        rewriter_.InsertText(source_manager.getLocForStartOfFile(source_manager.getMainFileID()), Defines::kGuardTypedef + Defines::kRetGuardTypedef);

		for (DeclContext::decl_iterator iter = tu->decls_begin(), end = tu->decls_end(); iter != end; ++iter) 
			guarder.Visit(*iter);
		Utils::WriteFiles(rewriter_,filename);
	}
};

}

#endif



