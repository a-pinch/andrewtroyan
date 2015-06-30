#pragma once

#include "trait.h"
#include <vector>
#include <string>
#include <map>

using std::string;
using std::map;
using std::vector;

class answer {
private:
	const string text;
	map<trait_num, int> points;

public:
	//structure that contains trait_num and int fields (and have its own ctor)
	struct point {
		trait_num num;
		int score;

		point(const trait_num& num_, const int& score_) : num(num_), score(score_) {};
	};

	//ctors
	answer(const string& text_) : text(text_) {};

	answer(const string& text_, vector<point> list) : text(text_) {
		for (auto it = list.begin(); it != list.end(); ++it) {
			points[it->num] = it->score;
		}
	}

	//methods
	void push(const point& point_) {
		points[point_.num] = point_.score;
	}
};