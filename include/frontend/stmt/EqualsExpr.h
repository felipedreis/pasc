//
// Created by felipe on 06/07/16.
//

#ifndef PAS_C_EQUALSEXPR_H
#define PAS_C_EQUALSEXPR_H


#include "Statement.h"

class EqualsExpr : public BinaryExpr, public BooleanExpr {

public:
    EqualsExpr(CodeGenerator* gen, Expression* left, Expression* right) : BinaryExpr(gen, left, right), BooleanExpr(gen) {

    }

    void emmit();

};


#endif //PAS_C_EQUALSEXPR_H
