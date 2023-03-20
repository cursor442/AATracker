#include "../header/AA_Tracker.h"

void Game::handleMouseLeftDown(HWND& hWnd, LPARAM lParam)
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

void Game::handleMouseLeftUp(HWND& hWnd, LPARAM lParam)
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

void Game::handleMouseMove(HWND& hWnd, LPARAM lParam)
{
    // Track if a button is clicked and held
    if (buttonClicked)
    {
        gfx->buttons->checkForButton(hWnd, lParam, buttonClick, newButtonClicked, false);

        if (newButtonClicked && !newButtonUnclicked)
        {
            newButtonUnclicked = true;

            gfx->buttons->releaseButton();

            nsSection |= PHASE_SECT;
            nsPhase = PR_PHASE;
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
        }
        else if (buttonClick && !newButtonClicked && newButtonUnclicked)
        {
            newButtonUnclicked = false;

            gfx->buttons->pressButton();

            nsSection |= PHASE_SECT;
            nsPhase = PR_PHASE;
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
        }
    }
}
