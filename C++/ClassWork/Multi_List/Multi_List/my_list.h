#pragma once

#include "value.h"
#include <vector>
#include <iostream>
#include <initializer_list>

using std::cout;
using std::vector;
using std::initializer_list;

class my_list : public value {
private:
	vector<value*> values;
public:
	my_list(initializer_list<value*> list) {
		for (auto it : list)
			values.push_back(it);
	}

	virtual void print() {
		cout << "[";
		for (auto it = values.begin(); it != values.end(); ++it) {
			if (it != values.begin())
				cout << ", ";
			(*it)->print();
		}
		cout << "]";
	}
};