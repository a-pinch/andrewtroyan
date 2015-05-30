#include "List.h"

int main() {
	List a;
	a.pushFront(6);
	a.pushFront(3);
	a.pushBack(5);
	cout << a << endl;
	auto it = a.begin();
	it[2].insert(4);
	cout << a << endl;
	cin.get();
	return 0;
}