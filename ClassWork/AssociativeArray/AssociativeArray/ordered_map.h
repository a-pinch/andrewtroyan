#pragma once

#include "unordered_map.h";

template <class T_key, class T_value>
class ordered_map {
private:
	unordered_map<T_key, T_value>* array;
	size_t size;

	int digest(T_key key);
public:
	ordered_map() : array(nullptr), size(0) {};
	~ordered_map() { delete[] array; };

	ordered_map& initialize(size_t num);
	T_value& operator[](T_key key);
};

template<int>
int digest(int key) {
	int hash = 0;
	while (key) {
		hash += key
	}
}

template <class T_key, class T_value>
ordered_map<T_key, T_value>& ordered_map<T_key, T_value>::initialize(size_t num) {
	size = 3 * num;
	array = new unordered_map<T_key, T_value>[size];
	return *this;
}