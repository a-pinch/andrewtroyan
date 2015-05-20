#pragma once

#include <string>

using namespace std;

class Animal
{
protected: //доступно для представителей класса и для наследников
	string name;
public:
	Animal(string name_); //конструктор с параметрами
	~Animal(); //деструктор
	virtual void voice(); //виртуальный метод, который смогут выполнять наследники класса (адрес метода не известен на этапе компиляции)
};

