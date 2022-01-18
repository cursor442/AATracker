#pragma once

#include "NationClass.h"

class ANZAC : public Nation
{
public:
	ANZAC(char nat[4]);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	bool origTerritoryBonus, islandsBonus;

};
