#include "profession.h"
#include "details.h"
#include "trait.h"
#include <fstream>
#include <exception>
#include <string>
#include <sstream>

using std::ifstream;
using std::exception;
using std::string;
using std::getline;
using std::stringstream;

const vector<profession> profession::professions;

void profession::init() {
	ifstream file("professions.csv");
	if (!file.is_open())
		throw exception("File \"professions.csv\" is not found.");

	int current_index = 0, test_index;
	string buffer;

	while (!file.eof()) {
		getline(file, buffer);

		vector<string> values = parse_csv_line(buffer);
		auto it = values.begin();

		stringstream ss(*(it++));
		ss >> test_index;
		if (current_index != test_index) {
			file.close();
			throw exception("There's a mistake in \"professions.csv\".");
		}

		string profession_name = *(it++);
		vector<trait_num> related_traits;
		trait_num tr_number;

		while (it != values.end()) {
			stringstream ss_trait(*(it++));
			ss_trait >> tr_number;
			related_traits.push_back(tr_number);
		}
		
		const_cast<vector<profession>&>(profession::professions).push_back(profession(profession_name, related_traits));
		++current_index;
	}

	file.close();
}