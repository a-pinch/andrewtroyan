#include "Animal.h"
#include <string>
#include <iostream>

using namespace std;

Animal::Animal(string name_) //конструктор с параметром
{
	name = name_; //присваивание параметра конструктора полю name
	cout << "New animal " << name << " is created." << endl; //выводим сообщение при срабатывании конструктора
}


Animal::~Animal()
{
	cout << "Animal " << name << " is dead." << endl; //выводим сообщение при срабатывании деструктора
}

void Animal::voice() {

}