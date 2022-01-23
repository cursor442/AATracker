#ifndef TERRITORY_CLASS
#define TERRITORY_CLASS

#include "../../game/header/Resource.h"
#include "Territories.h"
#include "IndustrialComplexClass.h"
#include "AirBaseClass.h"
#include "NavalBaseClass.h"

class Territory
{
public:
	Territory(WCHAR*, int, int, int, int, int, bool, bool = false);
	~Territory();

	void setOriginal(int);
	void setOwner(int);
	void setMap(int);

	void setIsIsland(bool);

	int  getSide();

	bool getIsCoastal();
	bool getIsIsland();
	bool getIsValidForChina();

	bool getValidForMinorIC();
	bool getValidForMajorIC();
	bool getValidForAirBase();
	bool getValidForNavalBase();

	bool placeIC(int);
	bool upgradeIC();
	bool downgradeIC();
	bool destroyIC();
	bool placeAirBase();
	bool placeNavalBase();

	bool getHasIC();
	int  getICType();
	int  getICCapacity();


private:
	WCHAR name[TERRITORY_NAMELEN];
	int   alphabet;
	int   original;
	int   owner;
	int   value;

	int   map;

	bool  isCoastal;
	bool  isIsland;
	bool  isValidForChina;

	IndustrialComplex* industrialComplex;
	AirBase* airBase;
	NavalBase* navalBase;
};

#endif
