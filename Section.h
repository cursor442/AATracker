#ifndef SECTION_CLASS
#define SECTION_CLASS

#include "framework.h"
#include "Resource.h"
#include "GraphicsHeader.h"

class Section
{
public:
	Section(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	virtual ~Section();

	virtual void configNationBrushesP(SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*);
	virtual void configNationBrushesS(SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*);
	virtual void configNationBrushesF(SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*);


protected:

	// Base graphics
	Pen* borderPen, * borderlessPen;
	FontFamily* fontFamily;
	StringFormat* textFormat, * centerFormat;
	Font* baseTextFont, * baseTitleFont;
	SolidBrush* textBrush;
	SolidBrush* backBrush;
	SolidBrush* paneBrush;
	void configBaseDrawTools(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);

	// Nation brushes
	SolidBrush* gerBrushP, * gerBrushS, * gerBrushF;
	SolidBrush* sovBrushP, * sovBrushS, * sovBrushF;
	SolidBrush* jpnBrushP, * jpnBrushS, * jpnBrushF;
	SolidBrush* usaBrushP, * usaBrushS, * usaBrushF;
	SolidBrush* chnBrushP, * chnBrushS, * chnBrushF;
	SolidBrush* ukBrushP,  * ukBrushS,  * ukBrushF;
	SolidBrush* itaBrushP, * itaBrushS, * itaBrushF;
	SolidBrush* anzBrushP, * anzBrushS, * anzBrushF;
	SolidBrush* fraBrushP, * fraBrushS, * fraBrushF;

	Pen* pen;

};

#endif
