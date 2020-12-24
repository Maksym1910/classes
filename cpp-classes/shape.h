#pragma once
class Shape { 
protected:    
	long xs1, ys1, xs2, ys2; 
	COLORREF color;
	BOOL isFill;
public:   
	~Shape();
	void Set(long, long, long, long); 
	void SetColor(COLORREF);
	void SetFill(BOOL);
	virtual void Show(HDC, bool) = 0;
	virtual Shape* Copy() = 0;
	virtual int Popup() = 0;
};
 