#include "player.h"
#include "slot_machine.h"
#include "game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::exception;

int main() {
	srand(time(nullptr));

	player p(100);
	slot_machine m(1000, 10);

	char answer;

	try {
		do {
			system("cls");
			game our_game(m, p);
			our_game.start_game();
			cout << "Do you want more? (y/n)" << endl;
			cin >> answer;
		} while (answer == 'y');
	}
	catch (exception e) {
		cout << e.what() << endl;
		cin.get();
	}

	cin.get();

	return 0;
}