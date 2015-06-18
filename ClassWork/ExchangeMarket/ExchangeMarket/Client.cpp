#include "Client.h"

#include <cstdlib>

void Client::act() {
	int temp = rand();
	double power;

	if (stock.get_sell_rate() / stock.get_buy_rate() < 1.0001)
		power = 6.0;
	else
		power = 5.0;

	if (temp % 2)
		stock.buy(pow(10, rand() * power / (RAND_MAX - 1)));
	else
		stock.sell(pow(10, rand() * power / (RAND_MAX - 1)));
}