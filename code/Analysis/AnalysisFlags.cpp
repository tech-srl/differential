/*
 * AnalysisFlags.cpp
 *
 *  Created on: May 17, 2013
 *      Author: user
 */

#include "AnalysisFlags.h"

#include "apronxx/apronxx.hh"
#include "apronxx/apxx_box.hh"
#include "apronxx/apxx_oct.hh"
#include "apronxx/apxx_polka.hh"
#include "apronxx/apxx_ppl.hh"
#include "apronxx/apxx_ppl_product.hh"
using namespace apron;

namespace differential {

// Apron Domain Managers
const char * AnalysisFlags::kManagerTypeBox =               "box";
const char * AnalysisFlags::kManagerTypeOctagon =           "oct";
const char * AnalysisFlags::kManagerTypePolka =             "polka";
const char * AnalysisFlags::kManagerTypePolkaStrict =       "polka_strict";
const char * AnalysisFlags::kManagerTypePPL =               "ppl";
const char * AnalysisFlags::kManagerTypePPLStrict =         "ppl_strict";
const char * AnalysisFlags::kManagerTypePPLGrids =          "ppl_grids";
const char * AnalysisFlags::kManagerTypePolkaPPL =          "polka_ppl";
const char * AnalysisFlags::kManagerTypePolkaPPLStrict =    "polka_ppl_strict";
const char * AnalysisFlags::kManagerTypes =                 "box|oct|polka|polka_strict|ppl(default)|ppl_strict|ppl_grids|polka_ppl|polka_ppl_strict";

// Partition Points
const char * AnalysisFlags::kFlagPartitionPointAtJoin =		"at-join";
const char * AnalysisFlags::kFlagPartitionPointAtDiff = 	"at-diff";
const char * AnalysisFlags::kFlagPartitionPointAtNone = 	"at-none";
const char * AnalysisFlags::kFlagPartitionPoints =      	"at-none|at-join|at-diff(default)";

// Partition Strategies
const char * AnalysisFlags::kFlagPartitionStrategyAll = 	"all";
const char * AnalysisFlags::kFlagPartitionStrategyNone = 	"none";
const char * AnalysisFlags::kFlagPartitionStrategyGuards = 	"guards";
const char * AnalysisFlags::kFlagPartitionStrategyEquiv = 	"equiv";
const char * AnalysisFlags::kFlagPartitionStrategies = 		"none|all|equiv(default)|guards(not supported for idizy)";

// Widening Points
const char * AnalysisFlags::kFlagWideningPointAtBackEdges = "at-back";
const char * AnalysisFlags::kFlagWideningPointAtDiff =	  	"at-diff";
const char * AnalysisFlags::kFlagWideningPointAtAll = 	  	"at-all";
const char * AnalysisFlags::kFlagWideningPoints =      	  	"at-all|at-diff|at-back(default)";

// Widening Strategies
const char * AnalysisFlags::kFlagWideningStrategyAll = 		"all";
const char * AnalysisFlags::kFlagWideningStrategyGuards = 	"guards";
const char * AnalysisFlags::kFlagWideningStrategyEquiv = 	"equiv";
const char * AnalysisFlags::kFlagWideningStrategies = 		"all|equiv(default for idizy)|guards(default for cdizy, not supported for idizy)";

void AnalysisFlags::ParseAnalysisFlags(ClList ManagerType,
		ClList PartitionPoint,ClList PartitionStrategy,ClList PartitonThreshold,
		ClList WideningPoint, ClList WideningStrategy, ClList WideningThreshold) {
	cout << "Analysis Configuration\n" << "----------------------\n";
	cout << "Domain: ";
	if (ManagerType.size()) {
		if (ManagerType[0] == kManagerTypeBox) {
			cout << "Box\n";
			State::mgr_ptr_ = new box_manager();
		} else if (ManagerType[0] == kManagerTypeOctagon) {
			cout << "Octagon\n";
			State::mgr_ptr_ = new oct_manager();
		} else if (ManagerType[0] == kManagerTypePolka) {
			cout << "Polka (loose)\n";
			State::mgr_ptr_ = new polka_manager();
		} else if (ManagerType[0] == kManagerTypePolkaStrict) {
			cout << "Polka (strict)\n";
			State::mgr_ptr_ = new polka_manager(true);
		} else if (ManagerType[0] == kManagerTypePPL) {
			cout << "PPL (polyhedra, loose)\n";
			State::mgr_ptr_ = new ppl_poly_manager();
		} else if (ManagerType[0] == kManagerTypePPLStrict) {
			cout << "PPL (polyhedra, strict)\n";
			State::mgr_ptr_ = new ppl_poly_manager(true);
		} else if (ManagerType[0] == kManagerTypePPLGrids) {
			cout << "PPL (grids)\n";
			State::mgr_ptr_ = new ppl_grid_manager();
		} else if (ManagerType[0] == kManagerTypePolkaPPL) {
			cout << "Product Polka (loose) * PPL grids\n";
			State::mgr_ptr_ = new pkgrid_manager(false);
		} else if (ManagerType[0] == kManagerTypePolkaPPLStrict) {
			cout << "Product Polka (strict) * PPL grids\n";
			State::mgr_ptr_ = new pkgrid_manager(true);
		} else {
			cout << "PPL (polyhedra, loose)\n";
			State::mgr_ptr_ = new ppl_poly_manager();
		}
	} else {
		cout << "PPL (polyhedra, loose)\n";
		State::mgr_ptr_ = new ppl_poly_manager();
	}
	cout << "Partition Point: ";
	if (PartitionPoint.size()) {
		if (PartitionPoint[0] == kFlagPartitionPointAtNone) {
			State::partition_point = State::PARTITION_AT_NONE;
			cout << "At-None\n";
		} else if (PartitionPoint[0] == kFlagPartitionPointAtJoin) {
			State::partition_point = State::PARTITION_AT_JOIN;
			cout << "At-Join\n";
		} else {
			// default partition point
			State::partition_point = State::PARTITION_AT_CORR_POINT;
			cout << "At-Correlation-Point\n";
		}
	} else {
		// default partition point
		State::partition_point = State::PARTITION_AT_CORR_POINT;
		cout << "At-Correlation-Point\n";
	}
	cout << "Partition Strategy: ";
	if (PartitionStrategy.size()) {
		if (PartitionStrategy[0] == kFlagPartitionStrategyAll) {
			State::partition_strategy = State::JOIN_ALL;
			cout << "Join-All\n";
		} else if (PartitionStrategy[0] == kFlagPartitionStrategyNone) {
			State::partition_strategy = State::JOIN_NONE;
			cout << "No-Join\n";
		} else if (PartitionStrategy[0] == kFlagPartitionStrategyGuards) {
			State::partition_strategy = State::JOIN_GUARDS;
			cout << "Join-By-Guards\n";
		} else {
			// default partition strategry
			State::partition_strategy = State::JOIN_EQUIV;
			cout << "Join-if-Equivalent\n";
		}
	} else {
		// default partition strategry
		State::partition_strategy = State::JOIN_EQUIV;
		cout << "Join-if-Equivalent\n";
	}
	if (PartitonThreshold.size()) {
		State::partition_threshold = atoi(PartitonThreshold[0].c_str());
		cout << "Partition Threshold: " << State::partition_threshold << '\n';
	}
	cout << "Widening Point: ";
	if (WideningPoint.size()) {
		if (WideningPoint[0] == kFlagWideningPointAtAll) {
			State::widening_point = State::WIDEN_AT_ALL;
			cout << "At-None\n";
		} else if (WideningPoint[0] == kFlagWideningPointAtDiff) {
			State::widening_point = State::WIDEN_AT_CORR_POINT;
			cout << "At-Correlation-Point\n";
		} else {
			// default widening point
			State::widening_point = State::WIDEN_AT_BACK_EDGE;
			cout << "At-Back-Edge\n";
		}
	} else {
		// default widening point
		State::widening_point = State::WIDEN_AT_BACK_EDGE;
		cout << "At-Back-Edge\n";
	}
	cout << "Widening Strategy: ";
	if (WideningStrategy.size()) {
		if (WideningStrategy[0] == kFlagWideningStrategyAll) {
			State::widening_strategy = State::WIDEN_ALL;
			cout << "Join-All-And-Widen\n";
		} else if (WideningStrategy[0] == kFlagWideningStrategyEquiv) {
			State::widening_strategy = State::WIDEN_EQUIV;
			cout << "By-Equivalence\n";
		} else {
			// default widening strategry
			State::widening_strategy = State::WIDEN_GUARDS;
			cout << "By-Guards\n";
		}
	} else {
		// default widening strategry
		State::widening_strategy = State::WIDEN_GUARDS;
		cout << "By-Guards\n";
	}
	if (WideningThreshold.size()) {
		State::widening_threshold = atoi(WideningThreshold[0].c_str());
	}
	cout << "Widening Threshold: "<< State::widening_threshold << '\n';
	cout << "======================\n";
}

}

