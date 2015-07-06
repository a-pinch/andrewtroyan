#include "value.h"
#include <vector>

using std::vector;

class my_list : public value {
private:
	vector<value*> values;
public:
	value& operator[](unsigned int index) {
		return *(values[index]);
	}
};