#include "Player.h"

#include <cstdlib>

void Player::act() {
	int temp = rand();
	if (temp % 2)
		stock.make_buy_bet(stock.get_buy_rate() + ((double)rand() / RAND_MAX - 0.5) * (stock.get_sell_rate() - stock.get_buy_rate()), pow(10, rand() * 5.0 / RAND_MAX));
	else
		stock.make_sell_bet(stock.get_sell_rate() + ((double)rand() / RAND_MAX - 0.5) * (stock.get_sell_rate() - stock.get_buy_rate()), pow(10, rand() * 5.0 / RAND_MAX));
}
