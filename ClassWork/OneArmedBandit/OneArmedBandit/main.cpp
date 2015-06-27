#include "player.h"
#include "slot_machine.h"
#include "game.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	player p(100);
	slot_machine m(10000, 6);

	game our_game(m, p);

	cin.get();

	return 0;
}