#include "Vector.h"

#include <iostream>
#include <cstdlib>

Vector::Vector() {
	array = nullptr;
	amountOfNumbers = 0;
	sizeOfMemory = 0;
}

Vector::Vector(int size) {
	array = (double *)malloc(size * sizeof(double));
	amountOfNumbers = 0;
	sizeOfMemory = 0;
}

Vector::Vector(std::initializer_list<double> list) {
	auto first = list.begin();
	amountOfNumbers = list.size();
	sizeOfMemory = amountOfNumbers + 4;
	array = (double *)malloc(sizeOfMemory * sizeof(double));
	for (int i = 0; first != list.end(); ++i, ++first)
		array[i] = *first;
}

Vector::Vector(const Vector& orig) {
	if (orig.array) {
		array = (double *)malloc(orig.sizeOfMemory * sizeof(double));
		for (int i = 0; i < orig.amountOfNumbers; ++i)
			array[i] = orig.array[i];
	}
	else
		array = nullptr;
	amountOfNumbers = orig.amountOfNumbers;
	sizeOfMemory = orig.sizeOfMemory;
}

Vector::~Vector() {
	free(array);
}

Vector& Vector::pushFront(double num) {
	if (amountOfNumbers + 1 >= sizeOfMemory) {
		array = (double *)realloc(array, (sizeOfMemory + 4) * sizeof(double));
		if (!array)
			return *this;
		sizeOfMemory += 4;
	}
	memmove(array + 1, array, amountOfNumbers * sizeof(double));
	array[0] = num;
	++amountOfNumbers;
	return *this;
}

Vector& Vector::pushBack(double num) {
	if (amountOfNumbers + 1 >= sizeOfMemory) {
		array = (double *)realloc(array, (sizeOfMemory + 4) * sizeof(double));
		if (!array)
			return *this;
		sizeOfMemory += 4;
	}
	array[amountOfNumbers] = num;
	++amountOfNumbers;
	return *this;
}

double Vector::popFront() {
	if (array) {
		double retVal = array[0];
		memmove(array, array + 1, (amountOfNumbers - 1) * sizeof(double));
		--amountOfNumbers;
		if (sizeOfMemory - amountOfNumbers > 4) {
			array = (double *)realloc(array, (sizeOfMemory - 4) * sizeof(double));
			sizeOfMemory -= 4;
		}
		return retVal;
	}
	std::cout << "Error." << std::endl;
	exit(EXIT_FAILURE);
}

double Vector::popBack() {
	if (array) {
		double retVal = array[amountOfNumbers - 1];
		--amountOfNumbers;
		if (sizeOfMemory - amountOfNumbers > 4) {
			array = (double *)realloc(array, (sizeOfMemory - 4) * sizeof(double));
			sizeOfMemory -= 4;
		}
		return retVal;
	}
	std::cout << "Error." << std::endl;
	exit(EXIT_FAILURE);
}

Vector& Vector::cat(const Vector& what) {
	sizeOfMemory = amountOfNumbers + what.amountOfNumbers + 4;
	array = (double *)realloc(array, sizeOfMemory * sizeof(double));
	for (int i = amountOfNumbers, j = 0; j < what.amountOfNumbers; ++i, ++j)
		array[i] = what.array[j];
	amountOfNumbers += what.amountOfNumbers;
	return *this;
}

Vector& Vector::operator=(const Vector& what) {
	array = (double *)realloc(array, what.sizeOfMemory * sizeof(double));
	for (int i = 0; i < what.amountOfNumbers; ++i)
		array[i] = what.array[i];
	sizeOfMemory = what.sizeOfMemory;
	amountOfNumbers = what.amountOfNumbers;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
	out << '{';
	for (int i = 0; i < vector.amountOfNumbers; ++i) {
		out << vector.array[i];
		if (i != vector.amountOfNumbers - 1)
			out << ", ";
	}
	out << '}';
	return out;
}