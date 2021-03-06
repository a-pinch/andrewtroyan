#include <windows.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <list>

using namespace std;

list<int> threadStorages[2];
static ofstream fileOneCore, fileTwoCores;

//amount of threads
const int N = 2;

DWORD WINAPI countPrimesForOneCore(LPVOID lp) {
	for (int candidate = 3; candidate < 10; candidate += 2) {
		bool flag = true;
		for (int divider = 3; divider * divider <= candidate; divider += 2) {
			if (candidate % divider == 0) {
				flag = false;
			}
		}
		if (flag) {
			fileOneCore << candidate << endl;
		}
	}
	return 0;
}

DWORD WINAPI countPrimesForTwoCores(LPVOID lp) {
	int threadIndex = (int)lp;

	for (int candidate = 2 * threadIndex + 3; candidate < 10; candidate += N * 2) {
		bool flag = true;
		for (int divider = 3; divider * divider <= candidate; divider += 2) {
			if (candidate % divider == 0) {
				flag = false;
			}
		}
		if (flag) {
			threadStorages[threadIndex].push_back(candidate);
		}
	}
	return 0;
}

int main() {
	chrono::system_clock::time_point before, after;
	HANDLE threads[N];
	fileOneCore.open("fileOneCore.csv"), fileTwoCores.open("fileTwoCores.csv");

	// ---

	before = chrono::system_clock::now();

	countPrimesForOneCore(NULL);
	
	after = chrono::system_clock::now();

	cout << "Result for one core: " << chrono::duration_cast<chrono::milliseconds>(after - before).count() << " milliseconds." << endl;

	// ---

	before = chrono::system_clock::now();

	for (int i = 0; i < N; ++i) {
		threads[i] = CreateThread(NULL, 0, countPrimesForTwoCores, (LPVOID)i, 0, NULL);
	}

	//Sleep(10);

	//int index1 = 0, index2 = 0;
	//int result1, result2;

	//while (index1 < threadStorages[0].size() && index2 < threadStorages[1].size()) {
	//	result1 = threadStorages[0].front();
	//	result2 = threadStorages[1].front();
	//	
	//	if (result1 < result2) {
	//		fileTwoCores << result1 << endl;
	//		threadStorages[0].pop_front();
	//		index1 = 0;
	//	}
	//	else {
	//		fileTwoCores << result2 << endl;
	//		threadStorages[1].pop_front();
	//		index2 = 0;
	//	}
	//}

	//while (index1 < threadStorages[0].size()) {
	//	fileTwoCores << threadStorages[0].front() << endl;
	//	threadStorages[0].pop_front();
	//	index1 = 0;
	//}

	//while (index2 < threadStorages[1].size()) {
	//	fileTwoCores << threadStorages[1].front() << endl;
	//	threadStorages[1].pop_front();
	//	index2 = 0;
	//}

	WaitForMultipleObjects(N, threads, TRUE, INFINITE);

	auto it1 = threadStorages[0].begin();
	auto it2 = threadStorages[1].begin();

	while (it1 != threadStorages[0].end() && it2 != threadStorages[1].end()) {
		if (*it1 < *it2) {
			fileTwoCores << *it1 << endl;
			++it1;
		}
		else {
			fileTwoCores << *it2 << endl;
			++it2;
		}
	}
	while (it1 != threadStorages[0].end()) {
		fileTwoCores << *it1 << endl;
		++it1;
	}
	while (it2 != threadStorages[1].end()) {
		fileTwoCores << *it2 << endl;
		++it2;
	}

	after = chrono::system_clock::now();

	cout << "Result for two cores: " << chrono::duration_cast<chrono::milliseconds>(after - before).count() << " milliseconds." << endl;

	// ---

	fileOneCore.close();
	fileTwoCores.close();

	cin.get();

	return 0;
}