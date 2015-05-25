#pragma once

#include <iostream>
#include <initializer_list>

class Vector {
	double* array;
	int amountOfNumbers, sizeOfMemory;
public:
	Vector();
	Vector(int size);
	Vector(std::initializer_list<double> list);
	Vector(const Vector& orig);
	~Vector();

	Vector& pushFront(double num);
	Vector& pushBack(double num);
	double popFront();
	double popBack();
	Vector& cat(const Vector& what);

	Vector& operator=(const Vector& what);
	 
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
};

std::ostream& operator<<(std::ostream& out, const Vector& vector);