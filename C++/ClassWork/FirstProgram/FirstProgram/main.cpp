#include "Cat.h"
#include "Dog.h"
#include "Animal.h"
#include <iostream>

int main() {
	Cat thomas("Tommy"); //создаем объект thomas класса Cat, вызывается конструктор и в конструктор передается параметр имени
	Dog bobby("Bob");

	//thomas.voice();
	//bobby.voice();

	Animal *array[2];
	array[0] = &thomas;
	array[1] = &bobby;

	for (int i = 0; i < 2; ++i)
	{
		array[i]->voice();
	}

	getc(stdin);
	return 0;
}