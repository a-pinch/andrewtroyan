#include <iostream>
#include "ordered_map.h"

using std::cout;
using std::endl;

void incr(string &key, int& value);

int main() {
	ordered_map<string, int> people;
	people.initialize(3);
	people["Anna"] = 17;
	people["Alex"] = 27;
	people["Boreau"] = 10;
	people.show();
	cout << endl;

	people.erase("Anna");
	people.show();
	cout << endl;

	cout << people.search(10) << endl << endl;

	people.work_on_elements(incr);
	people.show();
	cout << endl;

	people.statistics();
	cin.get();
	return 0;
}

void incr(string &key, int& value) {
	++value;
}