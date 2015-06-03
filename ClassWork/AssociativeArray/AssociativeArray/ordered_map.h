#pragma once

#include "digest.h"
#include "unordered_map.h"

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