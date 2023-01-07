#ifndef BOARD_CLASS
#define BOARD_CLASS

#include "../../nations/header/NationClass.h"
#include "../../nations/header/GermanyClass.h"
#include "../../nations/header/SovietClass.h"
#include "../../nations/header/JapanClass.h"
#include "../../nations/header/UnitedStatesClass.h"
#include "../../nations/header/ChinaClass.h"
#include "../../nations/header/UnitedKingdomClass.h"
#include "../../nations/header/ItalyClass.h"
#include "../../nations/header/ANZACClass.h"
#include "../../nations/header/FranceClass.h"

#include "../../board/header/WarMatrix.h"
#include "../../board/header/TerritoriesClass.h"
#include "../../board/header/BonusClass.h"

struct vicDlyEur {
	bool vicDly;
	uint16_t nat;
};

class Board
{
public:
	Board();
	~Board();

	///////////////////////////////////////////////////////////////////////////
	//// Territories
	///////////////////////////////////////////////////////////////////////////

	void setTerritoryOwner(int, int);

	void getTerritoryName(int, listTerritory&);
	int  getTerritoryAlphabet(int);
	int  getTerritoryOriginal(int);
	int  getTerritoryOwner(int);
	int  getTerritoryValue(int);
	bool getTerritoryValidForChina(int);
	void getNeutralTerrs(vector<territoryTransaction>&);
	void getNeutralTerrs(vector<listTerritory>&, int, bool = false);
	int  getNeutralTerrUpdateSize();
	void getNeutralTerrUpdate(vector<territoryTransaction>&);
	void resetNeutralTerrUpdate();
	
	void transferTerritory(HWND, int, int&);
	void transferTerritory(HWND, int, int&, int&, int&, bool&, bool&);
	void transferTerritory(HWND, int, int, vector<int>&);
	void transferTerritoryAllies(HWND, int, vector<vector<int>>&);
	int  calcNationIncome(int);

	void setNeutralLean(int, bool = false);
	void setMongoliaLean(int);
	int  getNeutralLean();
	int  getMongoliaLean();
	bool attackNeutral(HWND);
	bool attackMongolia(HWND);
	bool attackJapan(HWND);
	bool attackSoviet(HWND);
	void occupyNeutral();

	void mongoliaJoinsSoviet(HWND);

	///////////////////////////////////////////////////////////////////////////
	//// Board Configuration
	///////////////////////////////////////////////////////////////////////////

	void setGameType(int);
	void setGameResearch(bool);
	void setGameTurn(uint16_t);
	void incGameTurn();
	void setGameCurrNation(uint16_t);
	void incGameCurrNation();
	void setNationControlsCapital(uint16_t, bool);
	void setGameTurnPhase(uint16_t);
	void incGameTurnPhase();
	void setNationSize(uint16_t, uint16_t);
	void incNationSize(int);
	void setNationBank(int, int, int);
	void addNationBank(int, int, int);
	void calcNextNationBank(uint16_t, uint16_t);
	void setNationIncome(int, int, int);
	void setNationBonus(int, int, int);
	void addNationBonus(int, int, int);
	void setNationPenalty(int, int, int);
	void setNationExpenses(int, int, int);
	void addNationExpenses(int, int, int);
	void setNationTerritories(int, int, int);
	void addNationTerritories(int, int, int);
	void setWarMatrix(int, int, bool);
	void setAtWarWith(int, int);

	void     addPurchases(Purchase[2]);
	void     setPurchases(uint16_t, uint16_t, uint16_t);
	uint16_t getPurchases(uint16_t, uint16_t);

	void     setResearch(uint16_t, uint16_t);
	void     setResearch(uint16_t, Research&);
	void     setFailures(uint16_t, uint16_t);

	bool     getResearch(uint16_t, uint16_t);
	uint16_t getFailures(uint16_t);
	uint16_t getCount(uint16_t);

	int      getGameType();
	bool     getGameResearch();
	uint16_t getGameTurn();
	uint16_t getGameCurrNation();
	char*    getNationName(uint16_t);
	bool     getNationControlsCapital(uint16_t);
	int      getGameTurnPhase();
	int      getNationBank(int, int);
	int      getNationIncome(int, int);
	int      getNationBonus(int, int);
	int      getNationPenalty(int, int);
	int      getNationExpenses(int, int);
	int      getNationTerritories(int, int);
	bool     getNationIsAtWar(int);
	WarMatrix* getWarMatrix();
	bool     getAtWarWith(int, int);
	bool     canDeclareWarOn(uint16_t, uint16_t);

	void     setLondonFallen();
	void     setNAFallen();
	void     setJPNDeclaredWarOnUK();
	void     setDeclaredWarOnUSA();
	void     setFranceLiberated();
	void     setSovControlGer();
	void     setUSABonus();
	void     setFRABonus();
	void     setJPNAttackedSoviet(bool);
	void     setJPNAttackedSovietFlag(bool);
	void     setSOVAttackedJapan(bool);
	bool     isAtWar(uint16_t);

	bool     getLondonFallen();
	bool     getNAFallen();
	bool     getJPNDeclaredWarOnUK();
	bool     getDeclaredWarOnUSA();
	bool     getFranceLiberated();
	bool     getSovControlGer();
	bool     getUSABonus();
	bool     getFRABonus();
	bool     getJPNAttackedSoviet();
	bool     getJPNAttackedSovietFlag();
	bool     getSOVAttackedJapan();

	void     updateBonuses(HWND, int, bool, int = 0);
	uint16_t checkBonus(uint16_t, uint16_t, bool&);
	vector<bonusTransaction>* getBonusUpdate();
	void     resetBonusUpdate();

	void     setCityControl(int, int);
	void     setCityControl(int, int, int);
	uint16_t getCityControl(uint16_t);
	void     transferBank(uint16_t, uint16_t);

	void     setVictory(uint16_t);
	bool     getVictory(uint16_t);
	void     setNumVicCities(uint16_t, uint16_t);
	void     setNumVicCities(uint16_t, uint16_t, uint16_t);
	uint16_t getNumVicCities(uint16_t);
	uint16_t getNumVicCities(uint16_t, uint16_t);
	void     incVicCityHist();
	uint16_t getNumCapCities(uint16_t);
	void     setVicDly(uint16_t, vicDlyEur);
	vicDlyEur getVicDly(uint16_t);
	bool     checkVictory(bool);

	char nationNames[10][4] = { "GER", "SOV", "JPN",
							    "USA", "CHN", "UKE",
							    "UKP", "ITA", "ANZ", "FRA" };

	bool ready;

private:
	uint32_t gameType;
	bool     gameResearch;

	uint16_t gameTurn;
	uint16_t gameCurrNation;
	uint16_t gameTurnPhase;

	int neutralLean;
	int mongoliaLean;

	Nation* nations[10];
	uint16_t cities[19];

	bool axisVictory, alliesVictory;

	vector<uint16_t> vicCities[4];
	uint16_t vicCitiesAxisEur;
	uint16_t vicCitiesAlliesEur;
	uint16_t vicCitiesAxisPac;
	uint16_t vicCitiesAlliesPac;
	vicDlyEur vicDlyAxisEur, vicDlyAlliesEur, vicDlyAxisPac;
	bool londonFallen, NAFallen, jpnDeclaredWarOnUK,
		declaredWarOnUSA, sovControlGer, usaBonus,
		franceLiberated, fraBonus;
	bool jpnAttackedSoviet, jpnAttackedSovietFlag;
	bool sovAttackedJapan;
	vector<uint16_t> axisVicCities, alliesVicCities;

	WarMatrix* warMatrix;
	Territories* territories;
	BonusClass* bonuses;
};

#endif
