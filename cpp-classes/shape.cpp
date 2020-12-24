#include "stdafx.h"
#include "shape.h"

Shape::~Shape() {};

void Shape::Set(long x1, long y1, long x2, long y2)
{
	xs1 = x1;
	ys1 = y1;
	xs2 = x2;
	ys2 = y2;
}

void Shape::SetColor(COLORREF newColor) {
	color = newColor;
}

void Shape::SetFill(BOOL isF) {
	isFill = isF;
}

