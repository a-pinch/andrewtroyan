#include <windows.h>
#include <tchar.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::for_each;

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT(" аркасное приложение");

LRESULT CALLBACK xxx(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK yyy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

vector<HWND> randowWindows;

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	srand(time(NULL));

	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = xxx;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("ѕеречисление окон верхнего уровн€"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	SetTimer(hWnd, 1, 2000, NULL);
	//MessageBox(hWnd, TEXT("ƒл€ перечислени€ окон верхнего уровн€ нажмите <CTRL>"), TEXT("ѕеречисление окон верхнего уровн€"), MB_OK | MB_ICONINFORMATION);

	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	HWND hWindow = (HWND)lParam; // дескриптор окна нашего приложени€
	//TCHAR caption[MAX_PATH] = { 0 }, classname[100] = { 0 }, text[500] = { 0 };
	//GetWindowText(hWnd, caption, 100); // получаем текст заголовка текущего окна верхнего уровн€
	//GetClassName(hWnd, classname, 100); // получаем им€ класса текущего окна верхнего уровн€
	//if (lstrlen(caption))
	//{
	//	lstrcat(text, TEXT("«аголовок окна: "));
	//	lstrcat(text, caption);
	//	lstrcat(text, TEXT("\n"));
	//	lstrcat(text, TEXT(" ласс окна: "));
	//	lstrcat(text, classname);
	//	MessageBox(hWindow, text, TEXT("ѕеречисление окон верхнего уровн€"), MB_OK | MB_ICONINFORMATION);
	//}
	//SetWindowText(hWnd, TEXT("Oops :P"));

	//if (hWnd != hWindow && randowWindows.size() <= 10) {
	//	if (rand() % 2) {
	//		randowWindows.push_back(hWnd);
	//	}
	//}

	if (rand() % 2)
		ShowWindow(hWnd, SW_SHOW);
	else
		ShowWindow(hWnd, SW_HIDE);

	return TRUE; // продолжаем перечисление окон верхнего уровн€
}

LRESULT CALLBACK xxx(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		for_each(randowWindows.begin(), randowWindows.end(), [](HWND hWnd){ DestroyWindow(hWnd); });
		PostQuitMessage(0);
		break;
	//case WM_KEYDOWN:

	//	if (wParam == VK_CONTROL)
	//		EnumWindows(EnumWindowsProc, (LPARAM)hWnd);
	//	break;
	case WM_TIMER:
		for_each(randowWindows.begin(), randowWindows.end(), [](HWND hWnd){ DestroyWindow(hWnd); });
		EnumWindows(EnumWindowsProc, (LPARAM)hWnd);
		for_each(randowWindows.begin(), randowWindows.end(), [](HWND hWnd){ 
			ShowWindow(hWnd, SW_SHOWDEFAULT);
			UpdateWindow(hWnd);
		});
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK yyy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_CONTROL)
			EnumWindows(EnumWindowsProc, (LPARAM)hWnd);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

