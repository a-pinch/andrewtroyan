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

	void operator=(const String& source); //перегрузка оператора присваивания

	void print() const;
	const char* c_str() const { //inline method (inside class)
		return (const char *)s;
	}
	const char* find(const char *substr) const;
	const char* add(const char *str);
	String plus(const String& obj) const;
	void regUp();
	String first(const int amount) const;
	String last(const int amount) const;
	String takeSubStr(const int pos, const int amount) const;
	int deleteSpaces();

	~String();
};

void print(String str);

inline int sqr(int x) { //inline function
	return x * x;
}

