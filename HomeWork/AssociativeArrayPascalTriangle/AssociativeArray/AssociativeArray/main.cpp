#include "Hash.h"

#include <iostream>

using namespace std;

int main() {
	Hash a(6);
	a.add("pi", 3.1415);
	a.add("e", 2.78);
	cout << a.find("pi") << endl << a["e"] << endl;
	a.remove("pi");
	cout << a.find("pi") << endl << a["e"] << endl;
	cin.get();
	return 0;
}