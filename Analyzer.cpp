//============================================================================
// Name        : Analyzer.cpp
// Author      : nimi@cs
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include "Analyzer.h"
#include "Analysis/AnalysisConfiguration.h"

#include "DTL/dtl.hpp"
#include "DTL/variables.hpp"
using namespace dtl;

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//#define DEBUG

extern llvm::cl::opt<string>  InputFilename;
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

    int Analyzer::Main(int argc, char* argv[]) {
        CodeHandler::Init(argc,argv);
        Analyzer().RunAnalysis();
        return 0;
    }

// Create all structures needed for diagnostics
    Analyzer::Analyzer() : CodeHandler(InputFilename) {
    	AnalysisConfiguration::PrintConfigurationHeader();
    	APAbstractDomain::ValTy::mgr_ptr_ = AnalysisConfiguration::ParseManager(ManagerType);
    	APAbstractDomain::ValTy::partition_point_ = AnalysisConfiguration::ParsePartitionPoint(PartitionPoint);
    	APAbstractDomain::ValTy::partition_strategy_ = AnalysisConfiguration::ParsePartitionStrategy(PartitionStrategy);
    	APAbstractDomain::ValTy::widening_point_ = AnalysisConfiguration::ParseWideningPoint(WideningPoint);
    	APAbstractDomain::ValTy::widening_strategy_ = AnalysisConfiguration::ParseWideningStrategy(WideningStrategy);
    	APAbstractDomain::ValTy::widening_threshold_ = AnalysisConfiguration::ParseWideningThreshold(WideningThreshold);
    	AnalysisConfiguration::PrintConfigurationFooter();
    }

    void Analyzer::RunAnalysis(ostream& report_file) {
        IdentifierTable id_table(language_options_);
        SelectorTable selector_table;
        Builtin::Context builtint_contex;
        ASTContext contex(language_options_, source_manager_, target_info_, id_table, selector_table, builtint_contex, 0);
        AnalysisConsumer consumer(contex, diagnostics_engine_, preprocessor_ptr_, report_file, ComputeDiff.size() && ComputeDiff[0] == "true");
        ParseAST(*preprocessor_ptr_, &consumer, contex);
    }
    /*
    void Analyzer::RunGRExprAnalysis() {
        IdentifierTable id_table(language_options_);
        SelectorTable selector_table;
        Builtin::Context builtint_contex(*target_info_);
        ASTContext contex(language_options_, source_manager_, *target_info_, id_table, selector_table, builtint_contex, 0);
        AnalyzerOptions options;
        options.AnalyzeAll = 1;
        options.AnalyzerDisplayProgress = 1;
        options.EnableExperimentalChecks = 1;
        //Opts.EnableExperimentalInternalChecks = 1;
        options.AnalyzeNestedBlocks = 1;
        options.MaxLoop = 1;
        options.MaxNodes = 150000;
        options.AnalyzerDisplayProgress = 1;
        //Opts.InlineCall = 1;
        options.PurgeDead = 0;
        ASTConsumer *consumer = clang::ento::CreateAnalysisConsumer(*preprocessor_ptr_, string(), options);
        consumer->Initialize(contex);
        clang::ParseAST(*preprocessor_ptr_, consumer, contex);
    }
    */
}
