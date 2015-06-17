#pragma once

#include "Buddy.h"
#include "Stock.h"

class Player : public Buddy {
public:
	Player(Stock& stock) : Buddy(stock) {};
	~Player() {};

	virtual void act();
};
