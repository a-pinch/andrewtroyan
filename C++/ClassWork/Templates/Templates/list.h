#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <new>

using namespace std;

template <class T>
class list {
private:
	struct Node {
		T data;
		Node *next, *prev;
	};

	Node *head, *tail;
	size_t size;
public:
	list() : head(nullptr), tail(nullptr), size(0) {};
	list(const list& orig);
	~list();

	list& pushFront(const T& data);
	list& pushBack(const T& data);
	list& popFront();
	list& popBack();
	list& insert(const size_t& index, const T& data);
	list& erase(const size_t& index);
	list& clear();
	bool empty() const { return head == nullptr; };
	const size_t& getSize() const { return size; };
	list& merge(const list& what);
	void swap(list& what);
	list& reverse();
	void printAll();

	list& operator=(const list& what);
};

template <class T>
list<T>::list(const list<T>& orig) {
	head = nullptr;
	tail = nullptr;
	size = 0;
	Node* temp = orig.head;
	for (size_t i = 0; i < orig.size; ++i, temp = temp->next)
		pushBack(temp->data);
}

template <class T>
list<T>::~list() {
	while (size > 0)
		popFront();
}

template <class T>
list<T>& list<T>::pushFront(const T& data) {
	Node *temp = new Node;
	temp->data = data;
	temp->next = head;
	temp->prev = nullptr;

	if (head != nullptr)
		head->prev = temp;

	head = temp;
	++size;

	if (size == 1)
		tail = head;

	return *this;
}

template <class T>
list<T>& list<T>::pushBack(const T& data) {
	if (size == 0)
		pushFront(data);
	else {
		Node* temp = new Node;
		temp->data = data;
		temp->next = nullptr;
		temp->prev = tail;

		tail->next = temp;
		tail = temp;
		++size;
	}
	return *this;
}

template <class T>
list<T>& list<T>::popFront() {
	if (size > 0) {
		Node *temp = head;
		head = head->next;

		if (head != nullptr)
			head->prev = nullptr;

		delete temp;
		--size;

		if (size == 0)
			tail = nullptr;

		return *this;
	}
	throw exception("In list<T>& list<T>::popFront(): empty list.");
}

template <class T>
list<T>& list<T>::popBack() {
	if (size == 1)
		popFront();
	else if (size > 0) {
		Node *temp = tail;
		tail = tail->prev;
		tail->next = nullptr;

		delete temp;
		--size;

		return *this;
	}
	throw exception("In list<T>& list<T>::popBack(): empty list.");
}

template <class T>
list<T>& list<T>::insert(const size_t& index, const T& data) {
	if (index > size)
		throw out_of_range("In list<T>::insert(const size_t& index, const T& data): index is out of range.");

	if (index == 0)
		pushFront(data);
	else if (index == size)
		pushBack(data);
	else {
		Node *temp;
		if (index <= (size - 1) / 2) {
			temp = head;
			for (size_t i = 0; i != index - 1; ++i)
				temp = temp->next;
		}
		else {
			temp = tail;
			for (size_t i = size - 1; i != index - 1; --i)
				temp = temp->prev;
		}

		Node *newNode = new Node;
		newNode->data = data;
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next->prev = newNode;
		temp->next = newNode;
	}
	return *this;
}

template <class T>
list<T>& list<T>::erase(const size_t& index) { 
	if (index >= size)
		throw out_of_range("In list<T>::erase(const size_t& index): index is out of range.");

	if (index == 0)
		popFront();
	else if (index == size - 1)
		popBack();
	else {
		Node *temp;
		if (index <= (size - 1) / 2) {
			temp = head;
			for (size_t i = 0; i != index; ++i)
				temp = temp->next;
		}
		else {
			temp = tail;
			for (size_t i = size - 1; i != index; --i)
				temp = temp->prev;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		--size;
	}
	return *this;
}

template <class T>
list<T>& list<T>::clear() {
	while (size > 0)
		popFront();
	return *this;
}

template <class T>
list<T>& list<T>::merge(const list<T>& what) {
	Node *temp = what.head;
	for (size_t i = 0; i < what.size; ++i, temp = temp->next)
		pushBack(temp->data);
	return *this;
}

template <class T>
void list<T>::swap(list<T>& what) {
	Node *tempHead = head, *tempTail = tail;
	size_t tempSize = size;
	head = what.head;
	tail = what.tail;
	size = what.size;
	what.head = tempHead;
	what.tail = tempTail;
	what.size = tempSize;
}

template <class T>
list<T>& list<T>::reverse() {
	if (size > 0) {
		Node *start = head, *end = tail;
		for (size_t i = 0; i < size / 2; ++i, start = start->next, end = end->prev) {
			int temp = start->data;
			start->data = end->data;
			end->data = temp;
		}
		return *this;
	}
	throw exception("In list<T>::reverse(): list is empty.");
}

template <class T>
list<T>& list<T>::operator=(const list<T>& what) {
	while (size > 0)
		popFront();
	Node* temp = what.head;
	for (size_t i = 0; i < what.size; ++i, temp = temp->next)
		pushBack(temp->data);
	return *this;
}

template <class T>
void list<T>::printAll() {
	Node *temp = head;
	cout << '{';
	while (temp != nullptr) {
		if (temp->next != nullptr)
			cout << temp->data << ", ";
		else
			cout << temp->data;
		temp = temp->next;
	}
	cout << "}";
}