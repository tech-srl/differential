#ifndef ANALYZER_ANALYSIS_UTILS_H
#define ANALYZER_ANALYSIS_UTILS_H

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
    };
}

#endif
