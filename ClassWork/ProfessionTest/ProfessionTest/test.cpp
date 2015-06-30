#include "test.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using std::ifstream;
using std::string;
using std::getline;
using std::stringstream;

vector<question> test::questions;

void add_answers() {
	ifstream file("answers.csv");
	string buffer;
	size_t index;
	string name;

	while (!file.eof()) {
		getline(file, buffer);
		stringstream ss(buffer);
		ss >> index;

	}

	file.close();
}