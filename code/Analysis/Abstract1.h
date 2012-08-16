#ifndef ABSTRACT1_H
#define ABSTRACT1_H

#include <ostream>
#include <map>
#include <string>
using namespace std;

#include "apronxx/apronxx.hh"
using namespace apron;

namespace differential {

class Abstract1 {

	// To avoid duplication of memory consuming abstracts, we keep them all in one global map
	// which maps the string print-out of the state to the state itself (this is the best way to truly avoid duplication)
	static map<string,const abstract1*> abstract_dictionary;
	static Abstract1 AddAbstractToAll(const abstract1 &abstract);

	const abstract1 * abstract_ptr_;

public:

	Abstract1() : abstract_ptr_(0) { }
	Abstract1(const abstract1 *abstract_ptr) : abstract_ptr_(abstract_ptr) { }
	Abstract1(const abstract1 &abstract) { *this = AddAbstractToAll(abstract); }
	virtual ~Abstract1() { }

	operator abstract1() const { return abstract() ; }
	abstract1 abstract() const { assert(abstract_ptr_); return *abstract_ptr_; }

	// for stl containers
	string key() const;
	bool operator<(const Abstract1& left) const { return key() < left.key(); }
	bool operator>(const Abstract1& left) const { return key() > left.key(); }

	friend ostream& operator<<(ostream& os, const Abstract1& abstract ) {
		os << *abstract.abstract_ptr_;
		return os;
	}

};

}

#endif // ABSTRACT1_H
