#pragma once

#include <iostream>
#include <list>
#include <exception>
#include <stdexcept>
#include "ordered_map.h"

using namespace std;

template <class T_key, class T_value>
class unordered_map {
public:
	struct pair {
		pair(T_key k, T_value v) : key(k), value(v) {};
		T_key key;
		T_value value;
	};

	list<pair> pairs;
	int amount, collisions;
public:
	unordered_map(): amount(0), collisions(-1) {};
	~unordered_map() {};

	T_value& operator[](const T_key& key);
	void show();
};

template <class T_key, class T_value>
T_value& unordered_map<T_key, T_value>::operator[](const T_key& key) {
	for (auto it = pairs.begin(); it != pairs.end(); ++it) {
		if (key == it->key)
			return it->value;
	}
	pairs.push_back(pair(key, T_value()));
	++amount;
	++collisions;
	return pairs.back().value;
}

template <class T_key, class T_value>
void unordered_map<T_key, T_value>::show() {
	//for (auto it = pairs.begin(); it != pairs.end(); ++it) {
	//	cout << it->key << ' ' << it->value << endl;
	//}
	for (auto pair : pairs) {
		cout << pair.key << ' ' << pair.value << endl;
	}
}