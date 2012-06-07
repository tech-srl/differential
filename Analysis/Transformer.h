#ifndef TRANSFORMER_H
#define TRANSFORMER_H

namespace differential {

    struct Expression {
       texpr1 * expression_ptr;
       Expression(): expression_ptr(0) {
          expression_ptr = new texpr1(texpr1::builder(environment(),top()));
       }
       Expression(const Expression& expression) : expression_ptr(0) {
          if ( expression.expression_ptr ) expression_ptr = new texpr1(*expression.expression_ptr);
       }
       Expression& operator=(const Expression& expression_or_constraint) {
          expression_ptr = (expression_or_constraint.expression_ptr) ? new texpr1(*expression_or_constraint.expression_ptr) : 0;
          return *this;
       }

       void setExpression(const texpr1& expression) {
          delete expression_ptr; 
          expression_ptr = new texpr1(expression);
       }

       operator texpr1() {
          return *expression_ptr;
       }

       friend ostream& operator<<(ostream& os, const Expression& expression);
       ~Expression() {
          delete expression_ptr;
       }
    };


    class TransferFuncs : public CFGStmtVisitor<TransferFuncs,Expression> {

       typedef APAbstractDomain::ValTy::AbstractRefSet AbstractRefSet;

       APAbstractDomain::ValTy State, NState;
       APAbstractDomain::AnalysisDataTy& AD;
       map<Expr*,Expression> expr_map_;
       map<Expr*,pair<APAbstractDomain::ValTy,APAbstractDomain::ValTy> > state_map_;
       map<string,pair<APAbstractDomain::ValTy,APAbstractDomain::ValTy> > guard_map_;
       string current_guard_;
       bool report_;

       Expression GetVarExpression(Expr* node, const Type * type, const string& name);
       Expression ApplyExpressionToState(BinaryOperator *B, const texpr1 &expression);
       abstract1 AbsFromConstraint(const tcons1 &cons) const;


    public:

       static const texpr1 kOne, kZero;

       TransferFuncs(APAbstractDomain::AnalysisDataTy& ad, bool reportResults = false) : 
           AD(ad), report_(reportResults), current_guard_("") { }

       APAbstractDomain::ValTy& getVal() {
          return State;
       }

       APAbstractDomain::ValTy& getNVal() {
          return NState;
       }

       CFG& getCFG() {
          return AD.getCFG();
       }

       void SetTopValue(APAbstractDomain::ValTy& V) {
          V.setValues(AD);
       }

       typedef CFGStmtVisitor<TransferFuncs,Expression> BaseStmtVisitor;

       using BaseStmtVisitor::Visit;

       Expression VisitDeclRefExpr(DeclRefExpr* DR);
       Expression VisitBinaryOperator(BinaryOperator* B);
       Expression VisitUnaryOperator(UnaryOperator* U);
       Expression VisitDeclStmt(DeclStmt* D);
       Expression VisitIntegerLiteral(IntegerLiteral * IL);
       Expression VisitImplicitCastExpr(ImplicitCastExpr * node);
       Expression VisitArraySubscriptExpr(ArraySubscriptExpr *node);
       Expression VisitReturnStmt(ReturnStmt * S);
       Expression VisitCallExpr(CallExpr * node);
       Expression VisitMemberExpr(MemberExpr * node);
       void VisitTerminator(CFGBlock* B) {
       } 
    };

}

#endif
