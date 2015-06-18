#include "Stock.h"
#include "Buddy.h"
#include "Client.h"
#include "Player.h"
#include "CentralBank.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>
#include <fstream>

using namespace std;

int main() {
	Stock stock;

	srand(time(nullptr));

	ofstream results("results.csv");
	results.imbue(std::locale(""));

	results << "Sell rate;Buy rate" << endl;

	stock.make_sell_bet(1.37, 20000);
	stock.make_sell_bet(1.375, 50000);
	stock.make_sell_bet(1.369, 10000);
	stock.make_sell_bet(1.4, 10000000000);

	stock.make_buy_bet(1.356, 100000);
	stock.make_buy_bet(1.35, 200000);
	stock.make_buy_bet(1.3, 10000000000);

	CentralBank bank(stock);

	vector<Buddy*> buddies{ new Player(stock), new Player(stock), new Player(stock), new Client(stock), new Client(stock) };
	for (int i = 1; i <= 10000; ++i) {
		for (auto it = buddies.begin(); it != buddies.end(); ++it) {
			(*it)->act();
		}

		if (i % 5 == 0)
			bank.act();

		if (i % 100 == 0) {
			results << stock.get_sell_rate() << ";" << stock.get_buy_rate() << endl;
			cout << "---" << endl << stock.get_sell_rate() << endl;
			cout << stock.get_buy_rate() << endl << "---" << endl;
		}
	}

	cin.get();
	results.close();

	return 0;
}