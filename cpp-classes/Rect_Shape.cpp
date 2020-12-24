#include "stdafx.h"
#include "Rect_Shape.h"

void RectShape::Show(HDC hdc, bool isDash) {
	HPEN hPen, hPenOld;
	HBRUSH hBrush, hBrushOld;

	if (isDash) {
		hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
		hPenOld = (HPEN)SelectObject(hdc, hPen);

		MoveToEx(hdc, xs1, ys1, NULL);
		LineTo(hdc, xs1, ys2);
		LineTo(hdc, xs2, ys2);
		LineTo(hdc, xs2, ys1);
		LineTo(hdc, xs1, ys1);
	}
	else
	{
		hPen = CreatePen(PS_SOLID, 1, color);
		hPenOld = (HPEN)SelectObject(hdc, hPen);

		if (isFill) {
			hBrush = CreateSolidBrush(color);
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
			SelectObject(hdc, hBrush);
			Rectangle(hdc, xs1, ys1, xs2, ys2);
			SelectObject(hdc, hBrushOld);
			DeleteObject(hBrush);
		}
		else {
			MoveToEx(hdc, xs1, ys1, NULL);
			LineTo(hdc, xs1, ys2);
			LineTo(hdc, xs2, ys2);
			LineTo(hdc, xs2, ys1);
			LineTo(hdc, xs1, ys1);
		}
	}


	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

Shape* RectShape::Copy() {
	return new RectShape();
}

int RectShape::Popup() {
	return 2;
}