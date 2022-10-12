#ifndef AA_TOOLTIP
#define AA_TOOLTIP

#define TT_RECT_TL   0
#define TT_RECT_TR   1
#define TT_RECT_BL   2
#define TT_RECT_BR   3

#define TT_DIR_NULL -1
#define TT_DIR_LEFT  0
#define TT_DIR_RIGHT 1
#define TT_DIR_UP    2
#define TT_DIR_DOWN  3

#define TT_TEXTLEN   128

#define TT_TRI_SIZE  6

#include "UseGDI.h"
#include "../../game/header/Resource.h"
#include "GraphicsObjects.h"

struct screenFrames {
	vector<RectF> f;
	vector<int> b;
};

struct framesList {
	vector<screenFrames> s;
};

class AATooltip
{
public:
	AATooltip(int);
	~AATooltip();

	void configBaseDrawTools(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	void configTooltip(Graphics* graphics, int, RectF&, int, const char*, framesList*);

	void drawTooltip(Graphics*, bool, bool, int);
	void hideTooltip(Graphics*, int&);

	int getTooltipId();

	bool   isPointInBox(int, int);
	PointF getRectCorner(int);

private:

	int   ttId;
	int   ttScr;
	RectF ttBox;
	int   ttDir;

	AABox* ttTextBox;
	AATri* ttTriBox;
	AABox* ttBlankBox;

	WCHAR ttText[TT_TEXTLEN];

	int intersections;

	void config(Graphics*, const char*, framesList*);

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