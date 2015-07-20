#include "List.h"
#include <string>

int main() {
	//try {
	//	List<int> a;
	//	a.pushBack(6);
	//	a.pushBack(3);
	//	a.pushBack(5);

	//	for (auto it = a.begin(); it != a.end(); ++it)
	//		cout << *it << ' ';
	//	cout << endl;

	//	a.sort(0, a.getSize() - 1, reduce);
	//	
	//	for (auto it = a.begin(); it != a.end(); ++it)
	//		cout << *it << ' ';
	//	cout << endl;
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

	//List<int> a_int;

	//for (int i = 0; i < 7; i++)
	//	a_int.pushFront(i);

	//auto p = a_int.find(4);
	//if (p == a_int.end()) {
	//	cout << "Value is not found!" << endl;

	//	cin.get();
	//	return 0;
	//}

	//a_int.erase(p);

	//for (auto q = a_int.begin(); q != a_int.end(); ++q) {
	//	cout << *q << ' ';
	//}

	List<string> people;
	people.pushBack("Tolik");
	people.pushBack("Andrew");
	people.pushBack("Vadim");

	//for (auto it = people.begin(); it != people.end(); ++it) {
	//	cout << *it << ' ';
	//}
	//cout << endl;

	//cout << people << endl;

	//people.sort(0, people.getSize() - 1, ascend);

	//for (auto it = people.begin(); it != people.end(); ++it) {
	//	cout << *it << ' ';
	//}
	//cout << endl;

	cout << people << endl;

	auto it = people.begin();
	it += 1;

	people.erase(it);
	cout << people << endl;

	cin.get();
	return 0;
}