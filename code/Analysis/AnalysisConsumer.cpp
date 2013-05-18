#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclGroup.h>
#include <clang/Analysis/AnalysisContext.h>
#include "clang/Analysis/Analyses/UninitializedValues.h"
#include "clang/Analysis/Analyses/LiveVariables.h"
#include <clang/Analysis/Analyses/ReachableCode.h>
#include "clang/AST/Decl.h"
#include "clang/AST/DeclObjC.h"
#include "clang/AST/DeclTemplate.h"
#include <clang/Basic/Diagnostic.h>
using namespace clang;

#include "AnalysisConsumer.h"

namespace differential {

// Here we define all the is needed for the correlating program solver

struct Merge {
    void operator()(State& Dst, State& Src) { Dst |= Src; }
};

struct LowerOrEqual {
    bool operator()(State& Dst, State& Src) { return(Dst <= Src); }
};

typedef DataflowSolver<APAbstractDomain,TransferFuncs,Merge,LowerOrEqual> Solver;

void AnalysisConsumer::AnalyzeFunction(CFG& cfg, ASTContext &contex, unsigned &report_ctr) {
        // Compute the ranges information.
    	cfg.print(llvm::outs(),LangOptions());
        APAbstractDomain Dom(cfg);
        Dom.InitializeValues(cfg);
        APChecker Observer(contex,diagnostics_engine_, preprocessor_ptr_);
        Dom.getAnalysisData().Observer = &Observer;
        Dom.getAnalysisData().setContext(contex);
        Solver S(Dom);
        S.runOnCFG(cfg, true);
        Observer.ObserveFixedPoint(true, compute_diff_, report_ctr);
    }

void AnalysisConsumer::HandleTranslationUnit(ASTContext &contex) { // called when everything is done
		TranslationUnitDecl *tran_unit_ptr = contex.getTranslationUnitDecl();
		AnalysisContextManager context_manager;
		unsigned report_ctr = 0;

		for (DeclContext::decl_iterator iter = tran_unit_ptr->decls_begin(), end = tran_unit_ptr->decls_end(); iter != end; ++iter) {
			// Only handle declarations with bodies
			if (const FunctionDecl *FD = dyn_cast<FunctionDecl>(*iter)) {
				if (!FD->isThisDeclarationADefinition())
					continue;
                FD->print(llvm::outs());
				CFG * cfg_ptr = context_manager.getContext(FD)->getCFG();
				if (cfg_ptr) {
//					string error;
//					llvm::raw_fd_ostream os("cfg-file",error);
//					cfg_ptr->print(os,LangOptions());
					AnalyzeFunction(*cfg_ptr, contex, report_ctr);
				}
			}
		}
		report_file_ << setw(6) << report_ctr << " | ";
	}

}


