#pragma once

#include "NationClass.h"

class France : public Nation
{
public:
	France(char nat[4], int);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	bool liberationBonus;

};
