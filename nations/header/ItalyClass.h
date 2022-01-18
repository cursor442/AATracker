#ifndef ITALY_CLASS
#define ITALY_CLASS

#include "NationClass.h"

class Italy : public Nation
{
public:
	Italy(char nat[4]);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	bool mediterraneanLandBonus, mediterraneanSeaBonus, northAfricaBonus;
	int middleEastBonus;

};

#endif
