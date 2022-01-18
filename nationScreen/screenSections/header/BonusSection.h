#ifndef BONUS_SECTION
#define BONUS_SECTION

#include "../../../graphics/header/Section.h"

#define BONS_OBJ_LEN 128
#define BONS_CON_LEN 51
#define BONS_BON_LEN 39
#define BONS_STS_LEN 12

#define BONS_MET_TYP 0
#define BONS_CNT_TYP 1
#define BONS_AWD_TYP 2

struct bonus_text {
	WCHAR obj[BONS_OBJ_LEN];
	WCHAR con[BONS_CON_LEN];
	WCHAR bon[BONS_BON_LEN];
	WCHAR sts[BONS_STS_LEN];
};

class BonusSection : public Section
{
public:
	BonusSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~BonusSection();

	void configureBonusBox(RectF&, int);
	void configDrawTools(Font*);

	void updateBonusFormat(int, int);
	void updateBonusText(int, int, int = BONS_NON, int = BONS_NON, bool = false);

	void resetBonusBox();

	void configGerBonusText(int);
	void configSovBonusText(int);
	void configJpnBonusText(int);
	void configUsaBonusText(int, int);
	void configChnBonusText(int);
	void configUkBonusText(int, int);
	void configItaBonusText(int);
	void configAnzBonusText(int);
	void configFraBonusText(int);

	void drawBonusBox(Graphics*, bool, bool, int);
	void drawBonusBox(Graphics*, bool, bool, bool, int);

private:

	// Section frame
	AABox* bonusFrame;

	// Section boxes
	AABox* bonusHead[BONS_COLS];
	AABox* bonus4Box[4][BONS_COLS];
	AABox* bonus6Box[6][BONS_COLS];

	// Section text
	vector<vector<bonus_text>> bonusText;

	// Section variables
	bool bonusSel;
	int natIdx;

	void valConv(bonus_text*, int, int, bool);

	// Unique graphics
	Font* headFont;
	SolidBrush* bonusBrushP, * bonusBrushS, * bonusBrushF;
	SolidBrush* bonusBrush;

};

#endif
