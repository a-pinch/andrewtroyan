#pragma once

#include "Buddy.h"
#include "Stock.h"

class Client : public Buddy {
public:
	Client(Stock& stock) : Buddy(stock) {};
	~Client() {};

	virtual void act();
};

