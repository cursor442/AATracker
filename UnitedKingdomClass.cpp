
#include "UnitedKingdomClass.h"

UnitedKingdom::UnitedKingdom(char nat[4], int econ, int type)
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
	penalty[0] = 0;
	expenses[0] = 0;

	// Turn 1 - First turn
	penalty[1] = 0;
	expenses[1] = 0;

	// Turn 2 - Preview of next bank
	income[2] = NULL_VAL;
	bonus[2] = NULL_VAL;
	penalty[2] = NULL_VAL;
	expenses[2] = NULL_VAL;
	territories[2] = NULL_VAL;

	economy = econ;

	if (econ == UK_EUROPE)
	{
		atWar = true;

		if (type == EUROPE_GAME)
		{
			bank[0] = 29;
			bank[1] = 29;
			bank[2] = 63;
			income[0] = 29;
			income[1] = 29;
			bonus[0] = 5;
			bonus[1] = 5;
			territories[0] = 26;
			territories[1] = 26;
		}
		else if (type == GLOBAL_GAME)// Global
		{
			bank[0] = 28;
			bank[1] = 28;
			bank[2] = 61;
			income[0] = 28;
			income[1] = 28;
			bonus[0] = 5;
			bonus[1] = 5;
			territories[0] = 26;
			territories[1] = 26;
		}
	}
	else if (econ == UK_PACIFIC)
	{
		if (type == PACIFIC_GAME)
		{
			bank[0] = 16;
			bank[1] = 16;
			bank[2] = 32;
			income[0] = 16;
			income[1] = 16;
			bonus[0] = 0;
			bonus[1] = 0;
			territories[0] = 11;
			territories[1] = 11;
		}
		else if (type == GLOBAL_GAME)// Global
		{
			atWar = true;

			bank[0] = 17;
			bank[1] = 17;
			bank[2] = 34;
			income[0] = 17;
			income[1] = 17;
			bonus[0] = 0;
			bonus[1] = 0;
			territories[0] = 11;
			territories[1] = 11;
		}
	}

	if (econ == UK_EUROPE)
		europeBonus = true;
	else
		europeBonus = false;
	pacificBonus = false;
}

void UnitedKingdom::updateBonus(int bonus, int val, bool cond)
{
	if (economy == UK_EUROPE)
	{
		switch (bonus)
		{
		case BONS_UKE_TER:
			europeBonus = cond;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (bonus)
		{
		case BONS_UKP_TER: case BONS_UKP_GLO_TER:
			pacificBonus = cond;
			break;
		default:
			break;
		}
	}
}

bool UnitedKingdom::checkBonus(int bonus, bool)
{
	if (economy == UK_EUROPE)
	{
		switch (bonus)
		{
		case BONS_UKE_TER:
			return europeBonus;
			break;
		default:
			return false;
			break;
		}
	}
	else
	{
		switch (bonus)
		{
		case BONS_UKP_TER: case BONS_UKP_GLO_TER:
			return pacificBonus;
			break;
		default:
			return false;
			break;
		}
	}
}

int UnitedKingdom::checkBonus(int num)
{
	return 0;
}

