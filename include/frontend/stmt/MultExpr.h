#ifndef _MULT_EXPR_H
#define _MULT_EXPR_H

#include "exception/InvalidOperation.h"
#include "exception/TypeMismatch.h"

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"
#include "frontend/Type.h"

/**
 * Generate code to int product. 
 */
class MultExpr : public BinaryExpr {

public:
	MultExpr(CodeGenerator* gen, Expression *left, Expression *right) : BinaryExpr(gen, left, right) {

		if (left->getType() != right->getType() && left->getType() != NATIVE_INT) {
			throw TypeMismatch();
		} else if (left->getType() == NATIVE_STR) {
			throw InvalidOperation();
		}

		this->type = left->getType();
	}

	void emmit();
};

#endif