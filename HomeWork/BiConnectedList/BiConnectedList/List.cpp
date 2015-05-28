#include "List.h"

#include <iostream>
#include <new>

using namespace std;

List::~List() {
}

List& List::pushFront(int data) {
	Node *temp = new Node;
	temp->data = data;
	temp->next = head;
	temp->prev = nullptr;

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
		head->prev = nullptr;
		delete temp;
		--size;

		if (size == 0)
			tail = nullptr;

		return *this;
	}
	throw exception("In List::popFront(): empty list.\n");
}

bool List::empty() const {
	return head == nullptr;
}