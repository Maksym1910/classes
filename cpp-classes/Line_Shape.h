#include "shape.h"
#pragma once

class LineShape : public virtual Shape
{
public:
	virtual void Show(HDC, bool);
	virtual Shape* Copy();
	virtual int Popup();
};