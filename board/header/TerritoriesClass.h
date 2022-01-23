#ifndef TERRITORIES_CLASS
#define TERRITORIES_CLASS

#include "../../game/header/Resource.h"
#include "../../board/header/TerritoryClass.h"

struct listTerritory {
	WCHAR name[TERRITORY_NAMELEN];
	int   id;
	int   alph;
};

struct territoryTransaction {
	int id;
	int side;
	int owner;
};

class Territories
{
public:
	Territories();
	~Territories();

	void setGameType(int);
	void configEurTerrs();
	void configEurCities();
	void configEurIslands();
	void configEurFacilities();
	void configPacTerrs();
	void configPacCities();
	void configPacIslands();
	void configPacFacilities();
	void globalGameAdj();

	void setTerritoryOwner(int, int);

	void getTerritoryName(int, listTerritory&);
	int  getTerritoryAlphabet(int);
	int  getTerritoryOwner(int);
	int  getTerritoryOriginal(int);
	int  getTerritoryValue(int);

	bool getIsCap(int);
	bool transferTerritory(int, int);

private:
	vector<Territory*> territories;

	int gameType;

};

#endif