#ifndef AA_TOOLTIPS
#define AA_TOOLTIPS

#define TT_ID_NULL        -1
#define TT_GRID_SIZE       5
#define TT_GRID_ADD        0
#define TT_GRID_SUB        1

#define TT_TIMER_NULL      0
#define TT_SAMPLE_TIMER_ID 1
#define TT_HOVER_TIMER_ID  2
#define TT_SAMPLE_TIMEOUT  250
#define TT_HOVER_TIMEOUT   1500

#include "../../game/header/framework.h"
#include "AATooltip.h"

class AATooltips
{
public:
	AATooltips(HWND, RectF);
	~AATooltips();

	void configBaseDrawTools(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	void configScreenFrames(framesList*);

	void updateCurrPoint(HWND&, LPARAM, bool&, bool&);
	void drawTooltip(HWND&, LPARAM, Graphics*, bool, bool, int);
	void hideTooltip(HWND&, LPARAM, Graphics*, int&);

	bool registerTooltip(Graphics* graphics, int, int, RectF&, int, const char*);
	bool activateTooltip(int);
	bool deactivateTooltip(int);

	int  isPointInTooltipBox(int, int, int, int);
	void updateTooltipGrid(int, bool);

private:
	POINT    currPoint;   // The current mouse location
	int      currTooltip; // The window the mouse is currently over
	int      currIdx;     // Index of the active tooltip mouse is over
	int      lastIdx;     // Index of the last active tooltip mouse was over

	// Active and inactive tooltips
	vector<AATooltip*> activeTooltips;
	vector<AATooltip*> inactiveTooltips;

	RectF windowRect;
	vector<int> activeTooltipGrid[TT_GRID_SIZE][TT_GRID_SIZE];
	int getGridIdx(int, int);

	framesList* screenFrames;

	// Graphics
	Pen* borderPen, * borderlessPen;
	FontFamily* fontFamily;
	StringFormat* textFormat, * centerFormat;
	Font* baseTextFont;
	SolidBrush* textBrush;
	SolidBrush* backBrush;
	SolidBrush* popupBrush;

};

#endif