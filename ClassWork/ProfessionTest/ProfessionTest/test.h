#pragma once

#include "ratee.h"
#include "question.h"
#include <vector>

using std::vector;

class test {
private:
	//ratee
	ratee r;
	//iterator to current question
	vector<question>::iterator current_question;

public:
	//ctor
	test(const string& name) : r(name), current_question(question::questions.begin()) {};

	//when we ask ratee
	void ask();
	//shows ratee's results of test
	void show_result();

	bool is_finished() { return current_question == question::questions.end(); };
};