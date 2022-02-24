#include "frontend/stmt/AddExpr.h"
#include "frontend/stmt/AndExpr.h"
#include "frontend/stmt/ConstIntExpr.h"
#include "frontend/stmt/ConstStrExpr.h"
#include "frontend/stmt/DivExpr.h"
#include "frontend/stmt/InvExpr.h"
#include "frontend/stmt/MultExpr.h"
#include "frontend/stmt/NotExpr.h"
#include "frontend/stmt/OrExpr.h"
#include "frontend/stmt/SubExpr.h"
#include "frontend/stmt/VarExpr.h"
#include "frontend/stmt/DiffExpr.h"
#include "frontend/stmt/EqualsExpr.h"
#include "frontend/stmt/GraterEqualExpr.h"
#include "frontend/stmt/GraterExpr.h"
#include "frontend/stmt/LessEqualExpr.h"
#include "frontend/stmt/LessExpr.h"

void BooleanExpr::addAddressFalseSet(int address) {
    falseSet.push_back(address);
}

void BooleanExpr::addAddressTrueSet(int address) {
    trueSet.push_back(address);
}

vector<int> BooleanExpr::getFalseSet() {
    return falseSet;
}
#include <iostream>

vector<int> BooleanExpr::getTrueSet() {
    return trueSet;
}

// --------------------- Arithmetic instructions -----------------------------
void AddExpr::emmit(){
    left->emmit();
    right->emmit();
    generator->emmit(new MultInst());
}

void SubExpr::emmit() {
    left->emmit();
    right->emmit();
    generator->emmit(new SubInst);
}

void MultExpr::emmit() {
	left->emmit();
    right->emmit();
    generator->emmit(new MultInst);
} 

void DivExpr::emmit() {
    left->emmit();
    right->emmit();
    generator->emmit(new DivInst);
}

void InvExpr::emmit() {
    generator->emmit(new PushInt(0));
    expr->emmit();
    generator->emmit(new SubInst);
}

// --------------------- Boolean instructions -----------------------------
void DiffExpr::emmit() {
    left->emmit();
    right->emmit();

    BinaryExpr::generator->emmit(new EqualInst);
    BinaryExpr::generator->emmit(new NotInst);
    addAddressTrueSet(BinaryExpr::generator->getNextInst());
    addAddressFalseSet(BinaryExpr::generator->getNextInst() + 1);

    BinaryExpr::generator->emmit(new JumpInst(true));
    BinaryExpr::generator->emmit(new JumpInst(false));

}

void EqualsExpr::emmit() {
    left->emmit();
    right->emmit();

    BinaryExpr::generator->emmit(new EqualInst);

    addAddressTrueSet(BinaryExpr::generator->getNextInst());
    addAddressFalseSet(BinaryExpr::generator->getNextInst() + 1);

    BinaryExpr::generator->emmit(new JumpInst(true));
    BinaryExpr::generator->emmit(new JumpInst(false));
}

void NotExpr::emmit() {
    expr->emmit();
    trueSet = ((BooleanExpr*)expr)->getFalseSet();
    falseSet = ((BooleanExpr*)expr)->getTrueSet();

    UnaryExpr::generator->emmit(new NotInst);
}

void OrExpr::emmit() {
    left->emmit();
    int Minst = BinaryExpr::generator->getNextInst();
    right->emmit();

    BinaryExpr::generator->backpatch(((BooleanExpr*)left)->getFalseSet(), Minst);
    trueSet = BinaryExpr::generator->merge(((BooleanExpr*)left)->getTrueSet(), ((BooleanExpr*)right)->getTrueSet());
    falseSet = ((BooleanExpr*)right)->getFalseSet();
}

void AndExpr::emmit() {
    left->emmit();
    int Minst = BinaryExpr::generator->getNextInst();
    right->emmit();

    BinaryExpr::generator->backpatch(((BooleanExpr*)left)->getTrueSet(), Minst);
    trueSet = ((BooleanExpr*)right)->getTrueSet();
    falseSet = BinaryExpr::generator->merge(((BooleanExpr*)left)->getFalseSet(), ((BooleanExpr*)right)->getFalseSet());
}
//----------------------- accessors -----------------------------

void VarExpr::emmit() {
    generator->emmit(new PushInt(symbol->getAddress()));
    generator->emmit(new LoadInst(0));
}

void ConstStrExpr::emmit() {
	//throw "Method undefined";
}

void ConstIntExpr::emmit() {
    generator->emmit(new PushInt(value));
}
