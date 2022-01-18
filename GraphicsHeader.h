#include "framework.h"
#include "UseGDI.h"

#include "LogText.h"

#ifndef AA_GRAPHICS
#define AA_GRAPHICS

#define FONT12_S        12
#define FONT14_S        14
#define FONT16_S        16
#define FONT17_S        17
#define FONT18_S        18
#define FONT20_S        20
#define FONT24_S        24
#define FONT28_S        28
#define FONT32_S        32
#define FONT64_S        64

#define TURNFONT_S      16
#define TEXTFONT_S      12

#define NAMEFONT_S      65

#define DEFAULT_TEXTLEN 20
#define PURCH_TEXTLEN   64

#define BOX_LEFT        0
#define BOX_RIGHT       1
#define BOX_TOP         2
#define BOX_BOTTOM      3
#define BOX_WIDTH       4
#define BOX_HEIGHT      5

class AAGraphics
{
public:
	AAGraphics();
	~AAGraphics();

	void config(HDC&);

	///////////////////////////////////////////////////////////////////////////
	//// Pens
	///////////////////////////////////////////////////////////////////////////

	Pen* borderlessPen;
	Pen* blackPen1, * blackPen2, * blackPen4;
	Pen* backPen;

	///////////////////////////////////////////////////////////////////////////
	//// Fonts
	///////////////////////////////////////////////////////////////////////////

	FontFamily* calibriFamily;

	// Formats
	StringFormat* logTextFormat, * leftCenterFormat, * centerFormat,
		* leftTopFormat, * purchaseFormat;

	// Fonts
	Font* font12, * font12_b;
	Font* font14, * font14_b;
	Font* font16, * font16_b;
	Font* font17;
	Font* font18, * font18_b;
	Font* font20, * font20_b;
	Font* font24, * font24_b;
	Font* font28;
	Font* font32;
	Font* font64_b;

	///////////////////////////////////////////////////////////////////////////
	//// Brushes
	///////////////////////////////////////////////////////////////////////////

	SolidBrush* textBrush, * paneBrush, * backBrush;
	SolidBrush* tileBrushL, * tileBrushD;
	SolidBrush* whiteBrush, * redBrush;
	SolidBrush* clearBrush;

	// Turn phase brushes
	SolidBrush* resBrushP, * purchBrushP, * cmBrushP,
		* ccBrushP, * ncBrushP, * mobBrushP, * incBrushP;
	SolidBrush* resBrushS, * purchBrushS, * cmBrushS,
		* ccBrushS, * ncBrushS, * mobBrushS, * incBrushS;

	// Nation brushes
	SolidBrush* gerBrushP, * gerBrushS, * gerBrushF,
		* sovBrushP, * sovBrushS, * sovBrushF,
		* jpnBrushP, * jpnBrushS, * jpnBrushF,
		* usaBrushP, * usaBrushS, * usaBrushF,
		* chnBrushP, * chnBrushS, * chnBrushF,
		* ukBrushP, * ukBrushS, * ukBrushF,
		* itaBrushP, * itaBrushS, * itaBrushF,
		* anzBrushP, * anzBrushS, * anzBrushF,
		* fraBrushP, * fraBrushS, * fraBrushF;

};

class AABox
{
public:
	AABox();
	AABox(const char*);
	~AABox();

	void config(RectF, int);

	void drawFrame(Graphics*, Pen*, Font*, StringFormat*, Brush*, Brush*, int);
	void drawBox(Graphics*, Pen*, Font*, StringFormat*, Brush*, Brush*, const WCHAR*, int);

	RectF box;
	int layer;

	WCHAR defaultText[DEFAULT_TEXTLEN];
	
};

class AATri : public AABox
{
public:
	AATri();
	~AATri();

	void config(PointF, PointF, PointF, int);

	void drawTri(Graphics*, Pen*, Brush*, int);

	PointF tri[3];

};

class AAQuad : public AABox
{
public:
	AAQuad();
	~AAQuad();

	void config(PointF, PointF, PointF, PointF, int);

	void drawQuad(Graphics*, Pen*, Brush*, int);

	PointF quad[4];
};

class AABox6 : public AABox
{
public:
	AABox6(const char*);
	~AABox6();

	void config(PointF, PointF, PointF, PointF, PointF, PointF, RectF&, RectF&, int);

	void drawBox6(Graphics*, Pen*, Font*, StringFormat*, Brush*, Brush*, int, bool = false);

	PointF box6[6];
	RectF  box0;
	RectF  box1;

};

#endif // !AA_GRAPHICS