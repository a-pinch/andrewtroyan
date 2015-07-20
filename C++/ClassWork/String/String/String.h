#pragma once

class String {
private:
	char *s;
	int length;
public:
	String();
	String(const char *p);
	String(char c, size_t n);

	String(const String& orig); //copy constructor

	void print();
	const char* c_str();
	const char* find(const char *substr);
	const char* add(const char *str);

	~String();
};

void print(String str);

