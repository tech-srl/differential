#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#include <clang/Analysis/Analyses/LiveVariables.h>
#include <clang/Analysis/Analyses/ReachableCode.h>
#include <clang/Analysis/AnalysisContext.h>
#include <clang/Analysis/CFG.h>
#include <clang/Analysis/FlowSensitive/DataflowSolver.h>
using namespace clang;


#include "CodeHandler.h"
#include "Analysis/AnalysisConsumer.h"


namespace differential {

class Analyzer : public CodeHandler {
private:
	AnalyzerOptions analyzer_options_;

public:
    ASTContext * contex_ptr_;

	Analyzer();
    ~Analyzer() { }

    DiagnosticsEngine& getDiagnosticsEngine() {
        return diagnostics_engine_;
    }

    void emitDiagnosticsToOut() {
        TextDiagnosticPrinter *tdp_ptr = new TextDiagnosticPrinter(llvm::outs(), diagnostic_options_);
        tdp_ptr->BeginSourceFile(language_options_, preprocessor_ptr_);
        diagnostics_engine_.setClient(tdp_ptr);
    }

    void RunAnalysis(ostream& report_file = cout);
    //void RunGRExprAnalysis();
    static int Main(int argc, char *argv[]);


   class Flags {
   public:
      // Apron Domain Managers
      static const char * kManagerTypeBox;
      static const char * kManagerTypeOctagon;
      static const char * kManagerTypePolka;
      static const char * kManagerTypePolkaStrict;
      static const char * kManagerTypePPL;
      static const char * kManagerTypePPLStrict;
      static const char * kManagerTypePPLGrids;
      static const char * kManagerTypePolkaPPL;
      static const char * kManagerTypePolkaPPLStrict;
      static const char * kManagerTypes;

      // Canonization Points
      static const char * kFlagCanonizationPointAtJoin;
      static const char * kFlagCanonizationPointAtDiff;
      static const char * kFlagCanonizationPointAtNone;
      static const char * kFlagCanonizationPoints;

      // Canonization Strategies
      static const char * kFlagCanonizationStrategyAll;
      static const char * kFlagCanonizationStrategyID;
      static const char * kFlagCanonizationStrategyEquiv;
      static const char * kFlagCanonizationStrategies;

   };

};

}
#endif
