#pragma once

#include <fstream>

using std::ifstream;
using std::ofstream;

class passport {
private:
	static size_t global_id;
	
	size_t client_id;
public:
	passport();

	size_t get_id() { return client_id; };

	static size_t get_global_id() {
		return global_id;
	}

	static void save_changes() {
		if (global_id) {
			ofstream file("id.txt");
			file << global_id;
			file.close();
		}
	}
};

