#include "../header/AAGraphicsObject.h"

AAGraphicsObject::AAGraphicsObject(int id)
{
	objId = id;
	objScr = SCREEN_NONE;
	objBox = { 0, 0, 0, 0 };

	borderPen = NULL;
	borderlessPen = NULL;
	fontFamily = NULL;
	textFormat = NULL;
	centerFormat = NULL;
	baseTextFont = NULL;
	textBrush = NULL;
	backBrush = NULL;
	popupBrush = NULL;

	pen = NULL;

	for (int i = 0; i < GRAPHICS_TEXTLEN; i++)
		objText[i] = '\0';

	intersections = NO_SECT;
}

AAGraphicsObject::~AAGraphicsObject()
{
	
}

void AAGraphicsObject::configBaseDrawTools(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
{
	borderPen = p0;
	borderlessPen = p1;

	fontFamily = ff;
	textFormat = sf0;
	centerFormat = sf1;
	baseTextFont = f0;

	textBrush = b0;
	backBrush = b1;
	popupBrush = b2;
}

void AAGraphicsObject::configObject(Graphics* graphics, int screen, RectF& rect, const char* text, framesList* frames)
{
	objScr = screen;
	objBox = rect;
}

void AAGraphicsObject::drawObject(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;
}

void AAGraphicsObject::hideObject(Graphics* graphics, int& sect)
{
	sect = intersections;
}

int AAGraphicsObject::getObjectId()
{
	return objId;
}


bool AAGraphicsObject::isPointInBox(int xPos, int yPos)
{
	PointF point = PointF((REAL)xPos, (REAL)yPos);

	if (objBox.Contains(point))
		return true;
	else
		return false;
}

PointF AAGraphicsObject::getRectCorner(int corner)
{
	switch (corner)
	{
	case GRAPHICS_RECT_TL:
		return { objBox.X, objBox.Y };
		break;
	case GRAPHICS_RECT_TR:
		return { objBox.GetRight(), objBox.Y };
		break;
	case GRAPHICS_RECT_BL:
		return { objBox.X, objBox.GetBottom() };
		break;
	case GRAPHICS_RECT_BR:
		return { objBox.GetRight(), objBox.GetBottom() };
		break;
	default:
		return { 0, 0 };

	}
}
