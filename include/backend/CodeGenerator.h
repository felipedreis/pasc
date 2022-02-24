#ifndef _CODE_GENERATOR_H
#define _CODE_GENERATOR_H

#include <set>
#include <string>
#include <vector>

#include "backend/Instruction.h"

using std::set;
using std::string;
using std::vector;

class Instruction;


class CodeGenerator {
public:
	CodeGenerator() {

	}

	~CodeGenerator() {

	}


	void emmit(Instruction* inst);

	int getNextInst();

    vector<int> makelist(int address);
    void backpatch(const vector<int>& a, int address);
    vector<int> merge(const vector<int>& a, const vector<int>& b);

    void generate();

private:
    vector<Instruction*> code;
	int counter;
};

#endif