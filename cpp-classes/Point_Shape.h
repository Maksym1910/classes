#include "shape.h"

class PointShape : public Shape
{
	void Show(HDC, bool);
	Shape* Copy();
	int Popup();
};