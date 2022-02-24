#ifndef _SYMBOL_H
#define _SYMBOL_H

#include <string>

#include "frontend/Type.h"

using std::string;

class Symbol {
public:
	
	Symbol() {
	}

	Symbol(string name, int address, VarType type) : name(name), address(address), type(type) {

	}

	~Symbol() {}

	string getName();
	void setName(string name);

	int getAddress();
	void setAddress(int address);

	VarType getType();
	void setType(VarType type);

private:
	string name;
	int address;
	VarType type;
};

#endif