#include "AA_Tracker.h"
#include "BoardClass.h"

vector<bonusTransaction>* Board::getBonusUpdate()
{
	return bonuses->getBonusUpdate();
}

void Board::resetBonusUpdate()
{
	bonuses->resetBonusUpdate();
}

void Board::updateBonuses(HWND hDlg, int nat, bool popups, int transferVal)
{
	bonuses->updateBonuses(hDlg, nations, warMatrix, territories, gameTurn, nat, popups, transferVal);

	/*

	uint16_t total = 0;

	bool jpnCond = (this->getAtWarWith(TURN_JPN, TURN_UKE) == true && this->getAtWarWith(TURN_JPN, TURN_USA) == true);

	switch (nat)
	{
	case TURN_GER:
	{
		if (this->getAtWarWith(TURN_GER, TURN_SOV) == true) // notAtWarWithSovBonus
			nations[TURN_GER]->updateBonus(0, 0, false);
		else
			total += 5;

		uint16_t cnt = 0;
		if (territories[TER_NOVGOROD].owner == TURN_GER) // controlSovTerrBonus
			cnt++;
		if (territories[TER_VOLGOGRAD].owner == TURN_GER)
			cnt++;
		if (territories[TER_RUSSIA].owner == TURN_GER)
			cnt++;
		if (this->getAtWarWith(TURN_GER, TURN_SOV) == true)
			nations[TURN_GER]->updateBonus(1, cnt, false);
		total += 5 * cnt;

		if (this->getAtWarWith(TURN_GER, TURN_SOV) == true) // axisCaucusBonus
		{
			if (territories[TER_CAUCASUS].side == SIDE_AXIS)
			{
				nations[TURN_GER]->updateBonus(2, 0, true);
				total += 5;
			}
			else
				nations[TURN_GER]->updateBonus(2, 0, false);
		}
			
		if (territories[TER_EGYPT].side == TURN_GER && popups == true) // gerEgyptBonus
		{
			int msgboxID = MessageBox(hDlg, L"Is there a German land unit\nin Egypt?",
				L"Bonus Info", MB_YESNO);

			if (msgboxID == IDYES)
			{
				nations[TURN_GER]->updateBonus(3, 0, true);
				total += 5;
			}
			else
				nations[TURN_GER]->updateBonus(3, 0, false);
		}
		else if (popups == false && nations[TURN_GER]->checkBonus(3, true) == true)
			total += 5;

		if (((territories[TER_SWEDEN].owner == FULL_NEUTRAL) && allyNeutralLean == false) || // denNorBonus
			territories[TER_SWEDEN].side == SIDE_AXIS)
		{
			if (territories[TER_DENMARK].owner == TURN_GER &&
				territories[TER_NORWAY].owner == TURN_GER)
			{
				nations[TURN_GER]->updateBonus(4, 0, true);
				total += 5;
			}
			else
				nations[TURN_GER]->updateBonus(4, 0, false);
		}
		else
			nations[TURN_GER]->updateBonus(4, 0, false);

		cnt = 0;
		if (territories[TER_IRAQ].owner == TURN_GER) // gerMidEastBonus
			cnt++;
		if (territories[TER_PERSIA].owner == TURN_GER)
			cnt++;
		if (territories[TER_NW_PERSIA].owner == TURN_GER)
			cnt++;
		nations[TURN_GER]->updateBonus(5, cnt, false);
		total += 2 * cnt;
	}
		break;
	case TURN_SOV:
	{
		if (this->getAtWarWith(TURN_GER, TURN_SOV) == true) // independenceBonus
		{
			if (territories[TER_ARCHANGEL].owner == TURN_SOV && popups == true)
			{
				int msgboxID = MessageBox(hDlg, L"Is Sea Zone 125 free of\nAxis warships and are there\nno Allied troops in originally\nSoviet territory?",
					L"Bonus Info", MB_YESNO);

				if (msgboxID == IDYES)
				{
					nations[TURN_SOV]->updateBonus(0, 0, true);
					total += 5;
				}
				else
					nations[TURN_SOV]->updateBonus(0, 0, false);
			}
			else if (territories[TER_ARCHANGEL].owner != TURN_SOV)
				nations[TURN_SOV]->updateBonus(0, 0, false);
			else if (nations[TURN_SOV]->checkBonus(0, 0) == true)
				total += 5;
		}

		if (this->getAtWarWith(TURN_GER, TURN_SOV) == true) // controlAxisTerrBonus
		{
			uint16_t cnt = 0;

			uint16_t ters[21] = { TER_DENMARK,      TER_HOLL_BELG, TER_WEST_GERMANY, TER_SARDINIA,
								  TER_NORWAY,       TER_FINLAND,   TER_NORTH_ITALY,  TER_SOUTH_ITALY,
								  TER_SICILY,       TER_GERMANY,   TER_S_GERMANY,    TER_POLAND,
								  TER_SLOV_HUNGARY, TER_ALBANIA,   TER_ROMANIA,      TER_BULGARIA,
								  TER_LIBYA,        TER_TOBRUK,    TER_ETHIOPIA,     TER_ITAL_SOMALI,
								  TER_IRAQ };

			for (uint16_t i = 0; i < 21; i++)
				if (territories[ters[i]].owner == TURN_SOV)
					cnt++;

			nations[TURN_SOV]->updateBonus(1, cnt, false);
			total += 3 * cnt;
		}

		if (territories[TER_GERMANY].owner == TURN_SOV) // controlGerBonus
		{
			nations[TURN_SOV]->updateBonus(2, 0, true);
			if (sovControlGer == false)
			{
				total += 10;
				sovControlGer = true;
			}
		}
	}
		break;
	case TURN_JPN:
	{
		if (this->getAtWarWith(TURN_JPN, TURN_USA) == false) // pacificPeaceBonus
			if (territories[TER_FR_IND_CHINA].owner != TURN_JPN && jpnDeclaredWarOnUK == false)
			{
				nations[TURN_JPN]->updateBonus(0, 0, true);
				total += 10;
			}
			else
				nations[TURN_JPN]->updateBonus(0, 0, false);
		else
			nations[TURN_JPN]->updateBonus(0, 0, false);

		if (jpnCond) // pacificIslandsBonus
		{
			if (territories[TER_GUAM].side == SIDE_AXIS && territories[TER_MIDWAY].side == SIDE_AXIS &&
				territories[TER_WAKE_ISLAND].side == SIDE_AXIS && territories[TER_GILBERT_ISL].side == SIDE_AXIS &&
				territories[TER_SOLOMON_ISL].side == SIDE_AXIS)
			{
				nations[TURN_JPN]->updateBonus(1, 0, true);
				total += 5;
			}
			else
				nations[TURN_JPN]->updateBonus(1, 0, false);
		}

		uint16_t cnt = 0;
		if (jpnCond) // majorTerritoriesBonus
		{
			if (territories[TER_INDIA].side == SIDE_AXIS)
				cnt++;
			if (territories[TER_NEW_S_WALES].side == SIDE_AXIS)
				cnt++;
			if (territories[TER_HAWAII].side == SIDE_AXIS)
				cnt++;
			if (territories[TER_WEST_USA].side == SIDE_AXIS)
				cnt++;
			nations[TURN_JPN]->updateBonus(2, cnt, false);
			total += 5 * cnt;
		}

		if (jpnCond) // dutchTerritoriesBonus
		{
			if (territories[TER_SUMATRA].side == SIDE_AXIS && territories[TER_JAVA].side == SIDE_AXIS &&
				territories[TER_BORNEO].side == SIDE_AXIS && territories[TER_CELEBES].side == SIDE_AXIS)
			{
				nations[TURN_JPN]->updateBonus(3, 0, true);
				total += 5;
			}
			else
				nations[TURN_JPN]->updateBonus(3, 0, false);
		}
	}
		break;
	case TURN_USA:
	{
		if (this->getAtWarWith(TURN_GER, TURN_USA) == true || this->getAtWarWith(TURN_JPN, TURN_USA) == true) 
		{
			// homelandBonus
			if (territories[TER_EASTERN_USA].owner == TURN_USA && territories[TER_CENTRAL_USA].owner == TURN_USA && territories[TER_WEST_USA].owner == TURN_USA)
			{
				nations[TURN_USA]->updateBonus(0, 0, true);
				total += 10;
			}
			else
				nations[TURN_USA]->updateBonus(0, 0, false);

			// pacificBonus
			if (territories[TER_ALASKA].owner == TURN_USA && territories[TER_ALEUTIAN_ISL].owner == TURN_USA &&
				territories[TER_HAWAII].owner == TURN_USA && territories[TER_JOHNSTON_ISL].owner == TURN_USA &&
				territories[TER_LINE_ISLANDS].owner == TURN_USA)
			{
				nations[TURN_USA]->updateBonus(1, 0, true);
				total += 5;
			}
			else
				nations[TURN_USA]->updateBonus(1, 0, false);

			// atlanticBonus
			if (territories[TER_MEXICO].owner == TURN_USA && territories[TER_SE_MEXICO].owner == TURN_USA &&
				territories[TER_CENT_AMERICA].owner == TURN_USA && territories[TER_WEST_INDIES].owner == TURN_USA)
			{
				nations[TURN_USA]->updateBonus(2, 0, true);
				total += 5;
			}
			else
				nations[TURN_USA]->updateBonus(2, 0, false);

			// philippinesBonus
			if (territories[TER_PHILIPPINES].owner == TURN_USA)
			{
				nations[TURN_USA]->updateBonus(3, 0, true);
				total += 5;
			}
			else
				nations[TURN_USA]->updateBonus(3, 0, false);

			// franceBonus
			if (territories[TER_FRANCE].owner == TURN_FRA && popups == true)
			{
				int msgboxID = MessageBox(hDlg, L"Is there a US land unit\nin France?",
					L"Bonus Info", MB_YESNO);

				if (msgboxID == IDYES)
				{
					nations[TURN_USA]->updateBonus(4, 0, true);
					total += 5;
				}
				else
					nations[TURN_USA]->updateBonus(4, 0, false);
			}

			// mobilizationBonus
			if (declaredWarOnUSA == true)
			{
				nations[TURN_USA]->updateBonus(5, 0, true);

				if (usaBonus == false)
				{
					total += 30;
					usaBonus = true;
				}
			}
		}
	}
		break;
	case TURN_CHN:
	{
		if (territories[TER_INDIA].side == SIDE_ALLIES && territories[TER_BURMA].side == SIDE_ALLIES &&
			territories[TER_YUNNAN].side == SIDE_ALLIES && territories[TER_SZECHWAN].side == SIDE_ALLIES)
		{
			nations[TURN_CHN]->updateBonus(0, 0, true);
			total += 6;
		}
		else
			nations[TURN_CHN]->updateBonus(0, 0, false);
	}
		break;
	case TURN_UKE:
	{
		uint16_t ters[26] = { TER_ALBERTA, TER_ONTARIO, TER_QUEBEC, TER_NEWFOUNDLAND, TER_NEW_BRUNS,
			TER_BRIT_GUIANA, TER_ICELAND, TER_SCOTLAND, TER_UTD_KINGDOM, TER_GIBRALTAR, TER_GOLD_COAST,
			TER_NIGERIA, TER_MALTA, TER_ALEXANDRIA, TER_EGYPT, TER_AN_EGY_SUDAN, TER_BRIT_SOMALI,
			TER_BELG_CONGO, TER_KENYA, TER_TANGANYIKA, TER_RHODESIA, TER_SW_AFRICA, TER_SOUTH_AFRICA,
			TER_CYPRUS, TER_TRANS_JORDAN, TER_WEST_INDIA };

		if (gameType == GLOBAL_GAME)
			ters[25] = TER_W_CANADA;

		bool cond = true;
		for (uint16_t i = 0; i < 26; i++)
			if (territories[ters[i]].owner != TURN_UKE)
				cond = false;

		if (cond == true)
		{
			nations[TURN_UKE]->updateBonus(0, 0, true);
			total += 5;
		}
		else
			nations[TURN_UKE]->updateBonus(0, 0, false);
	}
		break;
	case TURN_UKP:
	{
		if (this->getAtWarWith(TURN_JPN, TURN_UKP) || this->getAtWarWith(TURN_JPN, TURN_UKE))
		{
			if (territories[TER_KWANGTUNG].owner == TURN_UKP && territories[TER_MALAYA].owner == TURN_UKP)
			{
				nations[TURN_UKP]->updateBonus(0, 0, true);
				total += 5;
			}
			else
				nations[TURN_UKP]->updateBonus(0, 0, false);
		}
	}
		break;
	case TURN_ITA:
	{
		uint16_t cnt = 0;
		if (territories[TER_GIBRALTAR].side == SIDE_AXIS) // mediterraneanLandBonus
			cnt++;
		if (territories[TER_SOUTH_FRANCE].side == SIDE_AXIS)
			cnt++;
		if (territories[TER_GREECE].side == SIDE_AXIS)
			cnt++;
		if (territories[TER_EGYPT].side == SIDE_AXIS)
			cnt++;
		if (cnt >= 3)
		{
			nations[TURN_ITA]->updateBonus(0, 0, true);
			total += 5;
		}
		else
			nations[TURN_ITA]->updateBonus(0, 0, false);

		if (popups == true)
		{
			int msgboxID = MessageBox(hDlg, L"Is the Mediterranean Sea\nfree of Allied warships?", // mediterraneanSeaBonus
				L"Bonus Info", MB_YESNO);

			if (msgboxID == IDYES)
			{
				nations[TURN_ITA]->updateBonus(1, 0, true);
				total += 5;
			}
			else
				nations[TURN_ITA]->updateBonus(1, 0, false);
		}

		if (territories[TER_MOROCCO].side == SIDE_AXIS && territories[TER_ALGERIA].side == SIDE_AXIS && // northAfricaBonus
			territories[TER_TUNISIA].side == SIDE_AXIS && territories[TER_LIBYA].side == SIDE_AXIS &&
			territories[TER_TOBRUK].side == SIDE_AXIS && territories[TER_ALEXANDRIA].side == SIDE_AXIS)
		{
			nations[TURN_ITA]->updateBonus(2, 0, true);
			total += 5;
		}
		else
			nations[TURN_ITA]->updateBonus(2, 0, false);

		// middleEastBonus
		cnt = 0;
		if (territories[TER_IRAQ].owner == TURN_ITA)
			cnt++;
		if (territories[TER_PERSIA].owner == TURN_ITA)
			cnt++;
		if (territories[TER_NW_PERSIA].owner == TURN_ITA)
			cnt++;
		nations[TURN_ITA]->updateBonus(3, cnt, false);
		total += 2 * cnt;
	}
		break;
	case TURN_ANZ:
	{
		if (this->getAtWarWith(TURN_JPN, TURN_ANZ))
		{
			// origTerritoryBonus
			uint16_t ters[10] = { TER_W_AUSTRALIA, TER_N_TERRITORY, TER_S_AUSTRALIA, TER_QUEENSLAND,
				TER_NEW_S_WALES, TER_VICTORIA, TER_NEW_ZEALAND, TER_SOLOMON_ISL, TER_NEW_BRITAIN, TER_NEW_GUINEA };

			if (territories[TER_MALAYA].side == SIDE_ALLIES)
			{
				bool cond = true;
				for (uint16_t i = 0; i < 10; i++)
					if (territories[ters[i]].owner != TURN_ANZ)
						cond = false;

				if (cond == true)
				{
					nations[TURN_ANZ]->updateBonus(0, 0, true);
					total += 5;
				}
				else
					nations[TURN_ANZ]->updateBonus(0, 0, false);
			}
			else
				nations[TURN_ANZ]->updateBonus(0, 0, false);

			// islandsBonus
			if (territories[TER_DUT_N_GUINEA].side == SIDE_ALLIES && territories[TER_NEW_GUINEA].side == SIDE_ALLIES &&
				territories[TER_NEW_BRITAIN].side == SIDE_ALLIES && territories[TER_SOLOMON_ISL].side == SIDE_ALLIES)
			{
				nations[TURN_ANZ]->updateBonus(1, 0, true);
				total += 5;
			}
			else
				nations[TURN_ANZ]->updateBonus(1, 0, false);
		}
	}
		break;
	case TURN_FRA:
	{
		if (franceLiberated == true)
		{
			nations[TURN_FRA]->updateBonus(0, 0, true);

			if (fraBonus == false)
			{
				int msgboxID = MessageBox(hDlg, L"Place 12 IPCs worth of units in France",
					L"France Liberated", MB_OK);

				fraBonus = true;
			}
		}
		else
			nations[TURN_FRA]->updateBonus(0, 0, false);
	}
		break;
	default: break;
	}
	
	int delta = ((int)total + transferVal) - (int)nations[nat]->getNationBonus(gameTurn);

	if (nations[nat]->getNationControlsCapital())
	{
		nations[nat]->setNationBonus(gameTurn, total + transferVal);
		nations[nat]->addNationBank(gameTurn + 1, delta);
	}

	*/
}

uint16_t Board::checkBonus(uint16_t nat , uint16_t whichBonus, bool& cookie)
{
	switch (nat)
	{
	case TURN_GER:
		if (whichBonus == 0 || whichBonus == 2 || whichBonus == 3 || whichBonus == 4)
			cookie = nations[TURN_GER]->checkBonus(whichBonus, cookie);
		else
			return nations[TURN_GER]->checkBonus(whichBonus);
		break;
	case TURN_SOV:
		if (whichBonus == 0 || whichBonus == 2)
			cookie = nations[TURN_SOV]->checkBonus(whichBonus, cookie);
		else
			return nations[TURN_SOV]->checkBonus(whichBonus);
		break;
	case TURN_JPN:
		if (whichBonus == 0 || whichBonus == 1 || whichBonus == 3)
			cookie = nations[TURN_JPN]->checkBonus(whichBonus, cookie);
		else
			return nations[TURN_JPN]->checkBonus(whichBonus);
		break;
	case TURN_USA:
		cookie = nations[TURN_USA]->checkBonus(whichBonus, cookie);
		break;
	case TURN_CHN:
		cookie = nations[TURN_CHN]->checkBonus(whichBonus, cookie);
		break;
	case TURN_UKE:
		cookie = nations[TURN_UKE]->checkBonus(whichBonus, cookie);
		break;
	case TURN_UKP:
		cookie = nations[TURN_UKP]->checkBonus(whichBonus, cookie);
		break;
	case TURN_ITA:
		if (whichBonus == 0 || whichBonus == 1 || whichBonus == 2)
			cookie = nations[TURN_ITA]->checkBonus(whichBonus, cookie);
		else
			return nations[TURN_ITA]->checkBonus(whichBonus);
		break;
	case TURN_ANZ:
		cookie = nations[TURN_ANZ]->checkBonus(whichBonus, cookie);
		break;
	case TURN_FRA:
		cookie = nations[TURN_FRA]->checkBonus(whichBonus, cookie);
		break;
	}
	return 0;
}

void Board::setResearch(uint16_t nat, uint16_t idx)
{
	nations[nat]->setResearch(idx);
}

void Board::setResearch(uint16_t nat, Research &res) // Load game
{
	nations[nat]->setResearch(res);
}

void Board::setFailures(uint16_t nat, uint16_t fails)
{
	nations[nat]->setFailures(fails);
}

bool Board::getResearch(uint16_t nat, uint16_t idx)
{
	return nations[nat]->getResearch(idx);
}

uint16_t Board::getFailures(uint16_t nat)
{
	return nations[nat]->getFailures();
}

uint16_t Board::getCount(uint16_t nat)
{
	return nations[nat]->getResearchCount();
}
