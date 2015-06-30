#include "test.h"
#include "details.h"
#include "answer.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>

using std::ifstream;
using std::string;
using std::getline;
using std::stringstream;
using std::exception;
using std::vector;

vector<question> test::questions;

void add_answers() {
	ifstream file("answers.csv");
	if (!file.is_open())
		throw exception("File \"answers.csv\" is not found.");

	string buffer, answer_text;
	size_t question_index;
	trait_num tr_num;
	int tr_sc;

	while (!file.eof()) {
		getline(file, buffer);

		vector<string> values = parse_csv_line(buffer);

		auto it = values.begin();
		stringstream ss(*(it++));
		ss >> question_index;
		answer_text = *(it++);

		vector<answer::point> points;
		while (it != values.end()) {
			stringstream trait_number(*(it++)), trait_score(*(it++));
			trait_number >> tr_num;
			trait_score >> tr_sc;
			points.push_back(answer::point(tr_num, tr_sc));
		}
		test::questions[question_index].push(answer(answer_text, points));
	}

	file.close();
}