
#include "ItalyClass.h"

Italy::Italy(char nat[4])
	:Nation(nat, 10, 0, 9) 
{
	atWar = true;

	mediterraneanLandBonus = false;
	mediterraneanSeaBonus = false;
	northAfricaBonus = false;
	middleEastBonus = 0;
};

void Italy::updateBonus(int bonus, int val, bool cond)
{
	switch (bonus)
	{
	case BONS_ITA_GIB:
		mediterraneanLandBonus = cond;
		break;
	case BONS_ITA_MED:
		mediterraneanSeaBonus = cond;
		break;
	case BONS_ITA_AFR:
		northAfricaBonus = cond;
		break;
	case BONS_ITA_PER:
		middleEastBonus = val;
		break;
	default:
		break;
	}
}

bool Italy::checkBonus(int bonus, bool)
{
	switch (bonus)
	{
	case BONS_ITA_GIB: return mediterraneanLandBonus;
	case BONS_ITA_MED: return mediterraneanSeaBonus;
	case BONS_ITA_AFR: return northAfricaBonus;
	default:
		return false;
	}
}

int Italy::checkBonus(int bonus)
{
	switch (bonus)
	{
	case BONS_ITA_PER: return middleEastBonus;
	default:
		return BONS_NON;
	}
}

