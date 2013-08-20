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

bool IterativeSolver::nextInterleaving(
		const pair<const CFGBlock*, const CFGBlock*>& exit_pcs,
		const pair<const CFGBlock*, const CFGBlock*>& initial_pcs,
		const State& initial_state, int& balance) {
	outs() << "Moving on from interleaving: ";
	for (int index = 0; index < traversal_.size() ; ++index) {
		BlockPair pcs = traversal_[index];
		outs() << "-->(" << pcs.first->getBlockID() << ',' << pcs.second->getBlockID() << ')';
	}
	outs() << '\n';
	// iteratively: go to the last pair of nodes traversed
	while (!traversal_.empty()) {
		pair<const CFGBlock*, const CFGBlock*> last_pcs = traversal_[traversal_.size() - 1];
		if (explored_[last_pcs] || // both options were explored
				last_pcs.first == exit_pcs.first ||
				last_pcs.second == exit_pcs.second) { // or one of the graphs is at EXIT
			// pop the last pair of nodes, clear their interleaving choice and re-iterate
			traversal_.pop_back();
			if (interleaving_[last_pcs] == FIRST_GRAPH) {
				balance -= 1;
			} else if (interleaving_[last_pcs] == SECOND_GRAPH) {
				balance += 1;
			}
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
			worklist_.push_back(initial_pcs);
			statespace_[worklist_.front()] = initial_state;
			break;
		}
	}
	if (traversal_.empty()) {
		// we exhausted all interleavings
		outs() << "All interleavings explored.\n";
		return false;
	}
	return true;
}

// compare the differncing parts of the state at pcs to the difference collected from all interleavings, and add it if its better
void IterativeSolver::saveDifference(const BlockPair &pcs) {
	if (diff_.count(pcs) == 0) { // first time we encounter these pcs, initialize to empty set
		diff_[pcs] = AbstractSet();
	} else if (diff_[pcs].size() == 0) { // the diff was previously proven to be empty by a certain interleaving, exit
		return;
	}
#if (DEBUG)
	State diff_state;
	diff_state.abs_set_ = diff_[pcs];
	cerr << "Arrived at <EXIT,EXIT>, diff is " << diff_state << "\nComparing current state in hopes to find smaller difference...\n";
#endif
	manager mgr = *transformer_.getVal().mgr_ptr_;
	if (AnalysisUtils::CheckEquivalence(mgr,statespace_[pcs].abs_set_) == true) {
		// the diff is proven to be empty by the current interleaving
		diff_[pcs].clear();
		return;
	}
	for (AbstractSet::const_iterator state_iter = statespace_[pcs].abs_set_.begin(), state_end = statespace_[pcs].abs_set_.end(); state_iter != state_end; ++state_iter) {
		// if the state holds no difference, continue on
		if (AnalysisUtils::HoldsEquivalence(state_iter->vars)) {
			continue;
		}
		bool insert = true;
		abstract1 current_abs = state_iter->vars;
		for (AbstractSet::const_iterator diff_iter = diff_[pcs].begin(), diff_end = diff_[pcs].end(); diff_iter != diff_end; ++diff_iter) {
			abstract1 diff_abs = diff_iter->vars;
			environment joined_env = AnalysisUtils::JoinEnvironments(current_abs.get_environment(),diff_abs.get_environment());
			current_abs.change_environment(mgr,joined_env);
			diff_abs.change_environment(mgr,joined_env);
			if (current_abs >= diff_abs) { // we already have a smaller (better) difference in the set, move on
				insert = false;
				break;
			} else if (current_abs < diff_abs) { // otherwise, if the difference is smaller than the one in the set, replace them
				diff_[pcs].erase(diff_iter);
#if (DEBUG)
				cerr << "Differencing state " << *state_iter << " smaller than " << *diff_iter << " and will replace it.\n";
#endif
			}
		}
		if (insert) { // if we arrived here, the difference is either smaller than one found in the set, or non comparable, add it either way
			Abstract2 diff;
			diff.vars = current_abs;
			diff.guards = state_iter->guards;
			diff_[pcs].insert(diff);
#if (DEBUG)
			cerr << "Inserting state " << *state_iter << '\n';
#endif
		}
	}
}

void IterativeSolver::runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr) {
	BlockPair initial_pcs(*(cfg_ptr->rbegin()),*(cfg2_ptr->rbegin()));
	// initial state = { V==V' }
	State initial_state = transformer_.getVal();
	int balance = 0;

	// worklist = { (entry1,entry2) }, statespace = { (entry1,entry2)->{ V==V' } }
	worklist_.push_back(initial_pcs);
	statespace_[worklist_.front()] = initial_state;

	BlockPair exit_pcs(*(cfg_ptr->begin()),*(cfg2_ptr->begin()));
	while (!worklist_.empty()) {
#if(DEBUG)
		errs() << "worklist top = (\n";
		worklist_.front().first->dump(cfg_ptr,LangOptions());
		errs() << ",\n";
		worklist_.front().second->dump(cfg2_ptr,LangOptions());
		errs() << ")\n";
#endif
		BlockPair pcs = worklist_.front();
		worklist_.pop_front();
		visits_[pcs]++; // number of times visited

		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_ALL) {
			advanceOnBlock(*cfg_ptr,pcs,true);
			advanceOnBlock(*cfg2_ptr,pcs,false);
			continue;
		}

		// greedy mode:
		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_GREEDY) {
			if (pcs.first == exit_pcs.first) { // first graph is at EXIT, advance on second
				advanceOnBlock(*cfg2_ptr,pcs,false);
			} else if (pcs.second == exit_pcs.second) { // second graph is at EXIT, advance on first
				advanceOnBlock(*cfg_ptr,pcs,true);
			} else { // speculatively advance on both and choose the better result (diff-wise)
				IterativeSolver initial_solver = *this;
				advanceOnBlock(*cfg_ptr,pcs,true);
				IterativeSolver solver_first = *this;
				State diff1;
				diff1.abs_set_ = diff_[worklist_.back()];
				*this = initial_solver;
				advanceOnBlock(*cfg2_ptr,pcs,false);
				State diff2;
				diff2.abs_set_ = diff_[worklist_.back()];
				if (diff1 <= diff2) {
					*this = solver_first;
				}
			}

		}

		// otherwise:
		if (interleaving_.count(pcs) == 0) {
			// first time we encounter this pair of nodes, add to the traversal order
			traversal_.push_back(pcs);
			explored_[pcs] = false;
			// pick on which of the graphs we advance when arriving at this pair of nodes
			if (pcs.first == exit_pcs.first) { // first graph is at EXIT
				interleaving_[pcs] = SECOND_GRAPH;
			} else if (pcs.second == exit_pcs.second) { // second graph is at EXIT
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
			if (nextInterleaving(exit_pcs, initial_pcs, initial_state, balance) == false) {
				outs() << "None yielded equivalence, exiting\n";
				exit(0);
			}
			continue;
		}

		// if we arrived at <EXIT,EXIT>, save the difference if it's not greater than any of the ones found so far
		if (!prove_equivalence_ && pcs == exit_pcs) {
			saveDifference(pcs);
			// now go to the next interleaving and restart the analysis
			if (nextInterleaving(exit_pcs, initial_pcs, initial_state, balance) == false) {
				// all interleaving explored, finish
				break;
			}
		}

#if(DEBUG)
		getchar();
#endif
	}
	// print the result at (EXIT,EXIT)
	outs() << "(Last) Result at (EXIT,EXIT):";
	statespace_[exit_pcs].print(outs());
	if (diff_.count(exit_pcs) > 0) {
		outs() << "Minimal diff:";
		State diff_state;
		diff_state.abs_set_ = diff_[exit_pcs];
		diff_state.print(outs());
	}
	outs() << statespace_[exit_pcs].ComputeDiff();
	outs() << "Interleaving is: ";
	for (int index = 0; index < traversal_.size() ; ++index) {
		BlockPair pcs = traversal_[index];
		outs() << "-->(" << pcs.first->getBlockID() << ',' << pcs.second->getBlockID() << ')';
	}
	outs() << '\n';
}
/**
 * Advances on all the edges of one of the blocks (according to @advance_on_first) and updates the state space.
 */
bool IterativeSolver::advanceOnBlock(const CFG &cfg, const BlockPair pcs, bool advance_on_first) {
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
	BlockPair new_pcs = advance_on_first ? make_pair((const CFGBlock *)first_succ, stay_block) :
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
bool IterativeSolver::advanceOnEdge(const BlockPair pcs,
		const BlockPair new_pcs,
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

	saveDifference(new_pcs);

	return false;

}

#define DEBUGWiden 0
void IterativeSolver::widen(const BlockPair pcs) {
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
