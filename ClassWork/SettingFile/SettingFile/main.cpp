#include "setting_file.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	cout << "Hello, " << setting_file::get_instance().name << "." << endl;

	cin.get();

	return 0;
}