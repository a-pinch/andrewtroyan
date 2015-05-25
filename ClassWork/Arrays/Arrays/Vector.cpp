#include "Vector.h"

#include <iostream>
#include <cstdlib>

Vector::Vector()
{
	array = nullptr;
	amountOfNumbers = 0;
	sizeOfMemory = 0;
}

Vector::Vector(int num)
{
	array = (int *)malloc(num * sizeof(int));
	amountOfNumbers = 0;
	sizeOfMemory = num;
}

Vector::Vector(const Vector& orig) {
	if (orig.array)
		array = (int *)malloc(orig.sizeOfMemory * sizeof(int));
	else
		array = nullptr;
	amountOfNumbers = orig.amountOfNumbers;
	sizeOfMemory = orig.sizeOfMemory;
}

Vector::~Vector()
{
	free(array);
}

Vector& Vector::pushFront(int num) {
	if (amountOfNumbers + 1 >= sizeOfMemory) {
		array = (int *)realloc(array, (sizeOfMemory + 4) * sizeof(int));
		if (!array)
			return *this;
		sizeOfMemory += 4;
	}
	memmove(array + sizeof(int), array, (sizeOfMemory - 1) * sizeof(int));
	array[0] = num;
	++amountOfNumbers;
	return *this;
}

Vector& Vector::pushBack(int num) {
	if (amountOfNumbers + 1 >= sizeOfMemory) {
		array = (int *)realloc(array, (sizeOfMemory + 4) * sizeof(int));
		if (!array)
			return *this;
		sizeOfMemory += 4;
	}
	array[amountOfNumbers] = num;
	++amountOfNumbers;
	return *this;
}

int Vector::popFront() {
	if (array) {
		int retVal = array[0];
		memmove(array, array + sizeof(int), (sizeOfMemory - 1) * sizeof(int));
		--amountOfNumbers;
		if (sizeOfMemory - amountOfNumbers > 4) {
			array = (int *)realloc(array, (sizeOfMemory - 4) * sizeof(int));
			sizeOfMemory -= 4;
		}
		return retVal;
	}
	cout << "Error." << endl;
	exit(EXIT_FAILURE);
}

int Vector::popBack() {
	if (array) {
		int retVal = array[amountOfNumbers - 1];
		--amountOfNumbers;
		if (sizeOfMemory - amountOfNumbers > 4) {
			array = (int *)realloc(array, (sizeOfMemory - 4) * sizeof(int));
			sizeOfMemory -= 4;
		}
		return retVal;
	}
	cout << "Error." << endl;
	exit(EXIT_FAILURE);
}

/*
Vector& Vector::plus(const Vector& what) {
	if (amountOfNumbers < what.amountOfNumbers && sizeOfMemory < what.amountOfNumbers)
		array = (int *)realloc(array, (what.amountOfNumbers + 4) * sizeof(int));
	int i = 0;
	for (; i < amountOfNumbers && i < ; ++i)
		array[i] += what.array[i];
	while (i < what.amountOfNumbers)
		array[i] = what.array[i];
	if (amountOfNumbers < what.amountOfNumbers && sizeOfMemory < what.amountOfNumbers) {
		sizeOfMemory = what.amountOfNumbers + 4;
		amountOfNumbers = what.amountOfNumbers;
	}
	return *this;
}*/

ostream& operator<<(ostream& out, const Vector& vector) {
	for (int i = 0; i < vector.amountOfNumbers; ++i)
		out << vector.array[i] << ' ';
	return out;
}