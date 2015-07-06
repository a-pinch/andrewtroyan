#include <list>
#include <vector>
#include <iterator>
#include <iostream>
#include "select_sort.h"
#include "toJSON.h"

using namespace std;

int main() {
	list<int> l{ 4, 1, 8, 10, 4 };
	vector<int> v{ 100, 2, 34, 192, 39, 1, 0, 1000 };

	//list sorting
	select_sort(l.begin(), l.end());

	//vector sorting
	select_sort(v.begin(), v.end());

	//result showing
	cout << toJSON(l) << endl;
	cout << toJSON(v) << endl;

	cin.get();

	return 0;
}