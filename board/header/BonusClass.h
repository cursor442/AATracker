#ifndef BONUS_CLASS
#define BONUS_CLASS

#include "../../game/header/Resource.h"
#include "../../nations/header/NationClass.h"
#include "../../board/header/TerritoriesClass.h"
#include "../../board/header/WarMatrix.h"

struct bonusStatus {
	int val;
	bool bin;
};

struct bonusTransaction {
	int nat;
	int bonus;
	int val;
	bool bin;
};

class BonusClass
{
public:
	BonusClass();
	~BonusClass();

	void setGameType(int);
	void setNeutralLean(int);
	void setSovControlGer(bool);
	void setJpnDeclaredWarOnUK(bool);
	void setAxisDeclaredWarOnUSA(bool);
	void setFranceLiberated(bool);
	void setTransferValTurn(int);
	void setTransferValNat(int);
	void setTransferVal(int);

	int getNeutralLean();
	bool getSovControlGer();
	bool getJpnDeclaredWarOnUK();
	bool getAxisDeclaredWarOnUSA();
	bool getUsaMobilizationBonus();
	bool getFranceLiberated();
	int getTransferValTurn();
	int getTransferValNat();
	int getTransferVal();

	void updateBonuses(HWND, Nation**, WarMatrix*, Territories*, int, int, bool, int);

	void resetBonusUpdate();
	vector<bonusTransaction>* getBonusUpdate();
	

private:
	vector<bonusStatus> bonusVals[10];
	vector<bonusTransaction> bonusUpdate;

	int gameType;
	int neutralLean;

	bool sovControlGer;
	bool jpnDeclaredWarOnUK;
	bool axisDeclaredWarOnUSA;
	bool usaMobilizationBonus;
	bool franceLiberated;

	int _transferValTurn;
	int _transferValNat;
	int _transferVal;
};

#endif
