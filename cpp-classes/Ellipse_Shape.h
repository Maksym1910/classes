#pragma once
#include "shape.h"

class EllipseShape : public virtual Shape
{
public:
	virtual void Show(HDC, bool);
	virtual Shape* Copy();
	virtual int Popup();
};
