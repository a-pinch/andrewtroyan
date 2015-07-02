#include "question.h"

#include "details.h"
#include "answer.h"
#include "question.h"
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

vector<question> question::questions;

void question::init() {

	//loads questions

	ifstream q_file("questions.csv");
	if (!q_file.is_open())
		throw exception("File \"questions.csv\" is not found.");

	int current_index = 0, test_index;
	string buffer;

	while (!q_file.eof()) {
		getline(q_file, buffer);

		vector<string> values = parse_csv_line(buffer);
		auto it = values.begin();

		stringstream ss(*it);
		ss >> test_index;
		if (current_index != test_index) {
			q_file.close();
			throw exception("There's a mistake in \"traits.csv\".");
		}

		question::questions.push_back(question(*(++it)));
		++current_index;
	}

	q_file.close();

	// loads answers

	ifstream a_file("answers.csv");
	if (!a_file.is_open())
		throw exception("File \"answers.csv\" is not found.");

	string answer_text;
	size_t question_index;
	trait_num tr_num;
	int tr_score;

	while (!a_file.eof()) {
		getline(a_file, buffer);

		vector<string> values = parse_csv_line(buffer);

		auto it = values.begin();
		stringstream ss(*(it++));
		ss >> question_index;
		answer_text = *(it++);

		vector<answer::point> points;
		while (it != values.end()) {
			stringstream trait_number(*(it++)), trait_score(*(it++));
			trait_number >> tr_num;
			trait_score >> tr_score;
			points.push_back(answer::point(tr_num, tr_score));
		}
		question::questions[question_index].push(answer(answer_text, points));
	}

	a_file.close();
}