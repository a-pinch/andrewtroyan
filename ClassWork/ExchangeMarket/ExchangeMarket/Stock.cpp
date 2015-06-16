#include "Stock.h"

void Stock::make_sell_bet(double rate, double amount) {
	//���� ���� ������ �� ������� � ������� ����� ������ ������� ����� �� �������
	while (rate <= get_buy_rate()) {
		//bet - �������� �� ����� �������� ������ �������
		auto bet = buy_bets.rbegin();
		//���� � ������������ ������ ������ ����� ��� � �����
		if (amount < bet->second) {
			//�������� ������������ ������������ ������
			bet->second -= amount;
			//� �� ������ �����
			return;
		}
		//���� � ������������ ������ ����� �� �������, ������� ������������
		amount -= bet->second;
		buy_bets.erase(bet->first);
		if (!amount) //���� ��������� ������ ������
			return;
	}
	
	//���� ��������, ��� ���������
	if (sell_bets.find(rate) == sell_bets.end())
		sell_bets[rate] = amount;
	else
		sell_bets[rate] += amount;
}

void Stock::sell(double amount) {
	while (amount > 0) {
		auto bet = buy_bets.rbegin();
		if (amount < bet->second) {
			bet->second -= amount;
			return;
		}
		amount -= bet->second;
		buy_bets.erase(bet->first);
	}
}
