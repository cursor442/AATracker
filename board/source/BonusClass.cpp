#include "../header/BonusClass.h"

BonusClass::BonusClass()
{
	for (int i = 0; i <= TURN_FRA; i++)
		bonusVals[i].resize(0);

	bonusUpdate.resize(0);

	gameType = NULL_GAME;

	neutralLean = SIDE_NEUTRAL;
	sovControlGer = false;
	jpnDeclaredWarOnUK = false;
	axisDeclaredWarOnUSA = false;
	usaMobilizationBonus = false;
	franceLiberated = false;

	_transferValTurn = 1;
	_transferValNat = TURN_NON;
	_transferVal = 0;
}

BonusClass::~BonusClass()
{

}

void BonusClass::setGameType(int type)
{
	gameType = type;

	if (gameType != PACIFIC_GAME)
	{
		// Germany
		bonusVals[TURN_GER].resize(6);
		bonusVals[TURN_GER][BONS_GER_SOV].bin = true;
		bonusVals[TURN_GER][BONS_GER_CTY].val = 0;
		bonusVals[TURN_GER][BONS_GER_CAU].bin = false;
		bonusVals[TURN_GER][BONS_GER_EGY].bin = false;
		bonusVals[TURN_GER][BONS_GER_DEN].bin = true;
		bonusVals[TURN_GER][BONS_GER_PER].val = 0;

		// Soviet Union
		bonusVals[TURN_SOV].resize(3);
		bonusVals[TURN_SOV][BONS_SOV_SEA].bin = false;
		bonusVals[TURN_SOV][BONS_SOV_AXT].val = 0;
		bonusVals[TURN_SOV][BONS_SOV_GER].bin = false;

		// United Kingdom
		bonusVals[TURN_UKE].resize(1);
		bonusVals[TURN_UKE][BONS_UKE_TER].bin = true;
		
		// Italy
		bonusVals[TURN_ITA].resize(4);
		bonusVals[TURN_ITA][BONS_ITA_GIB].bin = false;
		bonusVals[TURN_ITA][BONS_ITA_MED].bin = false;
		bonusVals[TURN_ITA][BONS_ITA_AFR].bin = false;
		bonusVals[TURN_ITA][BONS_ITA_PER].val = 0;

		// France
		bonusVals[TURN_FRA].resize(1);
		bonusVals[TURN_FRA][BONS_FRA_LIB].bin = false;
	}
	else
	{
		// United States
		bonusVals[TURN_USA].resize(5);
		bonusVals[TURN_USA][BONS_USA_USA].bin = false;
		bonusVals[TURN_USA][BONS_USA_PAC_TER].bin = false;
		bonusVals[TURN_USA][BONS_USA_PAC_ISL].bin = false;
		bonusVals[TURN_USA][BONS_USA_PHI].bin = false;
		bonusVals[TURN_USA][BONS_USA_PAC_WAR].bin = false;
	}

	if (gameType != EUROPE_GAME)
	{
		// Japan
		bonusVals[TURN_JPN].resize(4);
		bonusVals[TURN_JPN][BONS_JPN_UKZ].bin = true;
		bonusVals[TURN_JPN][BONS_JPN_ISL].bin = false;
		bonusVals[TURN_JPN][BONS_JPN_TER].val = 0;
		bonusVals[TURN_JPN][BONS_JPN_JAV].bin = false;

		// China
		bonusVals[TURN_CHN].resize(1);
		bonusVals[TURN_CHN][BONS_CHN_BUR].bin = true;

		// United Kingdom
		bonusVals[TURN_UKP].resize(1);
		bonusVals[TURN_UKP][BONS_UKP_TER].bin = false;

		// ANZAC
		bonusVals[TURN_ANZ].resize(2);
		bonusVals[TURN_ANZ][BONS_ANZ_TER].bin = false;
		bonusVals[TURN_ANZ][BONS_ANZ_ISL].bin = false;
	}
	else
	{
		// United States
		bonusVals[TURN_USA].resize(2);
		bonusVals[TURN_USA][BONS_USA_USA].bin = true;
		bonusVals[TURN_USA][BONS_USA_EUR_TER].bin = false;
	}

	if (gameType == GLOBAL_GAME)
	{
		// United States
		bonusVals[TURN_USA].resize(6);
		bonusVals[TURN_USA][BONS_USA_USA].bin = false;
		bonusVals[TURN_USA][BONS_USA_GLO_ISL].bin = false;
		bonusVals[TURN_USA][BONS_USA_GLO_TER].bin = false;
		bonusVals[TURN_USA][BONS_USA_PHI].bin = false;
		bonusVals[TURN_USA][BONS_USA_GLO_FRA].bin = false;
		bonusVals[TURN_USA][BONS_USA_GLO_WAR].bin = false;
	}
}

void BonusClass::setNeutralLean(int lean)
{
	neutralLean = lean;
}

void BonusClass::setSovControlGer(bool cond)
{
	sovControlGer = cond;
}

void BonusClass::setJpnDeclaredWarOnUK(bool cond)
{
	jpnDeclaredWarOnUK = cond;
}

void BonusClass::setAxisDeclaredWarOnUSA(bool cond)
{
	axisDeclaredWarOnUSA = cond;
}

void BonusClass::setFranceLiberated(bool cond)
{
	franceLiberated = cond;
}

void BonusClass::setTransferValTurn(int val)
{
	_transferValTurn = val;
}

void BonusClass::setTransferValNat(int val)
{
	_transferValNat = val;
}

void BonusClass::setTransferVal(int val)
{
	_transferVal = val;
}

int BonusClass::getNeutralLean()
{
	return neutralLean;
}

bool BonusClass::getSovControlGer()
{
	return sovControlGer;
}

bool BonusClass::getJpnDeclaredWarOnUK()
{
	return jpnDeclaredWarOnUK;
}

bool BonusClass::getAxisDeclaredWarOnUSA()
{
	return axisDeclaredWarOnUSA;
}

bool BonusClass::getUsaMobilizationBonus()
{
	return usaMobilizationBonus;
}

bool BonusClass::getFranceLiberated()
{
	return franceLiberated;
}

int BonusClass::getTransferValTurn()
{
	return _transferValTurn;
}

int BonusClass::getTransferValNat()
{
	return _transferValNat;
}

int BonusClass::getTransferVal()
{
	return _transferVal;
}

void BonusClass::updateBonuses(HWND hDlg, Nation** nations, WarMatrix* warMatrix, Territories* territories, int turn, int nat, bool popups, int transferVal)
{
	int total = 0; // Bonus total for specified nation
	int cnt = 0;   // Total territories for counting bonuses

	bonusTransaction tmp;
	
	// Check and update all bonuses for specified nation
	switch (nat)
	{
	case TURN_GER:
	{ 
		tmp.nat = TURN_GER;

		// notAtWarWithSovBonus, 5
		{
			bool cond = (!warMatrix->getAtWarWith(TURN_GER, TURN_SOV));

			if (cond)
				total += 5;
			else
				nations[TURN_GER]->updateBonus(BONS_GER_SOV, BONS_NON, false); // One-time switch

			if (bonusVals[TURN_GER][BONS_GER_SOV].bin != cond)
			{
				tmp.bonus = BONS_GER_SOV;
				tmp.bin = cond;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_GER][BONS_GER_SOV].bin = cond;
			}
		}

		// At war with Soviet Union condition
		if (warMatrix->getAtWarWith(TURN_GER, TURN_SOV))
		{
			// controlSovTerrBonus, 5 each
			{
				if (territories->getTerritoryOwner(TER_NOVGOROD) == TURN_GER)
					cnt++;
				if (territories->getTerritoryOwner(TER_VOLGOGRAD) == TURN_GER)
					cnt++;
				if (territories->getTerritoryOwner(TER_RUSSIA) == TURN_GER)
					cnt++;
				nations[TURN_GER]->updateBonus(BONS_GER_CTY, cnt, false);

				if (bonusVals[TURN_GER][BONS_GER_CTY].val != cnt)
				{
					tmp.bonus = BONS_GER_CTY;
					tmp.val = cnt;
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_GER][BONS_GER_CTY].val = cnt;
				}
				total += 5 * cnt;
				cnt = 0;
			}

			// axisCaucusBonus, 5
			{
				bool cond = (territories->getTerritoryOwner(TER_CAUCASUS) == SIDE_AXIS);

				if (cond)
				{
					nations[TURN_GER]->updateBonus(BONS_GER_CAU, BONS_NON, true);
					total += 5;
				}
				else
					nations[TURN_GER]->updateBonus(BONS_GER_CAU, BONS_NON, false);

				if (bonusVals[TURN_GER][BONS_GER_CAU].bin != cond)
				{
					tmp.bonus = BONS_GER_CAU;
					tmp.bin = cond;
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_GER][BONS_GER_CAU].bin = cond;
				}
			}
		}

		// gerEgyptBonus, 5
		{
			bool cond0 = (territories->getTerritoryOwner(TER_EGYPT) == SIDE_AXIS);
			bool cond1 = false;

			if (cond0 && popups)
			{
				int msgboxID = MessageBox(hDlg, L"Is there a German land unit\nin Egypt?",
					L"Bonus Info", MB_YESNO);

				if (msgboxID == IDYES)
				{
					nations[TURN_GER]->updateBonus(BONS_GER_EGY, BONS_NON, true);
					cond1 = true;
					total += 5;
				}
				else
					nations[TURN_GER]->updateBonus(BONS_GER_EGY, BONS_NON, false);
			}
			else if (!popups && nations[TURN_GER]->checkBonus(BONS_GER_EGY, true))
			{
				cond1 = true;
				total += 5;
			}

			if (bonusVals[TURN_GER][BONS_GER_EGY].bin != (cond0 && cond1))
			{
				tmp.bonus = BONS_GER_EGY;
				tmp.bin = (cond0 && cond1);
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_GER][BONS_GER_EGY].bin = (cond0 && cond1);
			}
		}

		// denNorBonus, 5
		{
			bool cond0 = (((territories->getTerritoryOwner(TER_SWEDEN) == FULL_NEUTRAL) && neutralLean != SIDE_ALLIES) ||
				(territories->getTerritoryOwner(TER_SWEDEN) == SIDE_AXIS));
			bool cond1 = false;

			if (cond0)
			{
				cond1 = ((territories->getTerritoryOwner(TER_DENMARK) == TURN_GER) && (territories->getTerritoryOwner(TER_NORWAY) == TURN_GER));

				if (cond1)
				{
					nations[TURN_GER]->updateBonus(BONS_GER_DEN, BONS_NON, true);
					total += 5;
				}
				else
					nations[TURN_GER]->updateBonus(BONS_GER_DEN, BONS_NON, false);
			}
			else
				nations[TURN_GER]->updateBonus(BONS_GER_DEN, BONS_NON, false);

			if (bonusVals[TURN_GER][BONS_GER_DEN].bin != (cond0 && cond1))
			{
				tmp.bonus = BONS_GER_DEN;
				tmp.bin = (cond0 && cond1);
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_GER][BONS_GER_DEN].bin = (cond0 && cond1);
			}
		}

		// gerMidEastBonus, 2 each
		{
			if (territories->getTerritoryOwner(TER_IRAQ) == TURN_GER)
				cnt++;
			if (territories->getTerritoryOwner(TER_PERSIA) == TURN_GER)
				cnt++;
			if (territories->getTerritoryOwner(TER_NW_PERSIA) == TURN_GER)
				cnt++;
			nations[TURN_GER]->updateBonus(BONS_GER_PER, cnt, false);

			if (bonusVals[TURN_GER][BONS_GER_PER].val != cnt)
			{
				tmp.bonus = BONS_GER_PER;
				tmp.val = cnt;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_GER][BONS_GER_PER].val = cnt;
			}

			total += 2 * cnt;
			cnt = 0;
		}
		break;
	}
	case TURN_SOV:
	{
		tmp.nat = TURN_SOV;

		if (warMatrix->getAtWarWith(TURN_GER, TURN_SOV) || warMatrix->getAtWarWith(TURN_ITA, TURN_SOV))
		{
			// independenceBonus, 5
			{
				bool cond0 = (territories->getTerritoryOwner(TER_ARCHANGEL) == TURN_SOV);
				bool cond1 = false;

				if (cond0 && popups)
				{
					int msgboxID = MessageBox(hDlg, L"Is Sea Zone 125 free of\nAxis warships and are there\nno Allied troops in originally\nSoviet territory?",
						L"Bonus Info", MB_YESNO);

					if (msgboxID == IDYES)
					{
						nations[TURN_SOV]->updateBonus(BONS_SOV_SEA, BONS_NON, true);
						cond1 = true;
						total += 5;
					}
					else
						nations[TURN_SOV]->updateBonus(BONS_SOV_SEA, BONS_NON, false);
				}
				else if (!cond0)
				{
					nations[TURN_SOV]->updateBonus(BONS_SOV_SEA, BONS_NON, false);
				}
				else if (nations[TURN_SOV]->checkBonus(BONS_SOV_SEA, false) == true)
				{
					total += 5;
				}

				if (bonusVals[TURN_SOV][BONS_SOV_SEA].bin != (cond0 && cond1))
				{
					tmp.bonus = BONS_SOV_SEA;
					tmp.bin = (cond0 && cond1);
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_SOV][BONS_SOV_SEA].bin = (cond0 && cond1);
				}
			}

			// controlAxisTerrBonus, 3 each
			{
				// German, Italian, Pro-Axis
				int ters[21] = { TER_DENMARK,      TER_HOLL_BELG, TER_WEST_GERMANY, TER_SARDINIA,
								 TER_NORWAY,       TER_FINLAND,   TER_NORTH_ITALY,  TER_SOUTH_ITALY,
								 TER_SICILY,       TER_GERMANY,   TER_S_GERMANY,    TER_POLAND,
								 TER_SLOV_HUNGARY, TER_ALBANIA,   TER_ROMANIA,      TER_BULGARIA,
								 TER_LIBYA,        TER_TOBRUK,    TER_ETHIOPIA,     TER_ITAL_SOMALI,
								 TER_IRAQ };

				for (int i = 0; i < 21; i++)
					if (territories->getTerritoryOwner(ters[i]) == TURN_SOV)
						cnt++;

				nations[TURN_SOV]->updateBonus(BONS_SOV_AXT, cnt, false);

				if (bonusVals[TURN_SOV][BONS_SOV_AXT].val != cnt)
				{
					tmp.bonus = BONS_SOV_AXT;
					tmp.val = cnt;
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_SOV][BONS_SOV_AXT].val = cnt;
				}

				total += 3 * cnt;
				cnt = 0;
			}

			// controlGerBonus, 10
			{
				if (territories->getTerritoryOwner(TER_GERMANY) == TURN_SOV)
				{
					nations[TURN_SOV]->updateBonus(BONS_SOV_GER, BONS_NON, true);
					if (sovControlGer == false)
					{
						total += 10;
						sovControlGer = true;
					}
				}

				if (bonusVals[TURN_SOV][BONS_SOV_GER].bin != sovControlGer)
				{
					tmp.bonus = BONS_SOV_GER;
					tmp.bin = sovControlGer;
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_SOV][BONS_SOV_GER].bin = sovControlGer;
				}
			}
		}
		break;
	}
	case TURN_JPN:
	{
		tmp.nat = TURN_JPN;

		// pacificPeaceBonus, 10
		{
			bool cond0 = (!warMatrix->getAtWarWith(TURN_JPN, TURN_USA));
			bool cond1 = (!jpnDeclaredWarOnUK);
			bool cond2 = false;

			// UK could have declared upon JPN and moved units into French Indo-China, then JPN 
			// could have unsuccessfully attacked. Unlikely, but possible
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_UKP) && bonusVals[TURN_JPN][BONS_JPN_UKZ].bin)
			{
				int msgboxID = MessageBox(hDlg, L"Has Japan attacked French Indo-China?",
					L"Bonus Info", MB_YESNO);

				if (msgboxID == IDYES)
					cond2 = false;
				else if (msgboxID == IDNO)
					cond2 = true;
			}
			else if (territories->getTerritoryOwner(TER_FR_IND_CHINA) == TURN_JPN)
				cond2 = false;
			else
				cond2 = true;

			if (cond0 && cond1 && cond2)
			{
			nations[TURN_JPN]->updateBonus(BONS_JPN_UKZ, BONS_NON, true);
			total += 10;
			}
			else
			{
			nations[TURN_JPN]->updateBonus(BONS_JPN_UKZ, BONS_NON, false);
			}

			if (bonusVals[TURN_JPN][BONS_JPN_UKZ].bin != (cond0 && cond1 && cond2))
			{
				tmp.bonus = BONS_JPN_UKZ;
				tmp.bin = (cond0 && cond1 && cond2);
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_JPN][BONS_JPN_UKZ].bin = (cond0 && cond1 && cond2);
			}
		}

		// At war with Western Allies
		if (warMatrix->getAtWarWith(TURN_JPN, TURN_UKP) ||
			warMatrix->getAtWarWith(TURN_JPN, TURN_USA) || warMatrix->getAtWarWith(TURN_JPN, TURN_FRA))
		{
			// pacificIslandsBonus, 5
			{
				bool cond = false;

				if (territories->getTerritoryOwnerSide(TER_GUAM) == SIDE_AXIS && territories->getTerritoryOwnerSide(TER_MIDWAY) == SIDE_AXIS &&
					territories->getTerritoryOwnerSide(TER_WAKE_ISLAND) == SIDE_AXIS && territories->getTerritoryOwnerSide(TER_GILBERT_ISL) == SIDE_AXIS &&
					territories->getTerritoryOwnerSide(TER_SOLOMON_ISL) == SIDE_AXIS)
				{
					nations[TURN_JPN]->updateBonus(BONS_JPN_ISL, BONS_NON, true);
					cond = true;
					total += 5;
				}
				else
					nations[TURN_JPN]->updateBonus(BONS_JPN_ISL, BONS_NON, false);

				if (bonusVals[TURN_JPN][BONS_JPN_ISL].bin != cond)
				{
					tmp.bonus = BONS_JPN_ISL;
					tmp.bin = cond;
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_JPN][BONS_JPN_ISL].bin = cond;
				}
			}

			// majorTerritoriesBonus, 5 each
			{
				if (territories->getTerritoryOwnerSide(TER_INDIA) == SIDE_AXIS)
					cnt++;
				if (territories->getTerritoryOwnerSide(TER_NEW_S_WALES) == SIDE_AXIS)
					cnt++;
				if (territories->getTerritoryOwnerSide(TER_HAWAII) == SIDE_AXIS)
					cnt++;
				if (territories->getTerritoryOwnerSide(TER_WESTERN_USA) == SIDE_AXIS)
					cnt++;
				nations[TURN_JPN]->updateBonus(BONS_JPN_TER, cnt, false);

				if (bonusVals[TURN_JPN][BONS_JPN_TER].val != cnt)
				{
					tmp.bonus = BONS_JPN_TER;
					tmp.val = cnt;
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_JPN][BONS_JPN_TER].val = cnt;
				}

				total += 5 * cnt;
				cnt = 0;
			}

			// dutchTerritoriesBonus, 5
			{
				bool cond = false;

				if (territories->getTerritoryOwnerSide(TER_SUMATRA) == SIDE_AXIS && territories->getTerritoryOwnerSide(TER_JAVA) == SIDE_AXIS &&
					territories->getTerritoryOwnerSide(TER_BORNEO) == SIDE_AXIS && territories->getTerritoryOwnerSide(TER_CELEBES) == SIDE_AXIS)
				{
					nations[TURN_JPN]->updateBonus(BONS_JPN_JAV, BONS_NON, true);
					cond = true;
					total += 5;
				}
				else
					nations[TURN_JPN]->updateBonus(BONS_JPN_JAV, BONS_NON, false);

				if (bonusVals[TURN_JPN][BONS_JPN_JAV].bin != cond)
				{
					tmp.bonus = BONS_JPN_JAV;
					tmp.bin = cond;
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_JPN][BONS_JPN_JAV].bin = cond;
				}
			}
		}
		break;
	}
	case TURN_USA:
	{
		tmp.nat = TURN_USA;

		if (gameType == EUROPE_GAME)
		{
			if (nations[TURN_USA]->isAtWar())
			{
				// homelandBonus, 20
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_EASTERN_USA) == TURN_USA && territories->getTerritoryOwner(TER_CENTRAL_USA) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_USA, BONS_NON, true);
						cond = true;
						total += 20;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_USA, BONS_NON, false);


					if (bonusVals[TURN_USA][BONS_USA_USA].bin != cond)
					{
						tmp.bonus = BONS_USA_USA;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_USA].bin = cond;
					}
				}

				// atlanticBonus, 5
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_SE_MEXICO) == TURN_USA && territories->getTerritoryOwner(TER_CENT_AMERICA) == TURN_USA &&
						territories->getTerritoryOwner(TER_WEST_INDIES) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_EUR_TER, BONS_NON, true);
						cond = true;
						total += 5;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_EUR_TER, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_EUR_TER].bin != cond)
					{
						tmp.bonus = BONS_USA_EUR_TER;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_EUR_TER].bin = cond;
					}
				}
			}
		}
		else if (gameType == PACIFIC_GAME)
		{
			if (nations[TURN_USA]->isAtWar())
			{
				// homelandBonus, 30
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_WESTERN_USA) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_USA, BONS_NON, true);
						cond = true;
						total += 30;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_USA, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_USA].bin != cond)
					{
						tmp.bonus = BONS_USA_USA;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_USA].bin = cond;
					}
				}

				// territoryBonus, 5
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_ALASKA) == TURN_USA && territories->getTerritoryOwner(TER_MEXICO) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_PAC_TER, BONS_NON, true);
						cond = true;
						total += 5;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_PAC_TER, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_PAC_TER].bin != cond)
					{
						tmp.bonus = BONS_USA_PAC_TER;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_PAC_TER].bin = cond;
					}
				}

				// pacificBonus, 5
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_ALEUTIAN_ISL) == TURN_USA && territories->getTerritoryOwner(TER_HAWAII) == TURN_USA && 
						territories->getTerritoryOwner(TER_JOHNSTON_ISL) == TURN_USA && territories->getTerritoryOwner(TER_LINE_ISLANDS) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_PAC_ISL, BONS_NON, true);
						cond = true;
						total += 5;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_PAC_ISL, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_PAC_ISL].bin != cond)
					{
						tmp.bonus = BONS_USA_PAC_ISL;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_PAC_ISL].bin = cond;
					}
				}

				// philippinesBonus, 5
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_PHILIPPINES) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_PHI, BONS_NON, true);
						cond = true;
						total += 5;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_PHI, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_PHI].bin != cond)
					{
						tmp.bonus = BONS_USA_PHI;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_PHI].bin = cond;
					}
				}

				// mobilizationBonus, 30, ICs
				{
					// One-time change
					usaMobilizationBonus = true;
					if (bonusVals[TURN_USA][BONS_USA_PAC_WAR].bin != usaMobilizationBonus)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_PAC_WAR, BONS_NON, true);
						
						if (axisDeclaredWarOnUSA)
						{
							total += 30;
						}

						int msgboxID = MessageBox(hDlg, L"Upgrade Industrial Complexes",
							L"Mobilization", MB_OK);

						tmp.bonus = BONS_USA_PAC_WAR;
						tmp.bin = usaMobilizationBonus;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_PAC_WAR].bin = usaMobilizationBonus;
					}
				}
			}
		}
		else if (gameType == GLOBAL_GAME)
		{
			if (nations[TURN_USA]->isAtWar())
			{
				// homelandBonus, 10
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_EASTERN_USA) == TURN_USA && territories->getTerritoryOwner(TER_CENTRAL_USA) == TURN_USA &&
						territories->getTerritoryOwner(TER_WESTERN_USA) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_USA, BONS_NON, true);
						cond = true;
						total += 10;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_USA, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_USA].bin != cond)
					{
						tmp.bonus = BONS_USA_USA;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_USA].bin = cond;
					}
				}

				// pacificBonus, 5
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_ALASKA) == TURN_USA && territories->getTerritoryOwner(TER_ALEUTIAN_ISL) == TURN_USA &&
						territories->getTerritoryOwner(TER_HAWAII) == TURN_USA && territories->getTerritoryOwner(TER_JOHNSTON_ISL) == TURN_USA &&
						territories->getTerritoryOwner(TER_LINE_ISLANDS) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_GLO_ISL, BONS_NON, true);
						cond = true;
						total += 5;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_GLO_ISL, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_GLO_ISL].bin != cond)
					{
						tmp.bonus = BONS_USA_GLO_ISL;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_GLO_ISL].bin = cond;
					}
				}

				// atlanticBonus, 5
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_MEXICO) == TURN_USA && territories->getTerritoryOwner(TER_SE_MEXICO) == TURN_USA &&
						territories->getTerritoryOwner(TER_CENT_AMERICA) == TURN_USA && territories->getTerritoryOwner(TER_WEST_INDIES) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_GLO_TER, BONS_NON, true);
						cond = true;
						total += 5;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_GLO_TER, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_GLO_TER].bin != cond)
					{
						tmp.bonus = BONS_USA_GLO_TER;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_GLO_TER].bin = cond;
					}
				}

				// philippinesBonus, 5
				{
					bool cond = false;

					if (territories->getTerritoryOwner(TER_PHILIPPINES) == TURN_USA)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_PHI, BONS_NON, true);
						cond = true;
						total += 5;
					}
					else
						nations[TURN_USA]->updateBonus(BONS_USA_PHI, BONS_NON, false);

					if (bonusVals[TURN_USA][BONS_USA_PHI].bin != cond)
					{
						tmp.bonus = BONS_USA_PHI;
						tmp.bin = cond;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_PHI].bin = cond;
					}
				}

				// franceBonus, 5
				{
					bool cond0 = (territories->getTerritoryOwner(TER_FRANCE) == TURN_FRA);
					bool cond1 = false;

					if (cond0 && popups)
					{
						int msgboxID = MessageBox(hDlg, L"Is there a US land unit\nin France?",
							L"Bonus Info", MB_YESNO);

						if (msgboxID == IDYES)
						{
							nations[TURN_USA]->updateBonus(BONS_USA_GLO_FRA, BONS_NON, true);
							cond1 = true;
							total += 5;
						}
						else
							nations[TURN_USA]->updateBonus(BONS_USA_GLO_FRA, BONS_NON, false);
					}
					else if (!cond0)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_GLO_FRA, BONS_NON, false);
					}
					else if (nations[TURN_USA]->checkBonus(BONS_USA_GLO_FRA, false) == true)
					{
						total += 5;
					}

					if (bonusVals[TURN_USA][BONS_USA_GLO_FRA].bin != (cond0 && cond1))
					{
						tmp.bonus = BONS_USA_GLO_FRA;
						tmp.bin = (cond0 && cond1);
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_GLO_FRA].bin = (cond0 && cond1);
					}
				}

				// mobilizationBonus, ICs
				{
					// One-time change
					usaMobilizationBonus = true;
					if (bonusVals[TURN_USA][BONS_USA_GLO_WAR].bin != usaMobilizationBonus)
					{
						nations[TURN_USA]->updateBonus(BONS_USA_GLO_WAR, BONS_NON, true);

						int msgboxID = MessageBox(hDlg, L"Upgrade Industrial Complexes",
							L"Mobilization", MB_OK);

						tmp.bonus = BONS_USA_GLO_WAR;
						tmp.bin = usaMobilizationBonus;
						bonusUpdate.push_back(tmp);

						bonusVals[TURN_USA][BONS_USA_GLO_WAR].bin = usaMobilizationBonus;
					}
				}
			}
		}
		break;
	}
	case TURN_CHN:
	{
		tmp.nat = TURN_CHN;

		// Burma Road, 6, artillery
		{
			bool cond = false;

			if (territories->getTerritoryOwnerSide(TER_INDIA) == SIDE_ALLIES && territories->getTerritoryOwner(TER_BURMA) == SIDE_ALLIES &&
				territories->getTerritoryOwnerSide(TER_YUNNAN) == SIDE_ALLIES && territories->getTerritoryOwner(TER_SZECHWAN) == SIDE_ALLIES)
			{
				nations[TURN_CHN]->updateBonus(BONS_CHN_BUR, BONS_NON, true);
				cond = true;
				total += 6;
			}
			else
				nations[TURN_CHN]->updateBonus(BONS_CHN_BUR, BONS_NON, false);

			if (bonusVals[TURN_CHN][BONS_CHN_BUR].bin != cond)
			{
				tmp.bonus = BONS_CHN_BUR;
				tmp.bin = cond;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_CHN][BONS_CHN_BUR].bin = cond;
			}
		}
		break;
	}
	case TURN_UKE:
	{
		tmp.nat = TURN_UKE;

		// Territory bonus, 5
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
				if (territories->getTerritoryOwner(ters[i]) != TURN_UKE)
					cond = false;

			if (cond)
			{
				nations[TURN_UKE]->updateBonus(BONS_UKE_TER, BONS_NON, true);
				total += 5;
			}
			else
				nations[TURN_UKE]->updateBonus(BONS_UKE_TER, BONS_NON, false);

			if (bonusVals[TURN_UKE][BONS_UKE_TER].bin != cond)
			{
				tmp.bonus = BONS_UKE_TER;
				tmp.bin = cond;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_UKE][BONS_UKE_TER].bin = cond;
			}
		}
		break;
	}
	case TURN_UKP:
	{
		tmp.nat = TURN_UKP;

		int ukpIdx = (gameType == GLOBAL_GAME) ? BONS_UKP_GLO_TER : BONS_UKP_TER;

		// Territory bonus, 5
		{
			bool cond = false;

			if (warMatrix->getAtWarWith(TURN_JPN, TURN_UKP))
			{
				if (territories->getTerritoryOwner(TER_KWANGTUNG) == TURN_UKP && territories->getTerritoryOwner(TER_MALAYA) == TURN_UKP)
				{
					nations[TURN_UKP]->updateBonus(ukpIdx, BONS_NON, true);
					cond = true;
					total += 5;
				}
				else
					nations[TURN_UKP]->updateBonus(ukpIdx, BONS_NON, false);
			}

			if (bonusVals[TURN_UKP][BONS_UKP_TER].bin != cond)
			{
				tmp.bonus = ukpIdx;
				tmp.bin = cond;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_UKP][BONS_UKP_TER].bin = cond;
			}
		}
		break;
	}
	case TURN_ITA:
	{
		tmp.nat = TURN_ITA;

		// mediterraneanLandBonus, 5
		{
			bool cond = false;

			if (territories->getTerritoryOwnerSide(TER_GIBRALTAR) == SIDE_AXIS)
				cnt++;
			if (territories->getTerritoryOwnerSide(TER_SOUTH_FRANCE) == SIDE_AXIS)
				cnt++;
			if (territories->getTerritoryOwnerSide(TER_GREECE) == SIDE_AXIS)
				cnt++;
			if (territories->getTerritoryOwnerSide(TER_EGYPT) == SIDE_AXIS)
				cnt++;
			if (cnt >= 3)
			{
				nations[TURN_ITA]->updateBonus(BONS_ITA_GIB, BONS_NON, true);
				cond = true;
				total += 5;
			}
			else
				nations[TURN_ITA]->updateBonus(BONS_ITA_GIB, BONS_NON, false);

			if (bonusVals[TURN_ITA][BONS_ITA_GIB].bin != cond)
			{
				tmp.bonus = BONS_ITA_GIB;
				tmp.bin = cond;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_ITA][BONS_ITA_GIB].bin = cond;
			}

			cnt = 0;
		}

		// mediterraneanSeaBonus, 5
		{
			bool cond = false;

			if (popups)
			{
				int msgboxID = MessageBox(hDlg, L"Is the Mediterranean Sea\nfree of Allied warships?",
					L"Bonus Info", MB_YESNO);

				if (msgboxID == IDYES)
				{
					nations[TURN_ITA]->updateBonus(BONS_ITA_MED, BONS_NON, true);
					cond = true;
					total += 5;
				}
				else
					nations[TURN_ITA]->updateBonus(BONS_ITA_MED, BONS_NON, false);
			}
			else if (nations[TURN_ITA]->checkBonus(BONS_ITA_MED, false) == true)
			{
				cond = true;
				total += 5;
			}

			if (bonusVals[TURN_ITA][BONS_ITA_MED].bin != cond)
			{
				tmp.bonus = BONS_ITA_MED;
				tmp.bin = cond;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_ITA][BONS_ITA_MED].bin = cond;
			}
		}

		// northAfricaBonus, 5
		{
			bool cond = false;

			if (territories->getTerritoryOwnerSide(TER_MOROCCO) == SIDE_AXIS && territories->getTerritoryOwnerSide(TER_ALGERIA) == SIDE_AXIS &&
				territories->getTerritoryOwnerSide(TER_TUNISIA) == SIDE_AXIS && territories->getTerritoryOwnerSide(TER_LIBYA) == SIDE_AXIS &&
				territories->getTerritoryOwnerSide(TER_TOBRUK) == SIDE_AXIS && territories->getTerritoryOwnerSide(TER_ALEXANDRIA) == SIDE_AXIS)
			{
				nations[TURN_ITA]->updateBonus(BONS_ITA_AFR, BONS_NON, true);
				cond = true;
				total += 5;
			}
			else
				nations[TURN_ITA]->updateBonus(BONS_ITA_AFR, BONS_NON, false);

			if (bonusVals[TURN_ITA][BONS_ITA_AFR].bin != cond)
			{
				tmp.bonus = BONS_ITA_AFR;
				tmp.bin = cond;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_ITA][BONS_ITA_AFR].bin = cond;
			}
		}

		// middleEastBonus, 2 each
		{
			if (territories->getTerritoryOwner(TER_IRAQ) == TURN_ITA)
				cnt++;
			if (territories->getTerritoryOwner(TER_PERSIA) == TURN_ITA)
				cnt++;
			if (territories->getTerritoryOwner(TER_NW_PERSIA) == TURN_ITA)
				cnt++;
			nations[TURN_ITA]->updateBonus(BONS_ITA_PER, cnt, false);

			if (bonusVals[TURN_ITA][BONS_ITA_PER].val != cnt)
			{
				tmp.bonus = BONS_ITA_PER;
				tmp.val = cnt;
				bonusUpdate.push_back(tmp);

				bonusVals[TURN_ITA][BONS_ITA_PER].val = cnt;
			}

			total += 2 * cnt;
			cnt = 0;
		}

		break;
	}
	case TURN_ANZ:
	{
		tmp.nat = TURN_ANZ;

		if (warMatrix->getAtWarWith(TURN_JPN, TURN_ANZ))
		{
			// origTerritoryBonus, 5
			{
				bool cond0 = (territories->getTerritoryOwnerSide(TER_MALAYA) == SIDE_ALLIES);
				bool cond1 = true;

				uint16_t ters[10] = { TER_W_AUSTRALIA, TER_N_TERRITORY, TER_S_AUSTRALIA, TER_QUEENSLAND,
					TER_NEW_S_WALES, TER_VICTORIA, TER_NEW_ZEALAND, TER_SOLOMON_ISL, TER_NEW_BRITAIN, TER_NEW_GUINEA };

				if (cond0)
				{
					for (int i = 0; i < 10; i++)
						if (territories->getTerritoryOwner(ters[i]) != TURN_ANZ)
							cond1 = false;

					if (cond1)
					{
						nations[TURN_ANZ]->updateBonus(BONS_ANZ_TER, BONS_NON, true);
						total += 5;
					}
					else
						nations[TURN_ANZ]->updateBonus(BONS_ANZ_TER, BONS_NON, false);
				}
				else
					nations[TURN_ANZ]->updateBonus(BONS_ANZ_TER, BONS_NON, false);

				if (bonusVals[TURN_ANZ][BONS_ANZ_TER].bin != (cond0 && cond1))
				{
					tmp.bonus = BONS_ANZ_TER;
					tmp.bin = (cond0 && cond1);
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_ANZ][BONS_ANZ_TER].bin = (cond0 && cond1);
				}
			}

			// islandsBonus, 5
			{
				bool cond = false;

				if (territories->getTerritoryOwnerSide(TER_DUT_N_GUINEA) == SIDE_ALLIES && territories->getTerritoryOwnerSide(TER_NEW_GUINEA) == SIDE_ALLIES &&
					territories->getTerritoryOwnerSide(TER_NEW_BRITAIN) == SIDE_ALLIES && territories->getTerritoryOwner(TER_SOLOMON_ISL) == SIDE_ALLIES)
				{
					nations[TURN_ANZ]->updateBonus(BONS_ANZ_ISL, BONS_NON, true);
					cond = true;
					total += 5;
				}
				else
					nations[TURN_ANZ]->updateBonus(BONS_ANZ_ISL, BONS_NON, false);

				if (bonusVals[TURN_ANZ][BONS_ANZ_ISL].bin != cond)
				{
					tmp.bonus = BONS_ANZ_ISL;
					tmp.bin = cond;
					bonusUpdate.push_back(tmp);

					bonusVals[TURN_ANZ][BONS_ANZ_ISL].bin = cond;
				}
			}
		}
		break;
	}
	case TURN_FRA:
	{
		tmp.nat = TURN_FRA;

		// franceLiberationBonus
		if (bonusVals[TURN_FRA][BONS_FRA_LIB].bin != franceLiberated)
		{
			nations[TURN_FRA]->updateBonus(BONS_FRA_LIB, BONS_NON, true);

			int msgboxID = MessageBox(hDlg, L"Place 12 IPCs worth of units in France",
				L"France Liberated", MB_OK);

			tmp.bonus = BONS_FRA_LIB;
			tmp.bin = franceLiberated;
			bonusUpdate.push_back(tmp);

			bonusVals[TURN_FRA][BONS_FRA_LIB].bin = franceLiberated;
		}

		break;
	}
	default:
		break;
	}

	// Keep track of the capital capture transfer values
	if (_transferValTurn != turn || _transferValNat != nat)
	{
		_transferValTurn = turn;
		_transferValNat = nat;

		_transferVal = transferVal;
	}
	else if (transferVal > 0)
		_transferVal += transferVal;

	// Change in bonuses this turn
	int delta = (total + _transferVal) - nations[nat]->getNationBonus(turn);

	// Can only have income if nation controls capital
	if (nations[nat]->getNationControlsCapital())
	{
		nations[nat]->setNationBonus(turn, total + _transferVal);
		nations[nat]->addNationBank(turn + 1, delta);
	}
}

void BonusClass::resetBonusUpdate()
{
	bonusUpdate.resize(0);
}

vector<bonusTransaction>* BonusClass::getBonusUpdate()
{
	return &bonusUpdate;
}

