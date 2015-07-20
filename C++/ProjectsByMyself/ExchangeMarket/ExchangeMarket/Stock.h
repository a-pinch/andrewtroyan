#pragma once

#include <map>

class Stock {
private:
	std::map<double, double> sell_bets, buy_bets;
public:
	Stock() {};
	~Stock() {};

	double get_sell_rate() {
		if (sell_bets.begin() != sell_bets.end())
			return sell_bets.begin()->first;
		else
			return INT_MAX;
	};
	double get_buy_rate() {
		if (buy_bets.rbegin() != buy_bets.rend())
			return buy_bets.rbegin()->first;
		else
			return 0.0;
	};

	void make_sell_bet(double rate, double amount);
	void make_buy_bet(double rate, double amount);

	void buy(double amount);
	void sell(double amount);
};

