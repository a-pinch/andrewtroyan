#pragma once

#include "answer.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class question {
public: 
	string text;
	vector<answer> answers;
};