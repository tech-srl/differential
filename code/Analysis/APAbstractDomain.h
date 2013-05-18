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
#include "Abstract1.h"
#include "AnalysisUtils.h"

#include "apronxx/apronxx.hh"
using namespace apron;

namespace differential
{

class APAbstractDomain_ValueTypes;

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

		AbstractSet abs_set_;
		static manager *mgr_ptr_;
		environment env_; // Shared environment for all abstracts in AbsSet
		bool at_diff_point_;

		typedef enum { PARTITION_AT_NONE, PARTITION_AT_JOIN, PARTITION_AT_DIFF_POINT } PartitionPoint;
		static PartitionPoint partition_point;

		typedef enum { JOIN_NONE, JOIN_ALL, JOIN_GUARDS, JOIN_EQUIV } PartitionStrategy;
		static PartitionStrategy partition_strategy;

		static unsigned partition_threshold;

		typedef enum { WIDEN_AT_ALL, WIDEN_AT_DIFF_POINT, WIDEN_AT_BACK_EDGE } WideningPoint;
		static WideningPoint widening_point;

		typedef enum { WIDEN_ALL, WIDEN_EQUIV, WIDEN_GUARDS } WideningStrategy;
		static WideningStrategy widening_strategy;

		static unsigned widening_threshold;

		ValTy() : at_diff_point_(false) {	}

		ValTy(const ValTy& V) : abs_set_(V.abs_set_), env_(V.env_), at_diff_point_(V.at_diff_point_) { }

		virtual ~ValTy() { }

		size_t size() const { return abs_set_.size(); }
		void print() const { cerr << *this; }
		bool isTop() const;
		void Assign(const environment& expr_env, const var& variable, texpr1 expr, bool is_guard = false);
		void Forget(string name); // forget given var from the state.
		void Assume(const set<abstract1>& added_abs_set); // Assume set{abs1,abs2} means assume (abs1 v abs2)

		friend ostream& operator<<(ostream& os, const ValTy& V);
		bool operator==(const ValTy& rhs) const;
		bool operator<=(const ValTy& rhs) const;

		operator string() const {
			if (abs_set_.empty())
				return "[ ]";
			std::stringstream ss;
			ss << "[\n";
			for ( AbstractSet::const_iterator iter = abs_set_.begin(), end = abs_set_.end(); iter != end; ++iter )
				ss << *iter << "\n";
			ss << "]";
			return ss.str();
		}

		void copyValues(const ValTy& rhs);
		void JoinAll(); // joins all abstracts in the set into one abstract i.e. it performs: |_|{abs_1,...,abs_n}

		void Partition();
		map<Abstract1,AbstractSet> PartitionByGuards() const; // returns a mapping: {guards} ->  [abstracts]
		map<set<var>,AbstractSet> PartitionByEquivalence() const;

	private:
		static map<set<var>,Abstract2> JoinByPartition(map<set<var>,AbstractSet> partition);
		static map<Abstract1,Abstract1> JoinByPartition(map<Abstract1,AbstractSet> partition);
		static AbstractSet PartitionToAbsSet(map<set<var>,Abstract2> partition);
		static AbstractSet PartitionToAbsSet(map<Abstract1,Abstract1> partition);
public:

		ValTy& operator|=(ValTy& rhs);
		ValTy& Join(ValTy& rhs);

		ValTy& operator&=(const ValTy& rhs);
		ValTy& operator&=(const abstract1& abs);
		ValTy& operator&=(const tcons1& cons);
		ValTy& Meet(const ValTy& rhs);
		ValTy& Meet(const abstract1& abs);
		ValTy& Meet(const tcons1& cons);
		ValTy& MeetGuard(const tcons1& guard_cons);

		void SetTop();
		void SetBottom();

		ValTy& WidenByGuards(const ValTy& post, ValTy& dest);
		ValTy& WidenByEquivlance(const ValTy& post, ValTy& dest);
		ValTy& WidenAll(const ValTy& post, ValTy& dest);
		ValTy& Widening(const ValTy& post, ValTy& dest);

		bool sizesEqual(const ValTy& RHS) const;
	};
};

class APAbstractDomain : public DataflowValues<APAbstractDomain_ValueTypes>
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

class APChecker	: public APAbstractDomain::ObserverTy
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

	static abstract1 ForgetUntagged(const abstract1 &abs); // forget all untagged variables in the given abstract state
	static abstract1 ForgetTagged(const abstract1 &abs); // forget all tagged variables in the given abstract state
	static abstract1 ForgetInit(const abstract1 &abs); // forget all initial variables in the given abstract state
	static abstract1 ForgetGuards(const abstract1 &abs); // forget all guard variables in the given abstract state
	static abstract1 ForgetEquivalent(const abstract1 &abs); // forget all equivalent variables (v==v') in the given abstract state
	static abstract1 ForgetUnconstrained(const abstract1 &abs); // forget all unconstrained variables (v==v') in the given abstract state and environment.
	static abstract1 ForgetUnmatched(const abstract1 &abs); // forget all variables that were removed by the patch (i.e. don't have a tagged version) or were added by the patch (i.e. don't have an untagged version). This includes guards.

	static set<abstract1> NegateAbstract(manager &mgr, abstract1 &tau_i);
	static set<abstract1> CrossConjunct(manager &mgr, const set<abstract1> &abs_set1, const set<abstract1> &abs_set2);
	static set<abstract1> CrossConjunctAbstracts(manager &mgr, vector<set<abstract1> > negated_tau);
	static set<abstract1> MinimizeResult(manager &mgr, vector<abstract1> &result);

	/// Print fixed-point range information when the analysis is done
	void ObserveFixedPoint(bool report_on_diff, bool compute_diff, unsigned &report_ctr);
};

} // end namespace differential

#endif
