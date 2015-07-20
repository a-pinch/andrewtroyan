#include "Vector.h"

using namespace std;

int main() {
	//Vector a{2, 3, 4, 5};
	//std::cout << a << std::endl;
	//a.pushFront(1);
	//std::cout << a << std::endl;
	//a.pushBack(6);
	//std::cout << a << std::endl;
	//double temp = a.popFront();
	//double temp2 = a.popBack();
	//std::cout << a << std::endl << temp << std::endl << temp2 << std::endl;

	Vector<int> a{ 1, 2, 3, 4, 5, 6 };

	auto p = a.begin();
	cout << p[2] << endl << *p << endl;
	p += 2;
	a.erase(p);

	cout << a << endl;

	Vector<double> b{ 3.14, 2.71 };
	cout << b << endl;

	cin.get();
	return 0;
}