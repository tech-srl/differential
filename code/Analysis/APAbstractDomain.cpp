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
#define DEBUGAssume             0
#define DEBUGresetValues        0
#define DEBUGsetValues          0
#define DEBUGEqual              0
#define DEBUGLowerEqual         0
#define DEBUGJoin               0
#define DEBUGMeet               0
#define DEBUGWidening           0
#define DEBUGMeetGuard			0
#define DEBUGForgetUnmatched	0
#define DEBUGPartition			0
#define DEBUGIsTop				0

namespace differential {

APAbstractDomain_ValueTypes::ValTy::PartitionPoint APAbstractDomain_ValueTypes::ValTy::partition_point = APAbstractDomain_ValueTypes::ValTy::PARTITION_AT_JOIN;
APAbstractDomain_ValueTypes::ValTy::PartitionStrategy APAbstractDomain_ValueTypes::ValTy::partition_strategy = APAbstractDomain_ValueTypes::ValTy::JOIN_EQUIV;
unsigned APAbstractDomain_ValueTypes::ValTy::partition_threshold = 1;
APAbstractDomain_ValueTypes::ValTy::WideningPoint APAbstractDomain_ValueTypes::ValTy::widening_point = APAbstractDomain_ValueTypes::ValTy::WIDEN_AT_BACK_EDGE;
APAbstractDomain_ValueTypes::ValTy::WideningStrategy APAbstractDomain_ValueTypes::ValTy::widening_strategy = APAbstractDomain_ValueTypes::ValTy::WIDEN_GUARDS;
unsigned APAbstractDomain_ValueTypes::ValTy::widening_threshold = 10;
manager * APAbstractDomain_ValueTypes::ValTy::mgr_ptr_ = 0;

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
		if ( iter->vars.abstract().is_top(*mgr_ptr_) && iter->guards.abstract().is_top(*mgr_ptr_) ) {
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
		abs.change_environment(mgr,env_);
		guards.change_environment(mgr,env_);
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


/// Assume set{abs1,abs2} means assume (abs1 v abs2)
void APAbstractDomain_ValueTypes::ValTy::Assume(const set<abstract1>& added_abs_set) {
#if (DEBUGAssume)
	cerr << "Assuming\n";
	cerr << "{";
	for ( set<abstract1>::const_iterator iter = added_abs_set.begin(), end = added_abs_set.end(); iter != end; ++iter )
		cerr << *iter << ",";
	cerr << "}\n";
#endif
	manager mgr = *mgr_ptr_;
	AbstractSet updated_abs_set;

	// No need to account for guards as they are never involed in this operation
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
				if (!(curr_abs.is_bottom(mgr) || iter->guards.abstract().is_bottom(mgr)))
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
	cerr << *this << " <= " << rhs << " ? (No)";
#endif
	manager mgr = *mgr_ptr_;
	// forall sub-states S1 in the abstract set
	for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		bool found = false;
		// exists a sub-state S2 in RHS
		for ( AbstractSet::const_iterator rhs_iter = rhs.abs_set_.begin(), rhs_end = rhs.abs_set_.end(); rhs_iter != rhs_end; ++rhs_iter ) {
			// Such that S1 <= S2
			abstract1 guards = (iter->guards), rhs_guards = (rhs_iter->guards);
			if (guards.get_environment() != rhs_guards.get_environment()) { // join environments if needed
				environment env = AnalysisUtils::JoinEnvironments(guards.get_environment(),rhs_guards.get_environment());
				guards.change_environment(mgr,env);
				rhs_guards.change_environment(mgr,env);
			}
			if (!(guards <= rhs_guards))
				continue; // no hope for this pair
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
		// no such sub-state found for S1, return false;
		if (!found)
			return false;
	}
#if (DEBUGLowerEqual)
	cerr << "Yes!";
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
		cerr << "Inserting " << guards << " -> " << (abs2.vars) << " Size = " << result[guards].size()  << endl;
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

map<set<var>,AbstractSet> APAbstractDomain_ValueTypes::ValTy::PartitionByEquivalence() const {
	manager mgr = *mgr_ptr_;
	map<set<var>,AbstractSet> result;
	for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
		abstract1 v_abs = (iter->vars), g_abs = (iter->guards);
		environment env = v_abs.get_environment();
		vector<var> vars = env.get_vars();
		set<var> equivalent_vars;
		// find the set of equivalent vars for the current abstract that agree on guards
		for (size_t i = 0; i < vars.size(); ++i ) {
			string name = vars[i],name_tag;
			Utils::Names(name,name_tag);
			var v(name),v_tag(name_tag);

			if ( !env.contains(v) )
				env = env.add(&v,1,0,0);
			if ( !env.contains(v_tag) )
				env = env.add(&v_tag,1,0,0);

			v_abs.change_environment(mgr,env);

			tcons1 v_equal(texpr1(env,v) == texpr1(env,v_tag));

			if (AnalysisUtils::IsEquivalent(v_abs,v,v_tag)) { // equivalence found for var v, add it to the set of equivalent vars
				equivalent_vars.insert(v);
			}
		}

		env = g_abs.get_environment();
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

			g_abs.change_environment(mgr,env);

			tcons1 v_equal(texpr1(env,v) == texpr1(env,v_tag));

			if (AnalysisUtils::IsEquivalent(g_abs,v,v_tag)) { // equivalence found for var v, add it to the set of equivalent vars
				equivalent_vars.insert(v);
			}
		}

		// put the abstract in the set of other abstract that hold equivalence for the same set of vars
		result[equivalent_vars].insert(*iter);
	}

#if (DEBUGPartition)
	cerr << "Partition: \n";
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

void APAbstractDomain_ValueTypes::ValTy::Partition() {
#if (DEBUGPartition)
	cerr << "\n---------------------\nCanonicalize: " << *this;
#endif
	cerr << abs_set_.size() << " -> ";
	if (abs_set_.size() > 1) {
		if ( partition_strategy == JOIN_ALL ) {
			JoinAll();
		} else if ( partition_strategy == JOIN_EQUIV ) {
			// for each, find the set of variables which are equivalent and partition
			abs_set_ = PartitionToAbsSet(JoinByPartition(PartitionByEquivalence()));
		} else if ( partition_strategy == JOIN_GUARDS ) {
			abs_set_ = PartitionToAbsSet(JoinByPartition(PartitionByGuards()));
		}
	}
	cerr << abs_set_.size() << "\n";

#if (DEBUGPartition)
	cerr << "\nResult: " << *this << "\n---------------------\n";
	getchar();
#endif
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
		if (iter->vars.abstract().is_bottom(*mgr_ptr_) || iter->guards.abstract().is_bottom(*mgr_ptr_))
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
				environment env = AnalysisUtils::JoinEnvironments(meet_abs.get_environment(),rhs_abs.get_environment());
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
			if (!(iter->vars.abstract().is_bottom(mgr) || meet_guards.is_bottom(mgr)))
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

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::WidenByGuards(const ValTy& post, ValTy& dest) {
#if (DEBUGWidening)
	cerr << "<-----\nWidening: " << *this << "\nAnd: "<< post << "\n";
#endif
	map<Abstract1, Abstract1> pre_partition = JoinByPartition(PartitionByGuards());//PartitionByGuards2();
	map<Abstract1, Abstract1> post_partition = JoinByPartition(post.PartitionByGuards());//post.PartitionByGuards2();


	dest.abs_set_.clear();
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
		dest.abs_set_.insert(Abstract2(Abstract1(widened_abs),guards));
	}
	// take care of the unmateched abstracts that remain in post
	for (map<Abstract1,Abstract1>::const_iterator iter = post_partition.begin(), end = post_partition.end(); iter != end; ++iter )
		// remember that the partition is guards->abs so iter->first should be second in the pair and vice versa
		dest.abs_set_.insert(Abstract2(iter->second,iter->first));

#if (DEBUGWidening)
	cerr << "Result: " << dest << "\n----->\n";
	getchar();
#endif
	return *this;
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::WidenByEquivlance(const ValTy& post, ValTy& dest) {
#if (DEBUGWidening)
	cerr << "<-----\nWidening: " << *this << " And: "<< post << "\n";
#endif
	map<set<var>,Abstract2> pre_partition = JoinByPartition(PartitionByEquivalence());
	map<set<var>,Abstract2> post_partition = post.JoinByPartition(post.PartitionByEquivalence());

	dest.abs_set_.clear();
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
			cerr << "Matched: " << widened_abs << "<->" << widened_guards << " And: "<< post_abs << " Result: ";
#endif
			apron::widening(mgr, widened_abs, widened_abs, post_abs);
			apron::widening(mgr, widened_guards, widened_guards, post_guards);
#if (DEBUGWidening)
			cerr << widened_abs << "<->" << widened_guards << endl;
#endif
			post_partition.erase(key);
		} // otherwise simply add it to the result
		dest.abs_set_.insert(Abstract2((widened_abs),(widened_guards)));
	}
	// take care of the unmateched abstracts that remain in post
	for (map<set<var>, Abstract2>::const_iterator iter = post_partition.begin(), end = post_partition.end(); iter != end; ++iter )
		dest.abs_set_.insert(iter->second);

#if (DEBUGWidening)
	cerr << "Result: " << dest << "\n----->\n";
#endif
	return *this;
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::WidenAll(const ValTy& post, ValTy& dest) {
	manager mgr = *mgr_ptr_;

	Abstract2 joined_pre_abs = AnalysisUtils::JoinAbstracts(mgr, abs_set_);
	Abstract2 joined_post_abs = AnalysisUtils::JoinAbstracts(mgr, post.abs_set_);

#if (DEBUGWidening)
	cerr << "Widening: " << (joined_pre_abs.vars) << "<->" << (joined_pre_abs.guards) << " And: "
			<< (joined_post_abs.vars) << "<->" << (joined_post_abs.guards)  << "\n";
#endif
	abstract1 widened_abs(*mgr_ptr_,env_,apron::bottom());
	apron::widening(mgr, widened_abs, (joined_pre_abs.vars), (joined_post_abs.vars));

	abstract1 widened_guards(*mgr_ptr_,env_,apron::bottom());
	apron::widening(mgr, widened_guards, (joined_pre_abs.guards), (joined_post_abs.guards));

	dest.abs_set_.clear();
	dest.abs_set_.insert(Abstract2((widened_abs),(widened_guards)));

#if (DEBUGWidening)
	cerr << "\nResult:\n" << dest << endl;
#endif
	return *this;
}

APAbstractDomain_ValueTypes::ValTy& APAbstractDomain_ValueTypes::ValTy::Widening(const ValTy& post, ValTy& dest) {
	if ( post == *this ) {
		dest = *this;
		return *this;
	}
	if (widening_strategy == WIDEN_ALL)
		return WidenAll(post,dest);
	if (widening_strategy == WIDEN_EQUIV)
		return WidenByEquivlance(post,dest);
	if (widening_strategy == WIDEN_GUARDS)
		return WidenByGuards(post,dest);
}

bool APAbstractDomain_ValueTypes::ValTy::sizesEqual(const ValTy& RHS) const {
	return ParentRef(*this).sizesEqual(ParentRef(RHS));
}

string APAbstractDomain_ValueTypes::ValTy::ComputeDiff(bool report_on_diff, bool compute_diff) {
	unsigned index = 0;
	bool diff_found = false;
	manager mgr = *mgr_ptr_;
	environment env, guards_env;// = state.env;
	string report_string;
	raw_string_ostream report_os(report_string);

	// start off by minimizing the state by removing unconstrained and unmatched variables (according to the flags)
	AbstractSet initial_abs_set = abs_set_;
	abs_set_.clear();
	for ( AbstractSet::iterator abs_iter = initial_abs_set.begin(), abs_end = initial_abs_set.end(); abs_iter != abs_end; ++abs_iter ) {
		abstract1 vars_i = (abs_iter->vars), guards_i = (abs_iter->guards);
		/* forget unconstrainted variables.
		vars_i = ForgetUnconstrained(vars_i);
		guards_i = ForgetUnconstrained(guards_i);
		*/
		// forget unmatched variables (old\new)
		vars_i = AnalysisUtils::ForgetUnmatched(vars_i);
		guards_i = AnalysisUtils::ForgetUnmatched(guards_i);

		abs_set_.insert(Abstract2((vars_i),(guards_i)));

		// collect the environment
		vector<var> vars = vars_i.get_environment().get_vars();
		for ( unsigned i = 0 ; i < vars.size() ; ++i )
			if ( !env.contains(vars[i]) )
				env = env.add(&vars[i],1,0,0);

		vars = guards_i.get_environment().get_vars();
		for ( unsigned i = 0 ; i < vars.size() ; ++i )
			if ( !guards_env.contains(vars[i]) )
				guards_env = guards_env.add(&vars[i],1,0,0);
	}
	// In case we only know T, a difference might exists and we could not precisly represent it,
	// therefore we must report a potential diff in order to stay sound
	if ( isTop() ) {
		report_os << "New / Lost State: top\n";
		diff_found = true;
	} else {
		vector< set<abstract1> > negated_tau;
		for ( AbstractSet::iterator abs_iter = abs_set_.begin(), abs_end = abs_set_.end(); abs_iter != abs_end; ++abs_iter ) {
			index++;
			abstract1 vars_i = (abs_iter->vars), guards_i = AnalysisUtils::ForgetUnmatched((abs_iter->guards));
#if (VVERBOSE)
			cout << "Staring off with Delta" << index << " = " << vars_i << "<->" << guards_i << endl;
#endif
			if (vars_i.is_bottom(mgr) || guards_i.is_bottom(mgr) )
			  continue;


			// if we check for difference on state level alone, no need for negation etc.
			if (!compute_diff) {
				// if applying (V==V') changed nothing, the abstract holds equivalence
				abstract1 abs = vars_i, abs2 = guards_i;
				environment joined_env = AnalysisUtils::JoinEnvironments(vars_i.get_environment(),guards_i.get_environment());
				abs.change_environment(mgr,joined_env);
				abs2.change_environment(mgr,joined_env);
				abs.meet(mgr,abs2);
				vector<var> vars = joined_env.get_vars();
				stringstream broken;
				for ( unsigned i = 0 ; i < vars.size() ; ++i ) {
					string name = vars[i],name_tag;
					if (name.find(Defines::kTagPrefix) == 0) // no need to check twice
						continue;
					Utils::Names(name,name_tag);
					tcons1 v_equal = AnalysisUtils::GetEquivCons(joined_env,name);
					if (!abs.sat(mgr,v_equal)) {
						broken << name << ", ";
						diff_found = true;
					}
				}
				if (broken.str().size()) {
					report_os << "<-------------------\n" <<
					 "Sub-state with diff (" << broken.str() << "):\n" << (*abs_iter).vars <<
					 "\n------------------->\n";
				}
				continue;
			}

			//vars_i.change_environment(mgr,env);
			abstract1 tau_i = vars_i;
			environment tau_i_env = tau_i.get_environment();
			vector<var> vars = tau_i_env.get_vars();
			for ( unsigned i = 0 ; i < vars.size() ; ++i ) {
				string name = vars[i],name_tag;
				Utils::Names(name,name_tag);
				// (V == V')
				tcons1 v_equal = AnalysisUtils::GetEquivCons(tau_i_env,name);
				tau_i.change_environment(mgr,AnalysisUtils::JoinEnvironments(tau_i_env,v_equal.get_environment()));
				// Tau_i = (Delta_i /\ (V == V'))
				tau_i.meet(mgr,tcons1_array(1,&v_equal));
			}

			//abstract1 tau_i = AnalysisUtils::MeetEquivalence(mgr,vars_i);

			//delta_guards_i.change_environment(mgr,guards_env);
			abstract1 tau_guards_i = guards_i, ntau_guards_i = guards_i;
			environment tau_guards_env = tau_guards_i.get_environment();
			vars = tau_guards_env.get_vars();
			for ( unsigned i = 0 ; i < vars.size() ; ++i ) {
				string name = vars[i],name_tag;
				Utils::Names(name,name_tag);
				// (Guard == Guard')
				tcons1 v_equal = AnalysisUtils::GetEquivCons(tau_guards_env,name);
				tau_guards_i.change_environment(mgr,AnalysisUtils::JoinEnvironments(tau_guards_env,v_equal.get_environment()));
				// Tau_Guards_i = (Delta_Guards_i /\ (Guard == Guard'))
				tau_guards_i.meet(mgr,tcons1_array(1,&v_equal));
				/*
				pair<tcons1,tcons1> v_diff = AnalysisUtils::GetDiffCons(tau_guards_env,name);
				ntau_guards_i.change_environment(mgr,AnalysisUtils::JoinEnvironments(tau_guards_env,v_diff.first.get_environment()));
				ntau_guards_i.meet(mgr,tcons1_array(1,&(v_diff.first)));
				ntau_guards_i.meet(mgr,tcons1_array(1,&(v_diff.second)));
				*/
			}

#if (VVERBOSE)
			cout << "Computing Tau" << index << " = (Delta" << index << " /\\ (V == V')) = " << tau_i << "<->" << tau_guards_i << endl;
#endif

			// Computing ~Tau_i by negating all the constraints (both for regular and for guards)
			environment joined_env = AnalysisUtils::JoinEnvironments(tau_i.get_environment(), tau_guards_i.get_environment());
			// make them have the same environment, so we can put them in a set together
			tau_i.change_environment(mgr,joined_env);
			tau_guards_i.change_environment(mgr,joined_env);
			// meet to get one joint abstract, this will simplify calculating the result
			//tau_i.meet(mgr,tau_guards_i);

			set<abstract1> negation = AnalysisUtils::NegateAbstract(mgr, tau_i);
			set<abstract1> guards_negation = AnalysisUtils::NegateAbstract(mgr, tau_guards_i);
			for (set<abstract1>::const_iterator iter = guards_negation.begin(), end = guards_negation.end(); iter != end; ++iter)
				negation.insert(*iter);
			negated_tau.push_back(negation);
		}

		// if we check for difference on state level alone, no need for negation etc.
		if (compute_diff) {

			// Cross-conjunct all Neg_Tau's
			set<abstract1> phi = AnalysisUtils::CrossConjunctAbstracts(mgr, negated_tau);

			// before negation we took out all the (V==V') constraints as they will repeat in every negation
			// i.e. we are replacing the computation: ~tau1 /\ ... /\ ~taun = (p1 \/ V!=V') /\ ... /\ (pn \/ V!=V')
			// with : (p1 /\ ... /\ pn) \/ (V!=V')	therefore we now need to add ( V!=V' ) to phi
			vector<var> vars = env.get_vars();
			//vars.insert(vars.end(), guards_env.get_vars().begin(), guards_env.get_vars().end());
			for (size_t i = 0 ; i < vars.size(); ++i ) {
				pair<tcons1,tcons1> diff_cons = AnalysisUtils::GetDiffCons(env,vars[i]);
				assert(phi.size());
				phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.first).change_environment(mgr,phi.begin()->get_environment()));
				phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.second).change_environment(mgr,phi.begin()->get_environment()));
			}
			vars = guards_env.get_vars();
			for (size_t i = 0 ; i < vars.size(); ++i ) {
				pair<tcons1,tcons1> diff_cons = AnalysisUtils::GetDiffCons(guards_env,vars[i]);
				assert(phi.size());
				phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.first).change_environment(mgr,phi.begin()->get_environment()));
				phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.second).change_environment(mgr,phi.begin()->get_environment()));
			}

			vector<abstract1> result_plus, result_minus;

			// Cross-meet with all states in Delta
			for ( AbstractSet::iterator abs_iter = abs_set_.begin(), abs_end = abs_set_.end(); abs_iter != abs_end; ++abs_iter ) {
				index = 0;
				abstract1 vars_i = (abs_iter->vars), guards_i = AnalysisUtils::ForgetUnmatched((abs_iter->guards));
				for ( set<abstract1>::iterator phi_iter = phi.begin(), phi_end = phi.end(); phi_iter != phi_end; ++phi_iter ) {
					abstract1 meet_result = vars_i, meet_guards_result = guards_i, phi_i = *phi_iter;
					// abstracts
					environment env = AnalysisUtils::JoinEnvironments(meet_result.get_environment(),phi_i.get_environment());
					meet_result.change_environment(mgr,env);
					phi_i.change_environment(mgr,env);
					meet_result.meet(mgr,phi_i);
					// guards
					env = AnalysisUtils::JoinEnvironments(meet_guards_result.get_environment(),phi_i.get_environment());
					meet_guards_result.change_environment(mgr,env);
					phi_i.change_environment(mgr,env);
					meet_guards_result.meet(mgr,phi_i);
#if (VVERBOSE)
					cout << "<-----\nMeeting Phi_" << ++index << ":\n" << phi_i << "\nWith:\n" << vars_i << "<->" << guards_i
						 << "\nResult:\n" << meet_result << " <-> " << meet_guards_result << "\n";
#endif
					if ( !meet_result.is_bottom(mgr) && !meet_guards_result.is_bottom(mgr) ) {
						// TODO: forget equivalent variable iff there are no non-equivalent depenant on them
						//meet_result = ForgetEquivalent(meet_result);
						meet_result.meet(mgr,meet_guards_result);
						//meet_result = ForgetGuards(meet_result);
						abstract1 meet_plus = meet_result, meet_minus = meet_result;
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
				diff_found = true;
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
				diff_found = true;
			}
#if (VVERBOSE)

#endif
		}

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

	for ( map<SourceLocation,APAbstractDomain::ValTy>::iterator iter  = diff_points_states_.begin(), end = diff_points_states_.end(); iter != end; ++iter ) {
		unsigned index = 0;
		APAbstractDomain::ValTy state = iter->second;
		SourceLocation location = iter->first;
		string report_string;
		raw_string_ostream report_os(report_string);

		// partition one last time if strategy was at-corr-point
		if (state.partition_point == ValTy::PARTITION_AT_CORR_POINT)
			state.Partition();

#if (VERBOSE)
		report_os << "For Diff Point: ";
		location.print(report_os,contex_.getSourceManager());
		report_os << "\nState = ";
		state.print(report_os);
		report_os << "\n";
		llvm::outs() << report_os.str();
#endif

		string diff_string = state.ComputeDiff(report_on_diff,compute_diff);
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
