// Файл WINDOWS.H содержит определения, макросы, и структуры 
// которые используются при написании приложений под Windows. 
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <map>

using namespace std;

typedef LRESULT CALLBACK EventProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

// прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");	/* Имя класса окна */

map<UINT, EventProc*> eventMap;

RECT winParams;

int VerticalMove = 0, HorizontalMove = 0;

//LRESULT CALLBACK KeyPressed(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
//	GetWindowRect(hWnd, &winParams);
//	switch (wParam) {
//	case VK_UP:
//		if (winParams.top - 10 > 0) {
//			winParams.top -= 10;
//			winParams.bottom -= 10;
//		}
//		break;
//	case VK_DOWN:
//		if (winParams.bottom + 10 < 1080) {
//			winParams.top += 10;
//			winParams.bottom += 10;
//		}
//		break;
//	case VK_LEFT:
//		if (winParams.left - 10 > 0) {
//			winParams.left -= 10;
//			winParams.right -= 10;
//		}
//		break;
//	case VK_RIGHT:
//		if (winParams.right + 10 < 1920) {
//			winParams.left += 10;
//			winParams.right += 10;
//		}
//		break;
//	}
//	MoveWindow(hWnd, winParams.left, winParams.top, winParams.right - winParams.left, winParams.bottom - winParams.top, TRUE);
//	return 0;
//}

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

LRESULT CALLBACK TimerClicked(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	if (VerticalMove || HorizontalMove) {
		GetWindowRect(hWnd, &winParams);
		if (VerticalMove > 0) {
			if (winParams.top - 10 > 0) {
				winParams.top -= 10;
				winParams.bottom -= 10;
			}
		}
		else if (VerticalMove < 0) {
			if (winParams.bottom + 10 < 1080) {
				winParams.top += 10;
				winParams.bottom += 10;
			}
		}
		else if (HorizontalMove < 0) {
			if (winParams.left - 10 > 0) {
				winParams.left -= 10;
				winParams.right -= 10;
			}
		}
		else if (HorizontalMove > 0) {
			if (winParams.right + 10 < 1920) {
				winParams.left += 10;
				winParams.right += 10;
			}
		}
		MoveWindow(hWnd, winParams.left, winParams.top, winParams.right - winParams.left, winParams.bottom - winParams.top, TRUE);
	}
	return 0;
}

LRESULT CALLBACK ToClose(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	int res;
	res = MessageBox(hWnd, TEXT("Вы действительно хотите?"), TEXT("Ожидание ответа..."), MB_YESNO | MB_ICONINFORMATION);

	if (res == IDYES) {
		res = MessageBox(hWnd, TEXT("Вы уверены?"), TEXT("Ожидание ответа..."), MB_YESNO | MB_ICONINFORMATION);
		if (res == IDYES) {
			res = MessageBox(hWnd, TEXT("Вы абсолютно уверены?"), TEXT("Ожидание ответа..."), MB_YESNO | MB_ICONINFORMATION);
			if (res == IDYES) {
				DestroyWindow(hWnd);
			}
		}
	}

	if (res == IDNO) {
		MessageBox(hWnd, TEXT("Вот молодец :)"), TEXT("Ура!"), MB_OK);
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
	int newTop = rand() % (1080 - winHeight), newLeft = rand() % (1920 - winWidht);
	MoveWindow(hWnd, newLeft, newTop, winWidht, winHeight, TRUE);
	return 0;
}

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;

	// 1. Определение класса окна
	wcl.cbSize = sizeof(wcl);	// размер структуры WNDCLASSEX
	// Перерисовать всё окно, если изменён размер по горизонтали или по вертикали
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - стиль класса окна
	wcl.lpfnWndProc = WindowProc;	// адрес оконной процедуры
	wcl.cbClsExtra = 0;		// используется Windows 
	wcl.cbWndExtra = 0; 	// используется Windows 
	wcl.hInstance = hInst;	// дескриптор данного приложения
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// загрузка стандартного курсора	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// заполнение окна белым цветом
	wcl.lpszMenuName = NULL;	// приложение не содержит меню
	wcl.lpszClassName = szClassWindow;	// имя класса окна
	wcl.hIconSm = NULL;	// отсутствие маленькой иконки для связи с классом окна

	// 2. Регистрация класса окна
	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход

	// 3. Создание окна
	// создается окно и  переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0,		// расширенный стиль окна
		szClassWindow,	//имя класса окна
		TEXT("Каркас Windows приложения"), // заголовок окна
		WS_OVERLAPPEDWINDOW,				// стиль окна
		/* Заголовок, рамка, позволяющая менять размеры, системное меню, кнопки развёртывания и свёртывания окна  */
		CW_USEDEFAULT,	// х-координата левого верхнего угла окна
		CW_USEDEFAULT,	// y-координата левого верхнего угла окна
		CW_USEDEFAULT,	// ширина окна
		CW_USEDEFAULT,	// высота окна
		NULL,			// дескриптор родительского окна
		NULL,			// дескриптор меню окна
		hInst,		// идентификатор приложения, создавшего окно
		NULL);		// указатель на область данных приложения

	// 4. Отображение окна
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна
	SetTimer(hWnd, 1, 10, NULL);

	eventMap[WM_TIMER] = TimerClicked;
	eventMap[WM_KEYDOWN] = KeyPressed;
	eventMap[WM_CLOSE] = ToClose;
	eventMap[WM_DESTROY] = ToDestroy;
	eventMap[WM_MOUSEMOVE] = ToRunAway;

	// 5. Запуск цикла обработки сообщений
	while (GetMessage(&Msg, NULL, 0, 0)) // получение очередного сообщения из очереди сообщений
	{
		TranslateMessage(&Msg);	// трансляция сообщения
		DispatchMessage(&Msg);	// диспетчеризация сообщений
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
