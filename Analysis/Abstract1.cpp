#include "Abstract1.h"

#include <set>
#include <sstream>

#define DEBUGKey 0

namespace differential
{

map<string,const abstract1*> Abstract1::abstract_dictionary;

Abstract1 Abstract1::AddAbstractToAll(const abstract1 &abstract) {
	/**
	 * look for an abstract that looks like the input in the dictionary by creating an Abstract1 from it
	 * and using it to search the map (Abstract1's < and > operators actually use the inner abstract for comparing
	 */
	string key = Abstract1(&abstract).key();
	if (abstract_dictionary.find(key) == abstract_dictionary.end()) {
		abstract_dictionary[key] = new abstract1(abstract);
	}
	return abstract_dictionary[key];
}

/**
 * the key is essentially the set of constraints of the abstracts, in string form.
 * this is the best way to uniquely define an abstract
 */
string Abstract1::key() const {
	if (abstract_ptr_ == NULL) {
		return "";
	}
	set<string> abs_identifier;
	stringstream env_ss;
	env_ss << abstract_ptr_->get_environment();
	string env_str = env_ss.str();
	stringstream abs_ss;
	abs_ss << *abstract_ptr_;
	string abs_str = abs_ss.str();
#if (DEBUGKey)
	cerr << "Env = " << env_str << "\nAbs = " << abs_str << endl;
#endif
	// an asbtract is uniquly defined by the set of string representing it's variables and it's constrains
	size_t start = env_str.find(" "), end = env_str.find(")", start);
	while (start != env_str.npos && end != abs_str.npos)  {
		string var_name = env_str.substr(start + 1, end - start);
#if (DEBUGKey)
		cerr << "Inserting var " << var_name << endl;
#endif
		abs_identifier.insert(var_name);
		start = env_str.find(" ",end), end = env_str.find(")", start);
	}

	start = abs_str.find(" "), end = abs_str.find(";", start);
	while (start != abs_str.npos && end != abs_str.npos) {
		string cons = abs_str.substr(start + 1, end - start - 1);
#if (DEBUGKey)
		cerr << "Inserting constraint " << cons << endl;
#endif
		abs_identifier.insert(cons);
		start = abs_str.find(" ",end), end = abs_str.find(";", start);
	}
	stringstream result;
	for (set<string>::const_iterator iter = abs_identifier.begin(), end = abs_identifier.end(); iter != end; ) {
		result << *iter;
		if (++iter != end)
			result << ";";
	}
#if (DEBUGKey)
	cerr << "Result = " << result.str() << endl;
#endif
	return result.str();
}

}
