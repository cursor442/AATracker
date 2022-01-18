#include "../header/MiniSpreadSection.h"

MiniSpreadSection::MiniSpreadSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	miniSpreadFrame = new AABox("Mini Spreadsheet Section");

	spreadHead[TURN_POS] = new AABox("Turn");
	spreadHead[BANK_POS] = new AABox("Bank");
	spreadHead[INCM_POS] = new AABox("Income");
	spreadHead[BONS_POS] = new AABox("Bonus");
	spreadHead[PNLT_POS] = new AABox("Penalty");
	spreadHead[XPNS_POS] = new AABox("Expenses");

	for (int i = 0; i < SPREAD_ROWS; i++)
	{
		for (int j = 0; j < SPREAD_COLS; j++)
			spreadBox[i][j] = new AABox("Cell");
		turnText[i][0] = '\0';
	}

	headFont = NULL;
	spreadFont = NULL;

	spreadBrushP = NULL; spreadBrushS = NULL;
	spreadLineBrush = NULL;
}

MiniSpreadSection::~MiniSpreadSection()
{
	delete miniSpreadFrame;

	for (int i = 0; i < SPREAD_COLS; i++)
		delete spreadHead[i];

	for (int i = 0; i < SPREAD_ROWS; i++)
		for (int j = 0; j < SPREAD_COLS; j++)
			delete spreadBox[i][j];
}

void MiniSpreadSection::configureMiniSpread(RectF& frame, int layer)
{
	miniSpreadFrame->config(frame, layer);

	spreadHead[TURN_POS]->config(frame, layer + 1);
	spreadHead[TURN_POS]->box.Width = frame.Width / SPREAD_COLS;
	spreadHead[TURN_POS]->box.Height = frame.Height / (SPREAD_ROWS + 1);

	spreadHead[BANK_POS]->config(spreadHead[TURN_POS]->box, layer + 1);
	spreadHead[BANK_POS]->box.X = spreadHead[TURN_POS]->box.GetRight();

	spreadHead[INCM_POS]->config(spreadHead[BANK_POS]->box, layer + 1);
	spreadHead[INCM_POS]->box.X = spreadHead[BANK_POS]->box.GetRight();

	spreadHead[BONS_POS]->config(spreadHead[INCM_POS]->box, layer + 1);
	spreadHead[BONS_POS]->box.X = spreadHead[INCM_POS]->box.GetRight();

	spreadHead[PNLT_POS]->config(spreadHead[BONS_POS]->box, layer + 1);
	spreadHead[PNLT_POS]->box.X = spreadHead[BONS_POS]->box.GetRight();

	spreadHead[XPNS_POS]->config(spreadHead[PNLT_POS]->box, layer + 1);
	spreadHead[XPNS_POS]->box.X = spreadHead[PNLT_POS]->box.GetRight();
	spreadHead[XPNS_POS]->box.Width = frame.GetRight() - spreadHead[XPNS_POS]->box.X;

	spreadBox[0][0]->config(spreadHead[TURN_POS]->box, layer + 1);
	spreadBox[0][0]->box.Y = spreadHead[TURN_POS]->box.GetBottom();

	for (int i = 1; i < SPREAD_ROWS; i++)
	{
		spreadBox[i][0]->config(spreadBox[i - 1][0]->box, layer + 1);
		spreadBox[i][0]->box.Y = spreadBox[i - 1][0]->box.GetBottom();
	}
	spreadBox[SPREAD_ROWS - 1][0]->box.Height = frame.GetBottom() - spreadBox[SPREAD_ROWS - 1][0]->box.Y;

	for (int i = 0; i < SPREAD_ROWS; i++)
	{
		for (int j = 1; j < SPREAD_COLS; j++)
		{
			spreadBox[i][j]->config(spreadBox[i][j - 1]->box, layer + 1);
			spreadBox[i][j]->box.X = spreadBox[i][j - 1]->box.GetRight();
		}
		spreadBox[i][SPREAD_COLS - 1]->box.Width = frame.GetRight() - spreadBox[i][SPREAD_COLS - 1]->box.X;
	}
}

void MiniSpreadSection::configDrawTools(Font* f0, Font* f1)
{
	headFont = f0;
	spreadFont = f1;
}

void MiniSpreadSection::updateMiniSpreadText(int turn)
{
	int minTurn;
	if (turn < SPREAD_ROWS)
		minTurn = 1;
	else
		minTurn = turn - SPREAD_ROWS + 2;

	for (int i = 0; i < SPREAD_ROWS; i++)
		valConv(turnText[i], minTurn + i);
}

void MiniSpreadSection::updateMiniSpreadFormat(int nat)
{
	switch (nat)
	{
	case TURN_GER:
	{
		spreadBrushP = gerBrushP;
		spreadBrushS = gerBrushS;
		break;
	}
	case TURN_SOV:
	{
		spreadBrushP = sovBrushP;
		spreadBrushS = sovBrushS;
		break;
	}
	case TURN_JPN:
	{
		spreadBrushP = jpnBrushP;
		spreadBrushS = jpnBrushS;
		break;
	}
	case TURN_USA:
	{
		spreadBrushP = usaBrushP;
		spreadBrushS = usaBrushS;
		break;
	}
	case TURN_CHN:
	{
		spreadBrushP = chnBrushP;
		spreadBrushS = chnBrushS;
		break;
	}
	case TURN_UKE: case TURN_UKP:
	{
		spreadBrushP = ukBrushP;
		spreadBrushS = ukBrushS;
		break;
	}
	case TURN_ITA:
	{
		spreadBrushP = itaBrushP;
		spreadBrushS = itaBrushS;
		break;
	}
	case TURN_ANZ:
	{
		spreadBrushP = anzBrushP;
		spreadBrushS = anzBrushS;
		break;
	}
	case TURN_FRA:
	{
		spreadBrushP = fraBrushP;
		spreadBrushS = fraBrushS;
		break;
	}
	default: break;
	}
}

void MiniSpreadSection::resetMiniSpreadText()
{
	for (int i = 0; i < SPREAD_ROWS; i++)
		turnText[i][0] = '\0';
}

void MiniSpreadSection::drawMiniSpread(Graphics* graphics, Spreadsheet* spread, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Always show bounding box
		pen = borderPen;
	else
		pen = borderPen;

	if (dbg_sections) // Show box names
	{
		miniSpreadFrame->drawFrame(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		for (int i = 0; i < SPREAD_COLS; i++)
			spreadHead[i]->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		for (int i = 0; i < SPREAD_ROWS; i++)
			for (int j = 0; j < SPREAD_COLS; j++)
				spreadBox[i][j]->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		
	}
	else // Actual graphics
	{
		int miniIdx = spread->getMiniIndex();

		spreadLineBrush = spreadBrushP;
		for (int i = 0; i < SPREAD_COLS; i++)
			spreadHead[i]->drawFrame(graphics, borderPen, headFont, centerFormat, textBrush, spreadLineBrush, layers);

		for (int i = 0; i < SPREAD_ROWS; i++)
		{
			spreadLineBrush = ((miniIdx + i) % 2 == 0) ? spreadBrushP : spreadBrushS;
			spreadBox[i][0]->drawBox(graphics, borderPen, spreadFont, centerFormat, textBrush, spreadLineBrush, turnText[i], layers);
			for (int j = BANK_POS; j < SPREAD_COLS; j++)
				spreadBox[i][j]->drawBox(graphics, borderPen, spreadFont, centerFormat, textBrush, spreadLineBrush,
					spread->getMiniSpreadText(i, j - BANK_POS), layers);
		}
	}
}

void MiniSpreadSection::drawMiniSpread(Graphics* graphics, Spreadsheet* spread, int turn, int col, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Always show bounding box
		pen = borderPen;
	else
		pen = borderPen;

	int miniIdx = spread->getMiniIndex();

	if (dbg_sections) // Show box names
	{
		spreadBox[turn - miniIdx][col]->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
	}
	else // Actual graphics
	{
		spreadLineBrush = (turn % 2 == 0) ? spreadBrushP : spreadBrushS;
		spreadBox[turn - miniIdx][col]->drawBox(graphics, borderPen, spreadFont, centerFormat, textBrush, spreadLineBrush,
			spread->getMiniSpreadText(turn - miniIdx, col - BANK_POS), layers);
	}
}

void MiniSpreadSection::valConv(WCHAR* c, int val)
{
	if (val > 99)
	{
		c[0] = uint2char_(val / 100);
		c[1] = uint2char_((val % 100) / 10);
		c[2] = uint2char_(val % 10);
		c[3] = '\0';
	}
	else if (val > 9)
	{
		c[0] = uint2char_(val / 10);
		c[1] = uint2char_(val % 10);
		c[2] = '\0';
	}
	else
	{
		c[0] = uint2char_(val);
		c[1] = '\0';
	}
}

SolidBrush* MiniSpreadSection::getLastLineBrush(int turn)
{
	return ((turn + SPREAD_ROWS - 1)% 2 == 0) ? spreadBrushP : spreadBrushS;
}
