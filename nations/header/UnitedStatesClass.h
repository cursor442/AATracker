#ifndef USA_CLASS
#define USA_CLASS

#include "NationClass.h"

class UnitedStates : public Nation
{
public:
	UnitedStates(char nat[4], int type);

	void updateBonus(int, int, bool) override;
	bool checkBonus(int, bool) override;
	int  checkBonus(int) override;

private:
	int gameType;

	bool homelandBonus, pacificBonus, atlanticBonus, philippinesBonus,
		franceBonus, mobilizationBonus;
	bool territoryBonus;

};

#endif
