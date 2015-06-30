#pragma once

#include "ratee.h"
#include "question.h"
#include <vector>

using std::vector;

class test {
private:
	ratee r;
	vector<question>::iterator current_question;

public:
	static vector<question> questions;

	static void add_answers();

	void ask();
	void show_result();
};