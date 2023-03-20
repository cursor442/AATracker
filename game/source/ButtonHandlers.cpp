#include "../header/AA_Tracker.h"

void Game::handleButtonLeftDown(HWND& hWnd, LPARAM lParam)
{
    gfx->buttons->checkForButton(hWnd, lParam, buttonClick, newButtonClick);

    if (buttonClick && gfx->buttons->pressButton())
    {
        buttonClicked = true;
        newButtonUnclicked = false;

        nsSection |= PHASE_SECT;
        nsPhase = PR_PHASE;
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
    }
}

void Game::handleButtonLeftUp(HWND& hWnd, LPARAM lParam)
{
    gfx->buttons->checkForButton(hWnd, lParam, buttonClick, newButtonClick);

    if (buttonClick && !newButtonClick && gfx->buttons->releaseButton())
    {
        buttonClicked = false;
        newButtonUnclicked = false;

        nsSection |= PHASE_SECT;
        nsPhase = PR_PHASE;
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
    }
}
