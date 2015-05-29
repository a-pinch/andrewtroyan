#include "List.h"

int main() {
	List a;
	a.pushFront(5);
	a.pushFront(3);
	a.pushBack(5);
	cout << a.empty() << endl;
	cout << a << endl;
	cin.get();
	return 0;
}