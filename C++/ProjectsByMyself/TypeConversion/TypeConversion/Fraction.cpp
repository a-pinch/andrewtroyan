#include "Fraction.h"

#include <iostream>
#include <cmath>

using namespace std;

//ctors

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int num) {
	numerator = num;
	denominator = 1;
}

Fraction::Fraction(int num, unsigned int den) {
	numerator = num;
	denominator = den;
}


