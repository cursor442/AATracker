#include "../header/BoardClass.h"

void Board::setNationBank(int n, int turn, int val)
{
	nations[n]->setNationBank(turn, val);
}

void Board::addNationBank(int n, int turn, int val)
{
	nations[n]->addNationBank(turn, val);
}

void Board::calcNextNationBank(uint16_t n, uint16_t turn)
{
	nations[n]->calcNextNationBank(turn);
}

void Board::setNationIncome(int n, int turn, int val)
{
	nations[n]->setNationIncome(turn, val);
}

void Board::setNationBonus(int n, int turn, int val)
{
	nations[n]->setNationBonus(turn, val);
}

void Board::addNationBonus(int n , int turn, int val)
{
	nations[n]->addNationBonus(turn, val);
}

void Board::setNationPenalty(int n, int turn, int val)
{
	nations[n]->setNationPenalty(turn, val);
}

void Board::setNationExpenses(int n, int turn, int val)
{
	nations[n]->setNationExpenses(turn, val);
}

void Board::addNationExpenses(int n, int turn, int val)
{
	nations[n]->addNationExpenses(turn, val);
}

void Board::setNationTerritories(int n, int turn, int val)
{
	nations[n]->setNationTerritories(turn, val);
}

void Board::addNationTerritories(int n, int turn, int val)
{
	nations[n]->addNationTerritories(turn, val);
}


int Board::getNationBank(int n, int turn)
{
	return nations[n]->getNationBank(turn);
}

int Board::getNationIncome(int n, int turn)
{
	return nations[n]->getNationIncome(turn);
}

int Board::getNationBonus(int n, int turn)
{
	return nations[n]->getNationBonus(turn);
}

int Board::getNationPenalty(int n, int turn)
{
	return nations[n]->getNationPenalty(turn);
}

int Board::getNationExpenses(int n, int turn)
{
	return nations[n]->getNationExpenses(turn);
}

int Board::getNationTerritories(int n, int turn)
{
	return nations[n]->getNationTerritories(turn);
}

void Board::addPurchases(Purchase purchases[2])
{
	if (!(gameCurrNation == TURN_UKP && gameType == PACIFIC_GAME))
		nations[gameCurrNation]->addPurchases(purchases[0]);

	if (gameCurrNation == TURN_UKE && gameType == GLOBAL_GAME)
		nations[gameCurrNation + 1]->addPurchases(purchases[1]);
}

void Board::setPurchases(uint16_t nat, uint16_t idx, uint16_t val)
{
	nations[nat]->setPurchases(idx, val);
}

uint16_t Board::getPurchases(uint16_t nat, uint16_t idx)
{
	return nations[nat]->getPurchases(idx);
}