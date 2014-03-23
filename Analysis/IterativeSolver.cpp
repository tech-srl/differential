/*
 * IterativeSolver.cpp
 *
 *  Created on: May 10, 2013
 *      Author: user
 */

#include "IterativeSolver.h"

#include <iostream>

#define DEBUG 0
#define DEBUG1 0

namespace differential {

void IterativeSolver::AssumeInputEquivalence(const FunctionDecl * fd,const FunctionDecl * fd2) {
	assert(fd->getNumParams() == fd2->getNumParams());
	// iterate over input parameters and assume equivalence
	for (int i = 0 ; i <  fd->getNumParams() ; ++i) {
		string name = fd->getParamDecl(i)->getNameAsString();
		assert (name == fd2->getParamDecl(i)->getNameAsString());
		const Type * type = fd->getParamDecl(i)->getType().getTypePtr();
		if (type->isIntegerType() ) // handle integers
			transformer_.AssumeTagEquivalence(transformer_.getVal(),name);
		if (type->isPointerType() && type->getPointeeType()->isIntegerType()) {// handle integer array
			transformer_.AssumeTagEquivalence(transformer_.getVal(),name);
			// add a special index variable
			var idx(name + Defines::kArrayIndexPostfix);
			transformer_.getVal().env_.add(&idx,1,NULL,0);
		}
	}
	AssumeInitialEquivalence(fd->getBody(), fd->getASTContext(), false);
	AssumeInitialEquivalence(fd2->getBody(), fd2->getASTContext(), true);
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
				transformer_.AssumeTagEquivalence(transformer_.getVal(),name.str());
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
		transformer_.AssumeTagEquivalence(transformer_.getVal(),call_str);
	}

	for (Expr::child_iterator iter = node->child_begin(), end = node->child_end(); iter != end; ++iter) {
		AssumeInitialEquivalence(*iter,context,tag);
	}
}

IterativeSolver IterativeSolver::FindMinimalDiffSolver(CFG * cfg_ptr,CFG * cfg2_ptr, vector<IterativeSolver> solvers) {
	const unsigned int size = solvers.size();
	assert(size > 0);
	if (size == 1)
		return solvers[0];
	errs() << "findMinimalDiffSolver: picking from " << size << " solvers...";
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
#if (DEBUG1)
	cerr << "Solver #" << index << " with score " << max << " was picked: " << solvers[index];
	getchar();
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
void IterativeSolver::Step(CFG * cfg_ptr, CFG * other_cfg_ptr, GraphPick which) {
#if(DEBUG)
	errs() << "Taking a step from: {";
	for (set<CFGBlockPair>::iterator iter = workset_.begin(), end = workset_.end(); iter != end; ++iter) {
		errs() << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << "),";
	}
	errs() << "}\n";
#endif
	set<CFGBlockPair> step_blocks = workset_;
	workset_.clear();
	for (set<CFGBlockPair>::const_iterator iter = step_blocks.begin(), end = step_blocks.end(); iter != end ; ++iter) {
		// if cannot advance on the chosen graph, but can on the other graph
		if ((which == FIRST_GRAPH && iter->first->succ_empty() && !iter->second->succ_empty()) ||
				(which == SECOND_GRAPH && iter->second->succ_empty() && !iter->first->succ_empty())   ) {
#if(DEBUG)
			errs() << "Can't advance over graph " << which + 1 << " from (" << iter->first->getBlockID() << "," <<
					iter->second->getBlockID() << ").\n";
#endif
			// return it to the work set
			workset_.insert(*iter);
			//getchar();
			//AdvanceOnBlock(*other_cfg_ptr,*iter,(GraphPick)(SECOND_GRAPH - which));
		} else {
			AdvanceOnBlock(*cfg_ptr,*iter,which);
		}
	}
	steps_++;

	if (steps_ && p_ && steps_ % p_ == 0) {
		cerr << "Partition: { ";
		// partition work set every p steps overall
		//		for (set<CFGBlockPair>::iterator iter = workset_.begin(), end = workset_.end(); iter != end; ++iter) {
		//			statespace_[*iter].Partition();
		//		}
		// partition state space every p steps overall
		//		map<CFGBlockPair,State> new_statespace;
		//		set<CFGBlockPair> new_workset;
		for (map<CFGBlockPair,State>::iterator iter = statespace_.begin(), end = statespace_.end(); iter != end; ++iter) {
#if(DEBUG)
			errs() << "Partitioning state at (" << iter->first.first->getBlockID() << "," << iter->first.second->getBlockID() << ")\n";
#endif
			//if (Backedges(iter->first)) { // partition at back-edges only
			prev_statespace_[iter->first] = iter->second;
			iter->second.Partition();
			assert(prev_statespace_[iter->first] <= iter->second);
				//				new_statespace[iter->first] = iter->second;
				//				new_workset.insert(iter->first);
			//}
		}
		cerr << "}\n";
		//		prev_statespace_= statespace_;
		//		workset_ = new_workset;
		//		statespace_ = new_statespace;
	}
}

bool IterativeSolver::CanPOR(void) {
	// Apply a POR here: if G1->G2-> reaches the same block pairs as G2->G1->, and no partitioning occurs in between, do just one of them
#if(DEBUG1)
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
#if(DEBUG1)
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
#if(DEBUG1)
	errs() << "Advancing on Second: {";
	for (set<CFGBlockPair>::iterator iter = succs2.begin(), end = succs2.end(); iter != end; ++iter) {
		errs() << "(" << iter->first->getBlockID() << "," << iter->second->getBlockID() << "),";
	}
	errs() << "}\n";
	getchar();
#endif
	return ((p_ && (steps_ + 1) % p_ != 0) && succs1 == succs2);
}

/**
 *  Advance {k1,k2} steps over the {first,second} graph, in all possible interleavings, while partitioning
 *  every p0 steps, and return the results. this does not change the state of the solver.
 */
void IterativeSolver::Speculate(CFG * cfg_ptr,CFG * cfg2_ptr,unsigned int k1, unsigned int k2, vector<IterativeSolver> &results) {
	if ((k1 == 0 && k2 == 0) || workset_.empty()) { // finished doing all steps on both graphs, save the result
		results.push_back(*this);
#if (DEBUG1)
		errs() << "k1 = " << k1 << " k2 = " << k2 << " Pushed solver : " << *this << "\n";
#endif
		return;
	}
	/*
	if (steps_ && p_ && steps_ % p_ == 0) { // partition every p steps overall
		for (map<CFGBlockPair,State>::iterator iter = statespace_.begin(), end = statespace_.end(); iter != end; ++iter) {
			iter->second.Partition();
		}
	}
	 */
	/**
	 *  Apply a POR here: if G1->G2-> reaches the same block pairs as G2->G1->
	 *  and no partitioning occurs in between, do just one of them
	 */
	if (k1 == 1 && k2 == 1 && CanPOR()) {
		Step(cfg_ptr, cfg2_ptr, FIRST_GRAPH);
		Step(cfg2_ptr, cfg_ptr, SECOND_GRAPH);
		Speculate(cfg2_ptr, cfg_ptr, k1 - 1, k2 - 1, results);
		return;
	}
	if (k1 > 0) {
		IterativeSolver s1 = (*this);
		s1.Step(cfg_ptr,cfg2_ptr,FIRST_GRAPH);
		s1.Speculate(cfg_ptr,cfg2_ptr,k1-1,k2,results);
	}
	if (k2 > 0) {
		IterativeSolver s2 = (*this);
		s2.Step(cfg2_ptr,cfg_ptr,SECOND_GRAPH);
		s2.Speculate(cfg_ptr,cfg2_ptr,k1,k2-1,results);
	}
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

void IterativeSolver::RunOnCFGs(CFG * cfg_ptr,CFG * cfg2_ptr) {
	CFGBlockPair initial_pcs(*(cfg_ptr->rbegin()),*(cfg2_ptr->rbegin())),
			exit_pcs(*(cfg_ptr->begin()),*(cfg2_ptr->begin()));
	// initial state = { V==V' } (this resides in the transformer after assumeInputEquivalence() has been run)
	State initial_state = transformer_.getVal();
	int balance = 0;

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
		// one mode:
		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_ONE) {
			Step(cfg_ptr,cfg2_ptr,FIRST_GRAPH);
			Step(cfg2_ptr,cfg_ptr,SECOND_GRAPH);
			continue;
		}
		// lookahead mode:
		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_LOOKAHEAD) {
			vector<IterativeSolver> results;
			errs() << "Speculating over k = " << k_ << "...";
			for (int i = 1 ; i <= k_; ++i)
				Speculate(cfg_ptr,cfg2_ptr,i,i,results);
			errs() << "done.\n";
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
			continue;
		}

		CFGBlockPair pcs = *(workset_.begin());
		workset_.erase(pcs);

		if (interleaving_type_ == AnalysisConfiguration::INTERLEAVING_ALL) {
			AdvanceOnBlock(*cfg_ptr,pcs,FIRST_GRAPH);
			AdvanceOnBlock(*cfg2_ptr,pcs,SECOND_GRAPH);
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

bool IterativeSolver::Backedges(const CFGBlockPair& pcs) {
	return backedge_blocks_.first.count(pcs.first)
			&& backedge_blocks_.second.count(pcs.second);
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
#if(1)
	errs() << "Advancing from (" << pcs.first->getBlockID() << "," << pcs.second->getBlockID() << ") on CFG " << which + 1 << " block (visit number " << visits_[pcs] << ")\n";
#endif
#if(DEBUG)
	advance_block->print(errs(),&cfg,LangOptions());
	errs() << "Transforming from state: " << statespace_[pcs] << "\n";
#endif

	visits_[pcs]++;

	// widen if threshold reached and either blocks have back-edges
	if (visits_[pcs] > transformer_.getVal().widening_threshold_) {
		//TODO: if window size too small, widening won't occur as we will never reach the pair of back-edge blocks!
		if (Backedges(pcs)) {
			Widen(pcs);
		}
	}

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
#endif
		/**
		 * only if the terminator is a *statement*, i.e. if, while, etc. will state_ and nstate_ change
		 * and will be considered by AdvanceOnEdge as a true conditional this is because CLang breaks
		 * down short-circuit evals to many blocks, and some seem like conditionals, but are not.
		 */
		switch (terminator_statement->getStmtClass()) {
		case Stmt::IfStmtClass:
		case Stmt::ForStmtClass:
		case Stmt::WhileStmtClass:
		case Stmt::DoStmtClass:
		case Stmt::SwitchStmtClass:
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
	//state.JoinAll(); prev_state.JoinAll(); //This is unsound for some reason
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

#define DEBUGWidening 0
void IterativeSolver::Widen(const CFGBlockPair pcs) {
	errs() << "Widening at ("<< pcs.first->getBlockID() << ',' << pcs.second->getBlockID() << ").\n";
#if(DEBUGWidening)
	errs() << " from: " << statespace_[pcs];
#endif
	State result;
	statespace_[pcs].Widening(prev_statespace_[pcs],statespace_[pcs],result);
	prev_statespace_[pcs] = statespace_[pcs];
	statespace_[pcs] = result;
#if(DEBUGWidening)
	errs() << " to " << result;
	getchar();
#endif
}

ostream& operator<<(ostream& os, const IterativeSolver &solver) {
	os << (string)solver;
	return os;
}

}// end namespace differential
