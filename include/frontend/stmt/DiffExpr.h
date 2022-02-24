//
// Created by felipe on 06/07/16.
//

#ifndef PAS_C_DIFFEXPR_H
#define PAS_C_DIFFEXPR_H


#include "Statement.h"

class DiffExpr : public BinaryExpr, public BooleanExpr{
public:

    DiffExpr(CodeGenerator *gen, Expression *left, Expression *right) : BinaryExpr(gen, left, right),
                                                                                             BooleanExpr(gen) { }

    void emmit();
};


#endif //PAS_C_DIFFEXPR_H
