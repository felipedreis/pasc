#ifndef _IF_STMT_H
#define _IF_STMT_H

#include <vector>

#include "frontend/stmt/Statement.h"

using std::vector;

class IfStmt : public ConditionalStmt {
public:
	IfStmt(CodeGenerator* gen, Expression* expr, vector<Statement*> stmtList, vector<Statement*> elseList)
			: ConditionalStmt(gen, expr, stmtList), elseList(elseList) {


	} 

	~IfStmt() {

	}

	void emmit();
private:

	vector<Statement*> elseList;
};

#endif