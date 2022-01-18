#include "Section.h"
#include "SpreadsheetClass.h"

class MiniSpreadSection : public Section
{
public:
	MiniSpreadSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~MiniSpreadSection();

	void configureMiniSpread(RectF&, int);
	void configDrawTools(Font*, Font*);

	void updateMiniSpreadText(int);
	void updateMiniSpreadFormat(int);

	void resetMiniSpreadText();

	SolidBrush* getLastLineBrush(int);

	void drawMiniSpread(Graphics*, Spreadsheet*, bool, bool, int);
	void drawMiniSpread(Graphics*, Spreadsheet*, int, int, bool, bool, int);

private:

	void valConv(WCHAR*, int);

	// Section frame
	AABox* miniSpreadFrame;

	// Section boxes
	AABox* spreadHead[SPREAD_COLS];
	AABox* spreadBox[SPREAD_ROWS][SPREAD_COLS];

	// Section text
	WCHAR turnText[SPREAD_ROWS][4];

	// Unique graphics
	Font* headFont;
	Font* spreadFont;

	SolidBrush* spreadBrushP, * spreadBrushS;
	SolidBrush* spreadLineBrush;
};