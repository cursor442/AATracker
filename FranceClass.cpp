
#include "FranceClass.h"

France::France(char nat[4], int type)
	:Nation(nat, 0, 0, 0)
{
	strcpy_s(name, nat);
	controlsCapital = true;

	bank.resize(3);
	income.resize(3);
	bonus.resize(3);
	penalty.resize(3);
	expenses.resize(3);
	territories.resize(3);

	// Turn 0 - Startpoint
	bonus[0] = 0;
	penalty[0] = 0;
	expenses[0] = 0;

	// Turn 1 - First Turn
	bonus[1] = 0;
	penalty[1] = 0;
	expenses[1] = 0;

	// Turn 2 - Preview of next bank
	income[2] = NULL_VAL;
	bonus[2] = NULL_VAL;
	penalty[2] = NULL_VAL;
	expenses[2] = NULL_VAL;
	territories[2] = NULL_VAL;
	
	income[1] = NULL_VAL;
	territories[1] = NULL_VAL;

	if (type == EUROPE_GAME)
	{
		bank[0] = 17;
		bank[1] = 17;
		bank[2] = 34;
		income[0] = 17;
		income[1] = 17;
		territories[0] = 12;
		territories[1] = 12;
	}
	else if (type == GLOBAL_GAME)// Global
	{
		bank[0] = 19;
		bank[1] = 19;
		bank[2] = 38;
		income[0] = 19;
		income[1] = 19;
		territories[0] = 14;
		territories[1] = 14;
	}

	atWar = true;
	liberationBonus = false;
};

void France::updateBonus(int bonus, int val, bool cond)
{
	switch (bonus)
	{
	case BONS_FRA_LIB:
		liberationBonus = cond;
		break;
	default:
		break;
	}
}

bool France::checkBonus(int bonus, bool)
{
	switch (bonus)
	{
	case BONS_FRA_LIB: return liberationBonus;
	default:
		return false;
	}
}

int France::checkBonus(int bonus)
{
	return BONS_NON;
}