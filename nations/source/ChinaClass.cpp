#include "../header/ChinaClass.h"

China::China(char nat[4])
	:Nation(nat, 12, 6, 12) 
{
	atWar = true;

	burmaRoadBonus = true;
};

void China::updateBonus(int num, int val, bool cond)
{
	switch (num)
	{
	case BONS_CHN_BUR:
		burmaRoadBonus = cond;
		break;
	default:
		break;
	}
}

bool China::checkBonus(int num, bool)
{
	switch (num)
	{
	case BONS_CHN_BUR: return burmaRoadBonus;
	default:
		return false;
	}
}

int China::checkBonus(int num)
{
	switch (num)
	{
	case BONS_CHN_BUR: return burmaRoadBonus;
	default:
		return BONS_NON;
	}
}
