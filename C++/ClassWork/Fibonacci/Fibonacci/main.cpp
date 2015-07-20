#include "Fibonacci.h"

#include <iostream>

using namespace std;

int main() {
	Fibonacci a;
	for (int i = 0; i < 30; ++i)
		cout << a[i] << endl;
	getc(stdin);
	return 0;
}