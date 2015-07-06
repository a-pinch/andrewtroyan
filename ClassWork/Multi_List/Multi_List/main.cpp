#include "value.h"
#include "my_list.h"
#include "scalar.h"
#include <initializer_list>
#include <iostream>

using namespace std;

int main() {
	my_list test{ new scalar(1), new scalar(2), new my_list{ new scalar(1), new scalar(2) } };

	test.print();

	cin.get();

	return 0;
}