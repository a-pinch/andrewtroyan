#pragma once

#include "trait.h"
#include <string>
#include <vector>
#include <initializer_list>

using std::string;
using std::vector;
using std::initializer_list;

class profession {
private:
	string name;
	vector<trait_num> traits;

	profession(string name_, initializer_list<trait_num> list);
};