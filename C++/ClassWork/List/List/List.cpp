#include "List.h"

#include <cstdlib>
#include <iostream>

using namespace std;

//int List::junk; //reserve static memory for our static field (it doesn't belong to object, it belongs to class!)

template <class T>
List<T>::List(const List& orig) {
	first = nullptr;
	Node* temp = orig.first;
	for (size_t i = 0; i < orig.size; ++i, temp = temp->next)
		pushBack(temp->data);
	size = orig.size;
}

template <class T>
List<T>::~List() {
	while (size > 0)
		popFront();
}

template <class T>
List<T>& List<T>::pushFront(T data) {
	Node *temp = new Node;
	temp->data = data;
	temp->next = first;
	first = temp;
	++size;
	return *this;
}

template <class T>
List<T>& List<T>::pushBack(T data) {
	if (first == nullptr)
		pushFront(data);
	else {
		Node *temp = new Node;
		temp->data = data;
		temp->next = nullptr;
		
		Node *temp2 = first;
		while (temp2->next != nullptr)
			temp2 = temp2->next;
		temp2->next = temp;

		++size;
	}
	return *this;
}

template <class T>
List<T>& List<T>::pushInIndex(T data, size_t index) {
	if (index >= 0 && index < size) {
		if (index == 0)
			pushFront(data);
		else if (index == size - 1)
			pushBack(data);
		else {
			Node *temp = new Node;
			temp->data = data;

			Node *temp2 = first;
			for (size_t i = 0; i < index - 1; ++i)
				temp2 = temp2->next;

			temp->next = temp2->next;
			temp2->next = temp;
			
			++size;
		}
	}
	return *this;
}

template <class T>
List<T>& List<T>::popFront() {
	if (first != nullptr) {
		Node *temp = first;
		first = first->next;
		delete temp;
		--size;
		return *this;
	}
	throw 1;
}

template <class T>
List<T>& List<T>::popBack() {
	if (first != nullptr) {
		if (first->next == nullptr)
			popFront();
		else {
			Node *temp = first;
			while (temp->next->next != nullptr)
				temp = temp->next;
			free(temp->next);
			temp->next = nullptr;
			--size;
		}
		return *this;
	}
	throw 1;
}

template <class T>
List<T>& List<T>::popFromIndex(size_t index) {
	if (index >= 0 && index < size) {
		if (index == 0)
			popFront();
		else if (index == size - 1)
			popBack();
		else {
			Node *temp = first;
			for (size_t i = 0; i < index - 1; ++i)
				temp = temp->next;

			Node *nodeToDelete = temp->next;

			temp->next = temp->next->next;
			delete nodeToDelete;

			--size;
		}
		return *this;
	}
	throw 1;
}

template <class T>
void List<T>::printAll() {
	Node *temp = first;
	cout << "{";
	for (size_t i = 0; i < size; ++i, temp = temp->next) {
		cout << temp->data;
		if (i != size - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

template <class T>
T& List<T>::operator[](size_t index) {
	if (index < size) {
		Node *temp = first;
		for (size_t i = 0; i < index; ++i)
			temp = temp->next;
		return temp->data;
	}
	throw 2;
}

template <class T>
List<T>& List<T>::operator=(const List& orig) {
	while (size > 0)
		popFront();
	Node* temp = orig.first;
	for (size_t i = 0; i < orig.size; ++i, temp = temp->next)
		pushBack(temp->data);
	size = orig.size;
	return *this;
}

template List<int>;