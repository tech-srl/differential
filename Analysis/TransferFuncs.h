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
        APAbstractDomain::AnalysisDataTy * analysis_data_ptr_;
        map<Expr*,ExpressionState> expr_map_;
        string current_guard_;
        bool report_;


        ExpressionState GetVarExpression(Expr* node, const QualType type, const string& name);
        ExpressionState ApplyExpressionToState(BinaryOperator *node, const texpr1 &expression);
        void SetGuard(const set<abstract1> &expr_abs, const set<abstract1> &neg_expr_abs);

    public:

        bool tag_; // setting this makes the transformer treat all variables as if they are tagged

        TransferFuncs(APAbstractDomain::AnalysisDataTy& ad, bool reportResults = false) : tag_(false), analysis_data_ptr_(&ad), report_(reportResults), current_guard_("") { }

        ExpressionState VisitDeclRefExpr(DeclRefExpr* node);
        ExpressionState VisitBinaryOperator(BinaryOperator* node);
        ExpressionState VisitUnaryOperator(UnaryOperator* node);
        ExpressionState VisitDeclStmt(DeclStmt* node);
        ExpressionState VisitIntegerLiteral(IntegerLiteral * node);
        ExpressionState VisitCharacterLiteral(CharacterLiteral * node);
        ExpressionState VisitImplicitCastExpr(ImplicitCastExpr * node);
        ExpressionState VisitCallExpr(CallExpr * node);
		ExpressionState VisitParenExpr(ParenExpr *node);
		ExpressionState VisitIfStmt(IfStmt* node);
		ExpressionState VisitConditionVariableInit(Stmt *node);
		void VisitTerminator(CFGBlock* B) { }
		VarDecl*   FindBlockVarDecl(Expr* node);

		State& getVal()  { return state_; }
        State& getNVal() { return nstate_; }
        CFG& getCFG() 	 { return analysis_data_ptr_->getCFG(); }

        static void AssumeTagEquivalence(State &state, const string &name);
		static void AssumeGuardEquivalence(State &state, string name);

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

}

#endif /* CORRELATINGTRANSFORMER_H_ */
