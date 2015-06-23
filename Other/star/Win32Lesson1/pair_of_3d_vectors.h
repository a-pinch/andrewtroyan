#pragma once

#include <Windows.h>
#include <initializer_list>
#include <vector>
#include "../../../ClassWork/VectorOperations/VectorOperations/matrix.h"

using std::vector;
using std::initializer_list;

class pair_3d {
public:
	static HDC hdc;
private:
	vector<double> v1, v2;

public:
	pair_3d(initializer_list<double> list1, initializer_list<double> list2) {
		auto it1 = list1.begin(), it2 = list2.begin();
		for (int i = 0; i < 3; ++i, ++it1, ++it2) {
			v1.push_back(*it1);
			v2.push_back(*it2);
		}
	}

	pair_3d& operator*=(const matrix<double>& mat) {
		v1 *= mat;
		v2 *= mat;
		return *this;
	}

	void draw() {
		matrix<double> mat(2, 3, { 1, 0, 0.7, 0, 1, 0.7 });
		vector<double> temp_v1 = v1 * mat, temp_v2 = v2 * mat;
		MoveToEx(hdc, temp_v1[0], temp_v1[1], NULL);
		LineTo(hdc, temp_v2[0], temp_v2[1]);
	}
};