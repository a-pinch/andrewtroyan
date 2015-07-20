#pragma once

#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator;
	unsigned int denominator;

public:
	//ctors and dtor
	Fraction();
	Fraction(int num);
	Fraction(double num);
	Fraction(int num, unsigned int den);

	//type conversion
	operator double() {
		return double(numerator) / denominator;
	}

	explicit operator int() {
		return numerator / denominator;
	}
};