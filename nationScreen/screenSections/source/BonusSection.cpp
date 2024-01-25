#include "../header/BonusSection.h"

BonusSection::BonusSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	bonusFrame = new AABox("Bonus Section");

	bonusHead[BONS_OBJ] = new AABox("Objective");
	bonusHead[BONS_CON] = new AABox("Condition");
	bonusHead[BONS_BNS] = new AABox("Bonus");
	bonusHead[BONS_STS] = new AABox("Status");

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < BONS_COLS; j++)
			bonus4Box[i][j] = new AABox("Cell 4");

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < BONS_COLS; j++)
			bonus6Box[i][j] = new AABox("Cell 6");

	bonusText.resize(0);

	bonusSel = BONS_6;
	natIdx = TURN_NON;

	headFont = NULL;
	bonusBrushP = NULL; bonusBrushS = NULL; bonusBrushF = NULL;
	bonusBrush = NULL;
}

BonusSection::~BonusSection()
{
	delete bonusFrame;

	for (int i = 0; i < BONS_COLS; i++)
		delete bonusHead[i];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < BONS_COLS; j++)
			delete bonus4Box[i][j];

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < BONS_COLS; j++)
			delete bonus6Box[i][j];
}

void BonusSection::configureBonusBox(RectF& frame, int layer)
{
	bonusFrame->config(frame, layer);

	bonusHead[BONS_OBJ]->config(bonusFrame->box, layer + 1);
	bonusHead[BONS_OBJ]->box.Width = bonusFrame->box.Width / 2;
	bonusHead[BONS_OBJ]->box.Height = bonusFrame->box.Height / 16;

	bonusHead[BONS_CON]->config(bonusHead[BONS_OBJ]->box, layer + 1);
	bonusHead[BONS_CON]->box.X = bonusHead[BONS_OBJ]->box.GetRight();
	bonusHead[BONS_CON]->box.Width = bonusFrame->box.Width / 4;

	bonusHead[BONS_BNS]->config(bonusHead[BONS_CON]->box, layer + 1);
	bonusHead[BONS_BNS]->box.X = bonusHead[BONS_CON]->box.GetRight();
	bonusHead[BONS_BNS]->box.Width = bonusFrame->box.Width / 8;

	bonusHead[BONS_STS]->config(bonusHead[BONS_BNS]->box, layer + 1);
	bonusHead[BONS_STS]->box.X = bonusHead[BONS_BNS]->box.GetRight();
	bonusHead[BONS_STS]->box.Width = bonusFrame->box.GetRight() - bonusHead[BONS_STS]->box.X;

	for (int i = 0; i < BONS_COLS; i++)
	{
		bonus4Box[0][i]->config(bonusHead[i]->box, layer + 1);
		bonus4Box[0][i]->box.Y = bonusHead[i]->box.GetBottom();
		bonus4Box[0][i]->box.Height = (bonusFrame->box.GetBottom() - bonus4Box[0][i]->box.Y) / 4;

		bonus6Box[0][i]->config(bonusHead[i]->box, layer + 1);
		bonus6Box[0][i]->box.Y = bonusHead[i]->box.GetBottom();
		bonus6Box[0][i]->box.Height = (bonusFrame->box.GetBottom() - bonus4Box[0][i]->box.Y) / 6;
	}

	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < BONS_COLS; j++)
		{
			bonus4Box[i][j]->config(bonus4Box[i - 1][j]->box, layer + 1);
			bonus4Box[i][j]->box.Y = bonus4Box[i - 1][j]->box.GetBottom();
		}
	}

	for (int i = 1; i < 6; i++)
	{
		for (int j = 0; j < BONS_COLS; j++)
		{
			bonus6Box[i][j]->config(bonus6Box[i - 1][j]->box, layer + 1);
			bonus6Box[i][j]->box.Y = bonus6Box[i - 1][j]->box.GetBottom();
		}
	}
}

void BonusSection::configDrawTools(Font* f0)
{
	headFont = f0;
}

void BonusSection::updateBonusFormat(int gameType, int nat)
{
	switch (nat)
	{
	case TURN_GER:
	{
		bonusBrushP = gerBrushP;
		bonusBrushS = gerBrushS;
		bonusBrushF = gerBrushF;
		bonusSel = BONS_6;
		break;
	}
	case TURN_SOV:
	{
		bonusBrushP = sovBrushP;
		bonusBrushS = sovBrushS;
		bonusBrushF = sovBrushF;
		bonusSel = BONS_4;
		break;
	}
	case TURN_JPN:
	{
		bonusBrushP = jpnBrushP;
		bonusBrushS = jpnBrushS;
		bonusBrushF = jpnBrushF;
		bonusSel = BONS_4;
		break;
	}
	case TURN_USA:
	{
		bonusBrushP = usaBrushP;
		bonusBrushS = usaBrushS;
		bonusBrushF = usaBrushF;
		if (gameType == EUROPE_GAME)
			bonusSel = BONS_4;
		else
			bonusSel = BONS_6;
		break;
	}
	case TURN_CHN:
	{
		bonusBrushP = chnBrushP;
		bonusBrushS = chnBrushS;
		bonusBrushF = chnBrushF;
		bonusSel = BONS_4;
		break;
	}
	case TURN_UKE: case TURN_UKP:
	{
		bonusBrushP = ukBrushP;
		bonusBrushS = ukBrushS;
		bonusBrushF = ukBrushF;
		bonusSel = BONS_4;
		break;
	}
	case TURN_ITA:
	{
		bonusBrushP = itaBrushP;
		bonusBrushS = itaBrushS;
		bonusBrushF = itaBrushF;
		bonusSel = BONS_4;
		break;
	}
	case TURN_ANZ:
	{
		bonusBrushP = anzBrushP;
		bonusBrushS = anzBrushS;
		bonusBrushF = anzBrushF;
		bonusSel = BONS_4;
		break;
	}
	case TURN_FRA:
	{
		bonusBrushP = fraBrushP;
		bonusBrushS = fraBrushS;
		bonusBrushF = fraBrushF;
		bonusSel = BONS_4;
		break;
	}
	default: break;
	}
}

void BonusSection::updateBonusText(int gameType, int nat, int bonus, int bonusVal, bool bonusBin)
{
	// Initialize bonus text if first time
	if (bonusText.size() == 0)
	{
		switch (gameType)
		{
		case EUROPE_GAME:
		{
			bonusText.resize(6);
			configGerBonusText(0);
			configSovBonusText(1);
			configUsaBonusText(2, gameType);
			configUkBonusText(3, gameType);
			configItaBonusText(4);
			configFraBonusText(5);
			break;
		}
		case PACIFIC_GAME:
		{
			bonusText.resize(5);
			configJpnBonusText(0);
			configUsaBonusText(1, gameType);
			configChnBonusText(2);
			configUkBonusText(3, gameType);
			configAnzBonusText(4);
			break;
		}
		case GLOBAL_GAME:
		{
			bonusText.resize(9);
			configGerBonusText(0);
			configSovBonusText(1);
			configJpnBonusText(2);
			configUsaBonusText(3, gameType);
			configChnBonusText(4);
			configUkBonusText(5, gameType);
			configItaBonusText(6);
			configAnzBonusText(7);
			configFraBonusText(8);
			break;
		}
		default:
			break;
		}
	}

	// Set nation location in vector of bonus texts
	switch (gameType)
	{
	case EUROPE_GAME:
	{
		switch (nat)
		{
		case TURN_GER:
			natIdx = 0;
			break;
		case TURN_SOV:
			natIdx = 1;
			break;
		case TURN_USA:
			natIdx = 2;
			break;
		case TURN_UKE:
			natIdx = 3;
			break;
		case TURN_ITA:
			natIdx = 4;
			break;
		case TURN_FRA:
			natIdx = 5;
			break;
		default:
			natIdx = TURN_NON;
			break;
		}
		break;
	}
	case PACIFIC_GAME:
	{
		switch (nat)
		{
		case TURN_JPN:
			natIdx = 0;
			break;
		case TURN_USA:
			natIdx = 1;
			break;
		case TURN_CHN:
			natIdx = 2;
			break;
		case TURN_UKP:
			natIdx = 3;
			break;
		case TURN_ANZ:
			natIdx = 4;
			break;
		default:
			natIdx = TURN_NON;
			break;
		}
		break;
	}
	case GLOBAL_GAME:
	{
		switch (nat)
		{
		case TURN_GER:
			natIdx = 0;
			break;
		case TURN_SOV:
			natIdx = 1;
			break;
		case TURN_JPN:
			natIdx = 2;
			break;
		case TURN_USA:
			natIdx = 3;
			break;
		case TURN_CHN:
			natIdx = 4;
			break;
		case TURN_UKE: case TURN_UKP:
			natIdx = 5;
			break;
		case TURN_ITA:
			natIdx = 6;
			break;
		case TURN_ANZ:
			natIdx = 7;
			break;
		case TURN_FRA:
			natIdx = 8;
			break;
		default:
			natIdx = TURN_NON;
			break;
		}
		break;
	}
	default:
		break;
	}

	// Update bonuses by nation
	switch (nat)
	{
	case TURN_GER:
	{
		switch (bonus)
		{
		case BONS_GER_SOV:
			valConv(&bonusText[natIdx][BONS_GER_SOV], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_GER_CTY:
			valConv(&bonusText[natIdx][BONS_GER_CTY], BONS_CNT_TYP, bonusVal, false);
			break;
		case BONS_GER_CAU:
			valConv(&bonusText[natIdx][BONS_GER_CAU], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_GER_EGY:
			valConv(&bonusText[natIdx][BONS_GER_EGY], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_GER_DEN:
			valConv(&bonusText[natIdx][BONS_GER_DEN], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_GER_PER:
			valConv(&bonusText[natIdx][BONS_GER_PER], BONS_CNT_TYP, bonusVal, false);
			break;
		default:
			break;
		}
		break;
	}
	case TURN_SOV:
	{
		switch (bonus)
		{
		case BONS_SOV_SEA:
			valConv(&bonusText[natIdx][BONS_SOV_SEA], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_SOV_AXT:
			valConv(&bonusText[natIdx][BONS_SOV_AXT], BONS_CNT_TYP, bonusVal, false);
			break;
		case BONS_SOV_GER:
			valConv(&bonusText[natIdx][BONS_SOV_GER], BONS_AWD_TYP, BONS_NON, bonusBin);
			break;
		default:
			break;
		}
		break;
	}
	case TURN_JPN:
	{
		switch (bonus)
		{
		case BONS_JPN_UKZ:
			valConv(&bonusText[natIdx][BONS_JPN_UKZ], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_JPN_ISL:
			valConv(&bonusText[natIdx][BONS_JPN_ISL], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_JPN_TER:
			valConv(&bonusText[natIdx][BONS_JPN_TER], BONS_CNT_TYP, bonusVal, false);
			break;
		case BONS_JPN_JAV:
			valConv(&bonusText[natIdx][BONS_JPN_JAV], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		default:
			break;
		}
		break;
	}
	case TURN_USA:
	{
		if (gameType == EUROPE_GAME)
		{
			switch (bonus)
			{
			case BONS_USA_USA:
				valConv(&bonusText[natIdx][BONS_USA_USA], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_EUR_TER:
				valConv(&bonusText[natIdx][BONS_USA_USA], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			default:
				break;
			}
		}
		else if (gameType == PACIFIC_GAME)
		{
			switch (bonus)
			{
			case BONS_USA_USA:
				valConv(&bonusText[natIdx][BONS_USA_USA], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_PAC_TER:
				valConv(&bonusText[natIdx][BONS_USA_PAC_TER], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_PAC_ISL:
				valConv(&bonusText[natIdx][BONS_USA_PAC_ISL], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_PHI:
				valConv(&bonusText[natIdx][BONS_USA_PHI], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_PAC_WAR:
				valConv(&bonusText[natIdx][BONS_USA_PAC_WAR], BONS_AWD_TYP, BONS_NON, bonusBin);
				break;
			default:
				break;
			}
		}
		else if (gameType == GLOBAL_GAME)
		{
			switch (bonus)
			{
			case BONS_USA_USA:
				valConv(&bonusText[natIdx][BONS_USA_USA], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_GLO_ISL:
				valConv(&bonusText[natIdx][BONS_USA_GLO_ISL], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_GLO_TER:
				valConv(&bonusText[natIdx][BONS_USA_GLO_TER], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_PHI:
				valConv(&bonusText[natIdx][BONS_USA_PHI], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_GLO_FRA:
				valConv(&bonusText[natIdx][BONS_USA_GLO_FRA], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_USA_GLO_WAR:
				valConv(&bonusText[natIdx][BONS_USA_GLO_WAR], BONS_AWD_TYP, BONS_NON, bonusBin);
				break;
			default:
				break;
			}
		}
		break;
	}
	case TURN_CHN:
	{
		switch (bonus)
		{
		case BONS_CHN_BUR:
			valConv(&bonusText[natIdx][BONS_CHN_BUR], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		default:
			break;
		}
		break;
	}
	case TURN_UKE: case TURN_UKP:
	{
		if (gameType == EUROPE_GAME)
		{
			switch (bonus)
			{
			case BONS_UKE_TER:
				valConv(&bonusText[natIdx][BONS_UKE_TER], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			default:
				break;
			}
		}
		else if (gameType == PACIFIC_GAME)
		{
			switch (bonus)
			{
			case BONS_UKP_TER:
				valConv(&bonusText[natIdx][BONS_UKP_TER], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			default:
				break;
			}
		}
		else if (gameType == GLOBAL_GAME)
		{
			switch (bonus)
			{
			case BONS_UKE_TER:
				valConv(&bonusText[natIdx][BONS_UKE_TER], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			case BONS_UKP_GLO_TER:
				valConv(&bonusText[natIdx][BONS_UKP_GLO_TER], BONS_MET_TYP, BONS_NON, bonusBin);
				break;
			default:
				break;
			}
		}
		break;
	}
	case TURN_ITA:
	{
		switch (bonus)
		{
		case BONS_ITA_GIB:
			valConv(&bonusText[natIdx][BONS_ITA_GIB], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_ITA_MED:
			valConv(&bonusText[natIdx][BONS_ITA_MED], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_ITA_AFR:
			valConv(&bonusText[natIdx][BONS_ITA_AFR], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_ITA_PER:
			valConv(&bonusText[natIdx][BONS_ITA_AFR], BONS_CNT_TYP, BONS_NON, bonusBin);
			break;
		default:
			break;
		}
		break;
	}
	case TURN_ANZ:
	{
		switch (bonus)
		{
		case BONS_ANZ_TER:
			valConv(&bonusText[natIdx][BONS_ANZ_TER], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		case BONS_ANZ_ISL:
			valConv(&bonusText[natIdx][BONS_ANZ_ISL], BONS_MET_TYP, BONS_NON, bonusBin);
			break;
		default:
			break;
		}
		break;
	}
	case TURN_FRA:
	{
		switch (bonus)
		{
		case BONS_FRA_LIB:
			valConv(&bonusText[natIdx][BONS_FRA_LIB], BONS_AWD_TYP, BONS_NON, bonusBin);
			break;
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}

void BonusSection::resetBonusBox()
{
	bonusText.resize(0);
}

void BonusSection::configGerBonusText(int idx)
{
	bonusText[idx].resize(6);

	wcsncpy_s(bonusText[idx][BONS_GER_SOV].obj, L"Not at war with Soviet Union", 29);
	wcsncpy_s(bonusText[idx][BONS_GER_SOV].con, L"", 1);
	wcsncpy_s(bonusText[idx][BONS_GER_SOV].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_GER_SOV].sts, L"Met", 4);

	wcsncpy_s(bonusText[idx][BONS_GER_CTY].obj, L"Control Novgorod, Volgograd, and/or Russia", 43);
	wcsncpy_s(bonusText[idx][BONS_GER_CTY].con, L"At war with Soviet Union", 25);
	wcsncpy_s(bonusText[idx][BONS_GER_CTY].bon, L"5 Each", 7);
	wcsncpy_s(bonusText[idx][BONS_GER_CTY].sts, L"0 Met", 6);

	wcsncpy_s(bonusText[idx][BONS_GER_CAU].obj, L"Axis power controls Caucuses", 29);
	wcsncpy_s(bonusText[idx][BONS_GER_CAU].con, L"At war with Soviet Union", 25);
	wcsncpy_s(bonusText[idx][BONS_GER_CAU].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_GER_CAU].sts, L"Unmet", 6);

	wcsncpy_s(bonusText[idx][BONS_GER_EGY].obj, L"German land unit in Egypt", 26);
	wcsncpy_s(bonusText[idx][BONS_GER_EGY].con, L"At war in Europe", 17);
	wcsncpy_s(bonusText[idx][BONS_GER_EGY].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_GER_EGY].sts, L"Unmet", 6);

	wcsncpy_s(bonusText[idx][BONS_GER_DEN].obj, L"Control Denmark and Norway", 27);
	wcsncpy_s(bonusText[idx][BONS_GER_DEN].con, L"Sweden is neither pro-Allies nor Allies-controlled", 51);
	wcsncpy_s(bonusText[idx][BONS_GER_DEN].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_GER_DEN].sts, L"Met", 4);

	wcsncpy_s(bonusText[idx][BONS_GER_PER].obj, L"Control Iraq, Persia, and/or Northwest Persia", 46);
	wcsncpy_s(bonusText[idx][BONS_GER_PER].con, L"At war in Europe", 17);
	wcsncpy_s(bonusText[idx][BONS_GER_PER].bon, L"2 Each", 7);
	wcsncpy_s(bonusText[idx][BONS_GER_PER].sts, L"0 Met", 6);
}

void BonusSection::configSovBonusText(int idx)
{
	bonusText[idx].resize(3);

	wcsncpy_s(bonusText[idx][BONS_SOV_SEA].obj, L"Convoy in Sea Zone 125 is free of Axis warships, control Archangel, and no Allied units in original Soviet territories", 119);
	wcsncpy_s(bonusText[idx][BONS_SOV_SEA].con, L"At war in Europe", 17);
	wcsncpy_s(bonusText[idx][BONS_SOV_SEA].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_SOV_SEA].sts, L"Unmet", 6);

	wcsncpy_s(bonusText[idx][BONS_SOV_AXT].obj, L"Control original German, Italian, or Pro-Axis neutral territory", 64);
	wcsncpy_s(bonusText[idx][BONS_SOV_AXT].con, L"At war in Europe", 17);
	wcsncpy_s(bonusText[idx][BONS_SOV_AXT].bon, L"3 Each", 7);
	wcsncpy_s(bonusText[idx][BONS_SOV_AXT].sts, L"0 Met", 6);

	wcsncpy_s(bonusText[idx][BONS_SOV_GER].obj, L"Capture Germany", 16);
	wcsncpy_s(bonusText[idx][BONS_SOV_GER].con, L"One time only", 14);
	wcsncpy_s(bonusText[idx][BONS_SOV_GER].bon, L"10", 3);
	wcsncpy_s(bonusText[idx][BONS_SOV_GER].sts, L"Not Awarded", 12);
}

void BonusSection::configJpnBonusText(int idx)
{
	bonusText[idx].resize(4);

	wcsncpy_s(bonusText[idx][BONS_JPN_UKZ].obj, L"Have not attacked French Indo-China, have not declared war on United Kingdom/ANZAC", 83);
	wcsncpy_s(bonusText[idx][BONS_JPN_UKZ].con, L"Not at war with USA", 20);
	wcsncpy_s(bonusText[idx][BONS_JPN_UKZ].bon, L"10", 3);
	wcsncpy_s(bonusText[idx][BONS_JPN_UKZ].sts, L"Met", 4);

	wcsncpy_s(bonusText[idx][BONS_JPN_ISL].obj, L"Axis powers control Guam, Midway, Wake Island, Gilbert Islands, and Solomon Islands", 84);
	wcsncpy_s(bonusText[idx][BONS_JPN_ISL].con, L"At war with Western Allies", 27);
	wcsncpy_s(bonusText[idx][BONS_JPN_ISL].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_JPN_ISL].sts, L"Unmet", 6);

	wcsncpy_s(bonusText[idx][BONS_JPN_TER].obj, L"Axis powers control India, New South Wales, Hawaiian Islands, and/or Western United States", 91);
	wcsncpy_s(bonusText[idx][BONS_JPN_TER].con, L"At war with Western Allies", 27);
	wcsncpy_s(bonusText[idx][BONS_JPN_TER].bon, L"5 Each", 7);
	wcsncpy_s(bonusText[idx][BONS_JPN_TER].sts, L"0 Met", 6);

	wcsncpy_s(bonusText[idx][BONS_JPN_JAV].obj, L"Axis powers control Sumatra, Java, Borneo, and Celebes", 55);
	wcsncpy_s(bonusText[idx][BONS_JPN_JAV].con, L"At war with Western Allies", 27);
	wcsncpy_s(bonusText[idx][BONS_JPN_JAV].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_JPN_JAV].sts, L"Unmet", 6);
}

void BonusSection::configUsaBonusText(int idx, int gameType)
{
	if (gameType == EUROPE_GAME)
	{
		bonusText[idx].resize(2);

		wcsncpy_s(bonusText[idx][BONS_USA_USA].obj, L"Control Eastern United States and Central United States", 56);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].bon, L"20", 3);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].sts, L"Unmet", 6);

		wcsncpy_s(bonusText[idx][BONS_USA_EUR_TER].obj, L"Control South Eastern Mexico, Central America, and West Indies", 63);
		wcsncpy_s(bonusText[idx][BONS_USA_EUR_TER].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_EUR_TER].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_USA_EUR_TER].sts, L"Unmet", 6);
	}
	else if (gameType == PACIFIC_GAME)
	{
		bonusText[idx].resize(5);

		wcsncpy_s(bonusText[idx][BONS_USA_USA].obj, L"Control Western United States", 30);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].bon, L"30", 3);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].sts, L"Unmet", 6);
		
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_TER].obj, L"Control Alaska and Mexico", 26);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_TER].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_TER].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_TER].sts, L"Unmet", 6);

		wcsncpy_s(bonusText[idx][BONS_USA_PAC_ISL].obj, L"Control Aleutian Islands, Hawaiian Islands, Johnston Island, and Line Islands", 78);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_ISL].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_ISL].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_ISL].sts, L"Unmet", 6);

		wcsncpy_s(bonusText[idx][BONS_USA_PHI].obj, L"Control Philippines", 20);
		wcsncpy_s(bonusText[idx][BONS_USA_PHI].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_PHI].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_USA_PHI].sts, L"Unmet", 6);
		
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_WAR].obj, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_WAR].con, L"Axis declared upon USA (IPCs only)", 43);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_WAR].bon, L"Upgrade ICs, 30 IPCs", 21);
		wcsncpy_s(bonusText[idx][BONS_USA_PAC_WAR].sts, L"Not Awarded", 12);
	}
	else if (gameType == GLOBAL_GAME)
	{
		bonusText[idx].resize(6);

		wcsncpy_s(bonusText[idx][BONS_USA_USA].obj, L"Control Eastern United States, Central United States, and Western United States", 80);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].bon, L"10", 3);
		wcsncpy_s(bonusText[idx][BONS_USA_USA].sts, L"Unmet", 6);

		wcsncpy_s(bonusText[idx][BONS_USA_GLO_ISL].obj, L"Control Alaska, Aleutian Islands, Hawaiian Islands, Johnston Island, and Line Islands", 86);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_ISL].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_ISL].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_ISL].sts, L"Unmet", 6);

		wcsncpy_s(bonusText[idx][BONS_USA_GLO_TER].obj, L"Control Mexico, South Eastern Mexico, Central America, and West Indies", 71);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_TER].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_TER].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_TER].sts, L"Unmet", 6);

		wcsncpy_s(bonusText[idx][BONS_USA_PHI].obj, L"Control Philippines", 20);
		wcsncpy_s(bonusText[idx][BONS_USA_PHI].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_PHI].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_USA_PHI].sts, L"Unmet", 6);

		wcsncpy_s(bonusText[idx][BONS_USA_GLO_FRA].obj, L"At least one United States land unit in France", 47);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_FRA].con, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_FRA].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_FRA].sts, L"Unmet", 6);

		wcsncpy_s(bonusText[idx][BONS_USA_GLO_WAR].obj, L"At war", 7);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_WAR].con, L"", 1);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_WAR].bon, L"Upgrade ICs", 12);
		wcsncpy_s(bonusText[idx][BONS_USA_GLO_WAR].sts, L"Not Awarded", 12);
	}
}

void BonusSection::configChnBonusText(int idx)
{
	bonusText[idx].resize(1);

	wcsncpy_s(bonusText[idx][BONS_CHN_BUR].obj, L"Burma road is totally open", 27);
	wcsncpy_s(bonusText[idx][BONS_CHN_BUR].con, L"At war", 7);
	wcsncpy_s(bonusText[idx][BONS_CHN_BUR].bon, L"6, can purchase artillery", 26);
	wcsncpy_s(bonusText[idx][BONS_CHN_BUR].sts, L"Met", 4);
}

void BonusSection::configUkBonusText(int idx, int gameType)
{
	int pacIdx = BONS_UKP_TER;
	if (gameType == GLOBAL_GAME)
	{
		bonusText[idx].resize(2);
		pacIdx = BONS_UKP_GLO_TER;
	}
	else
		bonusText[idx].resize(1);

	if (gameType != PACIFIC_GAME)
	{
		wcsncpy_s(bonusText[idx][BONS_UKE_TER].obj, L"Control all original territories in Europe economy", 51);
		wcsncpy_s(bonusText[idx][BONS_UKE_TER].con, L"At war in Europe", 17);
		wcsncpy_s(bonusText[idx][BONS_UKE_TER].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][BONS_UKE_TER].sts, L"Met", 4);
	}

	if (gameType != EUROPE_GAME)
	{
		wcsncpy_s(bonusText[idx][pacIdx].obj, L"Control Kwangtung and Malaya", 29);
		wcsncpy_s(bonusText[idx][pacIdx].con, L"At war with Japan", 18);
		wcsncpy_s(bonusText[idx][pacIdx].bon, L"5", 2);
		wcsncpy_s(bonusText[idx][pacIdx].sts, L"Unmet", 6);
	}
}

void BonusSection::configItaBonusText(int idx)
{
	bonusText[idx].resize(4);

	wcsncpy_s(bonusText[idx][BONS_ITA_GIB].obj, L"Axis powers control at least three of Gibraltar, Southern France, Greece, and Egypt", 84);
	wcsncpy_s(bonusText[idx][BONS_ITA_GIB].con, L"At war", 7);
	wcsncpy_s(bonusText[idx][BONS_ITA_GIB].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_ITA_GIB].sts, L"Unmet", 6);

	wcsncpy_s(bonusText[idx][BONS_ITA_MED].obj, L"No Allied surface warships in Mediterranean Sea", 48);
	wcsncpy_s(bonusText[idx][BONS_ITA_MED].con, L"At war", 7);
	wcsncpy_s(bonusText[idx][BONS_ITA_MED].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_ITA_MED].sts, L"Unmet", 6);

	wcsncpy_s(bonusText[idx][BONS_ITA_AFR].obj, L"Axis powers control Morocco, Algeria, Tunisia, Libya, Tobruk, and Alexandria", 77);
	wcsncpy_s(bonusText[idx][BONS_ITA_AFR].con, L"At war", 7);
	wcsncpy_s(bonusText[idx][BONS_ITA_AFR].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_ITA_AFR].sts, L"Unmet", 6);

	wcsncpy_s(bonusText[idx][BONS_ITA_PER].obj, L"Italy controls Iraq, Persia, and/or Northwest Persia", 53);
	wcsncpy_s(bonusText[idx][BONS_ITA_PER].con, L"At war", 7);
	wcsncpy_s(bonusText[idx][BONS_ITA_PER].bon, L"2 Each", 7);
	wcsncpy_s(bonusText[idx][BONS_ITA_PER].sts, L"0 Met", 6);
}

void BonusSection::configAnzBonusText(int idx)
{
	bonusText[idx].resize(2);
	
	wcsncpy_s(bonusText[idx][BONS_ANZ_TER].obj, L"Allied power controls Malaya and ANZAC controls all original territory", 71);
	wcsncpy_s(bonusText[idx][BONS_ANZ_TER].con, L"At war with Japan", 18);
	wcsncpy_s(bonusText[idx][BONS_ANZ_TER].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_ANZ_TER].sts, L"Unmet", 6);

	wcsncpy_s(bonusText[idx][BONS_ANZ_ISL].obj, L"Allies control Dutch New Guinea, New Guinea, New Britain, and Solomon Islands", 78);
	wcsncpy_s(bonusText[idx][BONS_ANZ_ISL].con, L"At war with Japan", 18);
	wcsncpy_s(bonusText[idx][BONS_ANZ_ISL].bon, L"5", 2);
	wcsncpy_s(bonusText[idx][BONS_ANZ_ISL].sts, L"Unmet", 6);
}

void BonusSection::configFraBonusText(int idx)
{
	bonusText[idx].resize(1);
	
	wcsncpy_s(bonusText[idx][BONS_FRA_LIB].obj, L"France has been liberated", 26);
	wcsncpy_s(bonusText[idx][BONS_FRA_LIB].con, L"One time only", 14);
	wcsncpy_s(bonusText[idx][BONS_FRA_LIB].bon, L"Place 12 IPC's worth of units for free", 39);
	wcsncpy_s(bonusText[idx][BONS_FRA_LIB].sts, L"Not Awarded", 12);
}

void BonusSection::drawBonusBox(Graphics* graphics, DBG& dbg)
{
	if (dbg.boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg.sections) // Show box names
	{
		bonusFrame->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, dbg.layers);

		for (int i = 0; i < BONS_COLS; i++)
			bonusHead[i]->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);

		if (bonusSel == BONS_4)
		{
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < BONS_COLS; j++)
					bonus4Box[i][j]->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		}
		else if (bonusSel == BONS_6)
		{
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < BONS_COLS; j++)
					bonus6Box[i][j]->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		}
	}
	else // Actual graphics
	{
		for (int i = 0; i < BONS_COLS; i++)
			bonusHead[i]->drawFrameFill(graphics, borderPen, headFont, centerFormat, textBrush, bonusBrushP, dbg.layers);

		if (bonusSel == BONS_4)
		{
			for (int i = 0; i < bonusText[natIdx].size(); i++)
			{
				bonusBrush = (i % 2 == 1) ? bonusBrushP : bonusBrushS;
				bonus4Box[i][BONS_OBJ]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].obj, dbg.layers);
				bonus4Box[i][BONS_CON]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].con, dbg.layers);
				bonus4Box[i][BONS_BNS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].bon, dbg.layers);
				bonus4Box[i][BONS_STS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].sts, dbg.layers);
			}

			for (int i = bonusText[natIdx].size(); i < 4; i++)
			{
				bonus4Box[i][BONS_OBJ]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrushF, L"", dbg.layers);
				bonus4Box[i][BONS_CON]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrushF, L"", dbg.layers);
				bonus4Box[i][BONS_BNS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrushF, L"", dbg.layers);
				bonus4Box[i][BONS_STS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrushF, L"", dbg.layers);
			}
		}
		else if (bonusSel == BONS_6)
		{
			for (int i = 0; i < bonusText[natIdx].size(); i++)
			{
				bonusBrush = (i % 2 == 1) ? bonusBrushP : bonusBrushS;
				bonus6Box[i][BONS_OBJ]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].obj, dbg.layers);
				bonus6Box[i][BONS_CON]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].con, dbg.layers);
				bonus6Box[i][BONS_BNS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].bon, dbg.layers);
				bonus6Box[i][BONS_STS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].sts, dbg.layers);
			}

			for (int i = bonusText[natIdx].size(); i < 6; i++)
			{
				bonus6Box[i][BONS_OBJ]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrushF, L"", dbg.layers);
				bonus6Box[i][BONS_CON]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrushF, L"", dbg.layers);
				bonus6Box[i][BONS_BNS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrushF, L"", dbg.layers);
				bonus6Box[i][BONS_STS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrushF, L"", dbg.layers);
			}
		}
	}
}

void BonusSection::drawBonusBox(Graphics* graphics, bool valsOnly, DBG& dbg)
{
	if (dbg.boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg.sections) // Show box names
	{
		
	}
	else // Actual graphics
	{
		if (bonusSel == BONS_4)
		{
			for (int i = 0; i < bonusText[natIdx].size(); i++)
			{
				bonusBrush = (i % 2 == 1) ? bonusBrushP : bonusBrushS;
				bonus4Box[i][BONS_STS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].sts, dbg.layers);
			}
		}
		else if (bonusSel == BONS_6)
		{
			for (int i = 0; i < bonusText[natIdx].size(); i++)
			{
				bonusBrush = (i % 2 == 1) ? bonusBrushP : bonusBrushS;
				bonus6Box[i][BONS_STS]->drawBox(graphics, borderPen, baseTextFont, centerFormat, textBrush, bonusBrush, bonusText[natIdx][i].sts, dbg.layers);
			}
		}
	}
}

void BonusSection::valConv(bonus_text* bons, int typ, int val, bool bin)
{
	switch (typ)
	{
	case BONS_MET_TYP:
	{
		if (bin)
			wcsncpy_s(bons->sts, L"Met", 4);
		else
			wcsncpy_s(bons->sts, L"Unmet", 6);
		break;
	}
	case BONS_CNT_TYP:
	{
		bons->sts[0] = int2char_(val);
		break;
	}
	case BONS_AWD_TYP:
	{
		if (bin)
			wcsncpy_s(bons->sts, L"Awarded", 8);
		else
			wcsncpy_s(bons->sts, L"Not Awarded", 12);
		break;
	}
	default:
		break;
	}
}
