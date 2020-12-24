#include "stdafx.h"
#include "my_editor.h"

static int count = 0;
static bool isPressed = false;
static const int MY_SHAPE_ARRAY_SIZE = 106;
static Shape **pcshape = new Shape*[MY_SHAPE_ARRAY_SIZE];


MyEditor::~MyEditor() {
	for (int i = 0; i < count; i++) delete pcshape[i];
	delete pcshape;
}

void MyEditor::Start(Shape *shape) {
	pcshape[count] = shape;
}

void MyEditor::OnLBdown(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x1 = x2 = pt.x;
	y1 = y2 = pt.y;
	isPressed = true;
}

void MyEditor::OnLBup(HWND hWnd, COLORREF color, BOOL isF) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	x2 = pt.x;
	y2 = pt.y;
	isPressed = false;
	pcshape[count]->Set(x1, y1, x2, y2);
	pcshape[count]->SetColor(color);
	pcshape[count]->SetFill(isF);
	count++;
	InvalidateRect(hWnd, NULL, TRUE);
	pcshape[count] = pcshape[count-1]->Copy();
}

void MyEditor::OnMouseMove(HWND hWnd) {
	if (isPressed) {
		POINT pt;
		HDC hdc = GetDC(hWnd);

		SetROP2(hdc, R2_NOTXORPEN);

		MoveToEx(hdc, x1, y1, NULL);
		pcshape[count]->Set(x1, y1, x2, y2);
		pcshape[count]->Show(hdc, 1);

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		x2 = pt.x;
		y2 = pt.y;

		MoveToEx(hdc, x1, y1, NULL);
		pcshape[count]->Set(x1, y1, x2, y2);
		pcshape[count]->Show(hdc, 1);

		ReleaseDC(hWnd, hdc);
	}
}

void MyEditor::OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < count; i++) {
		if (pcshape[i]) pcshape[i]->Show(hdc, 0);
	}
	EndPaint(hWnd, &ps);
}

void MyEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParams) {
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParams == hSubMenu) {
		CheckMenuItem(hSubMenu, IDM_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_RECTANGLE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, IDM_CUBE, MF_UNCHECKED);
		int smth = pcshape[count]->Popup();
		switch (smth) {
		case 0:
			CheckMenuItem(hSubMenu, IDM_POINT, MF_CHECKED);
			break;
		case 1:
			CheckMenuItem(hSubMenu, IDM_LINE, MF_CHECKED);
			break;
		case 2:
			CheckMenuItem(hSubMenu, IDM_RECTANGLE, MF_CHECKED);
			break;
		case 3:
			CheckMenuItem(hSubMenu, IDM_ELLIPSE, MF_CHECKED);
			break;
		case 4: 
			CheckMenuItem(hSubMenu, IDM_CUBE, MF_CHECKED);
			break;
		case 5:
			CheckMenuItem(hSubMenu, IDM_OLINEO, MF_CHECKED);
			break;
		}
	}

}
