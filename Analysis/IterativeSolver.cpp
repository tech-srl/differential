/*
 * IterativeSolver.cpp
 *
 *  Created on: May 10, 2013
 *      Author: user
 */

#include "IterativeSolver.h"

#include <iostream>

#define DEBUG 0

namespace differential {

void IterativeSolver::assumeInputEquivalence(const FunctionDecl * fd,const FunctionDecl * fd2) {
	assert(fd->getNumParams() == fd2->getNumParams());
	// iterate over input parameters and assume equivalence
	for (int i = 0 ; i <  fd->getNumParams() ; ++i) {
		string name = fd->getParamDecl(i)->getNameAsString();
		assert (name == fd2->getParamDecl(i)->getNameAsString());
		if (fd->getParamDecl(i)->getType().getTypePtr()->isIntegerType()) // handle only integers
			transformer_.AssumeTagEquivalence(transformer_.getVal(),name);
	}
	// the resulting state will be kept in the transformer until it is copied to <entry1,entry2>
}

void IterativeSolver::runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr) {
	pair<const CFGBlock *,const CFGBlock *> initial_pcs(*(cfg_ptr->rbegin()),*(cfg2_ptr->rbegin()));
	State initial_state = transformer_.getVal();
	int balance = 0;

	// worklist = { (entry1,entry2) }, statespace = { (entry1,entry2)->{V=V'} }
	worklist_.push_back(initial_pcs);
	statespace_[worklist_.front()] = initial_state;

	pair<const CFGBlock *,const CFGBlock *> exit_pcs(*(cfg_ptr->begin()),*(cfg2_ptr->begin()));
	diff_[exit_pcs] = State(); // initialize diff_[<EXIT,EXIT>]
	while (!worklist_.empty()) {
#if(DEBUG)
		errs() << "worklist top = (\n";
		worklist_.front().first->dump(cfg_ptr,LangOptions());
		errs() << ",\n";
		worklist_.front().second->dump(cfg2_ptr,LangOptions());
		errs() << ")\n";
#endif
		pair<const CFGBlock *,const CFGBlock *> pcs = worklist_.front();
		worklist_.pop_front();
		visits_[pcs]++; // number of times visited

		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_ALL) {
			advanceOnBlock(*cfg_ptr,pcs,true);
			advanceOnBlock(*cfg2_ptr,pcs,false);
			continue;
		}

		// otherwise:
		if (interleaving_.count(pcs) == 0) {
			// first time we encounter this pair of nodes, add to the traversal order
			traversal_.push_back(pcs);
			explored_[pcs] = false;
			// pick on which of the graphs we advance when arriving at this pair of nodes
			if (pcs.first == *(cfg_ptr->begin())) { // first graph is at EXIT
				interleaving_[pcs] = SECOND_GRAPH;
			} else if (pcs.second == *(cfg2_ptr->begin())) { // second graph is at EXIT
				interleaving_[pcs] = FIRST_GRAPH;
			} else if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_BALANCED) { // balanced interleaving
				if (balance <= 0) {
					interleaving_[pcs] = FIRST_GRAPH;
					balance++;
				} else {
					interleaving_[pcs] = SECOND_GRAPH;
					balance--;
				}
			} else { // enumerate through all interleavings
				interleaving_[pcs] = FIRST_GRAPH;
			}
		}

		/* this is the code for the equivalence search. */
		bool advance_on_first = (interleaving_[pcs] == FIRST_GRAPH);
		if (advanceOnBlock(advance_on_first ? *cfg_ptr : *cfg2_ptr,pcs,advance_on_first) && prove_equivalence_) {
			// partitioning happened and equivalence was broken in prove-equiv mode, restart with a different interleaving
			outs() << "Equivalence broken on interleaving: ";
			for (int index = 0; index < traversal_.size() ; ++index) {
				pair<const CFGBlock *,const CFGBlock *> pcs = traversal_[index];
				outs() << "-->(" << pcs.first->getBlockID() << ',' << pcs.second->getBlockID() << ')';
			}
			outs() << '\n';
			// iteratively: go to the last pair of nodes traversed
			while (!traversal_.empty()) {
				pair<const CFGBlock *,const CFGBlock *> last_pcs = traversal_[traversal_.size() - 1];
				if (explored_[last_pcs] || // both options were explored,
					last_pcs.second == exit_pcs.second || last_pcs.first == exit_pcs.first) { // or one of the graphs is at EXIT
					// pop the last pair of nodes, clear their interleaving choice and re-iterate
					traversal_.pop_back();
					interleaving_.erase(last_pcs);
					explored_[last_pcs] = false;
					visits_[last_pcs] = 0;
					predecessors_.erase(last_pcs);
				} else {
					// if advancement was made on graph 1, try graph 2 and vice versa
					if (interleaving_[last_pcs] == FIRST_GRAPH) {
						interleaving_[last_pcs] = SECOND_GRAPH;
						balance -= 2;
					} else if (interleaving_[last_pcs] == SECOND_GRAPH) {
						interleaving_[last_pcs] = FIRST_GRAPH;
						balance += 2;
					}
					explored_[last_pcs] = true; // both options for this node has been explored at this point
					worklist_.clear();
					statespace_.clear();
					prev_statespace_.clear();
					visits_.clear();
					predecessors_.clear();
					balance++;
					worklist_.push_back(initial_pcs);
					statespace_[worklist_.front()] = initial_state;
					break;
				}
			}
			if (traversal_.empty()) { // we exhausted all interleavings
				outs() << "All interleavings explored, none yielded equivalence, exiting.\n";
				exit(0);
			}
		}

		/*
		bool advance_on_first = (interleaving_[pcs] == FIRST_GRAPH);
		advanceOnBlock(advance_on_first ? *cfg_ptr : *cfg2_ptr,pcs,advance_on_first);
		if (pcs == exit_pcs) { // at <EXIT,EXIT>
			// meet the state
			diff_[pcs] = diff_[pcs].Meet(statespace_[pcs]);
			// iteratively: go to the last pair of nodes traversed
			while (!traversal_.empty()) {
				pair<const CFGBlock *,const CFGBlock *> last_pcs = traversal_[traversal_.size() - 1];
				if (explored_[last_pcs]) { // both options were explored, pop the last pair of nodes, clear their interleaving choice and re-iterate
					traversal_.pop_back();
					interleaving_.erase(last_pcs);
				} else {
					// if advancement was made on graph 1, try graph 2 and vice versa
					if (interleaving_[last_pcs] == FIRST_GRAPH) {
						interleaving_[last_pcs] = SECOND_GRAPH;
						balance -= 2;
					} else {
						interleaving_[last_pcs] = FIRST_GRAPH;
						balance += 2;
					}
					explored_[last_pcs] = true; // both options for this node has been explored at this point
					worklist_.clear();
					statespace_.clear();
					prev_statespace_.clear();
					visits_.clear();
					predecessors_.clear();
					balance++;
					worklist_.push_back(initial_pcs);
					statespace_[worklist_.front()] = initial_state;
					for (int index = 0; index < traversal_.size() ; ++index) {
						pair<const CFGBlock *,const CFGBlock *> pcs = traversal_[index];
						outs() << "-->(" << pcs.first->getBlockID() << ',' << pcs.second->getBlockID() << ')';
					}
					outs() << '\n';
					break;
				}
			}
			if (traversal_.empty()) { // we exhausted all interleavings
				outs() << "All interleavings explored, none yielded equivalence, exiting.\n";
				exit(0);
			}
		}
		*/
#if(DEBUG)
		//getchar();
#endif
	}
	// print the result at (EXIT,EXIT)
	const pair<const CFGBlock *,const CFGBlock *> result_pcs(*(cfg_ptr->begin()),*(cfg2_ptr->begin()));
	outs() << "Result at ";
	result_pcs.first->print(outs(),cfg_ptr,LangOptions());
	result_pcs.second->print(outs(),cfg2_ptr,LangOptions());
	outs() << ":\n";
	statespace_[result_pcs].print(outs());
	outs() << "Minimal diff:";
	diff_[result_pcs].print(outs());
	outs() << '\n';
	outs() << statespace_[result_pcs].ComputeDiff();
	outs() << "Interleaving is: ";
	for (int index = 0; index < traversal_.size() ; ++index) {
		pair<const CFGBlock *,const CFGBlock *> pcs = traversal_[index];
		outs() << "-->(" << pcs.first->getBlockID() << ',' << pcs.second->getBlockID() << ')';
	}
	outs() << '\n';
}
/**
 * Advances on all the edges of one of the blocks (according to @advance_on_first) and updates the state space.
 */
bool IterativeSolver::advanceOnBlock(const CFG &cfg, const pair<const CFGBlock *,const CFGBlock *> pcs, bool advance_on_first) {
	/**
	 * TODO: when/if we introduce correlation point, set the state flag accordingly
	 * statespace_[pcs].at_diff_point_ = ?;
	 */
	// start off by checking if this is a join point
	if (predecessors_[pcs].size() > 1) { // if so, partition according to strategy
		if (State::partition_point == State::PARTITION_AT_JOIN) {
			if (statespace_[pcs].Partition() && !AnalysisUtils::CheckEquivalence(*statespace_[pcs].mgr_ptr_,statespace_[pcs].abs_set_)) {
				// equivalence is broken
#if(DEBUG)
				errs() << "Equivalence broken, offending state: " << statespace_[pcs];
#endif
				return true;
			}
#if(DEBUG)
			errs() << "\nAfter Partitioning:\n";
			statespace_[pcs].print(errs());
#endif
		}

	}

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
		return false; // no successors, continue to the next block
#if(DEBUG)
	errs() << "Advancing on " << (advance_on_first ? "first" : "second") << " CFG's block number " << advance_block->getBlockID() <<
			" Successor(s) = (" << first_succ->getBlockID() << "," << last_succ->getBlockID() << ")\n";
#endif
	// create the pcs for the target, remember to consider if we are advancing on the first or second pc
	pair<const CFGBlock *,const CFGBlock *> new_pcs = advance_on_first ? make_pair((const CFGBlock *)first_succ, stay_block) :
			make_pair(stay_block,(const CFGBlock *)first_succ);
	predecessors_[new_pcs].insert(pcs);
	if (advanceOnEdge(pcs,new_pcs,advance_block,first_succ != last_succ,true)) { // equivalence broken
#if(DEBUG)
		errs() << "Advancing over edge caused equivalence to break at (" << new_pcs.first->getBlockID() << ',' << new_pcs.second->getBlockID() << "), Reverting.\n";
#endif
		return true;
	}
	// a block can have 2 edges
	if (first_succ != last_succ) {// this is a conditional
		// do the false branch
		new_pcs = advance_on_first ? make_pair((const CFGBlock *)last_succ, stay_block) : make_pair(stay_block,(const CFGBlock *)last_succ);
		predecessors_[new_pcs].insert(pcs);
		if (advanceOnEdge(pcs,new_pcs,advance_block,true,false)) {
#if(DEBUG)
			errs() << "Advancing over edge caused equivalence to break at (" << new_pcs.first->getBlockID() << ',' << new_pcs.second->getBlockID() << "), Reverting.\n";
			getchar();
#endif
			return true;
		}
	}
	return false;
}

/**
 * Advances over the edge (pcs)->(new_pcs) and joins the result into the state held from new_pcs.
 *
 * Returns a flag conveying whether advancing over the edge caused the state at (new_pcs) to lose equivalence (from partitioning).
 * in such a case, we may want to backtrack and choose a different interleaving.
 */
bool IterativeSolver::advanceOnEdge(const pair<const CFGBlock *,const CFGBlock *> pcs,
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
	if (visits_.count(new_pcs) == 0)
		visits_[new_pcs] = 0;
	prev_statespace_[new_pcs] = statespace_[new_pcs]; // save the previous state of new_pcs
	statespace_[new_pcs] = statespace_[new_pcs].Join(transformer_.getVal());
#if(DEBUG)
	errs() << "\nTransformed from state:\n";
	statespace_[pcs].print(llvm::errs());
	errs() << "\nTo state:\n";
	transformer_.getVal().print(llvm::errs());
	errs() << "\nJoined into:\n";
	statespace_[new_pcs].print(llvm::errs());
	errs() << "\nVisit number " << visits_[pcs] << "\n";
#endif

	if (visits_[new_pcs] > State::widening_threshold) {
		widen(new_pcs);
	}

	// see if the resulting state of new_pcs > previous state TODO: or this is the first visit
	if (!(statespace_[new_pcs] <= prev_statespace_[new_pcs]) /*|| first*/)
		worklist_.push_back(new_pcs); // if so, add it to the worklist

	return false;

}

#define DEBUGWiden 0
void IterativeSolver::widen(const pair<const CFGBlock *,const CFGBlock *> pcs) {
	if (State::widening_point == State::WIDEN_AT_ALL) {
		State::Widening(prev_statespace_[pcs],statespace_[pcs],statespace_[pcs]);
	} else if (State::widening_point == State::WIDEN_AT_BACK_EDGE) {
		int backedge1_id = Utils::hasBackEdge(pcs.first), backedge2_id = Utils::hasBackEdge(pcs.second);
		if (backedge1_id >= 0 && backedge2_id >= 0) {
#if (DEBUGWiden)
			errs() << "Back Edges Found! (" << pcs.first->getBlockID() << "," << pcs.second->getBlockID() << ")\n";
#endif
		}
		State::Widening(prev_statespace_[pcs],statespace_[pcs],statespace_[pcs]);
	} else if (State::widening_point == State::WIDEN_AT_CORR_POINT && statespace_[pcs].at_diff_point_ == true) {
#if (DEBUGWiden)
		errs() << "\nDiff Point Found!, Widneing...\n";
#endif
		State::Widening(prev_statespace_[pcs],statespace_[pcs],statespace_[pcs]);
	}
#if (DEBUGWiden)
	errs() << "\nWidening Result:\n";
	statespace_[pcs].print(llvm::errs());
#endif
}

}// end namespace differential
