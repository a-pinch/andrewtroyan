// NameSearching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	std::wifstream infile("namesLE.txt");
	infile.imbue(std::locale(infile.getloc(),
		new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
	std::wstring line;
	while (std::getline(infile, line))
	{
		count++;
	}
	std::cout << count << " lines" << std::endl;
	return 0;
}

