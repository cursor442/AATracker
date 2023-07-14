#include "../header/NeutralSection.h"

NeutralSection::NeutralSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	neutralFrame = new AABox("Neutrals Section");

	for (int i = 0; i < NEUTRAL_COLS; i++)
		for (int j = 0; j < NEUTRAL_ROWS; j++)
			neutralBox[i][j] = new AABox("Neutral");

	neutralText.resize(0);

	neutralPos.resize(0);
	neutralUpdatePos.resize(0);

	tileBrushL = NULL;
	neutBrush = NULL;
	axisBrush = NULL;
	allyBrush = NULL;

	statusFont = NULL;
	neutralFont = NULL;

	neutralBrush.resize(0);
}

NeutralSection::~NeutralSection()
{
	delete neutralFrame;

	for (int i = 0; i < NEUTRAL_COLS; i++)
		for (int j = 0; j < NEUTRAL_ROWS; j++)
			delete neutralBox;
}

void NeutralSection::configureNeutralBox(RectF& frame, int layer)
{
	neutralFrame->config(frame, layer);
	
	neutralBox[0][0]->config(neutralFrame->box, layer + 1);
	neutralBox[0][0]->box.Width = frame.Width / NEUTRAL_COLS;
	neutralBox[0][0]->box.Height = neutralFrame->box.Height / NEUTRAL_ROWS;

	for (int i = 1; i < NEUTRAL_COLS; i++)
	{
		neutralBox[i][0]->config(neutralBox[i - 1][0]->box, layer + 1);
		neutralBox[i][0]->box.X = neutralBox[i - 1][0]->box.GetRight();
	}
	neutralBox[NEUTRAL_COLS - 1][0]->box.Width = frame.GetRight() - neutralBox[NEUTRAL_COLS - 1][0]->box.X;

	for (int i = 0; i < NEUTRAL_COLS; i++)
	{
		for (int j = 1; j < NEUTRAL_ROWS; j++)
		{
			neutralBox[i][j]->config(neutralBox[i][j - 1]->box, layer + 1);
			neutralBox[i][j]->box.Y = neutralBox[i][j - 1]->box.GetBottom();
		}

		neutralBox[i][NEUTRAL_ROWS - 1]->box.Height = frame.GetBottom() - neutralBox[i][NEUTRAL_ROWS - 1]->box.Y;
	}
}

void NeutralSection::configDrawTools(SolidBrush* b0, HatchBrush* h0, HatchBrush* h1, HatchBrush* h2, Font* f0, Font* f1)
{
	tileBrushL = b0;

	neutBrush = h0;
	axisBrush = h1;
	allyBrush = h2;

	statusFont = f0;
	neutralFont = f1;
}

void NeutralSection::resetNeutralBox()
{
	neutralText.resize(0);
}

bool NeutralSection::getNeutralConfig()
{
	return (neutralText.size() != 0);
}

void NeutralSection::updateNeutralFormat(int gameType, vector<territoryTransaction>& neutralUpdate)
{
	// Initial configuration
	if (neutralText.size() == 0)
	{
		int idx = 0;
		switch (gameType)
		{
		case EUROPE_GAME:
		{
			neutralText.resize(NEUTRAL_EUR_S);
			for (int i = 0; i < neutralText.size(); i++)
				wcsncpy_s(neutralText[i].t, eurNeutral[i], NEUTRAL_NAMELEN);

			neutralPos.resize(NEUTRAL_EUR_S);
			neutralBrush.resize(NEUTRAL_EUR_S);
			break;
		}
		case PACIFIC_GAME:
		{
			neutralText.resize(NEUTRAL_PAC_S);
			for (int i = 0; i < neutralText.size(); i++)
				wcsncpy_s(neutralText[i].t, pacNeutral[i], NEUTRAL_NAMELEN);

			neutralPos.resize(NEUTRAL_PAC_S);
			neutralBrush.resize(NEUTRAL_PAC_S);
			break;
		}
		case GLOBAL_GAME:
		{
			neutralText.resize(NEUTRAL_EUR_S + NEUTRAL_PAC_S);
			for (int i = 0; i < NEUTRAL_EUR_S; i++)
				wcsncpy_s(neutralText[i].t, eurNeutral[i], NEUTRAL_NAMELEN);
			idx = NEUTRAL_EUR_S;
			for (int i = 0; i < NEUTRAL_PAC_S; i++)
			{
				wcsncpy_s(neutralText[idx].t, pacNeutral[i], NEUTRAL_NAMELEN);
				idx++;
			}

			neutralPos.resize(NEUTRAL_EUR_S + NEUTRAL_PAC_S);
			neutralBrush.resize(NEUTRAL_EUR_S + NEUTRAL_PAC_S);
			break;
		}
		default:
			break;
		}

		// Save the location of each territory
		for (int i = 0; i < neutralUpdate.size(); i++)
			neutralPos[i] = neutralUpdate[i].id;
	}

	// Update brushes
	for (int i = 0; i < neutralUpdate.size(); i++)
	{
		// Get index corresponding to territory
		vector<int>::iterator it;
		it = find(neutralPos.begin(), neutralPos.end(), neutralUpdate[i].id);
		int idx = it - neutralPos.begin();

		switch (neutralUpdate[i].owner)
		{
		case FULL_NEUTRAL: neutralBrush[idx] = neutBrush; break;
		case AXIS_NEUTRAL: neutralBrush[idx] = axisBrush; break;
		case ALLY_NEUTRAL: neutralBrush[idx] = allyBrush; break;
		case MONGOLIA_TER: neutralBrush[idx] = neutBrush; break;
		case TURN_GER: neutralBrush[idx] = gerBrushP; break;
		case TURN_SOV: neutralBrush[idx] = sovBrushP; break;
		case TURN_JPN: neutralBrush[idx] = jpnBrushP; break;
		case TURN_USA: neutralBrush[idx] = usaBrushP; break;
		case TURN_CHN: neutralBrush[idx] = chnBrushP; break;
		case TURN_UKE: neutralBrush[idx] = ukBrushP; break;
		case TURN_UKP: neutralBrush[idx] = ukBrushP; break;
		case TURN_ITA: neutralBrush[idx] = itaBrushP; break;
		case TURN_ANZ: neutralBrush[idx] = anzBrushP; break;
		case TURN_FRA: neutralBrush[idx] = fraBrushP; break;
		default: neutralBrush[idx] = neutBrush; break;
		}

		neutralUpdatePos.push_back(idx);
	}
}

void NeutralSection::drawNeutralBox(Graphics* graphics, int sect, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		neutralFrame->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		int idxC = 0, idxR = 0;
		for (int i = 0; i < neutralBrush.size(); i++)
		{
			idxC = i / NEUTRAL_ROWS;
			idxR = i % NEUTRAL_ROWS;
			neutralBox[idxC][idxR]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, neutralText[i].t, layers);
		}

		for (int i = neutralBrush.size(); i < (NEUTRAL_COLS * NEUTRAL_ROWS); i++)
		{
			idxC = i / NEUTRAL_ROWS;
			idxR = i % NEUTRAL_ROWS;
			neutralBox[idxC][idxR]->drawFrameFill(graphics, borderPen, baseTextFont, textFormat, textBrush, backBrush, layers);
		}
	}
	else // Actual graphics
	{
		int idxC = 0, idxR = 0;
		if (sect == NEUT_ALL)
		{
			for (int i = 0; i < neutralBrush.size(); i++)
			{
				idxC = i / NEUTRAL_ROWS;
				idxR = i % NEUTRAL_ROWS;
				neutralBox[idxC][idxR]->drawBox(graphics, pen, neutralFont, centerFormat, textBrush, neutralBrush[i], neutralText[i].t, layers);
			}
		}
		else
		{
			for (int i = 0; i < neutralUpdatePos.size(); i++)
			{
				idxC = neutralUpdatePos[i] / NEUTRAL_ROWS;
				idxR = neutralUpdatePos[i] % NEUTRAL_ROWS;
				neutralBox[idxC][idxR]->drawBox(graphics, pen, neutralFont, centerFormat, textBrush, neutralBrush[neutralUpdatePos[i]], neutralText[neutralUpdatePos[i]].t, layers);
			}
		}

		neutralUpdatePos.resize(0);

		if (sect == NEUT_ALL)
		{
			for (int i = neutralBrush.size(); i < (NEUTRAL_COLS * NEUTRAL_ROWS); i++)
			{
				idxC = i / NEUTRAL_ROWS;
				idxR = i % NEUTRAL_ROWS;
				neutralBox[idxC][idxR]->drawBox(graphics, pen, baseTextFont, textFormat, textBrush, tileBrushL, L"", layers);
			}
		}
	}
}