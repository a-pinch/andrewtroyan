#pragma once

#include "Buddy.h"
#include "Stock.h"
#include <vector>

using std::vector;

class Robot : public Buddy {
private:
	long double euro, dollars;
	vector<double> volatility;
	int degree;
public:
	Robot(Stock& stock, long double e, long double d) : Buddy(stock), euro(e), dollars(d), degree(1) {};
	~Robot() {};

	virtual void act();
	const long double& show_euro() const { return euro; };
	const long double& show_dollars() const { return dollars; };
};

