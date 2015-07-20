#include "Stock.h"

void Stock::make_sell_bet(double rate, double amount) {
	while (rate <= get_buy_rate()) {
		auto bet = buy_bets.rbegin();
		if (amount < bet->second) {
			bet->second -= amount;
			return;
		}
		amount -= bet->second;
		buy_bets.erase(bet->first);
		if (!amount) 
			return;
	}
	
	if (sell_bets.find(rate) == sell_bets.end())
		sell_bets[rate] = amount;
	else
		sell_bets[rate] += amount;
}

void Stock::make_buy_bet(double rate, double amount) {
	while (rate >= get_sell_rate()) {
		auto bet = sell_bets.begin();
		if (amount < bet->second) {
			bet->second -= amount;
			return;
		}
		amount -= bet->second;
		sell_bets.erase(bet);
		if (!amount)
			return;
	}
	if (buy_bets.find(rate) == buy_bets.end())
		buy_bets[rate] = amount;
	else
		buy_bets[rate] += amount;
}

void Stock::sell(double amount) {
	while (amount > 0) {
		auto bet = buy_bets.rbegin();
		
		if (bet == buy_bets.rend()) 
			return;

		if (amount < bet->second) {
			bet->second -= amount;
			return;
		}
		amount -= bet->second;
		buy_bets.erase(bet->first);
	}
}

void Stock::buy(double amount) {
	while (amount > 0) {
		auto bet = sell_bets.begin();

		if (bet == sell_bets.end())
			return;

		if (amount < bet->second) {
			bet->second -= amount;
			return;
		}
		amount -= bet->second;
		sell_bets.erase(bet);
	}
}

double Stock::required_amount_for_buying(double amount_to_buy) {
	double required_amount = 0.0;

	for (auto it = sell_bets.begin(); amount_to_buy > 0 && it != sell_bets.end(); ++it) {
		if (amount_to_buy < it->second) {
			required_amount += amount_to_buy * it->first;
			amount_to_buy = 0;
		}
		else {
			required_amount += it->second * it->first;
			amount_to_buy -= it->second;
		}
	}

	if (amount_to_buy != 0)
		return INT_MAX;

	return required_amount;
}

double Stock::amount_after_sell(double amount_to_sell) {
	double amount_after_sell = 0.0;

	for (auto it = buy_bets.rbegin(); amount_to_sell > 0 && it != buy_bets.rend(); ++it) {
		if (amount_to_sell < it->second) {
			amount_after_sell += amount_to_sell * it->first;
			amount_to_sell = 0;
		}
		else {
			amount_after_sell += it->second * it->first;
			amount_to_sell -= it->second;
		}
	}

	if (amount_to_sell != 0)
		return 0.0;

	return amount_after_sell;
}
