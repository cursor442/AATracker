#ifndef AA_BUTTONS
#define AA_BUTTONS

#include "AATimers.h"

#define BB_ID_NULL        -1
#define BB_GRID_SIZE       5
#define BB_GRID_ADD        0
#define BB_GRID_SUB        1

#include "../../game/header/framework.h"
#include "AAButton.h"

class AAButtons
{
public:
	AAButtons(HWND, RectF);
	~AAButtons();

	void configBaseDrawTools(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, SolidBrush*, SolidBrush*);
	void configDrawTools(vector<Color*>&, vector<SolidBrush*>&, SolidBrush*, Font*);
	void configScreenFrames(framesList*);

	void checkForButton(HWND&, LPARAM, bool&, bool&, bool = true);
	void drawButton(int, Graphics*, HDC&, bool, bool, int);
	void hideButton(HWND&, LPARAM, Graphics*, int&);

	bool pressButton();
	bool releaseButton();

	bool registerButton(Graphics* graphics, int, int, RectF&, const char*);
	bool activateButton(int);
	bool deactivateButton(int);

	int  isPointInButtonBox(int, int, int, int, bool = true);
	void updateButtonGrid(int, bool);

private:
	POINT    currPoint;   // The current mouse location
	int      currButton; // The window the mouse is currently over
	int      currIdx;     // Index of the active tooltip mouse is over
	int      lastIdx;     // Index of the last active tooltip mouse was over

	// Active and inactive tooltips
	vector<AAButton*> activeButtons;
	vector<AAButton*> inactiveButtons;

	RectF windowRect;
	vector<int> activeButtonGrid[BB_GRID_SIZE][BB_GRID_SIZE];
	int getGridIdx(int, int);

	framesList* screenFrames;

	// Graphics
	Pen* borderPen, * borderlessPen;
	FontFamily* fontFamily;
	StringFormat* textFormat, * centerFormat;
	Font* baseTextFont;
	SolidBrush* textBrush;
	SolidBrush* backBrush;

	SolidBrush* clearBrush;

	Font* buttonFont;

	vector<Color*>* grayColors;
	vector<SolidBrush*>* grayBrushes;

};

#endif