#ifndef AA_TAB
#define AA_TAB

#define TB_UP false
#define TB_DN true

#define TB_UP_LAYERS 5
#define TB_DN_LAYERS 2

#include "../../game/header/Resource.h"
#include "AAGraphicsObject.h"

class AATab : public AAGraphicsObject
{
public:
	AATab(int);
	~AATab();

	void configTab(Graphics*, int, RectF&, const char*);
	void configTab(Graphics*, int, RectF&, const char*, void (*tbFunc)(HWND&));
	void configDrawTools(vector<Color*>&, vector<SolidBrush*>&, SolidBrush*, Font*);
	void setTabFuncId(int);

	void drawTab(Graphics*, bool, bool, int);
	void hideTab(Graphics*);

	bool pressTab(HWND);
	bool releaseTab();

	int  getTabId();

private:

	int  tbState;
	bool isDrawn;

	vector<WCHAR> tbText[GRAPHICS_TEXTLEN];

	AABox* tbUpBox[TB_UP_LAYERS];
	AABox* tbDnBox[TB_DN_LAYERS];
	AABox* tbUpTextBox;
	AABox* tbDnTextBox;
	AABox* tbBlankBox;

	void config(const char*);
	void executeTab(HWND);

	SolidBrush* tbCenterBrush;
	SolidBrush* clearBrush;

	Font* tbFont;

	Pen* tbUpBorderPen[TB_UP_LAYERS];
	Pen* tbDnBorderPen[TB_DN_LAYERS];

	int  tbFuncId;
	bool hasFuncId;
	void (*tbFunction0)(HWND&);

};

#endif