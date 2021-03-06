#pragma once

#include <iostream>
#include <cstdlib>
#include <initializer_list>
#include <exception>
#include <stdexcept>
#include "sort.h"

using namespace std;

template <class T>
class Vector {
	T* array;
	size_t amountOfNumbers, sizeOfMemory;
public:
	class iterator {
	private:
		Vector *host;
		T *current, *begin, *end;
	public:
		iterator(Vector *host_, T* current_, T* begin_, T* end_) : host(host_), current(current_), begin(begin_), end(end_) {};
		iterator() : iterator(nullptr, nullptr, nullptr, nullptr) {};
		T& operator*();
		iterator& operator++();
		iterator& operator++(int);
		iterator& operator--();
		iterator& operator--(int);
		iterator& operator+=(const size_t& num);
		iterator operator+(const size_t& num);
		iterator& operator-=(const size_t& num);
		iterator operator-(const size_t& num);
		T& operator[](const int& num);
		bool operator==(const iterator& what);
		bool operator!=(const iterator& what);

		friend class Vector;

		template <class T>
		friend void my_sort(T begin, T end);
	};

	Vector() : array(nullptr), amountOfNumbers(0), sizeOfMemory(0) {};
	Vector(size_t size);
	Vector(std::initializer_list<T> list);
	Vector(const Vector& orig);
	~Vector() { free(array); };

	Vector& pushFront(const T& num);
	Vector& pushBack(const T& num);
	void popFront();
	void popBack();
	Vector& cat(const Vector& what);
	Vector& erase(iterator& it);
	Vector& erase_all(const T& value);

	iterator begin();
	iterator end();
	iterator back() { auto it = begin(); return it + (amountOfNumbers - 1); };
	iterator find(const T& value);

	Vector& operator=(const Vector& what);
	T& operator[](size_t index) const;

	template <class T>
	friend ostream& operator<<(ostream& out, const Vector<T>& vector);
};

template <class T>
T& Vector<T>::iterator::operator*() {
	if (current >= begin && current < end)
		return *current;
	throw std::invalid_argument("In Vector::iterator::operator*(): invalid iterator.");
}

template <class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator++() {
	if (current < end)
		++current;
	return *this;
}

template <class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator++(int) {
	if (current < end)
		++current;
	return *this;
}

template <class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator--() {
	if (current > begin)
		--current;
	return *this;
}

template <class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator--(int) {
	if (current > begin)
		--current;
	return *this;
}

template <class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator+=(const size_t& num) {
	if (current && current + num <= end) {
		current += num;
		return *this;
	}
	throw invalid_argument("In Vector<T>::iterator::operator+=(const size_t&): invalid iterator.");
}

template <class T>
typename Vector<T>::iterator Vector<T>::iterator::operator+(const size_t& num) {
	iterator temp = *this;
	return temp += num;
}

template <class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator-=(const size_t& num) {
	if (current && current - num >= begin) {
		current -= num;
		return *this;
	}
	throw invalid_argument("In Vector<T>::iterator::operator-=(const size_t&): invalid iterator.");
}

template <class T>
typename Vector<T>::iterator Vector<T>::iterator::operator-(const size_t& num) {
	iterator temp = *this;
	return temp -= num;
}

template <class T>
T& Vector<T>::iterator::operator[](const int& num) {
	if (num < 0)
		return *((*this) - (-num));
	return *((*this) + num);
}

template <class T>
bool Vector<T>::iterator::operator==(const iterator& what) {
	return current == what.current;
}

template <class T>
bool Vector<T>::iterator::operator!=(const iterator& what) {
	return current != what.current;
}

template <class T>
Vector<T>::Vector(size_t size) {
	array = (T *)malloc(size * sizeof(T));
	amountOfNumbers = 0;
	sizeOfMemory = size;
}

template <class T>
Vector<T>::Vector(std::initializer_list<T> list) {
	auto first = list.begin();
	amountOfNumbers = list.size();
	sizeOfMemory = amountOfNumbers + 4;
	array = (T *)malloc(sizeOfMemory * sizeof(T));
	for (int i = 0; first != list.end(); ++i, ++first)
		array[i] = *first;
}

template <class T>
Vector<T>::Vector(const Vector<T>& orig) {
	if (orig.array) {
		array = (T *)malloc(orig.sizeOfMemory * sizeof(T));
		for (size_t i = 0; i < orig.amountOfNumbers; ++i)
			array[i] = orig.array[i];
	}
	else
		array = nullptr;
	amountOfNumbers = orig.amountOfNumbers;
	sizeOfMemory = orig.sizeOfMemory;
}

template <class T>
Vector<T>& Vector<T>::pushFront(const T& num) {
	if (amountOfNumbers + 1 >= sizeOfMemory) {
		array = (T *)realloc(array, (sizeOfMemory + 4) * sizeof(T));
		if (!array)
			return *this;
		sizeOfMemory += 4;
	}
	memmove(array + 1, array, amountOfNumbers * sizeof(T));
	array[0] = num;
	++amountOfNumbers;
	return *this;
}

template <class T>
Vector<T>& Vector<T>::pushBack(const T& num) {
	if (amountOfNumbers + 1 >= sizeOfMemory) {
		array = (T *)realloc(array, (sizeOfMemory + 4) * sizeof(T));
		if (!array)
			return *this;
		sizeOfMemory += 4;
	}
	array[amountOfNumbers] = num;
	++amountOfNumbers;
	return *this;
}

template <class T>
void Vector<T>::popFront() {
	if (array) {
		memmove(array, array + 1, (amountOfNumbers - 1) * sizeof(T));
		--amountOfNumbers;
		if (sizeOfMemory - amountOfNumbers > 4) {
			array = (T *)realloc(array, (sizeOfMemory - 4) * sizeof(T));
			sizeOfMemory -= 4;
		}
	}
	else 
		throw exception("In Vector<T>::popFront(): vector is empty.");
}

template <class T>
void Vector<T>::popBack() {
	if (array) {
		--amountOfNumbers;
		if (sizeOfMemory - amountOfNumbers > 4) {
			array = (T *)realloc(array, (sizeOfMemory - 4) * sizeof(T));
			sizeOfMemory -= 4;
		}
	}
	else
		throw exception("In Vector<T>::popBack(): vector is empty.");
}

template <class T>
Vector<T>& Vector<T>::cat(const Vector<T>& what) {
	sizeOfMemory = amountOfNumbers + what.amountOfNumbers + 4;
	array = (T *)realloc(array, sizeOfMemory * sizeof(T));
	for (size_t i = amountOfNumbers, j = 0; j < what.amountOfNumbers; ++i, ++j)
		array[i] = what.array[j];
	amountOfNumbers += what.amountOfNumbers;
	return *this;
}

template <class T>
Vector<T>& Vector<T>::erase(iterator& what) {
	if (what.current != what.end && what.current != nullptr) {
		if (what.current == what.begin)
			popFront();
		else if (what.current == what.end - 1)
			popBack();
		else {
			memmove(what.current, what.current + 1, (what.end - what.current - 1) * sizeof(T));
			--amountOfNumbers;
			if (sizeOfMemory - amountOfNumbers > 4) {
				array = (T *)realloc(array, (sizeOfMemory - 4) * sizeof(T));
				sizeOfMemory -= 4;
			}
		}
		return *this;
	}
	throw invalid_argument("In Vector<T>::erase(iterator&): invalid iterayot.");
}

template <class T>
Vector<T>& Vector<T>::erase_all(const T& value) {
	auto it = begin();
	while ((it = find(value)) != end())
		erase(it);
	return *this;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin() {
	return iterator(this, array, array, array + amountOfNumbers);
}

template <class T>
typename Vector<T>::iterator Vector<T>::end() {
	return iterator(this, array + amountOfNumbers, array, array + amountOfNumbers);
}

template <class T>
typename Vector<T>::iterator Vector<T>::find(const T& value) {
	T *ptr = array;
	for (; ptr != (array + amountOfNumbers); ++ptr) {
		if (*ptr == value)
			return iterator(this, ptr, array, array + amountOfNumbers);
	}
	return iterator(this, ptr, array, array + amountOfNumbers);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& what) {
	array = (T *)realloc(array, what.sizeOfMemory * sizeof(T));
	for (size_t i = 0; i < what.amountOfNumbers; ++i)
		array[i] = what.array[i];
	sizeOfMemory = what.sizeOfMemory;
	amountOfNumbers = what.amountOfNumbers;
	return *this;
}

template <class T>
T& Vector<T>::operator[](size_t index) const {
	if (index >= 0 && amountOfNumbers > index)
		return array[index];
	throw out_of_range("In Vector<T>::operator[](size_t): invalid index.");
}

template <class T>
ostream& operator<<(ostream& out, const Vector<T>& vector) {
	out << '{';
	for (size_t i = 0; i < vector.amountOfNumbers; ++i) {
		out << vector.array[i];
		if (i != vector.amountOfNumbers - 1)
			out << ", ";
	}
	out << '}';
	return out;
}