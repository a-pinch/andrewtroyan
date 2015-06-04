#pragma once

#include "digest.h"
#include "unordered_map.h"
#include <exception>
#include <stdexcept>
#include <list>
#include <iterator>

template <class T_key, class T_value>
class ordered_map {
private:
	unordered_map<T_key, T_value>* array;
	size_t size;
public:
	ordered_map() : array(nullptr), size(0) {};
	~ordered_map() { delete[] array; };

	ordered_map& initialize(size_t num);
	T_value& operator[](T_key key);
	void show();

	ordered_map& erase(const T_key& key);
	ordered_map& work_on_elements(void (*func)(T_key& key, T_value& value));
	const T_key& search(const T_value& value);
	void statistics();
};

template <class T_key, class T_value>
ordered_map<T_key, T_value>& ordered_map<T_key, T_value>::initialize(size_t num) {
	size = 3 * num;
	array = new unordered_map<T_key, T_value>[size];
	return *this;
}

template <class T_key, class T_value>
T_value& ordered_map<T_key, T_value>::operator[](T_key key) {
	int dig = digest(key);
	return array[dig % size][key];
}

template <class T_key, class T_value>
void ordered_map<T_key, T_value>::show() {
	for (size_t i = 0; i < size; ++i)
		array[i].show();
}

template <class T_key, class T_value>
ordered_map<T_key, T_value>& ordered_map<T_key, T_value>::erase(const T_key& key) {
	int dig = digest(key);
	for (auto i = array[dig % size].pairs.begin(); i != array[dig % size].pairs.end(); ++i) {
		if (i->key == key) {
			array[dig % size].pairs.erase(i);
			--(array[dig % size].amount);
			break;
		}
	}
	return *this;
}

template <class T_key, class T_value>
ordered_map<T_key, T_value>& ordered_map<T_key, T_value>::work_on_elements(void(*func)(T_key& key, T_value& value)) {
	for (size_t i = 0; i < size; ++i) {
		for (auto it = array[i].pairs.begin(); it != array[i].pairs.end(); ++it) {
			func(it->key, it->value);
		}
	}
	return *this;
}

template <class T_key, class T_value>
const T_key& ordered_map<T_key, T_value>::search(const T_value& value) {
	for (size_t i = 0; i < size; ++i) {
		for (auto it = array[i].pairs.begin(); it != array[i].pairs.end(); ++it) {
			if (it->value == value)
				return it->key;
		}
	}
	throw exception("In ordered_map<T_key, T_value>::search(const T_value& value): invalis value.");
}

template <class T_key, class T_value>
void ordered_map<T_key, T_value>::statistics() {
	cout << "Statistics:" << endl << "Size of array: " << size << endl;
	int amount_of_elements = 0, amount_of_collisions = 0;
	for (size_t i = 0; i < size; ++i) {
		amount_of_elements += array[i].amount;
		if (array[i].collisions > 0)
			amount_of_elements += array[i].collisions;
	}
	cout << "Amount of elements: " << amount_of_elements << endl << "Amount of collisions: " << amount_of_collisions << endl;
}