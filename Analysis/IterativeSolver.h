/*
 * IterativeSolver.h
 *
 *  Created on: May 10, 2013
 *      Author: user
 */

#ifndef ITERATIVESOLVER_H_
#define ITERATIVESOLVER_H_

#include "AnalysisUtils.h"
#include "AnalysisConfiguration.h"
#include "APAbstractDomain.h"
#include "TransferFuncs.h"

#include <clang/Analysis/CFG.h>
using namespace clang;

#include <list>
using namespace std;

namespace differential {

class IterativeSolver {
public:

	IterativeSolver(APAbstractDomain domain, AnalysisConfiguration::Interleaving interleaving_type, bool prove_equivalence)
						: transformer_(domain.getAnalysisData()), interleaving_type_(interleaving_type), prove_equivalence_(prove_equivalence) { }
	virtual ~IterativeSolver() { }

	void assumeInputEquivalence(const FunctionDecl * fd,const FunctionDecl * fd2);
	void runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr);

	typedef APAbstractDomain_ValueTypes::ValTy State;
	typedef pair<const CFGBlock *,const CFGBlock *> BlockPair;

private:
	list< BlockPair > worklist_;
	map< BlockPair , State > statespace_, prev_statespace_;
	map< BlockPair , AbstractSet > diff_;
	map< BlockPair , unsigned int > visits_;
	map< BlockPair , set< BlockPair > > predecessors_;
	TransferFuncs transformer_;

	// this holds on which of the graphs {first,second} we advanced for each pair of nodes (effectively, this is the interleaving)
	typedef enum { FIRST_GRAPH = 1, SECOND_GRAPH = 2 } GraphPick ;
	map< BlockPair , GraphPick > interleaving_;
	map< BlockPair , bool > explored_; // have both options been explored in the interleaving?
	AnalysisConfiguration::Interleaving interleaving_type_;

	bool prove_equivalence_;

	// the traverse order
	vector< BlockPair > traversal_;

	bool advanceOnBlock(const CFG &cfg, const BlockPair pcs, bool first);
	bool advanceOnEdge(const BlockPair pcs, const BlockPair new_pcs,
					   const CFGBlock *advance_block, bool conditional, bool true_branch);
	void widen(const BlockPair pcs);
	bool nextInterleaving(const BlockPair& exit_pcs, const BlockPair& initial_pcs, const State& initial_state, int& balance);
	void saveDifference(const BlockPair &pcs);
};

}

#endif /* ITERATIVESOLVER_H_ */
