#ifndef AA_GRAPHICS_OBJECT
#define AA_GRAPHICS_OBJECT

#include "UseGDI.h"
#include "../../game/header/Resource.h"
#include "GraphicsObjects.h"

#define GRAPHICS_RECT_TL   0
#define GRAPHICS_RECT_TR   1
#define GRAPHICS_RECT_BL   2
#define GRAPHICS_RECT_BR   3

#define GRAPHICS_TEXTLEN   128

class AAGraphicsObject
{
public:
	AAGraphicsObject(int);
	virtual ~AAGraphicsObject();

	virtual void configBaseDrawTools(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, SolidBrush*, SolidBrush*, SolidBrush* = NULL);
	virtual void configObject(Graphics* graphics, int, int, RectF&, const char*, framesList*);

	virtual void drawObject(Graphics*, bool, bool, int);
	virtual void hideObject(Graphics*, int&);

	virtual int getObjectId();
	virtual int getObjectScreen();
	virtual int getObjectSection();

	virtual bool   isPointInBox(int, int);
	virtual PointF getRectCorner(int);

protected:

	int   objId;
	int   objScr;
	int   objSect;
	RectF objBox;

	WCHAR objText[GRAPHICS_TEXTLEN];

	int intersections;

	// Graphics
	Pen* borderPen, * borderlessPen;
	FontFamily* fontFamily;
	StringFormat* textFormat, * centerFormat;
	Font* baseTextFont;
	SolidBrush* textBrush;
	SolidBrush* backBrush;
	SolidBrush* popupBrush;

	Pen* pen;

};

#endif