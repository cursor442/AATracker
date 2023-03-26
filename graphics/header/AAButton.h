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

	void configButton(Graphics* graphics, int, RectF&, const char*, framesList*, void (*bbFunc)(HWND));
	void configDrawTools(vector<Color*>&, vector<SolidBrush*>&, SolidBrush*, Font*);

	void drawButton(Graphics*, bool, bool, int);
	void hideButton(Graphics*);

	bool pressButton();
	bool releaseButton();

	void executeButton(HWND);

	int  getButtonId();

private:

	bool bbState;
	bool isDrawn;

	AABox* bbUpBox[BB_UP_LAYERS];
	AABox* bbDnBox[BB_DN_LAYERS];
	AABox* bbUpTextBox;
	AABox* bbDnTextBox;
	AABox* bbBlankBox;

	void config(Graphics*, const char*, framesList*);

	SolidBrush* bbCenterBrush;
	SolidBrush* clearBrush;

	Font* bbFont;

	Pen* bbUpBorderPen[BB_UP_LAYERS];
	Pen* bbDnBorderPen[BB_DN_LAYERS];

	void (*bbFunction)(HWND);

};

#endif