#include <iostream>
#include "ordered_map.h"

using std::cout;
using std::endl;

int main() {
	ordered_map<string, float> people;
	people.initialize(3);
	people["Anna"] = 1.7f;
	people["Alex"] = 2.7f;
	people["Boreau"] = 0.1f;

	people.show();
	cin.get();
	return 0;
}