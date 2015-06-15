#pragma once

#include <string>
#include <iostream>

using namespace std;

// Classes

class Animal {
private:
	string name;
public:
	Animal() {};
	Animal(string name_) : name(name_) {};
	virtual void voice() = 0;
};

class Flyer {
public:
	virtual void fly() = 0;
};

class Mammal : public Animal {
public:
	virtual void voice() = 0;
};

class Bird : public Animal, public Flyer {
public:
	virtual void fly() = 0;
};

class Lupus : public Mammal {
public:
	virtual void voice();
};

class Bat : public Mammal, public Flyer {
public:
	virtual void voice();
	virtual void fly();
};

class Helicopter : public Flyer {
public:
	virtual void fly();
};

