#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

inline bool CheckForPrimarity(int number)
{
	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

void GeneratePrimes(unsigned int amount, string path)
{
	if (amount > 0)
	{
		ofstream file(path);

		unsigned int count = 0;
		int currentNumber = 2;

		file << currentNumber++ << '\n';
		++count;

		while (count < amount)
		{
			if (CheckForPrimarity(currentNumber))
			{
				file << currentNumber << '\n';
				++count;
			}

			currentNumber += 2;
		}

		//file.close();
	}
}

int main()
{
	system_clock::time_point before = system_clock::now();
	GeneratePrimes(500000, "test.txt");
	system_clock::time_point after = system_clock::now();

	ofstream file("result.txt");
	file << duration_cast<milliseconds>(after - before).count();
	file.close();
}