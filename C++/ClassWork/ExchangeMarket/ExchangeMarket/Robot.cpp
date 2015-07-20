#include "Robot.h"

#include <iostream>

void Robot::act() {
	volatility.push_back(sqrt(stock.get_sell_rate() * stock.get_buy_rate()));

	if (volatility.size() > 3) {
		volatility.erase(volatility.begin());
		
		auto it = volatility.begin();

		if (*it > *(it + 1) && *(it + 1) > *(it + 2)) {
			if (!dollars)
				return;

			double amount = pow(10, degree), required_amount;

			while (dollars < (required_amount = stock.required_amount_for_buying(amount)))
				amount /= 2;

			if (!required_amount)
				return;

			stock.buy(amount);
			dollars -= required_amount;
			euro += amount;
 
			++degree;
			return;
		}
		else if (*it < *(it + 1) && *(it + 1) < *(it + 2)) {
			if (!euro)
				return;

			double amount_to_sell = pow(10, degree), amount_after_sell;

			while (euro < amount_to_sell)
				amount_to_sell /= 2;

			while (!(amount_after_sell = stock.amount_after_sell(amount_to_sell)))
				amount_to_sell /= 2;

			if (!amount_to_sell)
				return;

			stock.sell(amount_to_sell);
			euro -= amount_to_sell;
			dollars += amount_after_sell;

			++degree;
			return;
		}

		degree = 1;
	}
}
