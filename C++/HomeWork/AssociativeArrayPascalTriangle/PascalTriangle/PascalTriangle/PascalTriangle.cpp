#include "PascalTriangle.h"

HelpingClass::HelpingClass(int n) {
	number = n;
}

int HelpingClass::operator[](int num) {
	int a = factorial(number), b = factorial(num), c = factorial(number - num);
	return a / b * c;
}

HelpingClass& HelpingClass::operator=(int num) {
	number = num;
	return *this;
}

HelpingClass& PascalTriangle::operator[](int num) {
	help = num;
	return help;
}

int factorial(int num) {
	int ret = 1;
	for (int i = 1; i <= num; ++i)
		ret *= i;
	return ret;
}