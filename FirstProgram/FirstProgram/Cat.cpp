#include <iostream>
#include "Cat.h"

using namespace std;

//Данным коснтруктором мы вызываем конструктор Animal
Cat::Cat(string name_) : Animal(name_) { 

}

//метод класса Cat
void Cat::voice() { 
	cout << "Cat " << name << " says meow." << endl;
}