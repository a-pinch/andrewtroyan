#include "Stock.h"

void Stock::make_sell_bet(double rate, double amount) {
	//если есть заявка на покупку у которой сумма больше текущей суммы на продажу
	while (rate <= get_buy_rate()) {
		//bet - итератор на самую выгодную сделку покупки
		auto bet = buy_bets.rbegin();
		//если в существующей заявке больше денег чем в новой
		if (amount < bet->second) {
			//частично осуществляем существующую заявку
			bet->second -= amount;
			//и не ставим новую
			return;
		}
		//если в сушествующей заявке денег не хватило, снимаем существующую
		amount -= bet->second;
		buy_bets.erase(bet->first);
		if (!amount) //если продавать больше нечего
			return;
	}
	
	//если осталось, что продавать
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
