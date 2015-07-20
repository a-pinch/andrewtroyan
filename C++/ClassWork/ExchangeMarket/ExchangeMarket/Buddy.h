#pragma once

#include "Stock.h"

class Buddy { 
protected:
	Stock& stock;
public:
	virtual void act() = 0;
	Buddy(Stock& st) : stock(st) {};
};

