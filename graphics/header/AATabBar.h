#ifndef AA_TAB_BAR
#define AA_TAB_BAR

#define TB_CFG_LEFT  0
#define TB_CFG_FILL  1

#include "AATab.h"

class AATabBar : public AAGraphicsObject
{
public:
	AATabBar(int, int);
	~AATabBar();

	void configTabBar(Graphics*, int, RectF&);
	void configDrawTools(vector<Color*>*, vector<SolidBrush*>*, SolidBrush*, Font*);
	void addTab(Graphics*, int, RectF&, const char*, void (*tbFunc)(HWND&));
	void setTabFuncId(int, int);

	void drawTab(Graphics*, bool, bool, int);
	void hideTab(Graphics*);

	bool pressTab(HWND, int);
	bool releaseTab(int);

	int  getTabId();

private:

	int  tbConfig;
	int  tbTabCnt;
	int  tbTabIdx;
	int  tbState;
	bool isDrawn;

	vector<AATab*> tbTabs;

	AABox* tbBlankBox;

	vector<Color*>*      grayColor;
	vector<SolidBrush*>* grayBrush;

	SolidBrush*          clearBrush;

	Font* tbFont;

	void configTabDrawTools(int);
};

#endif