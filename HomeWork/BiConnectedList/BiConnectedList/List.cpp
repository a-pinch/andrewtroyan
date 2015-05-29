#include "List.h"

#include <iostream>
#include <new>

using namespace std;

List::~List() {
	while (size > 0)
		popFront();
}

List& List::pushFront(int data) {
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

List& List::pushBack(int data) {
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
	throw exception("In List::popFront(): empty list.\n");
}

int& List::operator[](size_t index) {
	if (index >= 0 && index < size) {
		Node *temp = head;
		for (size_t i = 0; i < index; ++i)
			temp = temp->next;
		return temp->data;
	}
	throw exception("In List::operator[]: invalid index.\n");
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