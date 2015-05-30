#pragma once

#include <iostream>
#include <exception>

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
	class Iterator {
	private:
		Node *current;
	public:
		Iterator() { current = nullptr; };
		Iterator(Node *current) { this->current = current; };
		Iterator& operator++();
		Iterator& operator--();
		Iterator& operator[](size_t index);
		bool operator==(const Iterator& what) const { return current == what.current; };
		bool operator!=(const Iterator& what) const { return current != what.current; };
		int& operator*() const;
		void insert(const int& what);
	};

	List() : head(nullptr), tail(nullptr), size(0) {};
	~List();

	List& pushFront(const int& data);
	List& pushBack(const int& data);
	List& popFront();
	List& popBack();
	bool empty() const { return head == nullptr; };
	const size_t& getSize() const { return size; };
	Iterator begin() const;
	Iterator end() const;

	friend ostream& operator<<(ostream& out, const List& what);
};

ostream& operator<<(ostream& out, const List& what);

