#include <iostream>
#include <iomanip>
#include <vector>
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
/*
void AnalysisConsumer::HandleTranslationUnit(ASTContext &contex) {
		// called when everything is done

		TranslationUnitDecl *TU = contex.getTranslationUnitDecl();
		AnalysisContextManager anaCtxMgr;
		unsigned report_ctr = 0;

		for (DeclContext::decl_iterator I = TU->decls_begin(), E = TU->decls_end(); I != E; ++I) {
			Decl *D = *I;
			AnalysisContext * anaCtx = 0;
			CFG * cfg = 0;
			// Only handle declarations with bodies
			if (const FunctionDecl *FD = dyn_cast<FunctionDecl>(D)) {
				if (!FD->isThisDeclarationADefinition())
					continue; 
                FD->print(llvm::outs());
				anaCtx = anaCtxMgr.getContext(FD);
				cfg = anaCtx->getCFG();
			}

			if (cfg) {
				CheckLinEq(*cfg, contex, diagnostics_engine_, preprocessor_ptr_, report_ctr);
			}
		}
		report_file_ << setw(6) << report_ctr << " | ";
	}
}
*/
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
					string error;
					llvm::raw_fd_ostream os("cfg-file",error);
					cfg_ptr->print(os,LangOptions());
					CheckLinEq(*cfg_ptr, contex, diagnostics_engine_, preprocessor_ptr_, report_ctr, compute_diff_);
				}
			}
		}
		report_file_ << setw(6) << report_ctr << " | ";
	}
}


