#include <string>

using namespace std;

template <class T> 
int digest(T key);

int digest(int key) {
	int code = 0;
	while (key) {
		code += key % 10;
		key /= 10;
	}
	return code;
}

int digest(string key) {
	int code = 0;
}