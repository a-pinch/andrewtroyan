#pragma once

#include "trait.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

typedef size_t prof_num;

class profession {
public:
	//name of profession
	const string name;
	//container of requirement traits for this profession
	vector<trait_num> traits;

	//container of all possible professions
	static vector<profession> professions;
	//adds set of professions to container
	static void init();

	//ctor
	profession(const string& name_, vector<trait_num> list) : name(name_), traits(list) {};
};