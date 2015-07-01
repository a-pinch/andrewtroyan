#pragma once

#include "trait.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class profession {
private:
	//name of profession
	const string& name;
	//container of requirement traits for this profession
	vector<trait_num> traits;

public:
	//container of all possible professions
	static vector<profession> professions;
	//adds set of professions to container
	static void add_professions();

	//ctor
	profession(const string& name_, vector<trait_num> list) : name(name_), traits(list) {};
};