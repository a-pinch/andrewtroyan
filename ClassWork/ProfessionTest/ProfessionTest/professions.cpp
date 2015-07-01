#include "profession.h"
#include "details.h"
#include <fstream>
#include <exception>
#include <string>
#include <sstream>

using std::ifstream;
using std::exception;
using std::string;
using std::getline;
using std::stringstream;

vector<profession> profession::professions;

void profession::add_professions() {
}