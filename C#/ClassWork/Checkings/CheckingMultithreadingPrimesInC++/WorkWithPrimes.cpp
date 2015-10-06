#include "WorkWithPrimes.h"

#include <thread>

using namespace std;

WorkWithPrimes::WorkWithPrimes(int amountOfPrimesToFind_, string filePath_) {
	if (amountOfPrimesToFind_ > 0)
	{
		amountOfPrimesToFind = amountOfPrimesToFind_;
		writtenPrimes = 0;
		file.open(filePath_);
	}
	else
	{
		throw exception("In WorkWithPrimes::WorkWithPrimes(int): argument must be positive.");
	}
}

void WorkWithPrimes::Start()
{
	thread threadForFileWriting(wrapping, this);
	GeneratePrimes();
	threadForFileWriting.join();
	file.close();
}

void WorkWithPrimes::GeneratePrimes()
{
	int count = 0;
	int currentNumber = 2;

	primes.push(currentNumber++);
	++count;

	while (count < amountOfPrimesToFind)
	{
		if (CheckForPrimarity(currentNumber))
		{
			mutexForQueue.lock();
			primes.push(currentNumber);
			mutexForQueue.unlock();
			++count;
		}

		currentNumber += 2;
	}
}

void WorkWithPrimes::WriteToFile()
{
	while (writtenPrimes != amountOfPrimesToFind)
	{
		while (primes.size() != 0)
		{
			mutexForQueue.lock();
			file << primes.front() << '\n';
			primes.pop();
			mutexForQueue.unlock();
			++writtenPrimes;
		}
	}
}

bool WorkWithPrimes::CheckForPrimarity(int number)
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

void wrapping(WorkWithPrimes* generator)
{
	generator->WriteToFile();
}