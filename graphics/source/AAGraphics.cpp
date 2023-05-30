#include "../header/GraphicsHeader.h"

AAGraphics::AAGraphics(HWND hWnd, RectF rect)
{
	///////////////////////////////////////////////////////////////////////////
	//// Colors
	///////////////////////////////////////////////////////////////////////////

	clearColor = NULL;
	blackColor = NULL; whiteColor = NULL; redColor = NULL;
	backColor  = NULL; paneColor  = NULL;

	gerColorP = NULL; gerColorS = NULL; gerColorF = NULL;
	sovColorP = NULL; sovColorS = NULL; sovColorF = NULL;
	jpnColorP = NULL; jpnColorS = NULL; jpnColorF = NULL;
	usaColorP = NULL; usaColorS = NULL; usaColorF = NULL;
	chnColorP = NULL; chnColorS = NULL; chnColorF = NULL;
	ukColorP  = NULL; ukColorS  = NULL; ukColorF  = NULL;
	itaColorP = NULL; itaColorS = NULL; itaColorF = NULL;
	anzColorP = NULL; anzColorS = NULL; anzColorF = NULL;
	fraColorP = NULL; fraColorS = NULL; fraColorF = NULL;

	neutColorB = NULL; neutColorH = NULL;

	grayColors.resize(GRAY_MAX);
	for (int i = 0; i < GRAY_MAX; i++)
		grayColors[i] = NULL;

	///////////////////////////////////////////////////////////////////////////
	//// Pens
	///////////////////////////////////////////////////////////////////////////

	borderlessPen = NULL;
	blackPen1 = NULL; blackPen2 = NULL; blackPen4 = NULL;
	backPen = NULL;

	grayPens.resize(GRAY_MAX);
	for (int i = 0; i < GRAY_MAX; i++)
		grayPens[i] = NULL;

	///////////////////////////////////////////////////////////////////////////
	//// Fonts
	///////////////////////////////////////////////////////////////////////////

	calibriFamily = NULL;
	calibriLightFamily = NULL;

	logTextFormat = NULL; leftCenterFormat = NULL; centerFormat = NULL;
	leftTopFormat = NULL; leftBottomFormat = NULL; purchaseFormat = NULL;

	font12 = NULL; font12_b = NULL;
	font14 = NULL; font14_b = NULL;
	font16 = NULL; font16_b = NULL; font16_bl = NULL;
	font17 = NULL;
	font18 = NULL; font18_b = NULL; font18_l  = NULL; font18_bl = NULL;
	font20 = NULL; font20_b = NULL; font20_bl = NULL;
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

	// Neutral brushes
	neutBrush = NULL; axisBrush = NULL; allyBrush = NULL;

	grayBrushes.resize(GRAY_MAX);
	for (int i = 0; i < GRAY_MAX; i++)
		grayBrushes[i] = NULL;

	///////////////////////////////////////////////////////////////////////////
	//// Tabs
	///////////////////////////////////////////////////////////////////////////

	tabs = new AATabs(hWnd, rect);

	///////////////////////////////////////////////////////////////////////////
	//// Buttons
	///////////////////////////////////////////////////////////////////////////

	buttons = new AAButtons(hWnd, rect);

	///////////////////////////////////////////////////////////////////////////
	//// Tooltips
	///////////////////////////////////////////////////////////////////////////

	tooltips = new AATooltips(hWnd, rect);
}

AAGraphics::~AAGraphics()
{
	///////////////////////////////////////////////////////////////////////////
	//// Colors
	///////////////////////////////////////////////////////////////////////////

	delete clearColor;
	delete blackColor; delete whiteColor; delete redColor;
	delete backColor;  delete paneColor;

	delete gerColorP; delete gerColorS; delete gerColorF;
	delete sovColorP; delete sovColorS; delete sovColorF;
	delete jpnColorP; delete jpnColorS; delete jpnColorF;
	delete usaColorP; delete usaColorS; delete usaColorF;
	delete chnColorP; delete chnColorS; delete chnColorF;
	delete ukColorP ; delete ukColorS ; delete ukColorF ;
	delete itaColorP; delete itaColorS; delete itaColorF;
	delete anzColorP; delete anzColorS; delete anzColorF;
	delete fraColorP; delete fraColorS; delete fraColorF;

	delete neutColorB; delete neutColorH;

	for (int i = 0; i < GRAY_MAX; i++)
		delete grayColors[i];

	///////////////////////////////////////////////////////////////////////////
	//// Pens
	///////////////////////////////////////////////////////////////////////////

	delete borderlessPen;
	delete blackPen1; delete blackPen2; delete blackPen4;
	delete backPen;

	for (int i = 0; i < GRAY_MAX; i++)
		delete grayPens[i];
	
	///////////////////////////////////////////////////////////////////////////
	//// Fonts
	///////////////////////////////////////////////////////////////////////////

	delete calibriFamily;
	delete calibriLightFamily;

	delete logTextFormat; delete leftCenterFormat; delete centerFormat;
	delete leftTopFormat; delete leftBottomFormat; delete purchaseFormat;

	delete font12; delete font12_b;
	delete font14; delete font14_b;
	delete font16; delete font16_b; delete font16_bl;
	delete font17;
	delete font18; delete font18_b; delete font18_l;  delete font18_bl;
	delete font20; delete font20_b; delete font20_bl;
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

	// Neutral brushes
	delete neutBrush; delete axisBrush; delete allyBrush;

	for (int i = 0; i < GRAY_MAX; i++)
		delete grayBrushes[i];

	///////////////////////////////////////////////////////////////////////////
	//// Tabs
	///////////////////////////////////////////////////////////////////////////

	delete tabs;

	///////////////////////////////////////////////////////////////////////////
	//// Buttons
	///////////////////////////////////////////////////////////////////////////

	delete buttons;

	///////////////////////////////////////////////////////////////////////////
	//// Tooltips
	///////////////////////////////////////////////////////////////////////////

	delete tooltips;
}

void AAGraphics::config(HDC& hdc)
{
	///////////////////////////////////////////////////////////////////////////
	//// Colors
	///////////////////////////////////////////////////////////////////////////

	clearColor = new Color(0,   0,   0,   0  );
	blackColor = new Color(255, 0,   0,   0  );
	whiteColor = new Color(255, 255, 255);
	redColor   = new Color(255, 0,   0);
	backColor  = new Color(255, 240, 240, 240);
	paneColor  = new Color(212, 212, 212);

	gerColorP = new Color(77,  93,  83 );
	gerColorS = new Color(109, 122, 114);
	gerColorF = new Color(223, 226, 224);
	sovColorP = new Color(255, 26,  0  );
	sovColorS = new Color(255, 68,  46 );
	sovColorF = new Color(255, 213, 209);
	jpnColorP = new Color(188, 0,   45 );
	jpnColorS = new Color(200, 46,  83 );
	jpnColorF = new Color(243, 209, 217);
	usaColorP = new Color(107, 142, 35 );
	usaColorS = new Color(134, 163, 75 );
	usaColorF = new Color(228, 234, 215);
	chnColorP = new Color(0,   0,   149);
	chnColorS = new Color(46,  46,  168);
	chnColorF = new Color(209, 209, 236);
	ukColorP  = new Color(240, 230, 140);
	ukColorS  = new Color(243, 235, 161);
	ukColorF  = new Color(252, 250, 234);
	itaColorP = new Color(0,   140, 69 );
	itaColorS = new Color(46,  161, 103);
	itaColorF = new Color(209, 234, 221);
	anzColorP = new Color(47,  87,  21 );
	anzColorS = new Color(85,  118, 64 );
	anzColorF = new Color(217, 224, 212);
	fraColorP = new Color(0,   114, 187);
	fraColorS = new Color(46,  140, 199);
	fraColorF = new Color(209, 229, 243);

	neutColorB = new Color(190, 160, 120); 
	neutColorH = new Color(202, 176, 141);

	for (int i = 0; i < GRAY_MAX; i++)
		grayColors[i] = new Color(255, i, i, i);

	///////////////////////////////////////////////////////////////////////////
	//// Pens
	///////////////////////////////////////////////////////////////////////////

	borderlessPen = new Pen(*clearColor);
	blackPen1     = new Pen(*blackColor, 1);
	blackPen2     = new Pen(*blackColor, 2);
	blackPen4     = new Pen(*blackColor, 4);
	backPen       = new Pen(*backColor);

	// Grayscale
	for (int i = 0; i < GRAY_MAX; i++)
		grayPens[i] = new Pen(*grayColors[i]);

	///////////////////////////////////////////////////////////////////////////
	//// Fonts
	///////////////////////////////////////////////////////////////////////////

	REAL tabs0 = 20.0f;
	REAL tabs1[] = {212.0f, 48.0f, 60.0f, 76.0f, 72.0f, 88.0f};

	calibriFamily = new FontFamily(L"Calibri");
	calibriLightFamily = new FontFamily(L"Calibri Light");

	logTextFormat = new StringFormat();
	logTextFormat->SetAlignment(StringAlignmentNear);
	logTextFormat->SetLineAlignment(StringAlignmentNear);
	leftCenterFormat = new StringFormat();
	leftCenterFormat->SetAlignment(StringAlignmentNear);
	leftCenterFormat->SetLineAlignment(StringAlignmentCenter);
	leftBottomFormat = new StringFormat();
	leftBottomFormat->SetAlignment(StringAlignmentNear);
	leftBottomFormat->SetLineAlignment(StringAlignmentFar);
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

	HFONT* tmp_font16_bl = new HFONT(CreateFont(19, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, PROOF_QUALITY,
		VARIABLE_PITCH, L"Calibri Light"));
	HFONT* tmp_font17 = new HFONT(CreateFont(17, 0, 0, 0, FW_REGULAR, 0, 0, 0, 0, 0, 0, 2, 0, L"TMP_FONT17"));

	font12    = new Font(calibriFamily, FONT12_S, FontStyleRegular, UnitPixel);
	font12_b  = new Font(calibriFamily, FONT12_S, FontStyleBold, UnitPixel);
	font14    = new Font(calibriFamily, FONT14_S, FontStyleRegular, UnitPixel);
	font14_b  = new Font(calibriFamily, FONT14_S, FontStyleBold, UnitPixel);
	font16    = new Font(calibriFamily, FONT16_S, FontStyleRegular, UnitPixel);
	font16_b  = new Font(calibriFamily, FONT16_S, FontStyleBold, UnitPixel);
	//font16_bl = new Font(calibriLightFamily, FONT16_S, FontStyleBold, UnitPixel);
	font16_bl = new Font(hdc, *tmp_font16_bl);
	font17    = new Font(hdc, *tmp_font17);
	font18    = new Font(calibriFamily, FONT18_S, FontStyleRegular, UnitPixel);
	font18_b  = new Font(calibriFamily, FONT18_S, FontStyleBold, UnitPixel);
	font18_l  = new Font(calibriLightFamily, FONT16_S, FontStyleBold, UnitPixel);
	font18_bl = new Font(calibriLightFamily, FONT18_S, FontStyleBold, UnitPixel);
	font20    = new Font(calibriFamily, FONT20_S, FontStyleRegular, UnitPixel);
	font20_b  = new Font(calibriFamily, FONT20_S, FontStyleBold, UnitPixel);
	font20_bl = new Font(calibriLightFamily, FONT20_S, FontStyleBold, UnitPixel);
	font24    = new Font(calibriFamily, FONT24_S, FontStyleRegular, UnitPixel);
	font24_b  = new Font(calibriFamily, FONT24_S, FontStyleBold, UnitPixel);
	font28    = new Font(calibriFamily, FONT28_S, FontStyleRegular, UnitPixel);
	font32    = new Font(calibriFamily, FONT32_S, FontStyleRegular, UnitPixel);
	font64_b  = new Font(calibriFamily, FONT64_S, FontStyleBold, UnitPixel);

	//delete tmp_font16_bl;
	delete tmp_font17;

	///////////////////////////////////////////////////////////////////////////
	//// Brushes
	///////////////////////////////////////////////////////////////////////////

	textBrush  = new SolidBrush(*blackColor);
	paneBrush  = new SolidBrush(*paneColor);
	backBrush  = new SolidBrush(*backColor);
	tileBrushL = new SolidBrush(Color(234, 234, 234));
	tileBrushD = new SolidBrush(Color(191, 191, 191));
	whiteBrush = new SolidBrush(*whiteColor);
	redBrush   = new SolidBrush(*redColor);
	clearBrush = new SolidBrush(*clearColor);

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
	gerBrushP = new SolidBrush(*gerColorP);
	gerBrushS = new SolidBrush(*gerColorS);
	gerBrushF = new SolidBrush(*gerColorF);
	sovBrushP = new SolidBrush(*sovColorP);
	sovBrushS = new SolidBrush(*sovColorS);
	sovBrushF = new SolidBrush(*sovColorF);
	jpnBrushP = new SolidBrush(*jpnColorP);
	jpnBrushS = new SolidBrush(*jpnColorS);
	jpnBrushF = new SolidBrush(*jpnColorF);
	usaBrushP = new SolidBrush(*usaColorP);
	usaBrushS = new SolidBrush(*usaColorS);
	usaBrushF = new SolidBrush(*usaColorF);
	chnBrushP = new SolidBrush(*chnColorP);
	chnBrushS = new SolidBrush(*chnColorS);
	chnBrushF = new SolidBrush(*chnColorF);
	ukBrushP  = new SolidBrush(*ukColorP );
	ukBrushS  = new SolidBrush(*ukColorS );
	ukBrushF  = new SolidBrush(*ukColorF );
	itaBrushP = new SolidBrush(*itaColorP);
	itaBrushS = new SolidBrush(*itaColorS);
	itaBrushF = new SolidBrush(*itaColorF);
	anzBrushP = new SolidBrush(*anzColorP);
	anzBrushS = new SolidBrush(*anzColorS);
	anzBrushF = new SolidBrush(*anzColorF);
	fraBrushP = new SolidBrush(*fraColorP);
	fraBrushS = new SolidBrush(*fraColorS);
	fraBrushF = new SolidBrush(*fraColorF);

	// Neutral brushes
	neutBrush = new HatchBrush(HatchStyleVertical, *neutColorH, *neutColorB);
	axisBrush = new HatchBrush(HatchStyleBackwardDiagonal, *gerColorF, *gerColorS);
	allyBrush = new HatchBrush(HatchStyleForwardDiagonal, *ukColorF, *usaColorS);

	// Grayscale
	for (int i = 0; i < GRAY_MAX; i++)
		grayBrushes[i] = new SolidBrush(*grayColors[i]);

	///////////////////////////////////////////////////////////////////////////
	//// Tabs
	///////////////////////////////////////////////////////////////////////////

	tabs->configBaseDrawTools(blackPen1, borderlessPen, calibriFamily, leftBottomFormat, centerFormat,
		font18_l, textBrush, backBrush);
	tabs->configDrawTools(grayColors, grayBrushes, clearBrush, font18_bl, font16_bl);

	///////////////////////////////////////////////////////////////////////////
	//// Buttons
	///////////////////////////////////////////////////////////////////////////

	buttons->configBaseDrawTools(blackPen1, borderlessPen, calibriFamily, leftCenterFormat, centerFormat,
		font18_l, textBrush, backBrush);
	buttons->configDrawTools(grayColors, grayBrushes, clearBrush, font20_bl, font18_bl);

	///////////////////////////////////////////////////////////////////////////
	//// Tooltips
	///////////////////////////////////////////////////////////////////////////

	tooltips->configBaseDrawTools(blackPen1, borderlessPen, calibriFamily, leftCenterFormat, centerFormat,
		font16, textBrush, backBrush, paneBrush);
}
