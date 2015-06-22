#include "matrix.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
	matrix<int> a(3, 2, { 1, 2, 3, 4, 5, 6 }), b(1, 2, { 1, 2 });

	b = std::move(a);

	cout << b << endl;
	cin.get();
	
	return 0;
}