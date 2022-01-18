
#include "ANZACClass.h"

ANZAC::ANZAC(char nat[4])
	:Nation(nat, 10, 0, 10) 
{
	origTerritoryBonus = false;
	islandsBonus = false;
};

void ANZAC::updateBonus(int bonus, int val, bool cond)
{
	switch (bonus)
	{
	case BONS_ANZ_TER:
		origTerritoryBonus = cond;
		break;
	case BONS_ANZ_ISL:
		islandsBonus = cond;
		break;
	default:
		break;
	}
}

bool ANZAC::checkBonus(int bonus, bool)
{
	switch (bonus)
	{
	case BONS_ANZ_TER: return origTerritoryBonus;
	case BONS_ANZ_ISL: return islandsBonus;
	default:
		return false;
	}
}

int ANZAC::checkBonus(int bonus)
{
	return BONS_NON;
}
