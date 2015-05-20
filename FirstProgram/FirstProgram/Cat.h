#pragma once //будет подключен только один раз

#include "Animal.h"
#include <string>

using namespace std;

class Cat : public Animal { //отнаследован от Animal
public: //поля и методы, доступные для всех
	Cat(string name_); //конструктор с параметром
	virtual void voice();
};