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

	//vector<double> vec{ 1, 2, 3 };
	//matrix<double> mat(3, 3, { cos(30 * 0.17), 0, -sin(30 * 0.17), 0, 1, 0, sin(30 * 0.17), 0, cos(30 * 0.17) });
	//vector<double> res = vec * mat;

	//for (auto it : res)
	//	cout << it << endl;

	//matrix<double> unit = matrix<double>::unit_matrix;
	//matrix<double> zero = matrix<double>::zero_matrix;
	//matrix<double> rotate = matrix<double>::rotate_y(30 * 0.17);

	//cout << unit << endl << endl << zero << endl << endl << rotate << endl;

	//matrix<double> test(3, 3, { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	//cout << endl << test * unit << endl << endl << test + zero << endl;

	vector<vector<double>> q{ { 0, 0, 0 }, { 1, 0, 0 }, { 1, 1, 0 }, { 0, 1, 0 } };

	auto r = matrix<double>::rotate_y(0.1);

	for (auto v : q) {
		auto rotated =  r * v;

		for (auto coord : rotated) {
			cout << " " << coord;
		}
		cout << endl << "-----" << endl;
	}

	cin.get();
	
	return 0;
}