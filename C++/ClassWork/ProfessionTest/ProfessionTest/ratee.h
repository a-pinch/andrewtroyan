#pragma once

#include "trait.h"
#include "profession.h"
#include <string>
#include <map>

using std::string;
using std::map;
using std::multimap;

class ratee {
public:
	//name of ratee
	const string name;
	//his results (container of pairs which contain trait and its score)

	map<trait_num, int> results;
	multimap<int, string> results_to_show;

	ratee(const string& name_) : name(name_) {
		for (trait_num i = 0; i < trait::traits.size(); ++i)
			results[i] = 0;
	}
};