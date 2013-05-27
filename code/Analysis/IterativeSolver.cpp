/*
 * IterativeSolver.cpp
 *
 *  Created on: May 10, 2013
 *      Author: user
 */

#include "IterativeSolver.h"

#include <iostream>

#define DEBUG 1

namespace differential {

void IterativeSolver::assumeInputEquivalence(const FunctionDecl * fd,const FunctionDecl * fd2) {
	assert(fd->getNumParams() == fd2->getNumParams());
	// iterate over input parameters and assume equivalence
	for (int i = 0 ; i <  fd->getNumParams() ; ++i) {
		string name = fd->getParamDecl(i)->getNameAsString();
		assert (name == fd2->getParamDecl(i)->getNameAsString());
		if (fd->getParamDecl(i)->getType().getTypePtr()->isIntegerType()) // handle only integers
			transformer_.AssumeTagEquivalence(transformer_.getVal().env_,name);
	}
	// the resulting state will be kept in the transformer until it is copied to <entry1,entry2>
}

void IterativeSolver::runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr) {
	// worklist = { <entry1,entry2> }
	worklist_.push(make_pair(*(cfg_ptr->rbegin()),*(cfg2_ptr->rbegin())));
	statespace_[worklist_.front()] = transformer_.getVal();
	while (!worklist_.empty()) {
#if(DEBUG)
		std::cerr << "worklist top = (\n";
		worklist_.front().first->dump(cfg_ptr,LangOptions());
		cerr << ",\n";
		worklist_.front().second->dump(cfg2_ptr,LangOptions());
		cerr << ")\n";
#endif
		pair<const CFGBlock *,const CFGBlock *> pcs = worklist_.front();
		worklist_.pop();
		advanceOnBlock(*cfg_ptr,pcs,true);
		advanceOnBlock(*cfg2_ptr,pcs,false);
	}
	// print the result at (EXIT,EXIT)
	const pair<const CFGBlock *,const CFGBlock *> result_pcs(*(cfg_ptr->begin()),*(cfg2_ptr->begin()));
	cerr << "Result at ";
	result_pcs.first->dump(cfg_ptr,LangOptions());
	result_pcs.second->dump(cfg2_ptr,LangOptions());
	cerr << ":\n";
	statespace_[result_pcs].print(llvm::outs());

}
/**
 * Advances on all the edges of one of the blocks (according to @advance_on_first) and updates the state space.
 */
void IterativeSolver::advanceOnBlock(const CFG &cfg, const pair<const CFGBlock *,const CFGBlock *> pcs, bool advance_on_first) {
	// if we are working on the 2nd CFG, tell the transformer it needs to treat the variables as tagged
	transformer_.tag_ = !advance_on_first;
	const CFGBlock *advance_block, *stay_block;
	// figure out on which block we are advancing
	if (advance_on_first) {
		advance_block = pcs.first;
		stay_block = pcs.second;
	} else {
		advance_block = pcs.second;
		stay_block = pcs.first;
	}
	// find the block successors
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
#if(DEBUG)
	cerr << "Advancing on " << (advance_on_first ? "first" : "second") << " CFG's block number " << advance_block->getBlockID() <<
			" Successor(s) = (" << first_succ->getBlockID() << "," << last_succ->getBlockID() << ")\n";
#endif
	// create the pcs for the target, remember to consider if we are advancing on the first or second pc
	pair<const CFGBlock *,const CFGBlock *> new_pcs = advance_on_first ? make_pair((const CFGBlock *)first_succ, stay_block) : make_pair(stay_block,(const CFGBlock *)first_succ);
	advanceOnEdge(pcs,new_pcs,advance_block,first_succ != last_succ,true);
	// a block can have 2 edges
	if (first_succ != last_succ) {// this is a conditional
		// do the false branch
		new_pcs = advance_on_first ? make_pair((const CFGBlock *)last_succ, stay_block) : make_pair(stay_block,(const CFGBlock *)last_succ);
		advanceOnEdge(pcs,new_pcs,advance_block,true,false);
	}
}

void IterativeSolver::advanceOnEdge(const pair<const CFGBlock *,const CFGBlock *> pcs,
		const pair<const CFGBlock *,const CFGBlock *> new_pcs,
		const CFGBlock *advance_block, bool conditional, bool true_branch) {
	// apply the effect of advancing over an edge (by iterating over the block statements)
	transformer_.getVal() = statespace_[pcs]; // start off from the current state
	for ( CFGBlock::const_iterator iter = advance_block->begin(), end = advance_block->end(); iter != end; ++iter ) {
		CFGElement e = *iter;
		if ( const CFGStmt *s = e.getAs<CFGStmt>() ) {
			// apply the statement
			ExpressionState es = transformer_.BlockStmt_Visit(const_cast<Stmt*>(s->getStmt()));
			if (conditional && iter + 1 == end) { // only the last element is the actual conditional (otherwise es.s_ is [] and meeting with it will be bad)
				if (true_branch)
					transformer_.getVal() &= es.s_;
				else
					transformer_.getVal() &= es.ns_;
			}
		}
	}
	//bool first = (statespace_.count(new_pcs) == 0);
	State prev_state = statespace_[new_pcs]; // save the previous state of new_pcs
	statespace_[new_pcs] = statespace_[new_pcs].Join(transformer_.getVal());
#if(DEBUG)
	cerr << "\nTransformed from state:\n";
	statespace_[pcs].print(llvm::outs());
	cerr << "\nTo state:\n";
	transformer_.getVal().print(llvm::outs());
	cerr << "\nJoined into:\n";
	statespace_[new_pcs].print(llvm::outs());
#endif
	// see if the resulting state of new_pcs > previous state or this is the first visit
	if (!(statespace_[new_pcs] <= prev_state) /*|| first*/)
		worklist_.push(new_pcs); // if so, add it to the worklist
}

}// end namespace differential
