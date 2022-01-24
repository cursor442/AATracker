#ifndef NATION_CLASS
#define NATION_CLASS

#include "../../game/header/framework.h"
#include "../../game/header/Resource.h"
#include "../../nationScreen/header/PurchaseClass.h"
#include "../../researchScreen/header/ResearchClass.h"

class Nation
{
public:
	Nation(char [4], int, int, int);
	virtual ~Nation();

	virtual void  setNationControlsCapital(bool);
	virtual void  setNationSize(int);
	virtual void  incNationSize();
	virtual void  setNationBank(int, int);
	virtual void  addNationBank(int, int);
	virtual void  calcNextNationBank(int);
	virtual void  setNationIncome(int, int);
	virtual void  addNationIncome(int, int);
	virtual void  setNationBonus(int, int);
	virtual void  addNationBonus(int, int);
	virtual void  setNationPenalty(int, int);
	virtual void  addNationPenalty(int, int);
	virtual void  setNationExpenses(int, int);
	virtual void  addNationExpenses(int, int);
	virtual void  setNationTerritories(int, int);
	virtual void  addNationTerritories(int, int);
	
	virtual void  addPurchases(Purchase&);
	virtual void  setPurchases(int, int);
	virtual int   getPurchases(int);

	virtual void  setResearch(int);
	virtual void  setResearch(Research&);
	virtual void  setFailures(int);

	virtual bool  getResearch(int);
	virtual int   getFailures();
	virtual int   getResearchCount();
				     
	virtual char* getNationName();
	virtual bool  getNationControlsCapital();
	virtual int   getNationSize();
	virtual int   getNationBank(int);
	virtual int   getNationIncome(int);
	virtual int   getNationBonus(int);
	virtual int   getNationPenalty(int);
	virtual int   getNationExpenses(int);
	virtual int   getNationTerritories(int);

	virtual void  goToWar();
	virtual bool  isAtWar();

	virtual void  updateBonus(int, int, bool);
	virtual bool  checkBonus(int, bool);
	virtual int   checkBonus(int);

protected:
	char name[4];
	bool controlsCapital;
	bool atWar;

	int nationSize;
	vector<int> bank;
	vector<int> income;
	vector<int> bonus;
	vector<int> penalty;
	vector<int> expenses;
	vector<int> territories;

	Purchase purchases;

	Research research;
};

#endif
