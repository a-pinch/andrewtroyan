#pragma once

#include "Buddy.h"
#include "Stock.h"

class CentralBank : public Buddy {
private:
	double sell_rate, buy_rate;
public:
	CentralBank(Stock& stock) : Buddy(stock) { sell_rate = stock.get_sell_rate(); buy_rate = stock.get_buy_rate(); };
	~CentralBank() {};

	virtual void act();
};

