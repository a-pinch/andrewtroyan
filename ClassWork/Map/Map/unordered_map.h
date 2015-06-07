#pragma once

#include <iostream>
#include <list>
#include <exception>
#include <stdexcept>
#include "ordered_map.h"

using namespace std;

template <class T_key, class T_value>
class unordered_map {
private:
	struct pair {
		pair(T_key k, T_value v) : key(k), value(v) {};
		T_key key;
		T_value value;
	};

	list<pair> pairs;
	size_t amount_of_elements;
public:
	unordered_map() : amount_of_elements(0) {};
	~unordered_map() {};

	T_value& operator[](const T_key& key);
	void show() const;
	bool find(const T_key& key) const;
	unordered_map& erase(const T_key& key);
	unordered_map& work_on_elements(void(*func)(T_key& key, T_value& value));
	
	template <class T_key, class T_value>
	friend class ordered_map;
};

template <class T_key, class T_value>
T_value& unordered_map<T_key, T_value>::operator[](const T_key& key) {
	for (auto it = pairs.begin(); it != pairs.end(); ++it) {
		if (key == it->key)
			return it->value;
	}
	pairs.push_back(pair(key, T_value()));
	++amount_of_elements;
	return pairs.back().value;
}

template <class T_key, class T_value>
void unordered_map<T_key, T_value>::show() const {
	for (auto pair : pairs) {
		cout << pair.key << ' ' << pair.value << endl;
	}
}

template <class T_key, class T_value>
bool unordered_map<T_key, T_value>::find(const T_key& key) const {
	for (auto pair : pairs) {
		if (pair.key == key)
			return true;
	}
	return false;
}

template <class T_key, class T_value> 
unordered_map<T_key, T_value>& unordered_map<T_key, T_value>::erase(const T_key& key) {
	for (auto pair = pairs.begin(); pair != pairs.end(); ++pair) {
		if (pair->key == key) {
			pairs.erase(pair);
			--amount_of_elements;
			break;
		}
	}
	return *this;
}

template <class T_key, class T_value>
unordered_map<T_key, T_value>& unordered_map<T_key, T_value>::work_on_elements(void(*func)(T_key& key, T_value& value)) {
	for (auto it = pairs.begin(); it != pairs.end(); ++it) {
		func(it->key, it->value);
	}
	return *this;
}