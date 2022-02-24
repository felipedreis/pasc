#ifndef _NOT_EXPR_H
#define _NOT_EXPR_H

#include "exception/InvalidOperation.h"

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"
#include "frontend/Type.h"

/**
 * Generate code to int product. 
 */
class NotExpr : public UnaryExpr, public BooleanExpr{

public:
	NotExpr(CodeGenerator* gen, Expression *expr) : UnaryExpr(gen, expr), BooleanExpr(gen) {
		if (expr->getType() != NATIVE_INT) {
			throw InvalidOperation();
		}

		this->type = expr->getType();
	}

	void emmit();
};

#endif