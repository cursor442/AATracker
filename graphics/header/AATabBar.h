#ifndef AA_TAB_BAR
#define AA_TAB_BAR

#define TB_CFG_LEFT  0
#define TB_CFG_FILL  1
#define TB_CFG_EVEN  2

#include "AATab.h"

class AATabBar : public AAGraphicsObject
{
public:
	AATabBar(int, int, int);
	~AATabBar();

	void configTabBar(Graphics*, int, RectF&);
	void configDrawTools(vector<Color*>*, vector<SolidBrush*>*, SolidBrush*, Font*);
	void addTab(Graphics*, const char*, void (*tbFunc)(HWND&));
	void setTabFuncId(int, int);

	void drawTab(Graphics*, bool, bool, int);
	void hideTab(Graphics*);

	bool pressTab(int);
	bool pressTab(HWND, int);
	bool releaseTab(int);

	int  getTabId();
	int  whichTabContainsPoint(int, int);
	int  getTabState();

private:

	int  tbConfig;
	int  tbOrient;
	int  tbTabCnt;
	int  tbTabIdx;
	int  tbState;
	bool isDrawn;

	vector<AATab*> tbTabs;

	vector<REAL> tbTabWidths;
	vector<REAL> tbTabWeights;
	vector<REAL> tbTabStarts;

	AABox* tbBlankBox;

	vector<Color*>*      grayColor;
	vector<SolidBrush*>* grayBrush;

	SolidBrush*          clearBrush;

	Font* tbFont;

	void configTabDrawTools(int);

	RectF calcTabWidth(Graphics&, const char* = nullptr);
	RectF* calcTextWidth(Graphics&, const char* = nullptr);
	void  updateTabWidths(REAL = 0);

	bool  tbOrientVert;
	bool  isTransposed;
	void  transposeObjBox();
	void  transposeTabBox(RectF&);
};

#endif