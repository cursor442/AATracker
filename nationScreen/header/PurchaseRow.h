#ifndef PURCHASE_ROW
#define PURCHASE_ROW

#include "../../graphics/header/GraphicsHeader.h"

#define PURCH_ROW_BOX    0
#define PURCH_ROW_UNIT   1
#define PURCH_ROW_COST   2
#define PURCH_ROW_ATTACK 3
#define PURCH_ROW_DEFEND 4
#define PURCH_ROW_MOVE   5
#define PURCH_ROW_QUANT  6
#define PURCH_ROW_TOTAL  7

class PurchaseRow
{
public:
	PurchaseRow(const char*, const char* = "");
	~PurchaseRow();

	void configRow(RectF&, REAL, REAL, REAL, REAL, bool, int);
	void configRowText(const char*, const char*, const char*, const char*, const char*);
	void configQuantTotText(const char*, const char*);

	void setRowX(REAL);
	void setRowY(REAL);
	void setRowHeight(REAL);

	void drawPurchaseRow(Graphics*, Pen*, Font*, Font*, StringFormat*, StringFormat*, Brush*, Brush*, bool, int);
	void drawPurchaseRow(Graphics*, Pen*, Font*, Font*, StringFormat*, StringFormat*, Brush*, Brush*, int, bool, const WCHAR*, bool, int);

	void updatePurchaseText(int, const WCHAR*);

	REAL y();
	REAL bottom();
	REAL height();
	REAL buttonDownX();
	REAL buttonUpX();

	AABox* getBox(int = PURCH_ROW_BOX);

private:
	AABox* rowBox;
	
	AABox* unitBox;
	AABox* costBox;
	AABox* attackBox;
	AABox* defendBox;
	AABox* moveBox;
	AABox* quantBox;
	AABox* totalBox;

	bool hasButton;

	WCHAR unitText[PURCH_TEXTLEN_T];
	WCHAR costText[PURCH_TEXTLEN_T];
	WCHAR attackText[PURCH_TEXTLEN_T];
	WCHAR defendText[PURCH_TEXTLEN_T];
	WCHAR moveText[PURCH_TEXTLEN_T];
	WCHAR quantText[PURCH_TEXTLEN_T];
	WCHAR totalText[PURCH_TEXTLEN_T];

};

#endif
