#ifndef AA_BUTTON
#define AA_BUTTON

#define BB_UP false
#define BB_DN true

#define BB_UP_LAYERS 5
#define BB_DN_LAYERS 2

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

	AABox* bbUpBox[BB_UP_LAYERS];
	AABox* bbDnBox[BB_DN_LAYERS];
	AABox* bbUpTextBox;
	AABox* bbDnTextBox;
	AABox* bbBlankBox;

	void config(Graphics*, const char*, framesList*);

	SolidBrush* bbCenterBrush;
	SolidBrush* clearBrush;

	Font* buttonFont;

	Pen* bbUpBorderPen[BB_UP_LAYERS];
	Pen* bbDnBorderPen[BB_DN_LAYERS];

};

#endif