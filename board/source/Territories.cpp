#include "../header/BoardClass.h"

void Board::setTerritoryOwner(int ter, int own)
{
	territories->setTerritoryOwner(ter, own);
}


void Board::getTerritoryName(int ter, listTerritory& list)
{
	territories->getTerritoryName(ter, list);
}

int Board::getTerritoryAlphabet(int ter)
{
	return territories->getTerritoryAlphabet(ter);
}

int Board::getTerritoryOriginal(int ter)
{
	return territories->getTerritoryOriginal(ter);
}

int Board::getTerritoryOwner(int ter)
{
	return territories->getTerritoryOwner(ter);
}

int Board::getTerritoryValue(int ter)
{
	return territories->getTerritoryValue(ter);
}

void Board::getNeutralTerrs(vector<territoryTransaction>& ters)
{
	territories->getNeutralTerrs(ters);
}


void Board::transferTerritory(HWND hDlg, int ter, int& own, int &captureAmount, int &prev, bool &isLib, bool& libCap)
{
	int currNat = own;
	prev = territories->getTerritoryOwner(ter);
	int orig = territories->getTerritoryOriginal(ter);
	int val = territories->getTerritoryValue(ter);

	int transferVal = 0;

	// This is definitely not the best way to do this
	bool isCap = territories->getIsCap(ter);
	libCap = false;
	isLib = false;

	if (isCap)
		if (whichSide(orig) == whichSide(own))
			libCap = true;

	// Figure out who gets the added income
	if (isCap && !libCap) // Capturing a capital
		own = own;
	else if (libCap) // Liberating a capital
	{
		own = orig;
		isLib = true;
	}
	else if ((whichSide(own) == whichSide(orig))) // Liberating a territory
	{
		if (nations[orig]->getNationControlsCapital()) // Only liberate if nation has its own capital
		{
			own = orig;
			isLib = true;
		}
		else if (own == orig) // Or if a nation is reclaiming its land regardless of capital
		{
			own = orig;
			isLib = true;
		}
		else // Nation takes territory for itself
		{
			own = own;
			isLib = false;
		}
	}
	else // Capturing a territory
		own = own;

	// Need to give new owner income first
	nations[own]->addNationIncome(gameTurn, val);

	// Handle capital liberations
	if (libCap)
	{
		switch (own)
		{
		case TURN_GER:
			{
				setNationControlsCapital(TURN_GER, true);
				setCityControl(CITY_BERLIN, SIDE_AXIS, TURN_GER);

				if (isBeforeNation(TURN_GER, currNat))
					nations[TURN_GER]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_GER));
				else
					nations[TURN_GER]->setNationIncome(gameTurn, calcNationIncome(TURN_GER));

				break;
			}
		case TURN_SOV:
			{
				setNationControlsCapital(TURN_SOV, true);
				setCityControl(CITY_MOSCOW, SIDE_ALLIES, TURN_SOV);

				if (isBeforeNation(TURN_SOV, currNat))
					nations[TURN_SOV]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_SOV));
				else
					nations[TURN_SOV]->setNationIncome(gameTurn, calcNationIncome(TURN_SOV));

				break;
			}
		case TURN_JPN:
			{
				setNationControlsCapital(TURN_JPN, true);
				setCityControl(CITY_TOKYO, SIDE_AXIS, TURN_JPN);

				if (isBeforeNation(TURN_JPN, currNat))
					nations[TURN_JPN]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_JPN));
				else
					nations[TURN_JPN]->setNationIncome(gameTurn, calcNationIncome(TURN_JPN));

				break;
			}
		case TURN_USA:
			{
			setNationControlsCapital(TURN_USA, true);
			if (gameType != PACIFIC_GAME)
				setCityControl(CITY_WASH, SIDE_ALLIES, TURN_USA);
			else
				setCityControl(CITY_SANFRAN, SIDE_ALLIES, TURN_USA);

			if (isBeforeNation(TURN_USA, currNat))
				nations[TURN_USA]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_USA));
			else
				nations[TURN_USA]->setNationIncome(gameTurn, calcNationIncome(TURN_USA));

			break;
			}
		case TURN_UKE:
			{
				setNationControlsCapital(TURN_UKE, true);
				setCityControl(CITY_LONDON, SIDE_ALLIES, TURN_UKE);

				if (isBeforeNation(TURN_UKE, currNat))
					nations[TURN_UKE]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_UKE));
				else
					nations[TURN_UKE]->setNationIncome(gameTurn, calcNationIncome(TURN_UKE));

				break;
			}
		case TURN_UKP:
			{
				setNationControlsCapital(TURN_UKP, true);
				setCityControl(CITY_CALC, SIDE_ALLIES, TURN_UKP);

				if (isBeforeNation(TURN_UKP, currNat))
					nations[TURN_UKP]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_UKP));
				else
					nations[TURN_UKP]->setNationIncome(gameTurn, calcNationIncome(TURN_UKP));

				break;
			}
		case TURN_ITA:
			{
				setNationControlsCapital(TURN_ITA, true);
				setCityControl(CITY_ROME, SIDE_AXIS, TURN_ITA);

				if (isBeforeNation(TURN_ITA, currNat))
					nations[TURN_ITA]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_ITA));
				else
					nations[TURN_ITA]->setNationIncome(gameTurn, calcNationIncome(TURN_ITA));

				break;
			}
		case TURN_ANZ:
			{
				setNationControlsCapital(TURN_ANZ, true);
				setCityControl(CITY_SYDNEY, SIDE_ALLIES, TURN_ANZ);

				if (isBeforeNation(TURN_ANZ, currNat))
					nations[TURN_ANZ]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_ANZ));
				else
					nations[TURN_ANZ]->setNationIncome(gameTurn, calcNationIncome(TURN_ANZ));

				break;
			}
		case TURN_FRA:
			{
				setNationControlsCapital(TURN_FRA, true);
				setCityControl(CITY_PARIS, SIDE_ALLIES, TURN_FRA);
				franceLiberated = true;

				if (isBeforeNation(TURN_FRA, currNat))
					nations[TURN_FRA]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_FRA));
				else
					nations[TURN_FRA]->setNationIncome(gameTurn, calcNationIncome(TURN_FRA));

				break;
			}
		default: break;
		}
	}
	// Handle capital captures
	else if (isCap)
	{
		switch (ter)
		{
		case TER_GERMANY:
		{
			if (isBeforeNation(TURN_GER, currNat))
				transferVal = nations[TURN_GER]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_GER]->getNationBank(gameTurn);

			setCityControl(CITY_BERLIN, SIDE_ALLIES, own);

			break;
		}
		case TER_RUSSIA:
		{
			if (isBeforeNation(TURN_SOV, currNat))
				transferVal = nations[TURN_SOV]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_SOV]->getNationBank(gameTurn);

			setCityControl(CITY_MOSCOW, SIDE_AXIS, own);

			break;
		}
		case TER_JAPAN:
		{
			if (isBeforeNation(TURN_JPN, currNat))
				transferVal = nations[TURN_JPN]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_JPN]->getNationBank(gameTurn);

			setCityControl(CITY_TOKYO, SIDE_ALLIES, own);

			break;
		}
		case TER_EASTERN_USA:
		{
			if (isBeforeNation(TURN_USA, currNat))
				transferVal = nations[TURN_USA]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_USA]->getNationBank(gameTurn);

			setCityControl(CITY_WASH, SIDE_AXIS, own);

			break;
		}
		case TER_WESTERN_USA:
		{
			if (isBeforeNation(TURN_USA, currNat))
				transferVal = nations[TURN_USA]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_USA]->getNationBank(gameTurn);

			setCityControl(CITY_SANFRAN, SIDE_AXIS, own);

			break;
		}
		case TER_UTD_KINGDOM:
		{
			if (isBeforeNation(TURN_UKE, currNat))
				transferVal = nations[TURN_UKE]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_UKE]->getNationBank(gameTurn);

			setCityControl(CITY_LONDON, SIDE_AXIS, own);

			break;
		}
		case TER_INDIA:
		{
			if (isBeforeNation(TURN_UKP, currNat))
				transferVal = nations[TURN_UKP]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_UKP]->getNationBank(gameTurn);

			setCityControl(CITY_CALC, SIDE_AXIS, own);

			break;
		}
		case TER_SOUTH_ITALY:
		{
			if (isBeforeNation(TURN_ITA, currNat))
				transferVal = nations[TURN_ITA]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_ITA]->getNationBank(gameTurn);

			setCityControl(CITY_ROME, SIDE_ALLIES, own);

			break;
		}
		case TER_NEW_S_WALES:
		{
			if (isBeforeNation(TURN_ANZ, currNat))
				transferVal = nations[TURN_ANZ]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_ANZ]->getNationBank(gameTurn);

			setCityControl(CITY_SYDNEY, SIDE_AXIS, own);

			break;
		}
		case TER_FRANCE:
		{
			if (isBeforeNation(TURN_FRA, currNat))
				transferVal = nations[TURN_FRA]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_FRA]->getNationBank(gameTurn);

			setCityControl(CITY_PARIS, SIDE_AXIS, own);

			break;
		}
		default: break;
		}
	}
	// Handle other territory captures and liberations (if req met)
	else
	{
		switch (ter)
		{
		case TER_ONTARIO:
			setCityControl(CITY_OTTAWA, whichSide(own), own);
			setNAFallen();
			break;
		case TER_POLAND:
			setCityControl(CITY_WARSAW, whichSide(own), own);
			break;
		case TER_NOVGOROD:
			setCityControl(CITY_LENIN, whichSide(own), own);
			break;
		case TER_VOLGOGRAD:
			setCityControl(CITY_STALIN, whichSide(own), own);
			break;
		case TER_EGYPT:
			setCityControl(CITY_CAIRO, whichSide(own), own);
			break;
		case TER_KIANGSU:
			setCityControl(CITY_SHANG, whichSide(own), own);
			break;
		case TER_KWANGTUNG:
			setCityControl(CITY_HONG, whichSide(own), own);
			break;
		case TER_PHILIPPINES:
			setCityControl(CITY_MANILA, whichSide(own), own);
			break;
		case TER_HAWAII:
			setCityControl(CITY_HONO, whichSide(own), own);
			break;
		case TER_W_CANADA: case TER_ALBERTA: case TER_QUEBEC: case TER_NEW_BRUNS:
			setNAFallen();
			break;
		default: break;
		}
	}

	captureAmount = transferVal;

	// Subtract income from previous owner
	if (isBeforeNation(prev, own))
		nations[prev]->addNationIncome(gameTurn + 1, -1 * val);
	else
		nations[prev]->addNationIncome(gameTurn, -1 * val);

	// Transfer the territory
	//setTerritoryOwner(ter, own);
	territories->transferTerritory(ter, own);
	if (isBeforeNation(prev, own))
		nations[prev]->addNationTerritories(gameTurn + 1, -1);
	else
		nations[prev]->addNationTerritories(gameTurn, -1);
	nations[own]->addNationTerritories(gameTurn, 1);

	// Update bonuses
	updateBonuses(hDlg, own, false, captureAmount);

	// check victory



}

void Board::transferTerritory(HWND hDlg, int currOwn, int origOwn, vector<int> &targets)
{
	int type = gameType;
	int low = (type != PACIFIC_GAME) ? (TER_ALBERTA) : (TER_EVENKIYSKIY);
	int high = (type != EUROPE_GAME) ? (TER_MEXICO) : (TER_WEST_INDIA);

	targets.resize(0);

	// Liberator gives liberated its territories
	for (int i = low; i <= high; i++)
	{
		if (territories->getTerritoryOwner(i) == currOwn && territories->getTerritoryOriginal(i) == origOwn)
		{
			// Transfer the territory
			setTerritoryOwner(i, origOwn);
			nations[currOwn]->addNationTerritories(currOwn, -1);
			nations[origOwn]->addNationTerritories(origOwn, 1);

			//int val = territories[i].value;
			int val = territories->getTerritoryValue(i);

			// Subtract income from previous owner
			if (isBeforeNation(currOwn, origOwn))
				nations[currOwn]->addNationIncome(gameTurn + 1, -1 * val);
			else
				nations[currOwn]->addNationIncome(gameTurn, -1 * val);

			// Update bonuses, but only if transferring to current nation
			if (origOwn == gameCurrNation)
				updateBonuses(hDlg, origOwn, false, 0);

			calcNextNationBank(origOwn, gameTurn);

			targets.push_back(i);
		}
	}
}

void Board::transferTerritoryAllies(HWND hDlg, int libNat, vector<vector<int>>& targets)
{
	int type = gameType;
	int low = (type != PACIFIC_GAME) ? (TER_ALBERTA) : (TER_EVENKIYSKIY);
	int high = (type != EUROPE_GAME) ? (TER_MEXICO) : (TER_WEST_INDIA);

	for (int i = 0; i < 10; i++)
		targets[i].resize(0);

	int currSide = whichSide(libNat);

	// Go through all territories, transfer all territories controlled by allies that originally belonged to
	// liberated nation and adjust economies
	for (int i = low; i <= high; i++)
	{
		// Controlled by same side, originally controlled by liberated nation, not currently controlled by liberated nation
		if (territories->getTerritoryOwnerSide(i) == currSide && 
			territories->getTerritoryOriginal(i) == libNat && territories->getTerritoryOwner(i) != libNat)
		{
			// Note who the territory is transferred from
			int prevOwn = territories->getTerritoryOwner(i);

			// Transfer the territory
			territories->setTerritoryOwner(i, libNat);
			nations[prevOwn]->addNationTerritories(prevOwn, -1);
			nations[libNat]->addNationTerritories(libNat, 1);

			int val = territories->getTerritoryValue(i);

			// Subtract income from previous owner
			if (isBeforeNation(prevOwn, libNat))
				nations[prevOwn]->addNationIncome(gameTurn + 1, -1 * val);
			else
				nations[prevOwn]->addNationIncome(gameTurn, -1 * val);

			// Update bonuses only if transferring to current nation
			if (libNat == gameCurrNation)
				updateBonuses(hDlg, libNat, false, 0);

			calcNextNationBank(libNat, gameTurn);

			targets[prevOwn].push_back(i);
		}
	}
}

int Board::calcNationIncome(int nat)
{
	int tot = 0;
	int low = TER_ALBERTA;
	int high = TER_MEXICO;

	if (gameType == EUROPE_GAME)
		high = TER_WEST_INDIA;
	else if (gameType == PACIFIC_GAME)
		low = TER_EVENKIYSKIY;

	for (int i = low; i <= high; i++)
		if (territories->getTerritoryOwner(i) == nat)
			tot += territories->getTerritoryValue(i);

	return tot;
}


void Board::setNeutralLean(int side)
{
	if (neutralLean == SIDE_NEUTRAL)
	{
		if (side == SIDE_AXIS || side == SIDE_ALLIES)
			neutralLean = side;
	}

	bonuses->setNeutralLean(neutralLean);
}

void Board::setMong()
{
	mongoliaLean = true;
}

int Board::getNeutralLean()
{
	return neutralLean;
}

bool Board::getMong()
{
	return mongoliaLean;
}

bool Board::attackNeutral(HWND hWnd)
{
	int msgboxID = MessageBox(hWnd, L"Attacking a strict neutral territory will\nturn all other strict neutrals against you!\nContinue?",
		L"Attack Strict Neutral", MB_ICONEXCLAMATION | MB_YESNO);

	if (msgboxID == IDNO)
		return false;
	else if (msgboxID == IDYES)
	{
		int currSide = whichSide(gameCurrNation);

		int side = SIDE_NEUTRAL;
		if (currSide == SIDE_AXIS)
			side = SIDE_ALLIES;
		else if (currSide == SIDE_ALLIES)
			side = SIDE_AXIS;

		setNeutralLean(side);
		return true;
	}
	else
		return false;
}

void Board::occupyNeutral()
{

}