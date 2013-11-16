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
		CFGBlockPair pcs = traversal_[index];
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
			workset_.clear();
			statespace_.clear();
			prev_statespace_.clear();
			visits_.clear();
			predecessors_.clear();
			workset_.insert(initial_pcs);
			statespace_[initial_pcs] = initial_state;
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

IterativeSolver IterativeSolver::findMinimalDiffSolver(CFG * cfg_ptr,CFG * cfg2_ptr, vector<IterativeSolver> solvers) {
	const unsigned int size = solvers.size();
	assert(size > 0);
	if (size == 1)
		return solvers[0];
	errs() << "findMinimalDiffSolver: picking from " << size << " solvers.\n";
	manager &mgr = *(transformer_.getVal().mgr_ptr_);

	// define the score array and initialize to 0
	unsigned int score[size];
	memset(score,0,sizeof(unsigned int) * size);

	// alg: first check at back edges
	//		then equivalence gives a +1 * (number of block pairs), s.t. 1 equivalent block pair is better than a graph full of bottoms
	//		then bottoms get +1

	unsigned int num_block_pairs = cfg_ptr->getNumBlockIDs() * cfg2_ptr->getNumBlockIDs();

	for (set<const CFGBlock *>::const_iterator iter = backedge_blocks_.first.begin(), end = backedge_blocks_.first.end(); iter != end; ++iter) {
		for (set<const CFGBlock *>::const_iterator iter2 = backedge_blocks_.second.begin(), end2 = backedge_blocks_.second.end(); iter2 != end2; ++iter2) {
			CFGBlockPair pcs(*iter,*iter2);
			for (unsigned int i = 0; i < size ; ++i) {
				if (solvers[i].statespace_.count(pcs) && AnalysisUtils::CheckEquivalence(mgr,solvers[i].statespace_[pcs].abs_set_))
					score[i] += num_block_pairs * num_block_pairs;
			}
		}
	}

	set< CFGBlockPair > workset;
	for (CFG::const_iterator iter = cfg_ptr->begin(), end = cfg_ptr->end(); iter != end; ++iter) {
		for (CFG::const_iterator iter2 = cfg2_ptr->begin(), end2 = cfg2_ptr->end(); iter2 != end2; ++iter2) {
			workset.insert(make_pair(*iter,*iter2));
		}
	}

	// for each of the pcs in work set, find the best result (solver) from the solver list
	for (set<CFGBlockPair>::const_iterator pcs_iter = workset.begin(), pcs_end = workset.end(); pcs_iter != pcs_end; ++pcs_iter) {
		const CFGBlockPair &pcs = *pcs_iter;
		bool equivalence = false;
		/**
		 *  first try and find equivalence. if any of the solvers has equivalence for these pcs,
		 *  it gets a +1 and others will get a +1 only if they have equivalence as well
		 */
		for (unsigned int i = 0; i < size ; ++i) {
			if (solvers[i].statespace_.count(pcs) > 0 &&
					AnalysisUtils::CheckEquivalence(mgr,solvers[i].statespace_[pcs].abs_set_) == true) {
				// some solver found equivalence for the current pcs
				score[i] += num_block_pairs;
				equivalence = true;
			}
		}
		if (equivalence) // equivalence was found, no need to check differences
			continue;

		bool empty_diff = false;
		for (unsigned int i = 0; i < size ; ++i) {
			if (solvers[i].statespace_.count(pcs) == 0 ||  solvers[i].statespace_[pcs].size() == 0) {
				score[i]++;
				empty_diff = true;
			}
		}
		if (empty_diff) // empty_diff was found, no need to compute differences
			continue;

		// all solvers have a non-empty diff at this point, find the smallest one
		unsigned int diff[size];
		memset(diff,0,sizeof(unsigned int) * size);
		State delta_plus,delta_minus;
		unsigned int min = (unsigned int)(-1);
		for (unsigned int i = 0; i < size ; ++i) {
			if (solvers[i].statespace_.count(pcs)) {
				diff[i] = solvers[i].statespace_[pcs].ComputeDiff(true,false,false,delta_plus,delta_minus).size();
				if (min > diff[i]) {
					diff[i] = min;
				}
			}
		}

		for (unsigned int i = 0; i < size ; ++i) {
			if (diff[i] == min) {
				score[i]++;
			}
		}

	}

	// pick the solver with the highest score
	unsigned int max = 0, index = 0;
	for (unsigned int i = 0; i < size ; ++i) {
		if (score[i] > max) {
			max = score[i];
			index = i;
		}
#if (DEBUG1)
		cerr << "Solver #" << i << " has score " << score[i] << " : " << solvers[i];
#endif
	}
#if (DEBUG)
	cerr << "Solver #" << index << " with score " << max << " was picked: " << solvers[index];
	getchar();
#endif
	return solvers[index];
}

// perform a BFS step in the analysis: take all pcs in the work set and advance one step from them on the selected graph (while clearing the work set).
void IterativeSolver::step(CFG * cfg_ptr, GraphPick which) {
	set<CFGBlockPair> step_blocks = workset_;
	workset_.clear();
	for (set<CFGBlockPair>::const_iterator iter = step_blocks.begin(), end = step_blocks.end(); iter != end ; ++iter) {
		// if cannot advance on the chosen graph, but can on the other graph, return it to the work set
		if ((which == FIRST_GRAPH &&
				iter->first->succ_begin() == iter->first->succ_end() &&
				iter->second->succ_begin() != iter->second->succ_end())
				||
				(which == SECOND_GRAPH &&
						iter->second->succ_begin() == iter->second->succ_end() &&
						iter->first->succ_begin() != iter->first->succ_end() )) {
			workset_.insert(*iter);
		} else {
			advanceOnBlock(*cfg_ptr,*iter,which);
			steps_++;
		}
	}
}

/**
 *  Advance {k1,k2} steps over the {first,second} graph, in all possible interleavings, while partitioning
 *  every p0 steps, and return the results. this does not change the state of the solver.
 */
void IterativeSolver::kSteps(CFG * cfg_ptr,CFG * cfg2_ptr,unsigned int k1, unsigned int k2, vector<IterativeSolver> &results) {
	if ((k1 == 0 && k2 == 0) || workset_.empty()) { // finished doing all steps on both graphs, save the result
		results.push_back(*this);
#if (DEBUG)
		errs() << "k1 = " << k1 << " k2 = " << k2 << " Pushed solver : " << *this << "\n";
#endif
		return;
	}
	IterativeSolver s = *this;
	if (steps_ && p_ && steps_ % p_ == 0) { // partition every p steps overall
		for (set<CFGBlockPair>::const_iterator iter = s.workset_.begin(), end = s.workset_.end(); iter != end; ++iter) {
			s.statespace_[*iter].Partition();
		}
	}
	if (k1 > 0) {
		IterativeSolver s1 = s;
		s1.step(cfg_ptr,FIRST_GRAPH);
		s1.kSteps(cfg_ptr,cfg2_ptr,k1-1,k2,results);
	}
	if (k2 > 0) {
		IterativeSolver s2 = s;
		s2.step(cfg2_ptr,SECOND_GRAPH);
		s2.kSteps(cfg_ptr,cfg2_ptr,k1,k2-1,results);
	}
}

void IterativeSolver::FindBackedges(const CFGBlock* initial, set<const CFGBlock*> visited, set<const CFGBlock*> &result) {
	if (initial->succ_size() == 0)
		return;
	visited.insert(initial);
	const CFGBlock * left = *(initial->succ_begin());
	if (left) {
		if (visited.count(left) == 0) {
			FindBackedges(left,visited,result);
		} else {
			errs() << "found backedge into " << left->getBlockID() << "\n";
			result.insert(left);
		}
	}
	if (initial->succ_size() == 1)
		return;
	const CFGBlock * right = *(initial->succ_begin() + 1);
	if (right && left != right) {
		if (visited.count(right) == 0) {
			FindBackedges(right,visited,result);
		} else {
			errs() << "found backedge into " << right->getBlockID() << "\n";
			result.insert(right);
		}
	}
}

void IterativeSolver::runOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr) {
	CFGBlockPair initial_pcs(*(cfg_ptr->rbegin()),*(cfg2_ptr->rbegin())),
			exit_pcs(*(cfg_ptr->begin()),*(cfg2_ptr->begin()));
	// initial state = { V==V' } (this resides in the transformer after assumeInputEquivalence() has been run)
	State initial_state = transformer_.getVal();
	int balance = 0;

	cfg_ptr->dump(LangOptions());
	cfg2_ptr->dump(LangOptions());

	FindBackedges(initial_pcs.first,set<const CFGBlock*>(),backedge_blocks_.first );
	FindBackedges(initial_pcs.second,set<const CFGBlock*>(),backedge_blocks_.second );

	getchar();

	// worklist = { (entry1,entry2) }, statespace = { (entry1,entry2)->{ V==V' } }
	workset_.insert(initial_pcs);
	statespace_[initial_pcs] = initial_state;
	while (!workset_.empty()) {
		// one mode:
		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_ONE) {
			step(cfg_ptr,FIRST_GRAPH);
			step(cfg2_ptr,SECOND_GRAPH);
			continue;
		}
		// lookahead mode:
		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_LOOKAHEAD) {
			vector<IterativeSolver> results;
			for (int i = 1 ; i <= k_; ++i)
				kSteps(cfg_ptr,cfg2_ptr,i,i,results);
#if(DEBUG1)
			cerr << "Results:\n";
			int i = 0;
			for (vector<IterativeSolver>::const_iterator solvers_iter = results.begin(), solvers_end = results.end(); solvers_iter != solvers_end; ++solvers_iter) {
				IterativeSolver s = *solvers_iter;
				errs() << "Solver #" << ++i << " : " << s << "\n";
			}
#endif
			// pick the best result and proceed from it
			*this = findMinimalDiffSolver(cfg_ptr,cfg2_ptr,results);
			//			getchar();
			continue;
		}

		CFGBlockPair pcs = *(workset_.begin());
		workset_.erase(pcs);

		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_ALL) {
			advanceOnBlock(*cfg_ptr,pcs,FIRST_GRAPH);
			advanceOnBlock(*cfg2_ptr,pcs,SECOND_GRAPH);
#if(DEBUG)
			getchar();
#endif
			continue;
		}
	}
	// print the result at exit point
	outs() << "Result:\n" << *this << '\n';
	State delta_minus,delta_plus;
	outs() << "Delta at (EXIT,EXIT):\n" << statespace_[exit_pcs].ComputeDiff(true,false,false,delta_minus,delta_plus) << '\n';

	for (CFG::const_iterator iter = cfg_ptr->begin(), end = cfg_ptr->end(); iter != end; ++iter) {
		for (CFG::const_iterator iter2 = cfg2_ptr->begin(), end2 = cfg2_ptr->end(); iter2 != end2; ++iter2) {
			CFGBlockPair printf_pcs(*iter,*iter2);
			string s,s2;
			raw_string_ostream ros(s),ros2(s2);
			printf_pcs.first->print(ros,cfg_ptr,LangOptions());
			printf_pcs.second->print(ros2,cfg2_ptr,LangOptions());
			if (ros.str().find("printf") != ros.str().npos && ros2.str().find("printf") != ros2.str().npos) {
				outs() << "State at (" << printf_pcs.first->getBlockID() << "," << printf_pcs.second->getBlockID() << ") (blocks contain printf):\n" << statespace_[printf_pcs] << "\n";
				string delta = statespace_[printf_pcs].ComputeDiff(true,false,false,delta_minus,delta_plus);
				if (delta.size()) {
					outs() << "Delta:" << delta << '\n';
				} else {
					outs() << "Delta is empty.\n";
				}
			}
		}
	}
}

/**
 * Advances on all the edges of one of the blocks (according to @advance_on_first) and updates the state space.
 */
void IterativeSolver::advanceOnBlock(const CFG &cfg, const CFGBlockPair pcs, GraphPick which) {
	if (visits_.count(pcs) == 0) {
		visits_[pcs] = 0;
	}

	/**
	 * TODO: when/if we introduce correlation point, set the state flag accordingly
	 * statespace_[pcs].at_diff_point_ = ?;
	 */

	// if we are working on the 2nd CFG, tell the transformer it needs to treat the variables as tagged
	transformer_.tag_ = (which == SECOND_GRAPH);
	const CFGBlock *advance_block, *stay_block;
	// figure out on which block we are advancing
	if (which == FIRST_GRAPH) {
		advance_block = pcs.first;
		stay_block = pcs.second;
	} else {
		advance_block = pcs.second;
		stay_block = pcs.first;
	}
	assert(advance_block->succ_size() <= 2);
	// find the block successors
	const CFGBlock *first_succ = (advance_block->succ_size() > 0) ? *(advance_block->succ_begin()) : NULL;
	if (first_succ) {
#if(DEBUG)
		errs() << "Advancing on CFG " << which << " block: ";
		advance_block->print(errs(),&cfg,LangOptions());
#endif
		// create the pcs for the target, remember to consider if we are advancing on the first or second pc
		CFGBlockPair new_pcs = (which == FIRST_GRAPH) ? make_pair(first_succ, stay_block) :
				make_pair(stay_block,first_succ);
		predecessors_[new_pcs].insert(pcs);
		advanceOnEdge(pcs,new_pcs,advance_block,advance_block->succ_size() > 1,true);
	}
	const CFGBlock *last_succ = (advance_block->succ_size() > 1) ? *(advance_block->succ_begin() + 1) : NULL;
	// a block can have 2 edges
	if (first_succ != last_succ && last_succ) {// this is a conditional
		// do the false branch
		CFGBlockPair new_pcs = (which == FIRST_GRAPH) ? make_pair(last_succ, stay_block) :
				make_pair(stay_block,last_succ);
		predecessors_[new_pcs].insert(pcs);
		advanceOnEdge(pcs,new_pcs,advance_block,true,false);
	}
#if(DEBUG)
	getchar();
#endif
}

/**
 * Advances over the edge (pcs)->(new_pcs) and joins the result into the state held from new_pcs.
 */
void IterativeSolver::advanceOnEdge(const CFGBlockPair pcs,
		const CFGBlockPair new_pcs,
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
#if(DEBUG)
			s->getStmt()->dump();
			errs() << "\nState after statement: " << transformer_.getVal() << "\n";
#endif
		}
	}
#if(DEBUG)
	errs() << "\nState after block: " << transformer_.getVal() << "\n";
#endif
	if (visits_.count(new_pcs) == 0)
		visits_[new_pcs] = 0;
	prev_statespace_[new_pcs] = statespace_[new_pcs]; // save the previous state of new_pcs
	statespace_[new_pcs] = statespace_[new_pcs].Join(transformer_.getVal());

	// widen if threshold reached and either blocks have back-edges
	if (visits_[new_pcs]++ > transformer_.getVal().widening_threshold) {
		//TODO: if window size too small, widening won't occur as we will never reach the pair of back-edge blocks!
		bool widen = backedge_blocks_.first.count(new_pcs.first) && backedge_blocks_.second.count(new_pcs.second);
		if (widen) {
			errs() << "Widening at ("<< new_pcs.first->getBlockID() << ',' << new_pcs.second->getBlockID() << "), from: " << statespace_[new_pcs];
			State result;
			statespace_[new_pcs].WidenByEquivalence(prev_statespace_[new_pcs],statespace_[new_pcs],result);
			statespace_[new_pcs] = result;
			errs() << " to " << result;
		}
	}

#if(DEBUG)
	errs() << "Transformed from state: " << statespace_[pcs] << "\n";
	errs() << "To state: " << transformer_.getVal() << "\n";
	errs() << "Joined into (result at the destination pcs): " << statespace_[new_pcs] << "\n";
	errs() << "Visit number " << visits_[pcs] << "\n";
#endif

	// see if the resulting state of new_pcs > previous state TODO: or this is the first visit
	if (!(statespace_[new_pcs] <= prev_statespace_[new_pcs]) /*|| first*/) {
		workset_.insert(new_pcs); // if so, add it to the work set
	}
}

ostream& operator<<(ostream& os, const IterativeSolver &solver) {
	os << (string)solver;
	return os;
}

}// end namespace differential
