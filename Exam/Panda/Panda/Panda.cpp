#include "Panda.h"
#include <exception>
#include <iostream>

using std::exception;
using std::cout;
using std::endl;

void Panda::play(unsigned int amount_of_mins) {
	for (unsigned int current_amount = 0; current_amount < amount_of_mins; ++current_amount) {
		fullness > 0 ? fullness -= 1 : fullness -= 0;
		thirst < 100 ? thirst += 1 : thirst += 0;
		energy > 0 ? energy -= 1 : energy -= 0;

		if (!fullness || !energy || thirst == 100) {
			throw exception("Panda is dead!");
		}
	}
}

void Panda::feed(unsigned int amount_of_food) {
	for (unsigned int current_amount = 0; current_amount < amount_of_food; ++current_amount) {
		fullness < 100 ? fullness += 1 : fullness += 0;
	}
}

void Panda::water(unsigned int amount_of_water) {
	for (unsigned int current_amount = 0; current_amount < amount_of_water; ++current_amount) {
		thirst > 0 ? thirst -= 1 : thirst -= 0;
	}
}

bool Panda::check_health() {
	if (fullness > 0 && thirst < 100 && energy > 0) {
		return true; 
	}
	else {
		throw exception("Panda is dead!");
	}
}

void Panda::let_to_sleep(unsigned int amount_of_mins) {
	for (unsigned int current_amount = 0; current_amount < amount_of_mins; ++current_amount) {
		energy < 100 ? energy += 1 : energy += 0;
	}
}

void Panda::grow(unsigned int amount_of_years) {
	if (age + 1 > 26) {
		throw exception("Panda is dead!");
	}
	for (unsigned int current = 0; current < amount_of_years; ++current) {
		age += 1;
		if (age >= 1 && age <= 4) {
			length += 0.4;
			weight += 25;
		}
		else {
			age += amount_of_years - current - 1;
			break;
		}
	}
}

void Panda::get_characteristics() {
	cout << "-----" << endl;
	cout << "Name: " << name << endl;
	cout << "Weight: " << weight << " kg" << endl;
	cout << "Length: " << length << " m" << endl;
	cout << "Age: " << age << " years" << endl;
	cout << "-----" << endl;
}

void Panda::get_advanced_characteristics() {
	cout << "-----" << endl;
	cout << "Name: " << name << endl;
	cout << "Weight: " << weight << " kg" << endl;
	cout << "Length: " << length << " m" << endl;
	cout << "Age: " << age << " years" << endl;
	cout << "Fullness: " << fullness << "%" << endl;
	cout << "Thirst: " << thirst << "%" << endl;
	cout << "Energy: " << energy << "%" << endl;
	cout << "-----" << endl;
}
