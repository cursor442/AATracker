
#include "AA_Tracker.h"

void Game::resetPurchases()
{
	purchases[0].reset();
	purchases[1].reset();
	price = 0;
}

void Game::updatePurchases(uint16_t val)
{
	if (!currUKButton)
		purchases[0].updateVal(val);
	else
		purchases[1].updateVal(val);
}

void Game::undoPurchases(uint16_t val)
{
	uint16_t currNat = gameBoard->getGameCurrNation();

	if (gameBoard->getResearch(currNat, RES_SHIPYARDS))
	{
		purchases[0].setHasResearch(true);
		purchases[1].setHasResearch(true);
	}
	else
	{
		purchases[0].setHasResearch(false);
		purchases[1].setHasResearch(false);
	}

	if (!currUKButton)
	{
		purchases[0].undoVal(val);

		purchases[0].calcPrice(price, 0, 0);
	}
	else
	{
		purchases[1].undoVal(val);

		purchases[1].calcPrice(price, 0, 0);
	}
}

bool Game::calcPrice()
{
	int currNat = gameBoard->getGameCurrNation();

	if (gameBoard->getResearch(currNat, RES_SHIPYARDS))
	{
		purchases[0].setHasResearch(true);
		purchases[1].setHasResearch(true);
	}
	else
	{
		purchases[0].setHasResearch(false);
		purchases[1].setHasResearch(false);
	}

	if (!currUKButton)
		return purchases[0].calcPrice(price, gameBoard->getNationBank(currNat,
			gameBoard->getGameTurn()), numResDice[0] * RESEARCH_COST);
	else
		return purchases[1].calcPrice(price, gameBoard->getNationBank(currNat + 1,
			gameBoard->getGameTurn()), numResDice[1] * RESEARCH_COST);
}
