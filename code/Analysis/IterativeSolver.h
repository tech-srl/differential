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
#include "IterativeTransformer.h"

#include <clang/Analysis/CFG.h>
using namespace clang;

#include <queue>
using namespace std;

namespace differential {

class IterativeSolver {
public:

	IterativeSolver();
	virtual ~IterativeSolver();

	void runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr);

	typedef APAbstractDomain_ValueTypes::ValTy State;

private:
	queue< pair<const CFGBlock *,const CFGBlock *> > worklist_;
	map< pair<const CFGBlock *,const CFGBlock *> , State > statespace_;
	IterativeTransformer transformer_;

	void advanceOnBlock(const CFG &cfg, const pair<const CFGBlock *,const CFGBlock *> pcs, bool first);
};

}

#endif /* ITERATIVESOLVER_H_ */
