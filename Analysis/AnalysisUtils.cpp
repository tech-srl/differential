#include "AnalysisUtils.h"
#include "../Defines.h"
#include "../Utils.h"
#include <vector>
#include <sstream>


#define DEBUGNegate 0

namespace differential {

const texpr1 AnalysisUtils::kOne = texpr1::builder(environment(),1);
const texpr1 AnalysisUtils::kZero = texpr1::builder(environment(),0);

AnalysisUtils::AbstractDictionary AnalysisUtils::abstract_dictionary;

abstract1 AnalysisUtils::AbsFromConstraint(manager &mgr, const tcons1 &cons) {
    tcons1_array cons_arr(1,&cons);
    abstract1 abs(mgr,cons_arr);
    return abs;
}

environment AnalysisUtils::JoinEnvironments(const environment &env1, const environment &env2) {
    if (env1 == env2) 
        return env1;
    environment result = env1;
    const vector<var> variables = env2.get_vars();
    for ( unsigned i = 0 ; i < variables.size(); i++ ) {
        if ( !result.contains(variables[i]) ) {
            result = result.add(&variables[i],1,0,0);
        }
    }
    return result;
}

	void AnalysisUtils::NegateConstraint(manager &mgr, tcons1 constraint, set<abstract1> &result) {
#if (DEBUGNegate)
		cerr << "Negating: " << AnalysisUtils::AbsFromConstraint(mgr,constraint);
#endif
		environment env = constraint.get_environment();
		if (AnalysisUtils::AbsFromConstraint(mgr,constraint).is_bottom(mgr)) {
			result.insert(abstract1(mgr,env,apron::top()));
			return;
		}

		// first take care of guards
		vector<var> vars = env.get_vars();
		for (size_t i = 0 ; i < vars.size(); ++i) {
			string name = vars[i];
			if (name.find(Defines::kGuardPrefix) == 0) { // check if this is a guard constraint
				abstract1 abs = AbsFromConstraint(mgr,constraint),
						  neg_abs = AbsFromConstraint(mgr,tcons1(texpr1(env,vars[i]) == AnalysisUtils::kOne));
				if ((abs *= neg_abs).is_bottom(mgr)) { // G == 0
					result.insert(neg_abs);
#if (DEBUGNegate)
					cerr << " Result: " << neg_abs << endl;
#endif
					return;
				}
				abs = AbsFromConstraint(mgr,constraint);
				neg_abs = AbsFromConstraint(mgr,tcons1(texpr1(env,vars[i]) == AnalysisUtils::kZero));
				if ((abs *= neg_abs).is_bottom(mgr)) { // G == 1
					result.insert(neg_abs);
#if (DEBUGNegate)
					cerr << " Result: " << neg_abs << endl;
#endif
					return;
				}
			}
		}

		texpr1 expr = constraint.get_texpr();

		if ( constraint.get_constyp()==AP_CONS_EQ || constraint.get_constyp()==AP_CONS_DISEQ ) {
				// Turn == into != and vice versa
				if ( constraint.get_constyp()==AP_CONS_EQ ) {
					// Negate X == Y by creating the X > Y or X < Y states
					// X - Y == 0 --> X - Y >= 1
					tcons1 greater_than_cons(expr >= AnalysisUtils::kOne);
					abstract1 greater_than_abs = AbsFromConstraint(mgr,greater_than_cons);
					result.insert(greater_than_abs);
					// X - Y == 0 --> -X + Y >= 1
					tcons1 smaller_than_cons(-expr >= AnalysisUtils::kOne);
					abstract1 smaller_than_abs = AbsFromConstraint(mgr,smaller_than_cons);
					result.insert(smaller_than_abs);
#if (DEBUGNegate)
					cerr << " Result: " << greater_than_abs << " , " << smaller_than_abs << endl;
#endif
				} else {
					constraint.get_constyp() = AP_CONS_EQ;
					abstract1 negated_abs = AbsFromConstraint(mgr, constraint);
					result.insert(negated_abs);
#if (DEBUGNegate)
					cerr << " Result: " << negated_abs << endl;
#endif
				}
			} else {
				// E >= 0 --> E <= -1.
				tcons1 negated_cons(-expr >= AnalysisUtils::kOne);
				abstract1 negated_abs = AbsFromConstraint(mgr,negated_cons);
				result.insert(negated_abs);
#if (DEBUGNegate)
				cerr << " Result: " << negated_abs<< endl;
#endif
			}
	}
	
	const abstract1 * AnalysisUtils::AddAbstractToAll(const abstract1 & abs) {
			/*
			set<string> abs_identifier;
			stringstream env_ss;
			env_ss << abs.get_environment();
			string env_str = env_ss.str();
			stringstream abs_ss;
			abs_ss << abs;
			string abs_str = abs_ss.str();
			// an asbtract is uniquly defined by the set of string representing it's variables and it's constrains
			while (env_str.size() > 0) {
				size_t start = env_str.find(" ") + 1, end = env_str.find(" ", start);
				if (start == env_str.npos || end == env_str.npos )
					break;
				string var_name = env_str.substr(start, end);
				abs_identifier.insert(var_name);
				env_str = env_str.substr(env_str.find("\n"));
			}

			while (abs_str.size() > 0) {
				size_t start = abs_str.find(" ") + 1, end = abs_str.find(";", start);
				if (start == abs_str.npos || end == abs_str.npos )
					break;
				string cons = abs_str.substr(start, end);
				abs_identifier.insert(cons);
				abs_str = abs_str.substr(end);
			}
			
			if (abstract_dictionary.find(abs_identifier) == abstract_dictionary.end()) {
				abstract_dictionary[abs_identifier] = new abstract1(abs);
			}
			return abstract_dictionary[abs_identifier];
			
			*/
			stringstream ss;
			ss << abs.get_environment() << abs;
			string str = ss.str();
			if (abstract_dictionary.find(str) == abstract_dictionary.end()) {
				abstract_dictionary[str] = new abstract1(abs);
			}
			return abstract_dictionary[str];
		}	
			
		
		pair<const abstract1 *, const abstract1 *> AnalysisUtils::JoinAbstracts(manager& mgr, const AbstractRefSet  &abstracts) {
			abstract1 joined_abs(mgr,environment(),apron::bottom()), joined_guards(mgr,environment(),apron::bottom());
			for ( AbstractRefSet::const_iterator iter = abstracts.begin(), end = abstracts.end(); iter != end; ++iter ) {
				abstract1 abs = *(iter->first), guards = *(iter->second);
				environment env = AnalysisUtils::JoinEnvironments(joined_abs.get_environment(),abs.get_environment());
				abs.change_environment(mgr,env);
				joined_abs.change_environment(mgr,env);
				joined_abs.join(mgr, abs);
				environment guard_env = AnalysisUtils::JoinEnvironments(joined_guards.get_environment(),guards.get_environment());
				guards.change_environment(mgr,guard_env);
				joined_guards.change_environment(mgr,guard_env);
				joined_guards.join(mgr, guards);
			}
			return make_pair(AddAbstractToAll(joined_abs),AddAbstractToAll(joined_guards));
		}

		bool AnalysisUtils::IsGuard(const var &v) {
			string name = v;
			return ( name.find(Defines::kGuardPrefix) == 0 || name.find(Defines::kTagPrefix + Defines::kGuardPrefix) == 0 );
		}
		bool AnalysisUtils::IsEquivalent(const abstract1 &abs, const var& v, const var &v_tag) {
			manager mgr = abs.get_manager();
			environment env = abs.get_environment();
			texpr1 v_expr(env,v), v_tag_expr(env,v_tag);
			pair<tcons1,tcons1> diff_cons = GetDiffCons(env,v);
			tcons1_array v_greater_arr(1,&(diff_cons.first));
			abstract1 meet_greater = abs;
			tcons1_array v_lower_arr(1,&(diff_cons.first));
			abstract1 meet_lower = abs;
			return (meet_greater.meet(mgr,v_greater_arr).is_bottom(mgr) && meet_lower.meet(mgr,v_lower_arr).is_bottom(mgr));
		}

		tcons1 AnalysisUtils::GetEquivCons(environment env, const var &v0) {
			string name = v0;
			string tagged_name;
			Utils::Names(name,tagged_name);
			var v(name),v_tag(tagged_name);
			if ( !env.contains(v) )
				env = env.add(&v,1,0,0);
			if ( !env.contains(v_tag) )
				env = env.add(&v_tag,1,0,0);
			return tcons1(texpr1(env,v) == texpr1(env,v_tag));
		}

		pair<tcons1,tcons1> AnalysisUtils::GetDiffCons(environment env, const var &v0) {
			string name = v0;
			string tagged_name;
			Utils::Names(name,tagged_name);
			var v(name),v_tag(tagged_name);
			if ( !env.contains(v) )
				env = env.add(&v,1,0,0);
			if ( !env.contains(v_tag) )
				env = env.add(&v_tag,1,0,0);
			texpr1 v_expr(env,v), v_tag_expr(env,v_tag);
			tcons1 v_greater(v_expr >= v_tag_expr + kOne);
			tcons1 v_lower(v_expr <= v_tag_expr - kOne);
			return make_pair(v_lower,v_greater);
		}



}
