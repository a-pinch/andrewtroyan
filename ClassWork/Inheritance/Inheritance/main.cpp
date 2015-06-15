#include "circular_queue.h"
#include "animals.h"
#include <string>

int main() {
	//circular_queue<string> people;
	//people.pushBack("Tolik");
	//people.pushBack("Andrew");
	//people.pushBack("Vadim");

	//for (auto it = people.begin(); it != people.end(); ++it) {
	//	cout << *it << ' ';
	//}
	//cout << endl;

	Lupus Yo;
	Bat man;
	Helicopter John;

	Flyer* fl[] = { &man, &John };

	for (int i = 0; i < 2; ++i)
		fl[i]->fly();

	cin.get();
	return 0;
}