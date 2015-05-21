#include "Fraction.h"

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

Fraction::~Fraction()
{
}


Fraction Fraction::operator-() const {
	Fraction result(numerator * (-1), denominator);
	return result;
}

Fraction Fraction::operator+() const {
	Fraction result(*this);
	if (numerator < 0)
		result.numerator *= (-1);
	return result;
}

Fraction& Fraction::operator*=(const Fraction& what) {
	numerator *= what.numerator;
	denominator *= what.denominator;
	return *this;
}

Fraction Fraction::operator*(const Fraction& what) const {
	Fraction result(*this);
	result *= what;
	return result;
}

Fraction& Fraction::operator/=(const Fraction& what) {
	numerator *= what.denominator;
	denominator *= what.numerator;
	return *this;
}

Fraction Fraction::operator/(const Fraction& what) const {
	Fraction result(*this);
	result /= what;
	return result;
}

bool Fraction::operator==(const Fraction& what) const {
	if (numerator == what.numerator && denominator == what.denominator)
		return true;
	return false;
}

bool Fraction::operator!=(const Fraction& what) const {
	return !(*this == what);
}

bool Fraction::operator<(const Fraction& what) const {
	if ((numerator * what.denominator) < (denominator * what.numerator))
		return true;
	return false;
}

bool Fraction::operator>(const Fraction& what) const {
	return!(*this < what);
}

bool Fraction::operator<=(const Fraction& what) const {
	return (*this < what || *this == what);
}

bool Fraction::operator>=(const Fraction& what) const {
	return (*this > what || *this == what);
}

Fraction& Fraction::operator+=(const Fraction& what) {

}

Fraction& Fraction::cancel() {
	if (numerator >= denominator)
	{
		int div = gcd(numerator, denominator);
		numerator /= div;
		denominator /= div;
	}
	return *this;
}

int gcd(int a, unsigned int b) {
	if (b == 0)
		return a;
	while (a % b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return b;
}