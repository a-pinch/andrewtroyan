#include <windows.h>
#include <vector>
#include <map>
#include <string>
#include <tchar.h>

using namespace std;

struct MotorInfo {
	double capacity;
	int price;
};

vector<wstring> autoNames;
map<wstring, vector<MotorInfo>> autos;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassName[] = TEXT("UserClass");

HWND hMainWindow, hListBox, hQuestionBox, hButtonOK;
HINSTANCE hAppInstance;
int nCmdShowMode;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
	hAppInstance = hInstance;
	nCmdShowMode = nCmdShow;

	autoNames.push_back(TEXT("седан"));
	autoNames.push_back(TEXT("хэтчбек"));
	autoNames.push_back(TEXT("универсал"));
	autoNames.push_back(TEXT("купе"));

	autos[autoNames[0]] = { { 1.5, 15000 }, { 1.7, 17000 }, { 2.0, 23000 } };
	autos[autoNames[1]] = { { 1.2, 13000 }, { 1.5, 16000 }, { 1.7, 20000 } };
	autos[autoNames[2]] = { { 1.5, 15000 }, { 1.7, 17000 }, { 2.0, 23000 } };
	autos[autoNames[3]] = { { 1.5, 17000 }, { 1.7, 19000 }, { 2.0, 25000 } };

	MSG msg;
	WNDCLASSEX wc;

	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(wc);
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
		MessageBox(NULL, TEXT("Cannot create class."), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 1;
	}

	hMainWindow = CreateWindowEx(0, szClassName, TEXT("Auto selection"), WS_OVERLAPPEDWINDOW, 200, 200, 500, 300, NULL, NULL, hInstance, NULL);

	if (!hMainWindow) {
		MessageBox(NULL, TEXT("Cannot create window."), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 1;
	}

	hQuestionBox = CreateWindow(TEXT("STATIC"), TEXT("Выберите кузов:"), WS_CHILD | WS_VISIBLE | SS_CENTER | WS_EX_CLIENTEDGE, 0, 0, 500, 100, hMainWindow, NULL, hInstance, NULL);

	hListBox = CreateWindow(TEXT("LISTBOX"), TEXT("Bulk"), WS_BORDER | WS_CHILD | WS_VISIBLE, 0, 100, 500, 100, hMainWindow, NULL, hAppInstance, NULL);
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)TEXT("седан"));
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)TEXT("хэтчбек"));
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)TEXT("универсал"));
	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)TEXT("купе"));

	hButtonOK = CreateWindow(TEXT("BUTTON"), TEXT("OK"), WS_TABSTOP | WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 200, 200, 100, 50, hMainWindow, NULL, hInstance, NULL);

	ShowWindow(hMainWindow, nCmdShow);
	UpdateWindow(hMainWindow);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static int selectedName = -1, selectedCapacity;
	switch (uMsg) {
	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED) {
			if ((HWND)lParam == hButtonOK) {
				if (selectedName == -1 || selectedName == LB_ERR) {
					selectedName = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
					if (selectedName == LB_ERR) {
						MessageBox(NULL, TEXT("Вы не выбрали ни одного элемента!"), TEXT(""), MB_OK | MB_ICONEXCLAMATION);
					}
					else {
						SetWindowText(hQuestionBox, TEXT("Выберите объем двигателя:"));
						SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
						for (auto it = autos[autoNames[selectedName]].begin(); it != autos[autoNames[selectedName]].end(); ++it) {
							SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)to_wstring(it->capacity).c_str());
						}
					}
				}
				else {
					selectedCapacity = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
					if (selectedCapacity == LB_ERR) {
						MessageBox(NULL, TEXT("Вы не выбрали ни одного элемента!"), TEXT(""), MB_OK | MB_ICONEXCLAMATION);
					}
					else {
						wstring message(TEXT("Данная конфигурация составляет "));
						message += to_wstring(autos[autoNames[selectedName]][selectedCapacity].price).c_str();
						message += L"$";
						MessageBox(NULL, message.c_str(), TEXT(""), MB_OK);
						DestroyWindow(hMainWindow);
					}
				}
			}
		}
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