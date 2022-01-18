#pragma once

#include "NationClass.h"

class Germany : public Nation
{
public:
	Germany(char nat[4]);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	bool notAtWarWithSovBonus, axisCaucusBonus, gerEgyptBonus,
		denNorBonus;
	int controlSovTerrBonus, gerMidEastBonus;

};
