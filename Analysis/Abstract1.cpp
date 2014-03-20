#include "Abstract1.h"

#include "../Utils.h"
#include "../Defines.h"

#include <set>
#include <sstream>


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

#define DEBUGKey 0
/**
 * the key is essentially the set of constraints of the abstracts, in string form.
 * this is the best way to uniquely define an abstract
 */
string Abstract1::key() const {

	if (abstract_ptr_ == NULL) {
		return "";
	}
	manager mgr = abstract_ptr_->get_manager();
	if (abstract_ptr_->is_top(mgr)) {
		return "top";
	}
	if (abstract_ptr_->is_bottom(mgr)) {
		return "bottom";
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

Abstract1::operator string() const {
		stringstream ss;
		if (abstract_ptr_) {
			ss << *abstract_ptr_;
		}
		manager mgr = abstract_ptr_->get_manager();
		if (abstract_ptr_ && !abstract_ptr_->is_top(mgr) && !abstract_ptr_->is_bottom(mgr)) { // if not top or bottom
			// make the abstract more readable
			const size_t tag_prefix_size = Defines::kTagPrefix.size();
			vector<string> splitted = Utils::Split(ss.str().substr(1),';');
			stringstream splitted_ss, equiv_ss;
			splitted_ss << "{";
			equiv_ss << "=(";
			for (int i = 0 ; i < splitted.size() - 1 ; ++i) {
				// try and see if the constraint is of T_varname - 1varname = 0
				size_t minus_pos = splitted[i].find('-');
				if (minus_pos != splitted[i].npos) {
					string var = splitted[i].substr(tag_prefix_size + 1,minus_pos - (tag_prefix_size + 1) - 1);
					string second_var = splitted[i].substr(minus_pos + tag_prefix_size + 1,var.size());
					if (var == second_var) {
						equiv_ss << var << ","; // if so, print a shorthand version of it
						continue;
					}
				}
				splitted_ss << splitted[i] << "\n";
			}
			equiv_ss << ")";
			splitted_ss << "}";
			// replace T_ prefix with ' postfix
			return equiv_ss.str() + Utils::ReplaceTagPrefix(splitted_ss.str());
//			return equiv_ss.str() + splitted_ss.str();
		}
		return ss.str();
	}

}
