#include "../header/TerritoryClass.h"

Territory::Territory(WCHAR* n, int a, int orig, int own, int v, int m, bool coast, bool chn)
{
	wcsncpy_s(name, n, TERRITORY_NAMELEN);
	alphabet = a;
	original = orig;
	owner = own;
	value = v;

	map = m;
	city = CITY_NON;
	isCap = false;

	isCoastal = coast;
	isIsland = false;
	isValidForChina = chn;

	industrialComplex = NULL;
	airBase = NULL;
	navalBase = NULL;
}

Territory::~Territory()
{
	if (industrialComplex != NULL)
		delete industrialComplex;

	if (airBase != NULL)
		delete airBase;

	if (navalBase != NULL)
		delete navalBase;
}


void Territory::setOriginal(int orig)
{
	original = orig;
}

void Territory::setOwner(int own)
{
	owner = own;
}

void Territory::setMap(int m)
{
	map = m;
}

void Territory::setCity(int c, bool cap)
{
	city = c;
	isCap = cap;
}

void Territory::setIsCap(bool cond)
{
	isCap = cond;
}

void Territory::setIsIsland(bool i)
{
	isIsland = i;
}


terName& Territory::getName()
{
	terName tmp;
	wcsncpy_s(tmp.t, name, TERRITORY_NAMELEN);
	return tmp;
}

int Territory::getAlphabet()
{
	return alphabet;
}

int Territory::getSide()
{
	return whichSide(owner);
}

int Territory::getOwner()
{
	return owner;
}

int Territory::getOriginalSide()
{
	return whichSide(original);
}

int Territory::getOriginal()
{
	return original;
}

int Territory::getValue()
{
	return value;
}

int Territory::getMap()
{
	return map;
}

int Territory::getCity()
{
	return city;
}

bool Territory::getIsCap()
{
	return isCap;
}

bool Territory::getIsCoastal()
{
	return isCoastal;
}

bool Territory::getIsIsland()
{
	return isIsland;
}


bool Territory::getIsValidForChina()
{
	return isValidForChina;
}

bool Territory::getValidForMinorIC()
{
	// Must have IPC value of 2 or higher
	// Cannot be built on an island
	if (value >= 2 && !isIsland)
		return true;
	else
		return false;
}

bool Territory::getValidForMajorIC()
{
	// Must have IPC value of 3 or higher
	// Must by controlled by original owner
	// Cannot be built on an island
	if (value >= 3 && (owner == original) && !isIsland)
		return true;
	else
		return false;
}

bool Territory::getValidForAirBase()
{
	// Can be built on any controlled territory
	return true;
}

bool Territory::getValidForNavalBase()
{
	// Can be built on any controlled coastal territory
	if (isCoastal)
		return true;
	else
		return false;
}


bool Territory::placeIC(int type)
{
	if (type == MINOR_IC)
	{
		if (getValidForMinorIC() && industrialComplex == NULL)
		{
			industrialComplex = new IndustrialComplex(MINOR_IC);
			return true;
		}
		else
			return false;
	}
	else if (type == MAJOR_IC)
	{
		if (getValidForMajorIC() && industrialComplex == NULL)
		{
			industrialComplex = new IndustrialComplex(MAJOR_IC);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Territory::upgradeIC()
{
	if (getValidForMajorIC() && industrialComplex != NULL)
	{
		if (industrialComplex->getICType() == MINOR_IC)
		{
			industrialComplex->upgradeIC();
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Territory::downgradeIC()
{
	if (industrialComplex != NULL)
		return industrialComplex->downgradeIC();
	else
		return false;
}

bool Territory::destroyIC()
{
	if (industrialComplex != NULL)
	{
		delete industrialComplex;
		industrialComplex = NULL;
		return true;
	}
	else
		return false;
}

bool Territory::placeAirBase()
{
	if (getValidForAirBase() && airBase == NULL)
	{
		airBase = new AirBase();
		return true;
	}
	else
		return false;
}

bool Territory::placeNavalBase()
{
	if (getValidForNavalBase() && navalBase == NULL)
	{
		navalBase = new NavalBase();
		return true;
	}
	else
		return false;
}


bool Territory::getHasIC()
{
	if (industrialComplex != NULL)
		return true;
	else
		return false;
}

int Territory::getICType()
{
	if (industrialComplex != NULL)
		return industrialComplex->getICType();
	else
		return NULL_IC;
}

int Territory::getICCapacity()
{
	if (industrialComplex != NULL)
		return industrialComplex->getICCapacity();
	else
		return 0;

}
