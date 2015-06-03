#include <string>
#include "unordered_map.h"

int main() {
	unordered_map<string, float> people;
	people["Anna"] = 1.7f;
	people["Alex"] = 2.7f;
	people["Boreau"] = 0.1f;

	people.show();
	cin.get();
	return 0;
}