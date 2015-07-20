#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>

template <class T>
class forward_list
{
private:
	struct Node {
		T data;
		Node *next;
	};

	Node* first;
	size_t size;
public:
	forward_list() : first(nullptr), size(0) {};
	forward_list(const forward_list<T>& orig);
	~forward_list();

	forward_list& pushFront(const T& data);
	forward_list& pushBack(const T& data);
	forward_list& pushInIndex(T data, size_t index);
	forward_list& popFront();
	forward_list& popBack();
	forward_list& popFromIndex(size_t index);
	void printAll();
	const size_t& getSize() { return size; };

	T& operator[](size_t index);
	forward_list& operator=(const forward_list& orig);
};

template <class T>
std::ostream& operator<<(std::ostream& out, const forward_list<T>& what);

template <class T>
forward_list<T>::forward_list(const forward_list<T>& orig) {
	first = nullptr;
	Node* temp = orig.first;
	for (size_t i = 0; i < orig.size; ++i, temp = temp->next)
		pushBack(temp->data);
	size = orig.size;
}

template <class T>
forward_list<T>::~forward_list() {
	while (size > 0)
		popFront();
}

template <class T>
forward_list<T>& forward_list<T>::pushFront(const T& data) {
	Node *temp = new Node;
	temp->data = data;
	temp->next = first;
	first = temp;
	++size;
	return *this;
}

template <class T>
forward_list<T>& forward_list<T>::pushBack(const T& data) {
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
forward_list<T>& forward_list<T>::pushInIndex(T data, size_t index) {
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
		return *this;
	}
	throw std::out_of_range("In forward_list<T>& forward_list<T>::pushInIndex(T data, size_t index): invalid index.");
}

template <class T>
forward_list<T>& forward_list<T>::popFront() {
	if (first != nullptr) {
		Node *temp = first;
		first = first->next;
		delete temp;
		--size;
		return *this;
	}
	throw exception("In forward_list<T>& forward_list<T>::popFront(): list is empty");
}

template <class T>
forward_list<T>& forward_list<T>::popBack() {
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
	throw exception("In forward_list<T>& forward_list<T>::popBack(): list is empty");
}

template <class T>
forward_list<T>& forward_list<T>::popFromIndex(size_t index) {
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
	throw std::out_of_range("In forward_list<T>& forward_list<T>::popFromIndex(T data, size_t index): invalid index.");
}

template <class T>
T& forward_list<T>::operator[](size_t index) {
	if (index < size) {
		Node *temp = first;
		for (size_t i = 0; i < index; ++i)
			temp = temp->next;
		return temp->data;
	}
	throw std::out_of_range("In T& forward_list<T>::operator[](size_t index): invalid index.");
}

template <class T>
forward_list<T>& forward_list<T>::operator=(const forward_list<T>& orig) {
	while (size > 0)
		popFront();
	Node* temp = orig.first;
	for (size_t i = 0; i < orig.size; ++i, temp = temp->next)
		pushBack(temp->data);
	size = orig.size;
	return *this;
}

template <class T>
void forward_list<T>::printAll() {
	Node *temp = first;
	cout << "{";
	for (size_t i = 0; i < size; ++i, temp = temp->next) {
		cout << temp->data;
		if (i != size - 1)
			cout << ", ";
	}
	cout << "}";
}

