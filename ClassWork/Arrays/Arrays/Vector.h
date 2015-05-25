#pragma once

#include <iostream>

using namespace std;

class Vector {
	int* array;
	int amountOfNumbers, sizeOfMemory;
public:
	Vector();
	Vector(int num);
	Vector(const Vector& orig);
	~Vector();

	Vector& pushFront(int num);
	Vector& pushBack(int num);
	int popFront();
	int popBack();
	Vector& plus(const Vector& what);
	Vector& cat(const Vector& what);
	 
	friend ostream& operator<<(ostream& out, const Vector& vector);
};

ostream& operator<<(ostream& out, const Vector& vector);