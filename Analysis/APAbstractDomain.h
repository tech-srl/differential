#ifndef ANALYZER_AP_ABSTRACT_DOMAIN_H
#define ANALYZER_AP_ABSTRACT_DOMAIN_H

#include <sstream>
#include <map>
#include <vector>
#include <set>
using namespace std;

#include <clang/AST/Decl.h>
#include <clang/Analysis/AnalysisDiagnostic.h>
#include <clang/Analysis/Support/BlkExprDeclBitVector.h>
#include <clang/Analysis/FlowSensitive/DataflowValues.h>
#include <llvm/ADT/DenseMap.h>
#include "../CodeHandler.h"
#include "../Defines.h"
#include "AnalysisUtils.h"
using namespace differential;

#include "apronxx/apronxx.hh"
using namespace apron;


#define VERBOSE   1
#define VVERBOSE  0
#define VVVERBOSE 0

// Very Verbose requires Verbose
#if (VVERBOSE)
#define VERBOSE   1
#endif

// Very Very Verbose requires Verbose
#if (VVVERBOSE)
#define VVERBOSE  1
#endif

#define DEBUGAssign             0
#define DEBUGUpdateEnvironment  0
#define DEBUGAssume             0
#define DEBUGresetValues        0
#define DEBUGsetValues          0
#define DEBUGEqual              0
#define DEBUGLowerEqual         0
#define DEBUGCanonicalize       1
#define DEBUGJoin               0
#define DEBUGMeet               0
#define DEBUGWidening           1
#define DEBUGMeetGuard			0

namespace clang
{

class BlockVarDecl;
class Expr;
class DeclRefExpr;
class VarDecl;

class APAbstractDomain_ValueTypes
{
public:

	struct ValTy;
	struct AnalysisDataTy;

	struct ObserverTy {
		virtual ~ObserverTy() {
		}

		virtual void ObserveAll(APAbstractDomain_ValueTypes::ValTy& state, SourceLocation loc) {
		}
	};

	struct AnalysisDataTy : public StmtDeclBitVector_Types::AnalysisDataTy {
		AnalysisDataTy() : Observer(NULL) {
		}
		virtual ~AnalysisDataTy() {
		}

		ObserverTy* Observer;
	};

//===--------------------------------------------------------------------===//
// ValTy - Dataflow value.
//===--------------------------------------------------------------------===//

	class ValTy : public DeclBitVector_Types::ValTy
	{


		typedef DeclBitVector_Types::ValTy ParentTy;

		static inline ParentTy& ParentRef(ValTy& X) {
			return static_cast<ParentTy&>(X);
		}

		static inline const ParentTy& ParentRef(const ValTy& X) {
			return static_cast<const ParentTy&>(X);
		}

	public:

		AbstractRefSet abs_set_;
		static manager *mgr_ptr_;
		environment env_; // Shared environment for all abstracts in AbsSet

		typedef enum {
		    AT_NONE,
		    AT_JOIN,
		    AT_DIFF_POINT
		} CanonizationPoint;
		static CanonizationPoint canonization_point;

		typedef enum {
		    ID,
		    ALL,
		    EQUIV
		} CanonizationStrategy;
		static CanonizationStrategy canonization_strategy;

		static unsigned canonization_threshold;

		ValTy() {	}

		ValTy(const ValTy& V) : abs_set_(V.abs_set_), env_(V.env_) { }

		virtual ~ValTy() { }

		size_t size() const {
			return abs_set_.size();
		}

		void print() const {
			cerr << *this;
		}

		bool isTop() const {
			for ( AbstractRefSet::const_iterator iter = abs_set_.begin(), E = abs_set_.end(); iter != E; ++iter ) {
				if (iter->first->is_top(*mgr_ptr_) && iter->second->is_top(*mgr_ptr_))
					return true;
			}
			return false;
		}

		void Assign(const environment& expr_env, const var& variable, texpr1 expr, bool is_guard = false) {
#if (DEBUGAssign)
			cerr << "Assigning " << expr << " To " << variable << "\n";
#endif
			manager mgr = *mgr_ptr_;
			AbstractRefSet updated_abs_set;

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
					updated_abs_set.insert(make_pair(AnalysisUtils::AddAbstractToAll(abs),AnalysisUtils::AddAbstractToAll(guards)));
			} else {
				for ( AbstractRefSet::iterator iter = abs_set_.begin(), E = abs_set_.end(); iter != E; ++iter ) {
					abstract1 abs = *(iter->first), guards = *(iter->second);
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
						updated_abs_set.insert(make_pair(AnalysisUtils::AddAbstractToAll(abs),AnalysisUtils::AddAbstractToAll(guards)));
				}
			}
			abs_set_ = updated_abs_set;
#if (DEBUGAssign)
			cerr << "Assign. " << *this << endl;
#endif
		}


		/// forget given var from the state.
		void Forget(string name) {
			manager mgr = *mgr_ptr_;
			AbstractRefSet updated_abs_set;
			for ( AbstractRefSet::iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
				abstract1 abs = *(iter->first), guards =*(iter->second);
				abs.change_environment(mgr,env_);
				guards.change_environment(mgr,env_);
				if (abs.get_environment().contains(name)) {
					abs.forget(mgr,name);
				}
				if (guards.get_environment().contains(name)) {
					guards.forget(mgr,name);
				}
				updated_abs_set.insert(make_pair(AnalysisUtils::AddAbstractToAll(abs),AnalysisUtils::AddAbstractToAll(guards)));
			}
			abs_set_ = updated_abs_set;
		}

		/// Assume set{abs1,abs2} means assume (abs1 v abs2)
		void Assume(const set<abstract1>& added_abs_set) {
#if (DEBUGAssume)
			cerr << "Assuming\n";
			cerr << "{";
			for ( set<abstract1>::const_iterator iter = added_abs_set.begin(), end = added_abs_set.end(); iter != end; ++iter )
				cerr << *iter << ",";
			cerr << "}\n";
#endif
			manager mgr = *mgr_ptr_;
			AbstractRefSet updated_abs_set;

			// No need to account for guards as they are never involed in this operation
			for ( set<abstract1>::const_iterator added_iter = added_abs_set.begin(), added_end = added_abs_set.end(); added_iter != added_end; ++added_iter ) {
				abstract1 abs = *added_iter;
				if (abs_set_.size() == 0) {
					// no need to account for widen_ here since we start off from top
					updated_abs_set.insert(make_pair(AnalysisUtils::AddAbstractToAll(abs),AnalysisUtils::AddAbstractToAll(abstract1(mgr, env_, apron::top()))));
				} else {
					for ( AbstractRefSet::iterator iter = abs_set_.begin(), E = abs_set_.end(); iter != E; ++iter ) {
						abstract1 curr_abs = *(iter->first);
						environment env = AnalysisUtils::JoinEnvironments(abs.get_environment(),curr_abs.get_environment());
						curr_abs.change_environment(mgr,env);
						abs.change_environment(mgr,env);
						curr_abs *= abs;
						if (!(curr_abs.is_bottom(mgr) || iter->second->is_bottom(mgr)))
							updated_abs_set.insert(make_pair(AnalysisUtils::AddAbstractToAll(curr_abs),iter->second));
					}
				}
			}
			abs_set_ = updated_abs_set;

#if (DEBUGAssume)
			cerr << "Assume. " << *this << endl;
#endif
		}

		friend ostream& operator<<(ostream& os, const ValTy& V);

		operator string() const {
			std::stringstream ss;
			ss << "[ ";
			for ( AbstractRefSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter )
				ss << *(iter->second) << " <-> " << *(iter->first) << "\n";
			ss << "]";
			return ss.str();
		}

		bool operator==(const ValTy& rhs) const {
#if (DEBUGEqual)
			cerr << "Comparing " << *this << " To " << rhs;
#endif
			if (size() != rhs.size())
				return false;
			for ( AbstractRefSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
				if ( rhs.abs_set_.find(*iter) == rhs.abs_set_.end() ) return false;
			}
			return true;
		}

		//TODO: Make this better with a lattice
		bool operator<=(const ValTy& rhs) const {
#if (DEBUGLowerEqual)
			cerr << *this << " <= " << rhs << " ? (No)";
#endif
			manager mgr = *mgr_ptr_;
			// forall sub-states S1 in the abstract set
			for ( AbstractRefSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
				bool found = false;
				// exists a sub-state S2 in RHS
				for ( AbstractRefSet::const_iterator rhs_iter = rhs.abs_set_.begin(), rhs_end = rhs.abs_set_.end(); rhs_iter != rhs_end; ++rhs_iter ) {
					// Such that S1 <= S2
					abstract1 guards = *(iter->second), rhs_guards = *(rhs_iter->second);
					if (guards.get_environment() != rhs_guards.get_environment()) { // join environments if needed
						environment env = AnalysisUtils::JoinEnvironments(guards.get_environment(),rhs_guards.get_environment());
						guards.change_environment(mgr,env);
						rhs_guards.change_environment(mgr,env);
					}
					if (!(guards <= rhs_guards))
						continue; // no hope for this pair
					abstract1 abs = *(iter->first), rhs_abs = *(rhs_iter->first);
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

		inline void copyValues(const ValTy& rhs) {
			env_ = rhs.env_;
			abs_set_ = rhs.abs_set_;
		}

		/// JoinAll joins all abstracts in the set into one abstract i.e. it performs: |_|{abs_1,...,abs_n}
		void JoinAll() {
			abs_set_.clear();
			abs_set_.insert(AnalysisUtils::JoinAbstracts(*mgr_ptr_,abs_set_));
		}

		map<set<var>,AbstractRefSet> Partition() const {
			manager mgr = *mgr_ptr_;
			environment env = env_;
			map<set<var>,AbstractRefSet> result;
			for ( AbstractRefSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
				abstract1 abs = *(iter->first), guards = *(iter->second);
				vector<var> vars = env.get_vars();
				set<var> equivalent_vars;

				// find the set of equivalent vars for the current abstract that agree on guards
				for (size_t i = 0; i < vars.size(); ++i ) {
					var v = vars[i];
					string name = v;
					if (name.find(Defines::kTagPrefix) == 0) // check V == V' only (and not vice versa). this makes the code simpler.
						continue;


					var v_tag(Defines::kTagPrefix + name);
					if ( !env.contains(v_tag) )
						env = env.add(&v_tag,1,0,0);

					abs.change_environment(mgr,env);
					guards.change_environment(mgr,env);

					tcons1 v_equal(texpr1(env,v) == texpr1(env,v_tag));

					if (AnalysisUtils::IsEquivalent(abs,v,v_tag) || AnalysisUtils::IsEquivalent(guards,v,v_tag)) { // equivalence found for var v, add it to the set of equivalent vars
						equivalent_vars.insert(v);
					}
				}

				// put the abstract in the set of other abstract that hold equivalence for the same set of vars
				result[equivalent_vars].insert(*iter);
			}

			return result;
		}

		map<set<var>,pair<const abstract1*,const abstract1*> > JoinByPartition(map<set<var>,AbstractRefSet> partition) const {
			map<set<var>,pair<const abstract1*,const abstract1*> > result;
			manager mgr = *mgr_ptr_;
			for (map<set<var>,AbstractRefSet>::const_iterator partition_iter = partition.begin(), partition_end = partition.end(); partition_iter != partition_end; ++partition_iter ) {
				// for each set of abstracts (that hold equivalence for the same vars) join them all into one abstract and put it in the result
				result[partition_iter->first] = AnalysisUtils::JoinAbstracts(mgr,partition_iter->second);
			}
			return result;
		}



		AbstractRefSet PartitionToAbsSet(map<set<var>,pair<const abstract1*, const abstract1*> > partition) const {
			AbstractRefSet result;
			for (map<set<var>,pair<const abstract1*, const abstract1*> >::const_iterator partition_iter = partition.begin(), partition_end = partition.end(); partition_iter != partition_end; ++partition_iter ) {
				// join the partitioned (joined) abstracts into a regular abstract set
				result.insert(partition_iter->second);
			}
			return result;
		}


		void Canonicalize() {
#if (DEBUGCanonicalize)
			cerr << "\n---------------------\nCanonicalize: " << *this;
#endif
			if (abs_set_.size() > 1) {
				if ( canonization_strategy == ALL ) {
					JoinAll();
				} else if ( canonization_strategy == EQUIV ) {
					// for each, find the set of variables which are equivalent and partition
					map<set<var>,AbstractRefSet> partition = Partition();
					abs_set_ = PartitionToAbsSet(JoinByPartition(partition));
				}
			}

#if (DEBUGCanonicalize)
			cerr << "\nResult: " << *this << "\n---------------------\n";
			getchar();
#endif
		}

		ValTy& operator|=(ValTy& rhs) {
			return Join(rhs);
		}

		ValTy& Join(ValTy& rhs) {
#if (DEBUGJoin)
			static unsigned join_counter = 0;
			cerr << "joining: " << *this << "\nand: "<< rhs;
			size_t prev_size = abs_set_.size();
#endif

			for ( AbstractRefSet::const_iterator iter = rhs.abs_set_.begin(), end = rhs.abs_set_.end(); iter != end; ++iter ) {
				// Remove bottoms
				if (iter->first->is_bottom(*mgr_ptr_) || iter->second->is_bottom(*mgr_ptr_))
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

		ValTy& operator&=(const ValTy& rhs) {
			return Meet(rhs);
		}


		ValTy& operator&=(const abstract1& abs) {
			return Meet(abs);
		}

		ValTy& operator&=(const tcons1& cons) {
			return Meet(cons);
		}

		ValTy& Meet(const ValTy& rhs) {
#if (DEBUGMeet)
			cerr << "Meeting: " << *this << "And: "<< rhs;
#endif
			manager mgr = *mgr_ptr_;

			AbstractRefSet met_abs_set;
			if (abs_set_.size() == 0) {
				met_abs_set = rhs.abs_set_;
			} else {
				for ( AbstractRefSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
					for ( AbstractRefSet::const_iterator rhs_iter = rhs.abs_set_.begin(), rhs_end = rhs.abs_set_.end(); rhs_iter != rhs_end; ++rhs_iter ) {
						abstract1 rhs_abs = *(rhs_iter->first), meet_abs = *(iter->first);
						abstract1 rhs_guards = *(rhs_iter->second), meet_guards = *(iter->second);
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
							met_abs_set.insert(make_pair(AnalysisUtils::AddAbstractToAll(meet_abs),AnalysisUtils::AddAbstractToAll(meet_guards)));
					}
				}
			}
			abs_set_ = met_abs_set;
#if (DEBUGMeet)
			cerr << "Meet.\n" << *this << endl;
#endif
			return *this;
		}

		ValTy& Meet(const abstract1& abs) {
			ValTy rhs;
			rhs.abs_set_.insert(make_pair(AnalysisUtils::AddAbstractToAll(abs),AnalysisUtils::AddAbstractToAll(abstract1(*mgr_ptr_,abs.get_environment(),apron::top()))));
			return Meet(rhs);
		}
		ValTy& Meet(const tcons1& cons) {
			return Meet(AnalysisUtils::AbsFromConstraint(*mgr_ptr_,cons));
		}

		ValTy& MeetGuard(const tcons1& guard_cons) {
			manager mgr = *mgr_ptr_;
			abstract1 guard_abs = AnalysisUtils::AbsFromConstraint(mgr,guard_cons);
#if (DEBUGMeetGuard)
			cerr << "MeetGuard: " << *this << "And: "<< guard_abs;
#endif
			AbstractRefSet met_abs_set;
			if (abs_set_.size() == 0) {
				met_abs_set.insert(make_pair(AnalysisUtils::AddAbstractToAll(abstract1(*mgr_ptr_,guard_abs.get_environment(),apron::top())),AnalysisUtils::AddAbstractToAll(guard_abs)));
			} else {
				for ( AbstractRefSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter ) {
						abstract1 meet_guards = *(iter->second);
						environment env = AnalysisUtils::JoinEnvironments(meet_guards.get_environment(),guard_abs.get_environment());
						meet_guards.change_environment(mgr,env);
						guard_abs.change_environment(mgr,env);
						meet_guards.meet(mgr,guard_abs);
						if (!(iter->first->is_bottom(mgr) || meet_guards.is_bottom(mgr)))
							met_abs_set.insert(make_pair(iter->first,AnalysisUtils::AddAbstractToAll(meet_guards)));
				}
			}
			abs_set_ = met_abs_set;
#if (DEBUGMeetGuard)
			cerr << "MeetGuard.\n" << *this << endl;
#endif
			return *this;
		}

		void SetTop(){
			abs_set_.clear();
			const abstract1 * abs_ptr = AnalysisUtils::AddAbstractToAll(abstract1(*mgr_ptr_,env_,apron::top()));
			abs_set_.insert(make_pair(abs_ptr,abs_ptr));
		}
		void SetBottom(){
			abs_set_.clear();
		}

		ValTy& WidenByPartition(const ValTy& post, ValTy& dest) {
#if (DEBUGWidening)
			cerr << "<-----\nWidening: " << *this << " And: "<< post << "\n";
#endif
			map<set<var>, pair<const abstract1*,const abstract1*> > pre_partition = JoinByPartition(Partition());
			map<set<var>, pair<const abstract1*,const abstract1*> > post_partition = post.JoinByPartition(post.Partition());

			dest.abs_set_.clear();
			manager mgr = *mgr_ptr_;
			for (map<set<var>, pair<const abstract1*,const abstract1*> >::const_iterator iter = pre_partition.begin(), end = pre_partition.end(); iter != end; ++iter ) {
				const set<var> &key = iter->first;
				abstract1 widened_abs = *((iter->second).first), widened_guards = *((iter->second).second);
				// try and find an abstract of the same equivalence class
				if (post_partition.count(key)) {
					// if found, widen it with the matching abstract from rhs
					abstract1 post_abs = *((post_partition[key]).first), post_guards = *((post_partition[key]).second);
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
				dest.abs_set_.insert(make_pair(AnalysisUtils::AddAbstractToAll(widened_abs),AnalysisUtils::AddAbstractToAll(widened_guards)));
			}
			// take care of the unmateched abstracts that remain in post
			for (map<set<var>, pair<const abstract1*,const abstract1*> >::const_iterator iter = post_partition.begin(), end = post_partition.end(); iter != end; ++iter )
				dest.abs_set_.insert(iter->second);

#if (DEBUGWidening)
			cerr << "Result: " << dest << "\n----->\n";
#endif
			return *this;
		}

		ValTy& WidenAll(const ValTy& post, ValTy& dest) {
			manager mgr = *mgr_ptr_;

			pair<const abstract1*,const abstract1*> joined_pre_abs = AnalysisUtils::JoinAbstracts(mgr, abs_set_);
			pair<const abstract1*,const abstract1*> joined_post_abs = AnalysisUtils::JoinAbstracts(mgr, post.abs_set_);

#if (DEBUGWidening)
			cerr << "Widening: " << *(joined_pre_abs.first) << "<->" << *(joined_pre_abs.second) << " And: "
				 << *(joined_post_abs.first) << "<->" << *(joined_post_abs.second)  << "\n";
#endif
			abstract1 widened_abs(*mgr_ptr_,env_,apron::bottom());
			apron::widening(mgr, widened_abs, *(joined_pre_abs.first), *(joined_post_abs.first));

			abstract1 widened_guards(*mgr_ptr_,env_,apron::bottom());
			apron::widening(mgr, widened_guards, *(joined_pre_abs.second), *(joined_post_abs.second));

			dest.abs_set_.clear();
			dest.abs_set_.insert(make_pair(AnalysisUtils::AddAbstractToAll(widened_abs),AnalysisUtils::AddAbstractToAll(widened_guards)));

#if (DEBUGWidening)
			cerr << "\nResult:\n" << dest << endl;
#endif
			return *this;
		}

		ValTy& Widening(const ValTy& post, ValTy& dest) {
			if ( post == *this ) {
				dest = *this;
				return *this;
			}
			return WidenByPartition(post,dest);
		}

		bool sizesEqual(const ValTy& RHS) const {
			return ParentRef(*this).sizesEqual(ParentRef(RHS));
		}


	};


};



class APAbstractDomain :
	public DataflowValues<APAbstractDomain_ValueTypes>
{

public:
	APAbstractDomain(CFG &cfg) {
		getAnalysisData().setCFG(cfg);
	}

	/// IntializeValues - Create initial dataflow values and meta data for
	///  a given CFG.  This is intended to be called by the dataflow solver.
	void InitializeValues(const CFG& cfg);

	typedef APAbstractDomain_ValueTypes::ObserverTy ObserverTy;


};


//namespace {
class APChecker
	: public APAbstractDomain::ObserverTy
{

	typedef APAbstractDomain::ValTy ValTy;

	Rewriter                    rewriter_;
	ASTContext                  &contex_;
	DiagnosticsEngine           &diagnostics_engine_;
	Preprocessor                *preprocessor_ptr_;
	map<SourceLocation,ValTy>   diff_points_states_;

public:
	APChecker(ASTContext &contex, DiagnosticsEngine &diagnostics_engine, Preprocessor * preprocessor_ptr) :
		rewriter_(contex.getSourceManager(),contex.getLangOptions()), contex_(contex),
		diagnostics_engine_(diagnostics_engine), preprocessor_ptr_(preprocessor_ptr) { }

	virtual void ObserveAll(APAbstractDomain::ValTy& state, SourceLocation loc) {
		if ( // diff_points_states_[loc].abs_set_.size() <= state.abs_set_.size() && // more precise
		    diff_points_states_[loc] <= state)
			diff_points_states_[loc] = state;
	}

	/**
	 * Forget all untagged variables in the given abstract state
	 *
	 */
	void ForgetUntagged(abstract1 &abs) {
		manager mgr = abs.get_manager();
		vector<var> variables = abs.get_environment().get_vars();
		for ( unsigned i = 0 ; i < variables.size() ; ++i ) {
			string name = variables[i];
			if (name.find(Defines::kTagPrefix) > 0 )
				abs = abs.forget(mgr,variables[i]);
		}
	}

	/**
	 * Forget all tagged variables in the given abstract state
	 *
	 */
	void ForgetTagged(abstract1 &abs) {
		manager mgr = abs.get_manager();
		vector<var> variables = abs.get_environment().get_vars();
		for ( unsigned i = 0 ; i < variables.size() ; ++i ) {
			string name = variables[i];
			if (name.find(Defines::kTagPrefix) == 0 )
				abs = abs.forget(mgr,variables[i]);
		}
	}

	/**
	 * Forget all initial variables in the given abstract
	 * state
	 *
	 */
	void ForgetInit(abstract1 &abs) {
		manager mgr = abs.get_manager();
		vector<var> variables = abs.get_environment().get_vars();
		for ( unsigned i = 0 ; i < variables.size() ; ++i ) {
			string name = variables[i];
			if (name.find(Defines::kInitPrefix) == 0 ||
			    name.find(Defines::kTagPrefix + Defines::kInitPrefix) == 0)
				abs = abs.forget(mgr,name);
		}
	}

	/**
	 * Forget all guard variables in the given abstract
	 * state
	 */
	void ForgetGuards(abstract1 &abs) {
		manager mgr = abs.get_manager();
		environment env = abs.get_environment();
		vector<var> variables = env.get_vars();
		for ( unsigned i = 0 ; i < variables.size() ; ++i ) {
			string name = variables[i];
			if (name.find(Defines::kGuardPrefix) == 0 ||
			    name.find(Defines::kTagPrefix + Defines::kGuardPrefix) == 0 ) {
				abs = abs.forget(mgr,variables[i]);
				env = env.remove(&variables[i],1);
			}
		}
		abs.change_environment(mgr,env);
	}

	/**
	 * Forget all equivalent variables (v==v') in the given abstract
	 * state
	 */
	void ForgetEquivalent(abstract1 &abs) {
		manager mgr = abs.get_manager();
		environment env = abs.get_environment();
		vector<var> vars = env.get_vars();
		for (size_t i = 0; i < vars.size(); ++i ) {
			var v = vars[i];
			string name = v;
			if (name.find(Defines::kTagPrefix) == 0) // check V == V' only (and not vice versa). this makes the code simpler.
				continue;
			var v_tag(Defines::kTagPrefix + name);

			// Check for equivalence
			if (AnalysisUtils::IsEquivalent(abs,v,v_tag)) {
				abs = abs.forget(mgr,v);
				abs = abs.forget(mgr,v_tag);
			}
		}
	}


	/**
	 * Forget all unconstrained variables (v==v') in the given
	 * abstract state and environment.
	 */
	void ForgetUnconstrained(abstract1 &abs) {
		vector<var> vars = abs.get_environment().get_vars();
		manager mgr = abs.get_manager();
		for (size_t i = 0; i < vars.size(); ++i ) {
			environment env = abs.get_environment();
			if (abs.is_variable_unconstrained(mgr,vars[i])) {
				abs.forget(mgr,vars[i]);
				abs.change_environment(mgr,env.remove(&vars[i],1));
			}
		}
		//cerr <<"Reduced Env Size To " << abs.get_environment().intdim() << endl;;
	}

	set<abstract1> NegateAbstract(manager &mgr, abstract1 &tau_i) {
		// Computing ~(Tau_i) = {{~c | c \in Constrtaints}}

		// before negation take out all the (V==V') constraints as they will repeat in every negation
		// i.e. we are replacing the computation: ~tau1 /\ ... /\ ~taun = (p1 \/ V!=V') /\ ... /\ (pn \/ V!=V')
		// with : (p1 /\ ... /\ pn) \/ (V!=V')

		set<abstract1> negated_tau_i;

		// ~bottom = top
		if ( tau_i.is_bottom(mgr) ) {
			negated_tau_i.insert(abstract1(mgr,tau_i.get_environment(),apron::top()));
			return negated_tau_i;
		} else if ( tau_i.is_top(mgr) ) { // ~top = bottom
			negated_tau_i.insert(abstract1(mgr,tau_i.get_environment(),apron::bottom()));
			return negated_tau_i;
		}

		tcons1_array tau_i_cons = tau_i.to_tcons_array(mgr);

		// create a (V != V') abstract to check and see if it's a V=V' constraint
		environment env = tau_i.get_environment();
		vector<var> vars = env.get_vars();
		abstract1 unequiv_abs1(mgr,env,apron::top()), unequiv_abs2(mgr,env,apron::top());
		for (size_t i = 0 ; i < vars.size(); ++i ) {
			pair<tcons1,tcons1> diff_cons = AnalysisUtils::GetDiffCons(env,vars[i]);
			unequiv_abs1.change_environment(mgr,AnalysisUtils::JoinEnvironments(env,diff_cons.first.get_environment()));
			unequiv_abs2.change_environment(mgr,AnalysisUtils::JoinEnvironments(env,diff_cons.second.get_environment()));
			unequiv_abs1 *= tcons1_array(1,&(diff_cons.first));
			unequiv_abs2 *= tcons1_array(1,&(diff_cons.second));
		}

		for ( size_t i = 0 ; i < tau_i_cons.size(); i++ ) {
			// meeting the constraint with the (V > V') and (V < V) constraints
			// if both bottom, it must be V == V'
			if (AnalysisUtils::AbsFromConstraint(mgr,tau_i_cons.get(i)).meet(mgr,unequiv_abs1).is_bottom(mgr) &&
				AnalysisUtils::AbsFromConstraint(mgr,tau_i_cons.get(i)).meet(mgr,unequiv_abs2).is_bottom(mgr)){
					//cerr << "Skipping " << AnalysisUtils::AbsFromConstraint(mgr,tau_i_cons.get(i)) << endl;
					continue;
				}
			AnalysisUtils::NegateConstraint(mgr, tau_i_cons.get(i),negated_tau_i);
		}

		return negated_tau_i;
	}

	set<abstract1> CrossConjunct(manager &mgr, const set<abstract1> &abs_set1, const set<abstract1> &abs_set2) {
		set<abstract1> result;
		for ( set<abstract1>::iterator iter1 = abs_set1.begin(), end1 = abs_set1.end(); iter1 != end1; ++iter1 ) {
			for ( set<abstract1>::iterator iter2 = abs_set2.begin(),end2 = abs_set2.end(); iter2 != end2; ++iter2 ) {
				abstract1 conjunction_abs = *iter1, second_abs = *iter2;
				environment env = AnalysisUtils::JoinEnvironments(conjunction_abs.get_environment(),second_abs.get_environment());
				conjunction_abs.change_environment(mgr,env);
				second_abs.change_environment(mgr,env);
				conjunction_abs.meet(mgr,second_abs);
				result.insert(conjunction_abs);
			}
		}
		return result;
	}

	set<abstract1> CrossConjunctAbstracts(manager &mgr, vector<set<abstract1> > negated_tau) {
#if (VVERBOSE)
		cout << "\nCross Conjuncting:";
		for (size_t i = 0 ; i < negated_tau.size(); ++i) {
			for (set<abstract1>::const_iterator iter = negated_tau[i].begin(), end = negated_tau[i].end(); iter != end; ++iter)
				cout << *iter << " V ";
			if (i < negated_tau.size() - 1)
				cout << "\n/\\\n";
			else
				cout << endl;
		}
#endif
		if (negated_tau.empty()) // Conjunction with the empty set (i.e. false) results in an empty set
			return set<abstract1>();
		// Start off Phi as the last group of abstracts from Tau_Neg
		set<abstract1> phi = negated_tau.back();
		negated_tau.pop_back();
		while ( !negated_tau.empty() ) {
#if (VVVERBOSE)
			cout << "Phi So Far:";
			for (set<abstract1>::const_iterator iter = phi.begin(), end = phi.end(); iter != end; ++iter)
				cout << *iter << " V ";
			cout << endl;
#endif

			// cross-conjunct the (new) last group of abstracts from Tau_neg and Tau_neg_guards
			// with the already computed cross-conjunction in Phi
			phi = CrossConjunct(mgr,phi,negated_tau.back());

#if (VERBOSE)
			cerr << "Cross Conjunction so far holds " << phi.size() << " abstracts.\n";
#endif
			// Again, remove the last groups of abstracts (we're done incorporating it into Phi)
			negated_tau.pop_back();
		}
#if (VVERBOSE)
			cout << "Result:";
			for (set<abstract1>::const_iterator iter = phi.begin(), end = phi.end(); iter != end; ++iter)
				cout << *iter << " V ";
			cout << endl;
#endif
		return phi;
	}

	set<abstract1> MinimizeResult(manager &mgr, vector<abstract1> &result) {
		set<abstract1> minimized_result;
		environment env;

		// first collect the environment
		for (vector<abstract1>::iterator iter = result.begin(), end = result.end(); iter != end; ++iter)
			env = AnalysisUtils::JoinEnvironments(iter->get_environment(),env);

		for (vector<abstract1>::iterator iter = result.begin(), end = result.end(); iter != end; ++iter) {
			// check for containment in other abstract
			bool is_contained = false;
			abstract1 current_abs = *iter;
			current_abs.change_environment(mgr,env);
			for (vector<abstract1>::iterator iter2 = result.begin(), end2 = result.end(); iter2 != end2; ++iter2) {
				abstract1 current_abs2 = *iter2;
				current_abs2.change_environment(mgr,env);
				if (current_abs != current_abs2 && current_abs <= current_abs2) {
					is_contained = true;
					break;
				}
			}
			if (!is_contained) {
				minimized_result.insert(current_abs);
			}
		}
		return minimized_result;
	}

	/// Print fixed-point range information when the analysis is done
	void ObserveFixedPoint(bool report_on_diff, unsigned &report_ctr) {
		cout << "Generating results...\n";

		// We want the results in stdout, not stderr:
		diagnostics_engine_.setClient(new TextDiagnosticPrinter(llvm::outs(), DiagnosticOptions()));
		diagnostics_engine_.getClient()->BeginSourceFile(LangOptions(), preprocessor_ptr_);

		// First order the reports according to line and column
		map<unsigned,FullSourceLoc> ordered_locations;
		map<unsigned,unsigned> ordered_diag_ids;

		bool forget_unconstrained = true;

		for ( map<SourceLocation,APAbstractDomain::ValTy>::iterator iter  = diff_points_states_.begin(), end = diff_points_states_.end(); iter != end; ++iter ) {
			unsigned index = 0;
			bool diff_found = false;
			APAbstractDomain::ValTy state = iter->second;
			manager mgr = *state.mgr_ptr_;
			environment env, guards_env;// = state.env;
			SourceLocation location = iter->first;
			stringstream report_ss;

			// start off by minimizing the state by removing guards, unconstrained variables and equivalent variables (according to the flags)
			AbstractRefSet initial_abs_set = state.abs_set_;
			state.abs_set_.clear();
			for ( AbstractRefSet::iterator abs_iter = initial_abs_set.begin(), abs_end = initial_abs_set.end(); abs_iter != abs_end; ++abs_iter ) {
				abstract1 delta_i = *(abs_iter->first), guards_i = *(abs_iter->second);
				if (forget_unconstrained) { // forget unconstrainted variables.
					ForgetUnconstrained(delta_i);
					ForgetUnconstrained(guards_i);
				}
				state.abs_set_.insert(make_pair(AnalysisUtils::AddAbstractToAll(delta_i),AnalysisUtils::AddAbstractToAll(guards_i)));
				// collect the environment
				vector<var> vars = delta_i.get_environment().get_vars();
				for ( unsigned i = 0 ; i < vars.size() ; ++i )
					if ( !env.contains(vars[i]) )
						env = env.add(&vars[i],1,0,0);

				vars = guards_i.get_environment().get_vars();
				for ( unsigned i = 0 ; i < vars.size() ; ++i )
					if ( !guards_env.contains(vars[i]) )
						guards_env = guards_env.add(&vars[i],1,0,0);
			}


			cout << "For Diff Point: ";
			iter->first.dump(contex_.getSourceManager());
			cout << ", Abstract Set Size = " << state.abs_set_.size();
			cout << ", Environment Size = " << state.env_.intdim() << "\n";
			cout << ", State = " << state << "\n";
			report_ss << "\nState = " << state << "\n";

#if (VERBOSE)
			report_on_diff = false; // Report all
#endif
			// In case we only know T, a difference might exists and we could not precisly represent it,
			// therefore we must report a potential diff in order to stay sound
			if ( state.isTop() ) {
				report_ss << "New / Lost State: top\n";
				diff_found = true;
			} else {
				vector< set<abstract1> > negated_tau;
				for ( AbstractRefSet::iterator abs_iter = state.abs_set_.begin(), abs_end = state.abs_set_.end(); abs_iter != abs_end; ++abs_iter ) {
					index++;
					abstract1 delta_i = *(abs_iter->first), delta_guards_i = *(abs_iter->second);
#if (VVERBOSE)
					cout << "Staring off with Delta" << index << " = " << delta_i << "<->" << delta_guards_i << endl;
#endif
					if (delta_i.is_bottom(mgr) || delta_guards_i.is_bottom(mgr) )
					  continue;

					//delta_i.change_environment(mgr,env);
					abstract1 tau_i = delta_i;
					environment tau_i_env = tau_i.get_environment();
					vector<var> vars = tau_i_env.get_vars();
					for ( unsigned i = 0 ; i < vars.size() ; ++i ) {
						string name = vars[i];
						if (name.find(Defines::kTagPrefix) == 0) // V == V' is sufficient, no need to create V' == V
							continue;

						// (V == V')
						tcons1 v_equal = AnalysisUtils::GetEquivCons(tau_i_env,vars[i]);
						tau_i.change_environment(mgr,AnalysisUtils::JoinEnvironments(tau_i_env,v_equal.get_environment()));
						// Tau_i = (Delta_i /\ (V == V') /\ (V0 == V0'))
						tau_i.meet(mgr,tcons1_array(1,&v_equal));
					}

					delta_guards_i.change_environment(mgr,guards_env);
					abstract1 tau_guards_i = delta_guards_i;
					environment tau_guards_env = tau_guards_i.get_environment();
					vars = tau_guards_env.get_vars();
					for ( unsigned i = 0 ; i < vars.size() ; ++i ) {
						string name = vars[i];
						if (name.find(Defines::kTagPrefix) == 0 ) // V == V' is sufficient, no need to create V' == V
							continue;

						// (Guard == Guard')
						tcons1 v_equal = AnalysisUtils::GetEquivCons(tau_guards_env,vars[i]);
						tau_guards_i.change_environment(mgr,AnalysisUtils::JoinEnvironments(tau_guards_env,v_equal.get_environment()));
						// Tau_i = (Delta_i /\ (V == V') /\ (V0 == V0'))
						tau_guards_i.meet(mgr,tcons1_array(1,&v_equal));

					}

#if (VVERBOSE)
					cout << "Computed Tau" << index << " = (Delta" << index << " /\\ (V == V')) = " << tau_i << "<->" << tau_guards_i << endl;
#endif
					// Computing ~Tau_i by negating all the constraints (both for regular and for guards)
					environment joined_env = AnalysisUtils::JoinEnvironments(tau_i.get_environment(), tau_guards_i.get_environment());
					// make them have the same environment, so we can put them in a set together
					tau_i.change_environment(mgr,joined_env);
					tau_guards_i.change_environment(mgr,joined_env);

					set<abstract1> negation = NegateAbstract(mgr, tau_i), guards_negation = NegateAbstract(mgr, tau_guards_i);
					for (set<abstract1>::const_iterator iter = guards_negation.begin(), end = guards_negation.end(); iter != end; ++iter)
						negation.insert(*iter);
					negated_tau.push_back(negation);
				}

				// Cross-conjunct all Neg_Tau's
				set<abstract1> phi = CrossConjunctAbstracts(mgr, negated_tau);

				// before negation we took out all the (V==V') constraints as they will repeat in every negation
				// i.e. we are replacing the computation: ~tau1 /\ ... /\ ~taun = (p1 \/ V!=V') /\ ... /\ (pn \/ V!=V')
				// with : (p1 /\ ... /\ pn) \/ (V!=V')	therefore we now need to add ( V!=V' ) to phi
				vector<var> vars = env.get_vars();
				for (size_t i = 0 ; i < vars.size(); ++i ) {
					pair<tcons1,tcons1> diff_cons = AnalysisUtils::GetDiffCons(env,vars[i]);
					assert(phi.size());
					phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.first).change_environment(mgr,phi.begin()->get_environment()));
					phi.insert(AnalysisUtils::AbsFromConstraint(mgr,diff_cons.second).change_environment(mgr,phi.begin()->get_environment()));
				}

				vector<abstract1> result_plus, result_minus;

				// Cross-meet with all states in Delta
				for ( AbstractRefSet::iterator abs_iter = state.abs_set_.begin(), abs_end = state.abs_set_.end(); abs_iter != abs_end; ++abs_iter ) {
					index = 0;
					abstract1 delta_i = *(abs_iter->first), delta_guards_i = *(abs_iter->second);
					for ( set<abstract1>::iterator phi_iter = phi.begin(), phi_end = phi.end(); phi_iter != phi_end;++phi_iter ) {
						abstract1 meet_result = delta_i, meet_guards_result = delta_guards_i, phi_i = *phi_iter;
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
						if ( !meet_result.is_bottom(mgr) && !meet_guards_result.is_bottom(mgr) ) {
#if (VVERBOSE)
							cout << "<-----\nMeeting Phi_" << ++index << ":\n" << phi_i << "\nWith:\n" << delta_i << "<->" << delta_guards_i
							     << "\nResult:\n" << meet_result << " <-> " << meet_guards_result << "\n----->\n";
#endif

							// TODO: forget equivalent variable iff there are no non-equivalent depenant on them
							//ForgetEquivalent(meet_result);
							meet_result.meet(mgr,meet_guards_result);
							ForgetGuards(meet_result);
							abstract1 meet_plus = meet_result, meet_minus = meet_result;
							ForgetUntagged(meet_plus);
							ForgetTagged(meet_minus);
							result_minus.push_back(meet_minus);
							result_plus.push_back(meet_plus);
						}
					}
				}

				set<abstract1> minimized_result_plus = MinimizeResult(mgr,result_plus);
				for (set<abstract1>::iterator iter = minimized_result_plus.begin(), end = minimized_result_plus.end(); iter != end; ++iter) {
					stringstream ss;
					ss << *iter;
					string meet_str = ss.str();
#if (VVERBOSE)
					cout << "Result = " << meet_str << endl;
#endif
					meet_str = Utils::ReplaceAll(meet_str,Defines::kTagPrefix,"");
					report_ss << "New State: " << meet_str << endl;
					diff_found = true;
				}
				set<abstract1> minimized_result_minus = MinimizeResult(mgr,result_minus);
				for (set<abstract1>::iterator iter = minimized_result_minus.begin(), end = minimized_result_minus.end(); iter != end; ++iter) {
					stringstream ss;
					ss << *iter;
					string meet_str = ss.str();
#if (VVERBOSE)
					cout << "Result = " << meet_str << endl;
#endif
					meet_str = Utils::ReplaceAll(meet_str,Defines::kTagPrefix,"");
					report_ss << "Lost State: " << meet_str << endl;
					diff_found = true;
				}
#if (VVERBOSE)
					getchar();
#endif

			}
			// Create the report according to flags
			if ( !report_on_diff || diff_found ) {
				FullSourceLoc Loc = contex_.getFullLoc(location);
				bool Invalid;
				unsigned index = Loc.getExpansionLineNumber(&Invalid) * 1000 + Loc.getExpansionColumnNumber(&Invalid);
				ordered_locations[index] = Loc;
				ordered_diag_ids[index] = diagnostics_engine_.getCustomDiagID(DiagnosticsEngine::Warning,report_ss.str());
				rewriter_.InsertText(location.getLocWithOffset(-1), string("/*\n") + report_ss.str() + string("*/\n"));
			}
			if (diff_found) {
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
};
//} // end anonymous namespace

void CheckLinEq(CFG& cfg, ASTContext& contex, DiagnosticsEngine& diagnostics_engine, Preprocessor * preprocessor_ptr, unsigned& report_ctr);


} // end namespace clang

#endif
