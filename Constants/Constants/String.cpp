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

void String::operator=(const String& source) { //оператор присваивания
	free(s);
	length = source.length;
	s = (char *)malloc((length + 1) * sizeof(char));
	strcpy(s, source.s);
}

void String::print() const {
	std::cout << s << std::endl;
}

//const char* String::c_str() const {
//	return (const char *)s;
//}

const char* String::find(const char *substr) const {
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

String String::plus(const String& obj) const {
	String result(s);
	result.add(obj.s);
	return result;
}

void String::regUp() {
	for (int i = 0; i <= length; ++i) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - ('A'-'a');
	}
}

String String::first(const int amount) const {
	if (amount > 0 && amount <= length) {
		String result;
		free(result.s);
		result.length = amount;
		result.s = (char*)malloc((amount + 1) * sizeof(char));
		if (!result.s)
			return "Error.";
		for (int i = 0; i < amount; ++i)
			result.s[i] = s[i];
		result.s[amount] = '\0';
		return result;
	}
	return "Error.";
}

String String::last(const int amount) const {
	if (amount >= 0 && amount <= length) {
		String result;
		free(result.s);
		result.length = amount;
		result.s = (char*)malloc((amount + 1) * sizeof(char));
		if (!result.s)
			return "Error.";
		for (int i = 0, k = length - amount; i < amount; ++i, ++k) {
			result.s[i] = s[k];
		}
		result.s[amount] = '\0';
		return result;
	}
	return "Error.";
}

String String::takeSubStr(const int pos, const int amount) const {
	if (pos > 0 && pos + amount - 1 <= length)
	{
		String result;
		free(result.s);
		result.length = amount;
		result.s = (char*)malloc((amount + 1) * sizeof(char));
		if (!result.s)
			return "Error.";
		for (int i = 0, k = pos - 1; i < amount; ++i, ++k)
			result.s[i] = s[k];
		result.s[amount] = '\0';
		return result;
	}
	return "Error.";
}

int String::deleteSpaces() {
	int spaces = 0;
	for (int i = 0; s[i] == 32 && i < length; ++i)
		++spaces;
	if (spaces > 0) {
		length -= spaces;
		char* buf;
		buf = (char *)malloc((length + 1) * sizeof(char));
		if (!buf)
			return 1;
		strcpy(buf, s + spaces);
		free(s);
		s = buf;
		spaces = 0;
	}
	for (int i = length - 1; s[i] == 32 && i >= 0; --i)
		++spaces;
	if (spaces > 0) {
		length -= spaces;
		s = (char *)realloc(s, length + 1); 
		if (!s)
			return 1;
		s[length] = '\0';
	}
	return 0;
}

String::~String() {
	free(s);
}

void print(String str) {
	str.print();
}