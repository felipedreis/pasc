
#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include <string>

#define NULL_ADRESS  (-1)

using std::string;

class Instruction {
public:
	Instruction() {

	}

	~Instruction() {

	}

	virtual string toString() = 0;
};

class JumpInst : public Instruction {

public:

	JumpInst(bool conditional) : address(NULL_ADRESS), conditional(conditional) {}

	JumpInst(int address, bool conditional) : address(address), conditional(conditional) {}


	int address;
	bool conditional;

	string toString();

};

class PushInt : public Instruction {
public:

	PushInt(int value) : Instruction(), value(value) {}

	string toString();

	int value;
};

class AddInst : public Instruction {
public:
	AddInst() : Instruction() {

	}

	string toString();
};


class SubInst : public Instruction {
public:
	SubInst() : Instruction() {

	}

	string toString();
};


class MultInst : public Instruction {
public:
	MultInst() : Instruction() {

	}

	string toString();
};


class DivInst : public Instruction {
public:
	DivInst() : Instruction() {

	}

	string toString();
};


class EqualInst : public Instruction {
public:
	EqualInst() : Instruction() {

	}

	string toString();
};



class NotInst : public Instruction {
public:
	NotInst() : Instruction() {

	}

	string toString();
};


class LessInst : public Instruction {
public:
	LessInst() : Instruction() {

	}

	string toString();
};


class LessEqInst : public Instruction {
public:
	LessEqInst() : Instruction() {

	}

	string toString();
};

class GraterInst : public Instruction {
public:
	GraterInst () : Instruction() {

	}

	string toString();
};

class GraterEqInst : public Instruction {
public:
	GraterEqInst () : Instruction() {

	}

	string toString();
};

class LoadInst : public Instruction {
public:
	LoadInst(int n) : Instruction(), n(n) {

	}

	string toString();

	int n;
};

class StoreInst : public Instruction {
public:
	StoreInst(int n) : Instruction(), n(n) {

	}

	string toString();

	int n;
};

class ReadInst : public Instruction {
public:
	ReadInst() : Instruction() {

	}

	string toString();
};


class WriteInst : public Instruction {
public:
	WriteInst() : Instruction() {

	}

	string toString();
};


#endif