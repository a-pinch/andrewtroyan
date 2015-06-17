#include "Stock.h"
#include "Buddy.h"
#include "Client.h"
#include "Player.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>

using namespace std;

int main() {
	Stock stock;

	srand(time(nullptr));

	stock.make_sell_bet(1.369, 100);
	stock.make_sell_bet(1.37, 200);
	stock.make_sell_bet(1.375, 500);
	stock.make_sell_bet(1.38, 1000);

	stock.make_buy_bet(1.356, 100);
	stock.make_buy_bet(1.35, 200);
	stock.make_buy_bet(1.36, 1000);

	vector<Buddy*> buddies{ new Player(stock), new Client(stock) };
	while (1) {
		for (auto it = buddies.begin(); it != buddies.end(); ++it) {
			Sleep(1000);
			(*it)->act();
		}
		cout << "---" << endl << stock.get_buy_rate() << endl;
		cout << stock.get_sell_rate() << endl << "---" << endl;
	}
	return 0;
}