#include "Vector.h"

using namespace std;

int main() {
	/*Vector a{2, 3, 4, 5};
	std::cout << a << std::endl;
	a.pushFront(1);
	std::cout << a << std::endl;
	a.pushBack(6);
	std::cout << a << std::endl;
	double temp = a.popFront();
	double temp2 = a.popBack();
	std::cout << a << std::endl << temp << std::endl << temp2 << std::endl;*/

	Vector a{ 1, 2, 3 }, b{ 4, 5, 6 };
	a.cat(b);
	//std::cout << a << std::endl;
	//double g = a[1];
	//std::cout << g << std::endl;
	//std::cout << a[4] << std::endl;

	auto it = a.begin();
	*it = 100500;

	for (auto it = a.begin(); it != a.end(); ++it)
		cout << *it << endl;

	getc(stdin);
	return 0;
}