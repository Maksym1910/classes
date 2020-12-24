#include "stdafx.h"
#include "Point_Shape.h"

void PointShape::Show(HDC hdc, bool isDash) {
	SetPixel(hdc, xs1, ys1, color);
	SetPixel(hdc, xs1 + 1, ys1, color);
	SetPixel(hdc, xs1 - 1, ys1, color);
	SetPixel(hdc, xs1, ys1 + 1, color);
	SetPixel(hdc, xs1, ys1 - 1, color);
}

Shape *PointShape::Copy() {
	return new PointShape();
}

int PointShape::Popup() {
	return 0;
}