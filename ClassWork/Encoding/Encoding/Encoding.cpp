// Encoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//wchar_t buf[50];
	//wchar_t *hello = L"Привет"; //L - for 16-bit symbols
	//
	//wcscpy(buf, hello); //wcs - for 16-bit symbols (wcs is for "wide character string")
	//wcscat(buf, L", коллеги!");

	//std::wcout.imbue(std::locale(".866")); //imbue makes recoding of message

	//std::wregex r(L"[уеыаояиюёэ]");
	//std::wstring s(buf);
	//std::wsmatch m;

	//int count = 0;
	//while (std::regex_search(s, m, r)) {
	//	count++;
	//	s = m.suffix().str();
	//}
	//std::wcout << count << L" слогов.\n" << std::endl;

	//std::wcout << L"Привет!" << std::endl;
	//std::wcout << buf;

	wifstream input_file("names.txt", std::ios::binary);
	input_file.imbue(std::locale(input_file.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
	wstring buffer;
	vector<name> storage_of_strings;
	while (!input_file.eof()) {
		getline(input_file, buffer);
		storage_of_strings.push_back(name(buffer));
	}
	input_file.close();

	sort(storage_of_strings.begin(), storage_of_strings.end(), [](name a, name b){ return a.first_name < b.first_name; });

	wofstream output_file("names.txt");
	for (auto it : storage_of_strings)
		output_file << it.surname << ' ' << it.first_name << ' ' << it.second_name << endl;
	output_file.close();

	cin.get();

	return 0;
}

