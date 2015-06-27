#include "player.h"

#include <iostream>

unsigned int player::make_bet() {
	unsigned int bet;

	std::cout << "Enter the bet: ";
	std::cin >> bet;

	while (bet > storage) {
		std::cout << "Too big! Enter again: ";
		std::cin >> bet;
	}

	return bet;
}

void player::take_win(unsigned int win) {
	if (!win) {
		std::cout << "Unfortunately, you lost!" << std::endl;
		storage += win;
	}
	else
		std::cout << "You won $" << win << '!' << std::endl;
}
