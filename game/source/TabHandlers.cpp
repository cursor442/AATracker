#include "../header/AA_Tracker.h"

// Nation Screen
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
        whichLogTab = gfx->tabs->getTabState(logScreenTabs);
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

void Game::nationScreenHandlePurchaseSectionTab(HWND& hWnd)
{
    if (purchaseTab != TAB_PURCH)
    {
        purchaseTab = TAB_PURCH;
        nsSection = PURCH_SECT;
        nsNeut = NEUT_ALL;
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleNeutralSectionTab(HWND& hWnd)
{
    if (purchaseTab != TAB_NEUTRAL)
    {
        purchaseTab = TAB_NEUTRAL;
        nsSection = PURCH_SECT;
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleCombinedArmsSectionTab(HWND& hWnd)
{
    if (purchaseTab != TAB_COMB)
    {
        purchaseTab = TAB_COMB;
        nsSection = PURCH_SECT;
        nsNeut = NEUT_ALL;
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
    }
}

void Game::nationScreenHandleUKEconomyEuropeTab(HWND& hWnd)
{
    ukTab = TAB_UKE;
    toggleUKDisp();
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

void Game::nationScreenHandleUKEconomyPacificTab(HWND& hWnd)
{
    ukTab = TAB_UKP;
    toggleUKDisp();
    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
}

// Log Screen
void Game::logScreenHandlePageTab(HWND& hWnd, int page)
{
    whichLogTab = page;
    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
}
