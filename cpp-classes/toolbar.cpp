#include "stdafx.h"
#include "toolbar.h"

HWND hwndToolBar = NULL;
int whatPressed = ID_TOOL_POINT;

void OnCreate(HWND hWnd, HINSTANCE hInst) {
	TBBUTTON tbb[8];

	ZeroMemory(tbb, sizeof(tbb));
	tbb[0].iBitmap = 0;
	tbb[0].fsState = TBSTATE_ENABLED;
	tbb[0].fsStyle = TBSTYLE_BUTTON;
	tbb[0].idCommand = ID_TOOL_POINT;

	tbb[1].iBitmap = 1;
	tbb[1].fsState = TBSTATE_ENABLED;
	tbb[1].fsStyle = TBSTYLE_BUTTON;
	tbb[1].idCommand = ID_TOOL_LINE;

	tbb[2].iBitmap = 2;
	tbb[2].fsState = TBSTATE_ENABLED;
	tbb[2].fsStyle = TBSTYLE_BUTTON;
	tbb[2].idCommand = ID_TOOL_RECT;

	tbb[3].iBitmap = 3;
	tbb[3].fsState = TBSTATE_ENABLED;
	tbb[3].fsStyle = TBSTYLE_BUTTON;
	tbb[3].idCommand = ID_TOOL_RECTFILL;

	tbb[4].iBitmap = 4;
	tbb[4].fsState = TBSTATE_ENABLED;
	tbb[4].fsStyle = TBSTYLE_BUTTON;
	tbb[4].idCommand = ID_TOOL_ELLIPSE;

	tbb[5].iBitmap = 5;
	tbb[5].fsState = TBSTATE_ENABLED;
	tbb[5].fsStyle = TBSTYLE_BUTTON;
	tbb[5].idCommand = ID_TOOL_ELLIPSEFILL;

	tbb[6].iBitmap = 6;
	tbb[6].fsState = TBSTATE_ENABLED;
	tbb[6].fsStyle = TBSTYLE_BUTTON;
	tbb[6].idCommand = ID_TOOL_CUBE;

	tbb[7].iBitmap = 7;
	tbb[7].fsState = TBSTATE_ENABLED;
	tbb[7].fsStyle = TBSTYLE_BUTTON;
	tbb[7].idCommand = ID_TOOL_OLINEO;

	hwndToolBar = CreateToolbarEx(hWnd,
		WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP | TBSTYLE_TOOLTIPS,
		IDC_TOOLBAR,
		8,
		hInst,
		IDB_BITMAP_TOOL,
		tbb,
		8,
		24, 24, 24, 24,
		sizeof(TBBUTTON));

}

void OnSize(HWND hWnd) {
	RECT rc, rw;

	if (hwndToolBar) {
		GetClientRect(hWnd, &rc);
		GetWindowRect(hwndToolBar, &rw);
		MoveWindow(hwndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
	}
}

static void offPressed(int id) {
	SendMessage(hwndToolBar, TB_PRESSBUTTON, whatPressed, 0);
	whatPressed = id;
}

void OnPointPressed() {
	offPressed(ID_TOOL_POINT);
	SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_POINT, 1);
}

void OnLinePressed() {
	offPressed(ID_TOOL_LINE);
	SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_LINE, 1);
}

void OnRectPressed() {
	offPressed(ID_TOOL_RECT);
	SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_RECT, 1);
}

void OnRectFPressed() {
	offPressed(ID_TOOL_RECTFILL);
	SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_RECTFILL, 1);
}

void OnEllipsePressed() {
	offPressed(ID_TOOL_ELLIPSE);
	SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_ELLIPSE, 1);
}

void OnEllipseFPressed() {
	offPressed(ID_TOOL_ELLIPSEFILL);
	SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_ELLIPSEFILL, 1);
}

void OnCubePressed() {
	offPressed(ID_TOOL_CUBE);
	SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_CUBE, 1);
}

void OnOLineOPressed() {
	offPressed(ID_TOOL_OLINEO);
	SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_OLINEO, 1);
}


void OnNotify(HWND hWnd, LPARAM lParams) {
	LPNMHDR pnhm = (LPNMHDR)lParams;
	LPSTR pText;

	if (pnhm->code == TTN_NEEDTEXT)
	{
		LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParams;
		switch (lpttt->hdr.idFrom)
		{
		case ID_TOOL_POINT:
			pText = (LPSTR)"Точка";
			break;
		case ID_TOOL_LINE:
			pText = (LPSTR)"Лінія";
			break;
		case ID_TOOL_RECT:
			pText = (LPSTR)"Прямокутник";
			break;
		case ID_TOOL_RECTFILL:
			pText = (LPSTR)"Прямокутник iз заповненням";
			break;
		case ID_TOOL_ELLIPSE:
			pText = (LPSTR)"Еліпс";
			break;
		case ID_TOOL_ELLIPSEFILL:
			pText = (LPSTR)"Еліпс iз заповненням";
			break;
		case ID_TOOL_CUBE:
			pText = (LPSTR)"Куб";
			break;
		case ID_TOOL_OLINEO:
			pText = (LPSTR)"Лінія з кружечками";
			break;
		default: pText = (LPSTR)"Щось невідоме";
		}
		lstrcpy(lpttt->szText, pText);
	}
}

