#include "String.h"

#include <iostream>

using namespace std;

int main() {

	String a = "Hello", b = " world!", c;
	c = a + b;
	c.print();

	getc(stdin);
	return 0;
}