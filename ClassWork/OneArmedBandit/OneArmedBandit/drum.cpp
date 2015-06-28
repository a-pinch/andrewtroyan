#include "drum.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::random_shuffle;

drum::drum(unsigned int size_) : size(size_), symbols(size), current(-1) {
	symbols[0] = 0x37;
	char symbol = 0xC;
	for (size_t i = 1; i < size; ++i) {
		if (i >= size / 10 && i < size / 4)
			symbol = 0x6;
		else if (i >= size / 4 && i < size * 4 / 10)
			symbol = 0x5;
		else if (i >= size * 4 / 10 && i < size * 6 / 10)
			symbol = 0x4;
		else if (i >= size * 6 / 10 && i < size * 8 / 10)
			symbol = 0x3;
		else if (i >= size * 8 / 10)
			symbol = 0x2;

		symbols[i] = symbol;
	}

	random_shuffle(symbols.begin(), symbols.end());
}

char drum::show() {
	current = (current + 1) % size;
	cout << '|' << symbols[current] << '|';
	return symbols[current];
}