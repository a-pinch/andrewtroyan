#include "Client.h"

#include <cstdlib>

void Client::act() {
	int temp = rand();
	if (temp % 2)
		stock.buy(pow(10, rand() * 0.9 / RAND_MAX));
	else
		stock.sell(pow(10, rand() * 0.9 / RAND_MAX));
}
