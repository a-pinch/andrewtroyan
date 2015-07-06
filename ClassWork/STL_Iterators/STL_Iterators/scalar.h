#include "value.h"

class scalar : public value {
private:
	int scalar_value;
public:
	operator int() {
		return scalar_value;
	}
};