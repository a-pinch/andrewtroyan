#pragma once

#include "ratee.h"
#include "question.h"
#include <vector>

using std::vector;

class test {
private:
	ratee r;
	vector<question> questions;
public:
	//ctor

	void ask();
	void show_result();
};