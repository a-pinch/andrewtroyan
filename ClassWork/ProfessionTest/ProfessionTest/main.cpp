#include "trait.h"
#include "answer.h"
#include "profession.h"
#include "question.h"
#include "ratee.h"
#include "test.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	//test::add_question();
	//test::add_answers();
	//trait::add_traits();
	profession::add_professions();

	auto it = profession::professions.begin();

	cin.get();
	return 0;
}