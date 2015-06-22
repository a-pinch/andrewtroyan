#include "String.h"

#include <iostream>

using namespace std;

int main() {

	String a = "Hello", b = " world", c = "!", d;
	d = a + b + c;
	d.print();

	getc(stdin);
	return 0;
}