#pragma once

#include "trait.h"
#include <string>
#include <map>

using std::string;
using std::map;

class ratee {
private:
	//name of ratee
	const string& name;
	//his results (container of pairs which contain trait and its score)
	map<trait_num, int> results;
};