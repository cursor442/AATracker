//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by AA Tracker.rc

#include "framework.h"

#ifndef AA_RESOURCE
#define AA_RESOURCE

///////////////////////////////////////////////////////////////////////////
//// Game Configuration (0-10)
///////////////////////////////////////////////////////////////////////////

#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif

#define IDR_MAINFRAME			0
#define IDS_APP_TITLE			1
#define IDC_MYICON				2
#define IDC_AATRACKER			3
#define IDI_AATRACKER			4
#define IDI_SMALL				5
#define IDD_AATRACKER_DIALOG	6

///////////////////////////////////////////////////////////////////////////
//// Game Menus (11-80)
///////////////////////////////////////////////////////////////////////////

// File (11-20)
#define IDM_NEWGAME             11
#define IDM_SAVEGAME            12
#define IDM_LOADGAME            13
#define IDM_EXIT				14

// Debug (21-40)
#define IDM_DBG_BOUNDBOX        21

#define IDM_DBG_GRID_OFF        22
#define IDM_DBG_GRID_DIV2       23
#define IDM_DBG_GRID_DIV3       24
#define IDM_DBG_GRID_DIV4       25
#define IDM_DBG_GRID_DIV5       26
#define IDM_DBG_GRID_DIV8       27

#define IDM_DBG_LAYERS_ALL      30
#define IDM_DBG_LAYERS_0        31
#define IDM_DBG_LAYERS_1        32
#define IDM_DBG_LAYERS_2        33
#define IDM_DBG_LAYERS_3        34

#define IDM_DBG_SECTIONS        40

// Help
#define IDM_ABOUT				41

///////////////////////////////////////////////////////////////////////////
//// Game Dialogues (81-120)
///////////////////////////////////////////////////////////////////////////

#define IDD_NEWGAMEBOX          81
#define IDD_ABOUTBOX			82

#define IDD_DECLAREWARBOX       83
#define IDD_CAPTUREBOX          84
#define IDD_UKCAPTUREBOX        85

#define IDD_RESEARCHBOX         86
#define IDD_RESEARCHRESBOX      87
#define IDD_UKRESEARCHBOX       88
#define IDD_WARBONDBOX          89
#define IDD_CUSTLOGBOX          90

///////////////////////////////////////////////////////////////////////////
//// Dialogue Fields (121-250)
///////////////////////////////////////////////////////////////////////////

//#define IDE_NEWGAMENAME         12X
#define IDC_NEWGAMETYPE         121
#define IDM_EUROPEGAME          122
#define IDM_PACIFICGAME         123
#define IDM_GLOBALGAME          124
#define IDM_SELECTGAME          125
#define IDC_RESEARCHGAME        126

#define IDC_DECLAREWAR          130
#define IDC_CAPTURETER          131
#define IDC_UKE_CAPTURESEL      132
#define IDC_UKP_CAPTURESEL      133

#define IDC_RESEARCHNUM         140
#define IDC_RESEARCHRESNUM      141
#define IDC_RESEARCHRES         142
#define IDC_UKRESEARCHSPLIT     143
#define IDC_WARBONDNUM          144

#define IDC_GRAPHSELECT         150

#define IDE_CUSTLOG             155

///////////////////////////////////////////////////////////////////////////
//// Action Buttons (251-500)
///////////////////////////////////////////////////////////////////////////

// Nation screen (251-325)
#define IDB_NEXTPHASE           251
#define IDB_DECLAREWAR          252
#define IDB_CAPTURETER          253
#define IDB_RESEARCH            254
#define IDB_RESEARCHGO          255

#define IDB_INFUP               270
#define IDB_INFDN               271
#define IDB_ARTUP               272
#define IDB_ARTDN               273
#define IDB_MECHUP              274
#define IDB_MECHDN              275
#define IDB_TANKUP              276
#define IDB_TANKDN              277
#define IDB_AAAUP               278
#define IDB_AAADN               279
#define IDB_FIGHTUP             280
#define IDB_FIGHTDN             281
#define IDB_TACTUP              282
#define IDB_TACTDN              283
#define IDB_STRATUP             284
#define IDB_STRATDN             285
#define IDB_BATTLEUP            286
#define IDB_BATTLEDN            287
#define IDB_AIRCCUP             288
#define IDB_AIRCCDN             289
#define IDB_CRUISEUP            290
#define IDB_CRUISEDN            291
#define IDB_DESTRUP             292
#define IDB_DESTRDN             293
#define IDB_SUBUP               294
#define IDB_SUBDN               295
#define IDB_TRANSUP             296
#define IDB_TRANSDN             297
#define IDB_MAJORUP             298
#define IDB_MAJORDN             299
#define IDB_MINORUP             300
#define IDB_MINORDN             301
#define IDB_MINORUPUP           302
#define IDB_MINORUPDN           303
#define IDB_AIRBUP              304
#define IDB_AIRBDN              305
#define IDB_NAVBUP              306
#define IDB_NAVBDN              307
#define IDB_REPAIRUP            308
#define IDB_REPAIRDN            309

// Graph screen (326-350)
#define IDB_GERGRAPH            326
#define IDB_SOVGRAPH            327
#define IDB_JPNGRAPH            328
#define IDB_USAGRAPH            329
#define IDB_CHNGRAPH            330
#define IDB_UKGRAPH             331
#define IDB_ITAGRAPH            332
#define IDB_ANZGRAPH            333
#define IDB_FRAGRAPH            334

// Log screen
#define IDB_CUSTLOG             351

///////////////////////////////////////////////////////////////////////////
//// Icons (900+)
///////////////////////////////////////////////////////////////////////////

#define IDI_RES                 900
#define IDI_GER                 901
#define IDI_SOV                 902
#define IDI_JPN                 903
#define IDI_USA                 904
#define IDI_CHN                 905
#define IDI_UK	                906
#define IDI_ITA	                907
#define IDI_ANZ	                908
#define IDI_FRA	                909

///////////////////////////////////////////////////////////////////////////
//// Game Tabs
///////////////////////////////////////////////////////////////////////////

#define TAB_MAIN                0
#define TAB_SPREAD_AXIS         1
#define TAB_SPREAD_ALLIES       2
#define TAB_GRAPH               3
#define TAB_LOG                 4
#define TAB_RESEARCH            5
#define TAB_REFERENCE           6

///////////////////////////////////////////////////////////////////////////
//// Purchase Section Tabs
///////////////////////////////////////////////////////////////////////////

#define TAB_PURCH               0
#define TAB_COMB                1
#define TAB_NEUTRAL             2

///////////////////////////////////////////////////////////////////////////
//// UK Global Tabs
///////////////////////////////////////////////////////////////////////////

#define TAB_UKE                 0
#define TAB_UKP                 1

///////////////////////////////////////////////////////////////////////////
//// Nation Screen Sections
///////////////////////////////////////////////////////////////////////////

#define NO_SECT       0x0000
#define NAME_SECT     0x0001
#define STAT_SECT     0x0002
#define PHASE_SECT    0x0004
#define WAR_SECT      0x0008
#define CITY_SECT     0x0010
#define CITY1_SECT    0x1000
#define PURCH_SECT    0x0020
#define SPREAD_SECT   0x0040
#define CHEST_SECT    0x0080
#define BONUS_SECT    0x0100
#define PURCHT_SECT   0x0200
#define ALL_SECT      0x1FFF

///////////////////////////////////////////////////////////////////////////
//// Game Types
///////////////////////////////////////////////////////////////////////////

#define NULL_GAME   -1
#define EUROPE_GAME  0
#define PACIFIC_GAME 1
#define GLOBAL_GAME  2

///////////////////////////////////////////////////////////////////////////
//// Turn Phases
///////////////////////////////////////////////////////////////////////////

#define RS_PHASE      0
#define PR_PHASE      1
#define CM_PHASE      2
#define CC_PHASE      3
#define NC_PHASE      4
#define MN_PHASE      5
#define CI_PHASE      6

///////////////////////////////////////////////////////////////////////////
//// Player Turns
///////////////////////////////////////////////////////////////////////////

#define TURN_NON     -1
#define TURN_GER      0
#define TURN_SOV      1
#define TURN_JPN      2
#define TURN_USA      3
#define TURN_CHN      4
#define TURN_UKE      5
#define TURN_UKP      6
#define TURN_ITA      7
#define TURN_ANZ      8
#define TURN_FRA      9

#define DUTCH_TER     10
#define FULL_NEUTRAL  11
#define AXIS_NEUTRAL  12
#define ALLY_NEUTRAL  13
#define MONGOLIA_TER  14

// UK economy config
#define UK_EUROPE     0
#define UK_PACIFIC    1

// Axis or Allies
#define SIDE_AXIS     0
#define SIDE_ALLIES   1
#define SIDE_NEUTRAL  2

///////////////////////////////////////////////////////////////////////////
//// Victory Conditions and Cities
///////////////////////////////////////////////////////////////////////////

#define VIC_AXIS_EUR   0
#define VIC_ALLIES_EUR 1
#define VIC_AXIS_PAC   2
#define VIC_ALLIES_PAC 3
#define VIC_AXIS_GLO   4
#define VIC_ALLIES_GLO 5

// Victory cities
#define CITY_NON     -1
#define CITY_BERLIN   0
#define CITY_ROME     1
#define CITY_WARSAW   2
#define CITY_OTTAWA   3
#define CITY_WASH     4
#define CITY_LONDON   5
#define CITY_PARIS    6
#define CITY_CAIRO    7
#define CITY_LENIN    8
#define CITY_MOSCOW   9
#define CITY_STALIN   10
#define CITY_SHANG    11
#define CITY_TOKYO    12
#define CITY_CALC     13
#define CITY_HONG     14
#define CITY_MANILA   15
#define CITY_SYDNEY   16
#define CITY_HONO     17
#define CITY_SANFRAN  18

///////////////////////////////////////////////////////////////////////////
//// Purchase Sections
///////////////////////////////////////////////////////////////////////////

#define PURCH_ALL            -1

#define PURCH_INF             0
#define PURCH_ART             1
#define PURCH_MECH            2
#define PURCH_TANK            3
#define PURCH_AAA             4
#define PURCH_FIGHT           5
#define PURCH_TACT            6
#define PURCH_STRAT           7
#define PURCH_BATTLE          8
#define PURCH_AIRCC           9
#define PURCH_CRUISE          10
#define PURCH_DESTR           11
#define PURCH_SUB             12
#define PURCH_TRANS           13
#define PURCH_MAJOR           14
#define PURCH_MINOR           15
#define PURCH_MINORUP         16
#define PURCH_AIRB            17
#define PURCH_NAVB            18
#define PURCH_REP             19
#define PURCH_TOT             20

#define PURCH_TITLE           21
#define PURCH_HEAD            22

///////////////////////////////////////////////////////////////////////////
//// Spreadsheet Configuration
///////////////////////////////////////////////////////////////////////////

#define TURN_POS         0
#define BANK_POS         1
#define INCM_POS         2
#define BONS_POS         3
#define PNLT_POS         4
#define XPNS_POS         5

#define SPREAD_COLS      6
#define SPREAD_ROWS      5
#define SPREAD_TEXTLEN   5

#define SPREAD_ALL_ROWS -1
#define SPREAD_ALL_COLS -1

#define NULL_VAL        -1

///////////////////////////////////////////////////////////////////////////
//// Warchest Nations to Update
///////////////////////////////////////////////////////////////////////////

#define WC_NON   0x0000
#define WC_GER   0x0001
#define WC_SOV   0x0002
#define WC_JPN   0x0004
#define WC_USA   0x0008
#define WC_CHN   0x0010
#define WC_UKE   0x0020
#define WC_UKP   0x0040
#define WC_ITA   0x0080
#define WC_ANZ   0x0100
#define WC_FRA   0x0200
#define WC_ALL   0x03FF

///////////////////////////////////////////////////////////////////////////
//// Bonus Section 
///////////////////////////////////////////////////////////////////////////

#define BONS_COLS  4

#define BONS_OBJ   0
#define BONS_CON   1
#define BONS_BNS   2
#define BONS_STS   3

#define BONS_ALL  -1
#define BONS_UPD   0

#define BONS_4     0
#define BONS_6     1

#define BONS_NON       -1

#define BONS_GER_SOV    0
#define BONS_GER_CTY    1
#define BONS_GER_CAU    2
#define BONS_GER_EGY    3
#define BONS_GER_DEN    4
#define BONS_GER_PER    5

#define BONS_SOV_SEA    0
#define BONS_SOV_AXT    1
#define BONS_SOV_GER    2

#define BONS_JPN_UKZ    0
#define BONS_JPN_ISL    1
#define BONS_JPN_TER    2
#define BONS_JPN_JAV    3

#define BONS_USA_USA        0
#define BONS_USA_EUR_TER    1

#define BONS_USA_PAC_TER    1
#define BONS_USA_PAC_ISL    2
#define BONS_USA_PHI        3
#define BONS_USA_PAC_WAR    4
							
#define BONS_USA_GLO_ISL    1
#define BONS_USA_GLO_TER    2
#define BONS_USA_GLO_FRA    4
#define BONS_USA_GLO_WAR    5

#define BONS_CHN_BUR    0  

#define BONS_UKE_TER     0    
#define BONS_UKP_TER     0    
#define BONS_UKP_GLO_TER 1

#define BONS_ITA_GIB   0
#define BONS_ITA_MED   1
#define BONS_ITA_AFR   2
#define BONS_ITA_PER   3

#define BONS_ANZ_TER   0
#define BONS_ANZ_ISL   1

#define BONS_FRA_LIB   0

///////////////////////////////////////////////////////////////////////////
//// Research Technologies
///////////////////////////////////////////////////////////////////////////

#define RES_FAILURE    0
#define RES_ARTILLERY  1
#define RES_ROCKETS	   2
#define RES_PARATROOP  3
#define RES_FACTORY	   4
#define RES_BONDS	   5
#define RES_MECH_INF   6
#define RES_SUBMARINES 7
#define RES_FIGHTERS   8
#define RES_SHIPYARDS  9
#define RES_RADAR	   10
#define RES_AIRCRAFT   11
#define RES_BOMBERS	   12

#define RESEARCH_COST  5




// Game phases (kinda useless but whatever)
#define CONFIG_PHASE  0
#define INIT_PHASE    1
#define PLAY_PHASE    2
#define CLEAN_PHASE   3

///////////////////////////////////////////////////////////////////////////
//// Useful functions
///////////////////////////////////////////////////////////////////////////

char* uint2char(uint16_t);
char  uint2char_(uint16_t);
char* int2char(int);
char  int2char_(int);
void  remZeros(char*, uint16_t);
uint16_t char2uint(char*, uint16_t);
uint16_t char2uint_(char);
int  char2int(char*, int);
int  char2int_(char);

bool isBeforeNation(uint16_t, uint16_t);
int  whichSide(int);

// Next default values for new objects
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif


#endif
