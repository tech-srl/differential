#include "AnalysisUtils.h"
#include "../Defines.h"
#include "../Utils.h"
#include <vector>
#include <sstream>


#define DEBUGNegate 	  	0
#define DEBUGIsEquivalent 	0

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

void AnalysisUtils::JoinExtendEnvironments(manager &mgr, abstract1 &abs1, abstract1 &abs2) {
	environment env = JoinEnvironments(abs1.get_environment(),abs2.get_environment());
	abs1 = abs1.change_environment(mgr,env);
	abs2 = abs2.change_environment(mgr,env);
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
	return ( name.find(Defines::kGuardPrefix) == 0 || name.find(Defines::kTagPrefix + Defines::kGuardPrefix) == 0 );//||
	//name == Defines::kRetGuard || name == (Defines::kTagPrefix + Defines::kRetGuard) );
}

bool AnalysisUtils::IsEquivalent(const abstract1 &abs, const var& v, const var &v_tag) {
	// ignore the array index instrumentation variable
	string name = v;
	if (name.find(Defines::kArrayIndexPostfix) != name.npos) {
		return true;
	}
	manager mgr = abs.get_manager();
	environment env = abs.get_environment();
	if (!env.contains(v) || !env.contains(v_tag)) // if v or v' is not in the environment, equivalence can't hold
		return false;
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
	/*
			if ( !env.contains(v) )
				env = env.add(&v,1,0,0);
			if ( !env.contains(v_tag) )
				env = env.add(&v_tag,1,0,0);
	 */
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
	return result;
}

// check if the given abstract holds equivalence (this is stronger than meeting with equivalence)
bool AnalysisUtils::HoldsEquivalence(const abstract1 &abs) {
	environment env = abs.get_environment();
	vector<var> vars = env.get_vars();
	for ( unsigned i = 0 ; i < vars.size() ; ++i ) {
		string name = vars[i],name_tag;
		Utils::Names(name,name_tag);
		if (!IsEquivalent(abs,name,name_tag))
			return false;
	}
	return true;
}

// check if the given set of abstracts holds equivalence (this is stronger than meeting with equivalence)
bool AnalysisUtils::CheckEquivalence(manager& mgr, const AbstractSet &abstracts, bool with_guards) {
	if (abstracts.size() == 0)
		return false;
	for (AbstractSet::const_iterator iter = abstracts.begin(), end = abstracts.end(); iter != end; ++iter) {
		if (!HoldsEquivalence(iter->vars))
			return false;
		if (with_guards && !HoldsEquivalence(iter->guards))
			return false;
	}
	return true;
}


// Forget all untagged variables in the given abstract state
abstract1 AnalysisUtils::ForgetUntagged(const abstract1 &abs) {
	abstract1 result = abs;
	manager mgr = result.get_manager();
	environment env = result.get_environment();
	vector<var> variables = env.get_vars();
	for ( unsigned i = 0 ; i < variables.size() ; ++i ) {
		string name = variables[i];
		if (name.find(Defines::kTagPrefix) > 0 ) {
			result = result.forget(mgr,variables[i]);
			env = env.remove(&variables[i],1);
		}
	}
	result.change_environment(mgr,env);
	return result;
}


/**
 * Forget all tagged variables in the given abstract state
 */
abstract1 AnalysisUtils::ForgetTagged(const abstract1 &abs) {
	abstract1 result = abs;
	manager mgr = result.get_manager();
	environment env = result.get_environment();
	vector<var> variables = env.get_vars();
	for ( unsigned i = 0 ; i < variables.size() ; ++i ) {
		string name = variables[i];
		if (name.find(Defines::kTagPrefix) == 0 ) {
			result = result.forget(mgr,variables[i]);
			env = env.remove(&variables[i],1);
		}
	}
	result.change_environment(mgr,env);
	return result;
}

/**
 * Forget all initial variables in the given abstract state
 */
abstract1 AnalysisUtils::ForgetInit(const abstract1 &abs) {
	abstract1 result = abs;
	manager mgr = result.get_manager();
	environment env = result.get_environment();
	vector<var> variables = env.get_vars();
	for ( unsigned i = 0 ; i < variables.size() ; ++i ) {
		string name = variables[i];
		if (name.find(Defines::kInitPrefix) == 0 ||
		    name.find(Defines::kTagPrefix + Defines::kInitPrefix) == 0) {
			result = result.forget(mgr,name);
			env = env.remove(&variables[i],1);
		}
	}
	return result;
}

/**
 * Forget all guard variables in the given abstract state
 */
abstract1 AnalysisUtils::ForgetGuards(const abstract1 &abs) {
	abstract1 result = abs;
	manager mgr = result.get_manager();
	environment env = result.get_environment();
	vector<var> variables = env.get_vars();
	for ( unsigned i = 0 ; i < variables.size() ; ++i ) {
		if (AnalysisUtils::IsGuard(variables[i]) ) {
			result = result.forget(mgr,variables[i]);
			env = env.remove(&variables[i],1);
		}
	}
	result.change_environment(mgr,env);
	return result;
}

/**
 * Forget all equivalent variables (v==v') in the given abstract state
 */
abstract1 AnalysisUtils::ForgetEquivalent(const abstract1 &abs) {
	abstract1 result = abs;
	manager mgr = result.get_manager();
	environment env = result.get_environment();
	vector<var> vars = env.get_vars();
	for (size_t i = 0; i < vars.size(); ++i ) {
		string name = vars[i],name_tag;
		Utils::Names(name,name_tag);
		var v(name),v_tag(name_tag);

		// Check for equivalence
		if (AnalysisUtils::IsEquivalent(result,v,v_tag)) {
			result = result.forget(mgr,v);
			result = result.forget(mgr,v_tag);
			env = env.remove(&v,1);
			env = env.remove(&v_tag,1);
		}
	}
	result.change_environment(mgr,env);
	return result;
}


/**
 * Forget all unconstrained variables (v==v') in the given abstract state and environment.
 */
abstract1 AnalysisUtils::ForgetUnconstrained(const abstract1 &abs) {
	abstract1 result = abs;
	manager mgr = result.get_manager();
	environment env = result.get_environment();
	vector<var> vars = env.get_vars();
	for (size_t i = 0; i < vars.size(); ++i ) {
		if (result.is_variable_unconstrained(mgr,vars[i])) {
			result = result.forget(mgr,vars[i]);
			env = env.remove(&vars[i],1);
		}
	}
	result.change_environment(mgr,env);
	return result;
}

/**
 * Forget all variables that were removed by the patch (i.e. don't have a tagged version)
 * or were added by the patch (i.e. don't have an untagged version). This includes guards.
 */
abstract1 AnalysisUtils::ForgetUnmatched(const abstract1 &abs) {
	abstract1 result = abs;
	manager mgr = result.get_manager();
	environment env = result.get_environment();
#if (DEBUGForgetUnmatched)
	//cerr << "Got " << result << endl;
	//cerr << "Env = " << env << endl;
#endif
	vector<var> vars = env.get_vars();
	for (size_t i = 0; i < vars.size(); ++i ) {
		string name = vars[i],name_tag;
		Utils::Names(name,name_tag);
		var v(name),v_tag(name_tag);

		if (!env.contains(v)) {
			result = result.forget(mgr,v_tag);
			env = env.remove(&v_tag,1);
#if (DEBUGForgetUnmatched)
			cerr << "Forgetting " << v_tag << endl;
#endif
		} else if (!env.contains(v_tag)) {
			result = result.forget(mgr,v);
			env = env.remove(&v,1);
#if (DEBUGForgetUnmatched)
			cerr << "Forgetting " << v << endl;
#endif
		}
	}
	result.change_environment(mgr,env);
#if (DEBUGForgetUnmatched)
//cerr << "Done. Result = " << result << endl << "Env = " << result.get_environment();
#endif
	return result;
}


set<abstract1> AnalysisUtils::NegateAbstract(manager &mgr, abstract1 &tau_i) {
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

set<abstract1> AnalysisUtils::CrossConjunct(manager &mgr, const set<abstract1> &abs_set1, const set<abstract1> &abs_set2) {
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

set<abstract1> AnalysisUtils::CrossConjunctAbstracts(manager &mgr, vector<set<abstract1> > negated_tau) {
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


set<abstract1> AnalysisUtils::MinimizeResult(manager &mgr, vector<abstract1> &result) {
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



}
