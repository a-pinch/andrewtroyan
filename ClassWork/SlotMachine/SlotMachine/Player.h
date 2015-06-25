#pragma once
#include "SlotMachine.h"
#include <iostream>
#include <string>
#include <sstream>
class Player
{
public:
	Player(unsigned int initialSum)
		:sum(initialSum){}
private:
	unsigned int sum;
public:
	void play(SlotMachine& machine, unsigned int bet)
	{
		try{
			//Игрок сделал стьавку
			this->sum -= bet;
			//Положил деньги в автомат
			machine.makeBet(bet);
			//Игрок запускает автомат и ждет окончания
			machine.startGame();
			//Игрок забирает выйгрыш , если он есть 
			this->sum += machine.getMoney();
		}
		catch (std::exception e) {
			std::cerr << e.what() << std::endl;
		}
		
	};
	std::string toString(){
		std::stringstream sum;
		sum << this->sum;
		return sum.str();
	}
	void Win(unsigned int money){
		this->sum += money;
	}
};

