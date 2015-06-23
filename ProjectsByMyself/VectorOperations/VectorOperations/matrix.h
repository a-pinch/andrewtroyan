#pragma once

#include <initializer_list>
#include <iostream>
#include <exception>
#include <stdexcept>

template <class T>
class matrix {
private:
	size_t rows, cols;
	T* array;
public:
	class matrix_row {
	private:
		T* element;
		size_t amount;
	public:
		matrix_row(T* pointer, size_t cols) : element(pointer), amount(cols) {};
		~matrix_row() {};

		T& operator[](size_t index) {
			if (index < amount) 
				return element[index];
			throw std::out_of_range("In matrix<T>::matrix_row::operator[](size_t): invalid index.");
		}
	};
	
	//ctor and dtor
	matrix(size_t rows_, size_t cols_, std::initializer_list<T> list);
	matrix(const matrix& orig);
	matrix(matrix&& orig);
	~matrix() { delete[] array; };

	//operators (matrix only)
	matrix& operator=(const matrix& orig);
	matrix& operator=(matrix&& orig);
	bool operator==(const matrix& obj);
	bool operator!=(const matrix& obj) { return !(*this == obj); };
	matrix& operator+=(const matrix& obj);
	matrix operator+(const matrix& obj);
	matrix& operator-=(const matrix& obj);
	matrix operator-(const matrix& obj);

	matrix_row operator[](size_t index) {
		if (index < rows) 
			return matrix_row(array + (index * cols), cols);
		throw std::out_of_range("In matrix<T>::operator[](size_t): invalid index.");
	}

	//operators (matrix and number)
	matrix& operator*=(const double& num);
	matrix operator*(const double &num);
	matrix& operator/=(const double& num);
	matrix operator/(const double& num);

	//friendly functions
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, const matrix<T>& obj);

	//template <class T>
	//matrix<T> operator*(const int& num, const matrix<T>& obj);
};


//ctors and dtor

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


//operators (matrix only)

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

template<class T>
bool matrix<T>::operator==(const matrix<T>& obj) {
	if (rows == obj.rows && cols == obj.cols) {
		for (size_t i = 0; i < rows * cols; ++i) {
			if (array[i] != obj.array[i])
				return false;
		}
		return true;
	}
	return false;
}

template <class T>
matrix<T>& matrix<T>::operator+=(const matrix<T>& obj) {
	if (rows == obj.rows && cols == obj.cols) {
		for (size_t i = 0; i < rows * cols; ++i)
			array[i] += obj.array[i];
		return *this;
	}
	throw std::invalid_argument("In matrix<T>::operator+=(const matrix<T>&): matrixes have different sizes.");
}

template <class T>
matrix<T> matrix<T>::operator+(const matrix<T>& obj) {
	if (rows == obj.rows && cols == obj.cols) {
		matrix<T> temp(*this);
		temp += obj;
		return temp;
	}
	throw std::invalid_argument("In matrix<T>::operator+(const matrix<T>&): matrixes have different sizes.");
}

template <class T>
matrix<T>& matrix<T>::operator-=(const matrix<T>& obj) {
	if (rows == obj.rows && cols == obj.cols) {
		for (size_t i = 0; i < rows * cols; ++i)
			array[i] -= obj.array[i];
		return *this;
	}
	throw std::invalid_argument("In matrix<T>::operator-=(const matrix<T>&): matrixes have different sizes.");
}

template <class T>
matrix<T> matrix<T>::operator-(const matrix<T>& obj) {
	if (rows == obj.rows && cols == obj.cols) {
		matrix<T> temp(*this);
		temp -= obj;
		return temp;
	}
	throw std::invalid_argument("In matrix<T>::operator-(const matrix<T>&): matrixes have different sizes.");
}

//operators (matrix and number)

template <class T>
matrix<T>& matrix<T>::operator*=(const double& num) {
	for (size_t i = 0; i < rows * cols; ++i)
		array[i] *= num;
	return *this;
}

template <class T>
matrix<T> matrix<T>::operator*(const double& num) {
	matrix<T> temp(*this);
	temp *= num;
	return temp;
}

template <class T>
matrix<T>& matrix<T>::operator/=(const double& num) {
	for (size_t i = 0; i < rows * cols; ++i)
		array[i] /= num;
	return *this;
}

template <class T>
matrix<T> matrix<T>::operator/(const double& num) {
	matrix<T> temp(*this);
	temp /= num;
	return temp;
}

//friendly functions

template <class T>
std::ostream& operator<<(std::ostream& out, const matrix<T>& obj) {
	for (size_t i = 0; i < obj.rows; ++i) {
		for (size_t j = 0; j < obj.cols; ++j) {
			out << obj.array[i * obj.cols + j] << " ";
		}
		if(i != obj.rows - 1) cout << endl;
	}
	return out;
}
