#include "Fraction.h"
#include "Animal.h"
#include <iostream>
#include <vector>
#include <typeinfo>

using std::cout;
using std::endl;
using std::vector;
using std::bad_cast;

int main() {
	Fraction test(3, 2);

	//1. implicit conversion (to double)
	cout << test << endl;

	//2. explicit conversion (to int)
	cout << (int)test << endl;

	//3. conversion with static_cast
	cout << static_cast<double>(test) << endl;

	//4. type pointers conversion
	int x = 7;
	char* c;
	//c = (void *)(&x); - error 
	c = (char *)(void *)(&x); //this one works
	c = reinterpret_cast<char *>(&x);

	//5. conversion const to not const 
	const int test_int = 7;
	int& test_int_ref = const_cast<int &>(test_int);
	test_int_ref = 15; //it doesn't work!!! don't even know if it's good or bad... :D
	cout << test_int << endl;

	//6. dynamic conversion (for pointers and references)
	vector<Animal *> zoo{ new Donkey, new Bat };
	//auto x = (Flyers *)(zoo[1]); //compile-time error
	//Flyers* x = dynamic_cast<Flyers *>(zoo[1]); //it doesn't work either! because "Flyers" is not class-children of "Animal"

	Bat test_bat;

	Animal* animal_pointer_test = dynamic_cast<Animal *>(&test_bat);
	if (animal_pointer_test == nullptr) {
		cout << "dynamic_cast<Animal *>: fail." << endl;
	}

	try {
		Animal& animal_reference_test = dynamic_cast<Animal &>(test_bat);
	}
	catch (bad_cast e) {
		cout << e.what() << endl;
	}

	cin.get();

	return 0;
}