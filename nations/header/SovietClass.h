#ifndef SOVIET_CLASS
#define SOVIET_CLASS

#include "NationClass.h"

class Soviet : public Nation
{
public:
	Soviet(char nat[4], int type);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	bool independenceBonus, controlGerBonus;
	int controlAxisTerrBonus;

};

#endif
