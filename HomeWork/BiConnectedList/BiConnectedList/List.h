#pragma once

class List {
private:
	struct Node {
		int data;
		Node *next, *prev;
	};

	Node *head, *tail;
	int size;
public:
	List() : head(nullptr), tail(nullptr), size(0) {};
	~List();

	List& pushFront(int data);
	List& pushBack(int data);
	List& popFront();
	List& popBack();
	bool empty() const;
};

