#pragma once

#include "NationClass.h"

class UnitedKingdom : public Nation
{
public:
	UnitedKingdom(char nat[4], int, int);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	bool economy;
	bool europeBonus, pacificBonus;

};
