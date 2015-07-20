#pragma once
#include <string>
#include <sstream>
#include <cstdlib>
class SlotMachine
{
private:
	int win;
	unsigned int bet;
	unsigned int Summ;
	enum st
	{
		readyToBet, readyToGame, readyResult
	} state;
public:
	SlotMachine(unsigned int money) 
		:Summ(money), state(readyToBet)
	{}
	/*void result(Player& player){

	}*/
	std::string toString(){
		std::stringstream sum;
		sum << this->Summ;
		return sum.str();
	}
	void makeBet(unsigned int bet) {
		if (state != readyToBet)
		{
			throw std::exception
				("in slotMachine::makeBet: not ready to bet");
		}
		// деньги попали в автомат 
		this->bet = bet;
		this->Summ += bet;
		state = readyToGame;
	}
	unsigned int getMoney(){
		if (state != readyResult)
		{
			throw std::exception
				("in slotMachine::getMoney: not ready to pay");
		}
		this->Summ -= win;
		state = readyToBet;
		return win;
	}
	
	void startGame()
	{
		if (state != readyToGame)
		{
			throw std::exception
				("in slotMachine::startGame: not ready to game");
		}
		//вращаем барабан
		//определяем выигрыш
		win = this->bet *(rand() % 3);
		state = readyResult;
	}
};

