#pragma once

class Array {
private:
	int* array;
public:
	Array() : array(nullptr) {};
	Array(int num);
	~Array();
};

