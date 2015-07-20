#include "Fraction.h"

#include <iostream>
#include <ios>

using namespace std;

int main() {
	Fraction a(14, 7), b(1, 2), c = a + b, d(5.732);
	
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	a.cancel();
	cout << a << endl;
	a += 4;
	cout << a << endl;
	
	cout << d << endl;

	cout << ++a;

	getc(stdin);
	return 0;
}