#ifndef NEUTRAL_SECTION
#define NEUTRAL_SECTION

#include "../../../graphics/header/Section.h"
#include "../../../logScreen/header/LogText.h"
#include "../../../board/header/TerritoriesClass.h"

#define NEUTRAL_COLS     3
#define NEUTRAL_ROWS    13

class NeutralSection : public Section
{
public:
	NeutralSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~NeutralSection();

	void configureNeutralBox(RectF&, int);
	void configDrawTools(SolidBrush*, HatchBrush*, HatchBrush*, HatchBrush*, Font*, Font*);
	void resetNeutralBox();

	void updateNeutralFormat(int, vector<territoryTransaction>&);

	void drawNeutralBox(Graphics*, bool, bool, int);

private:

	// Section frame
	AABox* neutralFrame;

	// Section boxes
	AABox* neutralBox[NEUTRAL_COLS][NEUTRAL_ROWS];

	// Section text
	vector<terName> neutralText;

	// Section variables
	vector<int> neutralPos;

	// Section graphics
	SolidBrush* tileBrushL;
	HatchBrush* neutBrush, * axisBrush, * allyBrush;

	vector<Brush*> neutralBrush;

	Font* statusFont, * neutralFont;
	
};

#endif
