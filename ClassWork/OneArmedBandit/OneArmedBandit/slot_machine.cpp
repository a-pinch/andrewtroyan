#include "slot_machine.h"

void slot_machine::get_bet(unsigned int money) {
	if (money) {
		bet = money;
	}
}

void slot_machine::start_game() {
	if (bet) {
		//игра
		//win = выигрыш
		bet = 0;
	}
}

unsigned int slot_machine::return_win() {
	unsigned int return_win = win;
	win = 0;
	return return_win;
}