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

enum { MAX_K = 20 };

class IterativeSolver {

public:

	IterativeSolver() {} // deault c'tor defined for threading

	IterativeSolver(APAbstractDomain domain, unsigned int k, unsigned int p) : transformer_(domain.getAnalysisData()), k_(k), p_(p), steps_(0) { assert(k <= MAX_K); }
	virtual ~IterativeSolver() { }

	void AssumeInputEquivalence(const FunctionDecl * fd,const FunctionDecl * fd2);
	void AssumeInitialEquivalence(Stmt* root, ASTContext &context, bool tag); // search CFG for declarations and UFs and assume equivalence for them

	void RunOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr);

	typedef APAbstractDomain_ValueTypes::ValTy State;
	typedef pair<const CFGBlock *,const CFGBlock *> CFGBlockPair;
	pair < set< const CFGBlock *>,set< const CFGBlock *> > backedge_blocks_;

	set< CFGBlockPair > workset_;
	set< CFGBlockPair > changed_;
	map< CFGBlockPair , State > statespace_, prev_statespace_;
	map< CFGBlockPair , unsigned int > visits_;

	enum { NOT_COMPUTED = -1, EQUIVALENCE = 0 };

	TransferFuncs transformer_;

	// this holds on which of the graphs {first,second} we advanced for each pair of nodes (effectively, this is the interleaving)
	typedef enum { FIRST_GRAPH, SECOND_GRAPH } GraphPick ;
	unsigned int k_, p_, steps_;

	void AdvanceOnBlock(const CFG &cfg, const CFGBlockPair pcs, GraphPick which);
	void AdvanceOnEdge(const CFGBlockPair &new_pcs, bool conditional, bool true_branch);
	void Widen(const CFGBlockPair pcs);
	IterativeSolver FindMinimalDiffSolver(CFG * cfg_ptr,CFG * cfg2_ptr, vector<IterativeSolver> solvers);
	bool Step(CFG * cfg_ptr, CFG * other_cfg_ptr, GraphPick which);
	bool Speculate(CFG * cfg_ptr,CFG * cfg2_ptr,unsigned int k1, unsigned int k2);

	void Succesors(set<CFGBlockPair> pairs, GraphPick which, set<CFGBlockPair> &result);
	void GetSuccesors(set<CFGBlockPair> &result, CFGBlockPair from_block, const CFGBlock * advance_block);

	operator string() const {
		stringstream ss;
		ss << "workset = { ";
		for (set< CFGBlockPair >::const_iterator iter = workset_.begin(), end = workset_.end(); iter != end; ++iter) {
			ss << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << "),";
		}
		ss << " }\n";
		for (map< CFGBlockPair , State >::const_reverse_iterator iter = statespace_.rbegin(), end = statespace_.rend(); iter != end; ++iter) {
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
	bool CanPOR(void);
	bool Backedges(const CFGBlockPair& pcs);
	void Partition();

	// experimental!
	static void * SpeculateParallel(void * arguments);
	static void * ComputeEquivalenceScoreParallel(void * arguments);
};

// for threading (experimental):
struct ThreadArguments {
	IterativeSolver is;
	CFG * cfg_ptrs[2];
	int k[2];
	float score;
	ThreadArguments() {}
};

}

#endif /* ITERATIVESOLVER_H_ */
