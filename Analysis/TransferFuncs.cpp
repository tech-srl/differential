/*
 * CorrelatingTransformer.cpp
 *
 *  Created on: May 13, 2013
 *      Author: user
 */

#include "TransferFuncs.h"

#include <iostream>
using namespace std;

#define DEBUG		0
#define DEBUGCons   0
#define DEBUGExp    0
#define DEBUGGuard  0

//===----------------------------------------------------------------------===//
// Transfer functions.
//===----------------------------------------------------------------------===//

namespace differential {

ostream& operator<<(ostream& os, const ExpressionState &es){
	os << "<**--\nExpression = " << es.e_  << "\nState = " << es.s_ << "\nNState = " << es.ns_ << "\n--**>";
	return os;
}

void TransferFuncs::AssumeTagEquivalence(State &state, const string &name){
	tcons1 equal_cons = AnalysisUtils::GetEquivCons(state.env_,name);
	state &= equal_cons;
}

// forget all guard information and assume equivalence.
void TransferFuncs::AssumeGuardEquivalence(State &state, string name){
	string tagged_name;
	Utils::Names(name,tagged_name);
	tcons1 equal_cons = AnalysisUtils::GetEquivCons(state.env_,name);
	state.Forget(name);
	state.Forget(tagged_name);
	state &= equal_cons;
}

ExpressionState TransferFuncs::VisitDeclRefExpr(DeclRefExpr* node) {
	ExpressionState result;
	if ( VarDecl* decl = dyn_cast<VarDecl>(node->getDecl()) ) {
		const Type * type = decl->getType().getTypePtr();
		if (type->isIntegerType() || (type->isPointerType() && type->getPointeeType()->isIntegerType())) {
			stringstream name;
			name << (tag_ ? Defines::kTagPrefix : "") << decl->getNameAsString();
			var v(name.str());
			result = texpr1(environment().add(&v,1,0,0),v);
		}
	}
	expr_map_[node] = result;
	return result;
}

ExpressionState TransferFuncs::VisitCallExpr(CallExpr *node) {
	ExpressionState result;
	if ( node->getCallReturnType().getTypePtr()->isIntegerType() ) {
		string call;
		raw_string_ostream call_os(call);
		call_os << (tag_ ? Defines::kTagPrefix : "");
		node->printPretty(call_os,analysis_data_ptr_->getContext(),0, PrintingPolicy(LangOptions()));
		string call_str = Utils::ReplaceAll(call_os.str()," ",""); // remove spaces from call string
		var v(call_str);
		environment env;
		result = texpr1(env.add(&v,1,0,0),v);
		// assume the value of the function call is the same in both versions (TODO: this may not always be the case)
		AssumeTagEquivalence(state_,call_str);
		AssumeTagEquivalence(nstate_,call_str);
	}
	expr_map_[node] = result;
	return result;
}

ExpressionState TransferFuncs::VisitParenExpr(ParenExpr *node) {
	return expr_map_[node] = BlockStmt_Visit(node->getSubExpr());
}

#define DEBUGVisitImplicitCastExpr 0
ExpressionState TransferFuncs::VisitImplicitCastExpr(ImplicitCastExpr * node) {
#if (DEBUGVisitImplicitCastExpr)
	cerr << "TransferFuncs::VisitImplicitCastExpr(";
	node->dump();
	cerr << "):\n";
#endif
	BlockStmt_Visit(node->getSubExpr());
	ExpressionState result = expr_map_[node->getSubExpr()];
	if (isa<IntegerLiteral>(node->getSubExpr())) {
		return expr_map_[node] = result;
	}
	string name;
	raw_string_ostream name_os(name);
	name_os << (tag_ ? Defines::kTagPrefix : "");
	node->printPretty(name_os,analysis_data_ptr_->getContext(),0, PrintingPolicy(LangOptions()));
#if (DEBUGVisitImplicitCastExpr)
	cerr << "Encountered: " << name_os.str() << "\n";
#endif
	if (node->getCastKind() == CK_IntegralToBoolean) {
		environment env = result.e_.get_environment();
		VarDecl * decl = FindBlockVarDecl(node);
		if (decl && decl->getType().getAsString() == Defines::kGuardType) { // if (guard)
			// nstate should only matter in VisitImplicitCastExpr and in VisitUnaryOperator
			// as they are the actual way that the fixed point algorithm sees conditionals
			// in the union program (eithre as (!Ret) <- unary not, or as (g) <- cast from integral to boolean)
			nstate_ = state_;
			state_.MeetGuard(tcons1(texpr1(env,name_os.str()) == AnalysisUtils::kOne));
			nstate_.MeetGuard(tcons1(texpr1(env,name_os.str()) == AnalysisUtils::kZero));
		} else { // if (v) ; v can be any expression
			if (expr_map_.count(node) == 0) {// print warning just one time
				cerr << "Careful! the boolean condition (" << result.e_ <<
						") will be modeled on the false path as " << tcons1(result.e_ > AnalysisUtils::kZero) <<
						" V " << tcons1(result.e_ < AnalysisUtils::kZero) <<
						". Partitioning will discard this data and the path may get crossed with the other CFG's true path.\n";
				//getchar();
			}
			// result.s_ = { v != 0 }, result.ns_ = { v == 0 }
			//			var v(name_os.str());
			//			if (!env.contains(v)) {
			//				env = env.add(&v,1,0,0);
			//			}
			State s1,s2;
			s1.Meet(tcons1(result.e_ > AnalysisUtils::kZero));
			s2.Meet(tcons1(result.e_ < AnalysisUtils::kZero));
			//			s1.Meet(tcons1(texpr1(env,v) > AnalysisUtils::kZero));
			//			s2.Meet(tcons1(texpr1(env,v) < AnalysisUtils::kZero));
			result.s_ = s1.Join(s2);
			result.ns_.Meet(tcons1(result.e_ == AnalysisUtils::kZero));
			// 			result.ns_.Meet(tcons1(texpr1(env,name_os.str()) == AnalysisUtils::kZero));
		}
#if (DEBUGVisitImplicitCastExpr)
		cerr << "State = " << result.s_ << ", NState = " << result.ns_ << "\n------\n";
#endif
	}
	expr_map_[node] = result;
	return result;
}

VarDecl* TransferFuncs::FindBlockVarDecl(Expr* node) {
	// blast through casts and parentheses to find any DeclRefExprs that refer to a block VarDecl.

	// arrays
	if ( ArraySubscriptExpr* array_subscript_expr = dyn_cast<ArraySubscriptExpr>(node->IgnoreParenCasts()) ) {
		node = array_subscript_expr->getBase();
	}

	if ( DeclRefExpr* decl_ref_expr = dyn_cast<DeclRefExpr>(node->IgnoreParenCasts()) ) {
		if ( VarDecl* decl = dyn_cast<VarDecl>(decl_ref_expr->getDecl()) ) {
			const Type * type = decl->getType().getTypePtr();
			if (type->isIntegerType() || (type->isPointerType() && type->getPointeeType()->isIntegerType())) {
				return decl;
			}
		}
	}

	return NULL;
}

/**
 * A[i] will return the expression A, along with the state {A_idx = i} and nstate {A_idx != i}
 */
ExpressionState TransferFuncs::VisitArraySubscriptExpr(ArraySubscriptExpr *node) {
	ExpressionState result = Visit(node->getBase()), idx = Visit(node->getIdx());
	VarDecl *array_decl = FindBlockVarDecl(node->getBase());
	if (!array_decl) {
		errs() << "\nWarning: could not find variable in expression (not modeled yet):\n";
		node->getBase()->dump();
		return result;
	}
	var array_idx = (array_decl->getNameAsString() + "_idx");

	environment env = idx.e_.get_environment();
	env = env.add(&array_idx,1,0,0);
	idx.e_.extend_environment(env);


	set<abstract1> expr_abs_set, neg_expr_abs_set;
	tcons1 constraint = (texpr1(idx.e_.get_environment(),array_idx) == idx.e_);
	expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr_,constraint));
	AnalysisUtils::NegateConstraint(*state_.mgr_ptr_,constraint,neg_expr_abs_set);
	result.s_.Assume(expr_abs_set);
	result.ns_.Assume(neg_expr_abs_set);

	/**
	 * when reading from Arr[index], we return the expression Arr[index],
	 * along with the state: { Arr[index] = v }, where v is the value queried from state_


	stringstream ss;
	ss << array_decl->getNameAsString() << "[" << idx.e_ << "]";
	var array_and_index(ss.str());
	result.e_ = texpr1(environment(&array_and_index,1,0,0),array_and_index);

	// get { Arr[index] = v } by meeting state_ with {Arr_idx = index}
	State s = state_;
	s &= constraint;
	var array(array_decl->getNameAsString());
	s.Assign(result.e_.get_environment(),array_and_index,texpr1(environment(&array,1,0,0),array));
	s.Forget(array_idx);
	result.s_ &= s;
	result.ns_ &= s;

	cerr << result;
	getchar();
	 */

	return (expr_map_[node] = result);
}

ExpressionState TransferFuncs::VisitUnaryOperator(UnaryOperator* node) {
	UnaryOperator::Opcode opcode = node->getOpcode();
	Expr * sub = node->getSubExpr();
	ExpressionState result = Visit(sub);
	if (opcode == UO_Minus) {
		return (expr_map_[node] = (texpr1)(-result.e_));
	}
	VarDecl* decl = FindBlockVarDecl(sub);
	texpr1 sub_expr = result.e_;
	stringstream name;
	name << (tag_ ? Defines::kTagPrefix : "") << (decl ? decl->getNameAsString() : "");
	string type = (decl) ? decl->getType().getAsString() : "";
	var v(name.str());
	environment env = sub_expr.get_environment();

	switch ( opcode ) {
	case UO_LNot:
	{
		/**
		 * nstate should only matter in VisitImplicitCastExpr and in VisitUnaryOperator
		 * as they are the actual way that the fixed point algorithm sees conditionals
		 * in the union program (either as (!Ret) <- unary not, or as (g) <- cast from integral to boolean)
		 */
		if (type == Defines::kGuardType) {
			State tmp = nstate_;
			nstate_ = state_;
			state_ = tmp;
		}
		State tmp = result.s_;
		result.s_ = result.ns_;
		result.ns_ = tmp;
		break;
	}
	case UO_PostInc:
		if (decl->getType()->isPointerType()) { // handle array
			// bring the states up to speed
			result.s_ &= state_;
			result.ns_ &= state_;
			// result.s_ holds the state with the appropriate index and only it should change
			result.s_.Assign(env,v,sub_expr + AnalysisUtils::kOne);
			state_ = (result.s_ |= result.ns_);
			break;
		}

		state_.Assign(env,v,sub_expr + AnalysisUtils::kOne);
		nstate_.Assign(env,v,sub_expr + AnalysisUtils::kOne);
		break;
	case UO_PreInc:
		state_.Assign(env,v,sub_expr + AnalysisUtils::kOne);
		nstate_.Assign(env,v,sub_expr + AnalysisUtils::kOne);
		result = (texpr1)(sub_expr + AnalysisUtils::kOne); // the value is (sub-expression + 1)
		break;
	case UO_PostDec:
		state_.Assign(env,v,sub_expr - AnalysisUtils::kOne);
		nstate_.Assign(env,v,sub_expr - AnalysisUtils::kOne);
		break;
	case UO_PreDec:
		state_.Assign(env,v,sub_expr - AnalysisUtils::kOne);
		nstate_.Assign(env,v,sub_expr - AnalysisUtils::kOne);
		result = (texpr1)(sub_expr - AnalysisUtils::kOne); // the value is (sub-expression - 1)
		break;
	default:
		assert(0 && "unknown unary operator");
		break;
	}
	return (expr_map_[node] = result);
}

/**
 * this method actually is the entry point for visiting if, for, while and switch statements.
 */
ExpressionState TransferFuncs::VisitConditionVariableInit(Stmt *node) {
	return Visit(node); // careful here, mustn't use BlockStmt_Visit
}

ExpressionState TransferFuncs::VisitForStmt(ForStmt* node) {
	BlockStmt_Visit(node->getCond());
	ExpressionState result = expr_map_[node->getCond()];
	state_.Meet(result.s_);
	nstate_.Meet(result.ns_);
	return result;
}

ExpressionState TransferFuncs::VisitIfStmt(IfStmt* node) {
	BlockStmt_Visit(node->getCond());
	ExpressionState result = expr_map_[node->getCond()];
	state_.Meet(result.s_);
	nstate_.Meet(result.ns_);
	return result;
}

void TransferFuncs::AssignBoolExprToVar(const var& v, const ExpressionState& expr, environment& env) {
	State s1 = state_, s2 = state_;
	s1.Assign(env, v, AnalysisUtils::kOne, false);
	s1.Meet(expr.s_);
	s2.Assign(env, v, AnalysisUtils::kZero, false);
	s2.Meet(expr.ns_);
	state_ = s1.Join(s2);
}

ExpressionState TransferFuncs::VisitBinaryOperator(BinaryOperator* node) {
	manager mgr = *(state_.mgr_ptr_);
	environment &env = state_.env_;
	Expr *lhs = node->getLHS(), *rhs = node->getRHS();
	BlockStmt_Visit(lhs);
	BlockStmt_Visit(rhs);
	ExpressionState left = expr_map_[lhs], right = expr_map_[rhs];
	texpr1 left_texpr = left, right_texpr = right;
#if (DEBUGExp)
	cerr << "Left = " << left << " \nRight = " << right << '\n';
#endif

	VarDecl * left_var_decl_ptr = FindBlockVarDecl(lhs);
	//	if (!left_var_decl_ptr) {
	//		errs() << "\nWarning: could not find left variable in expression (not modeled yet):\n";
	//		node->dump();
	//		return expr_map_[node];
	//	}

	if (node->isAssignmentOp()) { // Making sure we are assigning to an integer
		if ( !left_var_decl_ptr )
			return left_texpr;
		const Type * type_ptr = left_var_decl_ptr->getType().getTypePtr();
		if ( !(type_ptr->isIntegerType() ||
				(type_ptr->isPointerType() && type_ptr->getPointeeType()->isIntegerType())) ) { // non Integer
			return left_texpr;
		}
	}

	stringstream left_var_name;
	if ( left_var_decl_ptr ) {
		left_var_name << (tag_ ? Defines::kTagPrefix : "") << left_var_decl_ptr->getNameAsString();
	}
	var left_var(left_var_name.str());

	left_texpr.extend_environment(AnalysisUtils::JoinEnvironments(left_texpr.get_environment(),right_texpr.get_environment()));
	right_texpr.extend_environment(AnalysisUtils::JoinEnvironments(left_texpr.get_environment(),right_texpr.get_environment()));

	set<abstract1> expr_abs_set, neg_expr_abs_set;
	ExpressionState result;
	switch ( node->getOpcode() ) {
	case BO_Assign:
	{
		result = right_texpr;
		bool is_guard = (left_var_decl_ptr->getType().getAsString() == Defines::kGuardType);
		// take care of cases like: int x = (y < z);
		if (!is_guard && rhs->isKnownToHaveBooleanValue()) {
			AssignBoolExprToVar(left_var, right, env);
			break;
		}

		/**
		 * handle reading from array:
		 * v = A[i] effect will be: state_ = state_ /\ ( { t = A , A_idx = i } \/ { A_idx != i } )
		 */
		VarDecl * right_var_decl_ptr = FindBlockVarDecl(rhs);
		if (right_var_decl_ptr && right_var_decl_ptr->getType()->isPointerType()) {
			assert(!left_var_decl_ptr->getType()->isPointerType() && "lvalue and rvalue can't both be arrays in our analysis.");
			result = right;
			// bring the states up to speed
			result.s_ &= state_;
			result.ns_ &= state_;
			// result.s_ holds the state with the appropriate index and only it should change
			result.s_.Assign(env,left_var,right_texpr);
			state_ = (result.s_ |= result.ns_);
			break;
		}

		// handle writing to array
		if (left_var_decl_ptr->getType()->isPointerType()) {
			result = left;
			// bring the states up to speed
			result.s_ &= state_;
			result.ns_ &= state_;
			// result.s_ holds the state with the appropriate index and only it should change
			result.s_.Assign(env,left_var,right_texpr);
			state_ = (result.s_ |= result.ns_);
			break;
		}

		// otherwise, assign the value
		state_.Assign(env,left_var,right_texpr,is_guard);

		if ( is_guard ) { // assigning to guard variables needs special handling
			State tmp = right.s_;
			tmp.MeetGuard(tcons1((texpr1)left == AnalysisUtils::kOne));
			State ntmp = right.ns_;
			ntmp.MeetGuard(tcons1((texpr1)left == AnalysisUtils::kZero));
			state_ &= (tmp |= ntmp);
#if (DEBUGGuard)
			cerr << "Assigned to guard " << left_var << "\nState = " << state_ << " NState = " << nstate_ << "\n";
			getchar();
#endif
		}
		break;
	}

	case BO_AddAssign:
		// Var += Exp --> Substitute Var with (Var + Exp)
		state_.Assign(env,left_var,left_texpr+right_texpr);
	case BO_Add:
		result = texpr1(left_texpr+right_texpr);
		break;

	case BO_SubAssign:
		// Var -= Exp --> Substitute Var with (Var - Exp)
		state_.Assign(env,left_var,left_texpr-right_texpr);
	case BO_Sub:
		result = texpr1(left_texpr-right_texpr);
		break;

	case BO_MulAssign:
		// Var *= Exp --> Substitute Var with (Var * Exp)
		state_.Assign(env,left_var,left_texpr*right_texpr);
	case BO_Mul:
		result = texpr1(left_texpr*right_texpr);
		break;

	case BO_DivAssign:
		// Var /= Exp --> Substitute Var with (Var / Exp)
		state_.Assign(env,left_var,left_texpr/right_texpr);
	case BO_Div:
		result = texpr1(left_texpr/right_texpr);
		break;

	case BO_RemAssign:
		// Var %= Exp --> Substitute Var with (Var % Exp)
		state_.Assign(env,left_var,left_texpr%right_texpr);
	case BO_Rem:
		result = texpr1(left_texpr%right_texpr);
		break;

	case BO_EQ:
	{
		tcons1 constraint = (left_texpr == right_texpr);
		expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(*state_.mgr_ptr_,constraint));
		AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
		result.s_.Assume(expr_abs_set);
		result.ns_.Assume(neg_expr_abs_set);
		break;
	}
	case BO_NE:
	{
		tcons1 constraint = (left_texpr == right_texpr);
		AnalysisUtils::NegateConstraint(mgr,constraint,expr_abs_set);
		neg_expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
		result.s_.Assume(expr_abs_set);
		result.ns_.Assume(neg_expr_abs_set);
		break;
	}
	case BO_GE:
	{
		tcons1 constraint = (left_texpr >= right_texpr);
		expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
		AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
		result.s_.Assume(expr_abs_set);
		result.ns_.Assume(neg_expr_abs_set);
		break;
	}
	case BO_GT:
	{
		tcons1 constraint = (left_texpr >= right_texpr + AnalysisUtils::kOne);
		expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
		AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
		result.s_.Assume(expr_abs_set);
		result.ns_.Assume(neg_expr_abs_set);
		break;
	}
	case BO_LE:
	{
		tcons1 constraint = (left_texpr <= right_texpr);
		expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
		AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
		result.s_.Assume(expr_abs_set);
		result.ns_.Assume(neg_expr_abs_set);
		break;
	}
	case BO_LT:
	{
		tcons1 constraint = (left_texpr <= right_texpr - AnalysisUtils::kOne);
		expr_abs_set.insert(AnalysisUtils::AbsFromConstraint(mgr,constraint));
		AnalysisUtils::NegateConstraint(mgr,constraint,neg_expr_abs_set);
		result.s_.Assume(expr_abs_set);
		result.ns_.Assume(neg_expr_abs_set);
		break;
	}
	case BO_LAnd:
	{
		result.s_ = left.s_;
		result.s_ &= right.s_;

		// ~(L /\ R) = ~L \/ (L /\ ~R)
		// start off with (L /\ ~R)
		result.ns_ = left.s_;
		result.ns_ &= right.ns_;
		// now do ~L
		result.ns_ |= left.ns_;

		break;
	}
	case BO_LOr:
	{
		result.s_ = left.s_;
		result.s_ |= right.s_;

		// !(L || R) = ~L and ~R
		result.ns_ = left.ns_;
		result.ns_ &= right.ns_;

		break;
	}
	case BO_Comma:
	{
		result.s_ = left.s_;
		result.s_ &= right.s_;
		state_ = result.s_;
		//assert(0 && "comma ',' operator not supported.");
		break;
	}
	case BO_Shr:
	{
		/*
			if (!ExpRight.is_scalar())
				break;
			long Factor = 1;
			manager Mgr = state_.Abs.get_manager();
			while (state_.Abs.bound(Mgr,ExpRight) != interval(0,0)) {
				Factor *= 2;
				ExpRight = ExpRight - texpr1(state_.Abs.get_environment(),1);
			}
			return (texpr1)(ExpLeft * texpr1(state_.Abs.get_environment(),Factor));
		 */
		break;
	}
	case BO_And:
	case BO_AndAssign:
	case BO_Or:
	case BO_OrAssign:
	case BO_Shl:
	case BO_ShlAssign:
	case BO_ShrAssign:
	case BO_Xor:
	case BO_XorAssign:
	default:
		break;
	}
#if (DEBUGCons)
	cerr << "Result: " << result << endl;
	getchar();
#endif
	expr_map_[node] = result;
	return result;
}

ExpressionState TransferFuncs::VisitDeclStmt(DeclStmt* node) {
	for ( DeclStmt::const_decl_iterator iter = node->decl_begin(), end = node->decl_end(); iter != end; ++iter ) {
		if ( VarDecl *decl = cast<VarDecl>(*iter) ) {
			string type = decl->getType().getAsString();
			stringstream name;
			name << (tag_ ? Defines::kTagPrefix : "") << decl->getNameAsString();
			/**
			 * correlation point variable - defined only to identify a point where
			 * the differential need be checked.
			 */
			if ( name.str().find(Defines::kCorrPointPrefix) == 0 ) {
				state_.at_diff_point_ = true;
				analysis_data_ptr_->Observer->ObserveAll(state_, node->getLocStart());
				// implement the partition-at-corr-point strategy
				if ( state_.partition_point_ == AnalysisConfiguration::PARTITION_AT_CORR_POINT) {
					state_.Partition();
				}
			}

			if ( decl->getType().getTypePtr()->isIntegerType() ) { // apply to integers alone (this includes guards)
				manager mgr = *(state_.mgr_ptr_);
				var v(name.str());
				/* first forget the variable (in case its defined in a loop) */
				AbstractSet abstracts = state_.abs_set_;
				state_.abs_set_.clear();
				for (AbstractSet::const_iterator iter = abstracts.begin(), end = abstracts.end();  iter != end; ++iter) {
					if (iter->vars.abstract()->get_environment().contains(v) &&
							!iter->vars.abstract()->is_variable_unconstrained(mgr,v)) {
						abstract1 abs(*(iter->vars.abstract()));
						abs = abs.forget(mgr,v,true);
						state_.abs_set_.insert(Abstract2(abs,iter->guards));
					} else if (iter->guards.abstract()->get_environment().contains(v) &&
							!iter->guards.abstract()->is_variable_unconstrained(mgr,v)) {
						abstract1 abs(*(iter->guards.abstract()));
						abs = abs.forget(mgr,v,true);
						state_.abs_set_.insert(Abstract2(iter->vars,abs));
					} else {
						state_.abs_set_.insert(*iter);
					}
				}
				/**
				 * add the newly declared integer variable to the environment.
				 * this should be the ONLY place this is needed!
				 */
				environment &env = state_.env_;
				if ( !env.contains(v) )
					env = env.add(&v,1,0,0);
				if ( Stmt* init = decl->getInit() ) {  // visit the subexpression to try and create an abstract expression
					if (type != Defines::kGuardType && decl->getInit()->isKnownToHaveBooleanValue()) {
						// take care of cases like: int x = (y < z);
						AssignBoolExprToVar(v,Visit(init),env);
					} else {
						state_.Assign(env,v,Visit(init), (type == Defines::kGuardType));
					}
				} else {
					//assert(0 && "please avoid uninitialized variables, they decrease analysis precision.");
					cerr << "Uninitialized variable " << v << " found. Uninitialized variables may decrease analysis precision.\n";
				}
			}
		}
	}
	return ExpressionState();
}

#define DEBUGVisitIntegerLiteral 0
ExpressionState TransferFuncs::VisitIntegerLiteral(IntegerLiteral * node) {
	long int value = node->getValue().getLimitedValue();
#if(DEBUGVisitIntegerLiteral)
	cerr << "TransferFuncs::VisitIntegerLiteral: value = " << value << '\n';
#endif
	ExpressionState result = texpr1(environment(), value );
	if (value) { // handle cases like: if (1)
		result.s_.SetTop();
	} else {
		result.ns_.SetTop();
	}
	expr_map_[node] = result;
	return result;
}

ExpressionState TransferFuncs::VisitCharacterLiteral(CharacterLiteral * node) {
	long int value = node->getValue();
	ExpressionState result = texpr1(environment(), value );
	expr_map_[node] = result;
	return result;
}


struct Merge {
	void operator()(State& Dst, State& Src) {
		Dst |= Src;
	}
};

struct LowerOrEqual {
	bool operator()(State& Dst, State& Src) {
		//cerr << Dst << " <= " << Src << " = " << (Dst <= Src);
		return(Dst <= Src);
	}
};

} // end namespace differential




