#include "passport.h"

size_t passport::id = 0;

passport::passport() {
	if (!id) {
		ifstream file("id.txt");
		file >> id;
		file.close();
	}

	client_id = ++id;
}

passport::~passport() {
	ofstream file("id.txt");
	file << id;
	file.close();
}