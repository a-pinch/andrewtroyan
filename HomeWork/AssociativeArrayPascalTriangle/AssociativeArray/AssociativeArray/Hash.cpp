#include "Hash.h"

#include <cstdlib>
#include <iostream>

int Hash::hash(const char* key) const {
	int code = 0;
	for (size_t i = 0; i < strlen(key); ++i)
		code += (int)key[i];
	return code % arraySize;
}

void Hash::clearList(Node **list) {
	Node *temp = *list;
	while (*list) {
		temp = *list;
		(*list) = (*list)->next;
		free(temp);
	}
}

Hash::Hash(int size) {
	array = (Node **)malloc(size * sizeof(Node *));
	arraySize = size;
	for (int i = 0; i < arraySize; ++i)
		array[i] = nullptr;
}

Hash::~Hash() {
	for (int i = 0; i < arraySize; ++i)
		clearList(&(array[i]));
	free(array);
}

Hash& Hash::add(const char* key, const double value) {
	int hashCode = hash(key);

	Node* newNode = nullptr;
	newNode = (Node *)malloc(sizeof(Node));
	if (newNode == nullptr) 
		return *this;

	strcpy(newNode->key, key);
	newNode->value = value;
	newNode->next = nullptr;

	if (!(array[hashCode]))
		array[hashCode] = newNode;
	else {
		Node *temp = array[hashCode];
		while (strcmp(temp->key, key) && temp->next)
			temp = temp->next;

		if (!strcmp(temp->key, key)) {
			free(newNode);
			return *this;
		}

		temp->next = newNode;
		temp = nullptr;
	}
	return *this;
}

double Hash::find(const char* key) const {
	int hashCode = hash(key);
	Node *temp = array[hashCode];
	while (temp && strcmp(temp->key, key))
		temp = temp->next;
	if (!temp)
		return 0.0;
	return temp->value;
}

Hash& Hash::remove(const char* key) {
	int hashCode = hash(key);

	Node *temp = array[hashCode];

	if (!temp)
		return *this;
	else if (!strcmp(temp->key, key)) {
		array[hashCode] = temp->next;
		free(temp);
		return *this;
	}

	while (temp->next && strcmp(temp->next->key, key))
		temp = temp->next;

	if (!strcmp(temp->next->key, key)) {
		Node *nodeToDelete = temp->next;
		temp->next = temp->next->next;
		free(nodeToDelete);
	}

	return *this;
}

double Hash::operator[](const char* key) const {
	int hashCode = hash(key);
	Node *temp = array[hashCode];
	while (temp && strcmp(temp->key, key))
		temp = temp->next;
	if (!temp)
		return 0.0;
	return temp->value;
}