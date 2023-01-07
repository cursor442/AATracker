#ifndef TERRITORIES_CLASS
#define TERRITORIES_CLASS

#include "../../game/header/Resource.h"
#include "../../board/header/TerritoryClass.h"
#include "../../board/header/MongoliaClass.h"

struct listTerritory {
	terName name;
	int     id;
	int     alph;
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
	void configEurNeutrals();
	void configEurDutch();
	void configEurFacilities();
	void configPacTerrs();
	void configPacCities();
	void configPacIslands();
	void configPacNeutrals();
	void configPacDutch();
	void configPacFacilities();
	void globalGameAdj();

	void setTerritoryOwner(int, int);

	void getTerritoryName(int, listTerritory&);
	int  getTerritoryAlphabet(int);
	int  getTerritoryOwner(int);
	int  getTerritoryOwnerSide(int);
	int  getTerritoryOriginal(int);
	int  getTerritoryOriginalSide(int);
	int  getTerritoryValue(int);

	bool getIsCap(int);
	bool getIsValidForChina(int);
	void transferTerritory(int, int);

	void setNeutralLean(int, int, bool = false);
	void getNeutralTerrs(vector<territoryTransaction>&);
	void getNeutralTerrs(vector<listTerritory>&, int, bool = false);
	int  getNeutralTerrUpdateSize();
	void getNeutralTerrUpdate(vector<territoryTransaction>&);

	void resetNeutralTerrUpdate();

private:
	vector<Territory*> territories;
	vector<territoryTransaction> neutrals;
	vector<territoryTransaction> neutralUpdate;

	int gameType;
	
	void alphabetizeList(vector<territoryTransaction>&);
	void alphabetizeList(vector<territoryTransaction>&, int, int);

};

#endif