#include "Panda.h"
#include <iostream>
#include <exception>

using std::cout;
using std::cin;
using std::endl;
using std::exception;

int main() {
	try {
		Panda my_first_panda("Debbie");

		cout << "Panda is just born:" << endl;
		my_first_panda.get_advanced_characteristics();

		my_first_panda.feed(30);
		my_first_panda.water(30);
		my_first_panda.let_to_sleep(120);

		cout << "After eating, drinking and sleeping:" << endl;
		my_first_panda.get_advanced_characteristics();

		my_first_panda.grow(20);
		cout << "Panda is grown-up:" << endl;
		my_first_panda.get_advanced_characteristics();

		cout << "Panda after playing:" << endl;
		my_first_panda.play(20);
		my_first_panda.get_advanced_characteristics();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	cin.get();

	return 0;
}