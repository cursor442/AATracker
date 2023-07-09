#include "../../game/header/AA_Tracker.h"

bool Game::nextTurnPhase(HWND& hWnd)
{
	if (lockPhase)
		return false;

	int type = gameBoard->getGameType();
	int turn = gameBoard->getGameTurn();
	int phase = gameBoard->getGameTurnPhase();
	bool res = gameBoard->getGameResearch();
	int nat = gameBoard->getGameCurrNation();

	// Pre-increment section
	lockPhase = true;
	if (phase == PR_PHASE)
	{
		// Make sure that Global UK player doesn't forget about the Pacific economy
		if (nat == TURN_UKE && type == GLOBAL_GAME && currUKButtonToggled == false
			&& gameBoard->getNationControlsCapital(TURN_UKP) == true)
		{
			int msgboxID = MessageBox(hWnd, L"You haven't made purchases for\nthe Pacific economy!\nContinue?",
				L"Two Economies Reminder", MB_ICONEXCLAMATION | MB_YESNO);

			if (msgboxID == IDNO)
				return false;
		}

		// Record purchases
		gameBoard->addPurchases(purchases);
		// Don't reset the purchases until end of turn to keep reference
	}
	else if (phase == CC_PHASE)
	{
		// All neutral or pro-Allies Mongolian territories join the Soviet Union
		if (nat == TURN_JPN && gameBoard->getJPNAttackedSovietFlag() && !gameBoard->getJPNAttackedSoviet())
		{
			gameBoard->mongoliaJoinsSoviet(hWnd);
			gameBoard->setJPNAttackedSovietFlag(false);
			gameBoard->setJPNAttackedSoviet(false);
			nsSection |= PURCH_SECT;
			nsNeut = NEUT_UPD;
		}
	}
	else if (phase == CI_PHASE)
	{
		// Prepare current nation's next turn
		gameBoard->incNationSize(nat);
		updateSpreadsheet(nat, turn + 1);

		if (type != PACIFIC_GAME && nat == TURN_FRA)
			gameBoard->incVicCityHist();
		else if (type == PACIFIC_GAME && nat == TURN_ANZ)
			gameBoard->incVicCityHist();

		// Reset the purchases for the next player
		resetPurchases();
	}
	lockPhase = false;

	int prevNat = nat;

	gameBoard->incGameTurnPhase();
	turn = gameBoard->getGameTurn();
	phase = gameBoard->getGameTurnPhase();
	nat = gameBoard->getGameCurrNation();

	// Post-increment section
	if ((phase == PR_PHASE && res == false) || phase == RS_PHASE)
	{
		nsSection = NAME_SECT | STAT_SECT | PHASE_SECT | WAR_SECT | CITY_SECT |
			PURCH_SECT | SPREAD_SECT | CHEST_SECT | BONUS_SECT;

		nsPhase = ALL_PHASE;
		currUKButton = false; currUKButtonToggled = false;
		nsUnit = PURCH_TITLE;

		nsTurn = SPREAD_ALL_ROWS;
		nsCol = SPREAD_ALL_COLS;

		warchestRotate = true;
		nsWC = 1 << prevNat;
		nsBonusRow = BONS_ALL;

		captureAmount = 0;

		// No need for popups
		gameBoard->updateBonuses(hWnd, nat, false, 0);
		updateSpreadsheet(nat, turn, BONS_POS);
	}
	else if (phase == PR_PHASE && res == true)
	{
		nsSection = PHASE_SECT | PURCHT_SECT | SPREAD_SECT;
		nsPhase = ALL_PHASE;
		nsTurn = gameBoard->getGameTurn();
		nsCol = XPNS_POS;
	}
	else if (phase == CM_PHASE)
	{
		nsSection = PHASE_SECT;
		nsPhase = ALL_PHASE;
	}
	else if (phase == CC_PHASE)
	{
		captureAmount = 0;
		nsSection = PHASE_SECT;
		nsPhase = ALL_PHASE;
	}
	else if (phase == NC_PHASE)
	{
		// Japan attacks Soviet Union condition
		if (nsNeut == NEUT_UPD)
			nsSection |= PHASE_SECT;
		else
			nsSection = PHASE_SECT;
		nsPhase = ALL_PHASE;
	}
	else if (phase == CI_PHASE)
	{
		lockPhase = true;

		// Now is the time for popups
		gameBoard->updateBonuses(hWnd, nat, true);
		updateSpreadsheet(nat, turn, BONS_POS);
		nsTurn = turn;
		nsCol = BONS_POS;
		nsBonusRow = BONS_UPD;

		lockPhase = false;

		nsTurn = gameBoard->getGameTurn();
		nsSection = PHASE_SECT | SPREAD_SECT | BONUS_SECT;
		nsPhase = ALL_PHASE;
	}
	else
	{
		nsSection = PHASE_SECT;
		nsPhase = ALL_PHASE;
	}

	return true;
}

void Game::researchButtonCost(HWND& hWnd)
{
	int turn = gameBoard->getGameTurn();
	int nat = gameBoard->getGameCurrNation();

	int resCost;
	if (numResDice[0] > 0)
	{
		// Calculate the cost
		resCost = numResDice[0] * RESEARCH_COST;
		gameBoard->addNationExpenses(nat, turn, resCost);
		gameBoard->addNationBank(nat, turn + 1, -1 * resCost);

		// Update the spreadsheet expenses text
		// Will also update the next bank
		updateSpreadsheet(nat, turn, XPNS_POS);
	}

	if (numResDice[1] > 0)
	{
		// Calculate the cost
		resCost = numResDice[1] * RESEARCH_COST;
		gameBoard->addNationExpenses(TURN_UKP, turn, resCost);
		gameBoard->addNationBank(TURN_UKP, turn + 1, -1 * resCost);

		// Update the spreadsheet expenses text
		// Will also update the next bank
		updateSpreadsheet(TURN_UKP, turn, XPNS_POS);
	}

	nextTurnPhase(hWnd);
	RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::purchaseButton(HWND& hWnd, int wmId)
{
	int turn = gameBoard->getGameTurn();
	int nat;
	if (currUKButton)
		nat = TURN_UKP;
	else
		nat = gameBoard->getGameCurrNation();
	int prevXpns = gameBoard->getNationExpenses(nat, turn);

	int delta;

	if (gameBoard->getGameTurnPhase() == PR_PHASE) // Only function during purchase phase
	{
		updatePurchases(wmId);
		if (nat != TURN_CHN) // China has its own rule
		{
			if (calcPrice()) // Can afford this purchase
			{
				// Calculate the delta in expenses
				delta = price - (prevXpns - (numResDice[currUKButton] * RESEARCH_COST));

				// Update expenses and next bank
				gameBoard->addNationExpenses(nat, turn, delta);
				gameBoard->addNationBank(nat, turn + 1, -1 * delta);

				// Update the relevant portions of the purchase and spread sections
				nsSection = PURCH_SECT | SPREAD_SECT;
				nsUnit = (wmId / 2) - (IDB_INFUP / 2) + PURCH_INF;
				nsTurn = turn;
				nsCol = XPNS_POS;

				// Update the spreadsheet expenses text
				// Will also update the next bank
				updateSpreadsheet(nat, turn, XPNS_POS);

				RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
			}
			else
				undoPurchases(wmId);
		}
		else
		{
			bool cond;
			gameBoard->checkBonus(TURN_CHN, 0, cond);
			uint16_t lim = (cond) ? (IDB_ARTDN) : (IDB_INFDN);

			if (calcPrice() && wmId <= lim) // Can afford and it is a legal unit for China
			{
				// Calculate the delta in expenses
				delta = price - (prevXpns - (numResDice[currUKButton] * RESEARCH_COST));

				// Update expenses and next bank
				gameBoard->addNationExpenses(nat, turn, delta);
				gameBoard->addNationBank(nat, turn + 1, -1 * delta);
				
				// Update the relevant portions of the purchase and spread sections
				nsSection = PURCH_SECT | SPREAD_SECT;
				nsUnit = (wmId / 2) - (IDB_INFUP / 2) + PURCH_INF;
				nsTurn = turn;
				nsCol = XPNS_POS;

				// Update the spreadsheet expenses text
				// Will also update the next bank
				updateSpreadsheet(TURN_CHN, turn, XPNS_POS);

				RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
			}
			else
				undoPurchases(wmId);
		}
	}
}

void Game::attackNeutralButtonHandler(HWND& hWnd)
{
	int whichSide = SIDE_NEUTRAL;
	if (gameBoard->attackNeutral(hWnd, whichSide))
	{
		if (whichSide == SIDE_AXIS)
			gameLog->addLogText(gameBoard->getGameTurn(), V_NEUTRAL_AXIS, TURN_NON, TURN_NON);
		else if (whichSide == SIDE_ALLIES)
			gameLog->addLogText(gameBoard->getGameTurn(), V_NEUTRAL_ALLY, TURN_NON, TURN_NON);
	}

	nsSection |= PHASE_SECT | PURCH_SECT;
	nsPhase = BUT_PHASE;
	nsNeut = NEUT_UPD;
	RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::attackMongoliaButtonHandler(HWND& hWnd)
{
	int currLean = SIDE_NEUTRAL;
	if (gameBoard->attackMongolia(hWnd, currLean))
	{
		if (currLean != SIDE_NEUTRAL) // Only Mongolia changes
			gameLog->addLogText(gameBoard->getGameTurn(), V_MONGOLIA, TURN_NON, TURN_NON);
		else // All neutral territories are becoming pro-Axis
		{
			gameLog->addLogText(gameBoard->getGameTurn(), V_NEUTRAL_AXIS, TURN_NON, TURN_NON);
			gameLog->addLogText(gameBoard->getGameTurn(), V_MONGOLIA, TURN_NON, TURN_NON);
		}
	}

	nsSection |= PHASE_SECT | PURCH_SECT;
	nsPhase = BUT_PHASE;
	nsNeut = NEUT_UPD;
	RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::loadMiniSpreads()
{
	//uint16_t idx = gameBoard->getGameType() - 114;
	//uint16_t currTurn = gameBoard->getGameTurn();
	//
	//for (uint16_t i = 0; i < saveNations[idx].size(); i++)
	//{
	//	uint16_t nat = saveNations[idx][i];
	//
	//	uint16_t adj = (isBeforeNation(saveNations[idx][i], gameBoard->getGameCurrNation())) ? (1) : (0);
	//	for (uint16_t turn = 0; turn < currTurn + adj; turn++)
	//	{
	//		if (turn < 3)
	//		{
	//			miniSpreads[nat]->setCellText(turn + 3, BANK_POS, gameBoard->getNationBank(nat, turn + 2));
	//			miniSpreads[nat]->setCellText(turn + 2, INCM_POS, gameBoard->getNationIncome(nat, turn + 1));
	//			miniSpreads[nat]->setCellText(turn + 2, BONS_POS, gameBoard->getNationBonus(nat, turn + 1));
	//			miniSpreads[nat]->setCellText(turn + 2, PNLT_POS, gameBoard->getNationPenalty(nat, turn + 1));
	//			miniSpreads[nat]->setCellText(turn + 2, XPNS_POS, gameBoard->getNationExpenses(nat, turn + 1));
	//		}
	//		else
	//		{
	//			for (uint16_t i = 1; i < 5; i++)
	//				shiftMiniSpread(nat, i);
	//
	//			miniSpreads[nat]->setCellTurn(turn + 3);
	//			miniSpreads[nat]->setCellText(5, BANK_POS, gameBoard->getNationBank(nat, turn + 2));
	//			miniSpreads[nat]->setCellText(4, INCM_POS, gameBoard->getNationIncome(nat, turn + 1));
	//			miniSpreads[nat]->setCellText(4, BONS_POS, gameBoard->getNationBonus(nat, turn + 1));
	//			miniSpreads[nat]->setCellText(4, PNLT_POS, gameBoard->getNationPenalty(nat, turn + 1));
	//			miniSpreads[nat]->setCellText(4, XPNS_POS, gameBoard->getNationExpenses(nat, turn + 1));
	//		}
	//	}
	//}
}

void Game::toggleUKDisp()
{
	currUKButton = !currUKButton;
	currUKButtonToggled = true;
	nsUKToggle = true;

	calcPrice();

	nsTurn = SPREAD_ALL_ROWS;
	nsCol = SPREAD_ALL_COLS;
	nsSection = PURCH_SECT | SPREAD_SECT;
}

