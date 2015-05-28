#pragma once

#include <iostream>

using namespace std;

int cnt = 0;

class A {
public:
	A() {
		cout << "A()" << endl;
		if (cnt > 0)
			throw 1;
		++cnt;
	}
	~A() {
		cout << "~A()" << endl;
	}
};

class B {
public:
	A a, b;
	B() {
		cout << "B()" << endl;
	}
	~B() {
		cout << "B()" << endl;
	}
	void method() {
		cout << "method()" << endl;
	}
};

