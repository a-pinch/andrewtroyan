#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <new>

using namespace std;

template <class T>
class List {
protected:
	struct Node {
		T data;
		Node *next, *prev;
	};

	Node *head, *tail;
	size_t size;
public:
	class Iterator { //instrument for list (like a pointer for standart arrays)
	protected:
		List *host;
		Node *current;
	public:
		Iterator() : current(nullptr), host(nullptr) {};
		Iterator(Node *current_, List *host_) : current(current_), host(host_) {};

		Iterator& operator++();
		Iterator& operator++(int);
		Iterator& operator--();
		Iterator& operator--(int);
		bool operator==(const Iterator& what) const { return current == what.current; };
		bool operator!=(const Iterator& what) const { return current != what.current; };
		T& operator*() const;
		Iterator& operator+=(const size_t& num);
		Iterator operator+(const size_t& num);
		Iterator& operator-=(const size_t& num);
		Iterator operator-(const size_t& num);
		T& operator[](const int& num);

		friend class List;
	};

	List() : head(nullptr), tail(nullptr), size(0) {};
	List(const List& orig);
	~List();

	List& pushFront(const T& data);
	List& pushBack(const T& data);
	List& popFront();
	List& popBack();
	List& insert(const size_t& index, const T& data);
	List& erase(const size_t& index);
	List& clear();
	bool empty() const { return head == nullptr; };
	const size_t& getSize() const { return size; };
	Iterator begin() { return Iterator(head, this); };
	Iterator end() { return Iterator(nullptr, this); };
	List& merge(const List& what);
	void swap(List& what);
	void sort(size_t startIndex, size_t endIndex, bool(*function)(const T& a, const T& b));
	List& reverse();
	Iterator find(const T& data);
	List& erase(Iterator& it);

	List& operator=(const List& what);

	template <class T>
	friend ostream& operator<<(ostream& out, const List<T>& what);
};

template <class T>
bool ascend(const T& a, const T& b) { //function for sorting (ascend list values)
	return a < b;
}

template <class T>
bool reduce(const T& a, const T& b) { //function for sorting (reduce list values)
	return a > b;
}

template <class T>
ostream& operator<<(ostream& out, const List<T>& what) {
	List<T>::Node *temp = what.head;
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