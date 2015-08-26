#include "details.h"
#include <Windows.h>
#include <windowsx.h>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <string>

using namespace std;

LRESULT CALLBACK WndProcMain(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcForDeck(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcForCardsInDeck(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcForSuitDecks(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcForCardsInSuitsDecks(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcForColumns(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcForCardsInColumns(HWND, UINT, WPARAM, LPARAM);

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

	shuffle(cards.begin(), cards.end(), default_random_engine(seed));

	int tempWidthOffset = 3 * offsetInWidth;

	for (int i = 0; i < 4; ++i) {
		hWndBuffer = CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | SS_NOTIFY,
			tempWidthOffset + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth, objectsHeight,
			hMainWnd, (HMENU)i, hInstance, NULL);
		tempWidthOffset += offsetInWidth;
		SetWindowLong(hWndBuffer, GWL_WNDPROC, (LONG)WndProcForSuitDecks);
		hSuitDecks.push_back(hWndBuffer);
	}

	tempWidthOffset = 0;

	for (int i = 0; i < 7; ++i) {
		hWndBuffer = CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | SS_NOTIFY,
			tempWidthOffset + (offsetInWidth - objectsWidth) / 2, offsetInHeight + (offsetInHeight - objectsHeight) / 2, objectsWidth, 
			objectsHeight, hMainWnd, (HMENU)i, hInstance, NULL);
		tempWidthOffset += offsetInWidth;
		SetWindowLong(hWndBuffer, GWL_WNDPROC, (LONG)WndProcForColumns);
		hCardColumns.push_back(hWndBuffer);
	}

	// Computer adds cards to columns

	for (int i = 1; i < 7; ++i) {
		SendMessage(hCardColumns[i], WM_ADDCLOSEDCARD, (WPARAM)i, (LPARAM)*(cards.begin()));
		cards.erase(cards.begin());
	}

	for (int i = 2; i < 7; ++i) {
		for (int j = i; j < 7; ++j) {
			SendMessage(*(cardColumns[i].rbegin()), WM_ADDCLOSEDCARD, (WPARAM)j, (LPARAM)*(cards.begin()));
			cards.erase(cards.begin());
		}
	}

	SendMessage(hCardColumns[0], WM_ADDCARDFROMCOMPUTER, (WPARAM)0, (LPARAM)*(cards.begin()));
	cards.erase(cards.begin());

	for (int i = 1; i < 7; ++i) {
		SendMessage(*(cardColumns[i].rbegin()), WM_ADDCARDFROMCOMPUTER, (WPARAM)i, (LPARAM)*(cards.begin()));
		cards.erase(cards.begin());
	}

	// Computer adds

	currentCardInDeck = cards.begin();
	indexOfCurrentCardInDeck = 0;

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
			SetBkColor((HDC)wParam, phone);
			return (INT_PTR)hDiagonalBrush;
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
			SendMessage(hWnd, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hCardBack);
			BringWindowToTop(*currentCardInDeck);

			++currentCardInDeck;
			++indexOfCurrentCardInDeck;
			if (currentCardInDeck == cards.end()) {
				currentCardInDeck = cards.begin();
				indexOfCurrentCardInDeck = 0;
				SendMessage(hWnd, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hEndOfDeck);
			}
		}
		else {
			if (cards.size() <= 1) {
				SendMessage(hWnd, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hNoMoreCards);
			}
		}
		break;

	default:
		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK WndProcForCardsInDeck(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	static bool isClicked = false;

	POINT mousePos;
	RECT finalPosRect;
	int indexOfSuitDeck, indexOfColumn;
	int result;

	switch (uMsg) {
	case WM_LBUTTONDBLCLK:
		for (int i = 0; i < 4; ++i) {
			if (!suitDecks[i].size()) {
				result = SendMessage(hSuitDecks[i], WM_ADDCARD, i, (LPARAM)hWnd);
				if (!result) {
					if (indexOfCurrentCardInDeck) {
						cards.erase(currentCardInDeck - 1);
						currentCardInDeck = cards.begin() + indexOfCurrentCardInDeck - 1;
						--indexOfCurrentCardInDeck;
					}
					else {
						cards.erase(currentCardInDeck + cards.size() - 1);
						currentCardInDeck = cards.begin();
					}
					return 0;
				}
			}
			else {
				result = SendMessage(*(suitDecks[i].rbegin()), WM_ADDCARD, i, (LPARAM)hWnd);
				if (!result) {
					if (indexOfCurrentCardInDeck) {
						cards.erase(currentCardInDeck - 1);
						currentCardInDeck = cards.begin() + indexOfCurrentCardInDeck - 1;
						--indexOfCurrentCardInDeck;
					}
					else {
						cards.erase(currentCardInDeck + cards.size() - 1);
						currentCardInDeck = cards.begin();
					}
					return 0;
				}
			}
		}
		break;

	case WM_LBUTTONDOWN:
		BringWindowToTop(hWnd);
		isClicked = true;
		SetCapture(hWnd);
		break;

	case WM_MOUSEMOVE:
		if (isClicked) {
			mousePos.x = GET_X_LPARAM(lParam);
			mousePos.y = GET_Y_LPARAM(lParam);

			ClientToScreen(hWnd, &mousePos);
			ScreenToClient(hMainWnd, &mousePos);

			MoveWindow(hWnd, mousePos.x, mousePos.y, objectsWidth, objectsHeight, TRUE);
		}
		break;

	case WM_LBUTTONUP:
		ReleaseCapture();
		isClicked = false;

		GetWindowRect(hWnd, &finalPosRect);
		mousePos.x = finalPosRect.left;
		mousePos.y = finalPosRect.top;
		ScreenToClient(hMainWnd, &mousePos);

		if (offsetInHeight - mousePos.y >= objectsHeight / 2) {
			if (mousePos.x > 3 * offsetInWidth && mousePos.x + objectsWidth < 4 * offsetInWidth) {
				indexOfSuitDeck = 0;
			}
			else if (mousePos.x > 4 * offsetInWidth && mousePos.x + objectsWidth < 5 * offsetInWidth) {
				indexOfSuitDeck = 1;
			}
			else if (mousePos.x > 5 * offsetInWidth && mousePos.x + objectsWidth < 6 * offsetInWidth) {
				indexOfSuitDeck = 2;
			}
			else if (mousePos.x > 6 * offsetInWidth && mousePos.x + objectsWidth < mainWndWidth) {
				indexOfSuitDeck = 3;
			}
			else {
				MoveWindow(hWnd, offsetInWidth + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth,
					objectsHeight, TRUE);
				break;
			}

			if (!suitDecks[indexOfSuitDeck].size()) {
				result = SendMessage(hSuitDecks[indexOfSuitDeck], WM_ADDCARD, indexOfSuitDeck, (LPARAM)hWnd);
				if (result) {
					MoveWindow(hWnd, offsetInWidth + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth,
						objectsHeight, TRUE);
				}
				else {
					if (indexOfCurrentCardInDeck) {
						cards.erase(currentCardInDeck - 1);
						currentCardInDeck = cards.begin() + indexOfCurrentCardInDeck - 1;
						--indexOfCurrentCardInDeck;
					}
					else {
						cards.erase(currentCardInDeck + cards.size() - 1);
						currentCardInDeck = cards.begin();
					}
				}
			}
			else {
				result = SendMessage(*(suitDecks[indexOfSuitDeck].rbegin()), WM_ADDCARD, indexOfSuitDeck, (LPARAM)hWnd);
				if (result) {
					MoveWindow(hWnd, offsetInWidth + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth,
						objectsHeight, TRUE);
				}
				else {
					if (indexOfCurrentCardInDeck) {
						cards.erase(currentCardInDeck - 1);
						currentCardInDeck = cards.begin() + indexOfCurrentCardInDeck - 1;
						--indexOfCurrentCardInDeck;
					}
					else {
						cards.erase(currentCardInDeck + cards.size() - 1);
						currentCardInDeck = cards.begin();
					}
				}
			}
		}
		else if ((mousePos.y + objectsHeight) - offsetInHeight > objectsHeight / 2) {
			if (mousePos.x > 0 && mousePos.x + objectsWidth < offsetInWidth) {
				indexOfColumn = 0;
			}
			else if (mousePos.x > offsetInWidth && mousePos.x + objectsWidth < 2 * offsetInWidth) {
				indexOfColumn = 1;
			}
			else if (mousePos.x > 2 * offsetInWidth && mousePos.x + objectsWidth < 3 * offsetInWidth) {
				indexOfColumn = 2;
			}
			else if (mousePos.x > 3 * offsetInWidth && mousePos.x + objectsWidth < 4 * offsetInWidth) {
				indexOfColumn = 3;
			}
			else if (mousePos.x > 4 * offsetInWidth && mousePos.x + objectsWidth < 5 * offsetInWidth) {
				indexOfColumn = 4;
			}
			else if (mousePos.x > 5 * offsetInWidth && mousePos.x + objectsWidth < 6 * offsetInWidth) {
				indexOfColumn = 5;
			}
			else if (mousePos.x > 6 * offsetInWidth && mousePos.x + objectsWidth < 7 * offsetInWidth) {
				indexOfColumn = 6;
			}
			else {
				MoveWindow(hWnd, offsetInWidth + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth,
					objectsHeight, TRUE);
				break;
			}
			
			if (!cardColumns[indexOfColumn].size()) {
				result = SendMessage(hCardColumns[indexOfColumn], WM_ADDCARD, indexOfColumn, (LPARAM)hWnd);
				if (result) {
					MoveWindow(hWnd, offsetInWidth + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth,
						objectsHeight, TRUE);
				}
				else {
					if (indexOfCurrentCardInDeck) {
						cards.erase(currentCardInDeck - 1);
						currentCardInDeck = cards.begin() + indexOfCurrentCardInDeck - 1;
						--indexOfCurrentCardInDeck;
					}
					else {
						cards.erase(currentCardInDeck + cards.size() - 1);
						currentCardInDeck = cards.begin();
					}
				}
			}
			else {
				result = SendMessage(*(cardColumns[indexOfColumn].rbegin()), WM_ADDCARD, indexOfColumn, (LPARAM)hWnd);
				if (result) {
					MoveWindow(hWnd, offsetInWidth + (offsetInWidth - objectsWidth) / 2, (offsetInHeight - objectsHeight) / 2, objectsWidth,
						objectsHeight, TRUE);
				}
				else {
					if (indexOfCurrentCardInDeck) {
						cards.erase(currentCardInDeck - 1);
						currentCardInDeck = cards.begin() + indexOfCurrentCardInDeck - 1;
						--indexOfCurrentCardInDeck;
					}
					else {
						cards.erase(currentCardInDeck + cards.size() - 1);
						currentCardInDeck = cards.begin();
					}
				}
			}
		}

		break;

	default:
		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK WndProcForSuitDecks(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	int index, indexOfCurrentSuitDeck;
	HWND hCard;
	RECT wndRect;
	POINT pos;

	switch (uMsg) {
	case WM_ADDCARD:
		hCard = (HWND)lParam;
		index = GetWindowLong(hCard, GWL_ID);
		indexOfCurrentSuitDeck = wParam;
			
		if (index % 13 == 0) {
			GetWindowRect(hWnd, &wndRect);
			pos.x = wndRect.left;
			pos.y = wndRect.top;
			ScreenToClient(hMainWnd, &pos);

			MoveWindow(hCard, pos.x, pos.y, objectsWidth, objectsHeight, TRUE);
			SetWindowLong(hCard, GWL_WNDPROC, (LONG)WndProcForCardsInSuitsDecks);
			BringWindowToTop(hCard);
			suitDecks[indexOfCurrentSuitDeck].push_back(hCard);

			return 0;
		}
		else {
			return 1;
		}

		break;

	default:
		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
	}

	return 0;
}


LRESULT CALLBACK WndProcForCardsInSuitsDecks(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	int indexOfCard, indexOfCurrentSuitDeck, indexOfLastCardInSuitDeck;
	HWND hCard;
	RECT wndRect;
	POINT pos;

	switch (uMsg) {
	case WM_ADDCARD:
		hCard = (HWND)lParam;
		indexOfCard = GetWindowLong(hCard, GWL_ID);
		indexOfCurrentSuitDeck = wParam;
		indexOfLastCardInSuitDeck = GetWindowLong(*(suitDecks[indexOfCurrentSuitDeck].rbegin()), GWL_ID);

		if (indexOfCard - indexOfLastCardInSuitDeck == 1 && indexOfLastCardInSuitDeck % 13 != 12) {
			GetWindowRect(hWnd, &wndRect);
			pos.x = wndRect.left;
			pos.y = wndRect.top;
			ScreenToClient(hMainWnd, &pos);

			MoveWindow(hCard, pos.x, pos.y, objectsWidth, objectsHeight, TRUE);
			SetWindowLong(hCard, GWL_WNDPROC, (LONG)WndProcForCardsInSuitsDecks);
			BringWindowToTop(hCard);
			suitDecks[indexOfCurrentSuitDeck].push_back(hCard);

			if (suitDecks[0].size() + suitDecks[1].size() + suitDecks[2].size() + suitDecks[3].size() == 52 ) {
				MessageBox(NULL, L"You won!", L"Game over", MB_ICONINFORMATION | MB_OK);
				DestroyWindow(hMainWnd);
			}

			return 0;
		}
		else {
			return 1;
		}

		break;

	default:
		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK WndProcForColumns(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	int index, indexOfCurrentColumn;
	HWND hCard;
	RECT wndRect;
	POINT pos;

	switch (uMsg) {
	case WM_ADDCLOSEDCARD:
		hCard = (HWND)lParam;
		indexOfCurrentColumn = wParam;
		SendMessage(hCard, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hCardBack);

		GetWindowRect(hWnd, &wndRect);
		pos.x = wndRect.left;
		pos.y = wndRect.top;
		ScreenToClient(hMainWnd, &pos);

		MoveWindow(hCard, pos.x, pos.y, objectsWidth, objectsHeight, TRUE);
		SetWindowLong(hCard, GWL_WNDPROC, (LONG)WndProcForCardsInColumns);
		BringWindowToTop(hCard);
		cardColumns[indexOfCurrentColumn].push_back(hCard);

		return 0;

		break;

	case WM_ADDCARDFROMCOMPUTER:
		hCard = (HWND)lParam;
		indexOfCurrentColumn = wParam;

		if (!cardColumns[indexOfCurrentColumn].size()) {
			GetWindowRect(hWnd, &wndRect);
			pos.x = wndRect.left;
			pos.y = wndRect.top;
			ScreenToClient(hMainWnd, &pos);

			MoveWindow(hCard, pos.x, pos.y, objectsWidth, objectsHeight, TRUE);
			SetWindowLong(hCard, GWL_WNDPROC, (LONG)WndProcForCardsInColumns);
			BringWindowToTop(hCard);
			cardColumns[indexOfCurrentColumn].push_back(hCard);

			return 0;
		}
		return 1;

		break;

	case WM_ADDCARD:
		hCard = (HWND)lParam;
		index = GetWindowLong(hCard, GWL_ID);
		indexOfCurrentColumn = wParam;

		if (index % 13 == 12) {
			GetWindowRect(hWnd, &wndRect);
			pos.x = wndRect.left;
			pos.y = wndRect.top;
			ScreenToClient(hMainWnd, &pos);

			MoveWindow(hCard, pos.x, pos.y, objectsWidth, objectsHeight, TRUE);
			SetWindowLong(hCard, GWL_WNDPROC, (LONG)WndProcForCardsInColumns);
			BringWindowToTop(hCard);
			cardColumns[indexOfCurrentColumn].push_back(hCard);

			return 0;
		}
		else {
			return 1;
		}

		break;

	default:
		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK WndProcForCardsInColumns(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	int indexOfCurrentColumn, indexOfCurrentSuit;
	int indexOfCurrentCard, indexOfLastCardInColumn;
	int suitOfCurrentCard, suitOfLastCardInColumn;
	int result;
	int offset;
	HWND hCard;
	RECT wndRect;
	POINT pos;
	HBITMAP cardFace;
	bool to_select = false;

	static POINT firstPos;
	static bool isClicked;
	static int indexOfCurrentColumnStatic; //used only in WM_LBUTTONDOWN
	static bool isAllowedToMove;
	static vector<HWND> selectedCards;

	switch (uMsg) {
	case WM_LBUTTONDBLCLK:
		GetWindowRect(hWnd, &wndRect);
		pos.x = wndRect.left;
		pos.y = wndRect.top;
		ScreenToClient(hMainWnd, &pos);

		if (pos.x > 0 && pos.x + objectsWidth < offsetInWidth) {
			indexOfCurrentColumn = 0;
		}
		else if (pos.x > offsetInWidth && pos.x + objectsWidth < 2 * offsetInWidth) {
			indexOfCurrentColumn = 1;
		}
		else if (pos.x > 2 * offsetInWidth && pos.x + objectsWidth < 3 * offsetInWidth) {
			indexOfCurrentColumn = 2;
		}
		else if (pos.x > 3 * offsetInWidth && pos.x + objectsWidth < 4 * offsetInWidth) {
			indexOfCurrentColumn = 3;
		}
		else if (pos.x > 4 * offsetInWidth && pos.x + objectsWidth < 5 * offsetInWidth) {
			indexOfCurrentColumn = 4;
		}
		else if (pos.x > 5 * offsetInWidth && pos.x + objectsWidth < 6 * offsetInWidth) {
			indexOfCurrentColumn = 5;
		}
		else if (pos.x > 6 * offsetInWidth && pos.x + objectsWidth < 7 * offsetInWidth) {
			indexOfCurrentColumn = 6;
		}

		if (hWnd == *(cardColumns[indexOfCurrentColumn].rbegin())) {
			for (int i = 0; i < 4; ++i) {
				if (!suitDecks[i].size()) {
					result = SendMessage(hSuitDecks[i], WM_ADDCARD, i, (LPARAM)hWnd);
					if (!result) {
						cardColumns[indexOfCurrentColumn].erase(cardColumns[indexOfCurrentColumn].begin() + (cardColumns[indexOfCurrentColumn].size() - 1));

						if (cardColumns[indexOfCurrentColumn].size()) {
							cardFace = (HBITMAP)SendMessage(*(cardColumns[indexOfCurrentColumn].rbegin()), STM_GETIMAGE, WPARAM(IMAGE_BITMAP), 0);
							if (cardFace == hCardBack) {
								indexOfCurrentCard = GetWindowLong(*(cardColumns[indexOfCurrentColumn].rbegin()), GWL_ID);
								SendMessage(*(cardColumns[indexOfCurrentColumn].rbegin()), STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cardFaces[indexOfCurrentCard]);
							}
						}

						return 0;
					}
				}
				else {
					result = SendMessage(*(suitDecks[i].rbegin()), WM_ADDCARD, i, (LPARAM)hWnd);
					if (!result) {
						cardColumns[indexOfCurrentColumnStatic].erase(cardColumns[indexOfCurrentColumnStatic].begin() + (cardColumns[indexOfCurrentColumnStatic].size() - 1));

						if (cardColumns[indexOfCurrentColumnStatic].size()) {
							cardFace = (HBITMAP)SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_GETIMAGE, WPARAM(IMAGE_BITMAP), 0);
							if (cardFace == hCardBack) {
								indexOfCurrentCard = GetWindowLong(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), GWL_ID);
								SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cardFaces[indexOfCurrentCard]);
							}
						}

						return 0;
					}
				}
			}
		}

		break;

	case WM_ADDCLOSEDCARD:
		hCard = (HWND)lParam;
		indexOfCurrentColumn = wParam;
		cardFace = (HBITMAP)SendMessage(*(cardColumns[indexOfCurrentColumn].rbegin()), STM_GETIMAGE, (WPARAM)IMAGE_BITMAP, 0);

		if (cardFace == hCardBack) {
			SendMessage(hCard, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hCardBack);

			GetWindowRect(*(cardColumns[indexOfCurrentColumn].rbegin()), &wndRect);
			pos.x = wndRect.left;
			pos.y = wndRect.top;
			ScreenToClient(hMainWnd, &pos);

			MoveWindow(hCard, pos.x, pos.y + objectsHeight / 6, objectsWidth, objectsHeight, TRUE);
			SetWindowLong(hCard, GWL_WNDPROC, (LONG)WndProcForCardsInColumns);
			BringWindowToTop(hCard);
			cardColumns[indexOfCurrentColumn].push_back(hCard);

			return 0;
		}
		return 1;

		break;

	case WM_ADDCARDFROMCOMPUTER:
		hCard = (HWND)lParam;
		indexOfCurrentColumn = wParam;
		cardFace = (HBITMAP)SendMessage(*(cardColumns[indexOfCurrentColumn].rbegin()), STM_GETIMAGE, (WPARAM)IMAGE_BITMAP, 0);

		if (cardFace == hCardBack) {
			GetWindowRect(*(cardColumns[indexOfCurrentColumn].rbegin()), &wndRect);
			pos.x = wndRect.left;
			pos.y = wndRect.top;
			ScreenToClient(hMainWnd, &pos);

			MoveWindow(hCard, pos.x, pos.y + objectsHeight / 6, objectsWidth, objectsHeight, TRUE);
			SetWindowLong(hCard, GWL_WNDPROC, (LONG)WndProcForCardsInColumns);
			BringWindowToTop(hCard);
			cardColumns[indexOfCurrentColumn].push_back(hCard);

			return 0;
		}
		return 1;

		break;

	case WM_ADDCARD:
		hCard = (HWND)lParam;
		indexOfCurrentColumn = wParam;
		indexOfCurrentCard= GetWindowLong(hCard, GWL_ID);
		indexOfLastCardInColumn = GetWindowLong(*(cardColumns[indexOfCurrentColumn].rbegin()), GWL_ID);
		suitOfCurrentCard = indexOfCurrentCard / 13;
		suitOfLastCardInColumn = indexOfLastCardInColumn / 13;

		if (indexOfCurrentCard % 13 != 12 && indexOfLastCardInColumn % 13 - indexOfCurrentCard % 13 == 1 && (suitOfCurrentCard - suitOfLastCardInColumn) % 2) {
			GetWindowRect(*(cardColumns[indexOfCurrentColumn].rbegin()), &wndRect);
			pos.x = wndRect.left;
			pos.y = wndRect.top;
			ScreenToClient(hMainWnd, &pos);

			MoveWindow(hCard, pos.x, pos.y + objectsHeight / 6, objectsWidth, objectsHeight, TRUE);
			SetWindowLong(hCard, GWL_WNDPROC, (LONG)WndProcForCardsInColumns);
			BringWindowToTop(hCard);
			cardColumns[indexOfCurrentColumn].push_back(hCard);

			return 0;
		}
		else {
			return 1;
		}

		break;

	case WM_LBUTTONDOWN:
		GetWindowRect(hWnd, &wndRect);
		firstPos.x = wndRect.left;
		firstPos.y = wndRect.top;
		ScreenToClient(hMainWnd, &firstPos);

		if (firstPos.x > 0 && firstPos.x + objectsWidth < offsetInWidth) {
			indexOfCurrentColumnStatic = 0;
		}
		else if (firstPos.x > offsetInWidth && firstPos.x + objectsWidth < 2 * offsetInWidth) {
			indexOfCurrentColumnStatic = 1;
		}
		else if (firstPos.x > 2 * offsetInWidth && firstPos.x + objectsWidth < 3 * offsetInWidth) {
			indexOfCurrentColumnStatic = 2;
		}
		else if (firstPos.x > 3 * offsetInWidth && firstPos.x + objectsWidth < 4 * offsetInWidth) {
			indexOfCurrentColumnStatic = 3;
		}
		else if (firstPos.x > 4 * offsetInWidth && firstPos.x + objectsWidth < 5 * offsetInWidth) {
			indexOfCurrentColumnStatic = 4;
		}
		else if (firstPos.x > 5 * offsetInWidth && firstPos.x + objectsWidth < 6 * offsetInWidth) {
			indexOfCurrentColumnStatic = 5;
		}
		else if (firstPos.x > 6 * offsetInWidth && firstPos.x + objectsWidth < 7 * offsetInWidth) {
			indexOfCurrentColumnStatic = 6;
		}

		cardFace = (HBITMAP)SendMessage(hWnd, STM_GETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)0);
		if (cardFace == hCardBack) {
			isAllowedToMove = false;
		}
		else {
			isAllowedToMove = true;

			for (auto it : cardColumns[indexOfCurrentColumnStatic]) {
				if (it == hWnd)
					to_select = true;

				if (to_select) {
					selectedCards.push_back(it);
				}
			}
		}

		for (auto it : selectedCards) {
			BringWindowToTop(it);
		}

		isClicked = true;
		SetCapture(hWnd);
		break;

	case WM_MOUSEMOVE:
		if (isClicked && isAllowedToMove) {
			pos.x = GET_X_LPARAM(lParam);
			pos.y = GET_Y_LPARAM(lParam);

			ClientToScreen(hWnd, &pos);
			ScreenToClient(hMainWnd, &pos);

			//MoveWindow(hWnd, pos.x, pos.y, objectsWidth, objectsHeight, TRUE);

			offset = 0;
			for (vector<HWND>::iterator it = selectedCards.begin(); it != selectedCards.end(); ++it) {
				MoveWindow(*it, pos.x, pos.y + offset, objectsWidth, objectsHeight, TRUE);
				offset += objectsHeight / 6;
			}
		}
		break;

	case WM_LBUTTONUP:
		ReleaseCapture();
		isClicked = false;

		GetWindowRect(hWnd, &wndRect);
		pos.x = wndRect.left;
		pos.y = wndRect.top;
		ScreenToClient(hMainWnd, &pos);

		if (offsetInHeight - pos.y >= objectsHeight / 2) {
			if (selectedCards.size() > 1) {
				offset = 0;
				for (vector<HWND>::iterator it = selectedCards.begin(); it != selectedCards.end(); ++it) {
					MoveWindow(*it, firstPos.x, firstPos.y + offset, objectsWidth, objectsHeight, TRUE);
					offset += objectsHeight / 6;
				}
				selectedCards.clear();
				return 0;
			}

			if (pos.x > 3 * offsetInWidth && pos.x + objectsWidth < 4 * offsetInWidth) {
				indexOfCurrentSuit = 0;
			}
			else if (pos.x > 4 * offsetInWidth && pos.x + objectsWidth < 5 * offsetInWidth) {
				indexOfCurrentSuit = 1;
			}
			else if (pos.x > 5 * offsetInWidth && pos.x + objectsWidth < 6 * offsetInWidth) {
				indexOfCurrentSuit = 2;
			}
			else if (pos.x > 6 * offsetInWidth && pos.x + objectsWidth < mainWndWidth) {
				indexOfCurrentSuit = 3;
			}
			else {
				offset = 0;
				for (vector<HWND>::iterator it = selectedCards.begin(); it != selectedCards.end(); ++it) {
					MoveWindow(*it, firstPos.x, firstPos.y + offset, objectsWidth, objectsHeight, TRUE);
					offset += objectsHeight / 6;
				}
				selectedCards.clear();
				return 0;
			}

			if (!suitDecks[indexOfCurrentSuit].size()) {
				result = SendMessage(hSuitDecks[indexOfCurrentSuit], WM_ADDCARD, indexOfCurrentSuit, (LPARAM)hWnd);
				if (result) {
					MoveWindow(hWnd, firstPos.x, firstPos.y, objectsWidth, objectsHeight, TRUE);
				}
				else {
					cardColumns[indexOfCurrentColumnStatic].erase(cardColumns[indexOfCurrentColumnStatic].begin() + (cardColumns[indexOfCurrentColumnStatic].size() - 1));
					
					if (cardColumns[indexOfCurrentColumnStatic].size()) {
						cardFace = (HBITMAP)SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_GETIMAGE, WPARAM(IMAGE_BITMAP), 0);
						if (cardFace == hCardBack) {
							indexOfCurrentCard = GetWindowLong(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), GWL_ID);
							SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cardFaces[indexOfCurrentCard]);
						}
					}
				}
			}
			else {
				result = SendMessage(*(suitDecks[indexOfCurrentSuit].rbegin()), WM_ADDCARD, indexOfCurrentSuit, (LPARAM)hWnd);
				if (result) {
					MoveWindow(hWnd, firstPos.x, firstPos.y, objectsWidth, objectsHeight, TRUE);
					selectedCards.clear();
					return 0;
				}
				else {
					cardColumns[indexOfCurrentColumnStatic].erase(cardColumns[indexOfCurrentColumnStatic].begin() + (cardColumns[indexOfCurrentColumnStatic].size() - 1));
				
					if (cardColumns[indexOfCurrentColumnStatic].size()) {
						cardFace = (HBITMAP)SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_GETIMAGE, WPARAM(IMAGE_BITMAP), 0);
						if (cardFace == hCardBack) {
							indexOfCurrentCard = GetWindowLong(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), GWL_ID);
							SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cardFaces[indexOfCurrentCard]);
						}
					}
				}
			}
		}
		else if ((pos.y + objectsHeight) - offsetInHeight > objectsHeight / 2) {
			if (pos.x > 0 && pos.x + objectsWidth < offsetInWidth) {
				indexOfCurrentColumn = 0;
			}
			else if (pos.x > offsetInWidth && pos.x + objectsWidth < 2 * offsetInWidth) {
				indexOfCurrentColumn = 1;
			}
			else if (pos.x > 2 * offsetInWidth && pos.x + objectsWidth < 3 * offsetInWidth) {
				indexOfCurrentColumn = 2;
			}
			else if (pos.x > 3 * offsetInWidth && pos.x + objectsWidth < 4 * offsetInWidth) {
				indexOfCurrentColumn = 3;
			}
			else if (pos.x > 4 * offsetInWidth && pos.x + objectsWidth < 5 * offsetInWidth) {
				indexOfCurrentColumn = 4;
			}
			else if (pos.x > 5 * offsetInWidth && pos.x + objectsWidth < 6 * offsetInWidth) {
				indexOfCurrentColumn = 5;
			}
			else if (pos.x > 6 * offsetInWidth && pos.x + objectsWidth < 7 * offsetInWidth) {
				indexOfCurrentColumn = 6;
			}
			else {
				offset = 0;
				for (vector<HWND>::iterator it = selectedCards.begin(); it != selectedCards.end(); ++it) {
					MoveWindow(*it, firstPos.x, firstPos.y + offset, objectsWidth, objectsHeight, TRUE);
					offset += objectsHeight / 6;
				}
				selectedCards.clear();
				return 0;
			}

			if (!cardColumns[indexOfCurrentColumn].size()) {
				result = SendMessage(hCardColumns[indexOfCurrentColumn], WM_ADDCARD, indexOfCurrentColumn, (LONG)hWnd);
				if (result) {
					offset = 0;
					for (vector<HWND>::iterator it = selectedCards.begin(); it != selectedCards.end(); ++it) {
						MoveWindow(*it, firstPos.x, firstPos.y + offset, objectsWidth, objectsHeight, TRUE);
						offset += objectsHeight / 6;
					}
				}
				else {
					cardColumns[indexOfCurrentColumnStatic].erase(cardColumns[indexOfCurrentColumnStatic].begin() + (cardColumns[indexOfCurrentColumnStatic].size() - 1));
				
					for (auto it = selectedCards.begin() + 1; it != selectedCards.end(); ++it) {
						SendMessage(hCardColumns[indexOfCurrentColumn], WM_ADDCARD, indexOfCurrentColumn, (LONG)*it);
						cardColumns[indexOfCurrentColumnStatic].erase(cardColumns[indexOfCurrentColumnStatic].begin() + (cardColumns[indexOfCurrentColumnStatic].size() - 1));
					}

					if (cardColumns[indexOfCurrentColumnStatic].size()) {
						cardFace = (HBITMAP)SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_GETIMAGE, WPARAM(IMAGE_BITMAP), 0);
						if (cardFace == hCardBack) {
							indexOfCurrentCard = GetWindowLong(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), GWL_ID);
							SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cardFaces[indexOfCurrentCard]);
						}
					}
				}
			}
			else {
				result = SendMessage(*(cardColumns[indexOfCurrentColumn].rbegin()), WM_ADDCARD, indexOfCurrentColumn, (LONG)hWnd);
				if (result) {
					offset = 0;
					for (vector<HWND>::iterator it = selectedCards.begin(); it != selectedCards.end(); ++it) {
						MoveWindow(*it, firstPos.x, firstPos.y + offset, objectsWidth, objectsHeight, TRUE);
						offset += objectsHeight / 6;
					}
				}
				else {
					cardColumns[indexOfCurrentColumnStatic].erase(cardColumns[indexOfCurrentColumnStatic].begin() + (cardColumns[indexOfCurrentColumnStatic].size() - 1));
				
					for (auto it = selectedCards.begin() + 1; it != selectedCards.end(); ++it) {
						SendMessage(*(cardColumns[indexOfCurrentColumn].rbegin()), WM_ADDCARD, indexOfCurrentColumn, (LONG)*it);
						cardColumns[indexOfCurrentColumnStatic].erase(cardColumns[indexOfCurrentColumnStatic].begin() + (cardColumns[indexOfCurrentColumnStatic].size() - 1));
					}

					if (cardColumns[indexOfCurrentColumnStatic].size()) {
						cardFace = (HBITMAP)SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_GETIMAGE, WPARAM(IMAGE_BITMAP), 0);
						if (cardFace == hCardBack) {
							indexOfCurrentCard = GetWindowLong(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), GWL_ID);
							SendMessage(*(cardColumns[indexOfCurrentColumnStatic].rbegin()), STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cardFaces[indexOfCurrentCard]);
						}
					}
				}
			}
		}

		selectedCards.clear();

		break;

	default:
		return CallWindowProc(standardWndProcForStatics, hWnd, uMsg, wParam, lParam);
	}

	return 0;
}