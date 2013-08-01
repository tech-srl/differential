/*
 * Analysiss.h
 *
 *  Created on: May 17, 2013
 *      Author: user
 */

#ifndef ANALYSISFLAGS_H_
#define ANALYSISFLAGS_H_

#include <string>

#include <llvm/Support/CommandLine.h>

#include "APAbstractDomain.h"

namespace differential {

class AnalysisConfiguration
{
public:
	typedef llvm::cl::list<std::string> ClList;
	typedef APAbstractDomain_ValueTypes::ValTy State;

	static void PrintConfigurationHeader(void) { cout << "Analysis Configuration:\n"; }
	static void PrintConfigurationFooter(void) { cout << "==============================\n"; }

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
	static void ParseManager(ClList manager_type);

	// Partition Points
	static const char * kPartitionPointAtJoin;
	static const char * kPartitionPointAtDiff;
	static const char * kPartitionPointAtNone;
	static const char * kPartitionPoints;
	static void ParsePartitionPoint(ClList partition_point);

	// Partition Strategies
	static const char * kPartitionStrategyAll;
	static const char * kPartitionStrategyNone;
	static const char * kPartitionStrategyGuards;
	static const char * kPartitionStrategyEquiv;
	static const char * kPartitionStrategies;
	static void ParsePartitionStrategy(ClList partition_strategy);

	static void ParseWideningThreshold(ClList widening_threshold);
	// Widening Points
	static const char * kWideningPointAtBackEdges;
	static const char * kWideningPointAtDiff;
	static const char * kWideningPointAtAll;
	static const char * kWideningPoints;
	static void ParseWideningPoint(ClList widening_point);
	// Widening Strategies
	static const char * kWideningStrategyAll;
	static const char * kWideningStrategyGuards;
	static const char * kWideningStrategyEquiv;
	static const char * kWideningStrategies;
	static void ParseWideningStrategy(ClList widening_strategy);

	// Interleaving
	typedef enum { INTERLEAVING_ALL, INTERLEAVING_BALANCED } Interleaving;
	static const char * kInterleavignAll;
	static const char * kInterleavignBalanced;
	static const char * kInterleavigns;
	static Interleaving ParseInterleaving(ClList interleaving);

};

} // end namespace differential

#endif /* ANALYSISFLAGS_H_ */
