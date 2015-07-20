#pragma once

#include <string>

using std::string;

class Panda {
private: 
	string name;
	int age;
	double weight, length;
	// is panda is hungry... percent scale
	unsigned int fullness;
	// is panda is thirsty... percent scale
	unsigned int thirst;
	// panda's energy... percent scale
	unsigned int energy;
public:
	Panda(string name_) : name(name_), age(0), weight(0.21), length(0.17), fullness(40), thirst(50), energy(40) {};

	void play(unsigned int amount_of_mins);
	void feed(unsigned int amount_of_food);
	void water(unsigned int amount_of_water);
	bool check_health();
	void let_to_sleep(unsigned int amount_of_mins);
	void grow(unsigned int amount_of_years);
	void get_characteristics();
	void get_advanced_characteristics();
};

