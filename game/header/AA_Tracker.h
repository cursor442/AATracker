#ifndef AA_TRACKER_H
#define AA_TRACKER_H

#include "../../game/header/framework.h"
#include "../../game/header/Resource.h"
#include "../../graphics/header/GraphicsHeader.h"

#include "../../graphics/header/DebugGrid.h"

#include "../../nationScreen/screenSections/header/NameSection.h"
#include "../../nationScreen/screenSections/header/PhaseSection.h"
#include "../../nationScreen/screenSections/header/WarSection.h"
#include "../../nationScreen/screenSections/header/CitiesSection.h"
#include "../../nationScreen/screenSections/header/StatusSection.h"
#include "../../nationScreen/screenSections/header/PurchaseSection.h"
#include "../../nationScreen/screenSections/header/NeutralSection.h"
#include "../../nationScreen/screenSections/header/MiniSpreadSection.h"
#include "../../nationScreen/screenSections/header/WarchestSection.h"
#include "../../nationScreen/screenSections/header/BonusSection.h"

#include "../../board/header/Territories.h"
#include "../../nations/header/NationClass.h"
#include "../../spreadScreen/header/SpreadsheetClass.h"
#include "../../nationScreen/header/PurchaseClass.h"
#include "../../researchScreen/header/ResearchClass.h"
#include "../../graphScreen/header/GraphClass.h"
#include "../../logScreen/header/LogClass.h"

#define MAX_LOADSTRING 100

class Game
{
public:
	// Forward declarations of functions included in this code module:
	ATOM                MyRegisterClass(HINSTANCE hInstance);
	BOOL                InitInstance(HINSTANCE, int);

	///////////////////////////////////////////////////////////////////////////
	// Global Variables
	///////////////////////////////////////////////////////////////////////////

	WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
	WCHAR szWindowClass[MAX_LOADSTRING];            // The main window class name
	HINSTANCE hInst;                                // Current instance
	ULONG_PTR gdiplusToken;
	UINT whichScreen, purchaseTab, ukTab;           // The current screen, purchase, UK tabs
	UINT whichTab;                                  // Current log tab
	UINT lastScreen;                                // For clearing buttons
	bool success;
	int price;
	int captureAmount;
	bool lockPhase;                                 // For preventing "Next phase" button spam

	// Research and bonus variables
	int numResDice[2], currResDie, bondAmount;
	
	// Nation screen graphics switches
	int nsSection;     // Screen section to update
	int nsPhase;       // Buttons only option, etc.
	int nsCity;        // City box to update
	int nsUnit;        // Purchase unit to update
	int nsNeut;        // Neutral territories to update
	int nsTurn, nsCol; // Mini spread box to update
	int nsWC;          // Warchest box to update
	int nsBonusRow;    // Bonus box to update

	// Nation screen graphics toggles
	bool nsUKToggle;
	bool warchestRotate;

	// Graph screen graphics switches
	int updateNatGraph;

	bool whichUpdateNatGraph, doUpdateGraph;

	// Buttons
	void showButton(HWND&);
	void hideButton(HWND&);
	
	// Tooltips
	bool activeTooltip;              // The mouse has been hovering over a tooltip-enabled location for long enough
	bool deactivateTooltip;          // The mouse has moved off of the current tooltip-enabled location
	void drawTooltip(HWND&, LPARAM); // Draw the currently selected tooltip
	void hideTooltip(HWND&, LPARAM); // Hide the previously selected tooltip

	// Debug
	bool dbg_boundbox;
	int  dbg_layers;
	bool dbg_sections;
	int  dbg_grid;

	// Tabs
	HWND nationScreenTabs;
	HWND purchaseSectionTabs;
	HWND ukEconomyTabs;
	HWND logScreenTabs;

	// Gameboard
	Board* gameBoard;
	void deleteBoard();
	void resetBoard();

	// Callbacks
	INT_PTR CALLBACK NewGame(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam, Board& gameBoard);
	INT_PTR CALLBACK DeclareWar(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam, Board& gameBoard);
	INT_PTR CALLBACK CaptureTerritory(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	INT_PTR CALLBACK ResearchF(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	INT_PTR CALLBACK ResearchRes(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	INT_PTR CALLBACK ResearchUK(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	INT_PTR CALLBACK WarBonds(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	INT_PTR CALLBACK CustomLog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
	INT_PTR CALLBACK OccupyNeutral(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

	// Constructor and destructor
	Game();
	~Game();

	// Reset game to a known position
	void resetGameControls();

	// Save and load
	bool doSaveGame(HWND, Board&);
	void doLoadGame(HWND, Board&);

	void setMainWnd(HWND&);
	HWND getMainWnd();

	void hideScreen();

	///////////////////////////////////////////////////////////////////////////
	// Graphics
	///////////////////////////////////////////////////////////////////////////
	Graphics* graphics;
	AAGraphics* gfx;

	void configGraphics(HDC&);
	void configGameScreens();

	// GDI+
	void setupGDI();
	void destroyGDI();

	// Debug
	DebugGrid* debugGrid;
	void debugSwitches();

	///////////////////////////////////////////////////////////////////////////
	// Main screen
	///////////////////////////////////////////////////////////////////////////

	bool MainScreen(HDC&, PAINTSTRUCT&, Board&);

	///////////////////////////////////////////////////////////////////////////
	//// Nation screen
	///////////////////////////////////////////////////////////////////////////

	// Nation screen configuration
	void configNationScreen();

	// Nation screen draw
	bool NationScreen(HDC&, PAINTSTRUCT&);
	void hideNationScreen();
	void hideNationScreenPurchButtons();
	
	// Nation screen section updates
	void drawNameFrame(HDC&);
	void drawStatusFrame(HDC&);
	void drawPhaseFrame(HDC&);
	void drawPhaseFrameButtons();
	void drawWarFrame(HDC&);
	void drawCitiesFrame(HDC&);
	void drawPurchaseFrame(HDC&);
	void drawCombinedArms(HDC&); // Combined Arms reference
	void drawNeutralBox(HDC&); // Neutral territories status
	void drawPurchaseCostUpdate(HDC&);
	void drawMiniSpread(HDC&);
	void drawUKEconTabs(bool);
	void drawWarchestFrame(HDC&);
	void drawBonusFrame(HDC&);

	// Nation screen auxiliary functions
	void valConv(HDC&, RECT&, uint16_t);
	void ukConv(HDC&, RECT&, uint16_t, uint16_t);
	void purchConv(HDC&, RECT&, uint16_t);
	void bonusConv(HDC&, RECT&, uint16_t);
	void swapBrush(HDC&);
	void resetBrush(HDC&);
	int  getCityOwn(int, bool&);

	// Nation screen handlers
	void configSpread(Board&);
	bool nextTurnPhase(HWND& hWnd);
	void purchaseButton(HWND&, int);
	void loadMiniSpreads();
	void toggleUKDisp();

	// Nation screen purchase helpers
	void resetPurchases();
	void updatePurchases(uint16_t);
	void undoPurchases(uint16_t);
	bool calcPrice();

	///////////////////////////////////////////////////////////////////////////
	//// Spreadsheet screen
	///////////////////////////////////////////////////////////////////////////

	// Configure spreadsheet screen
	void configSpreadScreen();
	//void addSpreadRow(Board&);

	void initSpreadsheets();
	void loadSpreadsheets();
	void updateSpreadsheet(int, int);
	void updateSpreadsheet(int, int, bool);
	void updateSpreadsheet(int, int, int);

	// Draw spreadsheet screen
	bool SpreadScreen(HWND&, HDC&, PAINTSTRUCT&, bool);
	void hideSpreadScreen();
	void destroySpreadScreen();

	///////////////////////////////////////////////////////////////////////////
	//// Graph screen
	///////////////////////////////////////////////////////////////////////////

	void     configGraphScreen();
	void     GraphScreen(HDC&);
	uint16_t graphSelectHandler(UINT, WPARAM, LPARAM);
	uint16_t getCurrGraph();
	void     graphSelectNation(UINT, WPARAM, LPARAM, uint16_t);
	void     hideGraphScreen();
	void     destroyGraphScreen();

	///////////////////////////////////////////////////////////////////////////
	//// Log screen
	///////////////////////////////////////////////////////////////////////////

	void     configLogScreen();
	void     LogScreen(HDC&, UINT);
	void     addLogTab(int);
	void     hideLogScreen();
	void     destroyLogScreen();

	///////////////////////////////////////////////////////////////////////////
	//// Research screen
	///////////////////////////////////////////////////////////////////////////

	// Configure research screen
	void configResearchScreen();
	void addResearchIcon(uint16_t, uint16_t);

	// Handle research cost
	void researchButtonCost(HWND&);

	// Draw research screen
	bool ResearchScreen(HWND&, HDC&, PAINTSTRUCT&);
	void hideResearchScreen();

	HBITMAP CreateBitmapMask(HBITMAP, COLORREF);
	void    selectBitmap(uint16_t, bool);

private:
	// Main window
	HWND   main_Wnd;

	// Main menu
	HMENU  main_Menu;

	// Current font, brush, etc.
	HFONT  hFont;
	HBRUSH hBrush, hBrushP, hBrushS; 
	bool   currBrush;
	HPEN hPen;

	///////////////////////////////////////////////////////////////////////////
	//// Graphics
	///////////////////////////////////////////////////////////////////////////

	// Pens
	HPEN borderless, bordered;

	/// Fonts
	FontFamily* calibriFamily;

	// Fonts
	Font* logTextFont, * logTurnFont;
	
	HFONT  descrFont, descrBFont,
		normalFont,
		headerFont;

	/// Brushes
	HBRUSH backBrush0;

	HBRUSH gerBrushP, gerBrushS, gerBrushF,
		sovBrushP, sovBrushS, sovBrushF,
		jpnBrushP, jpnBrushS, jpnBrushF,
		usaBrushP, usaBrushS, usaBrushF,
		chnBrushP, chnBrushS, chnBrushF,
		ukBrushP,  ukBrushS,  ukBrushF,
		itaBrushP, itaBrushS, itaBrushF,
		anzBrushP, anzBrushS, anzBrushF,
		fraBrushP, fraBrushS, fraBrushF;

	// Screen brushes
	HBRUSH tileBrush, tileDBrush;

	framesList screenFrames;
		   
	///////////////////////////////////////////////////////////////////////////
	//// Nation Screen
	///////////////////////////////////////////////////////////////////////////

	// Nation screen frames
	RECT nationScreenRect;
	RECT nationScreenWindow; // TEMP
//	RectF nationScreenWindow;
	RectF nationScreenWindow0; // TEMP

	// Name section
	NameSection* nameSection;
	RectF nameFrame;

	// Turn phase section
	PhaseSection* phaseSection;
	RectF phaseFrame;

	// War with section
	WarSection* warSection;
	RectF warFrame;

	// Cities section
	CitiesSection* citiesSection;
	RectF cityFrame, cityFrameL, cityFrameR;

	// Status section
	StatusSection* statusSection;
	RectF statusFrame;

	// Turn phase buttons
	HWND nextPhaseButton, researchButton, declareWarButton,
		captureTerritoryButton, attackNeutralButton, occupyNeutralButton,
		attackMongoliaButton, attackJapanButton, attackSovietButton;

	// Purchase section
	PurchaseSection* purchaseSection;
	RectF purchaseFrame;

	// Mini spreadsheet
	MiniSpreadSection* miniSpreadSection;
	RectF miniSpreadFrame;

	// United Kingdom Global Economy buttons
	bool currUKButton, currUKButtonToggled;

	// Warchest section
	WarchestSection* warchestSection;
	RectF warchestFrame;

	// Bonus section
	BonusSection* bonusSection;
	RectF bonusFrame;

	// United Kingdom Global capture radio buttons
	bool captButtonUKE, captButtonUKP;

	// Purchase tracking
	Purchase purchases[2];

	// Neutral Territories
	NeutralSection* neutralSection;
	RectF neutralFrame;

	// Bonus section
	RECT bonusHeadFrame, bonusRestFrame;
	RECT bonus4Box[4][4];
	RECT bonus6Box[6][4];
	

	///////////////////////////////////////////////////////////////////////////
	//// Spreadsheet Screen
	///////////////////////////////////////////////////////////////////////////

	Spreadsheet* nationSpreads[10];

	HWND spreadAxis, spreadAllies;

	///////////////////////////////////////////////////////////////////////////
	//// Graph Screen
	///////////////////////////////////////////////////////////////////////////

	Graph* graphs[NUM_GRAPHS];
	bool graphConfigured;
	HWND graphSelect;
	uint16_t currGraph, currGraphNats;
	HWND gerGraph, sovGraph, jpnGraph, usaGraph, chnGraph,
		ukGraph, itaGraph, anzGraph, fraGraph;
	RECT checkLines[9], checkNations[9];

	//// Log screen
	Log* gameLog;
	HWND customLogButton;
	int nextPage;

	//// Research screen
	HWND researchWnd;
	HDC hdcCompat;

	HBITMAP resBack;
	HBITMAP gerIcon, gerIconMask;
	HBITMAP sovIcon, sovIconMask;
	HBITMAP jpnIcon, jpnIconMask;
	HBITMAP usaIcon, usaIconMask;
	HBITMAP chnIcon, chnIconMask;
	HBITMAP ukIcon, ukIconMask;
	HBITMAP itaIcon, itaIconMask;
	HBITMAP anzIcon, anzIconMask;
	HBITMAP fraIcon, fraIconMask;

	BITMAP bmpRes;
	uint16_t resIconPos[12][9][2];
	vector<uint16_t> resIconOrd[12];
	
	// Misc
	int n, k, u;
	vector<int> saveNations[3];

};

#endif

