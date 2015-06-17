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

	stock.make_sell_bet(1.369, 100);
	stock.make_sell_bet(1.37, 200);
	stock.make_sell_bet(1.375, 500);
	stock.make_sell_bet(1.4, 10000000000);

	stock.make_buy_bet(1.356, 100);
	stock.make_buy_bet(1.35, 20000000000);
	stock.make_buy_bet(1.36, 1000);

	CentralBank bank(stock);

	vector<Buddy*> buddies{ new Player(stock), new Player(stock), new Player(stock), new Client(stock), new Client(stock) };
	for (int i = 0; i < 10000; ++i) {
		for (auto it = buddies.begin(); it != buddies.end(); ++it) {
			(*it)->act();
		}

		if (i % 5)
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