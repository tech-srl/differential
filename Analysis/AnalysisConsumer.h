#ifndef ANALYZER_ANALYSIS_CONSUMER_H
#define ANALYZER_ANALYSIS_CONSUMER_H

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std; 

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclGroup.h>
#include <clang/Analysis/AnalysisContext.h>
#include <clang/Analysis/Analyses/UninitializedValues.h>
#include <clang/Analysis/Analyses/LiveVariables.h>
#include <clang/Analysis/Analyses/ReachableCode.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/Basic/Diagnostic.h>
using namespace clang;

#include "APAbstractDomain.h"
#include "TransferFuncs.h"

namespace differential {

class AnalysisConsumer : public ASTConsumer {
	SourceManager           *source_manager_ptr_;
	AnalysisContextManager  contex_manager_;
	DiagnosticsEngine       &diagnostics_engine_;
    Preprocessor            *preprocessor_ptr_;
	ostream&                report_file_;
	bool 					compute_diff_;
public:
	AnalysisConsumer(ASTContext &contex, DiagnosticsEngine &diagnostics_engine, Preprocessor * preprocessor_ptr, ostream& report_file, bool compute_diff) :
        diagnostics_engine_(diagnostics_engine), preprocessor_ptr_(preprocessor_ptr), report_file_(report_file), compute_diff_(compute_diff) {
		source_manager_ptr_ = &contex.getSourceManager();
	}

	void HandleTranslationUnit(ASTContext &contex);
	void AnalyzeFunction(CFG& cfg, ASTContext &contex, unsigned &report_ctr);

};

} // end namespace differential

#endif
