#include "APAbstractDomain.h"

#include <sstream>
#include <map>
#include <vector>
#include <set>
using namespace std;

#include <clang/Basic/SourceManager.h>
#include <clang/Analysis/Visitors/CFGRecStmtDeclVisitor.h>
#include <clang/AST/DeclVisitor.h>
#include <clang/Analysis/AnalysisDiagnostic.h>
#include <clang/AST/ASTContext.h>
#include <clang/Analysis/FlowSensitive/DataflowSolver.h>
#include <llvm/ADT/SmallPtrSet.h>
using namespace clang;


#define VERBOSE   1
#define VVERBOSE  0
#define VVVERBOSE 0

// Very Very Verbose requires Verbose
#if (VVVERBOSE)
#	undef VVERBOSE
#	define VVERBOSE  1
#endif

// Very Verbose requires Verbose
#if (VVERBOSE)
#	undef VERBOSE
#	define VERBOSE   1
#endif

#define DEBUGAssign             0
#define DEBUGUpdateEnvironment  0
#define DEBUGresetValues        0
#define DEBUGsetValues          0
#define DEBUGEqual              0
#define DEBUGLowerEqual         0
#define DEBUGJoin               0
#define DEBUGWidening           0
#define DEBUGMeetGuard			0
#define DEBUGForgetUnmatched	0
#define DEBUGPartition			0
#define DEBUGIsTop				0

namespace differential {

manager * APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = 0;

map< var,vector<var> > APAbstractDomain_ValueTypes::ValTy::read_map_;
map< var,vector<var> > APAbstractDomain_ValueTypes::ValTy::update_map_;

AnalysisConfiguration::PartitionPoint APAbstractDomain_ValueTypes::ValTy::partition_point_ = AnalysisConfiguration::PARTITION_AT_CORR_POINT;
AnalysisConfiguration::PartitionStrategy APAbstractDomain_ValueTypes::ValTy::partition_strategy_ = AnalysisConfiguration::JOIN_EQUIV;

AnalysisConfiguration::WideningPoint APAbstractDomain_ValueTypes::ValTy::widening_point_ = AnalysisConfiguration::WIDEN_AT_BACK_EDGE;
AnalysisConfiguration::WideningStrategy APAbstractDomain_ValueTypes::ValTy::widening_strategy_ = AnalysisConfiguration::WIDEN_EQUIV;
unsigned APAbstractDomain_ValueTypes::ValTy::widening_threshold_ = AnalysisConfiguration::kWideningThreshold;

namespace {

class RegisterDecls
		: public CFGRecStmtDeclVisitor<RegisterDecls> {

	APAbstractDomain::AnalysisDataTy& AD;
		public:
	RegisterDecls(APAbstractDomain::AnalysisDataTy& ad) :  AD(ad) {
	}

	void VisitVarDecl(clang::VarDecl* VD) {
		AD.Register(VD);
	}
	CFG& getCFG() {
		return AD.getCFG();
	}
};

} // end anonymous namespace

bool APAbstractDomain_ValueTypes::ValTy::isTop(void) const {
#if (DEBUGIsTop)
	cerr << "IsTop: " << *this << endl;
#endif
	for ( AbstractSet::const_iterator iter = abs_set_.begin(), E = abs_set_.end(); iter != E; ++iter ) {
		if ( iter->vars.abstract()->is_top(*mgr_ptr_) && iter->guards.abstract()->is_top(*mgr_ptr_) ) {
#if (DEBUGIsTop)
			cerr << *iter << " is Top.\n";
#endif
			return true;
		}
	}
	return false;
}

void APAbstractDomain_ValueTypes::ValTy::Assign(const environment& expr_env, const var& variable, texpr1 expr, bool is_guard) {
	stringstream ss;
	ss << variable;
	assert(ss.str().size() > 0);
#if (DEBUGAssign)
	cerr << "Assigning " << expr << " To " << variable << "\n";
#endif
	manager mgr = *mgr_ptr_;
	AbstractSet updated_abs_set;

	if (abs_set_.size() == 0) {
		environment env;
		abstract1 abs(mgr, env, apron::top()), guards(mgr, env, apron::top());
		if (is_guard) {
			env = env.add(&variable,1,0,0);
			env = AnalysisUtils::JoinEnvironments(env,expr.get_environment());
			guards.change_environment(mgr,env);
			guards.assign(mgr,variable,expr);
		} else {
			env = env.add(&variable,1,0,0);
			env = AnalysisUtils::JoinEnvironments(env,expr.get_environment());
			abs.change_environment(mgr,env);
			abs.assign(mgr,variable,expr);
		}
		if (!(abs.is_bottom(mgr) || guards.is_bottom(mgr)))
			updated_abs_set.insert(Abstract2(abs,guards));
	} else {
		for ( AbstractSet::iterator iter = abs_set_.begin(), E = abs_set_.end(); iter != E; ++iter ) {
			abstract1 abs = iter->vars, guards = iter->guards;
			if (is_guard) {
				environment env = guards.get_environment();
				if ( !env.contains(variable) )
					env = env.add(&variable,1,0,0);
				env = AnalysisUtils::JoinEnvironments(env,expr.get_environment());
				guards.change_environment(mgr,env);
				guards.assign(mgr,variable,expr);
			} else {
				environment env = abs.get_environment();
				if ( !env.contains(variable) )
					env = env.add(&variable,1,0,0);
				env = AnalysisUtils::JoinEnvironments(env,expr.get_environment());
				abs.change_environment(mgr,env);
				abs.assign(mgr,variable,expr);
			}
			if (!(abs.is_bottom(mgr) || guards.is_bottom(mgr)))
				updated_abs_set.insert(Abstract2(abs,guards));
		}
	}
	abs_set_ = updated_abs_set;
#if (DEBUGAssign)
	cerr << "Assign. " << *this << endl;
#endif
}

/// forget given var from the state.
void APAbstractDomain_ValueTypes::ValTy::Forget(string name) {
	manager mgr = *mgr_ptr_;
	AbstractSet updated_abs_set;
	for ( AbstractSet::iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		abstract1 abs = iter->vars, guards = iter->guards;
		if (abs.get_environment().contains(name)) {
			abs.forget(mgr,name);
		}
		if (guards.get_environment().contains(name)) {
			guards.forget(mgr,name);
		}
		updated_abs_set.insert(Abstract2(abs,guards));
	}
	abs_set_ = updated_abs_set;
}

#define DEBUGAssume             0
/// Assume set{abs1,abs2} means assume (abs1 v abs2)
void APAbstractDomain_ValueTypes::ValTy::Assume(const set<abstract1>& added_abs_set) {
#if (DEBUGAssume)
	cerr << *this << " Assuming\n";
	cerr << "{";
	for ( set<abstract1>::const_iterator iter = added_abs_set.begin(), end = added_abs_set.end(); iter != end; ++iter )
		cerr << *iter << ",";
	cerr << "}\n";
#endif
	manager mgr = *mgr_ptr_;
	AbstractSet updated_abs_set;

	// No need to account for guards as they are never involved in this operation
	for ( set<abstract1>::const_iterator added_iter = added_abs_set.begin(), added_end = added_abs_set.end(); added_iter != added_end; ++added_iter ) {
		abstract1 abs = *added_iter;
		if (abs_set_.size() == 0) {
			// no need to account for widen_ here since we start off from top
			updated_abs_set.insert(Abstract2(abs,abstract1(mgr, env_, apron::top())));
		} else {
			for ( AbstractSet::iterator iter = abs_set_.begin(), E = abs_set_.end(); iter != E; ++iter ) {
				abstract1 curr_abs = iter->vars;
				environment env = AnalysisUtils::JoinEnvironments(abs.get_environment(),curr_abs.get_environment());
				curr_abs.change_environment(mgr,env);
				abs.change_environment(mgr,env);
				curr_abs *= abs;
				//if (!(curr_abs.is_bottom(mgr) || iter->guards.abstract()->is_bottom(mgr)))
				updated_abs_set.insert(Abstract2((curr_abs),iter->guards));
			}
		}
	}
	abs_set_ = updated_abs_set;

#if (DEBUGAssume)
	cerr << "Assume. " << *this << endl;
#endif
}

bool APAbstractDomain_ValueTypes::ValTy::operator==(const ValTy& rhs) const {
#if (DEBUGEqual)
	cerr << "Comparing " << *this << " To " << rhs;
#endif
	if (size() != rhs.size())
		return false;
	for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		if ( rhs.abs_set_.find(*iter) == rhs.abs_set_.end() ) return false;
	}
	return true;
}

//TODO: Make this better with a lattice
bool APAbstractDomain_ValueTypes::ValTy::operator<=(const ValTy& rhs) const {
#if (DEBUGLowerEqual)
	cerr << *this << " <= " << rhs << " ? ";
#endif
	manager mgr = *mgr_ptr_;
	// forall sub-states S1 in the abstract set
	for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		bool found = false;
		// exists a sub-state S2 in RHS
		for ( AbstractSet::const_iterator rhs_iter = rhs.abs_set_.begin(), rhs_end = rhs.abs_set_.end(); rhs_iter != rhs_end; ++rhs_iter ) {
			// Such that S1 <= S2
			if (iter->guards.abstract() && rhs_iter->guards.abstract() &&
					!rhs_iter->guards.abstract()->is_top(mgr)) { // if RHS is top then LHS <= RHS
				abstract1 guards = (iter->guards), rhs_guards = (rhs_iter->guards);
				if (guards.get_environment() != rhs_guards.get_environment()) { // join environments if needed
					environment env = AnalysisUtils::JoinEnvironments(guards.get_environment(),rhs_guards.get_environment());
					guards.change_environment(mgr,env);
					rhs_guards.change_environment(mgr,env);
				}
				if (!(guards <= rhs_guards))
					continue; // no hope for this pair
			}
			if (iter->vars.abstract() && rhs_iter->vars.abstract()) {
				abstract1 abs = (iter->vars), rhs_abs = (rhs_iter->vars);
				if (abs.get_environment() != rhs_abs.get_environment()) { // join environments if needed
					environment env = AnalysisUtils::JoinEnvironments(abs.get_environment(),rhs_abs.get_environment());
					abs.change_environment(mgr,env);
					rhs_abs.change_environment(mgr,env);
				}
				if (abs <= rhs_abs ) {
					found = true;
					break; // no need to keep searching for a match for S1
				}
			}
		}
		// no such sub-state found for S1, return false;
		if (!found) {
#if (DEBUGLowerEqual)
			cerr << "No.";
#endif
			return false;
		}
	}
#if (DEBUGLowerEqual)
	cerr << "Yes.";
#endif
	// All sub-states accounted for, return true!
	return true;
}

void APAbstractDomain_ValueTypes::ValTy::copyValues(const ValTy& rhs) {
	env_ = rhs.env_;
	abs_set_ = rhs.abs_set_;
}

/// JoinAll joins all abstracts in the set into one abstract i.e. it performs: |_|{abs_1,...,abs_n}
void APAbstractDomain_ValueTypes::ValTy::JoinAll() {
	abs_set_.clear();
	abs_set_.insert(AnalysisUtils::JoinAbstracts(*mgr_ptr_,abs_set_));
}

// returns a mapping: {guards} ->  [abstracts]
map<Abstract1,AbstractSet> APAbstractDomain_ValueTypes::ValTy::PartitionByGuards() const {
	map<Abstract1,AbstractSet> result;
	for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		Abstract2 abs2 = *iter;
		//Abstract1 guards = (abs2.guards);
		//guards.change_environment(*mgr_ptr_,env_);
		// map the abstract to it's guards
		//result[guards_str].insert(abs_ref);
		result[abs2.guards].insert(abs2);
#if (DEBUGPartition)
		cerr << "Inserting " << abs2.guards << " -> " << (abs2.vars) << " Size = " << result[abs2.guards].size()  << endl;
#endif
	}
#if (DEBUGPartition)
	cerr << "Partition: \n";
	for (map<Abstract1,AbstractSet>::iterator iter = result.begin(), end = result.end(); iter != end; ++iter) {
		AbstractSet abs_set = iter->second;
		cerr << iter->first << " -> ";
		for ( AbstractSet::const_iterator iter2 = abs_set.begin(), end2 = abs_set.end(); iter2 != end2; ++iter2 )
			cerr << (iter2->vars);
		cerr << endl;
	}
#endif
	return result;
}

/**
 *  implement the READ deduction rule:
 *  start by calculating read(A,idx_l1), read(B,idx_l2) equivalence
 *  if A = B and idx_l1 = idx_l2 then read(A,idx_l1) = read(B,idx_l2)
 */
void APAbstractDomain_ValueTypes::ValTy::ApplyArrayReadDeductionRule()  {
	if (!read_map_.size())
		return;
	manager mgr = *mgr_ptr_;
	AbstractSet deduced_set;
	for ( AbstractSet::iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		abstract1 abs = iter->vars;
		const environment& env = abs.get_environment();
		for (map< var, vector<var> >::const_iterator read_iter = read_map_.begin(), end = read_map_.end(); read_iter != end; ++read_iter) {
			map< var, vector<var> >::const_iterator read2_iter = read_iter;
			while (++read2_iter != end) {
				// for every (different) pair of reads
				const vector<var> &read = read_iter->second, &read2 = read2_iter->second;
				if (AnalysisUtils::IsEquivalent(abs, read[0], read2[0]) && 		// A == B
					AnalysisUtils::IsEquivalent(abs, read[1], read2[1])) {	// idx_l1 == idx_l2
					tcons1 constraint = (texpr1(env, read_iter->first) == texpr1(env, read2_iter->first));
					abs = abs.meet(mgr, tcons1_array(1, &constraint));
				}
			}
		}
		deduced_set.insert(Abstract2(abs,iter->guards));
	}
	abs_set_ = deduced_set;
}

/**
 *  implement the UPDATE deduction rule:
 *  foreach update(A,idx_l1), update(B,idx_l2),
 *  if A = B, idx_l1 = idx_l2 and update(A,idx_l1) = update(B,idx_l2) then both updates can be forgotten
 *  if the state has an unmatched update(), it means no equivalence
 */
void APAbstractDomain_ValueTypes::ValTy::ApplyArrayUpdateDeductionRule()  {
	if (!update_map_.size())
		return;
	manager mgr = *mgr_ptr_;
	AbstractSet deduced_set;
	for ( AbstractSet::iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		abstract1 abs = iter->vars;
		vector<var> equiv_updates;
		for (map< var, vector<var> >::const_iterator updates_iter = update_map_.begin(), end = update_map_.end(); updates_iter != end; ++updates_iter) {
			map< var, vector<var> >::const_iterator updates2_iter = updates_iter;
			while (++updates2_iter != end) {
				// for every (different) pair of updates
				const vector<var> &update = updates_iter->second, &update2 = updates2_iter->second;
				if (AnalysisUtils::IsEquivalent(abs, updates_iter->first, updates2_iter->first) && // update(A,idx_l1) == update(B,idx_l2),
					AnalysisUtils::IsEquivalent(abs, update[0], update2[0]) && 	// A == B
					AnalysisUtils::IsEquivalent(abs, update[1], update2[1])) {	// idx_l1 == idx_l2
					equiv_updates.push_back(updates_iter->first);
					equiv_updates.push_back(updates2_iter->first);
				}
			}
		}
		environment env = abs.get_environment().remove(equiv_updates);
		abs = abs.forget(mgr,equiv_updates);
		abs = abs.change_environment(mgr,env);
		deduced_set.insert(Abstract2(abs,iter->guards));
	}
	abs_set_ = deduced_set;
}

map<set<var>,AbstractSet> APAbstractDomain_ValueTypes::ValTy::PartitionByEquivalence() const {
	manager mgr = *mgr_ptr_;
	map<set<var>,AbstractSet> result;

	for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		abstract1 vars_abs = (iter->vars), guards_abs = (iter->guards);
		environment env = vars_abs.get_environment();
		vector<var> vars = env.get_vars();
		set<var> equivalent_vars;
		stringstream abs_ss;
		abs_ss << vars_abs;
		string abs_str = abs_ss.str();

		// find the set of equivalent vars for the current abstract that agree on guards
		for (size_t i = 0; i < vars.size(); ++i ) {
			string name = vars[i],name_tag;

			if (AnalysisUtils::IsArrayInstrumentationVar(vars[i]))
				continue;

			Utils::Names(name,name_tag);
			var v(name),v_tag(name_tag);

			// quick hack to save on domain operations
			stringstream equiv_ss;
			equiv_ss << name_tag << " - 1" << name << " = 0";
			if (abs_str.find(equiv_ss.str()) != abs_str.npos) {
				equivalent_vars.insert(v);
				continue;
			}

			if ( !env.contains(v) )
				env = env.add(&v,1,0,0);
			if ( !env.contains(v_tag) )
				env = env.add(&v_tag,1,0,0);
			vars_abs.change_environment(mgr,env);

			if (AnalysisUtils::IsEquivalent(vars_abs,v,v_tag)) { // equivalence found for var v, add it to the set of equivalent vars
				equivalent_vars.insert(v);
			}
		}

		env = guards_abs.get_environment();
		vars = env.get_vars();
		// find the set of equivalent vars for the current abstract that agree on guards
		for (size_t i = 0; i < vars.size(); ++i ) {
			string name = vars[i],name_tag;
			Utils::Names(name,name_tag);
			var v(name),v_tag(name_tag);

			if ( !env.contains(v) )
				env = env.add(&v,1,0,0);
			if ( !env.contains(v_tag) )
				env = env.add(&v_tag,1,0,0);

			guards_abs.change_environment(mgr,env);

			tcons1 v_equal(texpr1(env,v) == texpr1(env,v_tag));

			if (AnalysisUtils::IsEquivalent(guards_abs,v,v_tag)) { // equivalence found for var v, add it to the set of equivalent vars
				equivalent_vars.insert(v);
			}
		}

		// put the abstract in the set of other abstract that hold equivalence for the same set of vars
		result[equivalent_vars].insert(*iter);
	}

#if (DEBUGPartition)
	cerr << "Partition is: \n";
	for (map<set<var>,AbstractSet>::iterator iter = result.begin(), end = result.end(); iter != end; ++iter) {
		AbstractSet abs_set = iter->second;
		cerr << "{ ";
		for (set<var>::iterator iter2 = iter->first.begin(); iter2!=iter->first.end(); ++iter2)
			cerr << *iter2 << ", ";
		cerr << "} -> ";
		for ( AbstractSet::const_iterator iter2 = abs_set.begin(), end2 = abs_set.end(); iter2 != end2; ++iter2 )
			cerr << (iter2->vars);
		cerr << endl;
	}
#endif

	return result;
}

map<set<var>,Abstract2> APAbstractDomain_ValueTypes::ValTy::JoinByPartition(map<set<var>,AbstractSet> partition) {
	map<set<var>,Abstract2> result;
	for (map<set<var>,AbstractSet>::const_iterator iter = partition.begin(), end = partition.end(); iter != end; ++iter ) {
		// for each set of abstracts (that hold equivalence for the same vars) join them all into one abstract and put it in the result
		result[iter->first] = AnalysisUtils::JoinAbstracts(*mgr_ptr_,iter->second);
	}
	return result;
}

map<Abstract1,Abstract1> APAbstractDomain_ValueTypes::ValTy::JoinByPartition(map<Abstract1,AbstractSet> partition) {
	map<Abstract1,Abstract1> result;
	manager mgr = *mgr_ptr_;
#if (DEBUGPartition)
	cerr << "JoinByPartition: \n";
#endif
	for (map<Abstract1,AbstractSet>::const_iterator iter = partition.begin(), end = partition.end(); iter != end; ++iter ) {
		// for each set of abstracts (that have the same guards abstract) join them all into one abstract and put it in the result
		Abstract1 guards = iter->first;
		Abstract2 joined = AnalysisUtils::JoinAbstracts(mgr,iter->second);
		result[guards] = joined.vars;
#if (DEBUGPartition)
		cerr << guards << " -> " << result[guards] << endl;
#endif
	}
	return result;
}


AbstractSet APAbstractDomain_ValueTypes::ValTy::PartitionToAbsSet(map<set<var>,Abstract2> partition) {
	AbstractSet result;
	for (map<set<var>,Abstract2>::const_iterator partition_iter = partition.begin(), partition_end = partition.end(); partition_iter != partition_end; ++partition_iter ) {
		// join the partitioned (joined) abstracts into a regular abstract set
		result.insert(partition_iter->second);
	}
	return result;
}

AbstractSet APAbstractDomain_ValueTypes::ValTy::PartitionToAbsSet(map<Abstract1,Abstract1> partition) {
	AbstractSet result;
	for (map<Abstract1,Abstract1>::const_iterator partition_iter = partition.begin(), partition_end = partition.end(); partition_iter != partition_end; ++partition_iter ) {
		// place the abstracts into a regular abstract set
		result.insert(Abstract2(partition_iter->second,partition_iter->first));
	}
	return result;
}

bool APAbstractDomain_ValueTypes::ValTy::Partition() {
#if (DEBUGPartition)
	cerr << "\n---------------------\nPartition: " << *this;
#endif
	bool result = false;
	cerr << abs_set_.size() << "->";
	if (abs_set_.size() > 1) {
		result = true;
		if ( partition_strategy_ == AnalysisConfiguration::JOIN_ALL ) {
			JoinAll();
		} else if ( partition_strategy_ == AnalysisConfiguration::JOIN_EQUIV ) {
			ApplyArrayReadDeductionRule();
			ApplyArrayUpdateDeductionRule();
			// for each, find the set of variables which are equivalent and partition
			abs_set_ = PartitionToAbsSet(JoinByPartition(PartitionByEquivalence()));
		} else if ( partition_strategy_ == AnalysisConfiguration::JOIN_GUARDS ) {
			abs_set_ = PartitionToAbsSet(JoinByPartition(PartitionByGuards()));
		} else {
			result = false;
		}
	}
	cerr << abs_set_.size() << " ";
#if (DEBUGPartition)
	cerr << "\nResult: " << *this << "\n---------------------\n";
	getchar();
#endif
	return result;
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::operator|=(ValTy& rhs) {
	return Join(rhs);
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::Join(ValTy& rhs) {
#if (DEBUGJoin)
	static unsigned join_counter = 0;
	cerr << "joining: " << *this << "\nand: "<< rhs;
	size_t prev_size = abs_set_.size();
#endif

	for ( AbstractSet::const_iterator iter = rhs.abs_set_.begin(), end = rhs.abs_set_.end(); iter != end; ++iter ) {
		// Remove bottoms
		if (iter->vars.abstract()->is_bottom(*mgr_ptr_) || iter->guards.abstract()->is_bottom(*mgr_ptr_))
			continue;
		abs_set_.insert(*iter);
	}

#if (DEBUGJoin)
	cerr << "\njoin result: " << *this << endl;
	if (join_counter++ % 10 == 0) {
		cerr << join_counter << ":" << prev_size << "->" << abs_set_.size() << endl;
	}
#endif
	return *this;
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::operator&=(const ValTy& rhs) {
	return Meet(rhs);
}


APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::operator&=(const abstract1& abs) {
	return Meet(abs);
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::operator&=(const tcons1& cons) {
	return Meet(cons);
}

#define DEBUGMeet 1
APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::Meet(const ValTy& rhs) {
#if (DEBUGMeet)
	cerr << "Meeting: " << *this << "And: "<< rhs;
#endif
	manager mgr = *mgr_ptr_;

	AbstractSet met_abs_set;
	if (abs_set_.size() == 0) {
		met_abs_set = rhs.abs_set_;
	} else {
		for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
			for ( AbstractSet::const_iterator rhs_iter = rhs.abs_set_.begin(), rhs_end = rhs.abs_set_.end(); rhs_iter != rhs_end; ++rhs_iter ) {
				abstract1 rhs_abs = (rhs_iter->vars), meet_abs = (iter->vars);
				abstract1 rhs_guards = (rhs_iter->guards), meet_guards = (iter->guards);
				// abstarcts
				cerr << "Meeting environments " << meet_abs.get_environment() << " and " << rhs_abs.get_environment();
				environment env = AnalysisUtils::JoinEnvironments(meet_abs.get_environment(),rhs_abs.get_environment());
				cerr << "Result " << env;
				meet_abs.change_environment(mgr,env);
				rhs_abs.change_environment(mgr,env);
				meet_abs.meet(mgr,rhs_abs);
				// guards
				env = AnalysisUtils::JoinEnvironments(meet_guards.get_environment(),rhs_guards.get_environment());
				meet_guards.change_environment(mgr,env);
				rhs_guards.change_environment(mgr,env);
				meet_guards.meet(mgr,rhs_guards);
				if (!(meet_abs.is_bottom(mgr) || meet_guards.is_bottom(mgr)))
					met_abs_set.insert(Abstract2((meet_abs),(meet_guards)));
			}
		}
	}
	abs_set_ = met_abs_set;
#if (DEBUGMeet)
	cerr << "Meet.\n" << *this << endl;
#endif
	return *this;
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::Meet(const abstract1& abs) {
	ValTy rhs;
	rhs.abs_set_.insert(Abstract2((abs),(abstract1(*mgr_ptr_,abs.get_environment(),apron::top()))));
	//rhs.abs_set_.insert(Abstract2((abs),(abs)));
	return Meet(rhs);
}
APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::Meet(const tcons1& cons) {
	return Meet(AnalysisUtils::AbsFromConstraint(*mgr_ptr_,cons));
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::MeetGuard(const tcons1& guard_cons) {
	manager mgr = *mgr_ptr_;
	abstract1 guard_abs = AnalysisUtils::AbsFromConstraint(mgr,guard_cons);
#if (DEBUGMeetGuard)
	cerr << "MeetGuard: " << *this << "And: "<< guard_abs;
#endif
	AbstractSet met_abs_set;
	if (abs_set_.size() == 0) {
		met_abs_set.insert(Abstract2((abstract1(*mgr_ptr_,guard_abs.get_environment(),apron::top())),(guard_abs)));
	} else {
		for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
			abstract1 meet_guards = (iter->guards);
			environment env = AnalysisUtils::JoinEnvironments(meet_guards.get_environment(),guard_abs.get_environment());
			meet_guards.change_environment(mgr,env);
			guard_abs.change_environment(mgr,env);
			meet_guards.meet(mgr,guard_abs);
			if (!(iter->vars.abstract()->is_bottom(mgr) || meet_guards.is_bottom(mgr)))
				met_abs_set.insert(Abstract2(iter->vars,(meet_guards)));
		}
	}
	abs_set_ = met_abs_set;
#if (DEBUGMeetGuard)
	cerr << "MeetGuard.\n" << *this << endl;
#endif
	return *this;
}

void APAbstractDomain_ValueTypes::ValTy::SetTop(){
	abs_set_.clear();
	Abstract1 abs1(abstract1(*mgr_ptr_,env_,apron::top()));
	abs_set_.insert(Abstract2(abs1,abs1));
}
void APAbstractDomain_ValueTypes::ValTy::SetBottom(){
	abs_set_.clear();
}

void APAbstractDomain_ValueTypes::ValTy::WidenByGuards(const ValTy& pre, const ValTy& post, ValTy& result) {
#if (DEBUGWidening)
	cerr << "<-----\nWidening: " << pre << "\nAnd: "<< post << "\n";
#endif
	map<Abstract1, Abstract1> pre_partition = JoinByPartition(pre.PartitionByGuards());//PartitionByGuards2();
	map<Abstract1, Abstract1> post_partition = JoinByPartition(post.PartitionByGuards());//post.PartitionByGuards2();


	result.abs_set_.clear();
	manager mgr = *mgr_ptr_;
	for (map<Abstract1, Abstract1>::const_iterator iter = pre_partition.begin(), end = pre_partition.end(); iter != end; ++iter ) {
		Abstract1 guards = iter->first;
#if (DEBUGWidening)
		//cerr << "Trying to match: " << guards << "...\n";
#endif
		abstract1 widened_abs = iter->second;
		// try and find an abstract of the same equivalence class
		if (post_partition.count(guards)) {
			// if found, widen it with the matching abstract from rhs
			abstract1 post_abs = post_partition[guards];
			environment env = AnalysisUtils::JoinEnvironments(widened_abs.get_environment(),post_abs.get_environment());
			widened_abs.change_environment(mgr,env);
			post_abs.change_environment(mgr,env);

#if (DEBUGWidening)
			//cerr << "Matched: " << widened_abs << " And: "<< post_abs << " Result: ";
#endif
			apron::widening(mgr, widened_abs, widened_abs, post_abs);
#if (DEBUGWidening)
			//cerr << widened_abs << endl;
#endif
			post_partition.erase(guards);
		} // otherwise simply add it to the result
		result.abs_set_.insert(Abstract2(Abstract1(widened_abs),guards));
	}
	// take care of the unmateched abstracts that remain in post
	for (map<Abstract1,Abstract1>::const_iterator iter = post_partition.begin(), end = post_partition.end(); iter != end; ++iter )
		// remember that the partition is guards->abs so iter->first should be second in the pair and vice versa
		result.abs_set_.insert(Abstract2(iter->second,iter->first));

#if (DEBUGWidening)
	cerr << "Result: " << result << "\n----->\n";
	getchar();
#endif
}

void APAbstractDomain_ValueTypes::ValTy::WidenByEquivalence(const ValTy& pre, const ValTy& post, ValTy& result) {
#if (DEBUGWidening)
	cerr << "<-----\nWidening: " << pre << " And: "<< post << "\n";
#endif
	map<set<var>,Abstract2> pre_partition = JoinByPartition(pre.PartitionByEquivalence());
	map<set<var>,Abstract2> post_partition = post.JoinByPartition(post.PartitionByEquivalence());

	result.abs_set_.clear();
	manager mgr = *mgr_ptr_;
	for (map<set<var>,Abstract2>::const_iterator iter = pre_partition.begin(), end = pre_partition.end(); iter != end; ++iter ) {
		const set<var> &key = iter->first;
		abstract1 widened_abs = ((iter->second).vars), widened_guards = ((iter->second).guards);
		// try and find an abstract of the same equivalence class
		if (post_partition.count(key)) {
			// if found, widen it with the matching abstract from rhs
			abstract1 post_abs = ((post_partition[key]).vars), post_guards = ((post_partition[key]).guards);
			environment env = AnalysisUtils::JoinEnvironments(widened_abs.get_environment(),post_abs.get_environment());
			widened_abs.change_environment(mgr,env);
			post_abs.change_environment(mgr,env);

			env = AnalysisUtils::JoinEnvironments(widened_guards.get_environment(),post_guards.get_environment());
			widened_guards.change_environment(mgr,env);
			post_guards.change_environment(mgr,env);
#if (DEBUGWidening)
			cerr << "Matched: " << Abstract2(widened_guards,widened_abs) << " And: "<< Abstract2(post_guards,post_abs) << " Result: ";
#endif
			apron::widening(mgr, widened_abs, widened_abs, post_abs);
			apron::widening(mgr, widened_guards, widened_guards, post_guards);
#if (DEBUGWidening)
			cerr << Abstract2(widened_guards,widened_abs) << '\n';
#endif
			post_partition.erase(key);
		} // otherwise simply add it to the result
		result.abs_set_.insert(Abstract2((widened_abs),(widened_guards)));
	}
	// take care of the unmatched abstracts that remain in post
	for (map<set<var>, Abstract2>::const_iterator iter = post_partition.begin(), end = post_partition.end(); iter != end; ++iter )
		result.abs_set_.insert(iter->second);

#if (DEBUGWidening)
	cerr << "Result: " << result << "\n----->\n";
	getchar();
#endif
}

void APAbstractDomain_ValueTypes::ValTy::WidenAll(const ValTy& pre, const ValTy& post, ValTy& result) {
	manager mgr = *mgr_ptr_;

	Abstract2 joined_pre_abs = AnalysisUtils::JoinAbstracts(mgr, pre.abs_set_);
	Abstract2 joined_post_abs = AnalysisUtils::JoinAbstracts(mgr, post.abs_set_);

#if (DEBUGWidening)
	cerr << "Widening: " << joined_pre_abs << " And: " << joined_post_abs << "\n";
#endif
	environment env = AnalysisUtils::JoinEnvironments(joined_pre_abs.vars.abstract()->get_environment(),
			joined_post_abs.vars.abstract()->get_environment());
	abstract1 widened_abs(*mgr_ptr_,env,apron::bottom());
	apron::widening(mgr, widened_abs, joined_pre_abs.vars, joined_post_abs.vars);

	env = AnalysisUtils::JoinEnvironments(joined_pre_abs.guards.abstract()->get_environment(),
			joined_post_abs.guards.abstract()->get_environment());
	abstract1 widened_guards(*mgr_ptr_,env,apron::bottom());
	apron::widening(mgr, widened_guards, joined_pre_abs.guards, joined_post_abs.guards);

	result.abs_set_.clear();
	result.abs_set_.insert(Abstract2(widened_abs,widened_guards));

#if (DEBUGWidening)
	cerr << "\nResult:\n" << result << endl;
#endif
}

void APAbstractDomain_ValueTypes::ValTy::Widening(const ValTy& pre, const ValTy& post, ValTy& result) {
	if (widening_strategy_ == AnalysisConfiguration::WIDEN_ALL)
		WidenAll(pre,post,result);
	if (widening_strategy_ == AnalysisConfiguration::WIDEN_EQUIV)
		WidenByEquivalence(pre,post,result);
	if (widening_strategy_ == AnalysisConfiguration::WIDEN_GUARDS)
		WidenByGuards(pre,post,result);
}

bool APAbstractDomain_ValueTypes::ValTy::sizesEqual(const ValTy& RHS) const {
	return ParentRef(*this).sizesEqual(ParentRef(RHS));
}

void APAbstractDomain_ValueTypes::ValTy::RemoveUnmatchedVars() {
	// start off by minimizing the state by removing unmatched variables
	AbstractSet initial_abs_set = abs_set_;
	abs_set_.clear();
	for (AbstractSet::iterator abs_iter = initial_abs_set.begin(), abs_end =
			initial_abs_set.end(); abs_iter != abs_end; ++abs_iter) {
		// forget unmatched variables (old\new)
		abs_set_.insert(
				Abstract2((AnalysisUtils::ForgetUnmatched(abs_iter->vars)),
						AnalysisUtils::ForgetUnmatched(abs_iter->guards)));
	}
}

void APAbstractDomain_ValueTypes::ValTy::CollectEnvironment(environment& env,
		environment& guards_env) {
	// collect the environment
	for (AbstractSet::iterator abs_iter = abs_set_.begin(), abs_end =
			abs_set_.end(); abs_iter != abs_end; ++abs_iter) {
		abstract1 vars_i = (abs_iter->vars), guards_i = (abs_iter->guards);
		vector<var> vars = vars_i.get_environment().get_vars();
		for (unsigned i = 0; i < vars.size(); ++i)
			if (!env.contains(vars[i]))
				env = env.add(&vars[i], 1, 0, 0);
		vars = guards_i.get_environment().get_vars();
		for (unsigned i = 0; i < vars.size(); ++i)
			if (!guards_env.contains(vars[i]))
				guards_env = guards_env.add(&vars[i], 1, 0, 0);
	}
}

string APAbstractDomain_ValueTypes::ValTy::PrintBrokenEquivStates(manager& mgr) {
	stringstream result;
	for (AbstractSet::iterator abs_iter = abs_set_.begin(), abs_end = abs_set_.end(); abs_iter != abs_end; ++abs_iter) {
		abstract1 vars_abs = (abs_iter->vars), guards_abs =
				AnalysisUtils::ForgetUnmatched((abs_iter->guards));
		if (vars_abs.is_bottom(mgr) || guards_abs.is_bottom(mgr))
			continue;

		// if applying (V==V') changed nothing, the abstract holds equivalence
		environment joined_env = AnalysisUtils::JoinEnvironments(
				vars_abs.get_environment(), guards_abs.get_environment());
		vars_abs.change_environment(mgr, joined_env);
		guards_abs.change_environment(mgr, joined_env);
		vars_abs.meet(mgr, guards_abs);
		vector<var> vars = joined_env.get_vars();
		stringstream broken;
		for (unsigned i = 0; i < vars.size(); ++i) {
			string name = vars[i], name_tag;
			if (AnalysisUtils::IsArrayInstrumentationVar(vars[i]))
				continue;
			Utils::Names(name, name_tag);
			if (!AnalysisUtils::IsEquivalent(vars_abs, name, name_tag)) {
				broken << (vars[i] == name_tag ? name + "'" : name) << ", ";
			}
		}
		if (broken.str().size()) {
			result << "<-------------------\n" << "Sub-state with diff for variables: "
					<< broken.str() << " :\n" << (*abs_iter).vars
					<< "\n------------------->\n";
		}
	}
	return result.str();
}

// Negated_Tau_i = ~(Delta_i /\ (V == V'))
vector<set<abstract1> > APAbstractDomain_ValueTypes::ValTy::ComputeNegatedTau(unsigned index, manager& mgr, bool guards) {
	// Negated_Tau_i = ~(Delta_i /\ (V == V'))
	vector<set<abstract1> > negated_tau;
	for (AbstractSet::iterator abs_iter = abs_set_.begin(), abs_end = abs_set_.end(); abs_iter != abs_end; ++abs_iter) {
		if (abs_iter->vars.abstract()->is_bottom(mgr) || (guards && abs_iter->guards.abstract()->is_bottom(mgr)))
			continue;

		abstract1 tau_i = AnalysisUtils::MeetEquivalence(mgr,abs_iter->vars);

		if (!guards) {
			negated_tau.push_back(AnalysisUtils::NegateAbstract(mgr, tau_i));
		} else {
			abstract1 tau_guards_i = AnalysisUtils::MeetEquivalence(mgr,abs_iter->guards);

			// make them have the same environment, so we can put them in a set together
			environment joined_env = AnalysisUtils::JoinEnvironments(tau_i.get_environment(), tau_guards_i.get_environment());
			tau_i.change_environment(mgr, joined_env);
			tau_guards_i.change_environment(mgr, joined_env);

			set<abstract1> negation = AnalysisUtils::NegateAbstract(mgr, tau_i);
			set<abstract1> guards_negation = AnalysisUtils::NegateAbstract(mgr,tau_guards_i);
			for (set<abstract1>::const_iterator iter = guards_negation.begin(),	end = guards_negation.end(); iter != end; ++iter) {
				negation.insert(*iter);
			}
			negated_tau.push_back(negation);
		}
	}

	return negated_tau;
}

string APAbstractDomain_ValueTypes::ValTy::ComputeDiff(bool report_on_diff, bool compute_diff, bool guards, ValTy &delta_plus,  ValTy &delta_minus) {
	unsigned index = 0;
	manager mgr = *mgr_ptr_;
	environment env, guards_env;// = state.env;
	string report_string;
	raw_string_ostream report_os(report_string);

	// start off by minimizing the state by removing unmatched variables
	//RemoveUnmatchedVars();

	// collect the environment
	CollectEnvironment(env, guards_env);

	/**
	 * In case we only know T, a difference might exists and we could not precisely represent it,
	 * therefore we must report a potential diff in order to stay sound
	 */
	if ( isTop() ) {
		return "New / Lost State: top\n";
	}

	ApplyArrayReadDeductionRule();
	ApplyArrayUpdateDeductionRule();

	// if we check for difference on state level alone, no need for negation etc.
	if (!compute_diff) {
		return PrintBrokenEquivStates(mgr);
	}

	// Negated_Tau_i = ~(Delta_i /\ (V == V'))
	vector<set<abstract1> > negated_tau = ComputeNegatedTau(index,mgr,guards);

	// Cross-conjunct all Neg_Tau's
	set<abstract1> phi = AnalysisUtils::CrossConjunctAbstracts(mgr, negated_tau);

	// before negation we took out all the (V==V') constraints as they will repeat in every negation
	// i.e. we are replacing the computation: ~tau1 /\ ... /\ ~tauN = (p1 \/ V!=V') /\ ... /\ (pN \/ V!=V')
	// with : (p1 /\ ... /\ pn) \/ (V!=V')	therefore we now need to add ( V!=V' ) to phi
	vector<var> vars = env.get_vars();
	for (size_t i = 0 ; i < vars.size(); ++i ) {
		string v = vars[i], v_tag;
		Utils::Names(v,v_tag);
		pair<tcons1,tcons1> diff_cons = AnalysisUtils::GetDiffCons(env,v,v_tag);
		assert(phi.size());
		phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.first).change_environment(mgr,phi.begin()->get_environment()));
		phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.second).change_environment(mgr,phi.begin()->get_environment()));
	}
	if (guards) {
		vars = guards_env.get_vars();
		for (size_t i = 0 ; i < vars.size(); ++i ) {
			string v = vars[i], v_tag;
			Utils::Names(v,v_tag);
			pair<tcons1,tcons1> diff_cons = AnalysisUtils::GetDiffCons(env,v,v_tag);
			assert(phi.size());
			phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.first).change_environment(mgr,phi.begin()->get_environment()));
			phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.second).change_environment(mgr,phi.begin()->get_environment()));
		}
	}

	delta_plus = delta_minus = *this;
	vector<abstract1> result_plus, result_minus;

	// Cross-meet with all states in Delta
	for ( AbstractSet::iterator abs_iter = abs_set_.begin(), abs_end = abs_set_.end(); abs_iter != abs_end; ++abs_iter ) {
		index = 0;
		abstract1 vars_i = (abs_iter->vars), guards_i = AnalysisUtils::ForgetUnmatched((abs_iter->guards));
		for ( set<abstract1>::iterator phi_iter = phi.begin(), phi_end = phi.end(); phi_iter != phi_end; ++phi_iter ) {
			abstract1 meet_vars_result = vars_i, meet_guards_result = guards_i, phi_i = *phi_iter;
			// vars
			environment env = AnalysisUtils::JoinEnvironments(meet_vars_result.get_environment(),phi_i.get_environment());
			meet_vars_result.change_environment(mgr,env);
			phi_i.change_environment(mgr,env);
			meet_vars_result.meet(mgr,phi_i);
			if (guards) {
				// guards
				env = AnalysisUtils::JoinEnvironments(meet_guards_result.get_environment(),phi_i.get_environment());
				meet_guards_result.change_environment(mgr,env);
				phi_i.change_environment(mgr,env);
				meet_guards_result.meet(mgr,phi_i);
			}
#if (VVERBOSE)
			cout << "<-----\nMeeting Phi_" << ++index << ":\n" << phi_i << "\nWith:\n" << vars_i << "<->" << guards_i
					<< "\nResult:\n" << meet_vars_result << " <-> " << meet_guards_result << "\n";
#endif
			if ( !meet_vars_result.is_bottom(mgr) && !meet_guards_result.is_bottom(mgr) ) {
				// TODO: forget equivalent variable iff there are no non-equivalent depenant on them
				//meet_result = ForgetEquivalent(meet_result);
				if (guards) {
					meet_vars_result.meet(mgr,meet_guards_result);
					//meet_result = ForgetGuards(meet_result);
				}
				abstract1 meet_plus = meet_vars_result, meet_minus = meet_vars_result;
				meet_plus = AnalysisUtils::ForgetUntagged(meet_plus);
				meet_minus = AnalysisUtils::ForgetTagged(meet_minus);
#if (VVERBOSE)
				cout << "\nResult-: " << meet_minus << "\nResult+: " << meet_plus;
				getchar();
#endif
				result_minus.push_back(meet_minus);
				result_plus.push_back(meet_plus);
			}
#if (VVERBOSE)
			cout << "----->\n";
#endif
		}
	}

	set<abstract1> minimized_result_plus = AnalysisUtils::MinimizeResult(mgr,result_plus);
	for (set<abstract1>::iterator iter = minimized_result_plus.begin(), end = minimized_result_plus.end(); iter != end; ++iter) {
		abstract1 diff_clean = *iter;
		diff_clean = AnalysisUtils::ForgetGuards(diff_clean);
		stringstream ss;
		ss << diff_clean;
		string diff_str = ss.str();
#if (VVERBOSE)
		cout << "Result = " << diff_str << endl;
#endif
		diff_str = Utils::ReplaceAll(diff_str,Defines::kTagPrefix,"");
		report_os << "New State: " << diff_str << '\n';
#if (VVERBOSE)
		cout << "New State: " << diff_str << '\n';
		cout << "(Original: " << *iter << ")\n";
#endif
		delta_plus.abs_set_.insert(Abstract2(Abstract1(diff_clean),Abstract1()));
	}

	set<abstract1> minimized_result_minus = AnalysisUtils::MinimizeResult(mgr,result_minus);
	for (set<abstract1>::iterator iter = minimized_result_minus.begin(), end = minimized_result_minus.end(); iter != end; ++iter) {
		abstract1 diff_clean = *iter;
		diff_clean = AnalysisUtils::ForgetGuards(diff_clean);
		stringstream ss;
		ss << diff_clean;
		string diff_str = ss.str();
#if (VVERBOSE)
		cout << "Result = " << diff_str << endl;
#endif
		diff_str = Utils::ReplaceAll(diff_str,Defines::kTagPrefix,"");
		report_os << "Lost State: " << diff_str << '\n';
#if (VVERBOSE)
		cout << "Lost State: " << diff_str << '\n';
		cout << "(Original: " << *iter << ")\n";
#endif
	}

	return report_os.str();
}

// Print fixed-point range information when the analysis is done
void APChecker::ObserveFixedPoint(bool report_on_diff, bool compute_diff, unsigned &report_ctr) {
	cout << "Generating results...\n" << compute_diff;

	// We want the results in stdout, not stderr:
	diagnostics_engine_.setClient(new TextDiagnosticPrinter(llvm::outs(), DiagnosticOptions()));
	diagnostics_engine_.getClient()->BeginSourceFile(LangOptions(), preprocessor_ptr_);

	// First order the reports according to line and column
	map<unsigned,FullSourceLoc> ordered_locations;
	map<unsigned,unsigned> ordered_diag_ids;

#if (VERBOSE)
	report_on_diff = false; // Report all
#endif

	for ( map<SourceLocation,APAbstractDomain::ValTy>::iterator iter  = corr_points_states_.begin(), end = corr_points_states_.end(); iter != end; ++iter ) {
		unsigned index = 0;
		APAbstractDomain::ValTy state = iter->second;
		SourceLocation location = iter->first;
		string report_string;
		raw_string_ostream report_os(report_string);

		// partition one last time if strategy was at-corr-point
		if (state.partition_point_ == AnalysisConfiguration::PARTITION_AT_CORR_POINT)
			state.Partition();

#if (VERBOSE)
		report_os << "For Correlation Point: ";
		location.print(report_os,contex_.getSourceManager());
		report_os << "\nState = ";
		state.print(report_os);
		report_os << "\n";
		llvm::outs() << report_os.str();
#endif

		APAbstractDomain_ValueTypes::ValTy delta_plus,delta_minus;
		string diff_string = state.ComputeDiff(report_on_diff,compute_diff,true,delta_plus,delta_minus);
		report_os << diff_string;

		// Create the report according to flags
		if ( !report_on_diff || !diff_string.empty() ) {
			FullSourceLoc Loc = contex_.getFullLoc(location);
			bool Invalid;
			unsigned index = Loc.getExpansionLineNumber(&Invalid) * 1000 + Loc.getExpansionColumnNumber(&Invalid);
			ordered_locations[index] = Loc;
			ordered_diag_ids[index] = diagnostics_engine_.getCustomDiagID(DiagnosticsEngine::Warning,report_os.str());
			rewriter_.InsertText(location.getLocWithOffset(-1), string("/*\n") + report_os.str() + string("*/\n"));
		}
		if (!diff_string.empty()) {
			report_ctr++;
		}
	}

	map<unsigned,FullSourceLoc>::const_iterator ordered_locations_iter = ordered_locations.begin(), ordered_locations_end = ordered_locations.end();
	map<unsigned,unsigned>::const_iterator ordered_diag_ids_iter = ordered_diag_ids.begin();
	if ( ordered_locations_iter != ordered_locations_end ) {
#if (VERBOSE)
		cout << "Verbose flag is ON.\n";
#endif
		while ( ordered_locations_iter != ordered_locations_end ) {
			cout << "------------------------------------------------------------\n";
			diagnostics_engine_.Report(ordered_locations_iter->second,ordered_diag_ids_iter->second);
			++ordered_locations_iter;
			++ordered_diag_ids_iter;
			//getchar();
		}
		//cerr << "Diff Found!\n";
		cout << "Analysis of function complete.\n" <<
				"------------------------------------------------------------------\n";
		//getchar();
		SourceManager &source_manager = contex_.getSourceManager();
		string filename = Defines::kResultsFilenamePrefix + source_manager.getFileEntryForID(source_manager.getMainFileID())->getName();
		Utils::WriteFiles(rewriter_,filename);
	}

}

void APAbstractDomain::InitializeValues(const CFG& cfg) {
	RegisterDecls R(getAnalysisData());
	cfg.VisitBlockStmts(R);
}

ostream& operator<<(ostream& os, const APAbstractDomain_ValueTypes::ValTy & V) {
	os << (string)V;
	return os;
}

}
