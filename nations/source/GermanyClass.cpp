#include "../header/GermanyClass.h"

Germany::Germany(char nat[4])
	:Nation(nat, 30, 10, 9) 
{
	atWar = true;

	notAtWarWithSovBonus = true;
	controlSovTerrBonus = 0;
	axisCaucusBonus = false;
	gerEgyptBonus = false;
	denNorBonus = true; 
	gerMidEastBonus = 0;
};

void Germany::updateBonus(int bonus, int bonusVal, bool bonusBin)
{
	switch (bonus)
	{
	case BONS_GER_SOV:
		notAtWarWithSovBonus = bonusBin;
		break;
	case BONS_GER_CTY:
		controlSovTerrBonus = bonusVal;
		break;
	case BONS_GER_CAU:
		axisCaucusBonus = bonusBin;
		break;
	case BONS_GER_EGY:
		gerEgyptBonus = bonusBin;
		break;
	case BONS_GER_DEN:
		denNorBonus = bonusBin;
		break;
	case BONS_GER_PER:
		gerMidEastBonus = bonusVal;
		break;
	default:
		break;
	}
}

bool Germany::checkBonus(int bonus, bool)
{
	switch (bonus)
	{
	case BONS_GER_SOV: return notAtWarWithSovBonus;
	case BONS_GER_CAU:	return axisCaucusBonus;
	case BONS_GER_EGY: return gerEgyptBonus;
	case BONS_GER_DEN: return denNorBonus;
	default:
		return false;
	}
}

int Germany::checkBonus(int bonus)
{
	switch (bonus)
	{
	case BONS_GER_CTY: return controlSovTerrBonus;
	case BONS_GER_PER:	return gerMidEastBonus;
	default:
		return BONS_NON;
	}
}
