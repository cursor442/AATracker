#include "Section.h"

#define NAME_BOX 0
#define TYPE_BOX 1
#define TURN_BOX 2

class NameSection : public Section
{
public:
	NameSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~NameSection();

	void configureNameBox(RectF&, int);
	void configDrawTools(Font*, Font*);

	void updateNameText(int, int, int);

	void drawNameBox(Graphics*, bool, bool, int);

	REAL getBoxEdge(int, int);

private:

	// Section frame
	AABox* nameFrame;

	// Section boxes
	AABox* nameBox;
	AABox* typeBox;
	AABox* turnBox;

	// Section text
	WCHAR name[16];
	WCHAR gameType[16];
	WCHAR gameTurn[8];

	void turnConv(int);

	// Unique graphics
	Font* nameFont;
	Font* descrFont;
};