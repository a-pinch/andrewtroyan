#pragma once

#include <string>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::string;

class setting_file {
private:
	setting_file() {
		ifstream file("user.txt");
		file >> name;
		file.close();
	};

	static setting_file instance;
public:
	string name;

	static setting_file& get_instance() {
		return instance;
	}

	~setting_file() {
		ofstream file("user.txt");
		file << name;
		file.close();
	}
};
