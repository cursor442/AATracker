
#include "PurchaseClass.h"

Purchase::Purchase()
{
	for (int i = 0; i < 20; i++)
		units[i] = 0;

	battleCost = 20;
	airccCost = 16;
	cruiseCost = 12;
	destrCost = 8;
	subCost = 6;
	transCost = 7;
}

Purchase::~Purchase()
{

}

void Purchase::reset()
{
	for (int i = 0; i < 20; i++)
		units[i] = 0;

	battleCost = 20;
	airccCost = 16;
	cruiseCost = 12;
	destrCost = 8;
	subCost = 6;
	transCost = 7;
}

void Purchase::setHasResearch(bool res)
{
	if (res)
	{
		battleCost = 17;
		airccCost = 13;
		cruiseCost = 9;
		destrCost = 7;
		subCost = 5;
		transCost = 6;
	}
}

void Purchase::updateVal(int button)
{
	int val = (button / 2) - (IDB_INFUP / 2);
	int dir = button % 2;

	if (dir == 0) // Up
		units[val]++;
	else // Down
	{
		if (units[val] > 0)
			units[val]--;
	}
}

void Purchase::undoVal(int button)
{
	int val = (button / 2) - (IDB_INFUP / 2);
	int dir = button % 2;

	if (dir == 0) // Up
		units[val]--;
	else // Down
	{
		units[val]++;
	}
}

int Purchase::getVal(int button)
{
	int val = (button / 2) - (IDB_INFUP / 2);

	return units[val];
}

int Purchase::getCost(int button)
{
	int idx = (button / 2) - (IDB_INFUP / 2);

	switch (idx)
	{
	case 0:
		return units[0] * 3; // Infantry
	case 1:
		return units[1] * 4; // Artillery
	case 2:
		return units[2] * 4; // Mechanized Infantry
	case 3:
		return units[3] * 6; // Tank
	case 4:
		return units[4] * 5; // AAA
	case 5:
		return units[5] * 10; // Fighter
	case 6:
		return units[6] * 11; // Tactical Bomber
	case 7:
		return units[7] * 12; // Strategic Bomber
	case 8:
		return units[8] * battleCost; // Battleship
	case 9:
		return units[9] * airccCost; // Aircraft Carrier
	case 10:
		return units[10] * cruiseCost; // Cruiser
	case 11:
		return units[11] * destrCost; // Destroyer
	case 12:
		return units[12] * subCost; // Submarine
	case 13:
		return units[13] * transCost; // Transport
	case 14:
		return units[14] * 30; // Major IC
	case 15:
		return units[15] * 12; // Minor IC
	case 16:
		return units[16] * 20; // Minor IC Upgrade
	case 17:
		return units[17] * 15; // Air Base
	case 18:
		return units[18] * 15; // Naval Base
	case 19:
		return units[19] * 1; // Repairs
	}
}

int Purchase::getTotQuant()
{
	int quant = 0;
	for (int i = 0; i < 20; i++)
		quant += units[i];

	return quant;
}

bool Purchase::calcPrice(int& price, int bank, int resCost)
{
	price = 0;
	price += units[0]  * 3;          // Infantry
	price += units[1]  * 4;	         // Artillery
	price += units[2]  * 4;	         // Mechanized Infantry
	price += units[3]  * 6;	         // Tank
	price += units[4]  * 5;	         // AAA
	price += units[5]  * 10;	     // Fighter
	price += units[6]  * 11;	     // Tactical Bomber
	price += units[7]  * 12;	     // Strategic Bomber
	price += units[8]  * battleCost; // Battleship
	price += units[9]  * airccCost;	 // Aircraft Carrier
	price += units[10] * cruiseCost; // Cruiser
	price += units[11] * destrCost;	 // Destroyer
	price += units[12] * subCost;	 // Submarine
	price += units[13] * transCost;	 // Transport
	price += units[14] * 30;	     // Major IC
	price += units[15] * 12;	     // Minor IC
	price += units[16] * 20;	     // Minor IC Upgrade
	price += units[17] * 15;	     // Air Base
	price += units[18] * 15;	     // Naval Base
	price += units[19] * 1;	         // Repairs

	if (price > bank - resCost)
		return false;
	else
		return true;
}

void Purchase::addPurchases(Purchase& purch)
{
	for (int i = 0; i < 20; i++)
		this->units[i] += purch.units[i];
}

void Purchase::setPurchases(int idx, int val)
{
	this->units[idx] = val;
}

int Purchase::getPurchases(int idx)
{
	return this->units[idx];
}