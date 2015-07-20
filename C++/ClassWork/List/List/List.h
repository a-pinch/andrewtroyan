#pragma once

#include <exception>

template <class T>
class List { //data structure
private:
	struct Node { //container
		T data;
		Node *next;
	};

	Node *first;
	size_t size;
	//static int junk; //variable for errors
public:
	class Iterator {
	private:
		Node *current;
	public:
		Iterator() : current(nullptr) {};
		Iterator(Node *current) { this->current = current; };
		Iterator& operator++() { current = current->next; return *this; };
		int& operator*() { return current->data; };
		bool operator==(const Iterator& what) { return current == what.current; };
		bool operator!=(const Iterator& what) { return !(*this == what); };
	};

	List() : first(nullptr), size(0) {}; //initialization list (now we can initialize constants and call different constructors)
	List(const List& orig);
	~List();

	Iterator begin() { return Iterator(first); };
	Iterator end() { return Iterator(nullptr); };
	Iterator find(const T& data) {
		Node *temp = first;
		while (temp) {
			if (temp->data == data)
				return Iterator(temp);
			temp = temp->next;
		}
		return Iterator(nullptr);
	};

	List& pushFront(T data);
	List& pushBack(T data);
	List& pushInIndex(T data, size_t index);
	List& popFront();
	List& popBack();
	List& popFromIndex(size_t index);
	size_t getSize() { //getter method
		return size;
	}

	void printAll();

	T& operator[](size_t index);
	List& operator=(const List& orig);
};

