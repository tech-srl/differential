#ifndef ANALYSIS_CONF_H_
#define ANALYSIS_CONF_H_

#include <string>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/raw_ostream.h>
using namespace llvm;

#include "apronxx/apronxx.hh"

namespace differential {

class AnalysisConfiguration
{
public:
	typedef llvm::cl::list<std::string> ClList;

	static void PrintConfigurationHeader(void) { outs() << "Analysis Configuration:\n"; }
	static void PrintConfigurationFooter(void) { outs() << "==============================\n"; }

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
	static apron::manager * ParseManager(ClList manager_type);

	// Partition Points
	typedef enum { PARTITION_AT_NONE, PARTITION_AT_JOIN, PARTITION_AT_CORR_POINT } PartitionPoint;
	static const char * kPartitionPointAtJoin;
	static const char * kPartitionPointAtDiff;
	static const char * kPartitionPointAtNone;
	static const char * kPartitionPoints;
	static PartitionPoint ParsePartitionPoint(ClList partition_point);

	// Partition Strategies
	typedef enum { JOIN_NONE, JOIN_ALL, JOIN_GUARDS, JOIN_EQUIV } PartitionStrategy;
	static const char * kPartitionStrategyAll;
	static const char * kPartitionStrategyNone;
	static const char * kPartitionStrategyGuards;
	static const char * kPartitionStrategyEquiv;
	static const char * kPartitionStrategies;
	static PartitionStrategy ParsePartitionStrategy(ClList partition_strategy);

	// Widening Points
	typedef enum { WIDEN_AT_ALL, WIDEN_AT_CORR_POINT, WIDEN_AT_BACK_EDGE } WideningPoint;
	static const char * kWideningPointAtBackEdges;
	static const char * kWideningPointAtDiff;
	static const char * kWideningPointAtAll;
	static const char * kWideningPoints;
	static WideningPoint ParseWideningPoint(ClList widening_point);
	// Widening Strategies
	typedef enum { WIDEN_ALL, WIDEN_EQUIV, WIDEN_GUARDS } WideningStrategy;
	static const char * kWideningStrategyAll;
	static const char * kWideningStrategyGuards;
	static const char * kWideningStrategyEquiv;
	static const char * kWideningStrategies;
	static WideningStrategy ParseWideningStrategy(ClList widening_strategy);
	// Widening Threshold
	static const int kWideningThreshold;
	static unsigned ParseWideningThreshold(ClList widening_threshold);

	// Interleaving
	typedef enum { INTERLEAVING_ALL, INTERLEAVING_ONE, INTERLEAVING_LOOKAHEAD, INTERLEAVING_BALANCED } Interleaving;
	static const char * kInterleavignAll;
	static const char * kInterleavignOne;
	static const char * kInterleavignLookahead;
	static const char * kInterleavignBalanced;
	static const char * kInterleavigns;
	static Interleaving ParseInterleaving(ClList interleaving);
	static const int kInterleavignLookaheadWindow;
	static int ParseInterleavignLookaheadWindow(ClList window);
	static const int kInterleavignLookaheadPartition;
	static int ParseInterleavignLookaheadPartition(ClList partition);

	static bool ParseProveEquiv(ClList prove_equivalence);
};

} // end namespace differential

#endif /* ANALYSISFLAGS_H_ */
