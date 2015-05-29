#include "List.h"

int main() {
	List a;
	a.pushFront(6);
	a.pushFront(3);
	a.pushBack(5);
	cout << a << endl;
	cout << a[0] << endl;
	cin.get();
	return 0;
}