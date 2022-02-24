//
// Created by felipe on 06/07/16.
//

#include <sstream>

#include "backend/Instruction.h"

using std::stringstream;

typedef stringstream sstream;

string PushInt::toString() {
    sstream ss;

    ss << "PUSHI " << this->value;
    return ss.str();
}

string AddInst::toString() {
    return "ADD";
}

string SubInst::toString() {
    return "SUB";
}

string MultInst::toString() {
    return "MUL";
}

string DivInst::toString() {
    return "DIV";
}

string NotInst::toString() {
    return "NOT";
}

string EqualInst::toString() {
    return "EQUAL";
}

string LessInst::toString() {
    return "INF";
}

string LessEqInst::toString() {
    return "INFEQ";
}

string GraterInst::toString() {
    return "SUP";
}

string GraterEqInst::toString() {
    return "SUPEQ";
}

string JumpInst::toString() {
    if(conditional)
        return "JZ";
    else
        return "JUMP";
}

string StoreInst::toString() {
    return "STORE";
}

string LoadInst::toString() {
    return "LOAD";
}

string ReadInst::toString() {
    return "READ";
}

string WriteInst::toString() {
    return "WRITE";
}