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

	IterativeSolver(APAbstractDomain domain, AnalysisConfiguration::Interleaving interleaving_type, unsigned int k, unsigned int p, bool prove_equivalence)
: transformer_(domain.getAnalysisData()), interleaving_type_(interleaving_type), k_(k), p_(p), steps_(0), prove_equivalence_(prove_equivalence) { }
	virtual ~IterativeSolver() { }

	void assumeInputEquivalence(const FunctionDecl * fd,const FunctionDecl * fd2);
	void runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr);

	typedef APAbstractDomain_ValueTypes::ValTy State;
	typedef pair<const CFGBlock *,const CFGBlock *> CFGBlockPair;
	pair < set< const CFGBlock *>,set< const CFGBlock *> > backedge_blocks_;

	set< CFGBlockPair > workset_;
	map< CFGBlockPair , State > statespace_, prev_statespace_;
	map< CFGBlockPair , unsigned int > visits_;
	map< CFGBlockPair , set< CFGBlockPair > > predecessors_;
	TransferFuncs transformer_;

	// this holds on which of the graphs {first,second} we advanced for each pair of nodes (effectively, this is the interleaving)
	typedef enum { FIRST_GRAPH = 1, SECOND_GRAPH = 2 } GraphPick ;
	map< CFGBlockPair , GraphPick > interleaving_;
	map< CFGBlockPair , bool > explored_; // have both options been explored in the interleaving?
	AnalysisConfiguration::Interleaving interleaving_type_;
	unsigned int k_, p_, steps_;

	bool prove_equivalence_;

	// the traverse order
	vector< CFGBlockPair > traversal_;

	void advanceOnBlock(const CFG &cfg, const CFGBlockPair pcs, GraphPick which);
	void advanceOnEdge(const CFGBlockPair pcs, const CFGBlockPair new_pcs,
			const CFGBlock *advance_block, bool conditional, bool true_branch);
	void widen(const CFGBlockPair pcs);
	bool nextInterleaving(const CFGBlockPair& exit_pcs, const CFGBlockPair& initial_pcs, const State& initial_state, int& balance);
	IterativeSolver findMinimalDiffSolver(CFG * cfg_ptr,CFG * cfg2_ptr, vector<IterativeSolver> solvers);
	void step(CFG * cfg_ptr, GraphPick which);
	void kSteps(CFG * cfg_ptr,CFG * cfg2_ptr,unsigned int k1, unsigned int k2,  vector<IterativeSolver> &results);

	operator string() const {
		stringstream ss;
		ss << "workset = { ";
		for (set< CFGBlockPair >::const_iterator iter = workset_.begin(), end = workset_.end(); iter != end; ++iter) {
			ss << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << "),";
		}
		ss << " }\n";
		for (map< CFGBlockPair , State >::const_iterator iter = statespace_.begin(), end = statespace_.end(); iter != end; ++iter) {
			ss << "(" << iter->first.first->getBlockID() << "," << iter->first.second->getBlockID() << ") : " << iter->second << "\n";
		}
		return ss.str();
	}
	friend ostream& operator<<(ostream& os, const IterativeSolver& V);
	bool operator==(const IterativeSolver& rhs) const { return (string)*this == (string)rhs; }
	bool operator!=(const IterativeSolver& rhs) const { return !(*this == rhs); }
	bool operator<=(const IterativeSolver& rhs) const { return (string)*this <= (string)rhs; }
	bool operator<(const IterativeSolver& rhs) const { return (*this != rhs) && (*this <= rhs); }

private:
	void FindBackedges(const CFGBlock* initial, set<const CFGBlock*> visited, set<const CFGBlock*> &result);
};

}

#endif /* ITERATIVESOLVER_H_ */
