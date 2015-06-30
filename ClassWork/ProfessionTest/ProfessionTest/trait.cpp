#include "trait.h"
#include "details.h"
#include <fstream>
#include <exception>
#include <string>

using std::ifstream;
using std::exception;
using std::string;
using std::getline;

vector<trait> trait::traits;

void trait::add_traits() {
	ifstream file("trait.csv");
	if (!file.is_open())
		throw exception("File \"traits.csv\" is not found.");

	string buffer;
	while (!file.eof()) {
		getline(file, buffer);
		vector<string> values = parse_csv_line(buffer);
		auto it = values.begin();
		traits.push_back(trait(*(++it)));
	}
}