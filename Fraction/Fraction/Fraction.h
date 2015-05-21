#pragma once

class Fraction {
public:
	int numerator;
	unsigned int denominator;

	Fraction();
	Fraction(int num);
	Fraction(int num, unsigned int den);
	~Fraction();

	Fraction operator-() const;
	Fraction operator+() const;
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

	Fraction& cancel();
};

int gcd(int a, unsigned int b);

