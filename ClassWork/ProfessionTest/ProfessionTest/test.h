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
	//container of questions and answers
	static vector<question> questions;

	//adds set of question to questions' container
	static void add_question();
	//adds set of answers to questions' container
	static void add_answers();

	//when we ask ratee
	void ask();
	//shows ratee's results of test
	void show_result();
};