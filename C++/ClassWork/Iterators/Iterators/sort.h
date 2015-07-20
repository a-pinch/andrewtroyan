#pragma once

template <class T>
void my_sort(T begin, T end) {
	if (begin.host == end.host) {
		size_t amount_of_elements = 0;
		for (auto it = begin; it != end; ++it)
			++amount_of_elements;

		for (size_t i = 0; i < amount_of_elements - 1; ++i) {
			for (size_t j = 0; j < amount_of_elements - 1 - i; ++j) {
				if (*(begin + j) > *(begin + j + 1)) {
					auto max = *(begin + j);
					*(begin + j) = *(begin + j + 1);
					*(begin + j + 1) = max;
				}
			}
		}
	}
}