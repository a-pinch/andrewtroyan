#pragma once

#include "Buddy.h"
#include "Stock.h"
#include <queue>

using std::queue;

class Robot : public Buddy {
private:
	double euro, dollars;
	queue<double> volatility;
public:
	Robot(Stock& stock, double e, double d) : Buddy(stock), euro(e), dollars(d) {};
	~Robot() {};

	virtual void act();
};

