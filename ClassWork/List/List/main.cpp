#include "List.h"

#include <iostream>

using namespace std;

int main() {
	List a;
	a.pushFront(1).pushFront(2553).pushFront(54);

	a.pushBack(10).pushBack(16).popBack();
	a.printAll();

	List b = a;
	b.printAll();
	
	cin.get();
	return 0;
}