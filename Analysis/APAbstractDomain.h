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
#include "AnalysisConfiguration.h"
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
		environment env_; // shared environment for all abstracts in AbsSet

		static map< var, vector<var> > read_map_;   // l: v = A[i] is kept here as read(A,idx_l) -> (v,A,idx_l)
		static map< var, vector<var> > update_map_; // l: A[i] = e is kept here as update(A,idx_l) -> (A,idx_l)

		bool at_diff_point_;

		static AnalysisConfiguration::PartitionPoint partition_point_;
		static AnalysisConfiguration::PartitionStrategy partition_strategy_;

		static AnalysisConfiguration::WideningPoint widening_point_;
		static AnalysisConfiguration::WideningStrategy widening_strategy_;
		static unsigned widening_threshold_;

		ValTy() : at_diff_point_(false) {	}

		ValTy(const ValTy& V) : abs_set_(V.abs_set_), env_(V.env_), at_diff_point_(V.at_diff_point_) { }

		virtual ~ValTy() { }

		size_t size() const { return abs_set_.size(); }
		void print(raw_ostream &os) const { os << *this << '\n'; }
		bool isTop() const;
		void Assign(const environment& expr_env, const var& variable, texpr1 expr, bool is_guard = false);
		void Forget(string name); // forget given var from the state.
		void Assume(const set<abstract1>& added_abs_set); // Assume set{abs1,abs2} means assume (abs1 v abs2)

		friend ostream& operator<<(ostream& os, const ValTy& V);
		bool operator==(const ValTy& rhs) const;
		bool operator!=(const ValTy& rhs) const { return !(*this == rhs); }
		bool operator<=(const ValTy& rhs) const;
		bool operator<(const ValTy& rhs) const { return (*this != rhs) && (*this <= rhs); }

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

		bool Partition();
		map<Abstract1,AbstractSet> PartitionByGuards() const; // returns a mapping: {guards} ->  [abstracts]
		map<set<var>,AbstractSet> PartitionByEquivalence() const;

		void ApplyArrayReadDeductionRule(void);
		void ApplyArrayUpdateDeductionRule(void);

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

		static void WidenByGuards(const ValTy& pre, const ValTy& post, ValTy& result);
		static void WidenByEquivalence(const ValTy& pre, const ValTy& post, ValTy& result);
		static void WidenAll(const ValTy& pre, const ValTy& post, ValTy& result);
		static void Widening(const ValTy& pre, const ValTy& post, ValTy& result);

		bool sizesEqual(const ValTy& RHS) const;

		string ComputeDiff(bool report_on_diff, bool compute_diff, bool guards, ValTy &delta_plus,  ValTy &delta_minus);

	private:
		void RemoveUnmatchedVars();
		void CollectEnvironment(environment& env, environment& guards_env);
		string PrintBrokenEquivStates(manager& mgr);
		vector<set<abstract1> > ComputeNegatedTau(unsigned index, manager& mgr, bool guards);
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
	map<SourceLocation,ValTy>   corr_points_states_;

public:
	APChecker(ASTContext &contex, DiagnosticsEngine &diagnostics_engine, Preprocessor * preprocessor_ptr) :
		rewriter_(contex.getSourceManager(),contex.getLangOptions()), contex_(contex),
		diagnostics_engine_(diagnostics_engine), preprocessor_ptr_(preprocessor_ptr) { }

	virtual void ObserveAll(APAbstractDomain::ValTy& state, SourceLocation loc) {
		if ( // diff_points_states_[loc].abs_set_.size() <= state.abs_set_.size() && // more precise
		    corr_points_states_[loc] <= state)
			corr_points_states_[loc] = state;
	}

	/// Print fixed-point range information when the analysis is done
	void ObserveFixedPoint(bool report_on_diff, bool compute_diff, unsigned &report_ctr);
};

} // end namespace differential

#endif
