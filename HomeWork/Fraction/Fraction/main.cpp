#include "Fraction.h"

#include <iostream>
#include <ios>

using namespace std;

int main() {
	Fraction a(14, 7), b(1, 2), c = a + b, d(5.732);
	/*
	a.print();
	cout << endl;
	b.print();
	cout << endl;
	c.print();
	cout << endl;

	a.cancel();
	a.print();
	cout << endl;
	a += 4;
	a.print();
	cout << endl;

	d.print();
	cout << endl;*/

	cout << a << endl << b << endl;

	getc(stdin);
	return 0;
}