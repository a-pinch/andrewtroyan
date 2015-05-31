#include "List.h"

using namespace std;

//Iterator's methods

List::List(const List& orig) {
	head = nullptr;
	tail = nullptr;
	size = 0;
	Node* temp = orig.head;
	for (size_t i = 0; i < orig.size; ++i, temp = temp->next) 
		pushBack(temp->data);
}

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

// List's methods

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

List& List::insert(const size_t& index, const int& data) {
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

List& List::erase(const size_t& index) { //delete list value with defined index
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

List& List::clear() {
	while (size > 0)
		popFront();
	return *this;
}

List& List::merge(const List& what) {
	Node *temp = what.head;
	for (size_t i = 0; i < what.size; ++i, temp = temp->next)
		pushBack(temp->data);
	return *this;
}

void List::swap(List& what) {
	Node *tempHead = head, *tempTail = tail;
	size_t tempSize = size;
	head = what.head;
	tail = what.tail;
	size = what.size;
	what.head = tempHead;
	what.tail = tempTail;
	what.size = tempSize;
}

void List::sort(size_t startIndex, size_t endIndex, bool(*function)(const int& a, const int& b)) {
	if (startIndex < endIndex && startIndex < size && endIndex <size) {
		size_t i = startIndex;
		Iterator it1 = (*this)[startIndex], it2 = (*this)[endIndex];
		while (function(*it1, *it2)) {
			++it1;
			++i;
		}
		Iterator it3 = (*this)[i];
		for (size_t j = i; j < endIndex; ++j, ++it3) {
			if (function(*it3, *it2)) {
				int temp = *it3;
				*it3 = *it1;
				*it1 = temp;
				++i;
				++it1;
			}
		}
		int temp = *it1;
		*it1 = *it2;
		*it2 = temp;
		sort(startIndex, i - 1, function);
		sort(i + 1, endIndex, function);
	}
}

List& List::reverse() {
	if (size > 0) {
		Iterator start = (*this)[0], end = (*this)[size - 1];
		for (size_t i = 0; i < size / 2; ++i, ++start, --end) {
			int temp = *start;
			*start = *end;
			*end = temp;
		}
		return *this;
	}
	throw exception("In List::reverse(): list is empty.");
}

List& List::operator=(const List& what) {
	while (size > 0)
		popFront();
	Node* temp = what.head;
	for (size_t i = 0; i < what.size; ++i, temp = temp->next) 
		pushBack(temp->data);
	return *this;
}

List::Iterator List::operator[](const size_t& index) const {
	if (index >= size)
		throw out_of_range("In List::insert(const size_t&): index is out of range.");

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

	return Iterator(temp);
}

//Functions

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

bool ascend(const int& a, const int& b) { //function for sorting (ascend list values)
	return a < b;
}

bool reduce(const int& a, const int& b) { //function for sorting (reduce list values)
	return a > b;
}