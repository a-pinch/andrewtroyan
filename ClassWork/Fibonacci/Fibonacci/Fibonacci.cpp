#include "Fibonacci.h"

#include <cmath>

Fibonacci::Fibonacci() {
}

Fibonacci::~Fibonacci() {
}

//int Fibonacci::operator[](int n) {
//	int a = 0, b = 1, c;
//	for (int i = 0; i < n; ++i) {
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return b;
//}

int Fibonacci::operator[](int n) {
	double phi = (1.0 + sqrt(5.0)) / 2.0;
	return (pow(phi, n) - pow(-phi, -n)) / (2 * phi - 1.0);
}
