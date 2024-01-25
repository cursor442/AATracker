#ifndef PURCHASE_SECTION
#define PURCHASE_SECTION

#include "../../../graphics/header/Section.h"
#include "../../../nationScreen/header/PurchaseClass.h"
#include "../../graphics/header/GraphicsHeader.h"
#include "../../header/PurchaseRow.h"

#define PURCH_ROW_UNIT_WIDTH    0.30
#define PURCH_ROW_STAT_WIDTH    0.40
#define PURCH_ROW_QUANT_WIDTH   0.16
#define PURCH_ROW_TOTAL_WIDTH   0.14
#define PURCH_BUTTON_D_OFFSET 488
#define PURCH_BUTTON_U_OFFSET 548

class PurchaseSection : public Section
{
public:
	PurchaseSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~PurchaseSection();

	void configurePurchaseBox(Graphics*, HWND&, RectF&, AAButtons*, void (*purchaseButton)(HWND&, int), int);
	void configPurchaseButtons(Graphics*, AAButtons*, void (*purchaseButton)(HWND&, int));
	void configPurchaseBoxFunctions(void (*showButton)(int, bool), void (*hideButton)(int, bool), void (*hideButtonNoDraw)(int));
	void configDrawTools(Pen*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);

	void resetPurchaseText();
	void updatePurchaseText(bool);
	void updatePurchaseText(Purchase*, int);
	void updatePurchaseText(Purchase*, bool);

	void drawPurchaseBox(Graphics*, DBG&);
	void drawPurchaseBox(Graphics*, bool, DBG&);
	void drawPurchaseBox(Graphics*, int, DBG&);

	void drawPurchaseBoxButtons(Graphics*, DBG&);

	void showPurchaseButtons();
	void showPurchaseButtons(int);
	void hidePurchaseButtons(bool = false);

	REAL getBoxEdge(int, int);

private:

	// Section frame
	AABox* purchaseFrame;

	// Section boxes
	AABox* purchTitleBox;

	PurchaseRow* purchHeadRow,
		* infRow, * artRow, * mechRow, * tankRow,
		* aaaRow, * fightRow, * tactRow, * stratRow,
		* battleRow, * airccRow, * cruiseRow, * destrRow,
		* subRow, * transRow, * majorRow, * minorRow,
		* minorUpRow, * airbRow, * navbRow, * repRow,
		* totRow;
		
	PointF* titleP0, * titleP1;

	// Section buttons
	HWND* main_Wnd;
	AAButtons* buttons;
	void (*showButton)(int, bool);
	void (*hideButton)(int, bool);
	void (*hideButtonNoDraw)(int);
	int infDButton, infUButton;
	int artDButton, artUButton;
	int mechDButton, mechUButton;
	int tankDButton, tankUButton;
	int aaaDButton, aaaUButton;
	int fightDButton, fightUButton;
	int tactDButton, tactUButton;
	int stratDButton, stratUButton;
	int battleDButton, battleUButton;
	int airccDButton, airccUButton;
	int cruiseDButton, cruiseUButton;
	int destrDButton, destrUButton;
	int subDButton, subUButton;
	int transDButton, transUButton;
	int majorDButton, majorUButton;
	int minorDButton, minorUButton;
	int minorUpDButton, minorUpUButton;
	int airbDButton, airbUButton;
	int navbDButton, navbUButton;
	int repairDButton, repairUButton;

	int currUKButton;
	void valConv(WCHAR*, int);

	WCHAR infQ[4];
	WCHAR artQ[4];
	WCHAR mechQ[4];
	WCHAR tankQ[4];
	WCHAR aaaQ[4];
	WCHAR fightQ[4];
	WCHAR tactQ[4];
	WCHAR stratQ[4];
	WCHAR battleQ[4];
	WCHAR airccQ[4];
	WCHAR cruiseQ[4];
	WCHAR destrQ[4];
	WCHAR subQ[4];
	WCHAR transQ[4];
	WCHAR majorQ[4];
	WCHAR minorQ[4];
	WCHAR minorUpQ[4];
	WCHAR airbQ[4];
	WCHAR navbQ[4];
	WCHAR repQ[4];
	WCHAR totQ[4];

	WCHAR infC[4];
	WCHAR artC[4];
	WCHAR mechC[4];
	WCHAR tankC[4];
	WCHAR aaaC[4];
	WCHAR fightC[4];
	WCHAR tactC[4];
	WCHAR stratC[4];
	WCHAR battleC[4];
	WCHAR airccC[4];
	WCHAR cruiseC[4];
	WCHAR destrC[4];
	WCHAR subC[4];
	WCHAR transC[4];
	WCHAR majorC[4];
	WCHAR minorC[4];
	WCHAR minorUpC[4];
	WCHAR airbC[4];
	WCHAR navbC[4];
	WCHAR repC[4];
	WCHAR totC[4];

	// Unique graphics
	Pen* backPen;

	StringFormat* purchaseFormat;

	Font* purchFont;
	Font* costFont;

	SolidBrush* tileBrushL;
	SolidBrush* tileBrushD;
	SolidBrush* clearBrush;

};

#endif
