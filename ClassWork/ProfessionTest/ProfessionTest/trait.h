#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

typedef size_t trait_num;

class trait {
private:
	//name of trait
	const string name;

public:
	//container of all possible traits
	static vector<trait> traits;
	//adds set of traits to container
	static void add_traits();

	//ctor
	trait(const string& name_) : name(name_) {};
};