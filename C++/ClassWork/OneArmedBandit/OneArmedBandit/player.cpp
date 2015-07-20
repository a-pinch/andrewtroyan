#include "player.h"

#include <iostream>
#include <exception>

using std::cout;
using std::cin;
using std::endl;
using std::exception;

unsigned int player::make_bet() {
	unsigned int bet;

	if (!storage)
		throw exception("The player has no money!");

	cout << "Enter the bet: ";
	cin >> bet;

	while (bet > storage || !bet) {
		if (bet > storage)
			cout << "Too big! Enter again: ";
		else
			cout << "Wrong amount! Enter again: ";

		cin >> bet;
	}

	storage -= bet;

	return bet;
}

void player::take_win(unsigned int win) {
	if (!win) 
		cout << "Unfortunately, you lost!" << endl;
	else {
		cout << "You won $" << win << '!' << endl;
		storage += win;
	}
}
