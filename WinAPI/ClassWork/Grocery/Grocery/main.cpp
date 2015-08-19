#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <codecvt>

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

wchar_t szClassName[] = L"ClassForGroceries";
vector<wstring> goodsInShop, goodsInBasket;
HWND hMainWnd, hListShop, hListBusket, hButtonToBusket, hButtonFromBusket, hButtonBuy;
RECT mainWndClientRect;
HINSTANCE hInst;
int mainWndWidth, mainWndHeight;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, "rus");

	//---

	wifstream fileWithGoods("goods.txt", wifstream::in);

	if (!fileWithGoods.is_open()) {
		MessageBox(NULL, L"Cannot open file.", L"Error.", MB_OK | MB_ICONERROR);
		return -1;
	}

	fileWithGoods.imbue(std::locale(fileWithGoods.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));

	wstring stringBuffer;

	while (getline(fileWithGoods, stringBuffer)) {
		goodsInShop.push_back(stringBuffer);
	}

	fileWithGoods.close();

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
		return -1;
	}

	// ---

	hMainWnd = CreateWindow(szClassName, L"Groceries", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hMainWnd) {
		MessageBox(NULL, L"Cannot create window.", L"Error", MB_OK | MB_ICONERROR);
		return -1;
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
	int index;
	wstring finalMessage;

	switch (uMsg) {
	case WM_CREATE:
		DefWindowProc(hWnd, uMsg, wParam, lParam);

		GetClientRect(hWnd, &mainWndClientRect);
		mainWndHeight = mainWndClientRect.bottom - mainWndClientRect.top;
		mainWndWidth = mainWndClientRect.right - mainWndClientRect.left;

		hListShop = CreateWindow(L"LISTBOX", L"", WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER, mainWndWidth / 10, mainWndHeight / 5, 
			3 * mainWndWidth / 10, 3 * mainWndHeight / 5, hWnd, NULL, hInst, NULL);

		for (auto it : goodsInShop) {
			SendMessage(hListShop, LB_ADDSTRING, 0, (LPARAM)it.c_str());
		}

		hListBusket = CreateWindow(L"LISTBOX", L"", WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER, mainWndWidth / 10 + mainWndWidth / 2, mainWndHeight / 5,
			3 * mainWndWidth / 10, 3 * mainWndHeight / 5, hWnd, NULL, hInst, NULL);

		hButtonToBusket = CreateWindow(L"BUTTON", L"To busket", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, mainWndWidth / 2 - mainWndWidth / 20, mainWndHeight / 5 + mainWndHeight / 10, 
			mainWndWidth / 10, mainWndHeight / 9, hWnd, NULL, hInst, NULL);

		hButtonFromBusket = CreateWindow(L"BUTTON", L"From busket", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, mainWndWidth / 2 - mainWndWidth / 20, 2 * mainWndHeight / 5 + mainWndHeight / 10,
			mainWndWidth / 10, mainWndHeight / 9, hWnd, NULL, hInst, NULL);

		hButtonBuy = CreateWindow(L"BUTTON", L"Buy", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 2 * mainWndWidth / 5, 4 * mainWndHeight / 5, mainWndWidth / 5, mainWndHeight / 10,
			hWnd, NULL, hInst, NULL);

		break;

	case WM_SIZE:
		DefWindowProc(hWnd, uMsg, wParam, lParam);

		GetClientRect(hWnd, &mainWndClientRect);
		mainWndHeight = mainWndClientRect.bottom - mainWndClientRect.top;
		mainWndWidth = mainWndClientRect.right - mainWndClientRect.left;

		MoveWindow(hListShop, mainWndWidth / 10, mainWndHeight / 5, 3 * mainWndWidth / 10, 3 * mainWndHeight / 5, FALSE);
		MoveWindow(hListBusket, mainWndWidth / 10 + mainWndWidth / 2, mainWndHeight / 5, 3 * mainWndWidth / 10, 3 * mainWndHeight / 5, FALSE);
		MoveWindow(hButtonToBusket, mainWndWidth / 2 - mainWndWidth / 20, mainWndHeight / 5 + mainWndHeight / 10, mainWndWidth / 10, mainWndHeight / 9, FALSE);
		MoveWindow(hButtonFromBusket, mainWndWidth / 2 - mainWndWidth / 20, 2 * mainWndHeight / 5 + mainWndHeight / 10, mainWndWidth / 10, mainWndHeight / 9, FALSE);
		MoveWindow(hButtonBuy, 2 * mainWndWidth / 5, 4 * mainWndHeight / 5, mainWndWidth / 5, mainWndHeight / 10, FALSE);
		break;

	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED) {
			if (HWND(lParam) == hButtonToBusket) {
				index = SendMessage(hListShop, LB_GETCURSEL, 0, 0);
				if (index != LB_ERR) {
					for (auto it : goodsInBasket) {
						if (goodsInShop[index] == it)
							return 0;
					}

					SendMessage(hListBusket, LB_ADDSTRING, 0, (LPARAM)goodsInShop[index].c_str());
					goodsInBasket.push_back(goodsInShop[index]);
				}
			}
			else if (HWND(lParam) == hButtonFromBusket) {
				index = SendMessage(hListBusket, LB_GETCURSEL, 0, 0);
				if (index != LB_ERR) {
					SendMessage(hListBusket, LB_DELETESTRING, index, 0);
					goodsInBasket.erase(goodsInBasket.begin() + index);
				}
			}
			else if (HWND(lParam) == hButtonBuy) {
				if (!goodsInBasket.size()) {
					finalMessage = L"You bought nothing!";
				}
				else {
					finalMessage = L"You bought:\n";
					for (auto it : goodsInBasket) {
						finalMessage += it + L"\n";
					}
				}
				MessageBox(NULL, finalMessage.c_str(), L"Groceries", MB_OK);
				DestroyWindow(hWnd);
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