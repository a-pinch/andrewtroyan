#pragma once

#include <iostream>
#include <exception>
#include <new>

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
		Iterator& operator=(const int& data) { current->data = data; return *this; };
		bool operator==(const Iterator& what) const { return current == what.current; };
		bool operator!=(const Iterator& what) const { return current != what.current; };
		int& operator*() const;
	};

	List() : head(nullptr), tail(nullptr), size(0) {};
	List(const List& orig);
	~List();

	List& pushFront(const int& data);
	List& pushBack(const int& data);
	List& popFront();
	List& popBack();
	List& insert(const size_t& index, const int& data);
	List& erase(const size_t& index);
	List& clear();
	bool empty() const { return head == nullptr; };
	const size_t& getSize() const { return size; };
	Iterator begin() const;
	Iterator end() const;
	List& merge(const List& what);
	void swap(List& what);
	void sort(size_t startIndex, size_t endIndex);

	List& operator=(const List& what);
	Iterator operator[](const size_t& index) const;

	friend ostream& operator<<(ostream& out, const List& what);
};

ostream& operator<<(ostream& out, const List& what);

