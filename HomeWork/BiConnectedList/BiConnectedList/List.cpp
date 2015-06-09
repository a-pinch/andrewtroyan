#include "List.h"

#include <string>

//Copy ctor

template <class T>
List<T>::List(const List<T>& orig) {
	head = nullptr;
	tail = nullptr;
	size = 0;
	Node* temp = orig.head;
	for (size_t i = 0; i < orig.size; ++i, temp = temp->next) 
		pushBack(temp->data);
}

//Iterator's methods

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
	if (current != nullptr) 
		current = current->next;
	return *this;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator++(int) {
	if (current != nullptr)
		current = current->next;
	return *this;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
	if (current->prev != nullptr) 
		current = current->prev;
	return *this;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator--(int) {
	if (current->prev != nullptr)
		current = current->prev;
	return *this;
}

template <class T>
T& List<T>::Iterator::operator*() const {
	if (current != nullptr)
		return current->data;
	throw exception("In List::Iterator::operator*(): memory access denial.");
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator+=(const int& num) {
	if (num == 0)
		return *this;

	Node *temp = current;
	int i = 0;
	for (; temp != nullptr && i < num; ++i) {
		temp = temp->next;
	}
	if (i == num) {
		current = temp;
		return *this;
	}
	throw invalid_argument("In List<T>::Iterator::operator+=(const size_t&): invalid value.");
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator+(const int& num) {
	if (num == 0)
		return Iterator(current, host);

	Node *temp = current;
	int i = 0;
	for (; temp != nullptr && i < num; ++i) {
		temp = temp->next;
	}
	if (i == num) 
		return Iterator(temp, host);
	throw invalid_argument("In List<T>::Iterator::operator+(const size_t&): invalid value.");
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator-=(const int& num) {
	if (num == 0)
		return *this;

	Node *temp = current;
	int i = num;
	for (; temp != nullptr && i > 0; --i) {
		temp = temp->prev;
	}
	if (i == 0) {
		current = temp;
		return *this;
	}
	throw invalid_argument("In List<T>::Iterator::operator-=(const size_t&): invalid value.");
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator-(const int& num) {
	if (num == 0)
		return Iterator(current, host);

	Node *temp = current;
	int i = num;
	for (; temp != nullptr && i > 0; --i) {
		temp = temp->prev;
	}
	if (i == 0) 
		return Iterator(temp, host);
	throw invalid_argument("In List<T>::Iterator::operator-(const size_t&): invalid value.");
}

// List's methods

template <class T>
List<T>::~List() {
	while (size > 0)
		popFront();
}

template <class T>
List<T>& List<T>::pushFront(const T& data) {
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
List<T>& List<T>::pushBack(const T& data) {
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
List<T>& List<T>::popFront() {
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

template <class T>
List<T>& List<T>::popBack() {
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

template <class T>
List<T>& List<T>::insert(const size_t& index, const T& data) {
	if (index > size)
		throw out_of_range("In List::insert(const size_t&): index is out of range.");

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
List<T>& List<T>::erase(const size_t& index) { //delete list value with defined index
	if (index >= size)
		throw out_of_range("In List::insert(const size_t&): index is out of range.");

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
List<T>& List<T>::clear() {
	while (size > 0)
		popFront();
	return *this;
}

template <class T>
List<T>& List<T>::merge(const List& what) {
	Node *temp = what.head;
	for (size_t i = 0; i < what.size; ++i, temp = temp->next)
		pushBack(temp->data);
	return *this;
}

template <class T>
void List<T>::swap(List& what) {
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
void List<T>::sort(size_t startIndex, size_t endIndex, bool(*function)(const T& a, const T& b)) {
	if (startIndex < endIndex && endIndex <size) {
		size_t i = startIndex;
		Iterator it1 = (*this).begin() + (int)startIndex, it2 = (*this).begin() + (int)endIndex;
		while (function(*it1, *it2)) {
			++it1;
			++i;
		}
		Iterator it3 = (*this).begin() + (int)i;
		for (size_t j = i; j < endIndex; ++j, ++it3) {
			if (function(*it3, *it2)) {
				T temp = *it3;
				*it3 = *it1;
				*it1 = temp;
				++i;
				++it1;
			}
		}
		T temp = *it1;
		*it1 = *it2;
		*it2 = temp;
		sort(startIndex, i - 1, function);
		sort(i + 1, endIndex, function);
	}
}

template <class T>
List<T>& List<T>::reverse() {
	if (size > 0) {
		Node *start = head, *end = tail;
		for (size_t i = 0; i < size / 2; ++i, start = start->next, end = end->prev) {
			T temp = start->data;
			start->data = end->data;
			end->data = temp;
		}
		return *this;
	}
	throw exception("In List::reverse(): list is empty.");
}

template <class T>
typename List<T>::Iterator List<T>::find(const T& data) {
	Node *temp = head;
	while (temp) {
		if (temp->data == data)
			return Iterator(temp, this);
		temp = temp->next;
	}
	return Iterator(nullptr, this);
}

template <class T>
List<T>& List<T>::erase(Iterator& it) {
	if (it.current->next == nullptr) 
		tail = it.current->prev;
	else 
		it.current->next->prev = it.current->prev;

	if (it.current->prev == nullptr) 
		head = it.current->next;
	else 
		it.current->prev->next = it.current->next;

	delete it.current;
	it.current = nullptr;
	--size;

	return (*this);
}

template <class T>
List<T>& List<T>::operator=(const List& what) {
	while (size > 0)
		popFront();
	Node* temp = what.head;
	for (size_t i = 0; i < what.size; ++i, temp = temp->next) 
		pushBack(temp->data);
	return *this;
}

template List<int>;
template List<string>;