//template <class T>
//T f(T x, T y);

template <class T> //template <typename T>
class Vector {
private:
	T* elements;
	size_t size;
public:
	Vector() : elements(nullptr), size(0) {};
	Vector(size_t size_, T initial) : size(size_) { 
		elements = new T[size]; 
		for (size_t i = 0; i < size; ++i) {
			elements[i] = initial;
		}
	}
	T& operator[](size_t index) {
		if (index < size)
			return elements[index];
		throw 0;
	}
	~Vector() { delete[] elements; };
};
