#ifndef ANALYZER_UNION_CONSUMER_H
#define ANALYZER_UNION_CONSUMER_H

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

class Unioner : public DeclVisitor<Unioner>,
public StmtVisitor<Unioner>,
public TypeLocVisitor<Unioner>
{

public:

	SourceManager  &source_manager_;
	ASTContext     &contex_;
	Rewriter       &rewriter_;

	Unioner(Rewriter& rewriter, SourceManager &source_manager,ASTContext &contex) :
		source_manager_(source_manager), contex_(contex), rewriter_(rewriter) { }

	virtual ~Unioner() { }

	typedef DeclVisitor<Unioner> BaseDeclVisitor;
	typedef StmtVisitor<Unioner> BaseStmtVisitor;
	typedef TypeLocVisitor<Unioner> BaseTypeLocVisitor;

	using BaseStmtVisitor::Visit;
   using BaseDeclVisitor::Visit;
   using BaseTypeLocVisitor::Visit;

};

class UnionerASTConsumer : public ASTConsumer {
	SourceManager  *source_manager_;
	Rewriter       &rewriter_;

public:
    TranslationUnitDecl *unit_ptr_;

	UnionerASTConsumer(Rewriter& rewriter) : rewriter_(rewriter_), unit_ptr_(0) {}

	virtual ~UnionerASTConsumer() { delete unit_ptr_; }

	virtual void Initialize(ASTContext &context) {
		source_manager_ = &context.getSourceManager();
	}

	virtual void HandleTranslationUnit(ASTContext &context) {
		// called when everything is done
        unit_ptr_ = new TranslationUnitDecl(*context.getTranslationUnitDecl());
	}
};

}

#endif
