template <class T_key, class T_value>
struct node {
	node(T_key k, T_value v) : key(k), value(v) {};
	T_key key;
	T_value value;
};