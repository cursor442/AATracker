#ifndef PURCHASE_SECTION
#define PURCHASE_SECTION

#include "../../../graphics/header/Section.h"
#include "../../../nationScreen/header/PurchaseClass.h"

#define PURCH_BUTTON_D_OFFSET 488
#define PURCH_BUTTON_U_OFFSET 548

class PurchaseSection : public Section
{
public:
	PurchaseSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~PurchaseSection();

	void configurePurchaseBox(HWND&, RectF&, int);
	void configPurchaseButtons();
	void configDrawTools(Pen*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);

	void resetPurchaseText();
	void updatePurchaseText(bool);
	void updatePurchaseText(Purchase*, int);
	void updatePurchaseText(Purchase*, bool);

	void drawPurchaseBox(Graphics*, bool, bool, int);
	void drawPurchaseBox(Graphics*, bool, bool, bool, int);
	void drawPurchaseBox(Graphics*, int, bool, bool, int);

	void drawPurchaseBoxButtons(Graphics*, bool, bool, int);

	void showPurchaseButtons();
	void hidePurchaseButtons();

	REAL getBoxEdge(int, int);

private:

	// Section frame
	AABox* purchaseFrame;

	// Section boxes
	AABox* purchTitleBox, * purchHeadBox,
		* infBox, * artBox, * mechBox, * tankBox,
		* aaaBox, * fightBox, * tactBox, * stratBox,
		* battleBox, * airccBox, * cruiseBox, * destrBox,
		* subBox, * transBox, * majorBox, * minorBox,
		* minorUpBox, * airbBox, * navbBox, * repBox,
		* totBox;
		
	PointF* titleP0, * titleP1;

	// Section buttons
	HWND* main_Wnd;
	HWND infDButton, infUButton;
	HWND artDButton, artUButton;
	HWND mechDButton, mechUButton;
	HWND tankDButton, tankUButton;
	HWND aaaDButton, aaaUButton;
	HWND fightDButton, fightUButton;
	HWND tactDButton, tactUButton;
	HWND stratDButton, stratUButton;
	HWND battleDButton, battleUButton;
	HWND airccDButton, airccUButton;
	HWND cruiseDButton, cruiseUButton;
	HWND destrDButton, destrUButton;
	HWND subDButton, subUButton;
	HWND transDButton, transUButton;
	HWND majorDButton, majorUButton;
	HWND minorDButton, minorUButton;
	HWND minorUpDButton, minorUpUButton;
	HWND airbDButton, airbUButton;
	HWND navbDButton, navbUButton;
	HWND repairDButton, repairUButton;

	AABox* infQBox, * artQBox, * mechQBox, * tankQBox,
		* aaaQBox, * fightQBox, * tactQBox, * stratQBox,
		* battleQBox, * airccQBox, * cruiseQBox, * destrQBox,
		* subQBox, * transQBox, * majorQBox, * minorQBox,
		* minorUpQBox, * airbQBox, * navbQBox, * repQBox,
		* totQBox;

	AABox* infCBox, * artCBox, * mechCBox, * tankCBox,
		* aaaCBox, * fightCBox, * tactCBox, * stratCBox,
		* battleCBox, * airccCBox, * cruiseCBox, * destrCBox,
		* subCBox, * transCBox, * majorCBox, * minorCBox,
		* minorUpCBox, * airbCBox, * navbCBox, * repCBox,
		* totCBox;

	AABox* battleBoxU, * airccBoxU, * cruiseBoxU, * destrBoxU,
		* subBoxU, * transBoxU;

	// Section text
	WCHAR purchHeadText[PURCH_TEXTLEN];
	WCHAR infText[PURCH_TEXTLEN];
	WCHAR artText[PURCH_TEXTLEN];
	WCHAR mechText[PURCH_TEXTLEN];
	WCHAR tankText[PURCH_TEXTLEN];
	WCHAR aaaText[PURCH_TEXTLEN];
	WCHAR fightText[PURCH_TEXTLEN];
	WCHAR tactText[PURCH_TEXTLEN];
	WCHAR stratText[PURCH_TEXTLEN];
	WCHAR battleText[PURCH_TEXTLEN];
	WCHAR airccText[PURCH_TEXTLEN];
	WCHAR cruiseText[PURCH_TEXTLEN];
	WCHAR destrText[PURCH_TEXTLEN];
	WCHAR subText[PURCH_TEXTLEN];
	WCHAR transText[PURCH_TEXTLEN];
	WCHAR majorText[PURCH_TEXTLEN];
	WCHAR minorText[PURCH_TEXTLEN];
	WCHAR minorUpText[PURCH_TEXTLEN];
	WCHAR airbText[PURCH_TEXTLEN];
	WCHAR navbText[PURCH_TEXTLEN];
	WCHAR repText[PURCH_TEXTLEN];
	WCHAR totText[PURCH_TEXTLEN];

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
