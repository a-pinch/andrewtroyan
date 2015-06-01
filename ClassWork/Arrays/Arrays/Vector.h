#pragma once

#include <iostream>
#include <initializer_list>
#include <exception>
#include <stdexcept>

class Vector {
	double* array;
	int amountOfNumbers, sizeOfMemory;
public:
	class iterator {
	private:
		double* current, *begin, *end;
	public:
		iterator(double* current, double* begin, double* end);
		double& operator*();
		iterator& operator++();
		iterator& operator++(int);
		iterator& operator--();
		iterator& operator--(int);
		bool operator==(const iterator& what);
		bool operator!=(const iterator& what);
	};

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

	iterator begin();
	iterator end();
	iterator find(double value);

	Vector& operator=(const Vector& what);
	const double& operator[](size_t index) const;
	 
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
};

std::ostream& operator<<(std::ostream& out, const Vector& vector);