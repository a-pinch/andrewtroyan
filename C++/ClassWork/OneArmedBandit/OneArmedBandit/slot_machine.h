#pragma once

#include <string>
#include <sstream>
#include <vector>
#include "game.h"
#include "drum.h"

using std::string;
using std::stringstream;
using std::vector;

class slot_machine {
private:
	//fields
	unsigned int storage, bet, win;
	vector<drum*> drums;

	//private methods
	void get_bet(unsigned int money);
	void start_game();
	unsigned int return_win();
public:
	//ctor
	slot_machine(unsigned int amount, unsigned int drum_lines) : storage(amount), bet(0), win(0), drums(3) {
		for (int i = 0; i < 3; ++i)
			drums[i] = new drum(drum_lines);
	}

	//method
	string to_string() {
		stringstream ss;
		ss << storage;
		return ss.str();
	};

	//class-friend
	friend class game;
};

