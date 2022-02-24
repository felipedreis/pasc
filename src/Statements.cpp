#include "frontend/stmt/IfStmt.h"
#include "frontend/stmt/WhileStmt.h"
#include "frontend/stmt/AssignStmt.h"
#include "frontend/stmt/ReadStmt.h"
#include "frontend/stmt/WriteStmt.h"

void WhileStmt::emmit() {
	throw "Method undefined";
}

#include <iostream>
void IfStmt::emmit() {
	int M1, M2, i;

	if(!elseList.empty()) {
		expr->emmit();
		M1 = generator->getNextInst();

		for (i = 0; i < stmtList.size(); ++i) {
			stmtList[i]->emmit();
		}

		vector<int> nextList = generator->makelist(generator->getNextInst());

		generator->emmit(new JumpInst(false));

		M2 = generator->getNextInst();

		for (i = 0; i < elseList.size(); ++i) {
			elseList[i]->emmit();
		}

		generator->backpatch(((BooleanExpr *) expr)->getTrueSet(), M1);
		generator->backpatch(((BooleanExpr *) expr)->getFalseSet(), M2);
	} else {
		expr->emmit();
		M1 = generator->getNextInst();

		for (i = 0; i < stmtList.size(); ++i) {
			stmtList[i]->emmit();
		}

		generator->backpatch(((BooleanExpr *)expr)->getTrueSet(), M1);
		//nextInst = generator->merge(((BooleanExpr *) expr)->getFalseSet(), stmtListNextList);
	}
}

void AssignStmt::emmit() {
	generator->emmit(new PushInt(var->getAddress()));
	expr->emmit();
	generator->emmit(new StoreInst(0));
}

void WriteStmt::emmit() {
	generator->emmit(new WriteInst);
}

void ReadStmt::emmit() {
	generator->emmit(new ReadInst);
}

