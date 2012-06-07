#ifndef ANALYZER_ANALYSIS_UTILS_H
#define ANALYZER_ANALYSIS_UTILS_H

#include <set>
#include <map>
using namespace std;

#include "apronxx/apronxx.hh"
using namespace apron;

namespace differential {
	
	//typedef set<const abstract1*> AbstractRefSet;
	//typedef map<const abstract1*,unsigned> AbstractRefSet;
	//typedef map< set<string>, set<const abstract1*> > AbstractRefSet;
	typedef set<pair<const abstract1*,const abstract1*> > AbstractRefSet;

    class AnalysisUtils {
    public:
	
        static const texpr1 kOne;
        static const texpr1 kZero;
		
		// To avoid duplication of memory consuming abstracts, we keep them all in one global map
		// which maps the string print-out of the state to the state itself (this is the best way to truly avoid duplication)
		typedef map<string,abstract1*> AbstractDictionary;
		static AbstractDictionary abstract_dictionary;

		static const abstract1 * AddAbstractToAll(const abstract1 & abs);
        static abstract1 AbsFromConstraint(manager &mgr, const tcons1 &cons);
        static environment JoinEnvironments(const environment &env1, const environment &env2);
		static void NegateConstraint(manager &mgr, tcons1 constraint, set<abstract1> &result);
		static pair<const abstract1 *, const abstract1 *> JoinAbstracts(manager& mgr, const AbstractRefSet &abstracts);
		static bool IsGuard(const var &v);
		static bool IsEquivalent(const abstract1 &abs, const var &v, const var &v_tag);
		static tcons1 GetEquivCons(environment env, const var &v);
		static pair<tcons1,tcons1> GetDiffCons(environment env, const var &v);
    };
}

#endif
