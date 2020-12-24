#include "stdafx.h"
#include "Cube_Shape.h"

void CubeShape::Show(HDC hdc, bool isDash) {
	long x1, x2, y1, y2;
	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	RectShape::Set(x1 - 75, y1 - 75, x1 + 75, y1 + 75);
	RectShape::Show(hdc, isDash);

	RectShape::Set(x2 - 75, y2 - 75, x2 + 75, y2 + 75);
	RectShape::Show(hdc, isDash);

	LineShape::Set(x1 - 75, y1 - 75, x2 - 75, y2 - 75);
	LineShape::Show(hdc, isDash);

	LineShape::Set(x1 - 75, y1 + 75, x2 - 75, y2 + 75);
	LineShape::Show(hdc, isDash);

	LineShape::Set(x1 + 75, y1 + 75, x2 + 75, y2 + 75);
	LineShape::Show(hdc, isDash);

	LineShape::Set(x1 + 75, y1 - 75, x2 + 75, y2 - 75);
	LineShape::Show(hdc, isDash);

	LineShape::Set(x1, y1, x2, y2);
}

Shape* CubeShape::Copy() {
	return new CubeShape();
}

int CubeShape::Popup() {
	return 4;
}