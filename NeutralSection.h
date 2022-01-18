#include "Section.h"

#define NEUTRAL_COLS     3
#define NEUTRAL_ROWS    14

#define NEUTRAL_TEXTLEN 38

class NeutralSection : public Section
{
public:
	NeutralSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~NeutralSection();

	void configureNeutralBox(RectF&, int);
	void configDrawTools();

	void drawNeutralBox(Graphics*, bool, bool, int);

private:

	// Section frame
	AABox* neutralFrame;

	// Section boxes
	AABox* neutralStatusBox;
	AABox* neutralBox[NEUTRAL_COLS][NEUTRAL_ROWS];

	// Section text
	WCHAR neutralStatusText[NEUTRAL_TEXTLEN];

	
};