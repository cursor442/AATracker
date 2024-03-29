#ifndef STATUS_SECTION
#define STATUS_SECTION

#include "../../../graphics/header/Section.h"

#define NAME_BOX 0
#define TYPE_BOX 1
#define TURN_BOX 2

class StatusSection : public Section
{
public:
	StatusSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~StatusSection();

	void configureStatusBox(RectF&, int);
	void configDrawTools(StringFormat*, Font*);

	void updateStatusText(int, int, int, int, int);

	void drawStatusBox(Graphics*, int, DBG&);

private:

	// Section frame
	AABox* statusFrame;

	// Section boxes
	AABox* axisBox, * alliesBox;

	// Section text
	WCHAR axis[56];
	WCHAR axisG[95];
	WCHAR allies[55];

	// Unique graphics
	StringFormat* statusFormat;

	Font* statusFont;

};

#endif
