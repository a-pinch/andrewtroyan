#pragma once

#include <fstream>
#include <queue>
#include <mutex>

using namespace std;

class WorkWithPrimes
{
private:
	int amountOfPrimesToFind;
	int writtenPrimes;
	queue<int> primes;
	mutex mutexForQueue;
	ofstream file;

	void GeneratePrimes();
	void WriteToFile();

	static bool CheckForPrimarity(int);
public:
	WorkWithPrimes(int, string);

	void Start();

	// friend

	friend void wrapping(WorkWithPrimes*);
};

void wrapping(WorkWithPrimes*);