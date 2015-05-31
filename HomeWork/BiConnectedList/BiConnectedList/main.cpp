#include "List.h"

int main() {
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

	b.sort(0, b.getSize() - 1);
	cout << b << endl;

	cin.get();
	return 0;
}