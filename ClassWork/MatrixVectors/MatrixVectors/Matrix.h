#pragma once

#include <vector>
#include <stdexcept>

template <class T>
class Matrix {
private:
	size_t cols, rows;
	vector<T> elements;
public:
	Matrix(size_t rows_, size_t columns) :
		rows(rows_), cols(columns),
		elements(rows*cols)
	{}
	~Matrix() { }
	Matrix(const Matrix& orig) = default;
	Matrix(Matrix&& temp) = default;
	T* operator[](size_t row_index) {
		return &(elements[row_index]);
	}

	bool operator==(const Matrix& b) const{
		if (!is_same_size(b))
		{
			return false;
		}
		for (int i = 0; i < row*cols; i++)
		{
			if (elements[i] != b.elements[i])
				return false;
		}
		return true;
	};

	bool operator!=(const Matrix& b) const {
		return !((*this) == b);
	}

	bool is_same_size(const Matrix& b)const
	{
		return (rows == b.rows) && (cols == b.cols);
	};

	Matrix& operator+=(const Matrix& b)
	{
		if (!is_same_size(b))
		{
			throw std::invalid_argument("Matrix diff size");
		}
		for (int i = 0; i < row*cols; i++)
		{
			elements[i] += b.elements[i];
		}
		return (*this);
	};

	Matrix operator+(const Matrix& b) {
		Matrix a(*this);
		a += b;
		return a;
	}

	Matrix& operator-=(const Matrix& b){
		if (!is_same_size(b))
		{
			throw std::invalid_argument("Matrix::operator-():Matrix diff size");
		}
		for (int i = 0; i < row*cols; i++)
		{
			elements[i] -= b.elements[i];
		}
		return (*this);
	};

	Matrix operator-(const Matrix& b) {
		Matrix a(*this);
		a -= b;
		return a;
	}

	Matrix& operator*=(const Matrix& b)
	{
		if (!is_same_size(b) || (rows != cols))
		{
			throw std::invalid_argument("Matrix::operator*=():Matrix diff size");
		}
		(*this) = (*this)*b;
		return *this;
	};

	Matrix operator*(const Matrix& b)
	{
		if (cols != b.rows){
			throw std::invalid_argument("Matrix::operator*():Matrix row!=cols");
		}
		Matrix res(row, b.cols);
		for (int row_n = 0; row_n < rows; row_n++)
		{
			for (int cols_n = 0; cols_n < b.cols; cols_n++)
			{
				T summ = 0;
				for (int i = 0; i < cols; i++)
				{
					summ += (*this)[row_n][i] * b[i][cols_n];
				}
				res[row_n][cols_n] = summ;
			}
		}
		return res;
	};

	std::vector<T> operator*(const std::vector<T> &v)
	{
		if (cols != v.size()){
			throw std::invalid_argument("Matrix::operator*(vector):Matrix row!=cols");
		}
		std::vector<T> res(row);
		for (int row_n = 0; row_n < rows; row_n++)
		{
			T summ = 0;
			for (int i = 0; i < cols; i++)
			{
				summ += (*this)[row_n][i] * b[i];
			}
			res[row_n] = summ;
		}
		return res;
	};

	Matrix& operator*=(double a);
	Matrix operator*(double b) {
		Matrix a(*this);
		a *= b;
		return a;
	}

};