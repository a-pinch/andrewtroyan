#include <windows.h>
#include <iostream>
#include <chrono>

using namespace std;

DWORD WINAPI countPrimesForOneCore(LPVOID lp) {
	int amountOfPrimes = 0;

	for (int candidate = 3; candidate < 1000000; candidate += 2) {
		bool flag = true;
		for (int divider = 3; divider * divider <= candidate; divider += 2) {
			if (candidate % divider == 0) {
				flag = false;
			}
		}
		if (flag) {
			++amountOfPrimes;
		}
	}
	return amountOfPrimes;
}

DWORD WINAPI countPrimesForTwoCores(LPVOID lp) {
	int amountOfPrimes = 0;
	int candidate = (int)lp;

	for (; candidate < 1000000; candidate += 4) {
		bool flag = true;
		for (int divider = 3; divider * divider <= candidate; divider += 2) {
			if (candidate % divider == 0) {
				flag = false;
			}
		}
		if (flag) {
			++amountOfPrimes;
		}
	}
	return amountOfPrimes;
}

int main() {
	chrono::system_clock::time_point before, after;
	HANDLE thread1, thread2;

	before = chrono::system_clock::now();
	int result1 = countPrimesForOneCore(NULL);
	after = chrono::system_clock::now();

	cout << "Result for one core: " << chrono::duration_cast<chrono::milliseconds>(after - before).count() << " milliseconds." << endl << result1 << endl;

	before = chrono::system_clock::now();
	thread1 = CreateThread(NULL, 0, countPrimesForTwoCores, (LPVOID)3, 0, NULL);
	thread2 = CreateThread(NULL, 0, countPrimesForTwoCores, (LPVOID)5, 0, NULL);
	WaitForSingleObject(thread1, INFINITE);
	WaitForSingleObject(thread2, INFINITE);
	after = chrono::system_clock::now();

	DWORD result_thread1, result_thread2;
	GetExitCodeThread(thread1, &result_thread1);
	GetExitCodeThread(thread2, &result_thread2);
	int result2 = result_thread1 + result_thread2;

	cout << "Result for two cores: " << chrono::duration_cast<chrono::milliseconds>(after - before).count() << " milliseconds." << endl << result2 << endl;

	cin.get();

	return 0;
}