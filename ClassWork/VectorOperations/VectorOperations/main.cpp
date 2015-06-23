#include "matrix.h"
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
	//matrix<int> a(3, 3, { 1, 2, 3, 4, 5, 6, 7, 8, 9 }), b(3, 2, { 1, 2, 3, 4, 5, 6 });

	//a *= b;

	//cout << a << endl;

	//matrix<int> c(2, 4, { 1, 2, 3, 4, 5, 6, 7, 8 });
	//vector<int> vec{ 1, 2, 3, 4 };

	//vec *= c;

	//for (auto it : vec)
	//	cout << it << endl;

	vector<double> vec{ 1, 2, 3 };
	matrix<double> mat(3, 3, { cos(30 * 0.17), 0, -sin(30 * 0.17), 0, 1, 0, sin(30 * 0.17), 0, cos(30 * 0.17) });
	vector<double> res = vec * mat;

	for (auto it : res)
		cout << it << endl;

	cin.get();
	
	return 0;
}