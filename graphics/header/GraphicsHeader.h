#ifndef AA_GRAPHICS
#define AA_GRAPHICS

#include "../../game/header/framework.h"
#include "UseGDI.h"

#include "GraphicsObjects.h"
#include "../../logScreen/header/LogText.h"
#include "AATooltips.h"
#include "AAButtons.h"
#include "AATabs.h"

#define MAX_RES_X      1920
#define MAX_RES_Y      1080

#define GRAY_MAX       256

#define FONT12_S        12
#define FONT14_S        14
#define FONT16_S        16
#define FONT17_S        17
#define FONT18_S        18
#define FONT20_S        20
#define FONT24_S        24
#define FONT28_S        28
#define FONT32_S        32
#define FONT64_S        64

#define TURNFONT_S      16
#define TEXTFONT_S      12

#define NAMEFONT_S      65

class AAGraphics
{
public:
	AAGraphics(HWND, RectF);
	~AAGraphics();

	void config(HDC&);

	///////////////////////////////////////////////////////////////////////////
	//// Colors
	///////////////////////////////////////////////////////////////////////////

	Color* clearColor;
	Color* blackColor, * whiteColor, * redColor;
	Color* backColor, * paneColor;

	Color* gerColorP, * gerColorS, * gerColorF,
		* sovColorP, * sovColorS, * sovColorF,
		* jpnColorP, * jpnColorS, * jpnColorF,
		* usaColorP, * usaColorS, * usaColorF,
		* chnColorP, * chnColorS, * chnColorF,
		* ukColorP,  * ukColorS,  * ukColorF,
		* itaColorP, * itaColorS, * itaColorF,
		* anzColorP, * anzColorS, * anzColorF,
		* fraColorP, * fraColorS, * fraColorF;

	Color* neutColorB, * neutColorH;

	vector<Color*> grayColors;

	///////////////////////////////////////////////////////////////////////////
	//// Pens
	///////////////////////////////////////////////////////////////////////////

	Pen* borderlessPen;
	Pen* blackPen1, * blackPen2, * blackPen4;
	Pen* backPen;

	// Grayscale
	vector<Pen*> grayPens;

	///////////////////////////////////////////////////////////////////////////
	//// Fonts
	///////////////////////////////////////////////////////////////////////////

	FontFamily* calibriFamily;
	FontFamily* calibriLightFamily;

	// Formats
	StringFormat* logTextFormat, * leftCenterFormat, * centerFormat,
		* leftTopFormat, * leftBottomFormat, * purchaseFormat,
		* vertLeftCenterFormat, * vertRightCenterFormat;

	// Fonts
	Font* font12, * font12_b;
	Font* font14, * font14_b;
	Font* font16, * font16_b, * font16_bl;
	Font* font17;
	Font* font18, * font18_b, * font18_l,  * font18_bl;
	Font* font20, * font20_b, * font20_bl;
	Font* font24, * font24_b;
	Font* font28;
	Font* font32;
	Font* font64_b;

	///////////////////////////////////////////////////////////////////////////
	//// Brushes
	///////////////////////////////////////////////////////////////////////////

	SolidBrush* textBrush, * paneBrush, * backBrush;
	SolidBrush* tileBrushL, * tileBrushD;
	SolidBrush* whiteBrush, * redBrush;
	SolidBrush* clearBrush;

	// Turn phase brushes
	SolidBrush* resBrushP, * purchBrushP, * cmBrushP,
		* ccBrushP, * ncBrushP, * mobBrushP, * incBrushP;
	SolidBrush* resBrushS, * purchBrushS, * cmBrushS,
		* ccBrushS, * ncBrushS, * mobBrushS, * incBrushS;

	// Nation brushes
	SolidBrush* gerBrushP, * gerBrushS, * gerBrushF,
		* sovBrushP, * sovBrushS, * sovBrushF,
		* jpnBrushP, * jpnBrushS, * jpnBrushF,
		* usaBrushP, * usaBrushS, * usaBrushF,
		* chnBrushP, * chnBrushS, * chnBrushF,
		* ukBrushP, * ukBrushS, * ukBrushF,
		* itaBrushP, * itaBrushS, * itaBrushF,
		* anzBrushP, * anzBrushS, * anzBrushF,
		* fraBrushP, * fraBrushS, * fraBrushF;

	// Neutral brushes
	HatchBrush* neutBrush, * axisBrush, * allyBrush;

	// Grayscale
	vector<SolidBrush*> grayBrushes;

	///////////////////////////////////////////////////////////////////////////
	//// Tabs
	///////////////////////////////////////////////////////////////////////////

	AATabs* tabs;

	///////////////////////////////////////////////////////////////////////////
	//// Buttons
	///////////////////////////////////////////////////////////////////////////

	AAButtons* buttons;

	///////////////////////////////////////////////////////////////////////////
	//// Tooltips
	///////////////////////////////////////////////////////////////////////////

	AATooltips* tooltips;
};

#endif // !AA_GRAPHICS