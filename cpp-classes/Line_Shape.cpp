#include "stdafx.h"
#include "Line_Shape.h"

void LineShape::Show(HDC hdc, bool isDash) {
	HPEN hPen, hPenOld;

	if (isDash) {
		hPen = CreatePen(PS_DOT, 1, RGB(0,0,0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);
	}
	else {
		hPen = CreatePen(PS_SOLID, 1, color);
		hPenOld = (HPEN)SelectObject(hdc, hPen);
	}

	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs2, ys2);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

Shape* LineShape::Copy() {
	return new LineShape();
}

int LineShape::Popup() {
	return 1;
}