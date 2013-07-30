
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
#include "Analysis/AnalysisFlags.h"

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
extern llvm::cl::list<string> ComputeDiff;
extern llvm::cl::list<string> PartitionPoint;
extern llvm::cl::list<string> PartitionStrategy;
extern llvm::cl::list<string> PartitonThreshold;
extern llvm::cl::list<string> WideningPoint;
extern llvm::cl::list<string> WideningStrategy;
extern llvm::cl::list<string> WideningThreshold;


namespace differential {

    int IterativeAnalyzer::Main(int argc, char* argv[]) {
        CodeHandler::Init(argc,argv);
        IterativeAnalyzer().RunAnalysis();
        return 0;
    }

    IterativeAnalyzer::IterativeAnalyzer(){
    	// set the default widening strategy to be by-equivalence (guards are not supported so far)
    	if (WideningStrategy.size() == 0) {
			WideningStrategy.addValue(AnalysisFlags::kFlagWideningStrategyEquiv);
		}
    	AnalysisFlags::ParseAnalysisFlags(ManagerType,PartitionPoint,PartitionStrategy,PartitonThreshold,WideningPoint,WideningStrategy,WideningThreshold);
    }

    /**
     * Run the analysis on 2 files
     */
    void IterativeAnalyzer::RunAnalysis(ostream& report_file) {
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
			IterativeSolver is(domain);
			is.assumeInputEquivalence(fd,fd2);
			is.runOnCFGs(cfg_ptr,cfg2_ptr);

		}
    }

}
