#include "List.h"

#include <iostream>

using namespace std;

int main() {
	try {
		List<int> a;
		/*a.pushFront(1).pushFront(2553).pushFront(54);

		a.pushBack(10).pushBack(16).popBack();
		a.printAll();

		List b = a;
		b.printAll();*/

		a.pushBack(1);
		a.pushBack(2);
		a.pushBack(3);
		a.pushBack(4);
		a.pushBack(5);
		a.pushBack(6);
		a.pushBack(7);

		for (auto i = a.begin(); i != a.end(); ++i)
			cout << *i << ' ';
		cout << endl;

	}
	catch (int e) {
		if (e == 1)
			cerr << "Memory allocation error!" << endl;
		else if (e == 2)
			cerr << "Memory access error!" << endl;
	}

	cin.get();
	return 0;
}