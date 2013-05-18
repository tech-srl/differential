/*
 * AnalysisFlags.h
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

class AnalysisFlags
{
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
	// Partition Points
	static const char * kFlagPartitionPointAtJoin;
	static const char * kFlagPartitionPointAtDiff;
	static const char * kFlagPartitionPointAtNone;
	static const char * kFlagPartitionPoints;
	// Partition Strategies
	static const char * kFlagPartitionStrategyAll;
	static const char * kFlagPartitionStrategyNone;
	static const char * kFlagPartitionStrategyGuards;
	static const char * kFlagPartitionStrategyEquiv;
	static const char * kFlagPartitionStrategies;
	// Widening Points
	static const char * kFlagWideningPointAtBackEdges;
	static const char * kFlagWideningPointAtDiff;
	static const char * kFlagWideningPointAtAll;
	static const char * kFlagWideningPoints;
	// Widening Strategies
	static const char * kFlagWideningStrategyAll;
	static const char * kFlagWideningStrategyGuards;
	static const char * kFlagWideningStrategyEquiv;
	static const char * kFlagWideningStrategies;

	typedef llvm::cl::list<std::string> ClList;
	typedef APAbstractDomain_ValueTypes::ValTy State;

	static void ParseAnalysisFlags(ClList ManagerType,
			ClList PartitionPoint,ClList PartitionStrategy,ClList PartitonThreshold,
			ClList WideningPoint, ClList WideningStrategy, ClList WideningThreshold);
};

} // end namespace differential

#endif /* ANALYSISFLAGS_H_ */
