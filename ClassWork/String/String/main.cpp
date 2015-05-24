#include "String.h"

#include <iostream>

using namespace std;

int main() {
	String a = " world!", b = "Hello", c('v', 5);

	print(b);
	b.print();
	c.print();

	char *search = "word";
	
	if (b.find(search))
		cout << "\"" << search << "\" is found in \"" << b.c_str() << "\"." <<endl;
	else
		cout << "\"" << search << "\" is not found in \"" << b.c_str() << "\"." << endl;

	b.add(" world!");

	getc(stdin);
	return 0;
}