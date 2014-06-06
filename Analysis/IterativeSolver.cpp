/*
 * IterativeSolver.cpp
 *
 *  Created on: May 10, 2013
 *      Author: user
 */

#include "IterativeSolver.h"

#include <iostream>
#include <limits>
#include <pthread.h>

#define DEBUG 0
#define DEBUG1 0

namespace differential {

ThreadArguments thread_arguments_[MAX_K + 1];

void IterativeSolver::AssumeInputEquivalence(const FunctionDecl * fd,const FunctionDecl * fd2) {
	assert(fd->getNumParams() == fd2->getNumParams());
	// iterate over input parameters and assume equivalence
	for (int i = 0 ; i <  fd->getNumParams() ; ++i) {
		string name = fd->getParamDecl(i)->getNameAsString();
		assert (name == fd2->getParamDecl(i)->getNameAsString());
		const Type * type = fd->getParamDecl(i)->getType().getTypePtr();
		transformer_.AssumeTagEquivalence(transformer_.getVal(),name,type);
	}
	//AssumeInitialEquivalence(fd->getBody(), fd->getASTContext(), false);
	//AssumeInitialEquivalence(fd2->getBody(), fd2->getASTContext(), true);
	transformer_.getNVal() = transformer_.getVal();
	cerr << "Initial state: " << transformer_.getVal();
	// the resulting state will be kept in the transformer until it is copied to <entry1,entry2>
}

void IterativeSolver::AssumeInitialEquivalence(Stmt* node, ASTContext &context, bool tag) {
	if (!node)
		return;
	// declarations
	if ( DeclStmt* decl = dyn_cast<DeclStmt>(node) ) {
		for ( DeclStmt::const_decl_iterator iter = decl->decl_begin(), end = decl->decl_end(); iter != end; ++iter ) {
			if ( VarDecl *decl = cast<VarDecl>(*iter) ) {
				stringstream name;
				name << (tag ? Defines::kTagPrefix : "") << decl->getNameAsString();
				errs() << "Found " << name.str() << '\n';
				transformer_.AssumeTagEquivalence(transformer_.getVal(),name.str(),decl->getType().getTypePtr());
			}
		}
	} else if (CallExpr* call_expr = dyn_cast<CallExpr>(node)) {
		string call;
		raw_string_ostream call_os(call);
		call_os << (tag ? Defines::kTagPrefix : "");
		call_expr->printPretty(call_os,context,0, PrintingPolicy(LangOptions()));
		// assume the value of the function call is the same in both versions (TODO: this may not always be the case)
		string call_str = Utils::ReplaceAll(call_os.str()," ",""); // remove spaces from call string
		errs() << "Found " << call_str<< '\n';
		transformer_.AssumeTagEquivalence(transformer_.getVal(),call_str,call_expr->getCallReturnType().getTypePtr());
	}

	for (Expr::child_iterator iter = node->child_begin(), end = node->child_end(); iter != end; ++iter) {
		AssumeInitialEquivalence(*iter,context,tag);
	}
}

IterativeSolver IterativeSolver::FindMinimalDiffSolver(CFG * cfg_ptr,CFG * cfg2_ptr, vector<IterativeSolver> solvers) {
	const unsigned int size = solvers.size();
	assert(size > 0);
	errs() << "findMinimalDiffSolver: picking from " << size << " solvers...";
	if (size == 1)
		return solvers[0];
	manager &mgr = *(transformer_.getVal().mgr_ptr_);

	// define the score array and initialize to 0
	float score[size];
	memset(score,0,sizeof(float) * size);

	// factor = |CFG x CFG'|
	unsigned int factor = cfg_ptr->getNumBlockIDs() * cfg2_ptr->getNumBlockIDs();

	// since all solvers start from the same origin, we check only the changed locations
//	pthread_t threads[solvers.size()];
	for (int i = 0 ; i < solvers.size(); ++i) {
		IterativeSolver &solver = solvers[i];
		cerr << "\nSolver " << i << ": ";
		//		thread_arguments_[i].is = solver;
		//		pthread_create(threads + i, NULL, &differential::IterativeSolver::ComputeEquivalenceScore, &thread_arguments_[i]);
		int num_scored = 0;
		for (set<CFGBlockPair>::const_iterator iter = solver.changed_.begin(), end = solver.changed_.end(); iter != end; ++iter) {
			const AbstractSet &abstracts = solver.statespace_[*iter].abs_set_;
			if (abstracts.size() == 0)
				continue;
			unsigned int num_non_equiv = 0, num_vars = 0, num_equiv = 0;
			for (AbstractSet::const_iterator abs_iter = abstracts.begin(), abs_end = abstracts.end(); abs_iter != abs_end; ++abs_iter) {
				num_vars += abs_iter->vars.abstract()->get_environment().get_vars().size();
				num_non_equiv += abs_iter->vars.NonEquivVars().size();
			}
			num_equiv = num_vars - num_non_equiv;
			score[i] += ((float)num_equiv / num_vars);
			num_scored++;
			errs() << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << ") = " << ((float)num_equiv / num_vars) << ", ";
		}
		if (num_scored)
			score[i] /= num_scored;
		solver.changed_.clear();
		cerr << "\nOverall normalized score = " << score[i] << "\n";
	}

//	for (int i = 0 ; i < solvers.size(); ++i) { // wait for all threads to finish
//		pthread_join(threads[i],NULL);
//		solvers[i].changed_.clear();
//		score[i] = thread_arguments_[i].score;
//	}

	//	for (int i = 0 ; i < solvers.size(); ++i) {
	//		IterativeSolver &solver = solvers[i];
	//		cerr << "\nSolver " << i << ": ";
	//		for (map<CFGBlockPair,State>::const_iterator iter = solver.statespace_.begin(), end = solver.statespace_.end(); iter != end; ++iter) {
	//			const AbstractSet &abstracts = iter->second.abs_set_;
	//			if (abstracts.size() == 0)
	//				continue;
	//			float num_equiv = 0.0;
	//			for (AbstractSet::const_iterator abs_iter = abstracts.begin(), abs_end = abstracts.end(); abs_iter != abs_end; ++abs_iter) {
	//				if (abs_iter->vars.NonEquivVars().size() == 0)
	//					num_equiv++;
	//			}
	//			score[i] += num_equiv / abstracts.size();
	//			errs() << "(" << iter->first.first->getBlockID() << "," << iter->first.second->getBlockID() << ") = " << num_equiv / abstracts.size() << ", ";
	//		}
	//		cerr << "\nOverall score = " << score[i] << "\n";
	//	}

	//	// equivalence at back edges gets +factor^2
	//	for (set<const CFGBlock *>::const_iterator iter = backedge_blocks_.first.begin(), end = backedge_blocks_.first.end(); iter != end; ++iter) {
	//		for (set<const CFGBlock *>::const_iterator iter2 = backedge_blocks_.second.begin(), end2 = backedge_blocks_.second.end(); iter2 != end2; ++iter2) {
	//			CFGBlockPair pcs(*iter,*iter2);
	//			for (unsigned int i = 0; i < size ; ++i) {
	//				if (solvers[i].statespace_.count(pcs)) {
	//					if (AnalysisUtils::CheckEquivalence(mgr,solvers[i].statespace_[pcs].abs_set_)) {
	//						score[i] += factor * factor;
	//					}
	//				}
	//			}
	//		}
	//	}
	//

	//
	//	// for each of the pcs in work set, find the best result (solver) from the solver list
	//	for (set<CFGBlockPair>::const_iterator pcs_iter = pc_pairs.begin(), pcs_end = pc_pairs.end(); pcs_iter != pcs_end; ++pcs_iter) {
	//		const CFGBlockPair &pcs = *pcs_iter;
	//		bool equivalence = false;
	//
	//		/**
	//		 *  first try and find equivalence. if any of the solvers has equivalence for these pcs,
	//		 *  it gets a +|CFG x CFG'| and others will get a +factor only if they have equivalence as well
	//		 */
	//		for (unsigned int i = 0; i < size ; ++i) {
	//			if (solvers[i].statespace_.count(pcs)) {
	//				if (AnalysisUtils::CheckEquivalence(mgr,solvers[i].statespace_[pcs].abs_set_)) {
	//					// some solver found equivalence for the current pcs
	//					score[i] += factor;
	//					equivalence = true;
	//				}
	//			}
	//		}
	//		if (equivalence) // equivalence was found, no need to check differences
	//			continue;
	//
	//		// this piece of code prefers a solver that didn't visit a pair of locations
	//		// to ones that did visit and had a diff. TODO: this might result in reduced precision
	//		bool empty_diff = false;
	//		for (unsigned int i = 0; i < size ; ++i) {
	//			if (solvers[i].statespace_.count(pcs) == 0 ||  solvers[i].statespace_[pcs].size() == 0) {
	//				score[i]++;
	//				empty_diff = true;
	//			}
	//		}
	//		if (empty_diff) // empty_diff was found, no need to compute differences
	//			continue;
	//
	//		// all solvers have a non-empty diff at this point, find the smallest one
	//		int diff[size];
	//		memset(diff,0,sizeof(unsigned int) * size);
	//		State delta_plus,delta_minus;
	//		int min = std::numeric_limits<int>::max();
	//		for (unsigned int i = 0; i < size ; ++i) {
	//			if (solvers[i].statespace_.count(pcs)) {
	//					diff[i] = solvers[i].statespace_[pcs].ComputeDiff(true,false,false,delta_plus,delta_minus).size();
	//				if (min > diff[i]) {
	//					diff[i] = min;
	//				}
	//			}
	//		}
	//
	//		for (unsigned int i = 0; i < size ; ++i) {
	//			if (diff[i] == min) {
	//				score[i]++;
	//			}
	//		}
	//
	//	}

	// pick the solver with the highest score
	unsigned int index = 0;
	float max = score[index];
	for (unsigned int i = index + 1; i < size ; ++i) {
		if (score[i] > max/* || (score[i] == max && solvers[i].workset_.size() < solvers[index].workset_.size())*/) {
			max = score[i];
			index = i;
		}
#if (DEBUG)
		cerr << "Solver #" << i << " has score " << score[i] << " : " << solvers[i];
#endif
	}
#if (1)
	cerr << "Solver #" << index << " with score " << max << " was picked.\n";
//		getchar();
#endif

	errs() << "done.\n";
	return solvers[index];
}

void IterativeSolver::GetSuccesors(set<CFGBlockPair> &result, CFGBlockPair pcs, const CFGBlock * advance_block) {
	CFGBlockPair succ_pcs;
	const CFGBlock *first_succ = (advance_block->succ_size() > 0) ? *(advance_block->succ_begin()) : NULL;
	const CFGBlock *last_succ = (advance_block->succ_size() > 1) ? *(advance_block->succ_begin() + 1) : NULL;
	if (pcs.first == advance_block) {
		succ_pcs.second = pcs.second;
		if (first_succ) {
			succ_pcs.first = first_succ;
			result.insert(succ_pcs);
		}
		if (last_succ) {
			succ_pcs.first = last_succ;
			result.insert(succ_pcs);
		}
	} else if (pcs.second == advance_block) {
		succ_pcs.first = pcs.first;
		if (first_succ) {
			succ_pcs.second = first_succ;
			result.insert(succ_pcs);
		}
		if (last_succ) {
			succ_pcs.second = last_succ;
			result.insert(succ_pcs);
		}
	} else {
		assert(0 && "given advance_block is not in pcs.");
	}
}

void IterativeSolver::Succesors(set<CFGBlockPair> pairs, GraphPick which, set<CFGBlockPair> &result) {
	for (set<CFGBlockPair>::const_iterator iter = pairs.begin(), end = pairs.end(); iter != end ; ++iter) {
		// figure out on which block we are advancing
		if (which == FIRST_GRAPH) {
			if (iter->first->succ_begin() == iter->first->succ_end() &&
					iter->second->succ_begin() != iter->second->succ_end()) { // can only advance on second graph
				GetSuccesors(result,*iter,iter->second);
			} else {
				GetSuccesors(result,*iter,iter->first);
			}
		} else {
			if (iter->second->succ_begin() == iter->second->succ_end() &&
					iter->first->succ_begin() != iter->first->succ_end()) {  // can only advance on first graph
				GetSuccesors(result,*iter,iter->first);
			} else {
				GetSuccesors(result,*iter,iter->second);
			}
		}
	}
}

// perform a BFS step in the analysis: take all pcs in the work set and advance one step from them on the selected graph (while clearing the work set).
bool IterativeSolver::Step(CFG * cfg_ptr, CFG * other_cfg_ptr, GraphPick which) {
#if(DEBUG)
	errs() << "Taking a step from: {";
	for (set<CFGBlockPair>::iterator iter = workset_.begin(), end = workset_.end(); iter != end; ++iter) {
		errs() << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << "),";
	}
	errs() << "}\n";
#endif
	set<CFGBlockPair> step_blocks = workset_;
	workset_.clear();
	bool can_advance = false;
	for (set<CFGBlockPair>::const_iterator iter = step_blocks.begin(), end = step_blocks.end(); iter != end ; ++iter) {
		// if cannot advance on the chosen graph, but can on the other graph
		if ((which == FIRST_GRAPH && iter->first->succ_empty() && !iter->second->succ_empty()) ||
				(which == SECOND_GRAPH && iter->second->succ_empty() && !iter->first->succ_empty())   ) {
#if(1)
			errs() << "Can't advance over graph " << which + 1 << " from (" << iter->first->getBlockID() << "," <<
					iter->second->getBlockID() << ").\n";
#endif
			// return it to the work set
						workset_.insert(*iter);
//			AdvanceOnBlock(*other_cfg_ptr,*iter,(GraphPick)(SECOND_GRAPH - which));
		} else {
			can_advance = true;
			AdvanceOnBlock(*cfg_ptr,*iter,which);
		}
	}

	return can_advance;

	//	if (steps_++ && p_ && steps_ % p_ == 0)
	//		Partition();

}

#define DEBUGCanPOR 0
bool IterativeSolver::CanPOR(void) {
	// Apply a POR here: if G1->G2-> reaches the same block pairs as G2->G1->, and no partitioning occurs in between, do just one of them
#if(DEBUGCanPOR)
	errs() << "Starting from: {";
	for (set<CFGBlockPair>::iterator iter = workset_.begin(), end = workset_.end(); iter != end; ++iter) {
		errs() << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << "),";
	}
	errs() << "}\n";
#endif
	set<CFGBlockPair> succs1;
	Succesors(workset_, FIRST_GRAPH, succs1);
	set<CFGBlockPair> tmp = succs1;
	succs1.clear();
	Succesors(tmp, SECOND_GRAPH, succs1);
#if(DEBUGCanPOR)
	errs() << "Advancing on First: {";
	for (set<CFGBlockPair>::iterator iter = succs1.begin(), end = succs1.end(); iter != end; ++iter) {
		errs() << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << "),";
	}
	errs() << "}\n";
#endif
	set<CFGBlockPair> succs2;
	Succesors(workset_, SECOND_GRAPH, succs2);
	tmp = succs2;
	succs2.clear();
	Succesors(tmp, FIRST_GRAPH, succs2);
#if(DEBUGCanPOR)
	errs() << "Advancing on Second: {";
	for (set<CFGBlockPair>::iterator iter = succs2.begin(), end = succs2.end(); iter != end; ++iter) {
		errs() << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << "),";
	}
	errs() << "}\n";
	getchar();
#endif
	return (succs1 == succs2);
}

void * IterativeSolver::ComputeEquivalenceScoreParallel(void * arguments) {
	ThreadArguments * ta = (ThreadArguments*)arguments;
	IterativeSolver &solver = ta->is;
	ta->score = 0;
	int num_scored = 0;
	for (set<CFGBlockPair>::const_iterator iter = solver.changed_.begin(), end = solver.changed_.end(); iter != end; ++iter) {
		const AbstractSet &abstracts = solver.statespace_[*iter].abs_set_;
		if (abstracts.size() == 0)
			continue;
		float num_equiv = 0.0;
		for (AbstractSet::const_iterator abs_iter = abstracts.begin(), abs_end = abstracts.end(); abs_iter != abs_end; ++abs_iter) {
			if (abs_iter->vars.NonEquivVars().size() == 0)
				num_equiv++;
		}
		ta->score += num_equiv / abstracts.size();
		num_scored++;
		errs() << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << ") = " << num_equiv / abstracts.size() << ", ";
	}
	ta->score /= num_scored;
	return arguments;
}

// the problem here is that this method invoked parallel access to the abstracts dictionary, which is unsafe
void * IterativeSolver::SpeculateParallel(void * arguments) {
	ThreadArguments * ta = (ThreadArguments*)arguments;
	cerr << "Recieved: " << ta->is << "\n" << ta->cfg_ptrs[0] << "," << ta->cfg_ptrs[1] << "\n" << ta->k[0] << "," << ta->k[1] << "\n";
	vector<IterativeSolver> result;
	ta->is.Speculate(ta->cfg_ptrs[0],ta->cfg_ptrs[1],ta->k[0],ta->k[1]);
	cerr << "Result: " << ta->is;
	return arguments;
}

/**
 *  Advance {k1,k2} steps over the {first,second} graphs.
 */
bool IterativeSolver::Speculate(CFG * cfg_ptr,CFG * cfg2_ptr,unsigned int k1, unsigned int k2) {
	bool can_advance = false;
	while (k1-- > 0)
		if (Step(cfg_ptr, cfg2_ptr, FIRST_GRAPH))
			can_advance = true;
	while (k2-- > 0)
		if (Step(cfg_ptr, cfg2_ptr, SECOND_GRAPH))
			can_advance = true;
	return can_advance;

	//	if ((k1 == 0 && k2 == 0) || workset_.empty()) { // finished doing all steps on both graphs, save the result
	//		results.push_back(*this);
	//#if (DEBUG1)
	//		errs() << "k1 = " << k1 << " k2 = " << k2 << " Pushed solver : " << *this << "\n";
	//#endif
	//		return;
	//	}
	//
	//	/**
	//	 *  Apply a POR here: if G1->G2-> reaches the same block pairs as G2->G1->
	//	 *  and no partitioning occurs in between, do just one of them
	//	 */
	//	if (k1 == 1 && k2 == 1 && CanPOR()) {
	//		Step(cfg_ptr, cfg2_ptr, FIRST_GRAPH);
	//		Step(cfg2_ptr, cfg_ptr, SECOND_GRAPH);
	//		Speculate(cfg2_ptr, cfg_ptr, k1 - 1, k2 - 1, results);
	//		return;
	//	}
	//	if (k1 > 0) {
	//		IterativeSolver s1 = (*this);
	//		s1.Step(cfg_ptr,cfg2_ptr,FIRST_GRAPH);
	//		s1.Speculate(cfg_ptr,cfg2_ptr,k1-1,k2,results);
	//	}
	//	if (k2 > 0) {
	//		IterativeSolver s2 = (*this);
	//		s2.Step(cfg2_ptr,cfg_ptr,SECOND_GRAPH);
	//		s2.Speculate(cfg_ptr,cfg2_ptr,k1,k2-1,results);
	//	}
}

void IterativeSolver::FindBackedges(const CFGBlock* initial, set<const CFGBlock*> visited, set<const CFGBlock*> &result) {
	if (initial->succ_size() == 0)
		return;
	visited.insert(initial);
	const CFGBlock * left = *(initial->succ_begin());
	if (left) {
		if (result.count(left) == 0 && visited.count(left) == 0) {
			FindBackedges(left,visited,result);
		} else {
#if(DEBUG1)
			errs() << "found left backedge into " << left->getBlockID() << "\n";
#endif
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
#if(DEBUG1)
			errs() << "found right backedge into " << right->getBlockID() << "\n";
#endif
			result.insert(right);
		}
	}
}

void IterativeSolver::Partition() {
	{
		cerr << "Partition: { ";
		// partition work set every p steps overall
		//		for (set<CFGBlockPair>::iterator iter = workset_.begin(), end = workset_.end(); iter != end; ++iter) {
		for (map<CFGBlockPair, State>::iterator iter = statespace_.begin(),
				end = statespace_.end(); iter != end; ++iter) {
#if(DEBUG1)
			errs() << "Partitioning state at (" << iter->first.first->getBlockID() << "," << iter->first.second->getBlockID() << ")\n";
#endif
			//			if (backedge_blocks_.first.size() && Backedges(iter->first)) { // partition at back-edges only
			//prev_statespace_[iter->first] = iter->second;
			iter->second.Partition();
			// widen if threshold reached and either blocks have back-edges
			if (visits_[iter->first] > transformer_.getVal().widening_threshold_) {
				//TODO: if window size too small, widening won't occur as we will never reach the pair of back-edge blocks!
				if (Backedges(iter->first)) {
					Widen(iter->first);
				}
			}
			//				new_statespace[iter->first] = iter->second;
			//				new_workset.insert(iter->first);
			//			}
		}
		cerr << "}\n";
		//		if (backedge_blocks_.first.size()) {
		//			prev_statespace_= statespace_;
		//			workset_ = new_workset;
		//			statespace_ = new_statespace;
	}
}

void IterativeSolver::RunOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr) {
	CFGBlockPair initial_pcs(*(cfg_ptr->rbegin()),*(cfg2_ptr->rbegin())),
			exit_pcs(*(cfg_ptr->begin()),*(cfg2_ptr->begin()));
	// initial state = { V==V' } (this resides in the transformer after assumeInputEquivalence() has been run)
	State initial_state = transformer_.getVal();
	int balance = 0;

	initial_state.read_map_.clear();

	errs() << "Done parsing CFGs. Press Enter to continue...";
	getchar();

	cfg_ptr->dump(LangOptions());
	cfg2_ptr->dump(LangOptions());

	errs() << "CFGs dumped. Press Enter to continue...";
	getchar();

	FindBackedges(initial_pcs.first,set<const CFGBlock*>(),backedge_blocks_.first );
	FindBackedges(initial_pcs.second,set<const CFGBlock*>(),backedge_blocks_.second );

	errs() << "CFG 1 back-edges: {";
	for (set<const CFGBlock*>::const_iterator iter = backedge_blocks_.first.begin(), end = backedge_blocks_.first.end(); iter != end; ++iter) {
		errs() << (*iter)->getBlockID() << ",";
	}
	errs() << "}\n";
	errs() << "CFG 2 back-edges: {";
	for (set<const CFGBlock*>::const_iterator iter = backedge_blocks_.second.begin(), end = backedge_blocks_.second.end(); iter != end; ++iter) {
		errs() << (*iter)->getBlockID() << ",";
	}
	errs() << "}\n";
	errs() << "Back edges found. Press Enter to continue...";
	getchar();
	cerr << "Starting!\n";

	// worklist = { (entry1,entry2) }, statespace = { (entry1,entry2)->{ V==V' } }
	workset_.insert(initial_pcs);
	statespace_[initial_pcs] = initial_state;
	while (!workset_.empty()) {
		vector<IterativeSolver> results;
		errs() << "Speculating over k = " << k_ << "...";
		for (int i = 0,j = k_ ; i <= k_; ++i, --j) {
			IterativeSolver is = *this; // we want to speculate from the same point each iteration
			if (is.Speculate(cfg_ptr,cfg2_ptr,j,i))
				results.push_back(is);
		}
#if(DEBUG1)
		cerr << "Results:\n";
		int i = 0;
		for (vector<IterativeSolver>::const_iterator solvers_iter = results.begin(), solvers_end = results.end(); solvers_iter != solvers_end; ++solvers_iter) {
			IterativeSolver s = *solvers_iter;
			errs() << "Solver #" << ++i << " : " << s << "\n";
		}
#endif
		// pick the best result and proceed from it
		*this = FindMinimalDiffSolver(cfg_ptr,cfg2_ptr,results);
		steps_++;
		if (p_ && (steps_ % p_ == 0))
			Partition();
		errs() << "done.\n";
	}
	// print the result at exit point
	outs() << "Result:\n" << *this << '\n';
	State delta_minus,delta_plus;
	string exit_delta = statespace_[exit_pcs].ComputeDiff(true,false,false,delta_minus,delta_plus);
	outs() << "Delta at (EXIT,EXIT):\n" << (exit_delta.size() ? exit_delta : "Empty.") << '\n';

	for (CFG::const_iterator iter = cfg_ptr->begin(), end = cfg_ptr->end(); iter != end; ++iter) {
		for (CFG::const_iterator iter2 = cfg2_ptr->begin(), end2 = cfg2_ptr->end(); iter2 != end2; ++iter2) {
			CFGBlockPair printf_pcs(*iter,*iter2);
			string s,s2;
			raw_string_ostream ros(s),ros2(s2);
			printf_pcs.first->print(ros,cfg_ptr,LangOptions());
			printf_pcs.second->print(ros2,cfg2_ptr,LangOptions());
			if (ros.str().find("printf") != ros.str().npos && ros2.str().find("printf") != ros2.str().npos) {
				outs() << "State at (" << printf_pcs.first->getBlockID() << "," << printf_pcs.second->getBlockID() << ") : " << statespace_[printf_pcs];
				string delta = statespace_[printf_pcs].ComputeDiff(true,false,false,delta_minus,delta_plus);
				outs() << "Delta at (" << printf_pcs.first->getBlockID() << "," << printf_pcs.second->getBlockID() << ") (blocks contain printf): "<< (delta.size() ? delta : "Empty.") << '\n';
			}
		}
	}
}

bool IterativeSolver::Backedges(const CFGBlockPair& pcs) {
	//	if (visits_[pcs] < 2 * transformer_.getVal().widening_threshold_) {
	//		return backedge_blocks_.first.count(pcs.first)
	//				&& backedge_blocks_.second.count(pcs.second);
	//	} else {// adaptive - if we can't break out of the loop after trying for a while
	return backedge_blocks_.first.count(pcs.first)
			|| backedge_blocks_.second.count(pcs.second);
	//	}
}

/**
 * Advances on all the edges of one of the blocks (according to @advance_on_first) and updates the state space.
 */
void IterativeSolver::AdvanceOnBlock(const CFG &cfg, const CFGBlockPair pcs, GraphPick which) {
	if (visits_.count(pcs) == 0) {
		visits_[pcs] = 0;
	}
	/**
	 * TODO: when/if we introduce correlation point, set the state flag accordingly
	 * statespace_[pcs].at_diff_point_ = ?;
	 */

	//	if (Backedges(pcs)) { // partition all states every time we arrive at a pair of back edges
	//		if (steps_ && p_ && steps_ > p_) {
	//			steps_ %= p_;
	//			cerr << "Partition: { ";
	//			for (map<CFGBlockPair,State>::iterator iter = statespace_.begin(), end = statespace_.end(); iter != end; ++iter) {
	//				iter->second.Partition();
	//			}
	//			cerr << "}\n";
	//		}
	//	}

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
#if(DEBUG)
	errs() << "Advancing from (" << pcs.first->getBlockID() << "," << pcs.second->getBlockID() << ") on CFG " << which + 1 << " block (visit number " << visits_[pcs] << ")\n";
#endif
#if(DEBUG)
	advance_block->print(errs(),&cfg,LangOptions());
	errs() << "Transforming from state: " << statespace_[pcs] << "\n";
#endif

	visits_[pcs]++;

	// apply the effect of advancing over a block (by iterating over the block statements)
	transformer_.getVal() = statespace_[pcs]; // start off from the current state
	for ( CFGBlock::const_iterator iter = advance_block->begin(), end = advance_block->end(); iter != end; ++iter ) {
		CFGElement e = *iter;
		if ( const CFGStmt *statement = e.getAs<CFGStmt>()) {
			// apply the statement
#if(DEBUG1)
			statement->getStmt()->dump();
#endif
			transformer_.BlockStmt_Visit(const_cast<Stmt*>(statement->getStmt()));
#if(DEBUG1)
			errs() << "\nState after statement: " << transformer_.getVal() << "\n";
#endif
		}
	}

	// visit terminator
	if (const Stmt * terminator_statement = advance_block->getTerminator().getStmt()) {
		transformer_.getNVal() = transformer_.getVal();
#if(DEBUG1)
		errs() << "Terminator :";
		terminator_statement->dump();
		getchar();
#endif
		/**
		 * only if the terminator is a *statement*, i.e. if, while, etc. will state_ and nstate_ change
		 * and will be considered by AdvanceOnEdge as a true conditional this is because CLang breaks
		 * down short-circuit evals to many blocks, and some seem like conditionals, but are not.
		 */
		switch (terminator_statement->getStmtClass()) {
		case Stmt::WhileStmtClass:
		case Stmt::DoStmtClass:
		case Stmt::SwitchStmtClass:
			assert(0 && "unsupported terminator type (while, do-while or switch).");
			break;
		case Stmt::IfStmtClass:
		case Stmt::ForStmtClass:
		{
			transformer_.BlockStmt_Visit(const_cast<Stmt*>(terminator_statement));
			const CFGBlock *last_succ = (advance_block->succ_size() > 1) ? *(advance_block->succ_begin() + 1) : NULL;
			if (last_succ) {
				CFGBlockPair new_pcs = (which == FIRST_GRAPH) ?
						make_pair(last_succ, stay_block) :
						make_pair(stay_block,last_succ);
				AdvanceOnEdge(new_pcs,true,false);
#if(DEBUG)
				errs() << "State at new pcs: (" << new_pcs.first->getBlockID() << "," << new_pcs.second->getBlockID() << ") :"<< statespace_[new_pcs];
#endif
			}
			break;
		}
		case Stmt::BreakStmtClass:
			break;
		default: { // short-circuit evaluation
			// transfer state directly to the actual terminator and return
			if (BinaryOperator * cond = dyn_cast<BinaryOperator>(const_cast<Stmt*>(terminator_statement))) {
				assert(advance_block->succ_size() > 1);
				const CFGBlock *first_succ = *(advance_block->succ_begin());
				const CFGBlock *last_succ = *(advance_block->succ_begin() + 1);
				if (cond->getOpcode() == BO_LAnd) {
					if (last_succ) {
						CFGBlockPair new_pcs = (which == FIRST_GRAPH) ?
								make_pair(last_succ, stay_block) :
								make_pair(stay_block,last_succ);
						AdvanceOnEdge(new_pcs,true,true);
					}
				} else if (cond->getOpcode() == BO_LOr) {
					if (first_succ) {
						CFGBlockPair new_pcs = (which == FIRST_GRAPH) ?
								make_pair(first_succ, stay_block) :
								make_pair(stay_block,first_succ);
						AdvanceOnEdge(new_pcs,true,true);
					}
				} else {
					terminator_statement->dump();
					assert(0 && "unknown binary operator terminator.");
				}
			} else {
				terminator_statement->dump();
				assert(0 && "unknown terminator type.");
			}
			return;
		}



		}
	}

	const CFGBlock *first_succ = (advance_block->succ_size() > 0) ? *(advance_block->succ_begin()) : NULL;
	if (first_succ) {
		CFGBlockPair new_pcs = (which == FIRST_GRAPH) ?
				make_pair(first_succ, stay_block) :
				make_pair(stay_block,first_succ);
		AdvanceOnEdge(new_pcs,advance_block->succ_size() > 1,true);
#if(DEBUG)
		errs() << "State at new pcs: (" << new_pcs.first->getBlockID() << "," << new_pcs.second->getBlockID() << ") :"<< statespace_[new_pcs];
#endif
	}

#if(DEBUG)
	getchar();
#endif
}

void IterativeSolver::AdvanceOnEdge(const CFGBlockPair &new_pcs, bool conditional, bool true_branch) {
	prev_statespace_[new_pcs] = statespace_[new_pcs]; // save the previous state of new_pcs
	State final_state;
	if (!conditional || true_branch) {
		final_state = transformer_.getVal(); // non-conditional or a true branch
	} else {
		final_state = transformer_.getNVal(); // false branch
	}

#if(DEBUG1)
	errs() << "Advanced on edge, meeting with " << final_state << "\n";
#endif

	statespace_[new_pcs] = statespace_[new_pcs].Join(final_state);
	State state = statespace_[new_pcs], prev_state = prev_statespace_[new_pcs];
	changed_.insert(new_pcs);

	// see if the resulting state of new_pcs > previous state or this is the first visit
	if ((prev_statespace_[new_pcs].size() == 0 &&  statespace_[new_pcs].size() > 0) ||
			!(state <= prev_state)) {
		//		if (Backedges(new_pcs)) {
		//			cerr << state << " <= " << prev_state << " ? " << (state <= prev_state) << endl;
		//			getchar();
		//		}
#if(1)
		//		if (visits_[new_pcs] > transformer_.getVal().widening_threshold_) {
		errs() << "("<< new_pcs.first->getBlockID() << ',' << new_pcs.second->getBlockID() <<
				") added to workset, visit #" << visits_[new_pcs] << ".\n";// << statespace_[new_pcs];
		//			getchar();
		//		}
#endif
		//		cerr << "Added (" << new_pcs.first->getBlockID() << ',' << new_pcs.second->getBlockID() << ") : " << statespace_[new_pcs]  << " to workset.\n";
		//		getchar();
		workset_.insert(new_pcs); // if so, add it to the work set
	}
}

#define DEBUGWiden 0
void IterativeSolver::Widen(const CFGBlockPair pcs) {
	errs() << "Widening at ("<< pcs.first->getBlockID() << ',' << pcs.second->getBlockID() << ").\n";
#if(DEBUGWiden)
	errs() << " from: " << prev_statespace_[pcs] << "," << statespace_[pcs];
#endif
	State result;
	statespace_[pcs].Widening(prev_statespace_[pcs],statespace_[pcs],result);
	prev_statespace_[pcs] = statespace_[pcs];
	statespace_[pcs] = result;
	if (!(statespace_[pcs] <= prev_statespace_[pcs]))
		workset_.insert(pcs);
#if(DEBUGWiden)
	errs() << " to " << result;
	getchar();
#endif
}

ostream& operator<<(ostream& os, const IterativeSolver &solver) {
	os << (string)solver;
	return os;
}

}// end namespace differential
