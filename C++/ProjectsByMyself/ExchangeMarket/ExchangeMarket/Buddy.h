#pragma once

#include "Stock.h"

class Buddy { //����������� �����
protected:
	Stock& stock;
public:
	Buddy(Stock& st) : stock(st) {};

	virtual void act() = 0;
};

