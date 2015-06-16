#pragma once

#include <map>

class Stock {
private:
	std::map<double, double> sell_bets, buy_bets;
public:
	Stock() {};
	~Stock() {};

	double get_sell_rate() { return sell_bets.begin()->first; };
	double get_buy_rate() { return buy_bets.rbegin()->first; };

	void make_sell_bet(const double rate, double amount);
	void make_buy_bet(const double rate, double amount);

	void buy(double amount);
	void sell(double amount);
};

