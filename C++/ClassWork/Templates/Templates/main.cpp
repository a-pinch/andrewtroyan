#include "Header.h"

#include <iostream>
#include "forward_list.h"
#include "list.h"

using namespace std;

int main() {
	//f<int>(5, 6);
	//auto x = f<int>; //explicit instantiation
	//float z = f(1.0f, 2.0f); //implicit instantiation

	//Vector<int> arr(4, 0);
	//arr[0] = 1;
	//cout << arr[0] << endl;

	//cin.get();

	//Vector<Vector<int>> qq(3, Vector<int>(3, 0));

	//int z = qq[1][2];

	forward_list<int> a;
	a.pushFront(1);
	a.pushBack(2);
	a.printAll();

	list<int> b;
	b.pushFront(100);
	b.pushBack(200);
	b.printAll();

	list<string> c;
	c.pushFront(string("Hello!"));
	c.printAll();

	cin.get();
	return 0;
}