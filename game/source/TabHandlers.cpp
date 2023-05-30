#include "../header/AA_Tracker.h"

void Game::nationScreenHandleMainScreenTab(HWND& hWnd)
{
    if (whichScreen != NATION_SCREEN)
    {
        whichScreen = NATION_SCREEN;
        nsSection = ALL_SECT;
        nsPhase = ALL_PHASE;
        nsNeut = NEUT_ALL;
        RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleAxisSpreadScreenTab(HWND& hWnd)
{
    if (whichScreen != SPREAD0_SCREEN)
    {
        whichScreen = SPREAD0_SCREEN;
        RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleAlliesSpreadScreenTab(HWND& hWnd)
{
    if (whichScreen != SPREAD1_SCREEN)
    {
        whichScreen = SPREAD1_SCREEN;
        RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleGraphScreenTab(HWND& hWnd)
{
    if (whichScreen != GRAPH_SCREEN)
    {
        whichScreen = GRAPH_SCREEN;
        RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleLogScreenTab(HWND& hWnd)
{
    if (whichScreen != LOG_SCREEN)
    {
        whichScreen = LOG_SCREEN;
        whichTab = TabCtrl_GetCurSel(logScreenTabs);
        RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleResearchScreenTab(HWND& hWnd)
{
    if (whichScreen != RES_SCREEN)
    {
        whichScreen = RES_SCREEN;
        RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleReferenceScreenTab(HWND& hWnd)
{
    if (whichScreen != REF_SCREEN)
    {
        whichScreen = REF_SCREEN;
        RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
    }
}
