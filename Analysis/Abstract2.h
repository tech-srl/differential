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

	bool operator<(const Abstract2& left) const {
		assert(vars.abstract() && left.vars.abstract());
		environment env = vars.abstract()->get_environment();
		if (env != left.vars.abstract()->get_environment()) {
			vector<var> vv = left.vars.abstract()->get_environment().get_vars();
			for (int i = 0;i < vv.size();++i)
				if (!env.contains(vv[i]))
					env.add(&vv[i],1,0,0);
			manager mgr = vars.abstract()->get_manager();
			abstract1 abs1 = *vars.abstract(), abs2 = *left.vars.abstract();
			abs1 = abs1.change_environment(mgr,env);
			abs2 = abs2.change_environment(mgr,env);
			return (abs1 < abs2);
		}
		return *vars.abstract() < *left.vars.abstract();
	}
	/*
	bool operator<(const Abstract2& left) const { return vars.key()+guards.key() < left.vars.key()+left.guards.key(); }
	bool operator>(const Abstract2& left) const { return vars.key()+guards.key() > left.vars.key()+left.guards.key(); }
	*/
	friend ostream& operator<<(ostream& os, const Abstract2& abstract ) {
		os << abstract.guards << " <-> " << abstract.vars;
		return os;
	}

};

}

#endif // ABSTRACT2_H
