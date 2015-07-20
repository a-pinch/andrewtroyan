#pragma once

#include <iostream>
#include <cstdlib>
#include <initializer_list>
#include <exception>
#include <stdexcept>

using namespace std;

template <class T>
class Vector {
	T* array;
	size_t amountOfNumbers, sizeOfMemory;
public:
	class iterator {
	private:
		T* current, *begin, *end;
	public:
		iterator(T* current_, T* begin_, T* end_) : current(current_), begin(begin_), end(end_) {};
		iterator() : iterator(nullptr, nullptr, nullptr) {};
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

	iterator begin();
	iterator end();
	iterator find(const T& value);

	Vector& operator=(const Vector& what);
	T& operator[](size_t index) const;
	 
	template <class T>
	friend ostream& operator<<(ostream& out, const Vector<T>& vector);
};

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