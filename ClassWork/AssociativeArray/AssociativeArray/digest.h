#include <string>

using namespace std;

template <class T> 
int digest(T key);

int digest(int key) {
	int code = 0;
	for (; key; key /= 10) 
		code += key % 10;
	return code;
}

int digest(string key) {
	int code = 0;
	for (size_t i = 0; i < key.size(); ++i)
		code += (int)key[0];
	return code;
}

int digest(double key) {
	int code = 0;
	while (key - (int)key)
		key *= 10;
	for (; key; key /= 10)
		code += (int)key % 10;
	return code;
}

int digest(float key) {
	int code = 0;
	while (key - (int)key)
		key *= 10;
	for (; key; key /= 10)
		code += (int)key % 10;
	return code;
}