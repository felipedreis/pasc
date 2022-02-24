#ifndef _OR_EXPR_H
#define _OR_EXPR_H

#include "exception/InvalidOperation.h"
#include "exception/TypeMismatch.h"

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"

/**
 * \brief It represents or expressions. The semantic check is if both sides are same type and they must be integers.
 */
class OrExpr : public BinaryExpr, BooleanExpr {

public:

	OrExpr(CodeGenerator* gen, Expression *left, Expression *right) : BinaryExpr(gen, left, right), BooleanExpr(gen) {
		
		if (left->getType() != right->getType() && left->getType() != NATIVE_INT) {
			throw TypeMismatch();
		} else if (left->getType() == NATIVE_STR) {
			throw InvalidOperation();
		}

		BinaryExpr::setType(left->getType());
	}

	void emmit();

};

#endif