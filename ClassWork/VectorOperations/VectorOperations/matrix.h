#pragma once

#include <initializer_list>
#include <iostream>

template <class T>
class matrix {
private:
	size_t rows, cols;
	T* array;
public:
	matrix(size_t rows_, size_t cols_, std::initializer_list<T> list);
	matrix(const matrix& orig);
	matrix(matrix&& orig);
	~matrix() { delete[] array; };

	matrix& operator=(const matrix& orig);
	matrix& operator=(matrix&& orig);

	template <class T>
	friend std::ostream& operator<< (std::ostream& out, const matrix<T>& obj);
};

template <class T>
matrix<T>::matrix(size_t rows_, size_t cols_, std::initializer_list<T> list) : rows(rows_), cols(cols_), array(new T[rows * cols]) {
	size_t i = 0;

	for (auto it = list.begin(); it != list.end() && i < rows * cols; ++it, ++i) 
		array[i] = *it;

	while (i < rows * cols) {
		array[i] = 0;
		++i;
	}
}

template <class T>
matrix<T>::matrix(const matrix<T>& orig) : rows(orig.rows), cols(orig.cols), array(new T[rows * cols]) {
	for (size_t i = 0; i < rows * cols; ++i)
		array[i] = orig.array[i];
}

template <class T>
matrix<T>::matrix(matrix<T>&& orig) : rows(orig.rows), cols(orig.cols), array(orig.array) {
	orig.array = nullptr;
}

template <class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& orig) {
	delete[] array;

	rows = orig.rows;
	cols = orig.cols;
	array = new T[rows * cols];
	for (size_t i = 0; i < rows * cols; ++i)
		array[i] = orig.array[i];

	return *this;
}

template <class T>
matrix<T>& matrix<T>::operator=(matrix<T>&& orig) {
	delete[] array;

	rows = orig.rows;
	cols = orig.cols;
	array = orig.array;
	orig.array = nullptr;

	return *this;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const matrix<T>& obj) {
	for (size_t i = 0; i < obj.rows; ++i) {
		for (size_t j = 0; j < obj.cols; ++j) {
			out << obj.array[i * obj.cols + j] << " ";
		}
		cout << endl;
	}
	return out;
}