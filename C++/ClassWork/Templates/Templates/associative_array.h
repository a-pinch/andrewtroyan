#pragma once

#include <cstring>

using namespace std;

template <class KEY, class VALUE>
class associative_array {
private:
	struct Node {
		KEY key;
		VALUE value;
		Node* next;
	};

	Node **array;
	size_t arraySize;

	int hash(const KEY clue) const;
	void clearList(Node **list);
public:
	associative_array(size_t size);
	~associative_array();

	associative_array& add(const KEY key, const VALUE value);
	const VALUE& find(const KEY key) const;
	associative_array& remove(const KEY key);

	VALUE& operator[](const KEY key) const;
};

//template <class T>
//int associative_array<T>::hash(const KEY key) const {
//	int code = 0;
//	for (size_t i = 0; i < strlen(key); ++i)
//		code += (int)key[i];
//	return code % arraySize;
//}

template <class KEY, class VALUE>
void associative_array<KEY, VALUE>::clearList(Node **list) {
	Node *temp = *list;
	while (*list) {
		temp = *list;
		(*list) = (*list)->next;
		free(temp);
	}
}

template <class KEY, class VALUE>
associative_array<KEY, VALUE>::associative_array(size_t size) {
	array = new Node*[size];
	arraySize = size;
	for (int i = 0; i < arraySize; ++i)
		array[i] = nullptr;
}

template <class KEY, class VALUE>
associative_array<KEY, VALUE>::~associative_array<KEY, VALUE>() {
	for (int i = 0; i < arraySize; ++i)
		clearList(&(array[i]));
	free(array);
}
