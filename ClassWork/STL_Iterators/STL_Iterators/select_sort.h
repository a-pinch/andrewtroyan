
template <class it>
void select_sort(it from, it to) {
	for (auto i = from; i != to; ++i) {
		for (auto j = i; j != to; ++j) {
			if (*i > *j) {
				std::swap(*i, *j);
			}
		}
	}
}