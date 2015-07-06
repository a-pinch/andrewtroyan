#include <string>
#include <sstream>
#include <iterator>

using std::string;
using std::stringstream;

template <class container>
string toJSON(container what) {
	stringstream ss;

	ss << "[";
	for (auto it = what.begin(); it != what.end(); ++it) {
		if (it != what.begin())
			ss << ", ";
		ss << *it;
	}
	ss << "]";

	return ss.str();
}