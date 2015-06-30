#pragma once

#include "ratee.h"
#include "question.h"
#include <vector>

using std::vector;

class test {
public:
	static vector<question> questions;
	ratee r;
	vector<question>::iterator current_question;

	void ask();
	void show_result();

	static void add_answers();
};