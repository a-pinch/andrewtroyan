#include "passport.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	passport first_man, second_man;

	cout << first_man.get_id() << endl << second_man.get_id() << endl;

	cin.get();

	ofstream file("id.txt");
	file << passport::get_global_id();
	file.close();

	return 0;
}