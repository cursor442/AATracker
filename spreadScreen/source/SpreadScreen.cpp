#include "../../game/header/AA_Tracker.h"

void Game::configSpreadScreen()
{
	int idx = gameBoard->getGameType();
	if (idx < 3 && idx != NULL_GAME)
	{
		for (int i = 0; i < saveNations[idx].size(); i++)
		{
			int nat = saveNations[idx][i];
		}
	}
}

bool Game::SpreadScreen(HWND& hWnd, HDC& hdc, PAINTSTRUCT& ps, bool side)
{
	hideScreen();

	if (side == SIDE_AXIS)
	{
		if (spreadAxis == NULL)
		{
			/*spreadAxis = CreateWindowExA(
				WS_EX_TRANSPARENT,//WS_EX_STATICEDGE,
				"Edit", "",
				WS_CHILD | WS_VSCROLL | WS_VISIBLE,
				nationScreenWindow.left, 22,
				(nationScreenWindow.right - nationScreenWindow.left),
				(nationScreenWindow.bottom - nationScreenWindow.top) - 22,
				main_Wnd,
				NULL,
				hInst,
				NULL
			);*/

			spreadAxis = CreateWindowExA(
				WS_EX_PALETTEWINDOW
				,//WS_EX_TRANSPARENT,//WS_EX_STATICEDGE,
				"SCROLLBAR", (PSTR)NULL,
				SBS_VERT | WS_CHILD | WS_VISIBLE,
				nationScreenWindow.right - 25, nationScreenWindow.top,
				25, (nationScreenWindow.bottom - nationScreenWindow.top),
				main_Wnd,
				NULL,
				hInst,
				NULL
			);
		}
		else
			ShowWindow(spreadAxis, SW_SHOW);

		RECT temp[50];

		temp[0].top = 22; temp[0].bottom = 47;
		temp[0].left  = nationScreenWindow.left;
		temp[0].right = nationScreenWindow.right;

		for (uint16_t i = 1; i < 50; i++)
		{
			temp[i] = temp[i - 1];
			temp[i].top = temp[i - 1].bottom;
			temp[i].bottom += 25;
		}

		hBrushP = usaBrushP;
		hBrushS = usaBrushS;

		resetBrush(hdc);
		for (uint16_t i = 0; i < 50; i++)
		{
			Rectangle(hdc, temp[i].left, temp[i].top, temp[i].right, temp[i].bottom);
			swapBrush(hdc);
		}
	}
	else
	{

	}




	return true;
}

void Game::initSpreadsheets()
{
	int gameType = gameBoard->getGameType();

	int bank, incm, bons, pnlt, xpns;

	for (int i = 0; i < saveNations[gameType].size(); i++)
	{
		int nat = saveNations[gameType][i];
		if (nationSpreads[nat] == NULL)
		{
			nationSpreads[nat] = new Spreadsheet(3);

			bank = gameBoard->getNationBank(nat, 0);
			incm = gameBoard->getNationIncome(nat, 0);
			bons = gameBoard->getNationBonus(nat, 0);
			pnlt = 0;
			xpns = 0;
			nationSpreads[nat]->setSpreadText(0, bank, incm, bons, xpns, pnlt);

			bank = gameBoard->getNationBank(nat, 1);
			incm = gameBoard->getNationIncome(nat, 1);
			bons = gameBoard->getNationBonus(nat, 1);
			pnlt = 0;
			xpns = 0;
			nationSpreads[nat]->setSpreadText(1, bank, incm, bons, xpns, pnlt);

			bank = gameBoard->getNationBank(nat, 2);
			incm = NULL_VAL;
			bons = NULL_VAL;
			pnlt = NULL_VAL;
			xpns = NULL_VAL;
			nationSpreads[nat]->setSpreadText(2, bank, incm, bons, xpns, pnlt);
		}
	}
}

void Game::loadSpreadsheets()
{

}

void Game::updateSpreadsheet(int nat, int turn)
{
	// Update for next turn
	int bank, incm, bons, pnlt, xpns;
	bank = gameBoard->getNationBank(nat, turn);
	incm = gameBoard->getNationIncome(nat, turn);
	bons = gameBoard->getNationBonus(nat, turn);
	pnlt = gameBoard->getNationPenalty(nat, turn);
	xpns = gameBoard->getNationExpenses(nat, turn);
	nationSpreads[nat]->setSpreadText(turn, bank, incm, bons, xpns, pnlt);

	int gameType = gameBoard->getGameType();
	if (gameType == GLOBAL_GAME && nat == TURN_UKE)
	{
		nat++;
		bank = gameBoard->getNationBank(nat, turn);
		incm = gameBoard->getNationIncome(nat, turn);
		bons = gameBoard->getNationBonus(nat, turn);
		pnlt = gameBoard->getNationPenalty(nat, turn);
		xpns = gameBoard->getNationExpenses(nat, turn);
		nationSpreads[nat]->setSpreadText(turn, bank, incm, bons, xpns, pnlt);
		nat--;
	}

	// Preview bank for turn after
	turn++;
	bank = gameBoard->getNationBank(nat, turn);
	incm = gameBoard->getNationIncome(nat, turn);
	bons = gameBoard->getNationBonus(nat, turn);
	pnlt = gameBoard->getNationPenalty(nat, turn);
	xpns = gameBoard->getNationExpenses(nat, turn);
	nationSpreads[nat]->setSpreadText(turn, bank, incm, bons, xpns, pnlt);

	if (gameType == GLOBAL_GAME && nat == TURN_UKE)
	{
		nat++;
		bank = gameBoard->getNationBank(nat, turn);
		incm = gameBoard->getNationIncome(nat, turn);
		bons = gameBoard->getNationBonus(nat, turn);
		pnlt = gameBoard->getNationPenalty(nat, turn);
		xpns = gameBoard->getNationExpenses(nat, turn);
		nationSpreads[nat]->setSpreadText(turn, bank, incm, bons, xpns, pnlt);
	}
}

void Game::updateSpreadsheet(int nat, int turn, bool midTurn)
{
	// Update for this turn
	int bank, incm, bons, pnlt, xpns;
	bank = gameBoard->getNationBank(nat, turn);
	incm = gameBoard->getNationIncome(nat, turn);
	bons = gameBoard->getNationBonus(nat, turn);
	pnlt = gameBoard->getNationPenalty(nat, turn);
	xpns = gameBoard->getNationExpenses(nat, turn);
	nationSpreads[nat]->setSpreadText(turn, bank, incm, bons, xpns, pnlt);

	// Preview bank for turn after
	turn++;
	bank = gameBoard->getNationBank(nat, turn);
	incm = gameBoard->getNationIncome(nat, turn);
	bons = gameBoard->getNationBonus(nat, turn);
	pnlt = gameBoard->getNationPenalty(nat, turn);
	xpns = gameBoard->getNationExpenses(nat, turn);
	nationSpreads[nat]->setSpreadText(turn, bank, incm, bons, xpns, pnlt);
}

void Game::updateSpreadsheet(int nat, int turn, int col)
{
	// Update a single element
	int val, bank;
	int nextTurn = turn + 1;
	switch (col)
	{
	case BANK_POS:
	{
		val = gameBoard->getNationBank(nat, turn);
		break;
	}
	case INCM_POS: 
	{
		val = gameBoard->getNationIncome(nat, turn);
		break;
	}
	case BONS_POS: 
	{
		val = gameBoard->getNationBonus(nat, turn);
		break;
	}
	case PNLT_POS: 
	{
		val = gameBoard->getNationPenalty(nat, turn);
		break;
	}
	case XPNS_POS: 
	{
		val = gameBoard->getNationExpenses(nat, turn);
		break;
	}
	default:
	{
		val = gameBoard->getNationBank(nat, turn);
		break;
	}
	}

	// Also update next bank, because that will always be affected
	bank = gameBoard->getNationBank(nat, nextTurn);

	nationSpreads[nat]->setSpreadText(turn, col, val);
	nationSpreads[nat]->setSpreadText(nextTurn, BANK_POS, bank);
}

void Game::hideSpreadScreen()
{
	ShowWindow(spreadAxis, SW_HIDE);
	ShowWindow(spreadAllies, SW_HIDE);
}

void Game::destroySpreadScreen()
{
	for (int i = 0; i < 10; i++)
		if (nationSpreads[i] != NULL)
		{
			delete nationSpreads[i];
			nationSpreads[i] = NULL;
		}
}