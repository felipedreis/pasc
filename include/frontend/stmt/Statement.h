#ifndef _STATEMENT_H
#define _STATEMENT_H

#include <set>
#include <vector>
#include "backend/CodeGenerator.h"
#include "exception/TypeMismatch.h"
#include "frontend/Type.h"

using std::set;
using std::vector;

class Statement {
public:
	Statement() {
		generator = NULL;
	}

	Statement(CodeGenerator* generator) : generator(generator) {
	}

	~Statement() {}

	virtual void emmit() = 0;

	inline int getNextInst() {
		return this->nextInst;
	}

	inline void setNextInst(int nextInst){
		this->nextInst = nextInst;
	}

protected:
	CodeGenerator *generator;
	int nextInst;
};

class Expression : public Statement {

public:
	Expression(CodeGenerator* generator) : Statement(generator){
		
	}

	inline ExprType getType() {
		return this->type;
	}

	inline void setType(ExprType type) {
		this->type = type;
	}

protected:
	ExprType type;
};

/**
 * \brief It represent both int addition and string concatenation. The only semantic check
 * is if the left and right sides of expression are of the same type.
 */
class BooleanExpr : public Statement {

public:
	BooleanExpr(CodeGenerator* gen) : Statement(gen) {
		trueSet = vector<int>();
		falseSet = vector<int>();
	}

	void addAddressTrueSet(int address);
	void addAddressFalseSet(int address);

	vector<int> getTrueSet();
	vector<int> getFalseSet();

protected:
	vector<int> trueSet;
	vector<int> falseSet;
	
};

class UnaryExpr : public Expression {
public:
	UnaryExpr(CodeGenerator* gen, Expression * expr) : Expression(gen), expr(expr) {
	}

	~UnaryExpr(){
		delete expr;
	}

protected:
	Expression* expr;
};

/**
 * \brief It represents any kind of binary expression, that have left and right operands
 */
class BinaryExpr : public Expression {
public:
	BinaryExpr(CodeGenerator* gen, Expression *left, Expression *right) : Expression(gen), left(left), right(right) {
	}

	~BinaryExpr() {
		delete left;
		delete right;
	}

protected:
	Expression * left;
	Expression * right;

};

class ConditionalStmt : public BooleanExpr {
public:

	ConditionalStmt(CodeGenerator* gen, Expression* expr, vector<Statement*> stmtList) :
			BooleanExpr(gen), expr(expr), stmtList(stmtList) {

		if(expr->getType() != NATIVE_INT)
			throw TypeMismatch();

	}

	~ConditionalStmt() {
		vector<Statement*>::iterator it = stmtList.begin();

		for(; it != stmtList.end(); ++it){
			delete *it;
		}

		stmtList.clear();
		delete expr;
	}


protected:
	Expression * expr;
	vector<Statement*> stmtList;
};


#endif