#pragma once

#include "framework.h"
#include "Resource.h"

#ifndef PURCHASE_CLASS
#define PURCHASE_CLASS

class Purchase
{
public:
	Purchase();
	~Purchase();

	void reset();

	void setHasResearch(bool);

	void updateVal(int);
	void undoVal(int);

	int getVal(int);
	int getCost(int);
	int getTotQuant();

	bool calcPrice(int&, int, int);

	void addPurchases(Purchase&);
	void setPurchases(int, int);
	int getPurchases(int);

private:
	int units[20];

	int battleCost, airccCost, cruiseCost,
		destrCost, subCost, transCost;
};

#endif
