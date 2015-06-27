#pragma once

#include <string>
#include <sstream>
#include "game.h"

using std::string;
using std::stringstream;

class player {
private:
	//fields
	unsigned int storage;

	unsigned int make_bet();
	void take_win(unsigned int win);
public:
	//ctor
	player(unsigned int amount) : storage(amount) {};

	//methods
	string to_string() {
		stringstream ss;
		ss << storage;
		return ss.str();
	};

	friend class game;
};

