#include "../header/JapanClass.h"

Japan::Japan(char nat[4])
	:Nation(nat, 26, 10, 17) 
{
	atWar = true;

	pacificPeaceBonus = true;
	pacificIslandsBonus = false;
	majorTerritoriesBonus = 0;
	dutchTerritoriesBonus = false;
};

void Japan::updateBonus(int num, int val, bool cond)
{
	switch (num)
	{
	case BONS_JPN_UKZ:
		pacificPeaceBonus = cond;
		break;
	case BONS_JPN_ISL:
		pacificIslandsBonus = cond;
		break;
	case BONS_JPN_TER:
		majorTerritoriesBonus = val;
		break;
	case BONS_JPN_JAV:
		dutchTerritoriesBonus = cond;
		break;
	default:
		break;
	}
}

bool Japan::checkBonus(int num, bool)
{
	switch (num)
	{
	case BONS_JPN_UKZ: return pacificPeaceBonus;
	case BONS_JPN_ISL:	return pacificIslandsBonus;
	case BONS_JPN_JAV: return dutchTerritoriesBonus;
	default:
		return false;
	}
}

int Japan::checkBonus(int num)
{
	switch (num)
	{
	case BONS_JPN_TER: return majorTerritoriesBonus;
	default:
		return 0;
	}
}