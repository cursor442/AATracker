#include "../header/BoardClass.h"

void Board::setWarMatrix(int axis, int ally, bool val)
{
	warMatrix->setWarMatrix(axis, ally, val);

	switch (gameType)
	{
	case EUROPE_GAME:
		if (ally == TURN_SOV || ally == TURN_USA || ally == TURN_UKE || ally == TURN_FRA)
			nations[ally]->goToWar();
		break;
	case PACIFIC_GAME:
		if (ally == TURN_USA || ally == TURN_CHN || ally == TURN_UKP || ally == TURN_ANZ)
			nations[ally]->goToWar();
		break;
	case GLOBAL_GAME:
		nations[ally]->goToWar();
		break;
	default: break;
	}		
}

void Board::setAtWarWith(int axis, int ally)
{
	warMatrix->setWarMatrix(axis, ally, true);

	if (ally < DUTCH_TER)
		nations[ally]->goToWar();
}

WarMatrix* Board::getWarMatrix()
{
	return warMatrix;
}

bool Board::getAtWarWith(int axis, int ally)
{
	return warMatrix->getAtWarWith(axis, ally);
}

bool Board::getNationIsAtWar(int nat)
{
	return nations[nat]->isAtWar();
}

void Board::setLondonFallen()
{
	londonFallen = true;
}

bool Board::getLondonFallen()
{
	return londonFallen;
}

void Board::setNAFallen()
{
	NAFallen = true;
}

bool Board::getNAFallen()
{
	return NAFallen;
}

void Board::setJPNDeclaredWarOnUK()
{
	jpnDeclaredWarOnUK = true;

	bonuses->setJpnDeclaredWarOnUK(true);
}

bool Board::getJPNDeclaredWarOnUK()
{
	return jpnDeclaredWarOnUK;
}

void Board::setDeclaredWarOnUSA()
{
	declaredWarOnUSA = true;

	bonuses->setAxisDeclaredWarOnUSA(true);
}

bool Board::getDeclaredWarOnUSA()
{
	return declaredWarOnUSA;
}

void Board::setFranceLiberated()
{
	franceLiberated = true;

	bonuses->setFranceLiberated(true);
}

bool Board::getFranceLiberated()
{
	return franceLiberated;
}

void Board::setSovControlGer()
{
	sovControlGer = true;

	bonuses->setSovControlGer(true);
}

bool Board::getSovControlGer()
{
	return sovControlGer;
}

void Board::setUSABonus()
{
	usaBonus = true;
}

bool Board::getUSABonus()
{
	return usaBonus;
}

void Board::setFRABonus()
{
	fraBonus = true;
}

bool Board::getFRABonus()
{
	return fraBonus;
}

void Board::setJPNAttackedSoviet(bool val)
{
	jpnAttackedSoviet = val;
}

bool Board::getJPNAttackedSoviet()
{
	return jpnAttackedSoviet;
}

void Board::setJPNAttackedSovietFlag(bool val)
{
	jpnAttackedSovietFlag = val;
}

bool Board::getJPNAttackedSovietFlag()
{
	return jpnAttackedSovietFlag;
}

void Board::setSOVAttackedJapan(bool val)
{
	sovAttackedJapan = val;
}

bool Board::getSOVAttackedJapan()
{
	return sovAttackedJapan;
}

bool Board::isAtWar(uint16_t nat)
{
	return nations[nat]->isAtWar();
}

bool Board::canDeclareWarOn(uint16_t aggressor, uint16_t defender)
{
	if (whichSide(aggressor) == whichSide(defender))
		return false;
	if (defender == TURN_UKP)
		return false;
	else if (whichSide(aggressor) == SIDE_AXIS)
	{
		if (getAtWarWith(aggressor, defender) == false) // Not already at war
		{
			if (aggressor == TURN_GER || aggressor == TURN_ITA)
			{
				if (defender == TURN_CHN && gameType == EUROPE_GAME)
					return false;
				else
					return true;
			}
			else if (aggressor == TURN_JPN)
			{
				if ((defender == TURN_SOV || defender == TURN_FRA) && gameType == PACIFIC_GAME)
					return false;
				else
					return true;
				// Technically Allies moving into China isn't a declaration of war, but should be treated as such
			}
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		if (getAtWarWith(defender, aggressor) == false) // Not already at war
		{
			if (aggressor == TURN_SOV)
			{
				if (defender == TURN_JPN && gameType == EUROPE_GAME)
					return false;
				else if (gameTurn >= 3) // Can't declare war on Europe until turn 4
					return true;
				else if (defender == TURN_JPN && gameType == GLOBAL_GAME)
					return true;
				else if (londonFallen == true)
					return true;
				else if ((defender == TURN_GER && getAtWarWith(TURN_ITA, TURN_SOV)) ||
					(defender == TURN_ITA && getAtWarWith(TURN_GER, TURN_SOV)))
					return true;
				else
					return false;
			}
			else if (aggressor == TURN_USA)
			{
				if (defender == TURN_JPN && gameType == EUROPE_GAME)
					return false;
				else if ((defender == TURN_GER || defender == TURN_ITA) && gameType == PACIFIC_GAME)
					return false;
				else if (gameTurn >= 2) // Turn 3 is unconditional
					return true;
				else if (londonFallen || NAFallen || jpnDeclaredWarOnUK)
					return true;
				else if ((defender == TURN_GER && (getAtWarWith(TURN_ITA, TURN_USA) || getAtWarWith(TURN_JPN, TURN_USA))) ||
					(defender == TURN_ITA && (getAtWarWith(TURN_GER, TURN_USA) || getAtWarWith(TURN_JPN, TURN_USA))) ||
					(defender == TURN_JPN && (getAtWarWith(TURN_GER, TURN_USA) || getAtWarWith(TURN_ITA, TURN_USA))))
					return true;
				else
					return false;
			}
			else if (aggressor == TURN_CHN)
			{
				return false;
				// Technically Axis moving into China isn't a declaration of war, but should be treated as such
			}
			else if (aggressor == TURN_UKE || aggressor == TURN_UKP)
			{
				if (defender == TURN_JPN && gameType == EUROPE_GAME)
					return false;
				else
					return true;
			}
			else if (aggressor == TURN_ANZ)
			{
				if (gameType == EUROPE_GAME)
					return false;
				else
					return true;
			}
			else if (aggressor == TURN_FRA)
			{
				if (gameType == PACIFIC_GAME)
					return false;
				else if (defender == TURN_JPN && gameType == EUROPE_GAME)
					return false;
				else
					return true;
			}
			else
				return false;
		}
		else
			return false;
	}
}

