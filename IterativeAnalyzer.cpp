
#include "apronxx/apronxx.hh"
#include "apronxx/apxx_box.hh"
#include "apronxx/apxx_oct.hh"
#include "apronxx/apxx_polka.hh"
#include "apronxx/apxx_ppl.hh"
#include "apronxx/apxx_ppl_product.hh"
using namespace apron;


#include "IterativeAnalyzer.h"
#include "Analysis/APAbstractDomain.h"
#include "Analysis/IterativeSolver.h"
#include "Analysis/AnalysisConfiguration.h"

#include "DTL/dtl.hpp"
#include "DTL/variables.hpp"
using namespace dtl;

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
using namespace std;

#define DEBUG 0

extern llvm::cl::opt<string>  InputFilename;
extern llvm::cl::opt<string>  InputFilename2;
extern llvm::cl::list<string> IgnoredParams;
extern llvm::cl::list<string> DefinedMacros;
extern llvm::cl::list<string> IncludeDirs;
extern llvm::cl::list<string> ManagerType;
extern llvm::cl::list<string> PartitionPoint;
extern llvm::cl::list<string> PartitionStrategy;
extern llvm::cl::list<string> WideningPoint;
extern llvm::cl::list<string> WideningStrategy;
extern llvm::cl::list<string> WideningThreshold;
extern llvm::cl::list<string> Interleaving;
extern llvm::cl::list<string> InterleavingLookaheadWindow;
extern llvm::cl::list<string> InterleavingLookaheadPartition;
extern llvm::cl::list<string> ProveEquiv;

namespace differential {

    int IterativeAnalyzer::Main(int argc, char* argv[]) {
        CodeHandler::Init(argc,argv);
        IterativeAnalyzer().RunAnalysis();
        return 0;
    }

    IterativeAnalyzer::IterativeAnalyzer() {  }

    /**
     * Run the analysis on 2 files
     */
    void IterativeAnalyzer::RunAnalysis(ostream& report_file) {
    	// parse configuration
    	if (WideningStrategy.size() == 0) { // set the default widening strategy to be by-equivalence (guards are not supported so far)
    		WideningStrategy.addValue(AnalysisConfiguration::kWideningStrategyEquiv);
		}
    	AnalysisConfiguration::PrintConfigurationHeader();
    	APAbstractDomain::ValTy::mgr_ptr_ = AnalysisConfiguration::ParseManager(ManagerType);
    	APAbstractDomain::ValTy::partition_point_ = AnalysisConfiguration::ParsePartitionPoint(PartitionPoint);
    	APAbstractDomain::ValTy::partition_strategy_ = AnalysisConfiguration::ParsePartitionStrategy(PartitionStrategy);
    	APAbstractDomain::ValTy::widening_point_ = AnalysisConfiguration::ParseWideningPoint(WideningPoint);
    	APAbstractDomain::ValTy::widening_strategy_ = AnalysisConfiguration::ParseWideningStrategy(WideningStrategy);
    	APAbstractDomain::ValTy::widening_threshold_ = AnalysisConfiguration::ParseWideningThreshold(WideningThreshold);
    	AnalysisConfiguration::Interleaving interleaving = AnalysisConfiguration::ParseInterleaving(Interleaving);
    	int k = AnalysisConfiguration::ParseInterleavignLookaheadWindow(InterleavingLookaheadWindow);
    	int p = AnalysisConfiguration::ParseInterleavignLookaheadPartition(InterleavingLookaheadPartition);
    	bool prove_equivalence = AnalysisConfiguration::ParseProveEquiv(ProveEquiv);
    	AnalysisConfiguration::PrintConfigurationFooter();

    	// extract an AST from each of the files
    	CodeHandler code(InputFilename), code2(InputFilename2);
    	ASTContext * contex_ptr = code.getAST(),
    			   * contex2_ptr = code2.getAST();

    	// place functions in a map according to name (so they are easily matched)
		map<string,const FunctionDecl*> functions, functions2;
		Utils::CreateFunctionsMap(contex_ptr->getTranslationUnitDecl(),functions);
		Utils::CreateFunctionsMap(contex2_ptr->getTranslationUnitDecl(),functions2);

    	// the context manager is needed to produce a CFG
		AnalysisContextManager context_manager;
		// iterate over functions, match them, and perform the dual analysis
		for (map<string,const FunctionDecl*>::const_iterator iter = functions.begin(), end = functions.end(); iter != end; ++iter) {
			const FunctionDecl* fd = iter->second;
			if (!fd->isThisDeclarationADefinition())
				continue;
			const FunctionDecl* fd2 = functions2[iter->first];
			if (!fd2) // no matching for the function in the 2nd AST
				continue;
			CFG * cfg_ptr = context_manager.getContext(fd)->getCFG(), * cfg2_ptr = context_manager.getContext(fd2)->getCFG();
#if (DEBUG)
			cerr << "Found both cfgs for " << iter->first << ":\n";
			cfg_ptr->dump(LangOptions());
			cfg2_ptr->dump(LangOptions());
			getchar();
#endif
			// this codes sets up the observer to use the first cfg
			// an observer is what we used to report the results
			// this could be defined using the second cfg as well
			APAbstractDomain domain(*cfg_ptr);
			domain.InitializeValues(*cfg_ptr);
			APChecker Observer(*contex_ptr,code.getDiagnosticsEngine(), code.getPreprocessor());
			domain.getAnalysisData().Observer = &Observer;
			domain.getAnalysisData().setContext(*contex_ptr);
			IterativeSolver is(domain, interleaving, k, p, prove_equivalence);
			is.AssumeInputEquivalence(fd,fd2);
			is.RunOnCFGs(cfg_ptr,cfg2_ptr);

		}
    }

}
