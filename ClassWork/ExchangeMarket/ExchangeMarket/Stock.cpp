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
