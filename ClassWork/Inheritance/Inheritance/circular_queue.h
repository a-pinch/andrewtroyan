#pragma once

#include "../../../HomeWork/BiConnectedList/BiConnectedList/List.h"

using namespace std;

template <class T>
class circular_queue : public List<T> {
public:
	circular_queue() : List() {};
	~circular_queue() {};

	class iterator : public List<T>::Iterator { //list's iterator won't be inherited
	public:
		iterator() : List<T>::Iterator() {};
		iterator(List<T>::Node *current, circular_queue *host) : List<T>::Iterator(current, host) {}; //(List<T>*) host

		iterator& operator++() {
			if (current == nullptr || host == nullptr) 
				throw invalid_argument("In List<T>::Iterator::operator++(): invalid iterator.");

			current = current->next;

			//if (!current) {
			//	current = host->head;
			//}
			//return *this;
		}

		iterator& operator++(int) {
			return ++(*this);
		}
	};

	iterator begin() {
		return iterator(head, this);
	}

	iterator end() {
		return iterator(nullptr, this);
	}
};