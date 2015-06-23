#pragma once

#include <Windows.h>
#include "../../../ClassWork/VectorOperations/VectorOperations/matrix.h"

class Line {
public:
	static HDC hdc;
	double x1, y1, x2, y2;

	Line(double x1_, double y1_, double x2_, double y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_) {};

	void draw() {
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y2);
	}
};