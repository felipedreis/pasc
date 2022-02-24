//
// Created by felipe on 06/07/16.
//


#include "backend/CodeGenerator.h"

void CodeGenerator::emmit(Instruction *inst) {
    this->code.push_back(inst);
    this->counter++;
}

int CodeGenerator::getNextInst() {
    return counter;
}

vector<int> CodeGenerator::makelist(int address) {
    vector<int> nl;
    nl.push_back(address);

    return nl;
}

vector<int> CodeGenerator::merge(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    res.insert(res.end(), a.begin(), a.end());
    res.insert(res.end(), b.begin(), b.end());

    return res;
}

void CodeGenerator::backpatch(const vector<int>& a, int address) {

    vector<int>::const_iterator it = a.begin();

    for(; it != a.end(); ++it) {
        ((JumpInst*)code[*it])->address = address;
    }
}


#include <iostream>

void CodeGenerator::generate() {
    for (int i = 0; i < code.size(); ++i) {
        std::cout << code[i]->toString() << std::endl;
    }
}