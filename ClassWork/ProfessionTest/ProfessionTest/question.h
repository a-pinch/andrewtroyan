#pragma once

#include "answer.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class question {
public: 
	//text of the question
	const string text;
	//container of possible answers to this question
	vector<answer> answers;

	//container of questions and answers
	static vector<question> questions;

	//adds set of question to questions' container
	static void init();

	//ctor
	question(const string& text_) : text(text_) {};

	//pushes another possible answer to container of answers
	void push(const answer& obj) {
		answers.push_back(obj);
	}
};