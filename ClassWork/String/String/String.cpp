#define _CRT_SECURE_NO_WARNINGS

#include "String.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

String::String() {
	s = (char *)malloc(sizeof(char));
	*s = '\0'; //or s[0] = '\0';
	length = 0;
}

String::String(const char *p) {
	length = strlen(p);
	s = (char *)malloc((length + 1) * sizeof(char));
	strcpy(s, p);
}

String::String(char c, size_t n) {
	s = (char *)malloc((n + 1) * sizeof(char));
	memset(s, c, n);
	s[n] = '\0';
	length = n;
}

String::String(const String& orig) {
	s = (char *)malloc((strlen(orig.s) + 1) * sizeof(char));
	strcpy(s, orig.s);
	length = orig.length;
}

void String::print() {
	std::cout << s << std::endl;
}

const char* String::c_str() {
	return (const char *)s;
}

const char* String::find(const char *substr) {
	return (const char *)strstr(s, substr);
}

const char* String::add(const char *str) {
	length += strlen(str);
	s = (char *)realloc((void *)s, (length + 1) * sizeof(char));
	if (!s)
		return nullptr;
	strcat(s, str);
	return (const char *)s;
}

String::~String() {
	free(s);
}

void print(String str) {
	str.print();
}