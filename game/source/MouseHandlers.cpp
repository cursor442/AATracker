#include "../header/AA_Tracker.h"

void Game::handleMouseLeftDown(HWND& hWnd, LPARAM lParam)
{
    currButton = gfx->buttons->checkForButton(hWnd, lParam, buttonClick, newButtonClick);

    if (buttonClick && gfx->buttons->pressButton(currButton))
    {
        buttonClicked = true;
        newButtonUnclicked = false;

        nsSection |= PHASE_SECT;
        if (nsPhase == NON_PHASE)
            nsPhase = BUT_PHASE;
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
    }
}

void Game::handleMouseLeftUp(HWND& hWnd, LPARAM lParam)
{
    gfx->buttons->checkForButton(hWnd, lParam, buttonClick, newButtonClick, currButton);

    if (buttonClick && !newButtonClick && gfx->buttons->releaseButton(currButton))
    {
        buttonClicked = false;
        newButtonUnclicked = false;

        gfx->buttons->executeButton(hWnd);

        nsSection |= PHASE_SECT;
        if (nsPhase == NON_PHASE)
            nsPhase = BUT_PHASE;
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
    }
    else if (buttonClicked)
    {
        buttonClicked = false;
    }
}

void Game::handleMouseMove(HWND& hWnd, LPARAM lParam)
{
    // Track if a button is clicked and held
    if (buttonClicked)
    {
        gfx->buttons->checkForButton(hWnd, lParam, buttonClick, newButtonClicked, currButton, false);

        if (newButtonClicked && !newButtonUnclicked)
        {
            newButtonUnclicked = true; 

            gfx->buttons->releaseButton(currButton);

            nsSection |= PHASE_SECT;
            if (nsPhase == NON_PHASE)
                nsPhase = BUT_PHASE;
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
        }
        else if (buttonClick && !newButtonClicked && newButtonUnclicked)
        {
            newButtonUnclicked = false;

            gfx->buttons->pressButton(currButton);

            nsSection |= PHASE_SECT;
            if (nsPhase == NON_PHASE)
                nsPhase = BUT_PHASE;
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
        }
    }
}
