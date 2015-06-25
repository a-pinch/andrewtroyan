#include "player.h"
#include "slot_machine.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	player p(100);
	slot_machine m(1000);

	cout << "-----" << endl;
	for (int i = 0; i < 10; ++i) {
		p.play(m, 10);
		cout << p.to_string() << endl << m.to_string() << endl << "-----" << endl;
	}

	cin.get();

	return 0;
}