#ifndef _INV_EXPR_H
#define _INV_EXPR_H

#include "exception/InvalidOperation.h"

#include "frontend/stmt/Statement.h"
#include "frontend/Symbol.h"
#include "frontend/TokenType.h"

/**
 * \brief It represent both int addition and string concatenation. The only semantic check
 * is if the left and right sides of expression are of the same type.
 */
class InvExpr : public UnaryExpr {

public:
	InvExpr(CodeGenerator* gen, Expression* expr) : UnaryExpr(gen, expr) {
		
		if (expr->getType() != NATIVE_INT) {
			throw InvalidOperation();
		}

		this->type = expr->getType();
	}

	void emmit();
};

#endif