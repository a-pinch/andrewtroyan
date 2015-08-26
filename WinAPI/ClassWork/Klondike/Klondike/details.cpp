#include "details.h"
#include <string>

using namespace std;

int LoadCardBitmaps(vector<HBITMAP>& cardBitmaps) {
	HBITMAP hBitMapBuffer;
	int cardIndex;
	wstring stringStorage, stringBuffer;
	wchar_t dozen;
	bool check;

	for (int i = 0; i < 4; ++i) {
		check = true;
		cardIndex = 1;
		dozen = L'0';

		switch (i) {
		case 0:
			stringStorage = L"Diamonds\\";
			break;
		case 1:
			stringStorage = L"Clubs\\";
			break;
		case 2:
			stringStorage = L"Hearts\\";
			break;
		case 3:
			stringStorage = L"Spades\\";
			break;
		}

		while (cardIndex <= 13) {
			if (check && cardIndex >= 10) {
				dozen = L'1';
				check = false;
			}

			stringBuffer = stringStorage + dozen + to_wstring(cardIndex % 10)[0] + L".bmp";
			hBitMapBuffer = (HBITMAP)LoadImage(NULL, stringBuffer.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			cardBitmaps.push_back(hBitMapBuffer);
			++cardIndex;
		}
	}
	
	return 0;
}

int DeleteCardBitmaps(vector<HBITMAP>& cardsBitmaps) {
	for (auto it : cards) {
		DeleteObject(it);
	}
	return 0;
}

int DeleteOtherObjects() {
	DeleteObject(hCardBack);
	DeleteObject(hEndOfDeck);
	DeleteObject(hNoMoreCards);
	DeleteObject(hGreenBrush);
	DeleteObject(hDiagonalBrush);

	return 0;
}

int FillWinClassAttributes(WNDCLASSEX& wc, WNDPROC WndProc) {
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(wc);
	wc.cbWndExtra = 0;
	wc.hbrBackground = hGreenBrush;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = szClassName;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	return 0;
}