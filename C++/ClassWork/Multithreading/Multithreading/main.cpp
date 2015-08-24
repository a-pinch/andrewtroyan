#include <windows.h>
#include <iostream>

using namespace std;

int cnt;
CRITICAL_SECTION CriticalSection;

DWORD WINAPI ThreadProc(LPVOID);

int main() {
	HANDLE thread1, thread2;
	cnt = 0;

	InitializeCriticalSection(&CriticalSection);
	thread1 = CreateThread(NULL, 0, ThreadProc, (LPVOID)0, 0, NULL);
	thread2 = CreateThread(NULL, 0, ThreadProc, (LPVOID)1, 0, NULL);

	WaitForSingleObject(thread1, INFINITE);
	WaitForSingleObject(thread2, INFINITE);
	DeleteCriticalSection(&CriticalSection);

	cout << cnt << endl;

	cin.get();

	return 0;
}

DWORD WINAPI ThreadProc(LPVOID lp) {
	int index = (int)lp;

	for (int i = 0; i < 10000; ++i) {
		EnterCriticalSection(&CriticalSection);
		cnt += index ? -1 : 1;
		LeaveCriticalSection(&CriticalSection);
	}

	return 0;
}