#include "Array.h"

#include <cstdlib>

Array::Array(int num) {
	array = (int *)malloc(num * sizeof(int));
	if (array == nullptr)
		throw 1;
}


Array::~Array() {
	free (array);
}
