#pragma once

#include "trait.h"
#include <vector>
#include <string>
#include <map>

using std::string;
using std::map;
using std::vector;

class answer {
public:
	//contains text of the answer
	const string text;
	//contains container of pairs (trait_num - it's index number of trait, int - trait's score)
	const map<trait_num, int> points;

	//structure that contains trait_num and int fields (and have its own ctor)
	struct point {
		const trait_num num;
		const int score;

		point(const trait_num& num_, const int& score_) : num(num_), score(score_) {};
	};

	//ctors
	answer(const string& text_) : text(text_) {};

	answer(const string& text_, vector<point> list) : text(text_) {
		for (auto it = list.begin(); it != list.end(); ++it) {
			const_cast<map<trait_num, int>&>(points)[it->num] = it->score;
		}
	}

	//methods

	//pushes pair of values (trait_num, int) to map
	void push(const point& point_) {
		const_cast<map<trait_num, int>&>(points)[point_.num] = point_.score;
	}
};