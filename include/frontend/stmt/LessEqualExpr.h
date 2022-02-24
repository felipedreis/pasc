//
// Created by felipe on 06/07/16.
//

#ifndef PAS_C_LESSEQUALEXPR_H
#define PAS_C_LESSEQUALEXPR_H

#include "frontend/stmt/Statement.h"

class LessEqualExpr : public BinaryExpr, public BooleanExpr {
public:
    LessEqualExpr(CodeGenerator* gen, Expression* left, Expression* right) : BinaryExpr(gen, left, right), BooleanExpr(gen) {}

    void emmit();
};


#endif //PAS_C_LESSEQUALEXPR_H
