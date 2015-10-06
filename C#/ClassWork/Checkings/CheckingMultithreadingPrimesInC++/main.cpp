#include "WorkWithPrimes.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	WorkWithPrimes primesGenerator(500000, "test.txt");

	system_clock::time_point before = system_clock::now();
	primesGenerator.Start();
	system_clock::time_point after = system_clock::now();

	long result = duration_cast<milliseconds>(after - before).count();

	ofstream file("result.txt");
	file << result;
	file.close();

	cout << result;
	cin.get();
}