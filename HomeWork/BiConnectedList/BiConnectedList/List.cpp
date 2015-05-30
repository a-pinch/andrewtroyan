#include "List.h"

#include <iostream>
#include <new>

using namespace std;

List::Iterator& List::Iterator::operator++() {
	if (current != nullptr)
		current = current->next;
	return *this;
}

List::Iterator& List::Iterator::operator--() {
	if (current->prev != nullptr)
		current = current->prev;
	return *this;
}

int& List::Iterator::operator*() const {
	if (current != nullptr)
		return current->data;
	throw exception("In List::Iterator::operator*(): memory access denial.");
}

void List::Iterator::insert(const int& what) {
	if (current == nullptr)
		throw exception("In List::Iterator::push(const int&): invalid value of iterator.");
	else if (current->prev == nullptr)
		throw exception("In List::Iterator::push(const int&): you can't use 0 index of iterator.");
		
	Node *temp = new Node;
	temp->data = what;
	temp->prev = current->prev;
	temp->next = current;

	current->prev->next = temp;
	current->prev = temp;
}

List::Iterator& List::Iterator::operator[](size_t index) {
	if (current == nullptr) 
		throw exception("In List::Iterator::operator[](): memory access denial.");

	while (current->prev != nullptr)
		current = current->prev;

	size_t count = 0;
	for (; current != nullptr, count < index; ++count)
		current = current->next;
	
	if (current == nullptr)
		throw exception("In List::Iterator::operator[](): memory access denial.");

	return *this;
}

List::~List() {
	while (size > 0)
		popFront();
}

List& List::pushFront(const int& data) {
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

List& List::pushBack(const int& data) {
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

List& List::popFront() {
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
	throw exception("In List::popFront(): empty list.");
}

List& List::popBack() {
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
	throw exception("In List::popFront(): empty list.");
}

List::Iterator List::begin() const {
	return List::Iterator(head);
}

List::Iterator List::end() const {
	return List::Iterator(tail->next);
}

ostream& operator<<(ostream& out, const List& what) {
	List::Node *temp = what.head;
	out << '{';
	while (temp != nullptr) {
		if (temp->next != nullptr)
			out << temp->data << ", ";
		else
			out << temp->data;
		temp = temp->next;
	}
	out << "}";
	return out;
}