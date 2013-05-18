/*
 * Transformer.cpp
 *
 *  Created on: May 12, 2013
 *      Author: user
 */

#include "IterativeTransformer.h"

#include <iostream>
using namespace std;

namespace differential {

IterativeTransformer::IterativeTransformer() {
	// TODO Auto-generated constructor stub

}

IterativeTransformer::~IterativeTransformer() {
	// TODO Auto-generated destructor stub
}

State IterativeTransformer::VisitDeclStmt(DeclStmt* node) {
	cerr << "Applying:\n";
	node->dump();
	cerr << "\nto:\n";
	state_.print();
	cerr << "\n";
	return state_;
}

}

