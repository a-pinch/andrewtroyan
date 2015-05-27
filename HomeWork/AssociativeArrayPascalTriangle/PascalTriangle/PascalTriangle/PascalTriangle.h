#pragma once

class HelpingClass {
private:
	int number;
public:
	HelpingClass() {};
	~HelpingClass() {};
	HelpingClass(int n);

	int operator[](int num);
	HelpingClass& operator=(int num);
};

class PascalTriangle {
private:
	HelpingClass help;
public:
	PascalTriangle() {};
	~PascalTriangle() {};

	HelpingClass& operator[](int num);
};

int factorial(int num);

