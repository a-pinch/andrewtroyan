#pragma once

class List { //data structure
private:
	struct Node { //container
		int data;
		Node *next;
	};

	Node *first;
	size_t size;
	static int junk; //variable for errors
public:
	List() : first(nullptr), size(0) {}; //initialization list (now we can initialize constants and call different constructors)
	List(const List& orig);
	~List();

	List& pushFront(int data);
	List& pushBack(int data);
	List& popFront();
	List& popBack();
	size_t getSize() { //getter method
		return size;
	}

	void printAll();

	int& operator[](size_t index);
	List& operator=(const List& orig);
};

