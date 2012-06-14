#include "AnalysisUtils.h"
#include "../Defines.h"
#include "../Utils.h"
#include <vector>
#include <sstream>


#define DEBUGNegate 1
#define DEBUGIsEquivalent 0

namespace differential {

const texpr1 AnalysisUtils::kOne = texpr1::builder(environment(),1);
const texpr1 AnalysisUtils::kZero = texpr1::builder(environment(),0);

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

		/* we cannot assume that guard constraints are always of the sort G == 1
		// first take care of guards
		vector<var> vars = env.get_vars();
		for (size_t i = 0 ; i < vars.size(); ++i) {
			if (IsGuard(vars[i])) { // check if this is a guard constraint
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
		*/

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
		
		Abstract2 AnalysisUtils::JoinAbstracts(manager& mgr, const AbstractSet  &abstracts) {
			abstract1 joined_vars(mgr,environment(),apron::bottom()), joined_guards(mgr,environment(),apron::bottom());
			for ( AbstractSet::const_iterator iter = abstracts.begin(), end = abstracts.end(); iter != end; ++iter ) {
				abstract1 vars = iter->vars, guards = iter->guards;
				environment env = AnalysisUtils::JoinEnvironments(joined_vars.get_environment(),vars.get_environment());
				vars.change_environment(mgr,env);
				joined_vars.change_environment(mgr,env);
				joined_vars.join(mgr, vars);
				environment guard_env = AnalysisUtils::JoinEnvironments(joined_guards.get_environment(),guards.get_environment());
				guards.change_environment(mgr,guard_env);
				joined_guards.change_environment(mgr,guard_env);
				joined_guards.join(mgr, guards);
			}
			return Abstract2(joined_vars,joined_guards);
		}

		bool AnalysisUtils::IsGuard(const var &v) {
			string name = v;
			return ( name.find(Defines::kGuardPrefix) == 0 || name.find(Defines::kTagPrefix + Defines::kGuardPrefix) == 0 ||
					 name == Defines::kRetGuard || name == (Defines::kTagPrefix + Defines::kRetGuard) );
		}

		bool AnalysisUtils::IsEquivalent(const abstract1 &abs, const var& v, const var &v_tag) {
			manager mgr = abs.get_manager();
			environment env = abs.get_environment();
			texpr1 v_expr(env,v), v_tag_expr(env,v_tag);
			pair<tcons1,tcons1> diff_cons = GetDiffCons(env,v);
			tcons1_array v_greater_arr(1,&(diff_cons.first));
			abstract1 meet_greater = abs;
			meet_greater.change_environment(mgr,env);
			meet_greater.meet(mgr,v_greater_arr);
			tcons1_array v_lower_arr(1,&(diff_cons.second));
			abstract1 meet_lower = abs;
			meet_lower.change_environment(mgr,env);
			meet_lower.meet(mgr,v_lower_arr);
#if (DEBUGIsEquivalent)
			cerr << abs << " /\\ (" << v << " == " << v_tag << ")? : " << (meet_greater.is_bottom(mgr) && meet_lower.is_bottom(mgr)) << endl;
#endif
			return (meet_greater.is_bottom(mgr) && meet_lower.is_bottom(mgr));
		}

		tcons1 AnalysisUtils::GetEquivCons(environment &env, const var &v0) {
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

		pair<tcons1,tcons1> AnalysisUtils::GetDiffCons(environment &env, const var &v0) {
			string name = v0;
			string tagged_name;
			Utils::Names(name,tagged_name);
			var v(name),v_tag(tagged_name);
			if ( !env.contains(v) )
				env = env.add(&v,1,0,0);
			if ( !env.contains(v_tag) )
				env = env.add(&v_tag,1,0,0);
			texpr1 v_expr(env,v), v_tag_expr(env,v_tag);
			// the diff cons for guards is (g == g' - 1) || (g == g' + 1)
			if (IsGuard(v) && IsGuard(v_tag)) {
				tcons1 v_greater(v_expr == v_tag_expr + kOne);
				tcons1 v_lower(v_expr == v_tag_expr - kOne);
				return make_pair(v_lower,v_greater);
			} else {
				tcons1 v_greater(v_expr >= v_tag_expr + kOne);
				tcons1 v_lower(v_expr <= v_tag_expr - kOne);
				return make_pair(v_lower,v_greater);
			}
		}

		// Meet the given abstract with the (V == V') constraint
		abstract1 AnalysisUtils::MeetEquivalence(manager &mgr, const abstract1 &abs) {
			//abs.change_environment(mgr,env);
			abstract1 result = abs;
			environment env = result.get_environment();
			vector<var> vars = env.get_vars();
			for ( unsigned i = 0 ; i < vars.size() ; ++i ) {
				string name = vars[i],name_tag;
				Utils::Names(name,name_tag);
				// (V == V')
				tcons1 v_equal = GetEquivCons(env,name);
				result.change_environment(mgr,JoinEnvironments(env,v_equal.get_environment()));
				result.meet(mgr,tcons1_array(1,&v_equal));
			}
		}



}
