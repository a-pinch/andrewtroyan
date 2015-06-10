#include "list.h"
#include "vector.h"
#include <iostream>

using namespace std;

int main() {
	List<int> a;
	a.pushBack(1);
	a.pushBack(2);
	a.pushBack(3);
	a.pushBack(4);
	a.pushBack(4);
	a.pushBack(4);
	a.pushBack(5);
	a.pushBack(20);
	a.pushBack(17);
	a.pushBack(13);
	a.pushBack(10);

	auto p = a.find(1);
	if (p != a.end())
		a.erase(p);

	a.erase_all(4);

	auto it = a.back();
	cout << *it << endl;

	for (auto it = a.begin(); it != a.end(); ++it)
		cout << *it << ' ';
	cout << endl;

	my_sort<List<int>::iterator>(a.begin(), a.end());
	for (auto it = a.begin(); it != a.end(); ++it)
		cout << *it << ' ';
	cout << endl;

	cin.get();
	return 0;
}