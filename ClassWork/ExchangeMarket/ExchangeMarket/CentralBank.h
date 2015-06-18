#pragma once

#include "Buddy.h"
#include "Stock.h"
#include <queue>

using std::queue;

class CentralBank : public Buddy {
private:
	queue<double> volatility;
public:
	CentralBank(Stock& stock) : Buddy(stock) { volatility.push(sqrt(stock.get_sell_rate() * stock.get_buy_rate())); };
	~CentralBank() {};

	virtual void act();
};

