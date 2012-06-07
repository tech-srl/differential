#ifndef ANALYZER_TAG_CONSUMER_H
#define ANALYZER_TAG_CONSUMER_H

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

   class TagInstructions : public DeclVisitor<TagInstructions>,
   public StmtVisitor<TagInstructions>,
   public TypeLocVisitor<TagInstructions> {

   public:
      Rewriter       &rewriter_;
      SourceManager  &source_manager_;
      ASTContext     &contex_;
      stringstream   *assertion_ss_ptr;

      unsigned asserts_ctr_;

      const bool add_asserts_;
      const bool tag_equality_;
      bool is_l_value_;

      TagInstructions(Rewriter &rewriter, ASTContext &contex, bool tag_equality, bool add_asserts) :
          rewriter_(rewriter), source_manager_(rewriter_.getSourceMgr()), contex_(contex), 
          asserts_ctr_(0), tag_equality_(tag_equality), add_asserts_(add_asserts), is_l_value_(false)  {
            assertion_ss_ptr = new stringstream();
          }

      typedef DeclVisitor<TagInstructions> BaseDeclVisitor;
      typedef StmtVisitor<TagInstructions> BaseStmtVisitor;
      typedef TypeLocVisitor<TagInstructions> BaseTypeLocVisitor;

      using BaseDeclVisitor::Visit;
      using BaseStmtVisitor::Visit;
      using BaseTypeLocVisitor::Visit;

      void VisitFunctionDecl(FunctionDecl *node) ;
      void VisitDeclStmt(DeclStmt *node);
      void VisitVarDecl(VarDecl *node);
      void VisitDeclRefExpr(DeclRefExpr *node);
      void VisitStmt(Stmt *node);
      void VisitLabelStmt(LabelStmt *node);
      void VisitBinaryOperator(BinaryOperator * node);
      void VisitUnaryOperator(UnaryOperator * node);
      void VisitGotoStmt(GotoStmt * node);
      void VisitChildren(Stmt *node);
   };

   class TagInstructionsASTConsumer : public ASTConsumer {
       SourceManager    &source_manager_;
       Rewriter         &rewriter_;
       const bool tag_equality_;
       const bool add_asserts_;

   public:

      TagInstructionsASTConsumer(Rewriter& rewriter, bool tag_equality, bool add_asserts) : 
      rewriter_(rewriter), source_manager_(rewriter.getSourceMgr()), tag_equality_(tag_equality), add_asserts_(add_asserts)  {}

      virtual ~TagInstructionsASTConsumer() {}

      virtual void HandleTranslationUnit(ASTContext &contex) {
         // called when everything is done
         TagInstructions tagger(rewriter_, contex, tag_equality_, add_asserts_);
         TranslationUnitDecl *unit_ptr = contex.getTranslationUnitDecl();
         if (add_asserts_)
             rewriter_.InsertText(source_manager_.getLocForStartOfFile(source_manager_.getMainFileID()), "#include <assert.h>\n");
         for (DeclContext::decl_iterator iter = unit_ptr->decls_begin(), end = unit_ptr->decls_end(); iter != end; ++iter) 
            tagger.Visit(*iter);
         string filename = Defines::kTaggedFilenamePrefix + source_manager_.getFileEntryForID(source_manager_.getMainFileID())->getName();
         Utils::WriteFiles(rewriter_,filename);
      }
   };

}
 
#endif



