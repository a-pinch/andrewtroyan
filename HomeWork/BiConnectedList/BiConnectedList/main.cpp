#include "List.h"

int main() {
	try {
		List a;
		a.pushFront(6);
		a.pushFront(3);
		a.pushBack(5);
		cout << a << endl;
		a.insert(0, 100);
		cout << a << endl;
		a[0] = 3;
		cout << a << endl;

		auto it = a[1];
		while (it != a.end()) {
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		List b = a;
		cout << b << endl;
		a.merge(b);
		cout << a << endl;

		a.swap(b);
		cout << a << endl << b << endl;

		b.sort(0, b.getSize() - 1, reduce);
		cout << b << endl;

		b.reverse();
		cout << b << endl;
	}
	catch (bad_alloc e) {
		cerr << "Memory allocation error." << endl << e.what() << endl;
	}
	catch (out_of_range e) {
		cerr << "Error: out of range." << endl << e.what() << endl;
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Unknown error." << endl;
	}
	cin.get();
	return 0;
}