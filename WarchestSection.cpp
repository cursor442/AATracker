#include "WarchestSection.h"

WarchestSection::WarchestSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	warchestFrame = new AABox("Warchest Section");

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			warchestBoxes[i][j] = new AABox("Cell");
			warchestValBoxes[i][j] = new AABox("Val");
			warchestBrushes[i][j] = NULL;
			warchestValBrushes[i][j] = NULL;
		}

	warchestUKValBox = new AABox("Val");
	warchestCone = new AAQuad();

	natOrder.resize(0);
	ukPos.resize(0);
	natText.resize(9);
	natVals.resize(9);

	for (int i = 0; i < 9; i++)
	{
		wcsncpy_s(natText[i].t, L"", 2);
		wcsncpy_s(natVals[i].t, L"", 2);
	}
	wcsncpy_s(ukVal.t, L"", 2);

	natFont = NULL;
}

WarchestSection::~WarchestSection()
{
	delete warchestFrame;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			delete warchestBoxes[i][j];
			delete warchestValBoxes[i][j];
		}

	delete warchestUKValBox;
}

void WarchestSection::configureWarchestBox(RectF& frame, RectF& spreadFrame, int layer)
{
	warchestFrame->config(frame, layer);

	warchestBoxes[0][0]->config(warchestFrame->box, layer + 1);
	warchestBoxes[0][0]->box.Width = warchestFrame->box.Width / 3;
	warchestBoxes[0][0]->box.Height = warchestFrame->box.Height / 3;	

	for (int i = 0; i < 3; i++)
	{
		if (i > 0)
		{
			warchestBoxes[i][0]->config(warchestBoxes[i - 1][0]->box, layer + 1);
			warchestBoxes[i][0]->box.Y = warchestBoxes[i - 1][0]->box.GetBottom();
		}

		for (int j = 1; j < 3; j++)
		{
			warchestBoxes[i][j]->config(warchestBoxes[i][j - 1]->box, layer + 1);
			warchestBoxes[i][j]->box.X = warchestBoxes[i][j - 1]->box.GetRight();
		}

		for (int j = 0; j < 3; j++)
		{
			warchestValBoxes[i][j]->config(warchestBoxes[i][j]->box, layer + 2);
			warchestValBoxes[i][j]->box.X = warchestBoxes[i][j]->box.GetRight() - (WARCHEST_VALW + WARCHEST_VALM);
			warchestValBoxes[i][j]->box.Width = WARCHEST_VALW;
			warchestValBoxes[i][j]->box.Y = warchestBoxes[i][j]->box.Y + WARCHEST_VALM;
			warchestValBoxes[i][j]->box.Height = warchestBoxes[i][j]->box.Height - (2 * WARCHEST_VALM);
		}
	}

	warchestCone->config(
		{ spreadFrame.X, spreadFrame.GetBottom() + 1 },
		{ warchestBoxes[0][0]->box.X, warchestBoxes[0][0]->box.Y },
		{ warchestBoxes[0][0]->box.GetRight(), warchestBoxes[0][0]->box.Y },
		{ spreadFrame.GetRight(), spreadFrame.GetBottom() + 1 },
		layer);
}

void WarchestSection::configDrawTools(Font* f0)
{
	natFont = f0;
}

void WarchestSection::updateWarchestText(int nat, int bank, int incm, bool gloUK)
{
	int idx = TURN_NON;
	if (natOrder.size() == 9 && nat == TURN_UKP) // Global game and this is UKP
		nat = TURN_UKE; // Pacific goes in the normal spot

	for (int i = 0; i < natOrder.size(); i++)
		if (natOrder[i] == nat)
		{
			idx = i;
			break;
		}

	if (!gloUK)
		valConv(&natVals[idx], bank, incm);
	else
		valConv(&ukVal, bank, incm);
}

void WarchestSection::updateWarchestBrushes(int gameType, bool warchestRotate, SolidBrush* b0)
{
	if (natOrder.size() == 0)
	{
		switch (gameType)
		{
		case EUROPE_GAME:
		{
			natOrder.resize(6);
			natOrder = { TURN_GER, TURN_SOV, TURN_USA, TURN_UKE, TURN_ITA, TURN_FRA };

			ukPos.resize(0);

			warchestBrushes[2][0] = jpnBrushF;
			warchestBrushes[2][1] = chnBrushF;
			warchestBrushes[2][2] = anzBrushF;
			warchestValBrushes[2][0] = jpnBrushF;
			warchestValBrushes[2][1] = chnBrushF;
			warchestValBrushes[2][2] = anzBrushF;
			break;
		}
		case PACIFIC_GAME:
		{
			natOrder.resize(5);
			natOrder = { TURN_JPN, TURN_USA, TURN_CHN, TURN_UKP, TURN_ANZ };

			ukPos.resize(0);

			warchestBrushes[1][2] = gerBrushF;
			warchestBrushes[2][0] = sovBrushF;
			warchestBrushes[2][1] = itaBrushF;
			warchestBrushes[2][2] = fraBrushF;
			warchestValBrushes[1][2] = gerBrushF;
			warchestValBrushes[2][0] = sovBrushF;
			warchestValBrushes[2][1] = itaBrushF;
			warchestValBrushes[2][2] = fraBrushF;
			break;
		}
		case GLOBAL_GAME:
		{
			natOrder.resize(9);
			natOrder = { TURN_GER, TURN_SOV, TURN_JPN, TURN_USA, TURN_CHN,
						   TURN_UKE, TURN_ITA, TURN_ANZ, TURN_FRA };

			ukPos.resize(9);
			ukPos = { false, false, false, false, false,
						   true, false, false, false };
			break;
		}
		default:
			break;
		}

		// Load nation names
		for (int i = 0; i < natOrder.size(); i++)
			wcsncpy_s(natText[i].t, natNames[natOrder[i]], ARRAYSIZE(natNames[natOrder[i]]));

		// United Kingdom does not have space due to extra value box
		if (gameType == GLOBAL_GAME)
			wcsncpy_s(natText[TURN_UKE].t, L"UK E/P", 11);

		// Start with the last before first rotate
		rotate(natOrder.begin(), natOrder.end() - 1, natOrder.end());
		if (ukPos.size() > 0)
			rotate(ukPos.begin(), ukPos.end() - 1, ukPos.end());
		rotate(natText.begin(), natText.begin() + (natOrder.size() - 1), natText.begin() + natOrder.size());
		rotate(natVals.begin(), natVals.begin() + (natOrder.size() - 1), natVals.begin() + natOrder.size());
		warchestRotate = true;
	}

	if (warchestRotate)
	{
		rotate(natOrder.begin(), natOrder.begin() + 1, natOrder.end());
		if (ukPos.size() > 0)
			rotate(ukPos.begin(), ukPos.begin() + 1, ukPos.end());
		rotate(natText.begin(), natText.begin() + 1, natText.begin() + natOrder.size());
		rotate(natVals.begin(), natVals.begin() + 1, natVals.begin() + natOrder.size());

		for (int i = 0; i < natOrder.size(); i++)
		{
			int idx0 = i / 3;
			int idx1 = i % 3;

			switch (natOrder[i])
			{
			case TURN_GER:
			{
				warchestBrushes[idx0][idx1] = gerBrushP;
				warchestValBrushes[idx0][idx1] = gerBrushS;
				break;
			}
			case TURN_SOV:
			{
				warchestBrushes[idx0][idx1] = sovBrushP;
				warchestValBrushes[idx0][idx1] = sovBrushS;
				break;
			}
			case TURN_JPN:
			{
				warchestBrushes[idx0][idx1] = jpnBrushP;
				warchestValBrushes[idx0][idx1] = jpnBrushS;
				break;
			}
			case TURN_USA:
			{
				warchestBrushes[idx0][idx1] = usaBrushP;
				warchestValBrushes[idx0][idx1] = usaBrushS;
				break;
			}
			case TURN_CHN:
			{
				warchestBrushes[idx0][idx1] = chnBrushP;
				warchestValBrushes[idx0][idx1] = chnBrushS;
				break;
			}
			case TURN_UKE: case TURN_UKP:
			{
				warchestBrushes[idx0][idx1] = ukBrushP;
				warchestValBrushes[idx0][idx1] = ukBrushS;

				// If global game, move extra UK value box to new location
				warchestUKValBox->config(warchestValBoxes[idx0][idx1]->box, warchestValBoxes[idx0][idx1]->layer);
				warchestUKValBox->box.X -= (WARCHEST_VALW + WARCHEST_VALM);

				break;
			}
			case TURN_ITA:
			{
				warchestBrushes[idx0][idx1] = itaBrushP;
				warchestValBrushes[idx0][idx1] = itaBrushS;
				break;
			}
			case TURN_ANZ:
			{
				warchestBrushes[idx0][idx1] = anzBrushP;
				warchestValBrushes[idx0][idx1] = anzBrushS;
				break;
			}
			case TURN_FRA:
			{
				warchestBrushes[idx0][idx1] = fraBrushP;
				warchestValBrushes[idx0][idx1] = fraBrushS;
				break;
			}
			default:
			{
				warchestBrushes[idx0][idx1] = backBrush;
				warchestValBrushes[idx0][idx1] = backBrush;
				break;
			}
			}
		}

		// Match the shade of the last line of mini spread
		warchestBrushes[0][0] = b0;
		warchestValBrushes[0][0] = b0;
	}
}

void WarchestSection::resetWarchestBox()
{
	natOrder.resize(0);

	for (int i = 0; i < 9; i++)
	{
		wcsncpy_s(natText[i].t, L"", 2);
		wcsncpy_s(natVals[i].t, L"", 2);
	}
}

void WarchestSection::drawWarchestBox(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		warchestFrame->drawFrame(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				warchestBoxes[i][j]->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
				warchestValBoxes[i][j]->drawFrame(graphics, pen, baseTextFont, textFormat, textBrush, backBrush, layers);
			}

		warchestCone->drawQuad(graphics, borderPen, paneBrush, layers);
	}
	else // Actual graphics
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				int idx = (i * 3) + j;
				if (idx != 0)
				{
					warchestBoxes[i][j]->drawBox(graphics, pen, natFont, textFormat, textBrush,
						warchestBrushes[i][j], natText[idx].t, layers);
					warchestValBoxes[i][j]->drawBox(graphics, pen, baseTextFont, textFormat, textBrush,
						warchestValBrushes[i][j], natVals[idx].t, layers);

					if (ukPos.size() > 0 && ukPos[idx])
						warchestUKValBox->drawBox(graphics, pen, baseTextFont, textFormat, textBrush,
							warchestValBrushes[i][j], ukVal.t, layers);
				}
				else
					warchestBoxes[0][0]->drawBox(graphics, pen, natFont, textFormat, textBrush,
						warchestBrushes[0][0], L"", layers);
			}

		warchestCone->drawQuad(graphics, pen, warchestBrushes[0][0], layers);
	}
}

void WarchestSection::valConv(wcText* c, int bank, int incm)
{
	int idx = 0;

	// Bank
	if (bank > 999)
	{
		c->t[0] = uint2char_(bank / 1000);
		c->t[1] = uint2char_((bank % 1000) / 100);
		c->t[2] = uint2char_((bank % 100) / 10);
		c->t[3] = uint2char_(bank % 10);
		c->t[4] = '/';
		idx = 5;
	}
	else if (bank > 99)
	{
		c->t[0] = uint2char_(bank / 100);
		c->t[1] = uint2char_((bank % 100) / 10);
		c->t[2] = uint2char_(bank % 10);
		c->t[3] = '/';
		idx = 4;
	}
	else if (bank > 9)
	{
		c->t[0] = uint2char_(bank / 10);
		c->t[1] = uint2char_(bank % 10);
		c->t[2] = '/';
		idx = 3;
	}
	else
	{
		c->t[0] = uint2char_(bank);
		c->t[1] = '/';
		idx = 2;
	}

	// Income
	if (incm > 99)
	{
		c->t[idx + 0] = uint2char_(incm / 100);
		c->t[idx + 1] = uint2char_((incm % 100) / 10);
		c->t[idx + 2] = uint2char_(incm % 10);
		c->t[idx + 3] = '\0';
	}
	else if (incm > 9)
	{
		c->t[idx + 0] = uint2char_(incm / 10);
		c->t[idx + 1] = uint2char_(incm % 10);
		c->t[idx + 2] = '\0';
	}
	else
	{
		c->t[idx + 0] = uint2char_(incm);
		c->t[idx + 1] = '\0';
	}
}
