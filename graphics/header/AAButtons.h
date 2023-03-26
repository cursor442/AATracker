#ifndef AA_BUTTONS
#define AA_BUTTONS

#include "AATimers.h"

#define BB_ID_NULL        -1
#define BB_ID_BASE       101

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

	int  checkForButton(HWND&, LPARAM, bool&, bool&, int = BB_ID_NULL, bool = true);

	void drawButton(int, Graphics*, bool, bool, int);
	void hideButton(int, Graphics*);

	bool pressButton(int);
	bool releaseButton(int);

	void executeButton(HWND);

	int createButtonId();

	bool registerButton(Graphics* graphics, int, int, RectF&, const char*, void (*bbFunc)(HWND));
	bool activateButton(int);
	bool deactivateButton(int);

	int  isPointInButtonBox(int, int, int, int, bool = true);
	void updateButtonGrid(int, bool);

private:
	POINT    currPoint;  // The current mouse location
	int      currIdx;    // Index of the active button mouse is over
	int      lastIdx;    // Index of the last active button mouse was over
	int      currId;     // ID of the active button mouse is over 
	int      lastId;     // ID of the last active button mouse was over

	int  nextButtonId; // The next unique ID to assign to a newly registered button
	void convIdToIdx(int);

	// Active and inactive buttons
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