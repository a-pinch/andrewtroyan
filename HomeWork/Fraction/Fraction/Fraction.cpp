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

Fraction::Fraction(double num) {
	numerator = num * getPrecision(num);
	denominator = getPrecision(num);
}

Fraction::Fraction(int num, unsigned int den) {
	numerator = num;
	denominator = den;
}

//dtor

Fraction::~Fraction()
{
}

//methods

Fraction Fraction::operator-() const {
	Fraction result(-numerator, denominator);
	return result;
}

Fraction Fraction::operator+() const {
	Fraction result(*this);
	if (numerator < 0)
		result.numerator = -numerator;
	return result;
}

Fraction& Fraction::operator*=(const Fraction& what) {
	numerator *= what.numerator;
	denominator *= what.denominator;
	return *this;
}

Fraction Fraction::operator*(const Fraction& what) const {
	Fraction result(*this);
	return result *= what;
}

Fraction& Fraction::operator/=(const Fraction& what) {
	numerator *= what.denominator;
	denominator *= what.numerator;
	return *this;
}

Fraction Fraction::operator/(const Fraction& what) const {
	Fraction result(*this);
	return result /= what;
}

bool Fraction::operator==(const Fraction& what) const {
	Fraction a(*this), b(what);
	a.cancel();
	b.cancel();
	if (a.numerator == b.numerator && a.denominator == b.denominator)
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
	int lesComMul = lcm(denominator, what.denominator);
	numerator = lesComMul / denominator * numerator + lesComMul / what.denominator * what.numerator;
	denominator = lesComMul;
	return *this;
}

Fraction Fraction::operator+(const Fraction& what) const {
	Fraction temp(*this);
	return temp += what;
}

Fraction& Fraction::operator-=(const Fraction& what) {
	int lesComMul = lcm(denominator, what.denominator);
	numerator = lesComMul / denominator * numerator - lesComMul / what.denominator * what.numerator;
	denominator = lesComMul;
	return *this;
}

Fraction Fraction::operator-(const Fraction& what) const {
	Fraction temp(*this);
	return temp -= what;
}

void Fraction::print() const {
	cout << numerator << "/" << denominator;
}

Fraction& Fraction::cancel() {
	if ((unsigned int)abs(numerator) >= denominator)
	{
		int div = gcd(abs(numerator), denominator);
		numerator /= div;
		denominator /= div;
	}
	return *this;
}

int gcd(unsigned int a, unsigned int b) {
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

//functions

int lcm(unsigned int a, unsigned int b) {
	return a * (b / gcd(a, b));
}

int getPrecision(double num) {
	int precision = 1;
	while (num - (int)num) {
		precision *= 10;
		num *= 10;
	}
	return precision;
}

ostream& operator<<(ostream& out, const Fraction& what) {
	out << what.numerator << '/' << what.denominator;
	return out;
}
