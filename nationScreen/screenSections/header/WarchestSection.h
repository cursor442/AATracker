#ifndef WARCHEST_SECTION
#define WARCHEST_SECTION

#include "../../../graphics/header/Section.h"
#include "../../../logScreen/header/LogText.h"

#define WARCHEST_VALW   72
#define WARCHEST_VALM   8

struct wcText {
	WCHAR t[18];
};

class WarchestSection : public Section
{
public:
	WarchestSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~WarchestSection();

	void configureWarchestBox(RectF&, RectF&, int);
	void configDrawTools(Font*);

	void updateWarchestText(int, int, int, bool = false);
	void updateWarchestBrushes(int, bool, SolidBrush*);

	void resetWarchestBox();

	void drawWarchestBox(Graphics*, DBG&);

private:

	// Section frame
	AABox* warchestFrame;

	// Section boxes
	AABox* warchestBoxes[3][3];
	AABox* warchestValBoxes[3][3];
	AABox* warchestUKValBox;
	AAQuad* warchestCone;

	// Section variables
	vector<int> natOrder;
	vector<bool> ukPos;

	// Section text
	vector<wcText> natText;
	vector<wcText> natVals;
	wcText ukVal;

	void valConv(wcText*, int, int);

	// Unique graphics
	SolidBrush* warchestBrushes[3][3];
	SolidBrush* warchestValBrushes[3][3];
	Font* natFont;
};

#endif
