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
	//name of profession
	const string& name;
	//container of requirement traits for this profession
	vector<trait_num> traits;

public:
	//ctor
	profession(string name_, initializer_list<trait_num> list);
};