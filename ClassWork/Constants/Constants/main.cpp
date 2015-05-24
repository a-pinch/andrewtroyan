#include "String.h"

#include <iostream>

using namespace std;

int main() {
	/*
	const String test = "Hello!";
	String a, c;
	test.print();

	cout << test.c_str() << endl;

	int b = sqr(1 + 11 * 2);
	cout << b << endl;*/

	/*
	String b = "Hello", a = "world";
	a = b;
	a.print();*/

	String a = "Hello", b = " world!";
	String c = a.plus(b);
	c.print();

	String d = "Hello";
	d.regUp();
	d.print();

	String e = "ABCD";
	String f = e.first(2);
	f.print();

	String g = e.last(2);
	g.print();

	String h = c.takeSubStr(7, 5);
	h.print();

	String i = "         Hello!       ";
	i.deleteSpaces();
	i.print();

	getc(stdin);
	return 0;
}