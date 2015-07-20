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
			//����� ������ �������
			this->sum -= bet;
			//������� ������ � �������
			machine.makeBet(bet);
			//����� ��������� ������� � ���� ���������
			machine.startGame();
			//����� �������� ������� , ���� �� ���� 
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

