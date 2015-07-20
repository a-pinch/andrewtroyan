// определение символической константы _UNICODE
#define _UNICODE
#include <iostream>
#include <tchar.h>
using namespace std;

void main()
{
	_TCHAR szBuf3[15] = _TEXT("Hello,");
	_tcscat(szBuf3, _TEXT(" world!"));
	wcout << szBuf3 << '\n';
	cout << "The size of array: " << sizeof(szBuf3) << " bytes\n"; // 30 байт
}

