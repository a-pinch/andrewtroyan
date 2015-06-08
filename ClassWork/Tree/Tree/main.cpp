#include "Tree.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	//tree<string, int> dose;
	//dose["Anna"] = 10;
	//dose["Vadim"] = 20;

	//dose.clear();
	//dose.show();

	//dose["Tan"] = 100;
	//dose.show();

	//cout << dose.size() << endl;

	//cout << dose.find("Vadim") << endl;

	tree<string, string> people;
	people["Anna"] = "anna";
	people["Vadim"] = "vadim";
	people["Anatoly"] = "anatoly";
	people["Maxim"] = "maxim";
	people["Andrew"] = "andrew";
	people["Tatyana"] = "tatyana";
	people["Irina"] = "irina";

	people.show();

	people.remove("Andrew");

	cout << endl;
	people.show();

	cin.get();
	return 0;
}