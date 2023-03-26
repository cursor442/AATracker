#include "AA_Tracker.h"

int Game::screenResX;
int Game::screenResY;

WCHAR     Game::szTitle[MAX_LOADSTRING];       
WCHAR     Game::szWindowClass[MAX_LOADSTRING]; 
HINSTANCE Game::hInst;                     
ULONG_PTR Game::gdiplusToken;

UINT Game::whichScreen = MAIN_SCREEN;
UINT Game::purchaseTab;
UINT Game::ukTab;
UINT Game::whichTab;                       
UINT Game::lastScreen = MAIN_SCREEN;
bool Game::success = false;
int  Game::price;
int  Game::captureAmount = 0;
bool Game::lockPhase = false;

// Research and bonus variables
int Game::numResDice[2] = {0, 0};
int Game::currResDie = 0;
int Game::bondAmount;

// Nation screen graphics switches
int Game::nsSection = ALL_SECT;
int Game::nsPhase = ALL_PHASE;
int Game::nsCity;       
int Game::nsUnit = PURCH_TITLE;
int Game::nsNeut = NEUT_ALL;
int Game::nsTurn = SPREAD_ALL_ROWS;
int Game::nsCol = SPREAD_ALL_COLS;
int Game::nsWC = WC_ALL;
int Game::nsBonusRow = BONS_ALL;

// Nation screen graphics toggles
bool Game::nsUKToggle = false;
bool Game::warchestRotate = false;

// Graph screen graphics switches
int Game::updateNatGraph = 10;

bool Game::whichUpdateNatGraph = false;
bool Game::doUpdateGraph = false;

// Buttons
bool Game::buttonClick = false;
bool Game::newButtonClick = false;
bool Game::buttonClicked = false;
bool Game::newButtonClicked = false;
bool Game::newButtonUnclicked = false;
int  Game::currButton = BB_ID_NULL;

// Tooltips
bool Game::activeTooltip = false;
bool Game::deactivateTooltip = false;

// Debug
bool Game::dbg_boundbox = false;
int  Game::dbg_layers = 99;
bool Game::dbg_sections = false;
int  Game::dbg_grid = 0;

// Tabs
HWND Game::nationScreenTabs = NULL;
HWND Game::purchaseSectionTabs = NULL;
HWND Game::ukEconomyTabs = NULL;
HWND Game::logScreenTabs = NULL;

// Gameboard
Board* Game::gameBoard = new Board;

///////////////////////////////////////////////////////////////////////////
// Graphics
///////////////////////////////////////////////////////////////////////////
Graphics*   Game::graphics = NULL;
AAGraphics* Game::gfx = NULL;

// Debug
DebugGrid* Game::debugGrid = NULL;

// Main window
HWND   Game::main_Wnd;

// Main menu
HMENU  Game::main_Menu;

// Current font, brush, etc.
HFONT  Game::hFont;
HBRUSH Game::hBrush;
HBRUSH Game::hBrushP;
HBRUSH Game::hBrushS;
bool   Game::currBrush = true;
HPEN   Game::hPen;

///////////////////////////////////////////////////////////////////////////
//// Graphics (Many to be removed)
///////////////////////////////////////////////////////////////////////////

// Pens
HPEN Game::borderless = CreatePen(PS_NULL, 0, RGB(0, 0, 0));
HPEN Game::bordered   = CreatePen(PS_SOLID,  1, RGB(0, 0, 0));

/// Fonts
FontFamily* Game::calibriFamily = NULL;

// Fonts
Font* Game::logTextFont = NULL;
Font* Game::logTurnFont = NULL;

HFONT  Game::descrFont    = CreateFont(30, 0, 0, 0, FW_REGULAR, 0, 0, 0, 0, 0, 0, 2, 0, L"DESCR_FONT");
HFONT  Game::descrBFont   = CreateFont(30, 0, 0, 0, FW_BOLD,    0, 0, 0, 0, 0, 0, 2, 0, L"DESCRB_FONT");
HFONT  Game::normalFont   = CreateFont(20, 0, 0, 0, FW_REGULAR, 0, 0, 0, 0, 0, 0, 2, 0, L"NORM_FONT");
HFONT  Game::headerFont   = CreateFont(20, 0, 0, 0, FW_BOLD,    0, 0, 0, 0, 0, 0, 2, 0, L"HEAD_FONT");

/// Brushes
HBRUSH Game::backBrush0;

HBRUSH Game::gerBrushP = CreateSolidBrush(RGB(77,  93,  83));  // 95,  95,  95
HBRUSH Game::gerBrushS = CreateSolidBrush(RGB(109, 122, 114)); // 124, 124, 124
HBRUSH Game::gerBrushF = CreateSolidBrush(RGB(223, 226, 224)); // 226, 226, 226
HBRUSH Game::sovBrushP = CreateSolidBrush(RGB(255, 26,  0));	  // 204, 51,  0
HBRUSH Game::sovBrushS = CreateSolidBrush(RGB(255, 68, 46));	  // 213, 88, 46
HBRUSH Game::sovBrushF = CreateSolidBrush(RGB(255, 213, 209)); // 246, 218, 209
HBRUSH Game::jpnBrushP = CreateSolidBrush(RGB(188, 0,   45));  // 204, 102, 0
HBRUSH Game::jpnBrushS = CreateSolidBrush(RGB(200, 46,  83));  // 213, 130, 46
HBRUSH Game::jpnBrushF = CreateSolidBrush(RGB(243, 209, 217)); // 246, 227, 209
HBRUSH Game::usaBrushP = CreateSolidBrush(RGB(107, 142, 35));  // 102, 153, 0
HBRUSH Game::usaBrushS = CreateSolidBrush(RGB(134, 163, 75));  // 130, 172, 46)
HBRUSH Game::usaBrushF = CreateSolidBrush(RGB(228, 234, 215)); // 227, 236, 209
HBRUSH Game::chnBrushP = CreateSolidBrush(RGB(0,   0,  149));  // 255, 0,   0
HBRUSH Game::chnBrushS = CreateSolidBrush(RGB(46,  46,  168)); // 255, 46,  46
HBRUSH Game::chnBrushF = CreateSolidBrush(RGB(209, 209, 236)); // 255, 209, 209
HBRUSH Game::ukBrushP  = CreateSolidBrush(RGB(240, 230, 140)); // 255, 204, 102
HBRUSH Game::ukBrushS  = CreateSolidBrush(RGB(243, 235, 161)); // 255, 213, 130
HBRUSH Game::ukBrushF  = CreateSolidBrush(RGB(252, 250, 234)); // 255, 246, 227
HBRUSH Game::itaBrushP = CreateSolidBrush(RGB(0,   140, 69));  // 102, 255, 51 
HBRUSH Game::itaBrushS = CreateSolidBrush(RGB(46,  161, 103)); // 130, 255, 88
HBRUSH Game::itaBrushF = CreateSolidBrush(RGB(209, 234, 221)); // 227, 255, 218
HBRUSH Game::anzBrushP = CreateSolidBrush(RGB(47,  87,  21));  // 0,   153, 0 
HBRUSH Game::anzBrushS = CreateSolidBrush(RGB(85,  118, 64));  // 46,  172, 46 
HBRUSH Game::anzBrushF = CreateSolidBrush(RGB(217, 224, 212)); // 209, 236, 209
HBRUSH Game::fraBrushP = CreateSolidBrush(RGB(0,   114, 187)); // 102, 204, 255
HBRUSH Game::fraBrushS = CreateSolidBrush(RGB(46,  140, 199)); // 130, 213, 255
HBRUSH Game::fraBrushF = CreateSolidBrush(RGB(209, 229, 243)); // 227, 246, 255

// Screen brushes
HBRUSH Game::tileBrush  = CreateSolidBrush(RGB(234, 234, 234));
HBRUSH Game::tileDBrush = CreateSolidBrush(RGB(191, 191, 191));

framesList Game::screenFrames;

///////////////////////////////////////////////////////////////////////////
//// Nation Screen
///////////////////////////////////////////////////////////////////////////

// Nation screen frames
RECT Game::nationScreenRect;
RECT Game::nationScreenWindow; // TEMP
RectF Game::nationScreenWindow0; // TEMP

// Name section
NameSection* Game::nameSection = NULL;
RectF Game::nameFrame;

// Turn phase section
PhaseSection* Game::phaseSection = NULL;
RectF Game::phaseFrame;

// War with section
WarSection* Game::warSection = NULL;
RectF Game::warFrame;

// Cities section
CitiesSection* Game::citiesSection = NULL;
RectF Game::cityFrame;
RectF Game::cityFrameL;
RectF Game::cityFrameR;

// Status section
StatusSection* Game::statusSection = NULL;
RectF Game::statusFrame;

// Turn phase buttons
int Game::nextPhaseButton = BB_ID_NULL;
int Game::researchButton = BB_ID_NULL;
int Game::declareWarButton = BB_ID_NULL;
int Game::captureTerritoryButton = BB_ID_NULL;
int Game::attackNeutralButton = BB_ID_NULL;
HWND Game::occupyNeutralButton = NULL;
HWND Game::attackMongoliaButton = NULL;
HWND Game::attackJapanButton = NULL;
HWND Game::attackSovietButton = NULL;

// Purchase section
PurchaseSection* Game::purchaseSection = NULL;
RectF Game::purchaseFrame;

// Mini spreadsheet
MiniSpreadSection* Game::miniSpreadSection = NULL;
RectF Game::miniSpreadFrame;

// United Kingdom Global Economy buttons
bool Game::currUKButton = false;
bool Game::currUKButtonToggled = false;

// Warchest section
WarchestSection* Game::warchestSection = NULL;
RectF Game::warchestFrame;

// Bonus section
BonusSection* Game::bonusSection = NULL;
RectF Game::bonusFrame;

// United Kingdom Global capture radio buttons
bool Game::captButtonUKE = false;
bool Game::captButtonUKP = false;

// Purchase tracking
Purchase Game::purchases[2];

// Neutral Territories
NeutralSection* Game::neutralSection = NULL;
RectF Game::neutralFrame;

// Bonus section
RECT Game::bonusHeadFrame;
RECT Game::bonusRestFrame;
RECT Game::bonus4Box[4][4];
RECT Game::bonus6Box[6][4];


///////////////////////////////////////////////////////////////////////////
//// Spreadsheet Screen
///////////////////////////////////////////////////////////////////////////

Spreadsheet* Game::nationSpreads[10] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

HWND Game::spreadAxis = NULL;
HWND Game::spreadAllies = NULL;

///////////////////////////////////////////////////////////////////////////
//// Graph Screen
///////////////////////////////////////////////////////////////////////////

Graph* Game::graphs[NUM_GRAPHS];
bool Game::graphConfigured = false;
HWND Game::graphSelect = NULL;
uint16_t Game::currGraph = BLNK_GRAPH;
uint16_t Game::currGraphNats = GRAPH_NON;
HWND Game::gerGraph = NULL;
HWND Game::sovGraph = NULL;
HWND Game::jpnGraph = NULL;
HWND Game::usaGraph = NULL;
HWND Game::chnGraph = NULL;
HWND Game::ukGraph = NULL;
HWND Game::itaGraph = NULL;
HWND Game::anzGraph = NULL;
HWND Game::fraGraph = NULL;

RECT Game::checkLines[9];
RECT Game::checkNations[9];

///////////////////////////////////////////////////////////////////////////
//// Log Screen
///////////////////////////////////////////////////////////////////////////
Log* Game::gameLog = NULL;
HWND Game::customLogButton = NULL;
int  Game::nextPage = 2;

//// Research screen
HWND Game::researchWnd = NULL;
HDC  Game::hdcCompat;

HBITMAP Game::resBack;
HBITMAP Game::gerIcon;
HBITMAP Game::gerIconMask;
HBITMAP Game::sovIcon;
HBITMAP Game::sovIconMask;
HBITMAP Game::jpnIcon;
HBITMAP Game::jpnIconMask;
HBITMAP Game::usaIcon;
HBITMAP Game::usaIconMask;
HBITMAP Game::chnIcon;
HBITMAP Game::chnIconMask;
HBITMAP Game::ukIcon;
HBITMAP Game::ukIconMask;
HBITMAP Game::itaIcon;
HBITMAP Game::itaIconMask;
HBITMAP Game::anzIcon;
HBITMAP Game::anzIconMask;
HBITMAP Game::fraIcon;
HBITMAP Game::fraIconMask;

BITMAP Game::bmpRes;
uint16_t Game::resIconPos[12][9][2];
vector<uint16_t> Game::resIconOrd[12];

// Misc
int Game::n = 0;
int Game::k = 0;
int Game::u;
vector<int> Game::saveNations[3] = { {TURN_GER, TURN_SOV, TURN_USA, TURN_UKE, TURN_ITA, TURN_FRA}, // Europe
	{TURN_JPN, TURN_USA, TURN_CHN, TURN_UKP, TURN_ANZ}, // Pacific
	{TURN_GER, TURN_SOV, TURN_JPN, TURN_USA, TURN_CHN,
	 TURN_UKE, TURN_UKP, TURN_ITA, TURN_ANZ, TURN_FRA} }; // Global
