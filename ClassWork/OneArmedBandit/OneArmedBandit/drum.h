#pragma once

#include <vector>

class drum {
private:
	unsigned int size, current;
	std::vector<char> symbols;
public:
	drum(unsigned int size_);
};

