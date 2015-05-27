#pragma once

#include <cstring>

using namespace std;

struct Node {
	char key[32];
	double value;
	Node* next;
};

class Hash {
private:
	Node **array;
	int arraySize;

	int hash(const char* clue) const;
	void clearList(Node **list);
public:
	Hash(int size);
	~Hash();

	Hash& add(const char* key, const double value);
	double find(const char* key) const;
	Hash& remove(const char* key);

	double operator[](const char* key) const;
};

