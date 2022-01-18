#include "../header/DebugGrid.h"

DebugGrid::DebugGrid(RectF& r0, int l, Pen* p0, Pen* p1, Pen* p2)
{
	layer = l;
	rect = r0;
	
	pen1 = p0;
	pen2 = p1;
	pen4 = p2;

	setupGrid();
}

DebugGrid::~DebugGrid()
{

}

void DebugGrid::setupGrid()
{
	// Horizontal
	_12_5h0 = { rect.X, rect.Height / 8 };
	_12_5h1 = { rect.GetRight(), rect.Height / 8 };
	_20h0 = { rect.X, rect.Height / 5 };
	_20h1 = { rect.GetRight(), rect.Height / 5 };
	_25h0 = { rect.X, rect.Height / 4 };
	_25h1 = { rect.GetRight(), rect.Height / 4 };
	_33h0 = { rect.X, rect.Height / 3 };
	_33h1 = { rect.GetRight(), rect.Height / 3 };
	_37_5h0 = { rect.X, 3 * rect.Height / 8 };
	_37_5h1 = { rect.GetRight(), 3 * rect.Height / 8 };
	_40h0 = { rect.X, 2 * rect.Height / 5 };
	_40h1 = { rect.GetRight(), 2 * rect.Height / 5 };
	_50h0 = { rect.X, rect.Height / 2 };
	_50h1 = { rect.GetRight(), rect.Height / 2 };
	_60h0 = { rect.X, 3 * rect.Height / 5 };
	_60h1 = { rect.GetRight(), 3 * rect.Height / 5 };
	_62_5h0 = { rect.X, 5 * rect.Height / 8 };
	_62_5h1 = { rect.GetRight(), 5 * rect.Height / 8 };
	_66h0 = { rect.X, 2 * rect.Height / 3 };
	_66h1 = { rect.GetRight(), 2 * rect.Height / 3 };
	_75h0 = { rect.X, 3 * rect.Height / 4 };
	_75h1 = { rect.GetRight(), 3 * rect.Height / 4 };
	_80h0 = { rect.X, 4 * rect.Height / 5 };
	_80h1 = { rect.GetRight(), 4 * rect.Height / 5 };
	_87_5h0 = { rect.X, 7 * rect.Height / 8 };
	_87_5h1 = { rect.GetRight(), 7 * rect.Height / 8 };

	// Vertical
	_12_5v0 = { rect.Width / 8, rect.Y };
	_12_5v1 = { rect.Width / 8, rect.GetBottom() };
	_20v0 = { rect.Width / 5, rect.Y };
	_20v1 = { rect.Width / 5, rect.GetBottom() };
	_25v0 = { rect.Width / 4, rect.Y };
	_25v1 = { rect.Width / 4, rect.GetBottom() };
	_33v0 = { rect.Width / 3, rect.Y };
	_33v1 = { rect.Width / 3, rect.GetBottom() };
	_37_5v0 = { 3 * rect.Width / 8, rect.Y };
	_37_5v1 = { 3 * rect.Width / 8, rect.GetBottom() };
	_40v0 = { 2 * rect.Width / 5, rect.Y };
	_40v1 = { 2 * rect.Width / 5, rect.GetBottom() };
	_50v0 = { rect.Width / 2, rect.Y };
	_50v1 = { rect.Width / 2, rect.GetBottom() };
	_60v0 = { 3 * rect.Width / 5, rect.Y };
	_60v1 = { 3 * rect.Width / 5, rect.GetBottom() };
	_62_5v0 = { 5 * rect.Width / 8, rect.Y };
	_62_5v1 = { 5 * rect.Width / 8, rect.GetBottom() };
	_66v0 = { 2 * rect.Width / 3, rect.Y };
	_66v1 = { 2 * rect.Width / 3, rect.GetBottom() };
	_75v0 = { 3 * rect.Width / 4, rect.Y };
	_75v1 = { 3 * rect.Width / 4, rect.GetBottom() };
	_80v0 = { 4 * rect.Width / 5, rect.Y };
	_80v1 = { 4 * rect.Width / 5, rect.GetBottom() };
	_87_5v0 = { 7 * rect.Width / 8, rect.Y };
	_87_5v1 = { 7 * rect.Width / 8, rect.GetBottom() };
}

void DebugGrid::drawGrid(Graphics* graphics, int gridDiv)
{
	switch (gridDiv)
	{
	case 2:
	{
		graphics->DrawLine(pen1, _50h0, _50h1);
		graphics->DrawLine(pen1, _50v0, _50v1);
		break;
	}
	case 3:
	{
		graphics->DrawLine(pen1, _33h0, _33h1);
		graphics->DrawLine(pen1, _66h0, _66h1);

		graphics->DrawLine(pen1, _33v0, _33v1);
		graphics->DrawLine(pen1, _66v0, _66v1);
		break;
	}
	case 4:
	{
		graphics->DrawLine(pen1, _25h0, _25h1);
		graphics->DrawLine(pen2, _50h0, _50h1);
		graphics->DrawLine(pen1, _75h0, _75h1);

		graphics->DrawLine(pen1, _25v0, _25v1);
		graphics->DrawLine(pen2, _50v0, _50v1);
		graphics->DrawLine(pen1, _75v0, _75v1);
		break;
	}
	case 5:
	{
		graphics->DrawLine(pen1, _20h0, _20h1);
		graphics->DrawLine(pen1, _40h0, _40h1);
		graphics->DrawLine(pen1, _60h0, _60h1);
		graphics->DrawLine(pen1, _80h0, _80h1);

		graphics->DrawLine(pen1, _20v0, _20v1);
		graphics->DrawLine(pen1, _40v0, _40v1);
		graphics->DrawLine(pen1, _60v0, _60v1);
		graphics->DrawLine(pen1, _80v0, _80v1);
		break;
	}
	case 8:
	{
		graphics->DrawLine(pen1, _12_5h0, _12_5h1);
		graphics->DrawLine(pen2, _25h0, _25h1);
		graphics->DrawLine(pen1, _37_5h0, _37_5h1);
		graphics->DrawLine(pen4, _50h0, _50h1);
		graphics->DrawLine(pen1, _62_5h0, _62_5h1);
		graphics->DrawLine(pen2, _75h0, _75h1);
		graphics->DrawLine(pen1, _87_5h0, _87_5h1);

		graphics->DrawLine(pen1, _12_5v0, _12_5v1);
		graphics->DrawLine(pen2, _25v0, _25v1);
		graphics->DrawLine(pen1, _37_5v0, _37_5v1);
		graphics->DrawLine(pen4, _50v0, _50v1);
		graphics->DrawLine(pen1, _62_5v0, _62_5v1);
		graphics->DrawLine(pen2, _75v0, _75v1);
		graphics->DrawLine(pen1, _87_5v0, _87_5v1);
		break;
	}
	default:
		break;
	}


}
