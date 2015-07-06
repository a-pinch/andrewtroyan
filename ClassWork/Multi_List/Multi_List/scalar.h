#pragma once

#include "value.h"
#include <iostream>

using std::cout;

class scalar : public value {
private:
	int value;
public:
	//ctor
	scalar(const int what) : value(what) {};

	//method
	virtual void print() { cout << value; };

	//type conversing
	operator int() {
		return value;
	}
};