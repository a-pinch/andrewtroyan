#pragma once

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>      
#include <chrono>

using std::vector;

class Drum
{
private:
	unsigned int size, current;
	vector<char> symbols;
public:
	Drum(unsigned int size_) : size(size_), symbols(size) {
		symbols[0] = 6;
		char symb = 5;
		for (size_t i = 1; i < size; ++i) {
			//если закончились пятерки (10%)
			if (i > size / 10) {
				symb = 4;
			}
			//если закончились четверки (25%)
			else if (i > size / 4) {
				symb = 3;
			}
			//если закончились тройки (40%)
			else if (i > size * 4 / 10) {
				symb = 2;
			}
			//если закончились двойки (60%)
			else if (i > size * 6 / 10) {
				symb = 1;
			}
			//если закончились единицы (80%)
			else if (i > size * 8 / 10) {
				symb = 0;
			}
			symbols[i] = symb;
		}
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

		shuffle(symbols.begin(), symbols.end(), std::default_random_engine(seed));
	};

	void show() {

	}
};

