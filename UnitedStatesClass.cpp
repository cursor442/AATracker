
#include "UnitedStatesClass.h"

UnitedStates::UnitedStates(char nat[4], int type)
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
	
	gameType = type;

	if (type == EUROPE_GAME)
	{
		bank[0] = 35;
		bank[1] = 35;
		bank[2] = 70;
		income[0] = 35;
		income[1] = 35;
		territories[0] = 5;
		territories[1] = 5;
	}
	else if (type == PACIFIC_GAME)
	{
		bank[0] = 17;
		bank[1] = 17;
		bank[2] = 34;
		income[0] = 17;
		income[1] = 17;
		territories[0] = 11;
		territories[1] = 11;
	}
	else if (type == GLOBAL_GAME)// Global
	{
		bank[0] = 52;
		bank[1] = 52;
		bank[2] = 104;
		income[0] = 52;
		income[1] = 52;
		territories[0] = 16;
		territories[1] = 16;
	}

	homelandBonus = false;
	pacificBonus = false;
	atlanticBonus = false;
	philippinesBonus = false;
	franceBonus = false;
	mobilizationBonus = false;

	territoryBonus = false;
}

void UnitedStates::updateBonus(int bonus, int val, bool cond)
{
	switch (gameType)
	{
	case EUROPE_GAME:
	{
		switch (bonus)
		{
		case BONS_USA_USA:
			homelandBonus = cond;
			break;
		case BONS_USA_EUR_TER:
			atlanticBonus = cond;
			break;
		default:
			break;
		}
		break;
	}
	case PACIFIC_GAME:
	{
		switch (bonus)
		{
		case BONS_USA_USA:
			homelandBonus = cond;
			break;
		case BONS_USA_PAC_TER:
			territoryBonus = cond;
			break;
		case BONS_USA_PAC_ISL:
			pacificBonus = cond;
			break;
		case BONS_USA_PHI:
			philippinesBonus = cond;
			break;
		case BONS_USA_PAC_WAR:
			mobilizationBonus = cond;
			break;
		default:
			break;
		}
		break;
	}
	case GLOBAL_GAME:
	{
		switch (bonus)
		{
		case BONS_USA_USA:
			homelandBonus = cond;
			break;
		case BONS_USA_GLO_ISL:
			pacificBonus = cond;
			break;
		case BONS_USA_GLO_TER:
			atlanticBonus = cond;
			break;
		case BONS_USA_PHI:
			philippinesBonus = cond;
			break;
		case BONS_USA_GLO_FRA:
			franceBonus = cond;
			break;
		case BONS_USA_GLO_WAR:
			mobilizationBonus = cond;
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

bool UnitedStates::checkBonus(int bonus, bool)
{
	switch (gameType)
	{
	case EUROPE_GAME:
	{
		switch (bonus)
		{
		case BONS_USA_USA: return homelandBonus;
		case BONS_USA_EUR_TER: return atlanticBonus;
		default: return BONS_NON;
		}
		break;
	}
	case PACIFIC_GAME:
	{
		switch (bonus)
		{
		case BONS_USA_USA: return homelandBonus;
		case BONS_USA_PAC_TER: return territoryBonus;
		case BONS_USA_PAC_ISL: return pacificBonus;
		case BONS_USA_PHI: return philippinesBonus;
		case BONS_USA_PAC_WAR: return mobilizationBonus;
		default: return BONS_NON;
		}
		break;
	}
	case GLOBAL_GAME:
	{
		switch (bonus)
		{
		case BONS_USA_USA: return homelandBonus;
		case BONS_USA_GLO_ISL: return pacificBonus;
		case BONS_USA_GLO_TER: return atlanticBonus;
		case BONS_USA_PHI: return philippinesBonus;
		case BONS_USA_GLO_FRA: return franceBonus;
		case BONS_USA_GLO_WAR: return mobilizationBonus;
		default: return BONS_NON;
		}
		break;
	}
	default:
		break;
	}
}

int UnitedStates::checkBonus(int num)
{
	return BONS_NON;
}
