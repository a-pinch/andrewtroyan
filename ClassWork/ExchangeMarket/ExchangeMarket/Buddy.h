#pragma once

#include "Stock.h"

class Buddy { //абстрактный класс
public:
	Stock& stock;
	virtual void act() = 0;
	Buddy(Stock& st) : stock(st) {};
};

