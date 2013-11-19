/*
 * AnalysisConfiguration.cpp
 *
 *  Created on: May 17, 2013
 *      Author: user
 */

#include "AnalysisConfiguration.h"

#include "apronxx/apronxx.hh"
#include "apronxx/apxx_box.hh"
#include "apronxx/apxx_oct.hh"
#include "apronxx/apxx_polka.hh"
#include "apronxx/apxx_ppl.hh"
#include "apronxx/apxx_ppl_product.hh"
using namespace apron;

namespace differential {

// Apron Domain Managers
const char * AnalysisConfiguration::kManagerTypeBox =               "box";
const char * AnalysisConfiguration::kManagerTypeOctagon =           "oct";
const char * AnalysisConfiguration::kManagerTypePolka =             "polka";
const char * AnalysisConfiguration::kManagerTypePolkaStrict =       "polka_strict";
const char * AnalysisConfiguration::kManagerTypePPL =               "ppl";
const char * AnalysisConfiguration::kManagerTypePPLStrict =         "ppl_strict";
const char * AnalysisConfiguration::kManagerTypePPLGrids =          "ppl_grids";
const char * AnalysisConfiguration::kManagerTypePolkaPPL =          "polka_ppl";
const char * AnalysisConfiguration::kManagerTypePolkaPPLStrict =    "polka_ppl_strict";
const char * AnalysisConfiguration::kManagerTypes =                 "box|oct|polka|polka_strict|ppl(default)|ppl_strict|ppl_grids|polka_ppl|polka_ppl_strict";

void AnalysisConfiguration::ParseManager(ClList manager_type) {
	cout << "Domain: ";
	if (manager_type.size()) {
		if (manager_type[0] == kManagerTypeBox) {
			cout << "Box\n";
			State::mgr_ptr_ = new box_manager();
		} else if (manager_type[0] == kManagerTypeOctagon) {
			cout << "Octagon\n";
			State::mgr_ptr_ = new oct_manager();
		} else if (manager_type[0] == kManagerTypePolka) {
			cout << "Polka (loose)\n";
			State::mgr_ptr_ = new polka_manager();
		} else if (manager_type[0] == kManagerTypePolkaStrict) {
			cout << "Polka (strict)\n";
			State::mgr_ptr_ = new polka_manager(true);
		} else if (manager_type[0] == kManagerTypePPL) {
			cout << "PPL (polyhedra, loose)\n";
			State::mgr_ptr_ = new ppl_poly_manager();
		} else if (manager_type[0] == kManagerTypePPLStrict) {
			cout << "PPL (polyhedra, strict)\n";
			State::mgr_ptr_ = new ppl_poly_manager(true);
		} else if (manager_type[0] == kManagerTypePPLGrids) {
			cout << "PPL (grids)\n";
			State::mgr_ptr_ = new ppl_grid_manager();
		} else if (manager_type[0] == kManagerTypePolkaPPL) {
			cout << "Product Polka (loose) * PPL grids\n";
			State::mgr_ptr_ = new pkgrid_manager(false);
		} else if (manager_type[0] == kManagerTypePolkaPPLStrict) {
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
}

// Partition Points
const char * AnalysisConfiguration::kPartitionPointAtJoin =		"at-join";
const char * AnalysisConfiguration::kPartitionPointAtDiff = 	"at-diff";
const char * AnalysisConfiguration::kPartitionPointAtNone = 	"at-none";
const char * AnalysisConfiguration::kPartitionPoints =      	"at-none|at-join|at-diff(default)";

void AnalysisConfiguration::ParsePartitionPoint(ClList partition_point) {
	cout << "Partition Point: ";
		if (partition_point.size()) {
			if (partition_point[0] == kPartitionPointAtNone) {
				State::partition_point = State::PARTITION_AT_NONE;
				cout << "At-None\n";
			} else if (partition_point[0] == kPartitionPointAtJoin) {
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
}

// Partition Strategies
const char * AnalysisConfiguration::kPartitionStrategyAll = 	"all";
const char * AnalysisConfiguration::kPartitionStrategyNone = 	"none";
const char * AnalysisConfiguration::kPartitionStrategyGuards = 	"guards";
const char * AnalysisConfiguration::kPartitionStrategyEquiv = 	"equiv";
const char * AnalysisConfiguration::kPartitionStrategies = 		"none|all|equiv(default)|guards(not supported for idizy)";

void AnalysisConfiguration::ParsePartitionStrategy(ClList partition_strategy) {
	cout << "Partition Strategy: ";
	if (partition_strategy.size()) {
		if (partition_strategy[0] == kPartitionStrategyAll) {
			State::partition_strategy = State::JOIN_ALL;
			cout << "Join-All\n";
		} else if (partition_strategy[0] == kPartitionStrategyNone) {
			State::partition_strategy = State::JOIN_NONE;
			cout << "No-Join\n";
		} else if (partition_strategy[0] == kPartitionStrategyGuards) {
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
}

// Widening Points
const char * AnalysisConfiguration::kWideningPointAtBackEdges = "at-back";
const char * AnalysisConfiguration::kWideningPointAtDiff =	  	"at-diff";
const char * AnalysisConfiguration::kWideningPointAtAll = 	  	"at-all";
const char * AnalysisConfiguration::kWideningPoints =      	  	"at-all|at-diff|at-back(default)";

void AnalysisConfiguration::ParseWideningPoint(ClList widening_point) {
	cout << "Widening Point: ";
	if (widening_point.size()) {
		if (widening_point[0] == kWideningPointAtAll) {
			State::widening_point = State::WIDEN_AT_ALL;
			cout << "At-None\n";
		} else if (widening_point[0] == kWideningPointAtDiff) {
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
}

// Widening Strategies
const char * AnalysisConfiguration::kWideningStrategyAll = 		"all";
const char * AnalysisConfiguration::kWideningStrategyGuards = 	"guards";
const char * AnalysisConfiguration::kWideningStrategyEquiv = 	"equiv";
const char * AnalysisConfiguration::kWideningStrategies = 		"all|equiv(default for idizy)|guards(default for cdizy, not supported for idizy)";

void AnalysisConfiguration::ParseWideningStrategy(ClList widening_strategy) {
	cout << "Widening Strategy: ";
	if (widening_strategy.size()) {
		if (widening_strategy[0] == kWideningStrategyAll) {
			State::widening_strategy = State::WIDEN_ALL;
			cout << "Join-All-And-Widen\n";
		} else if (widening_strategy[0] == kWideningStrategyEquiv) {
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
}

void AnalysisConfiguration::ParseWideningThreshold(ClList widening_threshold){
	if (widening_threshold.size()) {
		State::widening_threshold = atoi(widening_threshold[0].c_str());
	}
	cout << "Widening Threshold: "<< State::widening_threshold << '\n';
}

// Interleavings
const char * AnalysisConfiguration::kInterleavignAll =			"all";
const char * AnalysisConfiguration::kInterleavignOne =			"one";
const char * AnalysisConfiguration::kInterleavignLookahead =	"lookahead";
const char * AnalysisConfiguration::kInterleavignBalanced = 	"balanced";
const char * AnalysisConfiguration::kInterleavigns =			"all|one|lookahead|balanced";

AnalysisConfiguration::Interleaving AnalysisConfiguration::ParseInterleaving(ClList interleaving) {
	cout << "Interleaving: ";
	if (interleaving.size()) {
		if (interleaving[0] == kInterleavignAll) {
			cout << "All together\n";
			return INTERLEAVING_ALL;
		} else if (interleaving[0] == kInterleavignLookahead) {
			cout << "Lookahead\n";
			return INTERLEAVING_LOOKAHEAD;
		} else if (interleaving[0] == kInterleavignOne) {
			cout << "One (no restricions)\n";
			return INTERLEAVING_ONE;
		} else if (interleaving[0] == kInterleavignBalanced) {
			cout << "One (balanced)\n";
			return INTERLEAVING_BALANCED;
		} else {
			goto exit;
		}
	} else {
		goto exit;
	}
	// default interleaving
exit:
	cout << "One (no restrictions)\n";
	return INTERLEAVING_ONE;
}

const int AnalysisConfiguration::kInterleavignLookaheadWindow = 1;
int AnalysisConfiguration::ParseInterleavignLookaheadWindow(ClList window) {
	int result = kInterleavignLookaheadWindow;
	if (window.size()) {
		result = atoi(window[0].c_str());
	}
	// default lookahead window
	cout << "Lookahead window: " << result << '\n';
	return result;
}

const int AnalysisConfiguration::kInterleavignLookaheadPartition = 10;
int AnalysisConfiguration::ParseInterleavignLookaheadPartition(ClList partition) {
	int result = kInterleavignLookaheadPartition;
	if (partition.size()) {
		result = atoi(partition[0].c_str());
	}
	// default lookahead partition interval
	cout << "Lookahead partition every " << result << " steps\n";
	return result;
}

bool AnalysisConfiguration::ParseProveEquiv(ClList prove_equivalence) {
	bool result = (prove_equivalence.size() > 0 && prove_equivalence[0] == "true");
	cout << "Try and prove equivalence? " << (result ? "Yes" : "No") << '\n';
	return result;
}

}

