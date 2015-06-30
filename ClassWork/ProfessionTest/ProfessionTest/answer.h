#pragma once

#include "trait.h"
#include <initializer_list>
#include <string>
#include <map>

using std::string;
using std::map;
using std::initializer_list;

class answer {
public:
	struct point {
		trait_num num;
		int score;

		point(trait_num num_, int score_) : num(num_), score(score_) {};
	};

	string text;
	map<trait_num, int> points;

	answer(const string& text_) : text(text_) {};

	//answer(const string& text_, initializer_list<point> list) : text(text_) {
	//	for (auto it = list.begin(); it != list.end(); ++it) {
	//		points[it->num] = it->score;
	//	}
	//}

	void push(const point& point_) {
		points[point_.num] = point_.score;
	}
};