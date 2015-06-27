#pragma once

#include <string>
#include <sstream>
#include <vector>
#include "game.h"
#include "drum.h"

using std::string;
using std::stringstream;

class slot_machine {
private:
	//fields
	unsigned int storage, bet, win;
	std::vector<drum> drums;

	//methods
	void get_bet(unsigned int money);
	void start_game();
	unsigned int return_win();
public:
	//ctor
	slot_machine(unsigned int amount, unsigned int drum_lines) : storage(amount), bet(0), win(0), drums(3, drum(drum_lines)) {};

	//methods
	string to_string() {
		stringstream ss;
		ss << storage;
		return ss.str();
	};

	friend class game;
};

