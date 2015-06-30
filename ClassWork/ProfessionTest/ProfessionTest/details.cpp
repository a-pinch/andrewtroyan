#include "details.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> parse_csv_line(const string& line) {
	vector<string> return_vector;
	
	size_t left_border = 0, right_border = 0; 

	while (right_border < line.size()) {
		right_border = line.find(';', left_border);
		string temp = line.substr(left_border, right_border - left_border);
		return_vector.push_back(temp);
		left_border = right_border + 1;
	}

	return return_vector;
}