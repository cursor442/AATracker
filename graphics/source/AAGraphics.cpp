#include "../header/GraphicsHeader.h"

AAGraphics::AAGraphics()
{
	///////////////////////////////////////////////////////////////////////////
	//// Pens
	///////////////////////////////////////////////////////////////////////////

	borderlessPen = NULL;
	blackPen1 = NULL; blackPen2 = NULL; blackPen4 = NULL;
	backPen = NULL;

	///////////////////////////////////////////////////////////////////////////
	//// Fonts
	///////////////////////////////////////////////////////////////////////////

	calibriFamily = NULL;

	logTextFormat = NULL; leftCenterFormat = NULL; centerFormat = NULL;
	leftTopFormat = NULL; purchaseFormat = NULL;

	font12 = NULL; font12_b = NULL;
	font14 = NULL; font14_b = NULL;
	font16 = NULL; font16_b = NULL;
	font17 = NULL;
	font18 = NULL; font18_b = NULL;
	font20 = NULL; font20_b = NULL;
	font24 = NULL; font24_b = NULL;
	font28 = NULL;
	font32 = NULL;
	font64_b = NULL;

	///////////////////////////////////////////////////////////////////////////
	//// Brushes
	///////////////////////////////////////////////////////////////////////////
	
	textBrush = NULL; paneBrush = NULL; backBrush = NULL;
	tileBrushL = NULL; tileBrushD = NULL;
	whiteBrush = NULL; redBrush = NULL;
	clearBrush = NULL;

	// Turn phase brushes
	resBrushP   = NULL; resBrushS   = NULL;
	purchBrushP = NULL;	purchBrushS = NULL;
	cmBrushP    = NULL;	cmBrushS    = NULL;
	ccBrushP    = NULL;	ccBrushS    = NULL;
	ncBrushP    = NULL;	ncBrushS    = NULL;
	mobBrushP   = NULL;	mobBrushS   = NULL;
	incBrushP   = NULL;	incBrushS   = NULL;

	// Nation brushes
	gerBrushP = NULL; gerBrushS = NULL; gerBrushF = NULL;
	sovBrushP = NULL; sovBrushS = NULL; sovBrushF = NULL;
	jpnBrushP = NULL; jpnBrushS = NULL; jpnBrushF = NULL;
	usaBrushP = NULL; usaBrushS = NULL; usaBrushF = NULL;
	chnBrushP = NULL; chnBrushS = NULL; chnBrushF = NULL;
	ukBrushP  = NULL; ukBrushS  = NULL; ukBrushF  = NULL;
	itaBrushP = NULL; itaBrushS = NULL; itaBrushF = NULL;
	anzBrushP = NULL; anzBrushS = NULL; anzBrushF = NULL;
	fraBrushP = NULL; fraBrushS = NULL; fraBrushF = NULL;
}

AAGraphics::~AAGraphics()
{
	///////////////////////////////////////////////////////////////////////////
	//// Pens
	///////////////////////////////////////////////////////////////////////////

	delete borderlessPen;
	delete blackPen1; delete blackPen2; delete blackPen4;
	delete backPen;
	
	///////////////////////////////////////////////////////////////////////////
	//// Fonts
	///////////////////////////////////////////////////////////////////////////

	delete calibriFamily;

	delete logTextFormat; delete leftCenterFormat; delete centerFormat;
	delete leftTopFormat; delete purchaseFormat;

	delete font12; delete font12_b;
	delete font14; delete font14_b;
	delete font16; delete font16_b;
	delete font17;
	delete font18; delete font18_b;
	delete font20; delete font20_b;
	delete font24; delete font24_b;
	delete font28;
	delete font32;
	delete font64_b;
	
	///////////////////////////////////////////////////////////////////////////
	//// Brushes
	///////////////////////////////////////////////////////////////////////////

	delete textBrush;  delete paneBrush; delete backBrush;
	delete tileBrushL; delete tileBrushD;
	delete whiteBrush; delete redBrush;
	delete clearBrush;

	// Phase section brushes
	delete resBrushP;   delete resBrushS;
	delete purchBrushP; delete purchBrushS;
	delete cmBrushP;	delete cmBrushS;
	delete ccBrushP;	delete ccBrushS;
	delete ncBrushP;	delete ncBrushS;
	delete mobBrushP;   delete mobBrushS;
	delete incBrushP;   delete incBrushS;

	// Nation brushes
	delete gerBrushP; delete gerBrushS; delete gerBrushF;
	delete sovBrushP; delete sovBrushS; delete sovBrushF;
	delete jpnBrushP; delete jpnBrushS; delete jpnBrushF;
	delete usaBrushP; delete usaBrushS; delete usaBrushF;
	delete chnBrushP; delete chnBrushS; delete chnBrushF;
	delete ukBrushP;  delete ukBrushS;  delete ukBrushF;
	delete itaBrushP; delete itaBrushS; delete itaBrushF;
	delete anzBrushP; delete anzBrushS; delete anzBrushF;
	delete fraBrushP; delete fraBrushS; delete fraBrushF;
}

void AAGraphics::config(HDC& hdc)
{
	///////////////////////////////////////////////////////////////////////////
	//// Pens
	///////////////////////////////////////////////////////////////////////////

	borderlessPen = new Pen(Color(0, 0, 0, 0));
	blackPen1 = new Pen(Color(255, 0, 0, 0), 1);
	blackPen2 = new Pen(Color(255, 0, 0, 0), 2);
	blackPen4 = new Pen(Color(255, 0, 0, 0), 4);
	backPen = new Pen(Color(255, 240, 240, 240));

	///////////////////////////////////////////////////////////////////////////
	//// Fonts
	///////////////////////////////////////////////////////////////////////////

	REAL tabs0 = 20.0f;
	REAL tabs1[] = {212.0f, 48.0f, 60.0f, 76.0f, 72.0f, 88.0f};

	calibriFamily = new FontFamily(L"Calibri");

	logTextFormat = new StringFormat();
	logTextFormat->SetAlignment(StringAlignmentNear);
	logTextFormat->SetLineAlignment(StringAlignmentNear);
	leftCenterFormat = new StringFormat();
	leftCenterFormat->SetAlignment(StringAlignmentNear);
	leftCenterFormat->SetLineAlignment(StringAlignmentCenter);
	centerFormat = new StringFormat();
	centerFormat->SetAlignment(StringAlignmentCenter);
	centerFormat->SetLineAlignment(StringAlignmentCenter);
	leftTopFormat = new StringFormat();
	leftTopFormat->SetAlignment(StringAlignmentNear);
	leftTopFormat->SetLineAlignment(StringAlignmentNear);
	leftTopFormat->SetTabStops(0.0f, 1, &tabs0);
	purchaseFormat = new StringFormat();
	purchaseFormat->SetAlignment(StringAlignmentNear);
	purchaseFormat->SetLineAlignment(StringAlignmentCenter);
	purchaseFormat->SetTabStops(0.0f, 6, tabs1);

	HFONT* tmp_font17 = new HFONT(CreateFont(17, 0, 0, 0, FW_REGULAR, 0, 0, 0, 0, 0, 0, 2, 0, L"TMP_FONT17"));

	font12 = new Font(calibriFamily, FONT12_S, FontStyleRegular, UnitPixel);
	font12_b = new Font(calibriFamily, FONT12_S, FontStyleBold, UnitPixel);
	font14 = new Font(calibriFamily, FONT14_S, FontStyleRegular, UnitPixel);
	font14_b = new Font(calibriFamily, FONT14_S, FontStyleBold, UnitPixel);
	font16 = new Font(calibriFamily, FONT16_S, FontStyleRegular, UnitPixel);
	font16_b = new Font(calibriFamily, FONT16_S, FontStyleBold, UnitPixel);
	font17 = new Font(hdc, *tmp_font17);
	font18 = new Font(calibriFamily, FONT18_S, FontStyleRegular, UnitPixel);
	font18_b = new Font(calibriFamily, FONT18_S, FontStyleBold, UnitPixel);
	font20 = new Font(calibriFamily, FONT20_S, FontStyleRegular, UnitPixel);
	font20_b = new Font(calibriFamily, FONT20_S, FontStyleBold, UnitPixel);
	font24 = new Font(calibriFamily, FONT24_S, FontStyleRegular, UnitPixel);
	font24_b = new Font(calibriFamily, FONT24_S, FontStyleBold, UnitPixel);
	font28 = new Font(calibriFamily, FONT28_S, FontStyleRegular, UnitPixel);
	font32 = new Font(calibriFamily, FONT32_S, FontStyleRegular, UnitPixel);
	font64_b = new Font(calibriFamily, FONT64_S, FontStyleBold, UnitPixel);

	delete tmp_font17;

	///////////////////////////////////////////////////////////////////////////
	//// Brushes
	///////////////////////////////////////////////////////////////////////////

	textBrush = new SolidBrush(Color(255, 0, 0, 0));
	paneBrush = new SolidBrush(Color(212, 212, 212));
	backBrush = new SolidBrush(Color(240, 240, 240));
	tileBrushL = new SolidBrush(Color(234, 234, 234));
	tileBrushD = new SolidBrush(Color(191, 191, 191));
	whiteBrush = new SolidBrush(Color(255, 255, 255));
	redBrush = new SolidBrush(Color(255, 0, 0));
	clearBrush = new SolidBrush(Color(0, 0, 0, 0));

	// Phase section brushes
	resBrushP   = new SolidBrush(Color(89,  89,  89));
	purchBrushP = new SolidBrush(Color(0,   255, 0));
	cmBrushP    = new SolidBrush(Color(151, 71,  6));
	ccBrushP    = new SolidBrush(Color(255, 0,   0));
	ncBrushP    = new SolidBrush(Color(79,  98,  40));
	mobBrushP   = new SolidBrush(Color(146, 208, 80));
	incBrushP   = new SolidBrush(Color(112, 48,  160));
	resBrushS   = new SolidBrush(Color(225, 225, 225));
	purchBrushS = new SolidBrush(Color(209, 255, 209));
	cmBrushS    = new SolidBrush(Color(236, 222, 210));
	ccBrushS    = new SolidBrush(Color(255, 209, 209));
	ncBrushS    = new SolidBrush(Color(223, 226, 216));
	mobBrushS   = new SolidBrush(Color(235, 246, 223));
	incBrushS   = new SolidBrush(Color(229, 217, 238));

	// Nation brushes
	gerBrushP = new SolidBrush(Color(77,  93,  83));
	gerBrushS = new SolidBrush(Color(109, 122, 114));
	gerBrushF = new SolidBrush(Color(223, 226, 224));
	sovBrushP = new SolidBrush(Color(255, 26,  0));
	sovBrushS = new SolidBrush(Color(255, 68,  46));
	sovBrushF = new SolidBrush(Color(255, 213, 209));
	jpnBrushP = new SolidBrush(Color(188, 0,   45));
	jpnBrushS = new SolidBrush(Color(200, 46,  83));
	jpnBrushF = new SolidBrush(Color(243, 209, 217));
	usaBrushP = new SolidBrush(Color(107, 142, 35));
	usaBrushS = new SolidBrush(Color(134, 163, 75));
	usaBrushF = new SolidBrush(Color(228, 234, 215));
	chnBrushP = new SolidBrush(Color(0,   0,   149));
	chnBrushS = new SolidBrush(Color(46,  46,  168));
	chnBrushF = new SolidBrush(Color(209, 209, 236));
	ukBrushP  = new SolidBrush(Color(240, 230, 140));
	ukBrushS  = new SolidBrush(Color(243, 235, 161));
	ukBrushF  = new SolidBrush(Color(252, 250, 234));
	itaBrushP = new SolidBrush(Color(0,   140, 69));
	itaBrushS = new SolidBrush(Color(46,  161, 103));
	itaBrushF = new SolidBrush(Color(209, 234, 221));
	anzBrushP = new SolidBrush(Color(47,  87,  21));
	anzBrushS = new SolidBrush(Color(85,  118, 64));
	anzBrushF = new SolidBrush(Color(217, 224, 212));
	fraBrushP = new SolidBrush(Color(0,   114, 187));
	fraBrushS = new SolidBrush(Color(46,  140, 199));
	fraBrushF = new SolidBrush(Color(209, 229, 243));
}

AABox::AABox()
{
	layer = 0;

	for (int i = 0; i < DEFAULT_TEXTLEN; i++)
		defaultText[i] = '\0';
}

AABox::AABox(const char* def)
{
	layer = 0;

	for (int i = 0; i < DEFAULT_TEXTLEN; i++)
		defaultText[i] = '\0';
	for (int i = 0; i < strlen(def); i++)
		defaultText[i] = def[i];
}

AABox::~AABox()
{

}

void AABox::config(RectF r, int l)
{
	box = r;
	layer = l;
}

void AABox::drawFrame(Graphics* graphics, Pen* pen, Font* font, StringFormat* sf, Brush* b0, Brush* b1, int layers)
{
	if (layer <= layers)
	{
		graphics->FillRectangle(b1, box);
		graphics->DrawRectangle(pen, box);
		graphics->DrawString(defaultText, -1, font, box, sf, b0);
	}
}

void AABox::drawBox(Graphics* graphics, Pen* pen, Font* font, StringFormat* sf, Brush* b0, Brush* b1, const WCHAR* str, int layers)
{
	if (layer <= layers)
	{
		graphics->FillRectangle(b1, box);
		graphics->DrawRectangle(pen, box);
		graphics->DrawString(str, -1, font, box, sf, b0);
	}
}

AATri::AATri()
{
	layer = 0;

	for (int i = 0; i < DEFAULT_TEXTLEN; i++)
		defaultText[i] = '\0';
}

AATri::~AATri()
{

}

void AATri::config(PointF p0, PointF p1, PointF p2, int l)
{
	tri[0] = p0;
	tri[1] = p1;
	tri[2] = p2;
	layer = l;
}

void AATri::drawTri(Graphics* graphics, Pen* pen, Brush* b0, int layers)
{
	if (layer <= layers)
	{
		graphics->FillPolygon(b0, tri, 3);
		graphics->DrawPolygon(pen, tri, 3);
	}
}

AAQuad::AAQuad()
{
	layer = 0;

	for (int i = 0; i < DEFAULT_TEXTLEN; i++)
		defaultText[i] = '\0';
}

AAQuad::~AAQuad()
{

}

void AAQuad::config(PointF p0, PointF p1, PointF p2, PointF p3, int l)
{
	quad[0] = p0;
	quad[1] = p1;
	quad[2] = p2;
	quad[3] = p3;
	layer = l;
}

void AAQuad::drawQuad(Graphics* graphics, Pen* pen, Brush* b0, int layers)
{
	if (layer <= layers)
	{
		graphics->FillPolygon(b0, quad, 4);
		graphics->DrawPolygon(pen, quad, 4);
	}
}

AABox6::AABox6(const char* def)
	:AABox(def)
{
	layer = 0;
}

AABox6::~AABox6()
{

}

void AABox6::config(PointF p0, PointF p1, PointF p2, PointF p3, PointF p4, PointF p5, RectF& b0, RectF& b1, int l)
{
	box6[0] = p0;
	box6[1] = p1;
	box6[2] = p2;
	box6[3] = p3;
	box6[4] = p4;
	box6[5] = p5;

	box0 = b0;
	box1 = b1;

	layer = l;
}

void AABox6::drawBox6(Graphics* graphics, Pen* pen, Font* font, StringFormat* sf, Brush* b0, Brush* b1, int layers, bool rects)
{
	if (layer <= layers)
	{
		graphics->FillPolygon(b1, box6, 6);
		graphics->DrawPolygon(pen, box6, 6);

		if (rects)
		{
			graphics->FillRectangle(b1, box0);
			graphics->FillRectangle(b1, box1);
			graphics->DrawRectangle(pen, box0);
			graphics->DrawRectangle(pen, box1);
			graphics->DrawString(defaultText, -1, font, box0, sf, b0);
			graphics->DrawString(defaultText, -1, font, box1, sf, b0);
		}
	}
}