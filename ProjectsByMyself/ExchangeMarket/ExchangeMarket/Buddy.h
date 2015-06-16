#pragma once

#include "Stock.h"

class Buddy { //абстрактный класс
protected:
	Stock& stock;
public:
	Buddy(Stock& st) : stock(st) {};

	virtual void act() = 0;
};

