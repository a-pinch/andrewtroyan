#include "Pupil.h"

#include <string>
#include <time.h>

using namespace std;

Pupil::Pupil()
{
	name = "";
	srand(time(NULL));

	int nameLength = rand() % 4 + 5;
	for (int i = 0; i < nameLength; ++i)
	{
		name += (char)rand() % 27 + 97;
	}

	age = rand() % 98 + 1;
}