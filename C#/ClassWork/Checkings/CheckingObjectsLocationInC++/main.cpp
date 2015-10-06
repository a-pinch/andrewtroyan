#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include "Pupil.h"

using namespace std;
using namespace std::chrono;

int main()
{
	system_clock::time_point before = system_clock::now();
	
	list<Pupil> listOfPupil;
	int amount = 1000000;
	
	for (int i = 0; i < amount; ++i)
	{
		listOfPupil.push_back(Pupil());
	}

	for (int i = 0; i < amount / 10; ++i)
	{
		listOfPupil.pop_back();
	}

	for (int i = 0; i < amount / 10; ++i)
	{
		listOfPupil.push_front(Pupil());
	}

	system_clock::time_point after = system_clock::now();

	long result = duration_cast<milliseconds>(after - before).count();

	ofstream file("result.txt");
	file << result;
	file.close();

	cout << result;
	cin.get();
}