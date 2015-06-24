#pragma once

#include <fstream>

using std::ifstream;
using std::ofstream;

class passport {
private:
	static size_t id;
	
	size_t client_id;
public:
	passport();
	~passport();

	size_t get_id() { return client_id; };
};

