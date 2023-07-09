#include "../header/GraphicsObjects.h"

AALine::AALine()
{
	layer = 0;

	vert = false;
	horz = false;
	dot  = false;
}

AALine::~AALine()
{

}

void AALine::config()
{
	if (pt0.X == pt1.X)
		vert = true;
	else
		vert = false;

	if (pt0.Y == pt1.Y)
		horz = true;
	else
		horz = false;

	if (vert && horz)
		dot = true;
	else
		dot = false;
}

void AALine::config(PointF s, PointF e, int l)
{
	pt0 = s;
	pt1 = e;
	layer = l;

	config();
}

void AALine::nudge(REAL n)
{
	if (vert)
	{
		pt0.Y += n;
		pt1.Y += n;
	}

	if (horz)
	{
		pt0.X += n;
		pt1.X += n;
	}
}

void AALine::shrink(REAL n)
{
	if (vert)
	{
		pt0.Y += n;
		pt1.Y -= n;
	}

	if (horz)
	{
		pt0.X += n;
		pt1.X -= n;
	}
}

void AALine::contract(REAL n0, REAL n1)
{
	if (vert)
	{
		pt0.Y -= n0;
		pt1.Y -= n1;
	}

	if (horz)
	{
		pt0.X -= n0;
		pt1.X -= n1;
	}
}

void AALine::rotateClock90(PointF ref)
{
	REAL angle = 90;
	REAL theta = 2 * M_PI * angle / 360;

	REAL s = sin(theta);
	REAL c = cos(theta);

	pt0.X -= ref.X;
	pt0.Y -= ref.Y;

	REAL xNew = pt0.X * c - pt0.Y * s;
	REAL yNew = pt0.X * s + pt0.Y * c;

	pt0.X = xNew + ref.X;
	pt0.Y = yNew + ref.Y;

	pt1.X -= ref.X;
	pt1.Y -= ref.Y;

	xNew = pt1.X * c - pt1.Y * s;
	yNew = pt1.X * s + pt1.Y * c;

	pt1.X = xNew + ref.X;
	pt1.Y = yNew + ref.Y;

	config();
}


void AALine::drawLine(Graphics* graphics, Pen* p0, int layers)
{
	if (layer <= layers)
	{
		graphics->DrawLine(p0, pt0, pt1);
	}
}

AARect::AARect()
{
	layer = 0;
}

AARect::~AARect()
{

}

void AARect::config(RectF r, int l)
{
	box = r;
	layer = l;
}

void AARect::drawRect(Graphics* graphics, Brush* b0, int layers)
{
	if (layer <= layers)
	{
		graphics->FillRectangle(b0, box);
	}
}


AABox::AABox()
{
	layer = 0;

	for (int i = 0; i < DEFAULT_TEXTLEN; i++)
		defaultText[i] = '\0';
}

AABox::AABox(const char* def)
{
	layer = 0;

	for (int i = 0; i < DEFAULT_TEXTLEN; i++)
		defaultText[i] = '\0';
	for (int i = 0; i < strlen(def); i++)
		defaultText[i] = def[i];
}

AABox::~AABox()
{

}

void AABox::config(RectF r, int l)
{
	box = r;
	layer = l;
}

void AABox::nudge(int x, int y)
{
	box.X += x;
	box.Y += y;
}

void AABox::shrink(int n)
{
	box.X += n;
	box.Y += n;
	box.Width -= 2 * n;
	box.Height -= 2 * n;
}

void AABox::shrinkX(int n)
{
	box.X += n;
	box.Width -= 2 * n;
}

void AABox::shrinkY(int n)
{
	box.Y += n;
	box.Height -= 2 * n;
}

void AABox::contract(int n)
{
	box.Width -= n;
	box.Height -= n;
}

void AABox::contract(int x, int y)
{
	box.Width -= x;
	box.Height -= y;
}

void AABox::expand(int x, int y)
{
	box.Width += x;
	box.Height += y;
}

void AABox::transpose()
{
	REAL w = box.Width;
	REAL h = box.Height;

	box.Width = h;
	box.Height = w;
}

void AABox::rotateClock90(PointF ref)
{
	REAL angle = 90;
	REAL theta = 2 * M_PI * angle / 360;

	REAL s = sin(theta);
	REAL c = cos(theta);

	box.X -= ref.X;
	box.Y -= ref.Y;

	REAL xNew = box.X * c - box.Y * s;
	REAL yNew = box.X * s + box.Y * c;

	box.X = xNew + ref.X;
	box.Y = yNew + ref.Y;

	REAL w = box.Width;
	REAL h = box.Height;

	box.Width = h;
	box.Height = w;

	box.X -= box.Width;
}

void AABox::drawFrame(Graphics* graphics, Pen* pen, Font* font, StringFormat* sf, Brush* b0, int layers)
{
	if (layer <= layers)
	{
		graphics->DrawRectangle(pen, box);
		graphics->DrawString(defaultText, -1, font, box, sf, b0);
	}
}

void AABox::drawFrameFill(Graphics* graphics, Pen* pen, Font* font, StringFormat* sf, Brush* b0, Brush* b1, int layers)
{
	if (layer <= layers)
	{
		graphics->FillRectangle(b1, box);
		graphics->DrawRectangle(pen, box);
		graphics->DrawString(defaultText, -1, font, box, sf, b0);
	}
}

void AABox::drawBox(Graphics* graphics, Pen* pen, Font* font, StringFormat* sf, Brush* b0, Brush* b1, const WCHAR* str, int layers, int angle)
{
	if (layer <= layers)
	{
		graphics->FillRectangle(b1, box);
		graphics->DrawRectangle(pen, box);

		if (angle != 0)
		{
			RectF tmpBox = box;

			//Offset the coordinate system so that point (0, 0) is at the center of the desired area.
			graphics->TranslateTransform(box.X + box.Width / 2, box.Y + box.Height / 2);

			//Rotate the Graphics object.
			graphics->RotateTransform(angle);

			//Offset the Drawstring method so that the center of the string matches the center.
			box.X = -box.Width / 2;
			box.Y = -box.Height / 2;
			graphics->DrawString(str, -1, font, box, sf, b0);

			//Reset the graphics object Transformations.
			graphics->ResetTransform();

			box = tmpBox;
		}
		else
			graphics->DrawString(str, -1, font, box, sf, b0);
	}
}

AATri::AATri()
{
	layer = 0;

	for (int i = 0; i < DEFAULT_TEXTLEN; i++)
		defaultText[i] = '\0';
}

AATri::~AATri()
{

}

void AATri::config(PointF p0, PointF p1, PointF p2, int l)
{
	tri[0] = p0;
	tri[1] = p1;
	tri[2] = p2;
	layer = l;
}

void AATri::drawTri(Graphics* graphics, Pen* pen, Brush* b0, int layers)
{
	if (layer <= layers)
	{
		graphics->FillPolygon(b0, tri, 3);
		graphics->DrawPolygon(pen, tri, 3);
	}
}

AAQuad::AAQuad()
{
	layer = 0;

	for (int i = 0; i < DEFAULT_TEXTLEN; i++)
		defaultText[i] = '\0';
}

AAQuad::~AAQuad()
{

}

void AAQuad::config(PointF p0, PointF p1, PointF p2, PointF p3, int l)
{
	quad[0] = p0;
	quad[1] = p1;
	quad[2] = p2;
	quad[3] = p3;
	layer = l;
}

void AAQuad::drawQuad(Graphics* graphics, Pen* pen, Brush* b0, int layers)
{
	if (layer <= layers)
	{
		graphics->FillPolygon(b0, quad, 4);
		graphics->DrawPolygon(pen, quad, 4);
	}
}

AABox6::AABox6(const char* def)
	:AABox(def)
{
	layer = 0;
}

AABox6::~AABox6()
{

}

void AABox6::config(PointF p0, PointF p1, PointF p2, PointF p3, PointF p4, PointF p5, RectF& b0, RectF& b1, int l)
{
	box6[0] = p0;
	box6[1] = p1;
	box6[2] = p2;
	box6[3] = p3;
	box6[4] = p4;
	box6[5] = p5;

	box0 = b0;
	box1 = b1;

	layer = l;
}

void AABox6::drawBox6(Graphics* graphics, Pen* pen, Font* font, StringFormat* sf, Brush* b0, Brush* b1, int layers, bool rects)
{
	if (layer <= layers)
	{
		graphics->FillPolygon(b1, box6, 6);
		graphics->DrawPolygon(pen, box6, 6);

		if (rects)
		{
			graphics->FillRectangle(b1, box0);
			graphics->FillRectangle(b1, box1);
			graphics->DrawRectangle(pen, box0);
			graphics->DrawRectangle(pen, box1);
			graphics->DrawString(defaultText, -1, font, box0, sf, b0);
			graphics->DrawString(defaultText, -1, font, box1, sf, b0);
		}
	}
}