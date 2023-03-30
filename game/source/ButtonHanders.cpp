#include "../header/AA_Tracker.h"
#include "../../nationScreen/header/NationScreenWrappers.h"

void Game::nationScreenHandleNextPhase(HWND& hWnd)
{
    nextTurnPhase(hWnd);
    if (gameBoard->getGameTurnPhase() == CI_PHASE &&
        gameBoard->getResearch(gameBoard->getGameCurrNation(), RES_BONDS))
        DialogBox(hInst, MAKEINTRESOURCE(IDD_WARBONDBOX), hWnd, WarBondWrapper);
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::nationScreenHandleResearch(HWND& hWnd)
{
    if (gameBoard->getGameType() == GLOBAL_GAME && gameBoard->getGameCurrNation() == TURN_UKE)
        DialogBox(hInst, MAKEINTRESOURCE(IDD_UKRESEARCHBOX), hWnd, ResearchUKWrapper);
    else
        DialogBox(hInst, MAKEINTRESOURCE(IDD_RESEARCHBOX), hWnd, ResearchWrapper);

    if (numResDice[0] == 0 && numResDice[1] == 0)
        return;
    else
    {
        for (int i = 0; i < numResDice[0] + numResDice[1]; i++)
        {
            currResDie = i;
            DialogBox(hInst, MAKEINTRESOURCE(IDD_RESEARCHRESBOX), hWnd, ResearchResWrapper);
        }
    }

    researchButtonCost(hWnd);
}

void Game::nationScreenHandleDeclareWar(HWND& hWnd)
{
    DialogBox(hInst, MAKEINTRESOURCE(IDD_DECLAREWARBOX), hWnd, DeclareWarWrapper);
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::nationScreenHandleCaptureTerritory(HWND& hWnd)
{
    if ((gameBoard->getGameType() != GLOBAL_GAME) || (gameBoard->getGameCurrNation() != TURN_UKE))
        DialogBox(hInst, MAKEINTRESOURCE(IDD_CAPTUREBOX), hWnd, CaptureTerritoryWrapper);
    else // UK needs extra EUR/PAC selector in global game
        DialogBox(hInst, MAKEINTRESOURCE(IDD_UKCAPTUREBOX), hWnd, CaptureTerritoryWrapper);
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::nationScreenHandleAttackNeutral(HWND& hWnd)
{
    attackNeutralButtonHandler(hWnd);
}

void Game::nationScreenHandleOccupyNeutral(HWND& hWnd)
{
    DialogBox(hInst, MAKEINTRESOURCE(IDD_OCCUPYNEUTBOX), hWnd, OccupyNeutralWrapper);
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::nationScreenHandleAttackMongolia(HWND& hWnd)
{
    attackMongoliaButtonHandler(hWnd);
}

void Game::nationScreenHandleAttackJapan(HWND& hWnd)
{
    gameBoard->attackJapan(hWnd);
    nsSection |= PHASE_SECT | PURCH_SECT;
    nsPhase = BUT_PHASE;
    nsNeut = NEUT_UPD;
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::nationScreenHandleAttackSoviet(HWND& hWnd)
{
    gameBoard->attackSoviet(hWnd);
    nsSection |= PHASE_SECT | PURCH_SECT;
    nsPhase = BUT_PHASE;
    nsNeut = NEUT_UPD;
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}