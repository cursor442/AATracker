#include "Section.h"

Section::Section(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
{
	configBaseDrawTools(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2);

	pen = NULL;

	gerBrushP = NULL; gerBrushS	= NULL; gerBrushF = NULL;
	sovBrushP = NULL; sovBrushS = NULL; sovBrushF = NULL;
	jpnBrushP = NULL; jpnBrushS = NULL; jpnBrushF = NULL;
	usaBrushP = NULL; usaBrushS = NULL; usaBrushF = NULL;
	chnBrushP = NULL; chnBrushS = NULL; chnBrushF = NULL;
	ukBrushP = NULL;  ukBrushS  = NULL; ukBrushF  = NULL;
	itaBrushP = NULL; itaBrushS = NULL; itaBrushF = NULL;
	anzBrushP = NULL; anzBrushS = NULL; anzBrushF = NULL;
	fraBrushP = NULL; fraBrushS = NULL; fraBrushF = NULL;
}

Section::~Section()
{

}

void Section::configBaseDrawTools(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
{
	borderPen = p0;
	borderlessPen = p1;

	fontFamily = ff;
	textFormat = sf0;
	centerFormat = sf1;
	baseTextFont = f0;
	baseTitleFont = f1;

	textBrush = b0;
	backBrush = b1;
	paneBrush = b2;
}

void Section::configNationBrushesP(SolidBrush* b0, SolidBrush* b1, SolidBrush* b2, SolidBrush* b3, SolidBrush* b4,
	SolidBrush* b5, SolidBrush* b6, SolidBrush* b7, SolidBrush* b8)
{
	gerBrushP = b0;
	sovBrushP = b1;
	jpnBrushP = b2;
	usaBrushP = b3;
	chnBrushP = b4;
	ukBrushP = b5;
	itaBrushP = b6;
	anzBrushP = b7;
	fraBrushP = b8;
}

void Section::configNationBrushesS(SolidBrush* b0, SolidBrush* b1, SolidBrush* b2, SolidBrush* b3, SolidBrush* b4,
	SolidBrush* b5, SolidBrush* b6, SolidBrush* b7, SolidBrush* b8)
{
	gerBrushS = b0;
	sovBrushS = b1;
	jpnBrushS = b2;
	usaBrushS = b3;
	chnBrushS = b4;
	ukBrushS = b5;
	itaBrushS = b6;
	anzBrushS = b7;
	fraBrushS = b8;
}

void Section::configNationBrushesF(SolidBrush* b0, SolidBrush* b1, SolidBrush* b2, SolidBrush* b3, SolidBrush* b4,
	SolidBrush* b5, SolidBrush* b6, SolidBrush* b7, SolidBrush* b8)
{
	gerBrushF = b0;
	sovBrushF = b1;
	jpnBrushF = b2;
	usaBrushF = b3;
	chnBrushF = b4;
	ukBrushF = b5;
	itaBrushF = b6;
	anzBrushF = b7;
	fraBrushF = b8;
}