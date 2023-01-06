#include "../header/BoardClass.h"

Board::Board()
{
	gameType = NULL_GAME; // Defaults
	gameResearch = false;

	gameTurn = 1;
	gameCurrNation = TURN_GER;
	gameTurnPhase = PR_PHASE;

	territories = NULL;
	neutralLean = SIDE_NEUTRAL;
	mongoliaLean = SIDE_NEUTRAL;

	for (uint16_t i = 0; i < 10; i++)
		nations[i] = NULL;

	cities[CITY_BERLIN ] = SIDE_AXIS;
	cities[CITY_ROME   ] = SIDE_AXIS;
	cities[CITY_WARSAW ] = SIDE_AXIS;
	cities[CITY_OTTAWA ] = SIDE_ALLIES;
	cities[CITY_WASH   ] = SIDE_ALLIES;
	cities[CITY_LONDON ] = SIDE_ALLIES;
	cities[CITY_PARIS  ] = SIDE_ALLIES;
	cities[CITY_CAIRO  ] = SIDE_ALLIES;
	cities[CITY_LENIN  ] = SIDE_ALLIES;
	cities[CITY_MOSCOW ] = SIDE_ALLIES;
	cities[CITY_STALIN ] = SIDE_ALLIES;
	cities[CITY_SHANG  ] = SIDE_AXIS;
	cities[CITY_TOKYO  ] = SIDE_AXIS;
	cities[CITY_CALC   ] = SIDE_ALLIES;
	cities[CITY_HONG   ] = SIDE_ALLIES;
	cities[CITY_MANILA ] = SIDE_ALLIES;
	cities[CITY_SYDNEY ] = SIDE_ALLIES;
	cities[CITY_HONO   ] = SIDE_ALLIES;
	cities[CITY_SANFRAN] = SIDE_ALLIES;

	axisVictory = false; alliesVictory = false;

	vicCities[VIC_AXIS_EUR].resize(8);
	vicCities[VIC_AXIS_EUR  ] = { CITY_OTTAWA, CITY_WASH, CITY_LONDON, CITY_PARIS,
		CITY_CAIRO, CITY_LENIN, CITY_MOSCOW, CITY_STALIN };
	vicCities[VIC_ALLIES_EUR].resize(3);
	vicCities[VIC_ALLIES_EUR] = { CITY_BERLIN, CITY_ROME, CITY_WARSAW };
	vicCities[VIC_AXIS_PAC].resize(6);
	vicCities[VIC_AXIS_PAC  ] = { CITY_CALC, CITY_HONG, CITY_MANILA, CITY_SYDNEY,
		CITY_HONO, CITY_SANFRAN };
	vicCities[VIC_ALLIES_PAC].resize(1);
	vicCities[VIC_ALLIES_PAC] = { CITY_TOKYO };

	vicCitiesAxisEur = 3;
	vicCitiesAlliesEur = 8;
	vicCitiesAxisPac = 2;
	vicCitiesAlliesPac = 6;

	vicDlyAxisEur.vicDly = false;
	vicDlyAlliesEur.vicDly = false;
	vicDlyAxisPac.vicDly = false;

	londonFallen = false;
	NAFallen = false;
	jpnDeclaredWarOnUK = false;
	declaredWarOnUSA = false;
	franceLiberated = false;
	sovControlGer = false;
	usaBonus = false;
	fraBonus = false;
	jpnAttackedSoviet = false;
	jpnAttackedSovietFlag = false;
	sovAttackedJapan = false;

	axisVicCities.resize(2);
	alliesVicCities.resize(2);

	warMatrix = new WarMatrix();
	territories = new Territories();
	bonuses = new BonusClass;

	ready = false;
}

Board::~Board()
{
	for (int i = 0; i < 10; i++)
	{
		if (nations[i] != NULL)
			delete nations[i];
	}

	delete warMatrix;
	delete territories;
	delete bonuses;
}

void Board::setGameType(int type)
{
	gameType = type;

	if (gameType == PACIFIC_GAME)
		gameCurrNation = TURN_JPN;
	else
		gameCurrNation = TURN_GER;

	if (gameType != PACIFIC_GAME)
	{
		if (nations[0] == NULL)
			nations[0] = new Germany(nationNames[0]);
		if (nations[1] == NULL)
			nations[1] = new Soviet(nationNames[1], gameType);
		if (nations[5] == NULL)
			nations[5] = new UnitedKingdom(nationNames[5], UK_EUROPE, gameType);
		if (nations[7] == NULL)
			nations[7] = new Italy(nationNames[7]);
		if (nations[9] == NULL)
			nations[9] = new France(nationNames[9], gameType);
	}
	if (gameType != EUROPE_GAME)
	{
		if (nations[2] == NULL)
			nations[2] = new Japan(nationNames[2]);
		if (nations[4] == NULL)
			nations[4] = new China(nationNames[4]);
		if (nations[6] == NULL)
			nations[6] = new UnitedKingdom(nationNames[6], UK_PACIFIC, gameType);
		if (nations[8] == NULL)
			nations[8] = new ANZAC(nationNames[8]);
	}
	if (nations[3] == NULL)
		nations[3] = new UnitedStates(nationNames[3], gameType);

	if (gameType == EUROPE_GAME)
	{
		axisVicCities[0] = 3;
		alliesVicCities[0] = 8;
	}
	else if (gameType == PACIFIC_GAME)
	{
		axisVicCities[0] = 2;
		alliesVicCities[0] = 6;
	}
	else
	{
		axisVicCities[0] = 5;
		alliesVicCities[0] = 14;
	}
	axisVicCities[1] = axisVicCities[0];
	alliesVicCities[1] = alliesVicCities[0];

	ready = true;

	warMatrix->setGameType(type);
	territories->setGameType(type);
	bonuses->setGameType(type);
}

void Board::setGameResearch(bool research)
{
	gameResearch = research;

	if (gameResearch)
		gameTurnPhase = RS_PHASE;
	else
		gameTurnPhase = PR_PHASE;
}

void Board::setGameTurn(uint16_t turn)
{
	gameTurn = turn;
}

void Board::incGameTurn()
{
	gameTurn++;
}

void Board::setGameCurrNation(uint16_t nat)
{
	gameCurrNation = nat;
}

void Board::incGameCurrNation()
{
	if (gameType == GLOBAL_GAME)
	{
		if (gameCurrNation == TURN_FRA)
		{
			gameCurrNation = TURN_GER;
			incGameTurn();
		}
		else if (gameCurrNation == TURN_UKE)
			gameCurrNation = TURN_ITA;
		else
			gameCurrNation++;
	}
	else if (gameType == PACIFIC_GAME)
	{
		if (gameCurrNation == TURN_ANZ)
		{
			gameCurrNation = TURN_JPN;
			incGameTurn();
		}
		else if (gameCurrNation == TURN_UKP)
			gameCurrNation = TURN_ANZ;
		else if (gameCurrNation == TURN_CHN)
			gameCurrNation = TURN_UKP;
		else if (gameCurrNation == TURN_USA)
			gameCurrNation = TURN_CHN;
		else
			gameCurrNation = TURN_USA;
	}
	else if (gameType == EUROPE_GAME)
	{
		if (gameCurrNation == TURN_FRA)
		{
			gameCurrNation = TURN_GER;
			incGameTurn();
		}
		else if (gameCurrNation == TURN_ITA)
			gameCurrNation = TURN_FRA;
		else if (gameCurrNation == TURN_UKE)
			gameCurrNation = TURN_ITA;
		else if (gameCurrNation == TURN_USA)
			gameCurrNation = TURN_UKE;
		else if (gameCurrNation == TURN_SOV)
			gameCurrNation = TURN_USA;
		else
			gameCurrNation = TURN_SOV;
	}
}

void Board::setNationControlsCapital(uint16_t n, bool param)
{
	nations[n]->setNationControlsCapital(param);
}

void Board::setGameTurnPhase(uint16_t phase)
{
	gameTurnPhase = phase;
}

void Board::incGameTurnPhase()
{
	if (gameTurnPhase == CI_PHASE)
	{
		if (gameResearch)
		{
			gameTurnPhase = RS_PHASE;
		}
		else
			gameTurnPhase = PR_PHASE;
		incGameCurrNation();
	}
	else
		gameTurnPhase++;
}

void Board::setNationSize(uint16_t n, uint16_t size)
{
	nations[n]->setNationSize(size);
}

void Board::incNationSize(int n)
{
	if (gameType == GLOBAL_GAME && n == TURN_UKE)
	{
		nations[n++]->incNationSize();
		nations[n]->incNationSize();
	}
	else
		nations[n]->incNationSize();
}

int Board::getGameType()
{
	return gameType;
}

bool Board::getGameResearch()
{
	return gameResearch;
}

uint16_t Board::getGameTurn()
{
	return gameTurn;
}

uint16_t Board::getGameCurrNation()
{
	return gameCurrNation;
}

char* Board::getNationName(uint16_t n)
{
	return nations[n]->getNationName();
}

bool Board::getNationControlsCapital(uint16_t n)
{
	return nations[n]->getNationControlsCapital();
}

int Board::getGameTurnPhase()
{
	return gameTurnPhase;
}

void Board::setCityControl(int city, int side)
{
	cities[city] = side;
}

void Board::setCityControl(int city, int side, int nat)
{
	if (cities[city] != side) // City is changing hands
	{
		if (side == SIDE_AXIS)
		{
			axisVicCities[gameTurn]++;
			alliesVicCities[gameTurn]--;
		}
		else if (side == SIDE_ALLIES)
		{
			axisVicCities[gameTurn]--;
			alliesVicCities[gameTurn]++;
		}

		cities[city] = side;

		if (city < CITY_SHANG) // Europe map
		{
			if (side == SIDE_AXIS)
			{
				vicCitiesAxisEur++;
				vicCitiesAlliesEur--;

				if (city == CITY_WASH)
				{
					nations[TURN_USA]->setNationControlsCapital(false);
					transferBank(TURN_USA, nat);
				}
				else if (city == CITY_LONDON)
				{
					nations[TURN_UKE]->setNationControlsCapital(false);
					transferBank(TURN_UKE, nat);
				}
				else if (city == CITY_PARIS)
				{
					nations[TURN_FRA]->setNationControlsCapital(false);
					transferBank(TURN_FRA, nat);
				}
				else if (city == CITY_MOSCOW)
				{
					nations[TURN_SOV]->setNationControlsCapital(false);
					transferBank(TURN_SOV, nat);
				}
				else if (city == CITY_BERLIN && vicDlyAlliesEur.vicDly == true)
					vicDlyAlliesEur.vicDly = false;
				else if (city == CITY_ROME && vicDlyAlliesEur.vicDly == true)
					vicDlyAlliesEur.vicDly = false;
			}
			else
			{
				vicCitiesAxisEur--;
				vicCitiesAlliesEur++;

				if (city == CITY_BERLIN)
				{
					nations[TURN_GER]->setNationControlsCapital(false);
					transferBank(TURN_GER, nat);
				}
				else if (city == CITY_ROME)
				{
					nations[TURN_ITA]->setNationControlsCapital(false);
					transferBank(TURN_ITA, nat);
				}

				if (vicDlyAxisEur.vicDly == true && vicCitiesAxisEur < 8)
					vicDlyAxisEur.vicDly = false;
			}
		}
		else // Pacific map
		{
			if (side == SIDE_AXIS)
			{
				vicCitiesAxisPac++;
				vicCitiesAlliesPac--;

				if (city == CITY_CALC)
				{
					nations[TURN_UKP]->setNationControlsCapital(false);
					transferBank(TURN_UKP, nat);
				}
				else if (city == CITY_SYDNEY)
				{
					nations[TURN_ANZ]->setNationControlsCapital(false);
					transferBank(TURN_ANZ, nat);
				}
				else if (city == CITY_SANFRAN)
				{
					if (gameType == PACIFIC_GAME)
					{
						nations[TURN_USA]->setNationControlsCapital(false);
						transferBank(TURN_USA, nat);
					}
				}

				if (city == CITY_TOKYO && vicDlyAlliesEur.vicDly == true)
					vicDlyAlliesEur.vicDly = false;
			}
			else
			{
				vicCitiesAxisPac--;
				vicCitiesAlliesPac++;

				if (vicDlyAxisPac.vicDly == true && vicCitiesAxisPac < 6)
					vicDlyAxisPac.vicDly = false;

				if (city == CITY_TOKYO)
				{
					nations[TURN_JPN]->setNationControlsCapital(false);
					transferBank(TURN_JPN, nat);
				}
			}
		}
	}
}

uint16_t Board::getCityControl(uint16_t city)
{
	return cities[city];
}

void Board::transferBank(uint16_t victim, uint16_t aggressor)
{
	if (isBeforeNation(victim, aggressor)) // Take from next turn's bank
	{
		nations[aggressor]->addNationBonus(gameTurn, nations[victim]->getNationBank(gameTurn + 1));
		nations[victim]->setNationBank(gameTurn + 2, 0);
		nations[victim]->setNationBank(gameTurn + 1, 0);
		nations[victim]->setNationIncome(gameTurn + 1, 0);
		nations[victim]->setNationBonus(gameTurn + 1, 0);
	}
	else // Take from this turn's bank
	{
		nations[aggressor]->addNationBonus(gameTurn, nations[victim]->getNationBank(gameTurn));
		nations[victim]->setNationBank(gameTurn + 1, 0);
		nations[victim]->setNationBank(gameTurn, 0);
		nations[victim]->setNationIncome(gameTurn, 0);
		nations[victim]->setNationBonus(gameTurn, 0);
	}

	calcNextNationBank(aggressor, gameTurn);
}

void Board::setVictory(uint16_t side)
{
	if (side == SIDE_AXIS)
		axisVictory = true;
	else
		alliesVictory = true;
}

bool Board::getVictory(uint16_t side)
{
	if (side == SIDE_AXIS)
		return axisVictory;
	else
		return alliesVictory;
}

void Board::setNumVicCities(uint16_t whichCase, uint16_t val)
{
	if (whichCase == VIC_AXIS_EUR)
		vicCitiesAxisEur = val;
	else if (whichCase == VIC_ALLIES_EUR)
		vicCitiesAlliesEur = val;
	else if (whichCase == VIC_AXIS_PAC)
		vicCitiesAxisPac = val;
	else if (whichCase == VIC_ALLIES_PAC)
		vicCitiesAlliesPac = val;
}

void Board::setNumVicCities(uint16_t side, uint16_t turn, uint16_t val)
{
	if (side == SIDE_AXIS)
	{
		if (axisVicCities.size() <= turn)
		{
			uint16_t len = turn + 1;
			axisVicCities.resize(len);
		}
		axisVicCities[turn] = val;
	}
	else if (side == SIDE_ALLIES)
	{
		if (alliesVicCities.size() <= turn)
		{
			uint16_t len = turn + 1;
			alliesVicCities.resize(len);
		}
		alliesVicCities[turn] = val;
	}
}

uint16_t Board::getNumVicCities(uint16_t whichCase)
{
	if (whichCase == VIC_AXIS_EUR)
		return vicCitiesAxisEur;
	else if (whichCase == VIC_ALLIES_EUR)
		return vicCitiesAlliesEur;
	else if (whichCase == VIC_AXIS_PAC)
		return vicCitiesAxisPac;
	else if (whichCase == VIC_ALLIES_PAC)
		return vicCitiesAlliesPac;
	else
		return 0;
}

uint16_t Board::getNumVicCities(uint16_t side, uint16_t turn)
{
	if (side == SIDE_AXIS)
		return axisVicCities[turn];
	else if (side == SIDE_ALLIES)
		return alliesVicCities[turn];
	else
		return 0;
}

void Board::incVicCityHist()
{
	size_t size = axisVicCities.size();
	size++;
	axisVicCities.resize(size);
	alliesVicCities.resize(size);
	size--;
	axisVicCities[size] = axisVicCities[size - 1];
	alliesVicCities[size] = alliesVicCities[size - 1];
}

uint16_t Board::getNumCapCities(uint16_t side)
{
	uint16_t count = 0;
	if (side == SIDE_AXIS)
	{
		if (gameType != PACIFIC_GAME)
		{
			if (nations[TURN_GER]->getNationControlsCapital())
				count++;
			if (nations[TURN_ITA]->getNationControlsCapital())
				count++;
		}

		if (gameType != EUROPE_GAME)
		{
			if (nations[TURN_JPN]->getNationControlsCapital())
				count++;
		}
	}
	else
	{
		if (nations[TURN_USA]->getNationControlsCapital())
			count++;
		if (gameType != PACIFIC_GAME)
		{
			if (nations[TURN_SOV]->getNationControlsCapital())
				count++;
			if (nations[TURN_UKE]->getNationControlsCapital())
				count++;
			if (nations[TURN_FRA]->getNationControlsCapital())
				count++;
		}
		else
		{
			if (nations[TURN_UKP]->getNationControlsCapital())
				count++;
			if (nations[TURN_ANZ]->getNationControlsCapital())
				count++;
		}
	}

	return count;
}

void Board::setVicDly(uint16_t whichCase, vicDlyEur cpy)
{
	if (whichCase == VIC_AXIS_EUR)
	{
		vicDlyAxisEur.vicDly = cpy.vicDly;
		vicDlyAxisEur.nat = cpy.nat;
	}
	else if (whichCase == VIC_ALLIES_EUR)
	{
		vicDlyAlliesEur.vicDly = cpy.vicDly;
		vicDlyAlliesEur.nat = cpy.nat;
	}
	else
	{
		vicDlyAxisPac.vicDly = cpy.vicDly;
		vicDlyAxisPac.nat = cpy.nat;
	}
}

vicDlyEur Board::getVicDly(uint16_t whichCase)
{
	if (whichCase == VIC_AXIS_EUR)
		return vicDlyAxisEur;
	else if (whichCase == VIC_ALLIES_EUR)
		return vicDlyAlliesEur;
	else
		return vicDlyAxisPac;
}

bool Board::checkVictory(bool side)
{
	if (gameType == EUROPE_GAME)
	{
		if (side == SIDE_AXIS)// Control any 8 cities, must include either Berlin or Rome
		{
			if ((cities[CITY_BERLIN] == SIDE_AXIS || cities[CITY_ROME] == SIDE_AXIS) && vicCitiesAxisEur >= 8)
			{
				if (vicDlyAxisEur.vicDly == true && vicDlyAxisEur.nat == gameCurrNation) // Game over
					return true;
				else if (vicDlyAxisEur.vicDly == true) // Not yet
					return false;
				else
				{
					vicDlyAxisEur.vicDly = true;
					vicDlyAxisEur.nat = gameCurrNation;
					return false;
				}
			}
			else
				return false;
		}
		else
		{
			if ((cities[CITY_WASH] == SIDE_ALLIES || cities[CITY_LONDON] == SIDE_ALLIES ||
				cities[CITY_PARIS] == SIDE_ALLIES || cities[CITY_MOSCOW] == SIDE_ALLIES) && 
				cities[CITY_BERLIN] == SIDE_ALLIES && cities[CITY_ROME] == SIDE_ALLIES)
			{
				if (vicDlyAlliesEur.vicDly == true && vicDlyAlliesEur.nat == gameCurrNation) // Game over
					return true;
				else if (vicDlyAlliesEur.vicDly == true) // Not yet
					return false;
				else
				{
					vicDlyAlliesEur.vicDly = true;
					vicDlyAlliesEur.nat = gameCurrNation;
					return false;
				}
			}
			else
				return false;
		}
	}
	else if (gameType == PACIFIC_GAME)
	{
		if (side == SIDE_AXIS) // Check at end of ANZAC's turn
		{
			if (cities[CITY_TOKYO] == SIDE_AXIS && vicCitiesAxisPac >= 6) // Victory condition met
			{
				if (vicDlyAxisPac.vicDly == true) // Game over
					return true;
				else
				{
					vicDlyAxisPac.vicDly = true;
					return false;
				}
			}
			else
				return false;
		}
		else // Check at end of Japan's turn
		{
			if (cities[CITY_TOKYO] == SIDE_ALLIES)
				return true;
			else
				return false;
		}
	}
	else
	{
		if (side == SIDE_AXIS)
		{
			if ((cities[CITY_BERLIN] == SIDE_AXIS || cities[CITY_ROME] == SIDE_AXIS || cities[CITY_TOKYO] == SIDE_AXIS) 
				&& vicCitiesAxisEur >= 8) // Axis victory in Europe
			{
				if (vicDlyAxisEur.vicDly == true && vicDlyAxisEur.nat == gameCurrNation) // Game over
					return true;
				else if (vicDlyAxisEur.vicDly == true); // Not yet
					
				else
				{
					vicDlyAxisEur.vicDly = true;
					vicDlyAxisEur.nat = gameCurrNation;
				}
			}
			if ((cities[CITY_BERLIN] == SIDE_AXIS || cities[CITY_ROME] == SIDE_AXIS || cities[CITY_TOKYO] == SIDE_AXIS)
				&& vicCitiesAxisPac >= 6)
			{
				if (vicDlyAxisPac.vicDly == true && vicDlyAxisPac.nat == gameCurrNation) // Game over
					return true;
				else if (vicDlyAxisPac.vicDly == true); // Not yet

				else
				{
					vicDlyAxisPac.vicDly = true;
					vicDlyAxisPac.nat = gameCurrNation;
				}
			}
		}
		else
		{
			if (cities[CITY_BERLIN] == SIDE_ALLIES && cities[CITY_ROME] == SIDE_ALLIES && cities[CITY_TOKYO] == SIDE_ALLIES)
			{
				if (vicDlyAlliesEur.vicDly == true && vicDlyAlliesEur.nat == gameCurrNation) // Game over
					return true;
				else if (vicDlyAlliesEur.vicDly == true); // Not yet

				else
				{
					vicDlyAlliesEur.vicDly = true;
					vicDlyAlliesEur.nat = gameCurrNation;
				}
			}
		}
	}
	return false;
}