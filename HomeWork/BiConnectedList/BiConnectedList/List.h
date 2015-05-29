#pragma once

#include <iostream>

using namespace std;

class List {
private:
	struct Node {
		int data;
		Node *next, *prev;
	};

	Node *head, *tail;
	size_t size;
public:
	List() : head(nullptr), tail(nullptr), size(0) {};
	~List();

	List& pushFront(int data);
	List& pushBack(int data);
	List& popFront();
	List& popBack();
	bool empty() const { return head == nullptr; };
	const size_t& getSize() const { return size; };

	int& operator[](size_t index);
	friend ostream& operator<<(ostream& out, const List& what);
};

ostream& operator<<(ostream& out, const List& what);

