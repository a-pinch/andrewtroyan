#pragma once

#include <iostream>
#include <list>

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
public:
	unordered_map() {};
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