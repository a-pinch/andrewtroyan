#include "details.h"
#include <Windows.h>
#include <windowsx.h>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

LRESULT CALLBACK WndProcMain(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcForDeck(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcForCardsInDeck(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK WndProcForSuitDecks(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lCmdLine, int nCmdShow) {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	LoadCardBitmaps(cardFaces);

	MSG msg;
	WNDCLASSEX wc;

	FillWinClassAttributes(wc, WndProcMain);

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"Cannot register a class.", L"Error", MB_ICONERROR);
		DeleteCardBitmaps(cardFaces);
		DeleteOtherObjects();
		return 1;
	}

	hMainWnd = CreateWindow(szClassName, L"Klondike", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		NULL, NULL, hInstance, NULL);

	if (!hMainWnd) {
		MessageBox(NULL, L"Cannot register main window.", L"Error", MB_ICONERROR);
		DeleteCardBitmaps(cardFaces);
		DeleteOtherObjects();
		return 1;
	}

	GetClientRect(hMainWnd, &mainWndClientRect);
	mainWndHeight = mainWndClientRect.bottom;
	mainWndWidth = mainWndClientRect.right;

	offsetInWidth = mainWndWidth / 7;
	offsetInHeight = mainWndHeight / 3;

	HWND hWndBuffer = NULL;

	hDeck = CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | SS_NOTIFY | SS_BITMAP,
		(offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth, objectsHeight,
		hMainWnd, NULL, hInstance, NULL);
	SendMessage(hDeck, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hCardBack);
	standardWndProcForStatics = (WNDPROC)SetWindowLong(hDeck, GWL_WNDPROC, (LONG)WndProcForDeck);

	int cardIndex = 0;

	for (auto it : cardFaces) {
		hWndBuffer = CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | SS_NOTIFY | SS_BITMAP,
			(offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth, objectsHeight,
			hMainWnd, (HMENU)cardIndex++, hInstance, NULL);
		SendMessage(hWndBuffer, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)it);
		SetWindowLong(hWndBuffer, GWL_WNDPROC, (LONG)WndProcForCardsInDeck);
		cards.push_back(hWndBuffer);
	}

	BringWindowToTop(hDeck);

	shuffle(cards.begin(), cards.end(), default_random_engine(seed));

	currentCardInDeck = cards.begin();

	int tempWidthOffset = 3 * offsetInWidth;

	for (int i = 0; i < 4; ++i) {
		hSuitDecks.push_back(CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | SS_NOTIFY,
			tempWidthOffset + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth, objectsHeight,
			hMainWnd, NULL, hInstance, NULL));
		tempWidthOffset += offsetInWidth;
	}

	tempWidthOffset = 0;

	for (int i = 0; i < 7; ++i) {
		hCardColumns.push_back(CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | SS_NOTIFY,
			tempWidthOffset + (offsetInWidth - objectsWidth) / 2, offsetInHeight + (offsetInHeight - objectsHeight) / 2, objectsWidth, 
			objectsHeight, hMainWnd, NULL, hInstance, NULL));
		tempWidthOffset += offsetInWidth;
	}

	ShowWindow(hMainWnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	DeleteCardBitmaps(cardFaces);
	DeleteOtherObjects();

	return 0;
}

LRESULT CALLBACK WndProcMain(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CTLCOLORSTATIC:
		if (find(hSuitDecks.begin(), hSuitDecks.end(), (HWND)lParam) != hSuitDecks.end() ||
			find(hCardColumns.begin(), hCardColumns.end(), (HWND)lParam) != hCardColumns.end()) {
			SetBkColor((HDC)wParam, RGB(5, 157, 9));
			return (INT_PTR)CreateHatchBrush(HS_DIAGCROSS, RGB(0, 0, 0));
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

LRESULT CALLBACK WndProcForDeck(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_LBUTTONUP:
		if (currentCardInDeck != cards.end()) {
			MoveWindow(*currentCardInDeck, offsetInWidth + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth,
				objectsHeight, TRUE);
			BringWindowToTop(*currentCardInDeck);

			++currentCardInDeck;
			if (currentCardInDeck == cards.end()) {
				SendMessage(hWnd, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hEndOfDeck);
			}
		}
		else {
			currentCardInDeck = cards.begin();
			SendMessage(hWnd, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hCardBack);
			SendMessage(hWnd, WM_LBUTTONUP, wParam, lParam);
		}
		break;

	default:
		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK WndProcForCardsInDeck(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	static bool isClicked = false;
	static RECT windowRect = { 0 };
	static int controlHeight = 0, controlWidth = 0;

	POINT mousePos;

	switch (uMsg) {
	case WM_LBUTTONDOWN:
		isClicked = true;
		GetWindowRect(hWnd, &windowRect);
		controlHeight = windowRect.bottom - windowRect.top;
		controlWidth = windowRect.right - windowRect.left;
		SetCapture(hWnd);
		break;

	case WM_MOUSEMOVE:
		if (isClicked) {
			mousePos.x = GET_X_LPARAM(lParam);
			mousePos.y = GET_Y_LPARAM(lParam);

			ClientToScreen(hWnd, &mousePos);
			ScreenToClient(hMainWnd, &mousePos);

			MoveWindow(hWnd, mousePos.x, mousePos.y, controlWidth, controlHeight, TRUE);
		}
		break;

	case WM_LBUTTONUP:
		ReleaseCapture();
		isClicked = false;
		break;

	default:
		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

//LRESULT CALLBACK WndProcForSuitDecks(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	int index = 0;
//	HWND hCard;
//	Card currentCard = { 0 };
//
//	switch (uMsg) {
//	case WM_ADDCARD:
//		hCard = (HWND)lParam;
//
//		if (find(cards.begin(), cards.end(), [hCard](Card curCard){ curCard.hWinCard == hCard; }) != cards.end()) {
//
//		}
//			
//
//		break;
//
//	default:
//		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
//	}
//
//	return 0;
//}