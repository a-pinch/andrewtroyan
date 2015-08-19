#include <Windows.h>
#include <vector>
#include <fstream>
#include <locale>
#include <codecvt>
#include "question_info.h"

#define WM_NEXTPAGE 0x1000

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

vector<question> questions;
wchar_t szClassName[] = L"ClassForMillionaireGame";
HWND hMainWnd, hBalanceArea, hQuestionArea;
vector<HWND> hButtonAnswers;
vector<question>::iterator currentQuestion;
HINSTANCE hInst;
unsigned int currentBalance;
RECT mainWndRect;
int mainWndWidth, mainWndHeight;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, "rus");

	// ---

	wifstream fileWithQuestions("questions.txt", wifstream::in);
	
	if (!fileWithQuestions.is_open()) {
		MessageBox(NULL, L"Cannot open file.", L"Error", MB_OK | MB_ICONERROR);
		return -1;
	}

	fileWithQuestions.imbue(std::locale(fileWithQuestions.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));

	loadQuestions(fileWithQuestions, questions);

	fileWithQuestions.close();

	// ---

	hInst = hInstance;

	MSG msg;
	WNDCLASSEX wc;

	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = szClassName;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"Cannot create class.", L"Error", MB_OK | MB_ICONERROR);
		return 1;
	}

	hMainWnd = CreateWindow(szClassName, L"Millionaire", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hMainWnd) {
		MessageBox(NULL, L"Cannot create window.", L"Error", MB_OK | MB_ICONERROR);
		return 1;
	}

	ShowWindow(hMainWnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int indexForNewButtons = 0;
	static int buttonOffset, buttonHeight;
	static HWND hButtonBuffer;
	static wchar_t stringBuffer[256];
	static wstring balanceMessage(L"Your balance: ");

	switch (uMsg) {
	case WM_CREATE:
		DefWindowProc(hWnd, uMsg, wParam, lParam);

		currentQuestion = questions.begin();
		currentBalance = 0;

		GetClientRect(hWnd, &mainWndRect);
		mainWndHeight = mainWndRect.bottom - mainWndRect.top;
		mainWndWidth = mainWndRect.right - mainWndRect.left;

		hQuestionArea = CreateWindow(L"STATIC", currentQuestion->textOfQuestion.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE, 
			0, 0, mainWndWidth, mainWndHeight / 6, hWnd, NULL, hInst, NULL);

		buttonOffset = 0;
		buttonHeight = mainWndHeight * 2 / 3 / currentQuestion->answers.size();

		for (auto it : currentQuestion->answers) {
			hButtonBuffer = CreateWindow(L"BUTTON", it.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER | BS_DEFPUSHBUTTON, 0, mainWndHeight / 6 + buttonOffset, mainWndWidth,
				buttonHeight, hWnd, (HMENU)indexForNewButtons++, hInst, NULL);
			hButtonAnswers.push_back(hButtonBuffer);
			buttonOffset += buttonHeight;
		}

		hBalanceArea = CreateWindow(L"STATIC", (balanceMessage + to_wstring(currentBalance)).c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
			0, mainWndHeight * 5 / 6, mainWndWidth, mainWndHeight / 6, hWnd, NULL, hInst, NULL);

		break;

	case WM_SIZE:
		GetClientRect(hWnd, &mainWndRect);
		mainWndHeight = mainWndRect.bottom - mainWndRect.top;
		mainWndWidth = mainWndRect.right - mainWndRect.left;

		MoveWindow(hQuestionArea, 0, 0, mainWndWidth, mainWndHeight / 6, FALSE);

		buttonOffset = 0;
		buttonHeight = mainWndHeight * 2 / 3 / currentQuestion->answers.size();

		for (auto it : hButtonAnswers) {
			MoveWindow(it, 0, mainWndHeight / 6 + buttonOffset, mainWndWidth, buttonHeight, FALSE);
			buttonOffset += buttonHeight;
		}

		MoveWindow(hBalanceArea, 0, mainWndHeight * 5 / 6, mainWndWidth, mainWndHeight / 6, FALSE);
		break;

	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED) {
			if ((int)wParam != currentQuestion->indexOfCorrectAnswer) {
				MessageBox(NULL, L"You lose.", L"Game over", MB_OK);
				DestroyWindow(hMainWnd);
			}
			else {
				// ---
				currentBalance += currentQuestion->points;
				SetWindowText(hBalanceArea, (balanceMessage + to_wstring(currentBalance)).c_str());
				SendMessage(hMainWnd, WM_NEXTPAGE, 0, 0);
				// ---
			}
		}
		break;

	//case WM_NEXTPAGE:
	//	if (currentQuestion + 1 == questions.end()) {
	//		MessageBox(NULL, ((wstring)L"You won " + to_wstring(currentBalance)).c_str(), L"Congratulations!", MB_OK);
	//	}
	//	else {
	//		++currentQuestion;
	//		SetWindowText(hQuestionArea, currentQuestion->textOfQuestion.c_str());

	//		if (hButtonAnswers.size() == currentQuestion->answers.size()) {

	//		}
	//		else {
	//			for (auto it : hButtonAnswers) {
	//				DestroyWindow(it);
	//			}

	//			buttonOffset = 0;
	//			buttonHeight = mainWndHeight * 2 / 3 / currentQuestion->answers.size();

	//			for (auto it : currentQuestion->answers) {
	//				hButtonBuffer = CreateWindow(L"BUTTON", it.c_str(), WS_CHILD | WS_VISIBLE | WS_BORDER | BS_DEFPUSHBUTTON, 0, mainWndHeight / 6 + buttonOffset, mainWndWidth,
	//					buttonHeight, hWnd, (HMENU)indexForNewButtons++, hInst, NULL);
	//				hButtonAnswers.push_back(hButtonBuffer);
	//				buttonOffset += buttonHeight;
	//			}
	//		}
	//	}
	//	break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}