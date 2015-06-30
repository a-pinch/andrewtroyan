#include "trait.h"
#include "details.h"
#include <fstream>
#include <exception>
#include <string>
#include <sstream>

using std::ifstream;
using std::exception;
using std::string;
using std::getline;
using std::stringstream;

vector<trait> trait::traits;

void trait::add_traits() {
	ifstream file("trait.csv");
	if (!file.is_open())
		throw exception("File \"traits.csv\" is not found.");

	int current_index = 0, test_index;

	string buffer;
	while (!file.eof()) {
		getline(file, buffer);

		vector<string> values = parse_csv_line(buffer);
		auto it = values.begin();

		stringstream ss(*it);
		ss >> test_index;
		if (current_index != test_index) {
			file.close();
			throw exception("There's a mistake in \"traits.csv\".");
		}

		traits.push_back(trait(*(++it)));
		++current_index;
	}

	file.close();
}