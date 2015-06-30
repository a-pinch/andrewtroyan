#pragma once

#include "answer.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class question {
private: 
	const string text;
	vector<answer> answers;

public:
	question(const string& text_) : text(text_) {};

	void push(const answer& obj) {
		answers.push_back(obj);
	}
};