#include "test.h"
#include <fstream>
#include <string>

using std::ifstream;
using std::string;

vector<question> test::questions;

void add_answers() {
	ifstream file("answers.csv");
	string buffer;

	while (!file.eof()) {
		std::getline(file, buffer);
	}
}