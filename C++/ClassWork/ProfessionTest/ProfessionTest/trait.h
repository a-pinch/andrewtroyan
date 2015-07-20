#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

typedef size_t trait_num;

class trait {
public:
	//name of trait
	const string name;

	//container of all possible traits
	static const vector<trait> traits;
	//adds set of traits to container
	static void init();

	//ctor
	trait(const string& name_) : name(name_) {};
};