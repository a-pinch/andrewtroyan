#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <new>

using namespace std;

template <class T>
class List {
private:
	struct Node {
		T data;
		Node *next, *prev;
	};

	Node *head, *tail;
	size_t size;
public:
	class Iterator { //instrument for list (like a pointer for standart arrays)
	private:
		List *host;
		Node *current;
	public:
		Iterator() { current = nullptr; host = nullptr; };
		Iterator(Node *current, List *host) { this->current = current; this->host = host; };
		Iterator& operator++();
		Iterator& operator++(int);
		Iterator& operator--();
		Iterator& operator=(const Iterator& what) { current = what.current; return *this; };
		bool operator==(const Iterator& what) const { return current == what.current; };
		bool operator!=(const Iterator& what) const { return current != what.current; };
		T& operator*() const;

		friend class List;
	};

	List() : head(nullptr), tail(nullptr), size(0) {};
	List(const List& orig);
	~List();

	List& pushFront(const T& data);
	List& pushBack(const T& data);
	List& popFront();
	List& popBack();
	List& insert(const size_t& index, const T& data);
	List& erase(const size_t& index);
	List& clear();
	bool empty() const { return head == nullptr; };
	const size_t& getSize() const { return size; };
	Iterator begin() { return Iterator(head, this); };
	Iterator end() { return Iterator(nullptr, this); };
	List& merge(const List& what);
	void swap(List& what);
	//void sort(size_t startIndex, size_t endIndex, bool(*function)(const T& a, const T& b));
	List& reverse();
	Iterator find(const T& data);
	List& erase(Iterator& it);

	List& operator=(const List& what);

	//friend ostream& operator<<(ostream& out, const List& what);
};
