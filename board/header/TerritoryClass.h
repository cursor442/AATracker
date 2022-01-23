#ifndef TERRITORY_CLASS
#define TERRITORY_CLASS

#include "../../game/header/Resource.h"
#include "Territories.h"
#include "TerritoryText.h"
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
	void setCity(int, bool = false);
	void setIsCap(bool);

	void setIsIsland(bool);

	terName& getName();
	int  getAlphabet();
	int  getSide();
	int  getOwner();
	int  getOriginal();
	int  getValue();

	int  getMap();
	int  getCity();
	bool getIsCap();
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
	int   city;
	bool  isCap;

	bool  isCoastal;
	bool  isIsland;
	bool  isValidForChina;

	IndustrialComplex* industrialComplex;
	AirBase* airBase;
	NavalBase* navalBase;
};

#endif
