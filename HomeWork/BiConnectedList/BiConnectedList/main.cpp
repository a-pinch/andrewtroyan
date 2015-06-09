#include "List.h"

int main() {
	//try {
	//	List<int> a;
	//	a.pushBack(6);
	//	a.pushBack(3);
	//	a.pushBack(5);

	//	for (auto it = a.begin(); it != a.end(); ++it)
	//		cout << *it << ' ';
	//	cout << endl;

	//	auto p = a.find(3);
	//	if (p != a.end())
	//		cout << *p;
	//	
	//}
	//catch (bad_alloc e) {
	//	cerr << "Memory allocation error." << endl << e.what() << endl;
	//}
	//catch (out_of_range e) {
	//	cerr << "Error: out of range." << endl << e.what() << endl;
	//}
	//catch (exception e) {
	//	cerr << e.what() << endl;
	//}
	//catch (...) {
	//	cerr << "Unknown error." << endl;
	//}

	List<int> a_int;

	for (int i = 0; i < 7; i++)
		a_int.pushFront(i);

	auto p = a_int.find(4);
	if (p == a_int.end()) {
		cout << "Value is not found!" << endl;

		cin.get();
		return 0;
	}

	a_int.erase(p);

	for (auto q = a_int.begin(); q != a_int.end(); ++q) {
		cout << *q << endl;
	}

	cin.get();
	return 0;
}