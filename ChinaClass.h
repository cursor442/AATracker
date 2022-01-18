#pragma once

#include "NationClass.h"

class China : public Nation
{
public:
	China(char nat[4]);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	bool burmaRoadBonus;

};
