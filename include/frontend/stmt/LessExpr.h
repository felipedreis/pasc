//
// Created by felipe on 06/07/16.
//

#ifndef PAS_C_LESSEXPR_H
#define PAS_C_LESSEXPR_H


class LessExpr : public BinaryExpr, public BooleanExpr{

public:
    LessExpr(CodeGenerator* gen, Expression* left, Expression* right) : BinaryExpr(gen, left, right), BooleanExpr(gen) {

    }

    void emmit();

};


#endif //PAS_C_LESSEXPR_H
