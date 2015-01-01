#ifndef ABSTRACT2_H
#define ABSTRACT2_H

#include <algorithm>
using namespace std;

#include "Abstract1.h"

namespace differential
{

struct Abstract2 {

	// the abstract is a pair <Vars,Guards>
	Abstract1 vars;
	Abstract1 guards;

	Abstract2() { }
	Abstract2(const Abstract1 &_vars,const Abstract1 &_guards) : vars(_vars), guards(_guards) { }
	virtual ~Abstract2() { }

	bool operator<(const Abstract2& right) const {
		assert(vars.abstract() && right.vars.abstract());
		environment vars_env = vars.abstract()->get_environment();
		environment guards_env = guards.abstract()->get_environment();
		abstract1 vars_abs1 = *vars.abstract(), vars_abs2 = *right.vars.abstract();
		abstract1 guards_abs1 = *guards.abstract(), guards_abs2 = *right.guards.abstract();
		if (vars_env != right.vars.abstract()->get_environment()) {
			vector<var> vv = right.vars.abstract()->get_environment().get_vars();
			for (int i = 0;i < vv.size();++i)
				if (!vars_env.contains(vv[i]))
					vars_env.add(&vv[i],1,0,0);
			manager mgr = vars.abstract()->get_manager();
			vars_abs1 = vars_abs1.change_environment(mgr,vars_env);
			vars_abs2 = vars_abs2.change_environment(mgr,vars_env);
		}
		if (guards_env != right.guards.abstract()->get_environment()) {
			vector<var> vv = right.guards.abstract()->get_environment().get_vars();
			for (int i = 0;i < vv.size();++i)
				if (!guards_env.contains(vv[i]))
					guards_env.add(&vv[i],1,0,0);
			manager mgr = guards.abstract()->get_manager();
			guards_abs1 = guards_abs1.change_environment(mgr,guards_env);
			guards_abs2 = guards_abs2.change_environment(mgr,guards_env);
		}

		return ((vars_abs1 < vars_abs2) || (!(vars_abs1 > vars_abs2) && guards_abs1 < guards_abs2));
	}

	friend ostream& operator<<(ostream& os, const Abstract2& abstract ) {
		os << abstract.guards << " <-> " << abstract.vars;
		return os;
	}

};

}

#endif // ABSTRACT2_H
