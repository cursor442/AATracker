#ifndef JAPAN_CLASS
#define JAPAN_CLASS

#include "NationClass.h"

class Japan : public Nation
{
public:
	Japan(char nat[4]);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	bool pacificPeaceBonus, pacificIslandsBonus, dutchTerritoriesBonus;
	int majorTerritoriesBonus;

};

#endif
