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
	size_t size, amount_of_pairs, collisions;
public:
	ordered_map() : array(nullptr), size(0), amount_of_pairs(0), collisions(0) {};
	~ordered_map() { delete[] array; };

	ordered_map& initialize(size_t num);
	T_value& operator[](T_key key);
	void show();

	ordered_map& erase(const T_key& key);
	bool find(const T_key& key);
	ordered_map& work_on_elements(void(*func)(T_key& key, T_value& value));
	void search(const T_value& value, T_key** keys, size_t& amount_of_keys);
	void statistics() const;
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
	size_t prev_size = array[dig % size].amount_of_elements;
	T_value& ret = array[dig % size][key];
	if (array[dig % size].amount_of_elements > prev_size)
		++amount_of_pairs;
	if (array[dig % size].amount_of_elements > 1)
		++collisions;
	return ret;
}

template <class T_key, class T_value>
void ordered_map<T_key, T_value>::show() {
	for (size_t i = 0; i < size; ++i)
		array[i].show();
}

template <class T_key, class T_value>
ordered_map<T_key, T_value>& ordered_map<T_key, T_value>::erase(const T_key& key) {
	int dig = digest(key);
	array[dig % size].erase(key);
	--amount_of_pairs;
	return *this;
}

template <class T_key, class T_value>
bool ordered_map<T_key, T_value>::find(const T_key& key) {
	return array[digest(key) % size].find(key);
}

template <class T_key, class T_value>
ordered_map<T_key, T_value>& ordered_map<T_key, T_value>::work_on_elements(void(*func)(T_key& key, T_value& value)) {
	for (size_t i = 0; i < size; ++i) {
		array[i].work_on_elements(func);
	}
	return *this;
}

template <class T_key, class T_value>
void ordered_map<T_key, T_value>::search(const T_value& value, T_key** keys, size_t& amount_of_keys) {
	*keys = nullptr;
	amount_of_keys = 0;
	for (size_t i = 0; i < size; ++i) {
		for (auto it = array[i].pairs.begin(); it != array[i].pairs.end(); ++it) {
			if (it->value == value)
				++amount_of_keys;
		}
	}

	if (amount_of_keys > 0) {
		*keys = new T_key[amount_of_keys];
		for (size_t i = 0, cur = 0; i < size; ++i) {
			for (auto it = array[i].pairs.begin(); it != array[i].pairs.end(); ++it) {
				if (it->value == value) {
					(*keys)[cur] = it->key;
					++cur;
				}
			}
		}
	}
}

template <class T_key, class T_value>
void ordered_map<T_key, T_value>::statistics() const {
	cout << "Statistics: " << endl;
	cout << "Size: " << size << endl;
	cout << "Amount of elements: " << amount_of_pairs << endl;
	cout << "Collisions: " << collisions << endl;
}