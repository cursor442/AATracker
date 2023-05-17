#ifndef AA_TABS
#define AA_TABS

#define TB_ID_NULL         -1
#define TB_ID_BASE       1001

#define TB_SMALL_FONT  true

#include "../../game/header/framework.h"
#include "AATabBar.h"

class AATabs
{
public:
	AATabs(HWND, RectF);
	~AATabs();

	void configBaseDrawTools(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, SolidBrush*, SolidBrush*);
	void configDrawTools(vector<Color*>&, vector<SolidBrush*>&, SolidBrush*, Font*, Font*);

	int  checkForTab(HWND&, LPARAM, bool&, bool&, int = TB_ID_NULL, bool = true);

	void drawTab(int, Graphics*, bool, bool, int);
	void hideTab(int, Graphics*);

	bool pressTab(HWND, int, int);
	bool releaseTab(int, int);

	int  createTabId();
	void setTabFuncId(int, int, int);

	int getTabScreen(int);
	int getTabSection(int);

	bool registerTab(Graphics*, int, int, RectF&, const char*, bool, bool);
	bool registerTab(Graphics*, int, int, int, RectF&, const char*, void (*bbFunc)(HWND&), bool = false);
	bool activateTab(int);
	bool deactivateTab(int);

	int  isPointInTabBox(int, int, bool = true);

private:
	POINT    currPoint;  // The current mouse location
	int      currIdx;    // Index of the active tab mouse is over
	int      lastIdx;    // Index of the last active tab mouse was over
	int      currId;     // ID of the active tab mouse is over 
	int      lastId;     // ID of the last active tab mouse was over

	int  nextTabId; // The next unique ID to assign to a newly registered tab
	void convIdToIdx(int);

	// Active and inactive tabs
	vector<AATabBar*> activeTabs;
	vector<AATabBar*> inactiveTabs;

	RectF windowRect;

	// Graphics
	Pen* borderPen, * borderlessPen;
	FontFamily* fontFamily;
	StringFormat* textFormat, * centerFormat;
	Font* baseTextFont;
	SolidBrush* textBrush;
	SolidBrush* backBrush;

	SolidBrush* clearBrush;

	Font* tabFont;
	Font* tabFont_s;

	vector<Color*>* grayColors;
	vector<SolidBrush*>* grayBrushes;

};

#endif