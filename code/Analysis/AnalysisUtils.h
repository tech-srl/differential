#ifndef ANALYZER_ANALYSIS_UTILS_H
#define ANALYZER_ANALYSIS_UTILS_H

#include <string>
#include <set>
#include <map>
using namespace std;

#include "apronxx/apronxx.hh"
using namespace apron;

#include "Abstract2.h"

namespace differential {

//typedef set<const abstract1*> AbstractSet;
//typedef map<const abstract1*,unsigned> AbstractSet;
//typedef map< set<string>, set<const abstract1*> > AbstractSet;
typedef set<Abstract2> AbstractSet;

class AnalysisUtils {
public:

	static const texpr1 kOne;
	static const texpr1 kZero;

	static abstract1 AbsFromConstraint(manager &mgr, const tcons1 &cons);
	static environment JoinEnvironments(const environment &env1, const environment &env2);
	static void NegateConstraint(manager &mgr, tcons1 constraint, set<abstract1> &result);
	static Abstract2 JoinAbstracts(manager& mgr, const AbstractSet &abstracts);
	static bool IsGuard(const var &v);
	static bool IsEquivalent(const abstract1 &abs, const var &v, const var &v_tag);
	static tcons1 GetEquivCons(environment &env, const var &v);
	static pair<tcons1,tcons1> GetDiffCons(environment &env, const var &v);
	static abstract1 MeetEquivalence(manager &mgr, const abstract1 &abs);

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

};


}

#endif
