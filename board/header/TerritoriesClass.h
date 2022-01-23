#ifndef TERRITORIES_CLASS
#define TERRITORIES_CLASS

#include "../../game/header/Resource.h"
#include "../../board/header/TerritoryClass.h"

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
	void configEurIslands();
	void configEurFacilities();
	void configPacTerrs();
	void configPacIslands();
	void configPacFacilities();
	void globalGameAdj();

private:
	vector<Territory*> territories;

	int gameType;

};

#endif