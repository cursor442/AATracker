
#include "SovietClass.h"

Soviet::Soviet(char nat[4], int type)
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

	// Turn 1 - First turn
	bonus[1] = 0;
	penalty[1] = 0;
	expenses[1] = 0;

	// Turn 2 - Preview of next bank
	income[2] = NULL_VAL;
	bonus[2] = NULL_VAL;
	penalty[2] = NULL_VAL;
	expenses[2] = NULL_VAL;
	territories[2] = NULL_VAL;

	if (type == EUROPE_GAME)
	{
		bank[0] = 28;
		bank[1] = 28;
		bank[2] = 56;
		income[0] = 28;
		income[1] = 28;
		territories[0] = 24;
		territories[1] = 24;
	}
	else if (type == GLOBAL_GAME)// Global
	{
		bank[0] = 37;
		bank[1] = 37;
		bank[2] = 74;
		income[0] = 37;
		income[1] = 37;
		territories[0] = 33;
		territories[1] = 33;
	}

	independenceBonus = false;
	controlAxisTerrBonus = 0;
	controlGerBonus = false;
}

void Soviet::updateBonus(int num, int val, bool cond)
{
	switch (num)
	{
	case BONS_SOV_SEA:
		independenceBonus = cond;
		break;
	case BONS_SOV_AXT:
		controlAxisTerrBonus = val;
		break;
	case BONS_SOV_GER:
		controlGerBonus = cond;
		break;
	default:
		break;
	}
}

bool Soviet::checkBonus(int num, bool)
{
	switch (num)
	{
	case BONS_SOV_SEA: return independenceBonus;
	case BONS_SOV_GER:	return controlGerBonus;
	default:
		return false;
	}
}

int Soviet::checkBonus(int num)
{
	switch (num)
	{
	case BONS_SOV_AXT: return controlAxisTerrBonus;
	default:
		return 0;
	}
}