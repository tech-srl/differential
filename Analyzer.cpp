//============================================================================
// Name        : Analyzer.cpp
// Author      : nimi@cs
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include "apronxx/apronxx.hh"
#include "apronxx/apxx_box.hh"
#include "apronxx/apxx_oct.hh"
#include "apronxx/apxx_polka.hh"
#include "apronxx/apxx_ppl.hh"
#include "apronxx/apxx_ppl_product.hh"
using namespace apron;

#include "Analyzer.h"
using namespace differential;

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
extern llvm::cl::list<string> CanonizationPoint;
extern llvm::cl::list<string> CanonizationStrategy;
extern llvm::cl::list<string> CanonizationThreshold;
extern llvm::cl::list<string> WideningStrategy;

namespace differential {

    // Apron Domain Managers
    const char * Analyzer::Flags::kManagerTypeBox =               "box";
    const char * Analyzer::Flags::kManagerTypeOctagon =           "oct";
    const char * Analyzer::Flags::kManagerTypePolka =             "polka";
    const char * Analyzer::Flags::kManagerTypePolkaStrict =       "polka_strict";
    const char * Analyzer::Flags::kManagerTypePPL =               "ppl";
    const char * Analyzer::Flags::kManagerTypePPLStrict =         "ppl_strict";
    const char * Analyzer::Flags::kManagerTypePPLGrids =          "ppl_grids";
    const char * Analyzer::Flags::kManagerTypePolkaPPL =          "polka_ppl";
    const char * Analyzer::Flags::kManagerTypePolkaPPLStrict =    "polka_ppl_strict";
    const char * Analyzer::Flags::kManagerTypes =                 "box|oct|polka|polka_strict|ppl(default)|ppl_strict|ppl_grids|polka_ppl|polka_ppl_strict";

    // Canonization Points
    const char * Analyzer::Flags::kFlagCanonizationPointAtJoin = "at-join";
    const char * Analyzer::Flags::kFlagCanonizationPointAtDiff = "at-diff";
    const char * Analyzer::Flags::kFlagCanonizationPointAtNone = "none";
    const char * Analyzer::Flags::kFlagCanonizationPoints =      "none|at-join|at-diff(default)";

    // Canonization Strategies
    const char * Analyzer::Flags::kFlagCanonizationStrategyAll = "all";
    const char * Analyzer::Flags::kFlagCanonizationStrategyNone = "none";
    const char * Analyzer::Flags::kFlagCanonizationStrategyEquiv = "equiv";
    const char * Analyzer::Flags::kFlagCanonizationStrategies = "none|all|equiv(default)";

    // Widening Strategies
    const char * Analyzer::Flags::kFlagWideningStrategyAll = "all";
    const char * Analyzer::Flags::kFlagWideningStrategyGuards = "guards";
    const char * Analyzer::Flags::kFlagWideningStrategyEquiv = "equiv";
    const char * Analyzer::Flags::kFlagWideningStrategies = "all|equiv|guards(default)";

    int Analyzer::Main(int argc, char* argv[]) {
        CodeHandler::Init(argc,argv);
        Analyzer().RunAnalysis();
        return 0;
    }

// Create all structures needed for diagnostics
    Analyzer::Analyzer() : CodeHandler() {
        cout << "Analysis Configuration\n" 
             << "----------------------\n";
        cout << "Domain: ";
        if ( ManagerType.size() ) {
            if ( ManagerType[0] == Analyzer::Flags::kManagerTypeBox ) {
                cout << "Box\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new box_manager();
            } else if ( ManagerType[0] == Analyzer::Flags::kManagerTypeOctagon ) {
                cout << "Octagon\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new oct_manager();
            } else if ( ManagerType[0] == Analyzer::Flags::kManagerTypePolka ) {
                cout << "Polka (loose)\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new polka_manager();
            } else if ( ManagerType[0] == Analyzer::Flags::kManagerTypePolkaStrict ) {
                cout << "Polka (strict)\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new polka_manager(true);
            } else if ( ManagerType[0] == Analyzer::Flags::kManagerTypePPL ) {
                cout << "PPL (polyhedra, loose)\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new ppl_poly_manager();
            } else if ( ManagerType[0] == Analyzer::Flags::kManagerTypePPLStrict ) {
                cout << "PPL (polyhedra, strict)\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new ppl_poly_manager(true);
            } else if ( ManagerType[0] == Analyzer::Flags::kManagerTypePPLGrids ) {
                cout << "PPL (grids)\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new ppl_grid_manager();
            } else if ( ManagerType[0] == Analyzer::Flags::kManagerTypePolkaPPL ) {
                cout << "Product Polka (loose) * PPL grids\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new pkgrid_manager(false);
            } else if ( ManagerType[0] == Analyzer::Flags::kManagerTypePolkaPPLStrict ) {
                cout << "Product Polka (strict) * PPL grids\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new pkgrid_manager(true);
            } else {
                cout << "PPL (polyhedra, loose)\n";
                APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new ppl_poly_manager();
            }
        } else {
            cout << "PPL (polyhedra, loose)\n";
            APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = new ppl_poly_manager();
        }


        cout << "Canonization Point: ";
        if ( CanonizationPoint.size() ) {
            if ( CanonizationPoint[0] == Analyzer::Flags::kFlagCanonizationPointAtNone ) {
                APAbstractDomain_ValueTypes::ValTy::canonization_point = APAbstractDomain_ValueTypes::ValTy::AT_NONE;
                cout << "At-None\n";
            } else if ( CanonizationPoint[0] == Analyzer::Flags::kFlagCanonizationPointAtJoin ) {
                APAbstractDomain_ValueTypes::ValTy::canonization_point = APAbstractDomain_ValueTypes::ValTy::AT_JOIN;
                cout << "At-Join\n";
            } else { // default canonization point
                APAbstractDomain_ValueTypes::ValTy::canonization_point = APAbstractDomain_ValueTypes::ValTy::AT_DIFF_POINT;
                cout << "At-Diff\n";
            } 
        } else { // default canonization point
                APAbstractDomain_ValueTypes::ValTy::canonization_point = APAbstractDomain_ValueTypes::ValTy::AT_DIFF_POINT;
                cout << "At-Diff\n";
        }

        cout << "Canonization Strategy: ";
        if ( CanonizationStrategy.size() ) {
            if ( CanonizationStrategy[0] == Analyzer::Flags::kFlagCanonizationStrategyAll ) {
                APAbstractDomain_ValueTypes::ValTy::canonization_strategy = APAbstractDomain_ValueTypes::ValTy::JOIN_ALL;
                cout << "Join-All\n";
            } else if ( CanonizationStrategy[0] == Analyzer::Flags::kFlagCanonizationStrategyNone ) {
                APAbstractDomain_ValueTypes::ValTy::canonization_strategy = APAbstractDomain_ValueTypes::ValTy::JOIN_NONE;
                cout << "No-Join\n";
            } else { // default canonization strategry
                APAbstractDomain_ValueTypes::ValTy::canonization_strategy = APAbstractDomain_ValueTypes::ValTy::JOIN_EQUIV;
                cout << "Join-if-Equivalent\n";
            } 
        } else { // default canonization strategry
                APAbstractDomain_ValueTypes::ValTy::canonization_strategy = APAbstractDomain_ValueTypes::ValTy::JOIN_EQUIV;
                cout << "Join-if-Equivalent\n";
        }

        if ( CanonizationThreshold.size() ) {
            APAbstractDomain_ValueTypes::ValTy::canonization_threshold = atoi(CanonizationThreshold[0].c_str());
            cout << "Canonization Threshold: " << APAbstractDomain_ValueTypes::ValTy::canonization_threshold << endl;
        }

        cout << "Widening Strategy: ";
        if ( WideningStrategy.size() ) {
            if ( WideningStrategy[0] == Analyzer::Flags::kFlagWideningStrategyAll ) {
                APAbstractDomain_ValueTypes::ValTy::widening_strategy = APAbstractDomain_ValueTypes::ValTy::WIDEN_ALL;
                cout << "Join-All\n";
            } else if ( WideningStrategy[0] == Analyzer::Flags::kFlagWideningStrategyEquiv ) {
                APAbstractDomain_ValueTypes::ValTy::widening_strategy = APAbstractDomain_ValueTypes::ValTy::WIDEN_EQUIV;
                cout << "By-Equivalence\n";
            } else { // default widening strategry
                APAbstractDomain_ValueTypes::ValTy::widening_strategy = APAbstractDomain_ValueTypes::ValTy::WIDEN_GUARDS;
                cout << "By-Guards\n";
            }
        } else { // default widening strategry
                APAbstractDomain_ValueTypes::ValTy::widening_strategy = APAbstractDomain_ValueTypes::ValTy::WIDEN_GUARDS;
                cout << "By-Guards\n";
        }
        cout << "======================\n";

    }

    void Analyzer::RunAnalysis(ostream& report_file) {
        IdentifierTable id_table(language_options_);
        SelectorTable selector_table;
        Builtin::Context builtint_contex;
        ASTContext contex(language_options_, source_manager_, target_info_, id_table, selector_table, builtint_contex, 0);
        AnalysisConsumer consumer(contex, diagnostics_engine_, preprocessor_ptr_, report_file);
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
