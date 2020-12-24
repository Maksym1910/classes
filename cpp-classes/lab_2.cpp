#include "stdafx.h"
#include "lab_2.h"
#include "my_editor.h"
#include "my_editor_resource.h"
#include "toolbar.h"
// shapes
#include "Point_Shape.h"
#include "Line_Shape.h"
#include "Rect_Shape.h"
#include "Ellipse_Shape.h"
#include "Cube_Shape.h"
#include "OLineO_Shape.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
COLORREF color = black;
BOOL isFill = false;
MyEditor *ped = new MyEditor;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void whatColor(HWND);
void isF(HWND);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	InitCommonControls();
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB2));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		OnCreate(hWnd, hInst);
		OnPointPressed();
		SetWindowText(hWnd, "Point");
		if (ped) ped->Start(new PointShape);
		break;
	case WM_SIZE:
		OnSize(hWnd);
		break;
	case WM_LBUTTONDOWN:
		if (ped) ped->OnLBdown(hWnd);
		break;
	case WM_LBUTTONUP:
		if (ped) ped->OnLBup(hWnd, color, isFill);
		break;
	case WM_MOUSEMOVE:
		if (ped) ped->OnMouseMove(hWnd);
		break;
	case WM_INITMENUPOPUP:
		if (ped) ped->OnInitMenuPopup(hWnd, wParam);
		whatColor(hWnd);
		isF(hWnd);
		break;
	case WM_NOTIFY:
		OnNotify(hWnd, lParam);
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
				// is fill
			case IDM_FILL:
				isFill = true;
				break;
			case IDM_NOTFILL:
				isFill = false;
				break;
				// colors
			case IDM_RED:
				color = red;
				break;
			case IDM_GREEN:
				color = green;
				break;
			case IDM_BLUE:
				color = blue;
				break;
			case IDM_LITEBLUE:
				color = lite_blue;
				break;
			case IDM_WHITE:
				color = white;
				break;
			case IDM_YELLOW:
				color = yellow;
				break;
			case IDM_PINK:
				color = pink;
				break;
			case IDM_ORANGE:
				color = orange;
				break;
			case IDM_GREY:
				color = grey;
				break;
			case IDM_BLACK:
				color = black;
				break;
				// figures
			case ID_TOOL_POINT:
			case IDM_POINT:
				SetWindowText(hWnd, "Point");
				if (ped) ped->Start(new PointShape);
				OnPointPressed();
				break;
			case ID_TOOL_LINE:
			case IDM_LINE:
				SetWindowText(hWnd, "Line");
				if (ped) ped->Start(new LineShape);
				OnLinePressed();
				break;
			case ID_TOOL_RECTFILL:
				isFill = true;
				OnRectFPressed();
				SetWindowText(hWnd, "Rect");
				if (ped) ped->Start(new RectShape);
				break;
			case ID_TOOL_RECT:
				isFill = false;
			case IDM_RECTANGLE:
				SetWindowText(hWnd, "Rect");
				if (ped) ped->Start(new RectShape);
				if (isFill) OnRectFPressed();
				else OnRectPressed();
				break;
			case ID_TOOL_ELLIPSEFILL:
				isFill = true;
				OnEllipseFPressed();
				SetWindowText(hWnd, "Ellipse");
				if (ped) ped->Start(new EllipseShape);
				break;
			case ID_TOOL_ELLIPSE:
				isFill = false;
			case IDM_ELLIPSE:
				SetWindowText(hWnd, "Ellipse");
				if (ped) ped->Start(new EllipseShape);
				if (isFill) OnEllipseFPressed();
				else OnEllipsePressed();
				break;
			case ID_TOOL_CUBE:
			case IDM_CUBE:
				isFill = false;
				SetWindowText(hWnd, "Cube");
				if (ped) ped->Start(new CubeShape);
				OnCubePressed();
				break;
			case ID_TOOL_OLINEO:
			case IDM_OLINEO:
				isFill = true;
				SetWindowText(hWnd, "OLineO");
				if (ped) ped->Start(new OLineOShape);
				OnOLineOPressed();
				break;
				// other
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
		if (ped) ped->OnPaint(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// func to change CHECKED on menu 
void whatColor(HWND hWnd) {
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 2);
	CheckMenuItem(hSubMenu, IDM_RED, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_GREEN, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_BLUE, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_LITEBLUE, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_WHITE, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_YELLOW, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_PINK, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_ORANGE, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_GREY, MF_UNCHECKED);
	CheckMenuItem(hSubMenu, IDM_BLACK, MF_UNCHECKED);
	switch (color)
	{
	case RGB(255, 0, 0):
		CheckMenuItem(hSubMenu, IDM_RED, MF_CHECKED);
		break;
	case RGB(0, 255, 0):
		CheckMenuItem(hSubMenu, IDM_GREEN, MF_CHECKED);
		break;
	case RGB(0, 0, 255):
		CheckMenuItem(hSubMenu, IDM_BLUE, MF_CHECKED);
		break;
	case RGB(0, 255, 255):
		CheckMenuItem(hSubMenu, IDM_LITEBLUE, MF_CHECKED);
		break;
	case RGB(255, 255, 255):
		CheckMenuItem(hSubMenu, IDM_WHITE, MF_CHECKED);
		break;
	case RGB(255, 255, 0):
		CheckMenuItem(hSubMenu, IDM_YELLOW, MF_CHECKED);
		break;
	case RGB(255, 0, 255):
		CheckMenuItem(hSubMenu, IDM_PINK, MF_CHECKED);
		break;
	case RGB(255, 128, 0):
		CheckMenuItem(hSubMenu, IDM_ORANGE, MF_UNCHECKED);
		break;
	case RGB(192, 192, 192):
		CheckMenuItem(hSubMenu, IDM_GREY, MF_CHECKED);
		break;
	case RGB(0, 0, 0):
		CheckMenuItem(hSubMenu, IDM_BLACK, MF_CHECKED);
		break;
	}
}

void isF(HWND hWnd) {
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 3);
	if (isFill) {
		CheckMenuItem(hSubMenu, IDM_FILL, MF_CHECKED);
		CheckMenuItem(hSubMenu, IDM_NOTFILL, MF_UNCHECKED);
	}
	else {
		CheckMenuItem(hSubMenu, IDM_FILL, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_NOTFILL, MF_CHECKED);
	}
}

