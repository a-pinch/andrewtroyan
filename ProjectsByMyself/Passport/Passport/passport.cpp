#include "passport.h"

size_t passport::global_id = 0;

passport::passport() {
	if (!global_id) {
		ifstream file("id.txt");
		file >> global_id;
		file.close();
	}

	client_id = ++global_id;
}