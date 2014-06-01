/*
 * AnalysisConfiguration.cpp
 *
 *  Created on: May 17, 2013
 *      Author: user
 */

#include "AnalysisConfiguration.h"

#include "apronxx/apxx_box.hh"
#include "apronxx/apxx_oct.hh"
#include "apronxx/apxx_polka.hh"
#include "apronxx/apxx_ppl.hh"
#include "apronxx/apxx_ppl_product.hh"
//#include "apronxx/apxx_t1p.hh"
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
const char * AnalysisConfiguration::kManagerTypeTaylor1Plus =    	"t1p";
const char * AnalysisConfiguration::kManagerTypes =                 "box|oct|polka|polka_strict|ppl(default)|ppl_strict|ppl_grids|polka_ppl|polka_ppl_strict";

manager * AnalysisConfiguration::ParseManager(ClList manager_type) {
	outs() << "Domain: ";
	if (manager_type.size()) {
		if (manager_type[0] == kManagerTypeBox) {
			outs() << "Box\n";
			return new box_manager();
		} else if (manager_type[0] == kManagerTypeOctagon) {
			outs() << "Octagon\n";
			return new oct_manager();
		} else if (manager_type[0] == kManagerTypePolka) {
			outs() << "Polka (loose)\n";
			return new polka_manager();
		} else if (manager_type[0] == kManagerTypePolkaStrict) {
			outs() << "Polka (strict)\n";
			return new polka_manager(true);
		} else if (manager_type[0] == kManagerTypePPL) {
			outs() << "PPL (polyhedra, loose)\n";
			return new ppl_poly_manager();
		} else if (manager_type[0] == kManagerTypePPLStrict) {
			outs() << "PPL (polyhedra, strict)\n";
			return new ppl_poly_manager(true);
		} else if (manager_type[0] == kManagerTypePPLGrids) {
			outs() << "PPL (grids)\n";
			return new ppl_grid_manager();
		} else if (manager_type[0] == kManagerTypePolkaPPL) {
			outs() << "Product Polka (loose) * PPL grids\n";
			return new pkgrid_manager(false);
		} else if (manager_type[0] == kManagerTypePolkaPPLStrict) {
			outs() << "Product Polka (strict) * PPL grids\n";
			return new pkgrid_manager(true);
//		} else if (manager_type[0] == kManagerTypeTaylor1Plus) {
//			outs() << "Taylor1plus\n";
//			return new t1p_manager();
		} else {
			outs() << "PPL (polyhedra, loose)\n";
			return new ppl_poly_manager();
		}
	} else {
		outs() << "PPL (polyhedra, loose)\n";
		return new ppl_poly_manager();
	}
}

// Partition Points
const char * AnalysisConfiguration::kPartitionPointAtJoin =		"at-join";
const char * AnalysisConfiguration::kPartitionPointAtDiff = 	"at-diff";
const char * AnalysisConfiguration::kPartitionPointAtNone = 	"at-none";
const char * AnalysisConfiguration::kPartitionPoints =      	"at-none|at-join|at-diff(default)";

AnalysisConfiguration::PartitionPoint AnalysisConfiguration::ParsePartitionPoint(ClList partition_point) {
	PartitionPoint result;
	outs() << "Partition Point: ";
	if (partition_point.size()) {
		if (partition_point[0] == kPartitionPointAtNone) {
			result = PARTITION_AT_NONE;
			outs() << "At-None\n";
		} else if (partition_point[0] == kPartitionPointAtJoin) {
			result = PARTITION_AT_JOIN;
			outs() << "At-Join\n";
		} else {
			// default partition point
			result = PARTITION_AT_CORR_POINT;
			outs() << "At-Correlation-Point\n";
		}
	} else {
		// default partition point
		result = PARTITION_AT_CORR_POINT;
		outs() << "At-Correlation-Point\n";
	}
	return result;
}

// Partition Strategies
const char * AnalysisConfiguration::kPartitionStrategyAll = 	"all";
const char * AnalysisConfiguration::kPartitionStrategyNone = 	"none";
const char * AnalysisConfiguration::kPartitionStrategyGuards = 	"guards";
const char * AnalysisConfiguration::kPartitionStrategyEquiv = 	"equiv";
const char * AnalysisConfiguration::kPartitionStrategies = 		"none|all|equiv(default)|guards(not supported for idizy)";

AnalysisConfiguration::PartitionStrategy AnalysisConfiguration::ParsePartitionStrategy(ClList partition_strategy) {
	PartitionStrategy result;
	outs() << "Partition Strategy: ";
	if (partition_strategy.size()) {
		if (partition_strategy[0] == kPartitionStrategyAll) {
			result = JOIN_ALL;
			outs() << "Join-All\n";
		} else if (partition_strategy[0] == kPartitionStrategyNone) {
			result = JOIN_NONE;
			outs() << "No-Join\n";
		} else if (partition_strategy[0] == kPartitionStrategyGuards) {
			result = JOIN_GUARDS;
			outs() << "Join-By-Guards\n";
		} else {
			// default partition strategry
			result = JOIN_EQUIV;
			outs() << "Join-if-Equivalent\n";
		}
	} else {
		// default partition strategry
		result = JOIN_EQUIV;
		outs() << "Join-if-Equivalent\n";
	}
	return result;
}

// Widening Points
const char * AnalysisConfiguration::kWideningPointAtBackEdges = "at-back";
const char * AnalysisConfiguration::kWideningPointAtDiff =	  	"at-diff";
const char * AnalysisConfiguration::kWideningPointAtAll = 	  	"at-all";
const char * AnalysisConfiguration::kWideningPoints =      	  	"at-all|at-diff|at-back(default)";

AnalysisConfiguration::WideningPoint AnalysisConfiguration::ParseWideningPoint(ClList widening_point) {
	WideningPoint result;
	outs() << "Widening Point: ";
	if (widening_point.size()) {
		if (widening_point[0] == kWideningPointAtAll) {
			result = WIDEN_AT_ALL;
			outs() << "At-None\n";
		} else if (widening_point[0] == kWideningPointAtDiff) {
			result = WIDEN_AT_CORR_POINT;
			outs() << "At-Correlation-Point\n";
		} else {
			// default widening point
			result = WIDEN_AT_BACK_EDGE;
			outs() << "At-Back-Edge\n";
		}
	} else {
		// default widening point
		result = WIDEN_AT_BACK_EDGE;
		outs() << "At-Back-Edge\n";
	}
	return result;
}

// Widening Strategies
const char * AnalysisConfiguration::kWideningStrategyAll = 		"all";
const char * AnalysisConfiguration::kWideningStrategyGuards = 	"guards";
const char * AnalysisConfiguration::kWideningStrategyEquiv = 	"equiv";
const char * AnalysisConfiguration::kWideningStrategies = 		"all|equiv(default for idizy)|guards(default for cdizy, not supported for idizy)";

AnalysisConfiguration::WideningStrategy AnalysisConfiguration::ParseWideningStrategy(ClList widening_strategy) {
	WideningStrategy result;
	outs() << "Widening Strategy: ";
	if (widening_strategy.size()) {
		if (widening_strategy[0] == kWideningStrategyAll) {
			result = WIDEN_ALL;
			outs() << "Join-All-And-Widen\n";
		} else if (widening_strategy[0] == kWideningStrategyGuards) {
			result = WIDEN_GUARDS;
			outs() << "By-Guards\n";
		} else {
			// default widening strategry
			result = WIDEN_EQUIV;
			outs() << "By-Equivalence\n";
		}
	} else {
		// default widening strategry
		result = WIDEN_EQUIV;
		outs() << "By-Equivalence\n";
	}
	return result;
}

const int AnalysisConfiguration::kWideningThreshold = 5;
unsigned AnalysisConfiguration::ParseWideningThreshold(ClList widening_threshold){
	unsigned result;
	if (widening_threshold.size()) {
		result = atoi(widening_threshold[0].c_str());
	} else {
		result = kWideningThreshold;
	}
	outs() << "Widening Threshold: "<< result << '\n';
	return result;
}

// Interleavings
const char * AnalysisConfiguration::kInterleavignAll =			"all";
const char * AnalysisConfiguration::kInterleavignOne =			"one";
const char * AnalysisConfiguration::kInterleavignLookahead =	"lookahead";
const char * AnalysisConfiguration::kInterleavignBalanced = 	"balanced";
const char * AnalysisConfiguration::kInterleavigns =			"all|one|lookahead|balanced";

AnalysisConfiguration::Interleaving AnalysisConfiguration::ParseInterleaving(ClList interleaving) {
	outs() << "Interleaving: ";
	if (interleaving.size()) {
		if (interleaving[0] == kInterleavignAll) {
			outs() << "All together\n";
			return INTERLEAVING_ALL;
		} else if (interleaving[0] == kInterleavignLookahead) {
			outs() << "Lookahead\n";
			return INTERLEAVING_LOOKAHEAD;
		} else if (interleaving[0] == kInterleavignOne) {
			outs() << "One (no restricions)\n";
			return INTERLEAVING_ONE;
		} else if (interleaving[0] == kInterleavignBalanced) {
			outs() << "One (balanced)\n";
			return INTERLEAVING_BALANCED;
		} else {
			goto exit;
		}
	} else {
		goto exit;
	}
	// default interleaving
	exit:
	outs() << "Lookahead\n";
	return INTERLEAVING_LOOKAHEAD;
}

const int AnalysisConfiguration::kInterleavignLookaheadWindow = 1;
int AnalysisConfiguration::ParseInterleavignLookaheadWindow(ClList window) {
	int result = kInterleavignLookaheadWindow;
	if (window.size()) {
		result = atoi(window[0].c_str());
	}
	// default lookahead window
	outs() << "Lookahead window: " << result << '\n';
	return result;
}

const int AnalysisConfiguration::kInterleavignLookaheadPartition = 1; // default: partition after every speculative step.
int AnalysisConfiguration::ParseInterleavignLookaheadPartition(ClList partition) {
	int result = kInterleavignLookaheadPartition;
	if (partition.size()) {
		result = atoi(partition[0].c_str());
	}
	// default lookahead partition interval
	outs() << "Lookahead partition every " << result << " steps\n";
	return result;
}

bool AnalysisConfiguration::ParseProveEquiv(ClList prove_equivalence) {
	bool result = (prove_equivalence.size() > 0 && prove_equivalence[0] == "true");
	outs() << "Try and prove equivalence? " << (result ? "Yes" : "No") << '\n';
	return result;
}

}

