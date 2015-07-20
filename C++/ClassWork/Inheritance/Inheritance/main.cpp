#include "circular_queue.h"
#include "animals.h"
#include "armor.h"
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

	Yo.voice();

	armor first_armor;
	virtual_armor second_armor;

	first_armor.show_details_id();
	second_armor.show_details_id();

	cin.get();
	return 0;
}