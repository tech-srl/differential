/*
 * Transformer.h
 *
 *  Created on: May 12, 2013
 *      Author: user
 */

#ifndef TRANSFORMER_H_
#define TRANSFORMER_H_

#include "APAbstractDomain.h"

#include <clang/AST/Stmt.h>
#include <clang/Analysis/Visitors/CFGRecStmtVisitor.h>
using namespace clang;

namespace differential {

typedef APAbstractDomain_ValueTypes::ValTy State;

class IterativeTransformer : public CFGStmtVisitor<IterativeTransformer,State> {
private:
	State state_;
	CFG cfg_;
public:
	IterativeTransformer();
	virtual ~IterativeTransformer();

	// These are required if we want to inherit CFGStmtVisitor
	State& getVal() { return state_; }
	CFG& getCFG() { return cfg_; }

	State VisitDeclStmt(DeclStmt* node);
};

}

#endif /* TRANSFORMER_H_ */
