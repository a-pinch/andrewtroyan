// Questions.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Questions.h"
#include <vector>

#define MAX_LOADSTRING 100

using std::vector;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HWND hWnd;
RECT WinParams;
HWND questionWindow, button1, button2, button3, button4, conclusionWindow;
vector<HWND> answers, correctAnswers;
int currentQuestion = 1;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_QUESTIONS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_QUESTIONS));


	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 500, 255, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	GetWindowRect(hWnd, &WinParams);
	questionWindow = CreateWindowEx(0, TEXT("STATIC"), TEXT("Сколько будет 2 + 2?"), WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
		0, 0, WinParams.right - WinParams.left, 100, hWnd, 0, hInst, 0);

	button1 = CreateWindow(TEXT("BUTTON"), TEXT("2"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 100, (WinParams.right - WinParams.left) / 4, 100, hWnd, NULL, hInst, NULL);     
	button2 = CreateWindow(TEXT("BUTTON"), TEXT("3"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, (WinParams.right - WinParams.left) / 4, 100, (WinParams.right - WinParams.left) / 4, 100, hWnd, NULL, hInst, NULL);
	button3 = CreateWindow(TEXT("BUTTON"), TEXT("4"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, (WinParams.right - WinParams.left) / 2, 100, (WinParams.right - WinParams.left) / 4, 100, hWnd, NULL, hInst, NULL);
	button4 = CreateWindow(TEXT("BUTTON"), TEXT("Не знаю :("), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, (WinParams.right - WinParams.left) / 4 * 3, 100, (WinParams.right - WinParams.left) / 4, 100, hWnd, NULL, hInst, NULL);

	correctAnswers.push_back(button3);
	correctAnswers.push_back(button1);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_QUESTIONS));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_QUESTIONS);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		//switch (wmId)
		//{
		//case IDM_ABOUT:
		//	DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		//	break;
		//case IDM_EXIT:
		//	DestroyWindow(hWnd);
		//	break;
		//default:
		//	return DefWindowProc(hWnd, message, wParam, lParam);
		//}

		switch (wmEvent)
		{
		case BN_CLICKED:
			if ((HWND)lParam == button1 || (HWND)lParam == button2 || (HWND)lParam == button3 || (HWND)lParam == button4) {
				answers.push_back((HWND)lParam);
				++currentQuestion;
			}

			if (currentQuestion <= correctAnswers.size()) {
				SetWindowText(questionWindow, TEXT("Сколько будет 3 * 3?"));
				SetWindowText(button1, TEXT("9"));
				SetWindowText(button2, TEXT("53"));
				SetWindowText(button3, TEXT("1"));
				SetWindowText(button4, TEXT("Не знаю :("));
			}
			else {
				DestroyWindow(questionWindow); 
				DestroyWindow(button1);
				DestroyWindow(button2);
				DestroyWindow(button3);
				DestroyWindow(button4);


				if (answers == correctAnswers) {
					conclusionWindow = CreateWindowEx(0, TEXT("STATIC"), TEXT("Всё верно, молодец!"), WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
						0, 0, WinParams.right - WinParams.left, 200, hWnd, 0, hInst, 0);
				}
				else {
					if (answers[0] != correctAnswers[0] && answers[1] != correctAnswers[1]) {
						conclusionWindow = CreateWindowEx(0, TEXT("STATIC"), TEXT("Ни один ответ не правильный :("), WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
							0, 0, WinParams.right - WinParams.left, 200, hWnd, 0, hInst, 0);
					}
					else if (answers[0] != correctAnswers[0]) {
						conclusionWindow = CreateWindowEx(0, TEXT("STATIC"), TEXT("Первый ответ не правильный :("), WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
							0, 0, WinParams.right - WinParams.left, 200, hWnd, 0, hInst, 0);
					}
					else if (answers[1] != correctAnswers[1]) {
						conclusionWindow = CreateWindowEx(0, TEXT("STATIC"), TEXT("Второй ответ не правильный :("), WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
							0, 0, WinParams.right - WinParams.left, 200, hWnd, 0, hInst, 0);
					}
				}
			}
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
