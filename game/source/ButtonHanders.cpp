#include "../header/AA_Tracker.h"
#include "../../nationScreen/header/NationScreenWrappers.h"

void Game::nationScreenHandleNextPhase(HWND hWnd)
{
    nextTurnPhase(hWnd);
    if (gameBoard->getGameTurnPhase() == CI_PHASE &&
        gameBoard->getResearch(gameBoard->getGameCurrNation(), RES_BONDS))
        DialogBox(hInst, MAKEINTRESOURCE(IDD_WARBONDBOX), hWnd, WarBondWrapper);
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::nationScreenHandleDeclareWar(HWND hWnd)
{
    DialogBox(hInst, MAKEINTRESOURCE(IDD_DECLAREWARBOX), hWnd, DeclareWarWrapper);
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}