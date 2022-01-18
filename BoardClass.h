#pragma once

#include "NationClass.h"
#include "GermanyClass.h"
#include "SovietClass.h"
#include "JapanClass.h"
#include "UnitedStatesClass.h"
#include "ChinaClass.h"
#include "UnitedKingdomClass.h"
#include "ItalyClass.h"
#include "ANZACClass.h"
#include "FranceClass.h"
#include "WarMatrix.h"
#include "PurchaseClass.h"
#include "Territories.h"
#include "BonusClass.h"

struct vicDlyEur {
	bool vicDly;
	uint16_t nat;
};

class Board
{
public:
	Board();
	~Board();

	void         configureTerritories();
	void         setTerritoryOwner(uint16_t, uint16_t);
	void         getTerritoryName(uint16_t, listTerritory&);
	uint16_t     getTerritoryAlphabet(uint16_t);
	uint16_t     getTerritoryOwner(uint16_t);
	uint16_t     getTerritoryValue(uint16_t);
	uint16_t     getTerritoryOriginal(uint16_t);
	void         transferTerritory(HWND, int, int&, int&, int&, bool&, bool&);
//	vector<int>& transferTerritory(uint16_t, uint16_t);
	void         transferTerritory(HWND, int, int, vector<int>&);
	void         transferTerritoryAllies(HWND, uint16_t, vector<vector<int>>&);
	uint16_t     calcNationIncome(uint16_t);

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
	WarMatrix* getWarMatrix();
	bool     getAtWarWith(int, int);
	uint16_t whichSide(uint16_t);
	bool     canDeclareWarOn(uint16_t, uint16_t);

	void     setLondonFallen();
	void     setNAFallen();
	void     setJPNDeclaredWarOnUK();
	void     setDeclaredWarOnUSA();
	void     setFranceLiberated();
	void     setSovControlGer();
	void     setUSABonus();
	void     setFRABonus();
	void     setLean(int);
	void     setMong();
	bool     isAtWar(uint16_t);

	bool     getLondonFallen();
	bool     getNAFallen();
	bool     getJPNDeclaredWarOnUK();
	bool     getDeclaredWarOnUSA();
	bool     getFranceLiberated();
	bool     getSovControlGer();
	bool     getUSABonus();
	bool     getFRABonus();
	int      getLean();
	bool     getMong();

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

	territory territories[201];
	bool mongoliaLean;
	int neutralLean;

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
	vector<uint16_t> axisVicCities, alliesVicCities;

	WarMatrix* warMatrix;
	BonusClass* bonuses;
};