#include "trait.h"
#include "answer.h"
#include "profession.h"
#include "question.h"
#include "ratee.h"
#include "test.h"
#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main() {
	question::init();
	trait::init();
	profession::init();

	test first_test("Andrew");

	while (!first_test.is_finished())
		first_test.ask();

	first_test.show_result();

	_getch();

	return 0;
}