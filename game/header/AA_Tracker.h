#ifndef AA_TRACKER_H
#define AA_TRACKER_H

#include "../../game/header/framework.h"
#include "../../game/header/Resource.h"
#include "../../graphics/header/GraphicsHeader.h"

#include "../../graphics/header/DebugGrid.h"

// Nation Screen
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

// Log Screen
#include "../../logScreen/screenSections/header/LogSection.h"

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

	static int screenResX;                                 // The resolution of the current monitor
	static int screenResY;

	static WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
	static WCHAR szWindowClass[MAX_LOADSTRING];            // The main window class name
	static HINSTANCE hInst;                                // Current instance
	static ULONG_PTR gdiplusToken;
	static int  whichScreen;                               // The current screen
	static int  lastScreen;                                // For clearing buttons
	static bool success;
	static int price;
	static int captureAmount;
	static bool lockPhase;                                 // For preventing "Next phase" button spam

	// Research and bonus variables
	static int numResDice[2], currResDie, bondAmount;

	// Graph screen graphics switches
	static int updateNatGraph;

	static bool whichUpdateNatGraph, doUpdateGraph;

	// Tabs
	static bool tabClick;                     // The mouse has clicked on an active tab
	static int  currTab;                      // The ID of the current tab selected
	static int  currTabIdx;                   // The selected index of the current tab
	static void showTabBar(int);              // Draw the currently selected tab bar 
	static void hideTabBar(int);              // Draw the currently selected tab bar 
	
	// Buttons
	static bool buttonClick;                  // The mouse has clicked on an active button
	static bool newButtonClick;               // The mouse has clicked on an active button that is different than the last button click
	static bool buttonClicked;                // The mouse is currently clicked and held on an active button
	static bool newButtonClicked;             // The mouse is currently clicked and held on an active button that is different from the initial click 
	static bool newButtonUnclicked;           // The mouse is currently held on an active button that is different from the initial click
	static int  currButton;                   // The ID of the current button selected
	static void showButton(int, bool = true); // Draw the currently selected button
	static void hideButton(int, bool = true); // Hide the currently selected button
	static void hideButtonNoDraw(int);        // Hide the currently selected button without drawing over it
	
	// Tooltips
	static bool activeTooltip;              // The mouse has been hovering over a tooltip-enabled location for long enough
	static bool deactivateTooltip;          // The mouse has moved off of the current tooltip-enabled location
	static void drawTooltip(HWND&, LPARAM); // Draw the currently selected tooltip
	static void hideTooltip(HWND&, LPARAM); // Hide the previously selected tooltip

	// Debug
	static bool dbg_boundbox;
	static int  dbg_layers;
	static bool dbg_sections;
	static int  dbg_grid;

	// Tabs
	static int  nationScreenTabs;
	static int  purchaseSectionTabs;
	static int  ukEconomyTabs;
	static int  logScreenTabs;

	// Gameboard
	static Board* gameBoard;
	static void deleteBoard();
	static void resetBoard();

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
	static void resetGameControls();

	// Save and load
	static bool doSaveGame(HWND, Board&);
	static void doLoadGame(HWND, Board&);

	static void setMainWnd(HWND&);
	static HWND getMainWnd();

	static void hideScreen(bool = false);

	///////////////////////////////////////////////////////////////////////////
	// Graphics
	///////////////////////////////////////////////////////////////////////////
	static Graphics* graphics;
	static AAGraphics* gfx;

	static void configGraphics(HDC&);
	static void configGameScreens();

	// GDI+
	static void setupGDI();
	static void destroyGDI();

	// Debug
	static DebugGrid*  debugGrid;
	static void debugSwitches();

	/////////////////////////////////////////////////////////////////////////
	// Mouse handlers
	/////////////////////////////////////////////////////////////////////////

	static void handleMouseLeftDown(HWND&, LPARAM);
	static void handleMouseLeftUp(HWND&, LPARAM);

	static void handleMouseMove(HWND&, LPARAM);

	static void handleMouseGraphicsSwitches(int);

	///////////////////////////////////////////////////////////////////////////
	// Main screen
	///////////////////////////////////////////////////////////////////////////

	static bool MainScreen(HDC&, PAINTSTRUCT&, Board&);

	///////////////////////////////////////////////////////////////////////////
	//// Nation screen
	///////////////////////////////////////////////////////////////////////////

	// Nation screen graphics switches
	static int nsSection;       // Screen section to update
	static int nsPhase;         // Buttons only option, etc.
	static int nsWar, nsWarTgt; // War box to update
	static int nsCity;          // City box to update
	static int nsUnit;          // Purchase unit to update
	static int nsNeut;          // Neutral territories to update
	static int nsTurn, nsCol;   // Mini spread box to update
	static int nsWC;            // Warchest box to update
	static int nsBonusRow;      // Bonus box to update

	static int purchaseTab;     // Current purchase section tab
	static int ukTab;           // Current UK economy tab

	// Nation screen graphics toggles
	static bool nsUKToggle;
	static bool warchestRotate;

	// Nation screen configuration
	static void configNationScreen();

	// Nation screen draw
	static bool NationScreen(HDC&, PAINTSTRUCT&);
	static void hideNationScreen();
	
	// Nation screen section updates
	static void drawNameFrame(HDC&);
	static void drawStatusFrame(HDC&);
	static void drawPhaseFrame(HDC&);
	static void drawPhaseFrameButtons(HDC&, bool = false);
	static void drawWarFrame(HDC&);
	static void drawCitiesFrame(HDC&);
	static void drawPurchaseFrame(HDC&);
	static void drawPurchaseFrameButtons(bool = false);
	static void drawPurchaseCostUpdate(HDC&);
	static void drawNeutralBox(HDC&); // Neutral territories status
	static void drawCombinedArms(HDC&); // Combined Arms reference
	static void drawMiniSpread(HDC&);
	static void drawUKEconTabs(bool);
	static void drawWarchestFrame(HDC&);
	static void drawBonusFrame(HDC&);

	static void hideNameFrame(bool = false);
	static void hideStatusFrame(bool = false);
	static void hidePhaseFrame(bool = false);
	static void hidePhaseFrameButtons();
	static void hideWarFrame(bool = false);
	static void hideCitiesFrame(bool = false);
	static void hidePurchaseFrame(bool = false);
	static void hidePurchaseFrameButtons();
	static void hideNeutralBox(bool = false);
	static void hideCombinedArms(bool = false);
	static void hideMiniSpread(bool = false);
	static void hideWarchestFrame(bool = false);
	static void hideBonusFrame(bool = false);

	// Nation screen auxiliary functions
	static void valConv(HDC&, RECT&, uint16_t);
	static void ukConv(HDC&, RECT&, uint16_t, uint16_t);
	static void purchConv(HDC&, RECT&, uint16_t);
	static void bonusConv(HDC&, RECT&, uint16_t);
	static void swapBrush(HDC&);
	static void resetBrush(HDC&);
	static int  getCityOwn(int, bool&);
	static int  getTerCity(int);

	// Nation screen handlers
	static void configSpread(Board&);
	static bool nextTurnPhase(HWND& hWnd);
	static void purchaseButton(HWND&, int);
	static void attackNeutralButtonHandler(HWND&);
	static void attackMongoliaButtonHandler(HWND&);
	static void loadMiniSpreads();
	static void toggleUKDisp();

	// Nation screen purchase helpers
	static void resetPurchases();
	static void updatePurchases(uint16_t);
	static void undoPurchases(uint16_t);
	static bool calcPrice();

	/////////////////////////////////////////////////////////////////////////
    // Nation screen tab handlers
	/////////////////////////////////////////////////////////////////////////

	static void nationScreenHandleMainScreenTab(HWND&);
	static void nationScreenHandleAxisSpreadScreenTab(HWND&);
	static void nationScreenHandleAlliesSpreadScreenTab(HWND&);
	static void nationScreenHandleGraphScreenTab(HWND&);
	static void nationScreenHandleLogScreenTab(HWND&);
	static void nationScreenHandleResearchScreenTab(HWND&);
	static void nationScreenHandleReferenceScreenTab(HWND&);

	static void nationScreenHandlePurchaseSectionTab(HWND&);
	static void nationScreenHandleNeutralSectionTab(HWND&);
	static void nationScreenHandleCombinedArmsSectionTab(HWND&);

	static void nationScreenHandleUKEconomyEuropeTab(HWND&);
	static void nationScreenHandleUKEconomyPacificTab(HWND&);

	/////////////////////////////////////////////////////////////////////////
	// Nation screen button handlers
	/////////////////////////////////////////////////////////////////////////

	static void nationScreenHandleNextPhase(HWND&);
	static void nationScreenHandleResearch(HWND&);
	static void nationScreenHandleDeclareWar(HWND&);
	static void nationScreenHandleCaptureTerritory(HWND&);
	static void nationScreenHandleAttackNeutral(HWND&);
	static void nationScreenHandleOccupyNeutral(HWND&);
	static void nationScreenHandleAttackMongolia(HWND&);
	static void nationScreenHandleAttackJapan(HWND&);
	static void nationScreenHandleAttackSoviet(HWND&);

	///////////////////////////////////////////////////////////////////////////
	//// Spreadsheet screen
	///////////////////////////////////////////////////////////////////////////

	// Configure spreadsheet screen
	static void configSpreadScreen();
	//static void addSpreadRow(Board&);

	static void initSpreadsheets();
	static void loadSpreadsheets();
	static void updateSpreadsheet(int, int);
	static void updateSpreadsheet(int, int, bool);
	static void updateSpreadsheet(int, int, int);

	// Draw spreadsheet screen
	static bool SpreadScreen(HWND&, HDC&, PAINTSTRUCT&, bool);
	static void hideSpreadScreen();
	static void destroySpreadScreen();

	///////////////////////////////////////////////////////////////////////////
	//// Graph screen
	///////////////////////////////////////////////////////////////////////////

	static void     configGraphScreen();
	static void     GraphScreen(HDC&);
	static uint16_t graphSelectHandler(UINT, WPARAM, LPARAM);
	static uint16_t getCurrGraph();
	static void     graphSelectNation(UINT, WPARAM, LPARAM, uint16_t);
	static void     hideGraphScreen();
	static void     destroyGraphScreen();

	///////////////////////////////////////////////////////////////////////////
	//// Log screen
	///////////////////////////////////////////////////////////////////////////

	// Log screen graphics switches
	static int whichLogTab; // Current log tab
	static int nextPage;	

	// Log screen graphics toggles

	// Log screen configuration
	static void     configLogScreen();

	// Log screen draw
	static void     LogScreen(HDC&, UINT);
	static void     hideLogScreen();

	// Log screen section updates

	// Log screen handlers
	static void     addLogTab(int);
	static void     destroyLogScreen(bool = true);

	/////////////////////////////////////////////////////////////////////////
	// Log screen tab handlers
	/////////////////////////////////////////////////////////////////////////

	static void logScreenHandlePageTab(HWND&, int);

	/////////////////////////////////////////////////////////////////////////
	// Log screen button handlers
	/////////////////////////////////////////////////////////////////////////

	static void logScreenHandleCustomEntry(HWND&);

	///////////////////////////////////////////////////////////////////////////
	//// Research screen
	///////////////////////////////////////////////////////////////////////////

	// Configure research screen
	static void configResearchScreen();
	static void addResearchIcon(uint16_t, uint16_t);

	// Handle research cost
	static void researchButtonCost(HWND&);

	// Draw research screen
	static bool ResearchScreen(HWND&, HDC&, PAINTSTRUCT&);
	static void hideResearchScreen();

	static HBITMAP CreateBitmapMask(HBITMAP, COLORREF);
	static void    selectBitmap(uint16_t, bool);

	///////////////////////////////////////////////////////////////////////////
	//// Reference screen
	///////////////////////////////////////////////////////////////////////////
	
	// Configure reference screen
	static void configReferenceScreen();

	// Draw reference screen
	static bool ReferenceScreen(HWND&, HDC&, PAINTSTRUCT&);
	static void hideReferenceScreen();


private:
	// Main window
	static HWND   main_Wnd;

	// Main menu
	static HMENU  main_Menu;

	// Current font, brush, etc.
	static HFONT  hFont;
	static HBRUSH hBrush, hBrushP, hBrushS; 
	static bool   currBrush;
	static HPEN hPen;

	///////////////////////////////////////////////////////////////////////////
	//// Graphics
	///////////////////////////////////////////////////////////////////////////

	// Pens
	static HPEN borderless, bordered;

	/// Fonts
	static FontFamily* calibriFamily;

	// Fonts
	static Font* logTextFont, * logTurnFont;
	
	static HFONT  descrFont, descrBFont,
		normalFont,
		headerFont;

	/// Brushes
	static HBRUSH backBrush0;

	static HBRUSH gerBrushP, gerBrushS, gerBrushF,
		sovBrushP, sovBrushS, sovBrushF,
		jpnBrushP, jpnBrushS, jpnBrushF,
		usaBrushP, usaBrushS, usaBrushF,
		chnBrushP, chnBrushS, chnBrushF,
		ukBrushP,  ukBrushS,  ukBrushF,
		itaBrushP, itaBrushS, itaBrushF,
		anzBrushP, anzBrushS, anzBrushF,
		fraBrushP, fraBrushS, fraBrushF;

	// Screen brushes
	static HBRUSH tileBrush, tileDBrush;

	static framesList screenFrames;
		   
	///////////////////////////////////////////////////////////////////////////
	//// Nation Screen
	///////////////////////////////////////////////////////////////////////////

	// Nation screen frames
	static RECT nationScreenRect;
	static RECT nationScreenWindow; // TEMP
//	static RectF nationScreenWindow;
	static RectF nationScreenWindow0; // TEMP

	// Name section
	static NameSection* nameSection;
	static RectF nameFrame;

	// Turn phase section
	static PhaseSection* phaseSection;
	static RectF phaseFrame;

	// War with section
	static WarSection* warSection;
	static RectF warFrame;

	// Cities section
	static CitiesSection* citiesSection;
	static RectF cityFrame, cityFrameL, cityFrameR;

	// Status section
	static StatusSection* statusSection;
	static RectF statusFrame;

	// Turn phase buttons
	static int nextPhaseButton, researchButton, declareWarButton,
		captureTerritoryButton, attackNeutralButton, occupyNeutralButton,
		attackMongoliaButton, attackJapanButton, attackSovietButton;

	// Purchase section
	static PurchaseSection* purchaseSection;
	static RectF purchaseFrame;

	// Mini spreadsheet
	static MiniSpreadSection* miniSpreadSection;
	static RectF miniSpreadFrame;

	// United Kingdom Global Economy buttons
	static bool currUKButton, currUKButtonToggled;

	// Warchest section
	static WarchestSection* warchestSection;
	static RectF warchestFrame;

	// Bonus section
	static BonusSection* bonusSection;
	static RectF bonusFrame;

	// United Kingdom Global capture radio buttons
	static bool captButtonUKE, captButtonUKP;

	// Purchase tracking
	static Purchase purchases[2];

	// Neutral Territories
	static NeutralSection* neutralSection;
	static RectF neutralFrame;

	// Bonus section
	static RECT bonusHeadFrame, bonusRestFrame;
	static RECT bonus4Box[4][4];
	static RECT bonus6Box[6][4];
	

	///////////////////////////////////////////////////////////////////////////
	//// Spreadsheet Screen
	///////////////////////////////////////////////////////////////////////////

	static Spreadsheet* nationSpreads[10];

	static HWND spreadAxis, spreadAllies;

	///////////////////////////////////////////////////////////////////////////
	//// Graph Screen
	///////////////////////////////////////////////////////////////////////////

	static Graph* graphs[NUM_GRAPHS];
	static bool graphConfigured;
	static HWND graphSelect;
	static uint16_t currGraph, currGraphNats;
	static HWND gerGraph, sovGraph, jpnGraph, usaGraph, chnGraph,
		ukGraph, itaGraph, anzGraph, fraGraph;
	static RECT checkLines[9], checkNations[9];

	///////////////////////////////////////////////////////////////////////////
	//// Log Screen
	///////////////////////////////////////////////////////////////////////////

	// Log sections
	static vector<LogSection*> logSections;
	static vector<RectF> logFrame;

	// Log buttons
	static int  customLogButton;
	
	// Log object
	static Log* gameLog;

	///////////////////////////////////////////////////////////////////////////
	//// Research Screen
	///////////////////////////////////////////////////////////////////////////

	static HWND researchWnd;
	static HDC hdcCompat;

	static HBITMAP resBack;
	static HBITMAP gerIcon, gerIconMask;
	static HBITMAP sovIcon, sovIconMask;
	static HBITMAP jpnIcon, jpnIconMask;
	static HBITMAP usaIcon, usaIconMask;
	static HBITMAP chnIcon, chnIconMask;
	static HBITMAP ukIcon, ukIconMask;
	static HBITMAP itaIcon, itaIconMask;
	static HBITMAP anzIcon, anzIconMask;
	static HBITMAP fraIcon, fraIconMask;

	static BITMAP bmpRes;
	static uint16_t resIconPos[12][9][2];
	static vector<uint16_t> resIconOrd[12];
	
	// Misc
	static int n, k, u;
	static vector<int> saveNations[3];

};

#endif

