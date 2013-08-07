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

	bool operator<(const Abstract2& left) const { return vars.key()+guards.key() < left.vars.key()+left.guards.key(); }
	bool operator>(const Abstract2& left) const { return vars.key()+guards.key() > left.vars.key()+left.guards.key(); }

	friend ostream& operator<<(ostream& os, const Abstract2& abstract ) {
		os << abstract.guards << " <-> " << abstract.vars;
		return os;
	}

};

}

#endif // ABSTRACT2_H
