#ifndef AA_GRAPHICS_OBJECTS
#define AA_GRAPHICS_OBJECTS

#include "../../game/header/framework.h"
#include "UseGDI.h"

#define DEFAULT_TEXTLEN 20
#define PURCH_TEXTLEN   64

#define BOX_LEFT        0
#define BOX_RIGHT       1
#define BOX_TOP         2
#define BOX_BOTTOM      3
#define BOX_WIDTH       4
#define BOX_HEIGHT      5

struct screenFrames {
	vector<RectF> f;
	vector<int> b;
};

struct framesList {
	vector<screenFrames> s;
};

class AALine
{
public:
	AALine();
	~AALine();

	void config();
	void config(PointF, PointF, int);
	void nudge(REAL);
	void shrink(REAL);
	void contract(REAL, REAL);

	void rotateClock90(PointF);

	void drawLine(Graphics*, Pen*, int);

	PointF pt0, pt1;
	int layer;

private:
	bool vert, horz;
	bool dot;

};

class AARect
{
public:
	AARect();
	~AARect();

	void config(RectF, int);

	void drawRect(Graphics*, Brush*, int);

	RectF box;
	int layer;

};

class AABox
{
public:
	AABox();
	AABox(const char*);
	~AABox();

	void config(RectF, int);
	void nudge(int, int);
	void shrink(int);
	void shrinkX(int);
	void shrinkY(int);
	void contract(int);
	void contract(int, int);
	void expand(int, int);

	void transpose();
	void rotateClock90(PointF);

	void drawFrame(Graphics*, Pen*, Font*, StringFormat*, Brush*, int);
	void drawFrameFill(Graphics*, Pen*, Font*, StringFormat*, Brush*, Brush*, int);
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

#endif // !AA_GRAPHICS_OBJECTS