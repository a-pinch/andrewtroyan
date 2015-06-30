#include "details.h"
#include <vector>
#include <iostream>
#include <locale>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::stringstream;

int main() {
	setlocale(0, "");
	string test("0;How are you?;2;+1;1;-1;");
	
	vector<string> test_vec = parse_csv_line(test);

	for (auto it = test_vec.begin(); it != test_vec.end(); ++it) {
		cout << *it << endl;
	}

	cin.get();
	return 0;
}