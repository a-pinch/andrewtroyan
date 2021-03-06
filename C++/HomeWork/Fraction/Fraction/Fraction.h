#pragma once

#include <iostream>

using namespace std;

class Fraction {
public:
	int numerator;
	unsigned int denominator;

	//ctors and dtor
	Fraction();
	Fraction(int num);
	Fraction(double num);
	Fraction(int num, unsigned int den);
	~Fraction();

	//unary operators
	Fraction operator-() const;
	Fraction operator+() const;
	Fraction& operator--();
	Fraction& operator++();
	
	//overloading binary operators 

	Fraction& operator*=(const Fraction& what);
	Fraction operator*(const Fraction& what) const;
	Fraction& operator/=(const Fraction& what);
	Fraction operator/(const Fraction& what) const;
	bool operator==(const Fraction& what) const;
	bool operator!=(const Fraction& what) const;
	bool operator<(const Fraction& what) const;
	bool operator>(const Fraction& what) const;
	bool operator<=(const Fraction& what) const;
	bool operator>=(const Fraction& what) const;
	Fraction& operator+=(const Fraction& what);
	Fraction operator+(const Fraction& what) const;
	Fraction& operator-=(const Fraction& what);
	Fraction operator-(const Fraction& what) const;

	void print() const;
	Fraction& cancel();
};

int gcd(unsigned int a, unsigned int b); //great common divider
int lcm(unsigned int a, unsigned int b); //least common multiplier
int getPrecision(double num); //max category in number after its comma 
ostream& operator<<(ostream& out, const Fraction& what);


