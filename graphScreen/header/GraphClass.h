#ifndef GRAPH_CLASS
#define GRAPH_CLASS

#include "../../game/header/framework.h"
#include "../../board/header/BoardClass.h"
#include "../../graphics/header/UseGDI.h"

#define NUM_GRAPHS   9
#define TICK_WIDTH   5
#define AXISFONT_S   17
#define LABELFONT_S  20
#define TITLEFONT_S  30
#define BARFONT_S    12

#define LINE_GRAPH   1
#define BAR_GRAPH    2

#define BLNK_GRAPH   0
// Line graphs
#define BANK_GRAPH   1
#define INCM_GRAPH   2
#define BONS_GRAPH   3
#define TERR_GRAPH   4
#define S_INCM_GRAPH 5
#define S_TERR_GRAPH 6
#define CITY_GRAPH   7
// Bar graphs
#define UNIT_GRAPH   8

#define GRAPH_NON    0x0000
#define GRAPH_GER    0x0001
#define GRAPH_SOV    0x0002
#define GRAPH_JPN    0x0004
#define GRAPH_USA    0x0008
#define GRAPH_CHN    0x0010
#define GRAPH_UKE    0x0020
#define GRAPH_UKP    0x0040
#define GRAPH_ITA    0x0080
#define GRAPH_ANZ    0x0100
#define GRAPH_FRA    0x0200

class Graph
{
public:
	Graph(uint16_t, RECT, uint16_t);
	~Graph();

	void drawGraph(HDC, Board&, uint16_t);

	void rescaleAxes(Board&);
	bool rescaleBars(uint16_t);
	void drawFrame(Graphics&);
	void drawTicks(Graphics&);
	void drawLabels(Graphics&);
	void drawData(Graphics&, Board&, uint16_t);
	void updateGraph(HDC, uint16_t, bool, uint16_t);

private: 
	uint16_t whichGraph, type, gameType;
	uint16_t lastTurn, lastTurnNat, lastTurnPhase;
	uint16_t yMax, yLim, xMax, xLim;
	uint16_t yRes, xRes;
	float    yScale, xScale;
	uint16_t yNumTicks, xNumTicks;
	float    yTickScale, xTickScale;

	vector<uint16_t> gerDat, sovDat, jpnDat, usaDat,
		chnDat, ukeDat, ukpDat, itaDat, anzDat, fraDat;
	vector<uint16_t> axisIncm, alliesIncm,
					 axisTerr, alliesTerr;

	vector<uint16_t> saveNations[3], saveGraphs[3];
	uint16_t numBars;
	RectF* infBar[10], *artBar[10], *mechBar[10],
		*tankBar[10], *aaaBar[10], *fightBar[10],
		*tactBar[10], *stratBar[10], *battleBar[10],
		*airccBar[10], *cruiseBar[10], *destrBar[10],
		*subBar[10], *transBar[10];

	RectF* rectB[14];

	RECT graphPane;

	void configDrawTools();
	void configBars();

	FontFamily*  fontFamily;
	Font*        axisFont, *labelFont, *titleFont, *barFont;
	StringFormat stringFormat;
	SolidBrush*  textBrush;
	SolidBrush*  paneBrush, *backBrush;
	Pen         *gerBrushP, *gerBrushF,
				*sovBrushP, *sovBrushF,
				*jpnBrushP, *jpnBrushF,
		        *usaBrushP, *usaBrushF,
		        *chnBrushP, *chnBrushF,
		        *ukBrushP,  *ukBrushF,
		        *itaBrushP, *itaBrushF,
		        *anzBrushP, *anzBrushF,
		        *fraBrushP, *fraBrushF;
	Pen*         linePen, *borderlessPen;

	WCHAR uint2wchar(uint16_t);
	bool  isBeforeNation(uint16_t, uint16_t);
	Color selectBrush(uint16_t);
	void  eraseBars(Graphics&);

};

#endif
