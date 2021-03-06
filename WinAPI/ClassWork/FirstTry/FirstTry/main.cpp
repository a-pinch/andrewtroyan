// ���� WINDOWS.H �������� �����������, �������, � ��������� 
// ������� ������������ ��� ��������� ���������� ��� Windows. 
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <map>

using namespace std;

typedef LRESULT CALLBACK EventProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

// �������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("��������� ����������");	/* ��� ������ ���� */

map<UINT, EventProc*> eventMap;

RECT winParams;
HINSTANCE hInstance;
HWND hWnd, hStatic;
TCHAR buf[20];

int VerticalMove = 0, HorizontalMove = 0;

////LRESULT CALLBACK KeyPressed(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
////	GetWindowRect(hWnd, &winParams);
////	switch (wParam) {
////	case VK_UP:
////		if (winParams.top - 10 > 0) {
////			winParams.top -= 10;
////			winParams.bottom -= 10;
////		}
////		break;
////	case VK_DOWN:
////		if (winParams.bottom + 10 < 1080) {
////			winParams.top += 10;
////			winParams.bottom += 10;
////		}
////		break;
////	case VK_LEFT:
////		if (winParams.left - 10 > 0) {
////			winParams.left -= 10;
////			winParams.right -= 10;
////		}
////		break;
////	case VK_RIGHT:
////		if (winParams.right + 10 < 1920) {
////			winParams.left += 10;
////			winParams.right += 10;
////		}
////		break;
////	}
////	MoveWindow(hWnd, winParams.left, winParams.top, winParams.right - winParams.left, winParams.bottom - winParams.top, TRUE);
////	return 0;
////}

LRESULT CALLBACK KeyPressed(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	switch (wParam) {
	case VK_UP:
		VerticalMove = 1;
		HorizontalMove = 0;
		break;
	case VK_DOWN:
		VerticalMove = -1;
		HorizontalMove = 0;
		break;
	case VK_LEFT:
		VerticalMove = 0;
		HorizontalMove = -1;
		break;
	case VK_RIGHT:
		VerticalMove = 0;
		HorizontalMove = 1;
		break;
	}
	return 0;
}

//LRESULT CALLBACK TimerClicked(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
//	if (VerticalMove || HorizontalMove) {
//		GetWindowRect(hWnd, &winParams);
//		if (VerticalMove > 0) {
//			if (winParams.top - 10 > 0) {
//				winParams.top -= 10;
//				winParams.bottom -= 10;
//			}
//		}
//		else if (VerticalMove < 0) {
//			if (winParams.bottom + 10 < GetSystemMetrics(SM_CYSCREEN)) {
//				winParams.top += 10;
//				winParams.bottom += 10;
//			}
//		}
//		else if (HorizontalMove < 0) {
//			if (winParams.left - 10 > 0) {
//				winParams.left -= 10;
//				winParams.right -= 10;
//			}
//		}
//		else if (HorizontalMove > 0) {
//			if (winParams.right + 10 < GetSystemMetrics(SM_CXSCREEN)) {
//				winParams.left += 10;
//				winParams.right += 10;
//			}
//		}
//		MoveWindow(hWnd, winParams.left, winParams.top, winParams.right - winParams.left, winParams.bottom - winParams.top, TRUE);
//	}
//	return 0;
//}

LRESULT CALLBACK ToClose(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	int res;
	res = MessageBox(hWnd, TEXT("�� ������������� ������?"), TEXT("�������� ������..."), MB_YESNO | MB_ICONINFORMATION);

	if (res == IDYES) {
		res = MessageBox(hWnd, TEXT("�� �������?"), TEXT("�������� ������..."), MB_YESNO | MB_ICONINFORMATION);
		if (res == IDYES) {
			res = MessageBox(hWnd, TEXT("�� ��������� �������?"), TEXT("�������� ������..."), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) {
				DestroyWindow(hWnd);
			}
		}
	}

	if (res == IDNO) {
		MessageBox(hWnd, TEXT("��� ������� :)"), TEXT("���!"), MB_OK);
	}
	return 0;
}

LRESULT CALLBACK ToDestroy(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	PostQuitMessage(0);
	return 0;
}

LRESULT CALLBACK ToRunAway(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	GetWindowRect(hWnd, &winParams);
	int winWidht = winParams.right - winParams.left, winHeight = winParams.bottom - winParams.top;
	int newTop = rand() % (GetSystemMetrics(SM_CYSCREEN) - winHeight), newLeft = rand() % (GetSystemMetrics(SM_CXSCREEN) - winWidht);
	MoveWindow(hWnd, newLeft, newTop, winWidht, winHeight, TRUE);
	return 0;
}

LRESULT CALLBACK IfLeftButtonClicked(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	hStatic = CreateWindowEx(0, TEXT("STATIC"), 0, WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | WS_EX_CLIENTEDGE,
		GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), 100, 20, hWnd, 0, hInstance, 0);
	swprintf(buf, 20, TEXT("X: %d, Y: %d"), GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
	SetWindowText(hStatic, buf);
	return 0;
}

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	MSG Msg;
	WNDCLASSEX wcl;
	hInstance = hInst;

	// 1. ����������� ������ ����
	wcl.cbSize = sizeof(wcl);	// ������ ��������� WNDCLASSEX
	// ������������ �� ����, ���� ������� ������ �� ����������� ��� �� ���������
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - ����� ������ ����
	wcl.lpfnWndProc = WindowProc;	// ����� ������� ���������
	wcl.cbClsExtra = 0;		// ������������ Windows 
	wcl.cbWndExtra = 0; 	// ������������ Windows 
	wcl.hInstance = hInst;	// ���������� ������� ����������
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �������� ����������� ������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// �������� ������������ �������	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ���������� ���� ����� ������
	wcl.lpszMenuName = NULL;	// ���������� �� �������� ����
	wcl.lpszClassName = szClassWindow;	// ��� ������ ����
	wcl.hIconSm = NULL;	// ���������� ��������� ������ ��� ����� � ������� ����

	// 2. ����������� ������ ����
	if (!RegisterClassEx(&wcl))
		return 0; // ��� ��������� ����������� - �����

	// 3. �������� ����
	// ��������� ���� �  ���������� hWnd ������������� ���������� ����
	hWnd = CreateWindowEx(
		0,		// ����������� ����� ����
		szClassWindow,	//��� ������ ����
		TEXT("������ Windows ����������"), // ��������� ����
		WS_OVERLAPPEDWINDOW,				// ����� ����
		/* ���������, �����, ����������� ������ �������, ��������� ����, ������ ������������ � ���������� ����  */
		CW_USEDEFAULT,	// �-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// y-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// ������ ����
		CW_USEDEFAULT,	// ������ ����
		NULL,			// ���������� ������������� ����
		NULL,			// ���������� ���� ����
		hInst,		// ������������� ����������, ���������� ����
		NULL);		// ��������� �� ������� ������ ����������

	// 4. ����������� ����
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // ����������� ����
	//SetTimer(hWnd, 1, 10, NULL);

	//eventMap[WM_TIMER] = TimerClicked;
	eventMap[WM_KEYDOWN] = KeyPressed;
	eventMap[WM_CLOSE] = ToClose;
	eventMap[WM_DESTROY] = ToDestroy;
	//eventMap[WM_MOUSEMOVE] = ToRunAway;
	eventMap[WM_LBUTTONDOWN] = IfLeftButtonClicked;

	// 5. ������ ����� ��������� ���������
	while (GetMessage(&Msg, NULL, 0, 0)) // ��������� ���������� ��������� �� ������� ���������
	{
		TranslateMessage(&Msg);	// ���������� ���������
		DispatchMessage(&Msg);	// ��������������� ���������
	}
	return Msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	if (eventMap.find(uMessage) != eventMap.end()) {
		return eventMap[uMessage](hWnd, uMessage, wParam, lParam);
	}
	else {
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
}
