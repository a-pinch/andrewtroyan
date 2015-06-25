#pragma once

#include "slot_machine.h"
#include <string>
#include <sstream>
#include <exception>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::stringstream;

class player {
private:
	unsigned int amount;
public:
	//ctor
	player(unsigned int amount_) : amount(amount_) {};

	//methods
	string to_string() {
		stringstream ss;
		ss << amount;
		return ss.str();
	};

	void play(slot_machine& automat, unsigned int bet) {
		if (bet <= amount) {
			try {
				amount -= bet;
				automat.make_bet(bet);
				automat.start_game();
				amount += automat.get_money();
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
		}
	};
};

