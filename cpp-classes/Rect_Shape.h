#include "shape.h"
#pragma once

class RectShape : public virtual Shape
{
public:
	virtual void Show(HDC, bool);
	virtual Shape* Copy();
	virtual int Popup();
};