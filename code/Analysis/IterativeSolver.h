/*
 * IterativeSolver.h
 *
 *  Created on: May 10, 2013
 *      Author: user
 */

#ifndef ITERATIVESOLVER_H_
#define ITERATIVESOLVER_H_

#include "AnalysisUtils.h"
#include "APAbstractDomain.h"
#include "TransferFuncs.h"

#include <clang/Analysis/CFG.h>
using namespace clang;

#include <list>
using namespace std;

namespace differential {

class IterativeSolver {
public:

	IterativeSolver(APAbstractDomain domain) : transformer_(domain.getAnalysisData()) { }
	virtual ~IterativeSolver() { }

	void assumeInputEquivalence(const FunctionDecl * fd,const FunctionDecl * fd2);
	void runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr);

	typedef APAbstractDomain_ValueTypes::ValTy State;

private:
	list< pair<const CFGBlock *,const CFGBlock *> > worklist_;
	map< pair<const CFGBlock *,const CFGBlock *> , State > statespace_, prev_statespace_;
	map< pair<const CFGBlock *,const CFGBlock *> , unsigned int > visits_;
	map< pair<const CFGBlock *,const CFGBlock *> , set< pair<const CFGBlock *,const CFGBlock *> > > preds_;
	TransferFuncs transformer_;

	// this holds on which of the graphs {first,second} we advanced for each pair of nodes (effectively, this is the interleaving)
	typedef enum { FIRST_GRAPH = 1, SECOND_GRAPH = 2 } GraphPick ;
	map< pair<const CFGBlock *,const CFGBlock *> , GraphPick > interleaving_;

	// the traverse order
	vector< pair<const CFGBlock *,const CFGBlock *> > traversal_;

	bool advanceOnBlock(const CFG &cfg, const pair<const CFGBlock *,const CFGBlock *> pcs, bool first);
	bool advanceOnEdge(const pair<const CFGBlock *,const CFGBlock *> pcs, const pair<const CFGBlock *,const CFGBlock *> new_pcs,
					   const CFGBlock *advance_block, bool conditional, bool true_branch);
	void widen(const pair<const CFGBlock *,const CFGBlock *> pcs);
};

}

#endif /* ITERATIVESOLVER_H_ */
