#ifndef AA_BUTTON
#define AA_BUTTON

#define BB_UP false
#define BB_DN true

#define BB_TOP_LINES      3
#define BB_LEFT_LINES     3
#define BB_BOT_LINES      4
#define BB_RIGHT_LINES    5

#include "AAGraphicsObject.h"

class AAButton : public AAGraphicsObject
{
public:
	AAButton(int);
	~AAButton();

	void configButton(Graphics* graphics, int, RectF&, const char*, framesList*);
	void configDrawTools(vector<Color*>&, vector<SolidBrush*>&, SolidBrush*, Font*);

	void drawButton(Graphics*, HDC&, bool, bool, int);
	void hideButton(Graphics*, int&);

	bool pressButton();
	bool releaseButton();

	int  getButtonId();

private:

	bool bbState;

	AABox* bbTextBox;
	AABox* bbBlankBox;

	void config(Graphics*, const char*, framesList*);

	HDC hdcCompat;
	HBITMAP* tmpBitmap, * tmpBitmapMask;
	Bitmap* bbBitmap;

	SolidBrush* bbCenterBrush;
	SolidBrush* clearBrush;

	Font* buttonFont;

	Color* bbTopColor[BB_TOP_LINES];
	Color* bbBotColor[BB_BOT_LINES];
	Color* bbLeftColor[BB_LEFT_LINES];
	Color* bbRightColor[BB_RIGHT_LINES];

	HBITMAP CreateBitmapMask(HBITMAP, COLORREF);

};

#endif