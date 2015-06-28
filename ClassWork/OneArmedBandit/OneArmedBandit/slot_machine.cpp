#include "slot_machine.h"
#include <cstdlib>
#include <iostream>
#include <exception>
#include <Windows.h>

using std::cout;
using std::endl;
using std::exception;

void slot_machine::get_bet(unsigned int money) {
	if (!money)
		throw exception("The player didn't make bet!");
	bet = money;
}

void slot_machine::start_game() {
	if (bet) {
		storage += bet;

		char result_1, result_2, result_3;
		int limit = rand() % 10 + 5;
		cout << "Drums are rotating..." << endl;
		for (int i = 0; i < limit; ++i) {
			cout << "\r";
			result_1 = drums[0]->show();
			result_2 = drums[1]->show();
			result_3 = drums[2]->show();
			Sleep(500);
		}
		cout << endl;
		 
		if (result_1 == result_2 && result_2 == result_3) {
			if (result_1 == 0x2)
				win = bet * 2;
			else if (result_1 == 0x3)
				win = bet * 3;
			else if (result_1 == 0x4)
				win = bet * 4;
			else if (result_1 == 0x5)
				win = bet * 5;
			else if (result_1 == 0x6)
				win = bet * 6;
			else if (result_1 == 0xC)
				win = bet * 7;
			else if (result_1 == 0x37)
				win = bet * 8;
		}
		else if (result_1 == result_2 || result_2 == result_3 || result_3 == result_1)
			win = bet;
		else
			win = 0;

		bet = 0;
	}
}

unsigned int slot_machine::return_win() {
	if (win > storage)
		throw exception("Automat doesn't have enough money. Call the administrator.");
	else
		storage -= win;

	unsigned int return_win = win;
	win = 0;

	return return_win;
}