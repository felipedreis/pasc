//
// Created by felipe on 06/07/16.
//

#ifndef PAS_C_GRATEREXPR_H
#define PAS_C_GRATEREXPR_H

#include "frontend/stmt/Statement.h"

class GraterExpr : public BinaryExpr, public BooleanExpr{
public:
    GraterExpr(CodeGenerator* gen, Expression* left, Expression* right) : BinaryExpr(gen, left, right), BooleanExpr(gen) {}

    void emmit();
};


#endif //PAS_C_GRATEREXPR_H
