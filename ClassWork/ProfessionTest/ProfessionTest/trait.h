#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

typedef size_t trait_num;

class trait {
public:
	static vector<trait> traits;	
	const string name;

	trait(const string& name_) : name(name_) {};
};