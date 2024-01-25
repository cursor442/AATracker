#ifndef AA_TAB
#define AA_TAB

#define TB_ORT_UP    0
#define TB_ORT_DN    1
#define TB_ORT_LEFT  2
#define TB_ORT_RIGHT 3

#define TB_UP false
#define TB_DN true

#define TB_TOP_LAYERS   8
#define TB_BOT_LAYERS   2
#define TB_LEFT_LAYERS  2
#define TB_RIGHT_LAYERS 2

#include "AAGraphicsObject.h"

class AATab : public AAGraphicsObject
{
public:
	AATab(int, int);
	~AATab();

	void configTab(Graphics*, int, RectF&, const char*);
	void configTab(Graphics*, int, RectF&, const char*, void (*tbFunc)(HWND&));
	void configTab(Graphics*, int, RectF&, const char*, void (*tbFunc)(HWND&, int));
	void reconfigTab(RectF&);
	void configDrawTools(vector<Color*>&, vector<SolidBrush*>&, SolidBrush*, Font*);
	void setTabFuncId(int);
	void setTabState(bool);

	void drawTab(Graphics*, DBG&);
	void hideTab(Graphics*);

	bool pressTab();
	bool pressTab(HWND);
	bool releaseTab();

	void setTabLast(bool);
	void setIsDrawn(bool);

	int  getTabId();
	int  getTabOrient();

private:

	int  tbOrient;
	bool tbState;
	bool tbLast;
	bool isDrawn;

	vector<WCHAR> tbText[GRAPHICS_TEXTLEN];

	AALine* tbUpTopLine[TB_TOP_LAYERS];
	AALine* tbUpBotLine[TB_BOT_LAYERS];
	AALine* tbUpLeftLine[TB_LEFT_LAYERS];
	AALine* tbUpRightLine[TB_RIGHT_LAYERS];
	AALine* tbDnTopLine[TB_TOP_LAYERS];
	AALine* tbDnBotLine[TB_BOT_LAYERS];
	AALine* tbDnLeftLine[TB_LEFT_LAYERS];
	AALine* tbDnRightLine[TB_RIGHT_LAYERS];
	AABox* tbUpTextBox;
	AABox* tbDnTextBox;
	AABox* tbBlankBox;

	void config(const char*);
	void configGraphics();
	void configGraphicsUp();
	void configGraphicsDown();
	void configGraphicsLeft();
	void configGraphicsRight();
	void executeTab(HWND);

	SolidBrush* tbCenterBrush;
	SolidBrush* clearBrush;

	Font* tbFont;

	Pen* tbTopPen[TB_TOP_LAYERS];
	Pen* tbBotPen[TB_BOT_LAYERS];
	Pen* tbLeftPen[TB_LEFT_LAYERS];
	Pen* tbRightPen[TB_RIGHT_LAYERS];

	int  tbFuncId;
	bool hasFuncId;
	void (*tbFunction0)(HWND&);
	void (*tbFunction1)(HWND&, int);

	bool  tbOrientVert;

};

#endif