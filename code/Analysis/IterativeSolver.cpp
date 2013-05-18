/*
 * IterativeSolver.cpp
 *
 *  Created on: May 10, 2013
 *      Author: user
 */

#include "IterativeSolver.h"

#include <iostream>

namespace differential {

IterativeSolver::IterativeSolver() {
	// TODO Auto-generated constructor stub

}

IterativeSolver::~IterativeSolver() {
	// TODO Auto-generated destructor stub
}

void IterativeSolver::runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr) {
	cout << "solver starting\n";
	// worklist = { <entry1,entry2> }
	worklist_.push(make_pair(*(cfg_ptr->rbegin()),*(cfg2_ptr->rbegin())));
	std::cout << "worklist top = (\n";
	worklist_.front().first->dump(cfg_ptr,LangOptions());
	cout << ",\n";
	worklist_.front().second->dump(cfg_ptr,LangOptions());
	cout << ")\n";

	while (!worklist_.empty()) {
		pair<const CFGBlock *,const CFGBlock *> pcs = worklist_.front();
		worklist_.pop();
		advanceOnBlock(*cfg_ptr,pcs,true);
		advanceOnBlock(*cfg2_ptr,pcs,false);
	}
}
/**
 * Advances on all the edges of one of the blocks (according to @advance_on_first) and updates the state space.
 */
void IterativeSolver::advanceOnBlock(const CFG &cfg, const pair<const CFGBlock *,const CFGBlock *> pcs, bool advance_on_first) {
	const CFGBlock *advance_block, *stay_block;
	if (advance_on_first) {
		advance_block = pcs.first;
		stay_block = pcs.second;
	} else {
		advance_block = pcs.second;
		stay_block = pcs.first;
	}
	CFGBlock *first_succ = NULL, *last_succ = NULL;
	for ( CFGBlock::const_succ_iterator iter = advance_block->succ_begin(), end = advance_block->succ_end(); iter != end; ++iter) {
		if (CFGBlock * succ = *iter) {
			if (!first_succ)
				first_succ = succ;
			last_succ = succ;
		}
	}
	if (!first_succ)
		return; // no successors, continue to the next block
	cerr << "block " << advance_block->getBlockID() <<
			" first successor = " << first_succ->getBlockID() <<
			", last successor = " << last_succ->getBlockID() << "\n";
	if (first_succ != last_succ) {// this is a conditional
		// last_succ is the negated edge, apply the negation of the conditional
	}
	// get the state for the new pair of pcs
	pair<const CFGBlock *,const CFGBlock *> new_pcs = make_pair(first_succ, stay_block);
	State state = statespace_[pcs], prev_state, new_state;
	// apply the effect of the block on it (by iterating over the block statements)
	prev_state = statespace_[new_pcs]; // save the previous state for new_pcs
	for ( CFGBlock::const_iterator iter = advance_block->begin(), end = advance_block->end(); iter != end; ++iter ) {
		CFGElement e = *iter;
		if ( const CFGStmt *s = e.getAs<CFGStmt>() ) {
			// apply the stmt
			transformer_.getCFG() = cfg;
			transformer_.getVal() = state;
			new_state = transformer_.BlockStmt_Visit(const_cast<Stmt*>(s->getStmt()));
			statespace_[new_pcs] = statespace_[new_pcs].Join(new_state);
		}
	}
	cerr << "Previous state:\n";
	statespace_[new_pcs].print();
	cerr << "Current state:\n";
	prev_state.print();
	// see if the resulting state of new_pcs > previous state or this is the first visit
	if (!(statespace_[new_pcs] <= prev_state) || statespace_[new_pcs].size() == 0)
		worklist_.push(new_pcs); // if so, add it to the worklist
}

}
