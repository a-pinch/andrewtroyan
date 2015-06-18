#include "Player.h"

#include <cstdlib>

void Player::act() {
	int temp = rand();
	double rate, amount = pow(10, rand() * 5.0 / (RAND_MAX - 1));
	if (temp % 2) {
		rate = stock.get_buy_rate() + ((double)rand() / (RAND_MAX - 1) - 0.5) * (stock.get_sell_rate() - stock.get_buy_rate());
		stock.make_buy_bet(rate, amount);
	}
	else {
		rate = stock.get_sell_rate() + ((double)rand() / (RAND_MAX - 1) - 0.5) * (stock.get_sell_rate() - stock.get_buy_rate());
		stock.make_sell_bet(rate, amount);
	}
}
