#include "test.h"
#include "question.h"
#include "profession.h"
#include "details.h"
#include <iostream>
#include <map>
#include <utility>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::stringstream;

void test::ask() {
	if (current_question != question::questions.end()) {
		//Shows question text and variants of answer
		cout << current_question->text << endl;
		int current_index = 1;
		for (auto it = current_question->answers.begin(); it != current_question->answers.end(); ++it, ++current_index) {
			cout << current_index << " " << it->text << endl;
		}

		//Takes user's answer
		size_t user_answer;
		cin >> user_answer;
		while (user_answer == 0 || user_answer > current_question->answers.size()) {
			cout << "Wrong answer! Enter again!" << endl;
			cin >> user_answer;
		}

		//Adds points
		for (auto tr = current_question->answers[user_answer - 1].points.begin(); tr != current_question->answers[user_answer - 1].points.end(); ++tr) {
			r.results[tr->first] += tr->second;
		}

		////Take multiple answer 
		//string answer;
		//size_t index;
		//cin >> answer;
		//vector<string> values = parse_line(answer);
		//for (auto it = values.begin(); it != values.end(); ++it) {
		//	stringstream ss(*it);
		//	ss >> index;
		//	if (index > 0 && index <= current_question->answers.size()) {
		//		for (auto tr = current_question->answers[index - 1].points.begin(); tr != current_question->answers[index - 1].points.end(); ++tr) {
		//			r.results[tr->first] += tr->second;
		//		}
		//	}
		//}

		++current_question;
	}
}

void test::show_result() {
	for (auto pr = profession::professions.begin(); pr != profession::professions.end(); ++pr) {
		int prof_result = 0;
		for (auto it = pr->traits.begin(); it != pr->traits.end(); ++it) {
			prof_result += r.results[*it];
		}
		r.results_to_show.insert(std::pair<int, string>(prof_result, pr->name));
	}

	size_t counter = 0;
	for (auto it = r.results_to_show.rbegin(); it != r.results_to_show.rend() && counter < 5; ++it, ++counter) {
		if (it->first) {
			cout << it->second << " " << it->first << endl;
		}
	}
}