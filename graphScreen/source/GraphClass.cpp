#include "../header/GraphClass.h"

Graph::Graph(uint16_t graph, RECT graphRect, uint16_t gameType_)
{
	whichGraph = graph;
	gameType = gameType_;

	if (whichGraph == BLNK_GRAPH)
		type = BLNK_GRAPH;
	else if (whichGraph <= CITY_GRAPH)
		type = LINE_GRAPH;
	else
		type = BAR_GRAPH;

	gerDat.resize(0); sovDat.resize(0); jpnDat.resize(0);
	usaDat.resize(0); chnDat.resize(0); ukeDat.resize(0);
	ukpDat.resize(0); itaDat.resize(0); anzDat.resize(0); 
	fraDat.resize(0);

	axisIncm.resize(0); alliesIncm.resize(0);
	axisTerr.resize(0); alliesTerr.resize(0);

	lastTurn = 0; lastTurnNat = 0; lastTurnPhase = 0;
	yMax = 0; yLim = 0; xMax = 0; xLim = 0;
	yRes = 1; xRes = 1;
	yScale = 1; yNumTicks = 0; xScale = 1; xNumTicks = 0;
	yTickScale = 1; xTickScale = 1;

	graphPane = graphRect;
	
	configDrawTools();

	if (type == BAR_GRAPH)
		configBars();
}

Graph::~Graph()
{
	delete fontFamily;
	delete axisFont; delete labelFont; delete titleFont; delete barFont;

	delete gerBrushP; delete gerBrushF;
	delete sovBrushP; delete sovBrushF;
	delete jpnBrushP; delete jpnBrushF;
	delete usaBrushP; delete usaBrushF;
	delete chnBrushP; delete chnBrushF;
	delete ukBrushP;  delete ukBrushF;
	delete itaBrushP; delete itaBrushF;
	delete anzBrushP; delete anzBrushF;
	delete fraBrushP; delete fraBrushF;

	delete textBrush;

	delete paneBrush; delete backBrush;

	delete linePen; delete borderlessPen;

	for (uint16_t i = 0; i < 10; i++)
	{
		if (infBar[i] != NULL)
			delete infBar[i];
		if (infBar[i] != NULL)
			delete artBar[i];
		if (infBar[i] != NULL)
			delete mechBar[i];
		if (infBar[i] != NULL)
			delete tankBar[i];
		if (infBar[i] != NULL)
			delete aaaBar[i];
		if (infBar[i] != NULL)
			delete fightBar[i];
		if (infBar[i] != NULL)
			delete tactBar[i];
		if (infBar[i] != NULL)
			delete stratBar[i];
		if (infBar[i] != NULL)
			delete battleBar[i];
		if (infBar[i] != NULL)
			delete airccBar[i];
		if (infBar[i] != NULL)
			delete cruiseBar[i];
		if (infBar[i] != NULL)
			delete destrBar[i];
		if (infBar[i] != NULL)
			delete subBar[i];
		if (infBar[i] != NULL)
			delete transBar[i];
	}

	if (rectB[0] != NULL)
	{
		for (uint16_t i = 0; i < 14; i++)
			delete rectB[i];
	}
}

void Graph::configDrawTools()
{
	fontFamily = new FontFamily(L"Calibri");
	axisFont = new Font(fontFamily, AXISFONT_S, FontStyleRegular, UnitPixel);
	labelFont = new Font(fontFamily, LABELFONT_S, FontStyleBold, UnitPixel);
	titleFont = new Font(fontFamily, TITLEFONT_S, FontStyleBold, UnitPixel);
	barFont = new Font(fontFamily, BARFONT_S, FontStyleRegular, UnitPixel);

	gerBrushP = new Pen(Color(255, 77,  93,  83),  2);
	gerBrushF = new Pen(Color(196, 223, 226, 224), 2);
	sovBrushP = new Pen(Color(255, 255, 26,  0),   2);
	sovBrushF = new Pen(Color(196, 255, 213, 209), 2);
	jpnBrushP = new Pen(Color(255, 188, 0,   45),  2);
	jpnBrushF = new Pen(Color(196, 243, 209, 217), 2);
	usaBrushP = new Pen(Color(255, 107, 142, 35),  2);
	usaBrushF = new Pen(Color(196, 228, 234, 215), 2);
	chnBrushP = new Pen(Color(255, 0,   0,   149), 2);
	chnBrushF = new Pen(Color(196, 209, 209, 236), 2);
	ukBrushP =  new Pen(Color(255, 240, 230, 140), 2);
	ukBrushF =  new Pen(Color(196, 252, 250, 234), 2);
	itaBrushP = new Pen(Color(255, 0,   140, 69),  2);
	itaBrushF = new Pen(Color(196, 209, 234, 221), 2);
	anzBrushP = new Pen(Color(255, 47,  87,  21),  2);
	anzBrushF = new Pen(Color(196, 217, 224, 212), 2);
	fraBrushP = new Pen(Color(255, 0,   114, 187), 2);
	fraBrushF = new Pen(Color(196, 209, 229, 243), 2);

	textBrush = new SolidBrush(Color(255, 0, 0, 0));

	paneBrush = new SolidBrush(Color(212, 212, 212));
	backBrush = new SolidBrush(Color(240, 240, 240));

	linePen = new Pen(Color(255, 0, 0, 0));
	borderlessPen = new Pen(Color(0, 0, 0, 0));
}

void Graph::configBars()
{
	saveNations[0].resize(6); // Europe
	saveNations[0] = { TURN_GER, TURN_SOV, TURN_USA, TURN_UKE, TURN_ITA, TURN_FRA };
	saveNations[1].resize(5); // Pacific
	saveNations[1] = { TURN_JPN, TURN_USA, TURN_CHN, TURN_UKP, TURN_ANZ };
	saveNations[2].resize(10); // Global
	saveNations[2] = { TURN_GER, TURN_SOV, TURN_JPN, TURN_USA, TURN_CHN,
					   TURN_UKE, TURN_UKP, TURN_ITA, TURN_ANZ, TURN_FRA };
	saveGraphs[0].resize(6); // Europe
	saveGraphs[0] = { GRAPH_GER, GRAPH_SOV, GRAPH_USA, GRAPH_UKE, GRAPH_ITA, GRAPH_FRA };
	saveGraphs[1].resize(5); // Pacific
	saveGraphs[1] = { GRAPH_JPN, GRAPH_USA, GRAPH_CHN, GRAPH_UKP, GRAPH_ANZ };
	saveGraphs[2].resize(10); // Global
	saveGraphs[2] = { GRAPH_GER, GRAPH_SOV, GRAPH_JPN, GRAPH_USA, GRAPH_CHN,
					   GRAPH_UKE, GRAPH_UKP, GRAPH_ITA, GRAPH_ANZ, GRAPH_FRA };

	uint16_t idx = gameType - 114;

	// X axis
	xLim = 14;
	xScale = (float)(graphPane.right - graphPane.left) / (float)xLim;

	xNumTicks = 13;
	xTickScale = (float)(graphPane.right - graphPane.left) / (float)(14);

	if (gameType == EUROPE_GAME)
		numBars = 6;
	else if (gameType == PACIFIC_GAME)
		numBars = 5;
	else
		numBars = 10;

	for (uint16_t i = 0; i < saveNations[idx].size(); i++)
	{
		float offset = xTickScale / (float)numBars;
		float left = graphPane.left + (float)i * offset;
		float bottom = graphPane.bottom - 1;

		if (i == 0)
			infBar[i] = new RectF(left + 1, bottom, offset - 1, 1);
		else
			infBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		artBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		mechBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		tankBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		aaaBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		fightBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		tactBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		stratBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		battleBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		airccBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		cruiseBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		destrBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		subBar[i] = new RectF(left, bottom, offset, 1);
		left += xTickScale;
		transBar[i] = new RectF(left, bottom, offset, 1);
	}

	float diff = (float)(graphPane.right - graphPane.left - 2) / 14;
	float barLeft = (float)graphPane.left + 1;
	rectB[0] = new RectF(barLeft, graphPane.bottom + 1.3 * BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[1] = new RectF(barLeft + diff, graphPane.bottom + 1.3 * BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[2] = new RectF(barLeft + 2 * diff, graphPane.bottom + 1.4 * BARFONT_S, 1.1 * diff, 3.5 * BARFONT_S);
	rectB[3] = new RectF(barLeft + 3 * diff, graphPane.bottom + BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[4] = new RectF(barLeft + 4 * diff, graphPane.bottom + BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[5] = new RectF(barLeft + 5 * diff, graphPane.bottom + BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[6] = new RectF(barLeft + 6 * diff, graphPane.bottom + BARFONT_S, 1.1 * diff, 3.5 * BARFONT_S);
	rectB[7] = new RectF(barLeft + 7 * diff, graphPane.bottom + BARFONT_S, 1.1 * diff, 3.5 * BARFONT_S);
	rectB[8] = new RectF(barLeft + 8 * diff, graphPane.bottom + BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[9] = new RectF(barLeft + 9 * diff, graphPane.bottom + BARFONT_S, 1.1 * diff, 3.5 * BARFONT_S);
	rectB[10] = new RectF(barLeft + 10 * diff, graphPane.bottom + BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[11] = new RectF(barLeft + 11 * diff, graphPane.bottom + BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[12] = new RectF(barLeft + 12 * diff, graphPane.bottom + BARFONT_S, diff, 1.5 * BARFONT_S);
	rectB[13] = new RectF(barLeft + 13 * diff, graphPane.bottom + BARFONT_S, diff, 1.5 * BARFONT_S);
	
}

void Graph::drawGraph(HDC hdc, Board& gameBoard, uint16_t nats)
{
	Graphics graphics(hdc);

	if (whichGraph != BLNK_GRAPH)
	{
		lastTurn = gameBoard.getGameTurn();
		lastTurnNat = gameBoard.getGameCurrNation();
		lastTurnPhase = gameBoard.getGameTurnPhase();

		rescaleAxes(gameBoard);
		if (type == BAR_GRAPH)
			rescaleBars(nats);
		drawFrame(graphics);

		drawTicks(graphics);
		drawLabels(graphics);
		drawData(graphics, gameBoard, nats);
	}
	else
		drawFrame(graphics);
}

void Graph::rescaleAxes(Board& gameBoard)
{
	// Y axis

	if (type == LINE_GRAPH)
	{
		switch (whichGraph)
		{
		case BANK_GRAPH:
		{
			uint16_t set = usaDat.size();
			if (set != 0)
				set--;
			int len = lastTurn + 2;
			int lim = len - 1;

			if (gameType != PACIFIC_GAME)
			{
				// Germany
				gerDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					gerDat[i] = gameBoard.getNationBank(TURN_GER, i);
					if (gerDat[i] > yMax)
						yMax = gerDat[i];
				}
				// Soviet Union
				sovDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					sovDat[i] = gameBoard.getNationBank(TURN_SOV, i);
					if (sovDat[i] > yMax)
						yMax = sovDat[i];
				}
				// United Kingdom
				ukeDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					ukeDat[i] = gameBoard.getNationBank(TURN_UKE, i);
					if (ukeDat[i] > yMax)
						yMax = ukeDat[i];
				}
				// Italy
				itaDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					itaDat[i] = gameBoard.getNationBank(TURN_ITA, i);
					if (itaDat[i] > yMax)
						yMax = itaDat[i];
				}
				// France
				fraDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					fraDat[i] = gameBoard.getNationBank(TURN_FRA, i);
					if (fraDat[i] > yMax)
						yMax = fraDat[i];
				}
			}
			if (gameType != EUROPE_GAME)
			{
				// Japan
				jpnDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					jpnDat[i] = gameBoard.getNationBank(TURN_JPN, i);
					if (jpnDat[i] > yMax)
						yMax = jpnDat[i];
				}
				// China
				chnDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					chnDat[i] = gameBoard.getNationBank(TURN_CHN, i);
					if (chnDat[i]  > yMax)
						yMax = chnDat[i];
				}
				// United Kingdom
				ukpDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					ukpDat[i] = gameBoard.getNationBank(TURN_UKP, i);
					if (ukpDat[i] > yMax)
						yMax = ukpDat[i];
				}
				// ANZAC
				anzDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					anzDat[i] = gameBoard.getNationBank(TURN_ANZ, i);
					if (anzDat[i] > yMax)
						yMax = anzDat[i];
				}
			}

			// United States
			usaDat.resize(len);
			for (uint16_t i = set; i <= lim; i++)
			{
				usaDat[i] = gameBoard.getNationBank(TURN_USA, i);
				if (usaDat[i] > yMax)
					yMax = usaDat[i];
			}
		}
		break;
		case INCM_GRAPH:
		{
			if (usaDat.size() == 0)
			{
				if (gameType == EUROPE_GAME)
				{
					gerDat.resize(1); sovDat.resize(1); usaDat.resize(1);
					ukeDat.resize(1); itaDat.resize(1); fraDat.resize(1);
					gerDat[0] = 30; sovDat[0] = 28; usaDat[0] = 35;
					ukeDat[0] = 29; itaDat[0] = 10; fraDat[0] = 17;
				}
				else if (gameType == PACIFIC_GAME)
				{
					jpnDat.resize(1); usaDat.resize(1); chnDat.resize(1); 
					ukpDat.resize(1); anzDat.resize(1); 
					jpnDat[0] = 26; usaDat[0] = 17; chnDat[0] = 12;
					ukpDat[0] = 16; anzDat[0] = 10;
				}
				else
				{
					gerDat.resize(1); sovDat.resize(1); jpnDat.resize(1);
					usaDat.resize(1); chnDat.resize(1); ukeDat.resize(1);
					ukpDat.resize(1); itaDat.resize(1); anzDat.resize(1); fraDat.resize(1);
					gerDat[0] = 30; sovDat[0] = 37; jpnDat[0] = 26;
					usaDat[0] = 52; chnDat[0] = 12; ukeDat[0] = 28; 
					ukpDat[0] = 17; itaDat[0] = 10; anzDat[0] = 10; fraDat[0] = 19;
				}
			}

			uint16_t set = usaDat.size();
			if (set != 1)
				set--;
			int len = lastTurn + 2;
			int lim = len - 1;

			if (gameType != PACIFIC_GAME)
			{
				// Germany
				gerDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					gerDat[i] = gameBoard.getNationIncome(TURN_GER, i - 1);
					if (gerDat[i] > yMax)
						yMax = gerDat[i];
				}
				// Soviet Union
				sovDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					sovDat[i] = gameBoard.getNationIncome(TURN_SOV, i - 1);
					if (sovDat[i] > yMax)
						yMax = sovDat[i];
				}
				// United Kingdom
				ukeDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					ukeDat[i] = gameBoard.getNationIncome(TURN_UKE, i - 1);
					if (ukeDat[i] > yMax)
						yMax = ukeDat[i];
				}
				// Italy
				itaDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					itaDat[i] = gameBoard.getNationIncome(TURN_ITA, i - 1);
					if (itaDat[i] > yMax)
						yMax = itaDat[i];
				}
				// France
				fraDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					fraDat[i] = gameBoard.getNationIncome(TURN_FRA, i - 1);
					if (fraDat[i] > yMax)
						yMax = fraDat[i];
				}
			}
			if (gameType != EUROPE_GAME)
			{
				// Japan
				jpnDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					jpnDat[i] = gameBoard.getNationIncome(TURN_JPN, i - 1);
					if (jpnDat[i] > yMax)
						yMax = jpnDat[i];
				}
				// China
				chnDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					chnDat[i] = gameBoard.getNationIncome(TURN_CHN, i - 1);
					if (chnDat[i] > yMax)
						yMax = chnDat[i];
				}
				// United Kingdom
				ukpDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					ukpDat[i] = gameBoard.getNationIncome(TURN_UKP, i - 1);
					if (ukpDat[i] > yMax)
						yMax = ukpDat[i];
				}
				// ANZAC
				anzDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					anzDat[i] = gameBoard.getNationIncome(TURN_ANZ, i - 1);
					if (anzDat[i] > yMax)
						yMax = anzDat[i];
				}
			}

			// United States
			usaDat.resize(len);
			for (uint16_t i = set; i <= lim; i++)
			{
				usaDat[i] = gameBoard.getNationIncome(TURN_USA, i - 1);
				if (usaDat[i] > yMax)
					yMax = usaDat[i];
			}
		}
		break;
		case BONS_GRAPH:
		{
			if (usaDat.size() == 0)
			{
				if (gameType == EUROPE_GAME)
				{
					gerDat.resize(1); sovDat.resize(1); usaDat.resize(1);
					ukeDat.resize(1); itaDat.resize(1); fraDat.resize(1);
					gerDat[0] = 10; sovDat[0] = 0; usaDat[0] = 0;
					ukeDat[0] = 5; itaDat[0] = 0; fraDat[0] = 0;
				}
				else if (gameType == PACIFIC_GAME)
				{
					jpnDat.resize(1); usaDat.resize(1); chnDat.resize(1);
					ukpDat.resize(1); anzDat.resize(1);
					jpnDat[0] = 10; usaDat[0] = 0; chnDat[0] = 6;
					ukpDat[0] = 0; anzDat[0] = 0;
				}
				else
				{
					gerDat.resize(1); sovDat.resize(1); jpnDat.resize(1);
					usaDat.resize(1); chnDat.resize(1); ukeDat.resize(1);
					ukpDat.resize(1); itaDat.resize(1); anzDat.resize(1); fraDat.resize(1);
					gerDat[0] = 10; sovDat[0] = 0; jpnDat[0] = 10;
					usaDat[0] = 0; chnDat[0] = 6; ukeDat[0] = 5;
					ukpDat[0] = 0; itaDat[0] = 0; anzDat[0] = 0; fraDat[0] = 0;
				}
			}

			uint16_t set = usaDat.size();
			if (set != 1)
				set--;
			int len = lastTurn + 2;
			int lim = len - 1;

			if (gameType != PACIFIC_GAME)
			{
				// Germany
				gerDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					gerDat[i] = gameBoard.getNationBonus(TURN_GER, i - 1);
					if (gerDat[i] > yMax)
						yMax = gerDat[i];
				}
				// Soviet Union
				sovDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					sovDat[i] = gameBoard.getNationBonus(TURN_SOV, i - 1);
					if (sovDat[i] > yMax)
						yMax = sovDat[i];
				}
				// United Kingdom
				ukeDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					ukeDat[i] = gameBoard.getNationBonus(TURN_UKE, i - 1);
					if (ukeDat[i] > yMax)
						yMax = ukeDat[i];
				}
				// Italy
				itaDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					itaDat[i] = gameBoard.getNationBonus(TURN_ITA, i - 1);
					if (itaDat[i] > yMax)
						yMax = itaDat[i];
				}
				// France
				fraDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					fraDat[i] = gameBoard.getNationBonus(TURN_FRA, i - 1);
					if (fraDat[i] > yMax)
						yMax = fraDat[i];
				}
			}
			if (gameType != EUROPE_GAME)
			{
				// Japan
				jpnDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					jpnDat[i] = gameBoard.getNationBonus(TURN_JPN, i - 1);
					if (jpnDat[i] > yMax)
						yMax = jpnDat[i];
				}
				// China
				chnDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					chnDat[i] = gameBoard.getNationBonus(TURN_CHN, i - 1);
					if (chnDat[i] > yMax)
						yMax = chnDat[i];
				}
				// United Kingdom
				ukpDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					ukpDat[i] = gameBoard.getNationBonus(TURN_UKP, i - 1);
					if (ukpDat[i] > yMax)
						yMax = ukpDat[i];
				}
				// ANZAC
				anzDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					anzDat[i] = gameBoard.getNationBonus(TURN_ANZ, i - 1);
					if (anzDat[i] > yMax)
						yMax = anzDat[i];
				}
			}

			// United States
			usaDat.resize(len);
			for (uint16_t i = set; i <= lim; i++)
			{
				usaDat[i] = gameBoard.getNationBonus(TURN_USA, i - 1);
				if (usaDat[i] > yMax)
					yMax = usaDat[i];
			}
		}
		break;
		case TERR_GRAPH:
		{
			if (usaDat.size() == 0)
			{
				if (gameType == EUROPE_GAME)
				{
					gerDat.resize(1); sovDat.resize(1); usaDat.resize(1);
					ukeDat.resize(1); itaDat.resize(1); fraDat.resize(1);
					gerDat[0] = 9; sovDat[0] = 24; usaDat[0] = 5;
					ukeDat[0] = 26; itaDat[0] = 9; fraDat[0] = 12;
				}
				else if (gameType == PACIFIC_GAME)
				{
					jpnDat.resize(1); usaDat.resize(1); chnDat.resize(1);
					ukpDat.resize(1); anzDat.resize(1);
					jpnDat[0] = 17; usaDat[0] = 11; chnDat[0] = 12;
					ukpDat[0] = 11; anzDat[0] = 10;
				}
				else
				{
					gerDat.resize(1); sovDat.resize(1); jpnDat.resize(1);
					usaDat.resize(1); chnDat.resize(1); ukeDat.resize(1);
					ukpDat.resize(1); itaDat.resize(1); anzDat.resize(1); fraDat.resize(1);
					gerDat[0] = 9; sovDat[0] = 33; jpnDat[0] = 17;
					usaDat[0] = 16; chnDat[0] = 12; ukeDat[0] = 26;
					ukpDat[0] = 11; itaDat[0] = 9; anzDat[0] = 10; fraDat[0] = 14;
				}
			}

			uint16_t set = usaDat.size();
			if (set != 1)
				set--;
			int len = lastTurn + 2;
			int lim = len - 1;

			if (gameType != PACIFIC_GAME)
			{
				// Germany
				gerDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					gerDat[i] = gameBoard.getNationTerritories(TURN_GER, i - 1);
					if (gerDat[i] > yMax)
						yMax = gerDat[i];
				}
				// Soviet Union
				sovDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					sovDat[i] = gameBoard.getNationTerritories(TURN_SOV, i - 1);
					if (sovDat[i] > yMax)
						yMax = sovDat[i];
				}
				// United Kingdom
				ukeDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					ukeDat[i] = gameBoard.getNationTerritories(TURN_UKE, i - 1);
					if (ukeDat[i] > yMax)
						yMax = ukeDat[i];
				}
				// Italy
				itaDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					itaDat[i] = gameBoard.getNationTerritories(TURN_ITA, i - 1);
					if (itaDat[i] > yMax)
						yMax = itaDat[i];
				}
				// France
				fraDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					fraDat[i] = gameBoard.getNationTerritories(TURN_FRA, i - 1);
					if (fraDat[i] > yMax)
						yMax = fraDat[i];
				}
			}
			if (gameType != EUROPE_GAME)
			{
				// Japan
				jpnDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					jpnDat[i] = gameBoard.getNationTerritories(TURN_JPN, i - 1);
					if (jpnDat[i] > yMax)
						yMax = jpnDat[i];
				}
				// China
				chnDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					chnDat[i] = gameBoard.getNationTerritories(TURN_CHN, i - 1);
					if (chnDat[i] > yMax)
						yMax = chnDat[i];
				}
				// United Kingdom
				ukpDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					ukpDat[i] = gameBoard.getNationTerritories(TURN_UKP, i - 1);
					if (ukpDat[i] > yMax)
						yMax = ukpDat[i];
				}
				// ANZAC
				anzDat.resize(len);
				for (uint16_t i = set; i <= lim; i++)
				{
					anzDat[i] = gameBoard.getNationTerritories(TURN_ANZ, i - 1);
					if (anzDat[i] > yMax)
						yMax = anzDat[i];
				}
			}

			// United States
			usaDat.resize(len);
			for (uint16_t i = set; i <= lim; i++)
			{
				usaDat[i] = gameBoard.getNationTerritories(TURN_USA, i - 1);
				if (usaDat[i] > yMax)
					yMax = usaDat[i];
			}
		}
		break;
		case S_INCM_GRAPH:
		{
			if (axisIncm.size() == 0)
			{
				axisIncm.resize(1); alliesIncm.resize(1);

				if (gameType == EUROPE_GAME)
				{
					axisIncm[0] = 40;
					alliesIncm[0] = 109;
				}
				else if (gameType == PACIFIC_GAME)
				{
					axisIncm[0] = 26;
					alliesIncm[0] = 55;
				}
				else
				{
					axisIncm[0] = 66;
					alliesIncm[0] = 175;
				}
			}

			uint16_t set = axisIncm.size();
			if (set != 0)
				set--;
			int len = lastTurn + 2;
			int lim = len - 1;
			axisIncm.resize(len);
			alliesIncm.resize(len);

			if (set != 0)
			{
				axisIncm[set] = 0;
				alliesIncm[set] = 0;
			}
			for (uint16_t i = set; i <= lim; i++)
			{
				if (gameType != PACIFIC_GAME)
				{
					axisIncm[i] += gameBoard.getNationIncome(TURN_GER, i - 1);
					axisIncm[i] += gameBoard.getNationIncome(TURN_ITA, i - 1);
					alliesIncm[i] += gameBoard.getNationIncome(TURN_SOV, i - 1);
					alliesIncm[i] += gameBoard.getNationIncome(TURN_UKE, i - 1);
					alliesIncm[i] += gameBoard.getNationIncome(TURN_FRA, i - 1);
				}
				if (gameType != EUROPE_GAME)
				{
					axisIncm[i] += gameBoard.getNationIncome(TURN_JPN, i - 1);
					alliesIncm[i] += gameBoard.getNationIncome(TURN_CHN, i - 1);
					alliesIncm[i] += gameBoard.getNationIncome(TURN_UKP, i - 1);
					alliesIncm[i] += gameBoard.getNationIncome(TURN_ANZ, i - 1);
				}
				alliesIncm[i] += gameBoard.getNationIncome(TURN_USA, i - 1);
			}

			for (uint16_t i = set; i <= lim; i++)
			{
				if (axisIncm[i] > yMax)
					yMax = axisIncm[i];
				if (alliesIncm[i] > yMax)
					yMax = alliesIncm[i];
			}
		}
		break;
		case S_TERR_GRAPH:
		{
			if (axisIncm.size() == 0)
			{
				axisIncm.resize(1); alliesIncm.resize(1);

				if (gameType == EUROPE_GAME)
				{
					axisIncm[0] = 18;
					alliesIncm[0] = 67;
				}
				else if (gameType == PACIFIC_GAME)
				{
					axisIncm[0] = 17;
					alliesIncm[0] = 44;
				}
				else
				{
					axisIncm[0] = 35;
					alliesIncm[0] = 122;
				}
			}

			uint16_t set = axisIncm.size();
			if (set != 0)
				set--;
			int len = lastTurn + 2;
			int lim = len - 1;
			axisIncm.resize(len);
			alliesIncm.resize(len);

			if (set != 0)
			{
				axisIncm[set] = 0;
				alliesIncm[set] = 0;
			}
			for (uint16_t i = set; i <= lim; i++)
			{
				if (gameType != PACIFIC_GAME)
				{
					axisIncm[i] += gameBoard.getNationTerritories(TURN_GER, i - 1);
					axisIncm[i] += gameBoard.getNationTerritories(TURN_ITA, i - 1);
					alliesIncm[i] += gameBoard.getNationTerritories(TURN_SOV, i - 1);
					alliesIncm[i] += gameBoard.getNationTerritories(TURN_UKE, i - 1);
					alliesIncm[i] += gameBoard.getNationTerritories(TURN_FRA, i - 1);
				}
				if (gameType != EUROPE_GAME)
				{
					axisIncm[i] += gameBoard.getNationTerritories(TURN_JPN, i - 1);
					alliesIncm[i] += gameBoard.getNationTerritories(TURN_CHN, i - 1);
					alliesIncm[i] += gameBoard.getNationTerritories(TURN_UKP, i - 1);
					alliesIncm[i] += gameBoard.getNationTerritories(TURN_ANZ, i - 1);
				}
				alliesIncm[i] += gameBoard.getNationTerritories(TURN_USA, i - 1);
			}
				
			for (uint16_t i = set; i <= lim; i++)
			{
				if (axisIncm[i] > yMax)
					yMax = axisIncm[i];
				if (alliesIncm[i] > yMax)
					yMax = alliesIncm[i];
			}
		}
		break;
		case CITY_GRAPH:
		{
			uint16_t set = axisIncm.size();
			if (set != 0)
				set--;
			int len = lastTurn + 2;
			int lim = len - 1;
			axisIncm.resize(len);
			alliesIncm.resize(len);

			for (uint16_t i = set; i <= lim; i++)
			{
				axisIncm[i] = gameBoard.getNumVicCities(SIDE_AXIS, i);
				alliesIncm[i] = gameBoard.getNumVicCities(SIDE_ALLIES, i);
			}

			for (uint16_t i = set; i <= lim; i++)
			{
				if (axisIncm[i] > yMax)
					yMax = axisIncm[i];
				if (alliesIncm[i] > yMax)
					yMax = alliesIncm[i];
			}
		}
		break;
		default:
			break;
		}

		// X axis
		xMax = lastTurn;
		xLim = lastTurn + 1;

		xScale = (float)(graphPane.right - graphPane.left) / (float)xLim;

		if (xLim > 20)
		{
			xRes = (xLim / 20) * 2;
			if (xLim % 20 == 0)
				xLim--;

			xNumTicks = (xLim / xRes);
			if (xLim % xRes == 0)
				xNumTicks--;
		}
		else
		{
			xRes = 1;
			xNumTicks = xLim - 1;
			
		}

		xTickScale = (float)(graphPane.right - graphPane.left) / (float)(xLim);

		uint16_t right = xRes * xNumTicks;
		float rightTick = (float)(graphPane.left) + (float)((xLim - right) * xScale);
		xTickScale = (float)(graphPane.right - rightTick) / (float)(xNumTicks);

		// Want y axis to be next increment of 5 above max
		yLim = yMax + 5;
		yLim -= yMax % 5;

		yScale = (float)(graphPane.bottom - graphPane.top) / (float)yLim;

		if (yLim > 100)
		{
			yRes = ((yLim / 100) + 1) * 10;
			yNumTicks = yLim / yRes;
			if (yLim % yRes == 0)
				yNumTicks--;
		}
		else if (yLim <= 10 || whichGraph == CITY_GRAPH)
		{
			yRes = 1;
			yNumTicks = yLim - 1;
		}
		else
		{
			yRes = 10;
			yNumTicks = (yLim / 10) - 1;
			if (yLim % 10 != 0)
				yNumTicks++;
		}

		uint16_t top = yRes * yNumTicks;
		float topTick = (float)(graphPane.top) + (float)((yLim - top) * yScale);
		yTickScale = (float)(graphPane.bottom - topTick) / (float)(yNumTicks);
	}
	else if (type == BAR_GRAPH)
	{
		switch (whichGraph)
		{
		case UNIT_GRAPH:
		{
			uint16_t idx = gameType - 114;

			for (uint16_t i = 0; i < saveNations[idx].size(); i++)
			{
				uint16_t newVal = gameBoard.getPurchases(saveNations[idx][i], 0);
				if (newVal > yMax)
					yMax = newVal;
				infBar[i]->Y = newVal;

				newVal = gameBoard.getPurchases(saveNations[idx][i], 1);
				if (newVal > yMax)
					yMax = newVal;
				artBar[i]->Y = newVal;

				newVal = gameBoard.getPurchases(saveNations[idx][i], 2);
				if (newVal > yMax)
					yMax = newVal;
				mechBar[i]->Y = newVal;

				newVal = gameBoard.getPurchases(saveNations[idx][i], 3);
				if (newVal > yMax)
					yMax = newVal;
				tankBar[i]->Y = newVal;

				newVal = gameBoard.getPurchases(saveNations[idx][i], 4);
				if (newVal > yMax)
					yMax = newVal;
				aaaBar[i]->Y = newVal;

				newVal = gameBoard.getPurchases(saveNations[idx][i], 5);
				if (newVal > yMax)
					yMax = newVal;
				fightBar[i]->Y = newVal;
				
				newVal = gameBoard.getPurchases(saveNations[idx][i], 6);
				if (newVal > yMax)
					yMax = newVal;
				tactBar[i]->Y = newVal;
				
				newVal = gameBoard.getPurchases(saveNations[idx][i], 7);
				if (newVal > yMax)
					yMax = newVal;
				stratBar[i]->Y = newVal;
				
				newVal = gameBoard.getPurchases(saveNations[idx][i], 8);
				if (newVal > yMax)
					yMax = newVal;
				battleBar[i]->Y = newVal;
				
				newVal = gameBoard.getPurchases(saveNations[idx][i], 9);
				if (newVal > yMax)
					yMax = newVal;
				airccBar[i]->Y = newVal;
				
				newVal = gameBoard.getPurchases(saveNations[idx][i], 10);
				if (newVal > yMax)
					yMax = newVal;
				cruiseBar[i]->Y = newVal;
				
				newVal = gameBoard.getPurchases(saveNations[idx][i], 11);
				if (newVal > yMax)
					yMax = newVal;
				destrBar[i]->Y = newVal;
				
				newVal = gameBoard.getPurchases(saveNations[idx][i], 12);
				if (newVal > yMax)
					yMax = newVal;
				subBar[i]->Y = newVal;
				
				newVal = gameBoard.getPurchases(saveNations[idx][i], 13);
				if (newVal > yMax)
					yMax = newVal;
				transBar[i]->Y = newVal;
			}

			yLim = yMax + 5;
			yLim -= yMax % 5;

			yScale = (float)(graphPane.bottom - graphPane.top) / (float)yLim;

			if (yLim > 100)
			{
				yRes = ((yLim / 100) + 1) * 10;
				yNumTicks = yLim / yRes;
				if (yLim % yRes == 0)
					yNumTicks--;
			}
			else if (yLim <= 10)
			{
				yRes = 1;
				yNumTicks = yLim - 1;
			}
			else
			{
				yRes = 10;
				yNumTicks = (yLim / 10) - 1;
				if (yLim % 10 != 0)
					yNumTicks++;
			}

			uint16_t top = yRes * yNumTicks;
			float topTick = (float)(graphPane.top) + (float)((yLim - top) * yScale);
			yTickScale = (float)(graphPane.bottom - topTick) / (float)(yNumTicks); 

			for (uint16_t i = 0; i < saveNations[idx].size(); i++)
			{
				infBar[i]->Y = graphPane.bottom - (infBar[i]->Y * yScale);
				infBar[i]->Height = graphPane.bottom - infBar[i]->Y;
				artBar[i]->Y = graphPane.bottom - (artBar[i]->Y * yScale);
				artBar[i]->Height = graphPane.bottom - artBar[i]->Y;
				mechBar[i]->Y = graphPane.bottom - (mechBar[i]->Y * yScale);
				mechBar[i]->Height = graphPane.bottom - mechBar[i]->Y;
				tankBar[i]->Y = graphPane.bottom - (tankBar[i]->Y * yScale);
				tankBar[i]->Height = graphPane.bottom - tankBar[i]->Y;
				aaaBar[i]->Y = graphPane.bottom - (aaaBar[i]->Y * yScale);
				aaaBar[i]->Height = graphPane.bottom - aaaBar[i]->Y;
				fightBar[i]->Y = graphPane.bottom - (fightBar[i]->Y * yScale);
				fightBar[i]->Height = graphPane.bottom - fightBar[i]->Y;
				tactBar[i]->Y = graphPane.bottom - (tactBar[i]->Y * yScale);
				tactBar[i]->Height = graphPane.bottom - tactBar[i]->Y;
				stratBar[i]->Y = graphPane.bottom - (stratBar[i]->Y * yScale);
				stratBar[i]->Height = graphPane.bottom - stratBar[i]->Y;
				battleBar[i]->Y = graphPane.bottom - (battleBar[i]->Y * yScale);
				battleBar[i]->Height = graphPane.bottom - battleBar[i]->Y;
				airccBar[i]->Y = graphPane.bottom - (airccBar[i]->Y * yScale);
				airccBar[i]->Height = graphPane.bottom - airccBar[i]->Y;
				cruiseBar[i]->Y = graphPane.bottom - (cruiseBar[i]->Y * yScale);
				cruiseBar[i]->Height = graphPane.bottom - cruiseBar[i]->Y;
				destrBar[i]->Y = graphPane.bottom - (destrBar[i]->Y * yScale);
				destrBar[i]->Height = graphPane.bottom - destrBar[i]->Y;
				subBar[i]->Y = graphPane.bottom - (subBar[i]->Y * yScale);
				subBar[i]->Height = graphPane.bottom - subBar[i]->Y;
				transBar[i]->Y = graphPane.bottom - (transBar[i]->Y * yScale);
				transBar[i]->Height = graphPane.bottom - transBar[i]->Y;
			}
		}
		break;
		default:
			break;
		}
	}
}

bool Graph::rescaleBars(uint16_t nats)
{
	uint16_t count = 0;

	if ((nats & GRAPH_GER) != 0)
		count++;
	if ((nats & GRAPH_SOV) != 0)
		count++;
	if ((nats & GRAPH_JPN) != 0)
		count++;
	if ((nats & GRAPH_USA) != 0)
		count++;
	if ((nats & GRAPH_CHN) != 0)
		count++;
	if ((nats & GRAPH_UKE) != 0)
		count++;
	if ((nats & GRAPH_UKP) != 0)
		count++;
	if ((nats & GRAPH_ITA) != 0)
		count++;
	if ((nats & GRAPH_ANZ) != 0)
		count++;
	if ((nats & GRAPH_FRA) != 0)
		count++;

	if (count == numBars)
		return false;
	else
		numBars = count;
	
	uint16_t idx = gameType - 114;

	float offset = xTickScale / (float)numBars;
	float t = 0;
	for (uint16_t i = 0; i < saveGraphs[idx].size(); i++)
	{
		if ((nats & saveGraphs[idx][i]) != 0)
		{
			float left = graphPane.left + (float)t * offset;

			if (t == 0)
			{
				infBar[i]->X = left + 1; infBar[i]->Width = offset - 1;
			}
			else
			{
				infBar[i]->X = left; infBar[i]->Width = offset;
			}
			left += xTickScale;
			artBar[i]->X = left; artBar[i]->Width = offset;
			left += xTickScale;
			mechBar[i]->X = left; mechBar[i]->Width = offset;
			left += xTickScale;
			tankBar[i]->X = left; tankBar[i]->Width = offset;
			left += xTickScale;
			aaaBar[i]->X = left; aaaBar[i]->Width = offset;
			left += xTickScale;
			fightBar[i]->X = left; fightBar[i]->Width = offset;
			left += xTickScale;
			tactBar[i]->X = left; tactBar[i]->Width = offset;
			left += xTickScale;
			stratBar[i]->X = left; stratBar[i]->Width = offset;
			left += xTickScale;
			battleBar[i]->X = left; battleBar[i]->Width = offset;
			left += xTickScale;
			airccBar[i]->X = left; airccBar[i]->Width = offset;
			left += xTickScale;
			cruiseBar[i]->X = left; cruiseBar[i]->Width = offset;
			left += xTickScale;
			destrBar[i]->X = left; destrBar[i]->Width = offset;
			left += xTickScale;
			subBar[i]->X = left; subBar[i]->Width = offset;
			left += xTickScale;
			transBar[i]->X = left; transBar[i]->Width = offset;

			t += 1;
		}
	}

	return true;
}

void Graph::drawFrame(Graphics& graphics)
{
	Rect rectC(graphPane.left - 3 * LABELFONT_S, graphPane.top - 2 * TICK_WIDTH,
		(graphPane.right - graphPane.left) + 4 * LABELFONT_S, (graphPane.bottom - graphPane.top) + 30 * TICK_WIDTH);
	graphics.FillRectangle(backBrush, rectC);

	Rect rectT(graphPane.left + 275, graphPane.top - 4 * TITLEFONT_S, graphPane.right - graphPane.left, 4 * TITLEFONT_S);
	graphics.FillRectangle(backBrush, rectT);

	Rect rectP(graphPane.left, graphPane.top, (graphPane.right - graphPane.left), (graphPane.bottom - graphPane.top));
	graphics.FillRectangle(paneBrush, rectP);
	graphics.DrawRectangle(linePen, rectP);
}

void Graph::drawTicks(Graphics& graphics)
{
	stringFormat.SetAlignment(StringAlignmentFar);

	float lastTick = (float)graphPane.bottom;
	uint16_t leftTick = graphPane.left - TICK_WIDTH;
	uint16_t rightTick = graphPane.left;
	uint16_t topTick = graphPane.bottom;
	if (type == LINE_GRAPH)
	{
		rightTick = graphPane.left + TICK_WIDTH;
		topTick = graphPane.bottom - TICK_WIDTH;
	}
	uint16_t bottomTick = graphPane.bottom + TICK_WIDTH;

	uint16_t lastAxis = 0;

	for (uint16_t i = 0; i < yNumTicks; i++)
	{
		lastTick -= yTickScale;

		Point p0(leftTick, (uint16_t)lastTick);
		Point p1(rightTick, (uint16_t)lastTick);
		graphics.DrawLine(linePen, p0, p1);

		WCHAR val[] = L"   \0";

		lastAxis += yRes;

		if (lastAxis >= 100)
		{
			val[0] = uint2wchar(lastAxis / 100);
			val[1] = '0';
		}
		if (lastAxis % 100 >= 10)
			val[1] = uint2wchar((lastAxis % 100) / 10);
		val[2] = uint2wchar(lastAxis % 10);

		RectF rectF((float)(leftTick - (1.5 * (float)AXISFONT_S)), lastTick - (1.1 * (float)AXISFONT_S),
			1.9 * (float)AXISFONT_S, (float)AXISFONT_S);
		graphics.DrawString(val, -1, axisFont, rectF, &stringFormat, textBrush);
	}	
	{
		RectF rectF((float)(leftTick - (1.5 * (float)AXISFONT_S)), graphPane.bottom - (1.1 * (float)AXISFONT_S),
			1.9 * (float)AXISFONT_S, (float)AXISFONT_S);
		graphics.DrawString(L"0", -1, axisFont, rectF, &stringFormat, textBrush);
	}

	stringFormat.SetAlignment(StringAlignmentNear);

	lastTick = (float)graphPane.left;
	lastAxis = 0;
	for (uint16_t i = 0; i < xNumTicks; i++)
	{
		lastTick += xTickScale;

		Point p0((uint16_t)lastTick, topTick);
		Point p1((uint16_t)lastTick, bottomTick);
		graphics.DrawLine(linePen, p0, p1);

		if (type == LINE_GRAPH)
		{
			WCHAR val[] = L"   \0";

			lastAxis += xRes;

			if (lastAxis >= 100)
			{
				val[0] = uint2wchar(lastAxis / 100);
				val[1] = '0';
			}
			if (lastAxis % 100 >= 10)
				val[1] = uint2wchar(lastAxis / 10);
			val[2] = uint2wchar(lastAxis % 10);

			RectF rectF((float)(lastTick + (0.1 * (float)AXISFONT_S)), ((float)bottomTick - (0.5 * (float)AXISFONT_S)),
				1.9 * (float)AXISFONT_S, (float)AXISFONT_S);
			graphics.DrawString(val, -1, axisFont, rectF, &stringFormat, textBrush);
		}
	}
}

void Graph::drawLabels(Graphics& graphics)
{
	stringFormat.SetAlignment(StringAlignmentCenter);

	StringFormat stringFormatV = stringFormat.Clone();
	stringFormatV.SetFormatFlags(StringFormatFlagsDirectionVertical);
	StringFormat stringFormatT = stringFormat.Clone();
	stringFormatT.SetFormatFlags(StringFormatFlagsNoFitBlackBox);
	StringFormat stringFormatD = stringFormat.Clone();

	RectF rectY(graphPane.left - 2.5 * LABELFONT_S, graphPane.top, LABELFONT_S, graphPane.bottom - graphPane.top);
	REAL x = rectY.X + (rectY.Width / 2);
	REAL y = rectY.Y + (rectY.Height / 2);

	RectF rectX(graphPane.left, graphPane.bottom + 1.1 * LABELFONT_S, graphPane.right - graphPane.left, LABELFONT_S);

	RectF rectT(graphPane.left, graphPane.top - 1.5 * TITLEFONT_S, graphPane.right - graphPane.left, TITLEFONT_S * 2);

	graphics.TranslateTransform(x, y);
	graphics.RotateTransform(180);
	graphics.TranslateTransform(-x, -y);
	graphics.DrawRectangle(borderlessPen, rectY);

	if (type != BAR_GRAPH)
		graphics.DrawRectangle(borderlessPen, rectX);

	WCHAR bankYLabel[] = L"Total IPCs in Bank";
	WCHAR bankTitle[] = L"Total IPCs in Bank After Turn";
	WCHAR incmYLabel[] = L"Total Income";
	WCHAR incmTitle[] = L"Total Income by Turn";
	WCHAR bonsYLabel[] = L"Total Bonuses";
	WCHAR bonsTitle[] = L"Total Bonuses by Turn";
	WCHAR terrYLabel[] = L"Total Territories Controlled";
	WCHAR terrTitle[] = L"Total Territories Controlled by Turn";
	WCHAR sideIncmLabel[] = L"Total Income per Side";
	WCHAR sideIncmTitle[] = L"Total Income per Side by Turn";
	WCHAR sideTerrLabel[] = L"Total Territories Controlled per Side";
	WCHAR sideTerrTitle[] = L"Total Territories Controlled per Side by Turn";
	WCHAR cityYLabel[] = L"Total Victory Cities Controlled per Side";
	WCHAR cityTitle[] = L"Total Victory Cities Controlled per Side After Turn";
	WCHAR unitYLabel[] = L"Total Units Purchased";
	WCHAR unitTitle[] = L"Total Units Purchased by Type";
	WCHAR xLabel[] = L"Turn";

	WCHAR infLabel[] = L"Infantry";
	WCHAR artLabel[] = L"Artillery";
	WCHAR mechLabel[] = L"Mechanized\nInfantry";
	WCHAR tankLabel[] = L"Tank";
	WCHAR aaaLabel[] = L"AAA";
	WCHAR fightLabel[] = L"Fighter";
	WCHAR tactLabel[] = L"Tactical\nBomber";
	WCHAR stratLabel[] = L"Strategic\nBomber";
	WCHAR battleLabel[] = L"Battleship";
	WCHAR airccLabel[] = L"Aircraft\nCarrier";
	WCHAR cruiseLabel[] = L"Cruiser";
	WCHAR destrLabel[] = L"Destroyer";
	WCHAR subLabel[] = L"Submarine";
	WCHAR transLabel[] = L"Transport";

	WCHAR* unitLabels[14] = { infLabel, artLabel, mechLabel, tankLabel, aaaLabel,
		fightLabel, tactLabel, stratLabel, battleLabel, airccLabel, cruiseLabel,
		destrLabel, subLabel, transLabel };

	switch (whichGraph)
	{
	case BANK_GRAPH:
	{
		graphics.DrawString(bankYLabel, -1, labelFont, rectY, &stringFormatV, textBrush);
		graphics.ResetTransform();

		graphics.DrawString(xLabel, -1, labelFont, rectX, &stringFormat, textBrush);
		graphics.DrawString(bankTitle, -1, titleFont, rectT, &stringFormatT, textBrush);
	}
		break;
	case INCM_GRAPH:
	{
		graphics.DrawString(incmYLabel, -1, labelFont, rectY, &stringFormatV, textBrush);
		graphics.ResetTransform();

		graphics.DrawString(xLabel, -1, labelFont, rectX, &stringFormat, textBrush);
		graphics.DrawString(incmTitle, -1, titleFont, rectT, &stringFormatT, textBrush);
	}
		break;
	case BONS_GRAPH:
	{
		graphics.DrawString(bonsYLabel, -1, labelFont, rectY, &stringFormatV, textBrush);
		graphics.ResetTransform();

		graphics.DrawString(xLabel, -1, labelFont, rectX, &stringFormat, textBrush);
		graphics.DrawString(bonsTitle, -1, titleFont, rectT, &stringFormatT, textBrush);
	}
		break;
	case TERR_GRAPH:
	{
		graphics.DrawString(terrYLabel, -1, labelFont, rectY, &stringFormatV, textBrush);
		graphics.ResetTransform();

		graphics.DrawString(xLabel, -1, labelFont, rectX, &stringFormat, textBrush);
		graphics.DrawString(terrTitle, -1, titleFont, rectT, &stringFormatT, textBrush);
		break;
	}
	case S_INCM_GRAPH:
	{
		graphics.DrawString(sideIncmLabel, -1, labelFont, rectY, &stringFormatV, textBrush);
		graphics.ResetTransform();

		graphics.DrawString(xLabel, -1, labelFont, rectX, &stringFormat, textBrush);
		graphics.DrawString(sideIncmTitle, -1, titleFont, rectT, &stringFormatT, textBrush);
	}
	break;
	case S_TERR_GRAPH:
	{
		graphics.DrawString(sideTerrLabel, -1, labelFont, rectY, &stringFormatV, textBrush);
		graphics.ResetTransform();

		graphics.DrawString(xLabel, -1, labelFont, rectX, &stringFormat, textBrush);
		graphics.DrawString(sideTerrTitle, -1, titleFont, rectT, &stringFormatT, textBrush);
	}
	break;
	case CITY_GRAPH:
	{
		graphics.DrawString(cityYLabel, -1, labelFont, rectY, &stringFormatV, textBrush);
		graphics.ResetTransform();

		graphics.DrawString(xLabel, -1, labelFont, rectX, &stringFormat, textBrush);
		graphics.DrawString(cityTitle, -1, titleFont, rectT, &stringFormatT, textBrush);
	}
	break;
	case UNIT_GRAPH:
	{
		graphics.DrawString(unitYLabel, -1, labelFont, rectY, &stringFormatV, textBrush);
		graphics.ResetTransform();

		graphics.DrawString(unitTitle, -1, titleFont, rectT, &stringFormatT, textBrush);

		for (uint16_t i = 0; i < 14; i++)
		{
			x = rectB[i]->X + (rectB[i]->Width / 2);
			y = rectB[i]->Y + (rectB[i]->Height / 2);

			graphics.TranslateTransform(x, y);
			graphics.RotateTransform(-30);
			graphics.TranslateTransform(-x, -y);
			graphics.DrawString(unitLabels[i], -1, axisFont, *rectB[i], &stringFormatD, textBrush);
			graphics.ResetTransform();
		}

		break;
	}
	default:
		break;
	}
}

void Graph::drawData(Graphics& graphics, Board& gameBoard, uint16_t nats)
{
	float yLastPos = 0;
	float xLastPos = (float)graphPane.left + 1;
	uint16_t lim = lastTurn + 1;

	switch (whichGraph)
	{
	case BANK_GRAPH: case INCM_GRAPH: case BONS_GRAPH: case TERR_GRAPH:
	{			
		if (gameType != EUROPE_GAME)
		{
			// China
			yLastPos = (float)graphPane.bottom - (chnDat[0] * yScale);
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = chnDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_CHN) != 0)
					graphics.DrawLine(chnBrushP, p0, p1);
				else
					graphics.DrawLine(chnBrushF, p0, p1);
			}
			// ANZAC
			yLastPos = (float)graphPane.bottom - (anzDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = anzDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_ANZ) != 0)
					graphics.DrawLine(anzBrushP, p0, p1);
				else
					graphics.DrawLine(anzBrushF, p0, p1);
			}
			// United Kingdom Pacific
			yLastPos = (float)graphPane.bottom - (ukpDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = ukpDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_UKP) != 0)
					graphics.DrawLine(ukBrushP, p0, p1);
				else
					graphics.DrawLine(ukBrushF, p0, p1);
			}
			// Japan
			yLastPos = (float)graphPane.bottom - (jpnDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = jpnDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_JPN) != 0)
					graphics.DrawLine(jpnBrushP, p0, p1);
				else
					graphics.DrawLine(jpnBrushF, p0, p1);
			}
		}
		if (gameType != PACIFIC_GAME)
		{
			// France
			yLastPos = (float)graphPane.bottom - (fraDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = fraDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_FRA) != 0)
					graphics.DrawLine(fraBrushP, p0, p1);
				else
					graphics.DrawLine(fraBrushF, p0, p1);
			}
			// Italy
			yLastPos = (float)graphPane.bottom - (itaDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = itaDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_ITA) != 0)
					graphics.DrawLine(itaBrushP, p0, p1);
				else
					graphics.DrawLine(itaBrushF, p0, p1);
			}
			// United Kingdom Europe
			yLastPos = (float)graphPane.bottom - (ukeDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = ukeDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_UKE) != 0)
					graphics.DrawLine(ukBrushP, p0, p1);
				else
					graphics.DrawLine(ukBrushF, p0, p1);
			}
			// Soviet Union
			yLastPos = (float)graphPane.bottom - (sovDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = sovDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_SOV) != 0)
					graphics.DrawLine(sovBrushP, p0, p1);
				else
					graphics.DrawLine(sovBrushF, p0, p1);
			}
			// Germany
			yLastPos = (float)graphPane.bottom - (gerDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = gerDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if ((nats & GRAPH_GER) != 0)
					graphics.DrawLine(gerBrushP, p0, p1);
				else
					graphics.DrawLine(gerBrushF, p0, p1);
			}
		}
		// United States
		yLastPos = (float)graphPane.bottom - (usaDat[0] * yScale);
		xLastPos = (float)graphPane.left + 1;
		for (uint16_t i = 1; i <= lim; i++)
		{
			uint16_t val = usaDat[i];
			float yPos = (float)graphPane.bottom - ((float)val * yScale);
			float xPos = (float)(i)*xScale + (float)graphPane.left;

			PointF p0(xLastPos, yLastPos);
			PointF p1(xPos, yPos);

			yLastPos = yPos;
			xLastPos = xPos;

			if ((nats & GRAPH_USA) != 0)
				graphics.DrawLine(usaBrushP, p0, p1);
			else
				graphics.DrawLine(usaBrushF, p0, p1);
		}
		break;
	}
	case S_INCM_GRAPH: case S_TERR_GRAPH: case CITY_GRAPH:
	{
		if (axisIncm.size() != 0)
		{
			// Allies
			yLastPos = (float)graphPane.bottom - (alliesIncm[0] * yScale);
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = alliesIncm[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (gameType == EUROPE_GAME)
				{
					usaBrushP->SetWidth(17);
					graphics.DrawLine(usaBrushP, p0, p1);
					usaBrushP->SetWidth(2);
					sovBrushP->SetWidth(13);
					graphics.DrawLine(sovBrushP, p0, p1);
					sovBrushP->SetWidth(2);
					ukBrushP->SetWidth(9);
					graphics.DrawLine(ukBrushP, p0, p1);
					ukBrushP->SetWidth(2);
					fraBrushP->SetWidth(5);
					graphics.DrawLine(fraBrushP, p0, p1);
					fraBrushP->SetWidth(2);
				}
				else if (gameType == PACIFIC_GAME)
				{
					usaBrushP->SetWidth(17);
					graphics.DrawLine(usaBrushP, p0, p1);
					usaBrushP->SetWidth(2);
					ukBrushP->SetWidth(13);
					graphics.DrawLine(ukBrushP, p0, p1);
					ukBrushP->SetWidth(2);
					anzBrushP->SetWidth(9);
					graphics.DrawLine(anzBrushP, p0, p1);
					anzBrushP->SetWidth(2);
					chnBrushP->SetWidth(5);
					graphics.DrawLine(chnBrushP, p0, p1);
					chnBrushP->SetWidth(2);
				}
				else
				{
					usaBrushP->SetWidth(25);
					graphics.DrawLine(usaBrushP, p0, p1);
					usaBrushP->SetWidth(2);
					sovBrushP->SetWidth(21);
					graphics.DrawLine(sovBrushP, p0, p1);
					sovBrushP->SetWidth(2);
					ukBrushP->SetWidth(17);
					graphics.DrawLine(ukBrushP, p0, p1);
					ukBrushP->SetWidth(2);
					anzBrushP->SetWidth(13);
					graphics.DrawLine(anzBrushP, p0, p1);
					anzBrushP->SetWidth(2);
					fraBrushP->SetWidth(9);
					graphics.DrawLine(fraBrushP, p0, p1);
					fraBrushP->SetWidth(2);
					chnBrushP->SetWidth(5);
					graphics.DrawLine(chnBrushP, p0, p1);
					chnBrushP->SetWidth(2);
				}
			}

			// Axis
			yLastPos = (float)graphPane.bottom - (axisIncm[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = axisIncm[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i) * xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (gameType == EUROPE_GAME)
				{
					gerBrushP->SetWidth(9);
					graphics.DrawLine(gerBrushP, p0, p1);
					gerBrushP->SetWidth(2);
					itaBrushP->SetWidth(5);
					graphics.DrawLine(itaBrushP, p0, p1);
					itaBrushP->SetWidth(2);
				}
				else if (gameType == PACIFIC_GAME)
				{
					jpnBrushP->SetWidth(5);
					graphics.DrawLine(jpnBrushP, p0, p1);
					jpnBrushP->SetWidth(2);
				}
				else
				{
					gerBrushP->SetWidth(13);
					graphics.DrawLine(gerBrushP, p0, p1);
					gerBrushP->SetWidth(2);
					jpnBrushP->SetWidth(9);
					graphics.DrawLine(jpnBrushP, p0, p1);
					jpnBrushP->SetWidth(5);
					graphics.DrawLine(itaBrushP, p0, p1);
					jpnBrushP->SetWidth(2);
				}
			}
		}
		break;
	}
	case UNIT_GRAPH:
	{
		uint16_t idx = gameType - 114;

		for (uint16_t i = 0; i < saveGraphs[idx].size(); i++)
		{
			if ((nats & saveGraphs[idx][i]) != 0)
			{
				SolidBrush brush(Color(0, 0, 0));
				brush.SetColor(selectBrush(saveNations[idx][i]));

				graphics.FillRectangle(&brush, *infBar[i]);
				graphics.FillRectangle(&brush, *artBar[i]);
				graphics.FillRectangle(&brush, *mechBar[i]);
				graphics.FillRectangle(&brush, *tankBar[i]);
				graphics.FillRectangle(&brush, *aaaBar[i]);
				graphics.FillRectangle(&brush, *fightBar[i]);
				graphics.FillRectangle(&brush, *tactBar[i]);
				graphics.FillRectangle(&brush, *stratBar[i]);
				graphics.FillRectangle(&brush, *battleBar[i]);
				graphics.FillRectangle(&brush, *airccBar[i]);
				graphics.FillRectangle(&brush, *cruiseBar[i]);
				graphics.FillRectangle(&brush, *destrBar[i]);
				graphics.FillRectangle(&brush, *subBar[i]);
				graphics.FillRectangle(&brush, *transBar[i]);
			}
		}

		break;
	}
	default:
		break;
	}
}

void Graph::updateGraph(HDC hdc, uint16_t nat, bool primary, uint16_t nats)
{
	Graphics graphics(hdc);

	float yLastPos = 0;
	float xLastPos = (float)graphPane.left + 1;
	uint16_t lim = lastTurn + 1;

	switch (whichGraph)
	{
	case BANK_GRAPH: case INCM_GRAPH: case BONS_GRAPH: case TERR_GRAPH:
	{
		switch (nat)
		{
		case TURN_GER:
		{
			yLastPos = (float)graphPane.bottom - (gerDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = gerDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (primary)
					graphics.DrawLine(gerBrushP, p0, p1);
				else
					graphics.DrawLine(gerBrushF, p0, p1);
			}
		}
			break;
		case TURN_SOV:
		{
			yLastPos = (float)graphPane.bottom - (sovDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = sovDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (primary)
					graphics.DrawLine(sovBrushP, p0, p1);
				else
					graphics.DrawLine(sovBrushF, p0, p1);
			}
		}
			break;
		case TURN_JPN:
		{
			yLastPos = (float)graphPane.bottom - (jpnDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = jpnDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (primary)
					graphics.DrawLine(jpnBrushP, p0, p1);
				else
					graphics.DrawLine(jpnBrushF, p0, p1);
			}
		}
			break;
		case TURN_USA:
		{
			yLastPos = (float)graphPane.bottom - (usaDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = usaDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (primary)
					graphics.DrawLine(usaBrushP, p0, p1);
				else
					graphics.DrawLine(usaBrushF, p0, p1);
			}
		}
			break;
		case TURN_CHN:
		{
			yLastPos = (float)graphPane.bottom - (chnDat[0] * yScale);
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = chnDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (primary)
					graphics.DrawLine(chnBrushP, p0, p1);
				else
					graphics.DrawLine(chnBrushF, p0, p1);
			}
		}
			break;
		case TURN_UKE:
		{
			if (gameType != PACIFIC_GAME)
			{
				yLastPos = (float)graphPane.bottom - (ukeDat[0] * yScale);
				xLastPos = (float)graphPane.left + 1;
				for (uint16_t i = 1; i <= lim; i++)
				{
					uint16_t val = ukeDat[i];
					float yPos = (float)graphPane.bottom - ((float)val * yScale);
					float xPos = (float)(i)*xScale + (float)graphPane.left;

					PointF p0(xLastPos, yLastPos);
					PointF p1(xPos, yPos);

					yLastPos = yPos;
					xLastPos = xPos;

					if (primary)
						graphics.DrawLine(ukBrushP, p0, p1);
					else
						graphics.DrawLine(ukBrushF, p0, p1);
				}
			}
			if (gameType != EUROPE_GAME)
			{
				yLastPos = (float)graphPane.bottom - (ukpDat[0] * yScale);
				xLastPos = (float)graphPane.left + 1;
				for (uint16_t i = 1; i <= lim; i++)
				{
					uint16_t val = ukpDat[i];
					float yPos = (float)graphPane.bottom - ((float)val * yScale);
					float xPos = (float)(i)*xScale + (float)graphPane.left;

					PointF p0(xLastPos, yLastPos);
					PointF p1(xPos, yPos);

					yLastPos = yPos;
					xLastPos = xPos;

					if (primary)
						graphics.DrawLine(ukBrushP, p0, p1);
					else
						graphics.DrawLine(ukBrushF, p0, p1);
				}
			}
		}
			break;
		case TURN_ITA:
		{
			yLastPos = (float)graphPane.bottom - (itaDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = itaDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (primary)
					graphics.DrawLine(itaBrushP, p0, p1);
				else
					graphics.DrawLine(itaBrushF, p0, p1);
			}
		}
			break;
		case TURN_ANZ:
		{
			yLastPos = (float)graphPane.bottom - (anzDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = anzDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (primary)
					graphics.DrawLine(anzBrushP, p0, p1);
				else
					graphics.DrawLine(anzBrushF, p0, p1);
			}
		}
			break;
		case TURN_FRA:
		{
			yLastPos = (float)graphPane.bottom - (fraDat[0] * yScale);
			xLastPos = (float)graphPane.left + 1;
			for (uint16_t i = 1; i <= lim; i++)
			{
				uint16_t val = fraDat[i];
				float yPos = (float)graphPane.bottom - ((float)val * yScale);
				float xPos = (float)(i)*xScale + (float)graphPane.left;

				PointF p0(xLastPos, yLastPos);
				PointF p1(xPos, yPos);

				yLastPos = yPos;
				xLastPos = xPos;

				if (primary)
					graphics.DrawLine(fraBrushP, p0, p1);
				else
					graphics.DrawLine(fraBrushF, p0, p1);
			}
		}
			break;
		default:
			break;
		}
		break;
	}
	case UNIT_GRAPH:
	{
		eraseBars(graphics);
		rescaleBars(nats);

		uint16_t idx = gameType - 114;

		for (uint16_t i = 0; i < saveNations[idx].size(); i++)
		{
			if ((nats & saveGraphs[idx][i]) != 0)
			{
				SolidBrush brush(Color(0, 0, 0));
				brush.SetColor(selectBrush(saveNations[idx][i]));

				graphics.FillRectangle(&brush, *infBar[i]);
				graphics.FillRectangle(&brush, *artBar[i]);
				graphics.FillRectangle(&brush, *mechBar[i]);
				graphics.FillRectangle(&brush, *tankBar[i]);
				graphics.FillRectangle(&brush, *aaaBar[i]);
				graphics.FillRectangle(&brush, *fightBar[i]);
				graphics.FillRectangle(&brush, *tactBar[i]);
				graphics.FillRectangle(&brush, *stratBar[i]);
				graphics.FillRectangle(&brush, *battleBar[i]);
				graphics.FillRectangle(&brush, *airccBar[i]);
				graphics.FillRectangle(&brush, *cruiseBar[i]);
				graphics.FillRectangle(&brush, *destrBar[i]);
				graphics.FillRectangle(&brush, *subBar[i]);
				graphics.FillRectangle(&brush, *transBar[i]);
			}
		}
	}
	default:
		break;
	}
}

WCHAR Graph::uint2wchar(uint16_t val)
{
	if (val == 0)
		return '0';
	else if (val == 1)
		return '1';
	else if (val == 2)
		return '2';
	else if (val == 3)
		return '3';
	else if (val == 4)
		return '4';
	else if (val == 5)
		return '5';
	else if (val == 6)
		return '6';
	else if (val == 7)
		return '7';
	else if (val == 8)
		return '8';
	else if (val == 9)
		return '9';
	else
		return ' ';
}

bool Graph::isBeforeNation(uint16_t target, uint16_t current)
{
	if (target >= current)
		return false;
	else
		return true;
}

Color Graph::selectBrush(uint16_t nat)
{
	switch (nat)
	{
	case TURN_GER:
		return Color(77, 93, 83);
		break;
	case TURN_SOV:
		return Color(255, 26, 0);
		break;
	case TURN_JPN:
		return Color(188, 0, 45);
		break;
	case TURN_USA:
		return Color(107, 142, 35);
		break;
	case TURN_CHN:
		return Color(0, 0, 149);
		break;
	case TURN_UKE: case TURN_UKP:
		return Color(240, 230, 140);
		break;
	case TURN_ITA:
		return Color(0, 140, 69);
		break;
	case TURN_ANZ:
		return Color(47, 87, 21);
		break;
	case TURN_FRA:
		return Color(0, 114, 187);
		break;
	default:
		return Color(212, 212, 212);
		break;
	}
}

void Graph::eraseBars(Graphics& graphics)
{
	uint16_t idx = gameType - 114;

	for (uint16_t i = 0; i < saveGraphs[idx].size(); i++)
	{
		SolidBrush brush(Color(212, 212, 212));

		graphics.FillRectangle(&brush, *infBar[i]);
		graphics.FillRectangle(&brush, *artBar[i]);
		graphics.FillRectangle(&brush, *mechBar[i]);
		graphics.FillRectangle(&brush, *tankBar[i]);
		graphics.FillRectangle(&brush, *aaaBar[i]);
		graphics.FillRectangle(&brush, *fightBar[i]);
		graphics.FillRectangle(&brush, *tactBar[i]);
		graphics.FillRectangle(&brush, *stratBar[i]);
		graphics.FillRectangle(&brush, *battleBar[i]);
		graphics.FillRectangle(&brush, *airccBar[i]);
		graphics.FillRectangle(&brush, *cruiseBar[i]);
		graphics.FillRectangle(&brush, *destrBar[i]);
		graphics.FillRectangle(&brush, *subBar[i]);
		graphics.FillRectangle(&brush, *transBar[i]);
	}
}