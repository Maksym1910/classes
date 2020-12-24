#include "shape.h"
#include "my_editor_resource.h"

class MyEditor {
protected:
	int x1, y1, x2, y2;
public:
	~MyEditor();
	void Start(Shape *);
	void OnLBdown(HWND);
	void OnLBup(HWND, COLORREF, BOOL);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};


