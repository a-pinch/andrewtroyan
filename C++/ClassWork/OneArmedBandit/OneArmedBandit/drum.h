#pragma once

#include <vector>

using std::vector;

class drum {
private:
	unsigned int size;
	int current;
	vector<char> symbols;
public:
	//ctor
	drum(unsigned int size_);
	
	//method
	char show();
};

