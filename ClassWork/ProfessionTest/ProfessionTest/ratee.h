#pragma once

#include "trait.h"
#include <string>
#include <map>

using std::string;
using std::map;

class ratee {
public:
	string name;
	map<trait_num, int> results;
};