#include "drum.h"

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>      
#include <chrono>

drum::drum(unsigned int size_) : size(size_), symbols(size) {
	symbols[0] = 6;
	char symbol = 5;
	for (size_t i = 1; i < size; ++i) {
		if (size > size / 10)
			symbol = 4;
		else if (i > size / 4) 
			symbol = 3;
		else if (i > size * 4 / 10) 
			symbol = 2;
		else if (i > size * 6 / 10)
			symbol = 1;
		else if (i > size * 8 / 10) 
			symbol = 0;

		symbols[i] = symbol;
	}
}