#pragma once

#include <initializer_list>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>

using std::vector;

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
	matrix(size_t rows_, size_t cols_);
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
	matrix operator*(const matrix& obj);
	matrix& operator*=(const matrix& obj);

	matrix_row operator[](size_t index) const {
		if (index < rows) 
			return matrix_row(array + (index * cols), cols);
		throw std::out_of_range("In matrix<T>::operator[](size_t): invalid index.");
	}

	//operators (matrix and number)
	matrix& operator*=(const double& num);
	matrix operator*(const double &num);
	matrix& operator/=(const double& num);
	matrix operator/(const double& num);

	//operators (matrix and vector)
	vector<T> operator*(const vector<T>& obj);
	matrix& operator*=(const vector<T>& obj);

	//friendly functions
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, const matrix<T>& obj);

	template <class T>
	friend matrix<T> operator*(const double& num, const matrix<T>& obj);

	template <class T>
	friend vector<T> operator*(const vector<T>& vec, const matrix<T>& mat);

	template <class T>
	friend vector<T>& operator*=(vector<T>& vec, const matrix<T>& mat);
};


//ctors and dtor

template <class T>
matrix<T>::matrix(size_t rows_, size_t cols_) : rows(rows_), cols(cols_), array(new T[rows * cols]) {
	for (size_t i = 0; i < rows * cols; ++i)
		array[i] = 0;
}

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

template <class T>
matrix<T> matrix<T>::operator*(const matrix<T>& obj) {
	if (cols == obj.rows) {
		matrix<T> result(rows, obj.cols);
		for (size_t i = 0; i < result.rows; ++i) {
			for (size_t j = 0; j < result.cols; ++j) {
				for (size_t k = 0, l = 0; k < cols && l < rows; ++k, ++l) {
					result[i][j] += (*this)[i][k] * obj[l][j];
				}
			}
		}
		return result;
	}
	throw std::invalid_argument("In matrix<T>::operator*(const matrix&): inappropriate matrixes.");
}

template <class T>
matrix<T>& matrix<T>::operator*=(const matrix<T>& obj) {
	if (cols == obj.rows) {
		*this = (*this) * obj;
		return *this;
	}
	throw std::invalid_argument("In matrix<T>::operator*=(const matrix&): inappropriate matrixes.");
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

//operators (matrix and vector)

template <class T>
vector<T> matrix<T>::operator*(const vector<T>& obj) {
	if (cols == obj.size()) {
		vector<T> result;
		for (size_t i = 0; i < rows; ++i) {
			T temp = 0;
			for (size_t k = 0, l = 0; k < cols && l < obj.size(); ++k, ++l) {
				temp += (*this)[i][k] * obj[l];
			}
			result.push_back(temp);
		}
		return result;
	}
	throw std::invalid_argument("In matrix<T>::operator*(const vector<T>&): invalid values.");
}

template <class T>
matrix<T>& matrix<T>::operator*=(const vector<T>& obj) {
	if (cols == obj.size()) {
		matrix<T> temp = std::move(*this);
		cols = 1;
		array = new T[rows];
		for (size_t i = 0; i < rows; ++i)
			array[i] = 0;

		for (size_t i = 0; i < rows; ++i) {
			for (size_t k = 0, l = 0; k < temp.cols && l < obj.size(); ++k, ++l) {
				array[i] += temp[i][k] * obj[l];
			}
		}

		return *this;
	}
	throw std::invalid_argument("In matrix<T>::operator*=(const vector<T>&): invalid values.");
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

template <class T>
matrix<T> operator*(const double& num, const matrix<T>& obj) {
	matrix<T> temp(obj);
	obj *= num;
	return obj;
}

template <class T>
vector<T> operator*(const vector<T>& vec, const matrix<T>& mat) {
	if (mat.cols == vec.size()) {
		vector<T> result;
		for (size_t i = 0; i < mat.rows; ++i) {
			T temp = 0;
			for (size_t k = 0, l = 0; k < mat.cols && l < vec.size(); ++k, ++l) {
				temp += mat[i][k] * vec[l];
			}
			result.push_back(temp);
		}
		return result;
	}
	throw std::invalid_argument("In operator*(const vector<T>&, const matrix<T>&): invalid values.");
}

template <class T>
vector<T>& operator*=(vector<T>& vec, const matrix<T>& mat) {
	if (mat.cols == vec.size()) {
		vec = vec * mat;
		return vec;
	}
	throw std::invalid_argument("In operator*=(vector<T>&, const matrix<T>&): invalid values.");
}
