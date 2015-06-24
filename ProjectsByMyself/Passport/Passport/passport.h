#pragma once

#include <fstream>

using std::ifstream;
using std::ofstream;

class passport {
private:
	static size_t id;
	
	size_t client_id;
public:
	passport() {
		if (!id) {
			ifstream file("id.txt");
			file >> id;
			file.close();
		}

		client_id = ++id;
	}

	~passport() {
		ofstream file("id.txt");
		file << id;
		file.close();
	}

	size_t get_id() {
		return client_id;
	}
};

