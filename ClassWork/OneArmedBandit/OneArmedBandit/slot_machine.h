#pragma once

#include <string>
#include <sstream>
#include <exception>

using std::string;
using std::exception;
using std::stringstream;

class slot_machine {
private:
	unsigned int amount, bet, win;
	enum state_ { ready_to_bet, ready_to_game, ready_result } state;
public:
	//ctor
	slot_machine(unsigned int amount_) : amount(amount_), state(ready_to_bet) {};

	//methods
	string to_string() {
		stringstream ss;
		ss << amount;
		return ss.str();
	};
	
	void make_bet(unsigned int money) {
		if (state == ready_to_bet) {
			bet = money;
			amount += money;
			state = ready_to_game;
			return;
		}
		throw exception("In slot_machine::bet(unsigned int): machine is not ready to bet.");
	}

	void start_game() {
		if (state == ready_to_game) {
			//drum's game
			win = bet * rand() % 3;
			state = ready_result;
			return;
		}
		throw exception("In slot_machine::start_game(): machine is not ready to play.");
	}

	unsigned int get_money() {
		if (state == ready_result) {
			amount -= win;
			state = ready_to_bet;
			return win;
		}
		throw exception("In slot_machine::get_money(): machine is not ready to pay.");
	}
};

