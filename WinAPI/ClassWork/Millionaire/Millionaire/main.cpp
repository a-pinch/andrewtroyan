#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <tchar.h>
#include <iostream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <cstdlib>

using std::wifstream;
using std::wstring;
using std::vector;
using std::stoi;

struct question {
	wstring text;
	vector<wstring> answers;
	int correctAnswer;
};

TCHAR className[] = TEXT("Millionaire");

//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow) 
{
	setlocale(LC_ALL, "rus");

	wifstream fileToRead("questions.txt", std::ifstream::in);
	if (!fileToRead.is_open()) {
		MessageBox(NULL, TEXT("Не удалось открыть файл."), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
		return 1;
	}

	fileToRead.imbue(std::locale(fileToRead.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));

	vector<question> questions;

	question questionBuffer;
	wstring stringBuffer;
	int amountOfQuestions;

	//while (!fileToRead.eof()) {
	//	getline(fileToRead, stringBuffer);

	//	amountOfQuestions = wcstol(stringBuffer.c_str(), NULL, 10);
	//	questionBuffer.correctAnswer = wcstol(stringBuffer.substr(2, 1).c_str(), NULL, 10);

	//	getline(fileToRead, questionBuffer.text);

	//	for (int i = 0; i < amountOfQuestions; ++i) {
	//		getline(fileToRead, stringBuffer);
	//		questionBuffer.answers.push_back(stringBuffer);
	//	}

	//	questions.push_back(std::move(questionBuffer));
	//}

	while (getline(fileToRead, stringBuffer)) {
	}

	fileToRead.close();

	//HWND hMainWnd;
	//MSG msg;
	//WNDCLASSEX wc;

	//wc.cbSize = sizeof(wc);
	//wc.cbClsExtra = 0;
	//wc.cbWndExtra = 0;
	//wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	//wc.hInstance = hInst;
	//wc.lpfnWndProc = WndProc;
	//wc.lpszClassName = className;
	//wc.lpszMenuName = NULL;
	//wc.style = CS_HREDRAW | CS_VREDRAW;

	//if (!RegisterClassEx(&wc)) {
	//	MessageBox(NULL, TEXT("Не удалось зарегистрировать класс."), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
	//	return 1;
	//}

	return 0;
}

//LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//
//}