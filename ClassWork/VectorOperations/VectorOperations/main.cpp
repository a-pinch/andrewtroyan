#include "matrix.h"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
	//matrix<int> a(3, 3, { 1, 2, 3, 4, 5, 6, 7, 8, 9 }), b(3, 2, { 1, 2, 3, 4, 5, 6 });

	//a *= b;

	//cout << a << endl;

	matrix<int> c(2, 4, { 1, 2, 3, 4, 5, 6, 7, 8 });
	vector<int> vec{ 1, 2, 3, 4 };

	vec *= c;

	for (auto it : vec)
		cout << it << endl;

	cin.get();
	
	return 0;
}