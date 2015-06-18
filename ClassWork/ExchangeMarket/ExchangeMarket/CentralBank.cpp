#include "CentralBank.h"

#include <cmath>

void CentralBank::act() {
	volatility.push(sqrt(stock.get_sell_rate() * stock.get_buy_rate()));

	if (volatility.size() > 5) {
		volatility.pop();
		double rate = volatility.back() / volatility.front();
		if (rate > 1.05)
			stock.make_sell_bet(stock.get_sell_rate(), pow(10, 6));
		else if (rate < 0.95)
			stock.make_buy_bet(stock.get_buy_rate(), pow(10, 6));
	}

}
