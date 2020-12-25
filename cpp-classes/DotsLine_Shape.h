#pragma once
#include "Line_Shape.h"
#include "Ellipse_Shape.h"

class OLineOShape : public LineShape, public EllipseShape {
public:
	void Show(HDC, bool);
	Shape* Copy();
	int Popup();

};
