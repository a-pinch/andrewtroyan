#include "ordered_map.h"
#include <string>

void func(string& key, int& value) {
	value += 1;
}

int main() {
	//ordered_map<string, int> people;
	//people.initialize(5);
	//people["Anna"] = 32;
	//people["Petya"] = 63;
	//people["Patye"] = 63;
	//people.show();
	//if (people.find("Vasya"))
	//	people.erase("Vasya"); 
	//people.work_on_elements(func);
	//people.show();
	//people.statistics();
	//size_t size;
	//string* array = nullptr;
	//people.search(64, &array, size);
	//for (size_t i = 0; i < size; ++i) {
	//	cout << array[i] << endl;
	//}
	//cin.get();

	unordered_map<string, int> people;
	people["Anna"] = 32;
	people["Petya"] = 63;
	people["Patye"] = 63;
	people.show();
	cout << endl;

	for (auto it = people.begin(); it != people.end(); ++it)
		cout << (*it).key << ' ' << (*it).value << endl;

	cout << endl;
	cin.get();

	return 0;
}