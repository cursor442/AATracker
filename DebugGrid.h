#ifndef DBG_GRID
#define DBG_GRID

#include "Section.h"

class DebugGrid
{
public:
	DebugGrid(RectF&, int, Pen*, Pen*, Pen*);
	~DebugGrid();

	void drawGrid(Graphics*, int);

private:
	int layer;
	RectF rect;

	/// Grid lines
	void setupGrid();
	// Horizontal
	PointF _12_5h0, _12_5h1;
	PointF _20h0, _20h1;
	PointF _25h0, _25h1;
	PointF _33h0, _33h1;
	PointF _37_5h0, _37_5h1;
	PointF _40h0, _40h1;
	PointF _50h0, _50h1;
	PointF _60h0, _60h1;
	PointF _62_5h0, _62_5h1;
	PointF _66h0, _66h1;
	PointF _75h0, _75h1;
	PointF _80h0, _80h1;
	PointF _87_5h0, _87_5h1;

	// Vertical
	PointF _12_5v0, _12_5v1;
	PointF _20v0, _20v1;
	PointF _25v0, _25v1;
	PointF _33v0, _33v1;
	PointF _37_5v0, _37_5v1;
	PointF _40v0, _40v1;
	PointF _50v0, _50v1;
	PointF _60v0, _60v1;
	PointF _62_5v0, _62_5v1;
	PointF _66v0, _66v1;
	PointF _75v0, _75v1;
	PointF _80v0, _80v1;
	PointF _87_5v0, _87_5v1;

	// Graphics
	Pen* pen1, * pen2, * pen4;
};

#endif
