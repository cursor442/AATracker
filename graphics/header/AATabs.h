#ifndef AA_TABS
#define AA_TABS

#define TB_ID_NULL         -1
#define TB_ID_BASE       1001

#define TB_SMALL_FONT  true

#include "AATabBar.h"

class AATabs
{
public:
	AATabs(HWND, RectF);
	~AATabs();

	void configBaseDrawTools(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, SolidBrush*, SolidBrush*);
	void configDrawTools(vector<Color*>&, vector<SolidBrush*>&, SolidBrush*, StringFormat*, StringFormat*, Font*, Font*);
	void addTab(Graphics*, int, const char*, void (*tbFunc)(HWND&));
	void addTab(Graphics*, int, const char*, void (*tbFunc)(HWND&, int));

	int  checkForTab(HWND&, LPARAM, bool&, int&);

	void drawTab(int, Graphics*, DBG&);
	void hideTab(int, Graphics*);
	void hideAllTabs(Graphics*);

	bool pressTab(int, int);
	bool pressTab(HWND, int, int);
	bool releaseTab(int, int);

	bool deleteTab(Graphics*, int, int);

	int  createTabId();
	void setTabFuncId(int, int, int);

	int getTabScreen(int);
	int getTabSection(int);
	int getTabBarTabs(int);

	bool registerTab(Graphics*, int, int, int, int, RectF&, const char*, bool, bool);
	bool registerTab(Graphics*, int, int, int, int, RectF&, const char*, void (*bbFunc)(HWND&), bool = false);
	bool activateTab(int);
	bool deactivateTab(int);
	bool deleteTabBar(int);

	int  isPointInTabBox(int, int);
	int  whichTabBox(int, int, int);
	int  getTabState(int);

private:
	POINT    currPoint;  // The current mouse location
	int      currIdx;    // Index of the active tab mouse is over
	int      lastIdx;    // Index of the last active tab mouse was over
	int      currId;     // ID of the active tab mouse is over 
	int      lastId;     // ID of the last active tab mouse was over

	int  nextTabId; // The next unique ID to assign to a newly registered tab
	void convIdToIdx(int);
	void convIdToIdxInactive(int);
	bool getIsActive(int, bool&);

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

	StringFormat* leftFormat, * rightFormat;

	Font* tabFont;
	Font* tabFont_s;

	vector<Color*>* grayColors;
	vector<SolidBrush*>* grayBrushes;

};

#endif