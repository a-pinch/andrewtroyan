#pragma once

#include <iostream>
#include <initializer_list>
#include <exception>
#include <stdexcept>

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
		T& operator*();
		iterator& operator++();
		iterator& operator++(int);
		iterator& operator--();
		iterator& operator--(int);
		bool operator==(const iterator& what);
		bool operator!=(const iterator& what);
	};

	Vector();
	Vector(size_t size);
	Vector(std::initializer_list<T> list);
	Vector(const Vector& orig);
	~Vector();

	Vector& pushFront(const T& num);
	Vector& pushBack(const T& num);
	void popFront();
	void popBack();
	Vector& cat(const Vector& what);

	iterator begin();
	iterator end();
	iterator find(T value);

	Vector& operator=(const Vector& what);
	T& operator[](size_t index) const;
	 
	//friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
};

//std::ostream& operator<<(std::ostream& out, const Vector& vector);