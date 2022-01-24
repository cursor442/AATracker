#include "../header/NationClass.h"

Nation::Nation(char nat[4], int initBank, int initBonus, int initTerrs)
{
	strcpy_s(name, nat);
	controlsCapital = true;

	bank.resize(3);
	income.resize(3);
	bonus.resize(3);
	penalty.resize(3);
	expenses.resize(3);
	territories.resize(3);
	
	// Turn 0 - Startpoint
	bank[0] = initBank;
	income[0] = initBank;
	bonus[0] = initBonus;
	penalty[0] = 0;
	expenses[0] = 0;
	territories[0] = initTerrs;

	// Turn 1 - First turn
	bank[1] = initBank;
	income[1] = initBank;
	bonus[1] = initBonus;
	penalty[1] = 0;
	expenses[1] = 0;
	territories[1] = initTerrs;

	// Turn 2 - Preview of next bank
	bank[2] = initBank + initBank + initBonus;
	income[2] = NULL_VAL;
	bonus[2] = NULL_VAL;
	penalty[2] = NULL_VAL;
	expenses[2] = NULL_VAL;
	territories[2] = NULL_VAL;

	nationSize = 3;

	atWar = false;
}

Nation::~Nation()
{

}

void Nation::setNationControlsCapital(bool param)
{
	controlsCapital = param;
}

void Nation::setNationSize(int size)
{
	nationSize = size;
	bank.resize(nationSize);
	income.resize(nationSize);
	bonus.resize(nationSize);
	penalty.resize(nationSize);
	expenses.resize(nationSize);
	territories.resize(nationSize);
}

void Nation::incNationSize()
{
	nationSize++;
	bank.resize(nationSize);
	income.resize(nationSize);
	bonus.resize(nationSize);
	penalty.resize(nationSize);
	expenses.resize(nationSize);
	territories.resize(nationSize);

	// Set up next turn's values
	int last = nationSize - 1;
	int next = nationSize - 2;
	int prev = nationSize - 3;
	income[next] = income[prev];
	bonus[next] = bonus[prev];
	penalty[next] = 0;
	expenses[next] = 0;

	// Set up the turn after's bank preview
	bank[last] = bank[next] + income[next] + bonus[next] - penalty[next] - expenses[next];
	income[last] = NULL_VAL;
	bonus[last] = NULL_VAL;
	penalty[last] = NULL_VAL;
	expenses[last] = NULL_VAL;
	territories[last] = NULL_VAL;
}

void Nation::setNationBank(int turn, int val)
{
	if (turn < nationSize)
		bank[turn] = val;
}

void Nation::addNationBank(int turn, int val)
{
	if (turn < nationSize)
	{
		if (bank[turn] + val < 0)
			bank[turn] = 0;
		else
			bank[turn] += val;
	}

	calcNextNationBank(turn);
}

void Nation::calcNextNationBank(int turn)
{
	if (turn < (nationSize - 1))
	{
		int temp = bank[turn] + income[turn] + bonus[turn] - penalty[turn] - expenses[turn];
		bank[++turn] = temp;
	}
}

void Nation::setNationIncome(int turn, int val)
{
	if (turn < nationSize)
		income[turn] = val;
}

void Nation::addNationIncome(int turn, int val)
{
	if (turn < nationSize)
	{
		if (income[turn] + val < 0)
			income[turn] = 0;
		else
			income[turn] += val;
	}

	calcNextNationBank(turn);
}

void Nation::setNationBonus(int turn, int val)
{
	if (turn < nationSize)
		bonus[turn] = val;
}

void Nation::addNationBonus(int turn, int val)
{
	if (turn < nationSize)
	{
		if (bonus[turn] + val < 0)
			bonus[turn] = 0;
		else
			bonus[turn] += val;
	}

	calcNextNationBank(turn);
}

void Nation::setNationPenalty(int turn, int val)
{
	if (turn < nationSize)
		penalty[turn] = val;
}

void Nation::addNationPenalty(int turn, int val)
{
	if (turn < nationSize)
	{
		penalty[turn] += val;
	}

	calcNextNationBank(turn);
}

void Nation::setNationExpenses(int turn, int val)
{
	if (turn < nationSize)
		expenses[turn] = val;
}

void Nation::addNationExpenses(int turn, int val)
{
	if (turn < nationSize)
	{
		if (expenses[turn] + val < 0)
			expenses[turn] = 0;
		else
			expenses[turn] += val;
	}

	calcNextNationBank(turn);
}

void Nation::setNationTerritories(int turn, int val)
{
	if (turn < nationSize)
		territories[turn] = val;
}

void Nation::addNationTerritories(int turn, int val)
{
	if (turn < nationSize)
	{
		if (territories[turn] + val < 0)
			territories[turn] = 0;
		else
			territories[turn] += val;
	}
}

void Nation::goToWar()
{
	atWar = true;
}

void Nation::addPurchases(Purchase& purch)
{
	purchases.addPurchases(purch);
}

void Nation::setPurchases(int idx, int val)
{
	purchases.setPurchases(idx, val);
}

int Nation::getPurchases(int idx)
{
	return purchases.getPurchases(idx);
}

void Nation::setResearch(int idx)
{
	research.setResearch(idx);

	if (idx == RES_SHIPYARDS)
		purchases.setHasResearch(true);
}

void Nation::setResearch(Research &res)
{
	research.setResearch(res);
	if (res.getResearch(RES_SHIPYARDS))
		purchases.setHasResearch(true);
}

void Nation::setFailures(int fails)
{
	research.setFailures(fails);
}

bool Nation::getResearch(int idx)
{
	return research.getResearch(idx);
}

int Nation::getFailures()
{
	return research.getFailures();
}

int Nation::getResearchCount()
{
	return research.getCount();
}

char* Nation::getNationName()
{
	return name;
}

bool Nation::getNationControlsCapital()
{
	return controlsCapital;
}

int Nation::getNationSize()
{
	return nationSize;
}

int Nation::getNationBank(int turn)
{
	if (turn < bank.size())
		return bank[turn];
	else
		return NULL_VAL;
}

int Nation::getNationIncome(int turn)
{
	if (turn < income.size())
		return income[turn];
	else
		return NULL_VAL;
}

int Nation::getNationBonus(int turn)
{
	if (turn < bonus.size())
		return bonus[turn];
	else
		return NULL_VAL;
}

int Nation::getNationPenalty(int turn)
{
	if (turn < penalty.size())
		return penalty[turn];
	else
		return NULL_VAL;
}

int Nation::getNationExpenses(int turn)
{
	if (turn < expenses.size())
		return expenses[turn];
	else
		return NULL_VAL;
}

int Nation::getNationTerritories(int turn)
{
	if (turn < territories.size())
		return territories[turn];
	else
		return NULL_VAL;
}

bool Nation::isAtWar()
{
	return atWar;
}

void Nation::updateBonus(int, int, bool)
{
	// Implemented on case-by-case basis
}

bool Nation::checkBonus(int, bool)
{
	// Implemented on case-by-case basis
	return false;
}

int Nation::checkBonus(int)
{
	// Implemented on case-by-case basis
	return 0;
}
