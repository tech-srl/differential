/*
 * CorrelatingTransformer.h
 *
 *  Created on: May 13, 2013
 *      Author: user
 */

#ifndef CORRELATINGTRANSFORMER_H_
#define CORRELATINGTRANSFORMER_H_

#include <map>
#include <iostream>
#include <cstdio>
using namespace std;

#include <clang/Basic/SourceManager.h>
#include <clang/Analysis/Visitors/CFGRecStmtDeclVisitor.h>
#include <clang/AST/DeclVisitor.h>
#include <clang/Analysis/AnalysisDiagnostic.h>
#include <clang/AST/ASTContext.h>
#include <clang/Analysis/FlowSensitive/DataflowSolver.h>
#include <llvm/ADT/SmallPtrSet.h>
using namespace clang;

#include "APAbstractDomain.h"
#include "../Defines.h"
#include "../Utils.h"

namespace differential {

typedef APAbstractDomain::ValTy State;
typedef apron::texpr1 Expression;

struct ExpressionState;

class TransferFuncs : public CFGStmtVisitor<TransferFuncs,ExpressionState> {

        State state_, nstate_;
        APAbstractDomain::AnalysisDataTy& AD;
        map<Expr*,ExpressionState> expr_map_;
        string current_guard_;
        bool report_;


        ExpressionState GetVarExpression(Expr* node, const QualType type, const string& name);
        ExpressionState ApplyExpressionToState(BinaryOperator *node, const texpr1 &expression);
        void SetGuard(const set<abstract1> &expr_abs, const set<abstract1> &neg_expr_abs);

    public:

        bool tag_; // setting this makes the transformer treat all variables as if they are tagged

        TransferFuncs(APAbstractDomain::AnalysisDataTy& ad, bool reportResults = false) : tag_(false), AD(ad), report_(reportResults), current_guard_("") { }

        typedef CFGStmtVisitor<TransferFuncs,ExpressionState> BaseStmtVisitor;
        //using BaseStmtVisitor::Visit;

        ExpressionState VisitDeclRefExpr(DeclRefExpr* node);
        ExpressionState VisitBinaryOperator(BinaryOperator* node);
        ExpressionState VisitUnaryOperator(UnaryOperator* node);
        ExpressionState VisitDeclStmt(DeclStmt* node);
        ExpressionState VisitIntegerLiteral(IntegerLiteral * node);
        ExpressionState VisitImplicitCastExpr(ImplicitCastExpr * node);
        ExpressionState VisitCallExpr(CallExpr * node);
		ExpressionState VisitParenExpr(ParenExpr *node);
		void VisitTerminator(CFGBlock* B) { }
		VarDecl*   FindBlockVarDecl(Expr* node);

		State& getVal()  { return state_; }
        State& getNVal() { return nstate_; }
        CFG& getCFG() 	 { return AD.getCFG(); }

        void AssumeTagEquivalence(environment &env, const string &name);
		void AssumeGuardEquivalence(environment &env, string name);

    };

struct ExpressionState {
    Expression e_;
	State s_, ns_;

    ExpressionState() : e_(texpr1::builder(environment(),top())) {   }

	 ExpressionState(const ExpressionState& rhs) :e_(rhs.e_), s_(rhs.s_), ns_(rhs.ns_) { }

    ExpressionState& operator=(const ExpressionState& rhs) {
        e_ = rhs.e_;
		s_ = rhs.s_;
		ns_ = rhs.ns_;
        return *this;
    }

	ExpressionState(const Expression& rhs) : e_(rhs) {  }

    operator Expression() const {
        return e_;
    }

    friend ostream& operator<<(ostream& os, const ExpressionState &es);
    virtual ~ExpressionState() { }
};

ostream& operator<<(ostream& os, const ExpressionState &es);

}

#endif /* CORRELATINGTRANSFORMER_H_ */
