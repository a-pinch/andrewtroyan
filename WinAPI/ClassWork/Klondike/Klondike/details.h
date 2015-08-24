#pragma once

#include <Windows.h>
#include <vector>

#define WM_ADDCARD 0x1000

using namespace std;

// 0-12 - Diamonds
// 13-25 - Hearts
// 26-38 - Clubs
// 39-51 - Spades

static const wchar_t szClassName[] = L"KlodikeClass";

static vector<HBITMAP> cardFaces;
static const HBITMAP hCardBack = (HBITMAP)LoadImage(NULL, L"back.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
static const HBITMAP hEndOfDeck = (HBITMAP)LoadImage(NULL, L"end_of_deck.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
static const HBITMAP hNoMoreCards = (HBITMAP)LoadImage(NULL, L"no_more_cards.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
static const HBRUSH hGreenBrush = CreateSolidBrush(RGB(5, 157, 9));
static const HBRUSH hCrossBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 0));

static const HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(NULL);

static HWND hMainWnd = NULL, hDeck = NULL;
static vector<HWND> hSuitDecks;
static vector<HWND> hCardColumns;

static WNDPROC standardWndProcForStatics = NULL;

static vector<HWND> cards;
static vector<vector<HWND>> suitDecks = vector<vector<HWND>>(4);
static vector<vector<HWND>> cardColums = vector<vector<HWND>>(7);

static RECT mainWndClientRect = { 0 };
static int mainWndWidth, mainWndHeight;
static int offsetInWidth, offsetInHeight;
static const int objectsHeight = 96, objectsWidth = 71;
static vector<HWND>::iterator currentCardInDeck;
static int indexOfCurrentCardInDeck;

int LoadCardBitmaps(vector<HBITMAP>&);
int DeleteCardBitmaps(vector<HBITMAP>&);
int DeleteOtherObjects();

int FillWinClassAttributes(WNDCLASSEX&, WNDPROC WndProc);


