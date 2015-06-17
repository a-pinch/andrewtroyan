#include "CentralBank.h"

#include <cmath>

void CentralBank::act() {
	if (fabs((stock.get_sell_rate() - sell_rate) / stock.get_sell_rate()) > 0.05) {
		if (stock.get_sell_rate() > sell_rate) 
			sell_rate = stock.get_sell_rate() + 0.01;
		else
			sell_rate = stock.get_sell_rate() - 0.01;
		stock.make_sell_bet(sell_rate, pow(10, 6));
	}

	if (fabs((stock.get_buy_rate() - buy_rate) / stock.get_buy_rate()) > 0.05) {
		if (stock.get_buy_rate() > buy_rate)
			buy_rate = stock.get_buy_rate() + 0.01;
		else
			buy_rate = stock.get_buy_rate() - 0.01;
		stock.make_buy_bet(buy_rate, pow(10, 6));
	}
}
