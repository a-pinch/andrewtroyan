#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

typedef size_t trait_num;

class trait {
private:
	const string name;

public:
	static vector<trait> traits;

	trait(const string& name_) : name(name_) {};
};