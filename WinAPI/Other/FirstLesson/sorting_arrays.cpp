#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	wcout.imbue(locale("rus_rus.866"));
	vector<wchar_t*> names{ L"привет", L"мой", L"дорогой", L"друг" };
	
	sort(names.begin(), names.end(),
		[](const wchar_t* a, const wchar_t* b) {
		return wcscmp(a, b)<0;
	});

	for (auto name : names) {
		wcout << name << endl;
	}

	getc(stdin);
}