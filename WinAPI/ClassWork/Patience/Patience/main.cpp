#include <Windows.h>
#include <string>
#include <cstdio>

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

wchar_t szClassName[] = L"Patience";
HWND hMainWnd, hButton, hStatic;
HBITMAP hBitMap;
HINSTANCE hInst;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow) {
	MSG msg;
	WNDCLASSEX wc;

	hInst = hInstance;

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CREATE:
		DefWindowProc(hWnd, uMsg, wParam, lParam);

		hBitMap = (HBITMAP)LoadImage(NULL, L"test_image16M.bmp", IMAGE_BITMAP, 50, 100, LR_LOADFROMFILE);

		if (!hBitMap) {
			MessageBox(NULL, L"Cannot create window.", L"Error", MB_OK | MB_ICONERROR);
			return 1;
		}

		hButton = CreateWindow(L"BUTTON", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_DEFPUSHBUTTON | BS_BITMAP, 0, 0, 50, 100, hWnd, NULL, hInst, NULL);
		SendMessage(hButton, (UINT)BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitMap);

		hStatic = CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_BITMAP | SS_NOTIFY, 100, 0, 50, 100, hWnd, NULL, hInst, NULL);
		SendMessage(hStatic, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitMap);

		break;

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