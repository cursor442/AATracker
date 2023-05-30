#include "../header/AA_Tracker.h"

void Game::handleMouseLeftDown(HWND& hWnd, LPARAM lParam)
{
    currButton = gfx->buttons->checkForButton(hWnd, lParam, buttonClick, newButtonClick);

    if (buttonClick && gfx->buttons->pressButton(currButton))
    {
        buttonClicked = true;
        newButtonUnclicked = false;

        handleMouseGraphicsSwitches(currButton);
        RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
        return;
    }

    currTab = gfx->tabs->checkForTab(hWnd, lParam, tabClick, currTabIdx);

    if (tabClick && gfx->tabs->pressTab(hWnd, currTab, currTabIdx))
    {

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

        handleMouseGraphicsSwitches(currButton);
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

            handleMouseGraphicsSwitches(currButton);
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
        }
        else if (buttonClick && !newButtonClicked && newButtonUnclicked)
        {
            newButtonUnclicked = false;

            gfx->buttons->pressButton(currButton);

            handleMouseGraphicsSwitches(currButton);
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
        }
    }
}

void Game::handleMouseGraphicsSwitches(int button)
{
    int bbScreen = gfx->buttons->getButtonScreen(button);
    int bbSection = gfx->buttons->getButtonSection(button);

    if (whichScreen == bbScreen)
    {
        switch (whichScreen)
        {
        case NATION_SCREEN:
        {
            nsSection |= bbSection;
            if (nsPhase == NON_PHASE)
                nsPhase = BUT_PHASE;

            if (bbSection == PURCH_SECT)
                nsUnit = gfx->buttons->getButtonValInt(button);
            break;
        }
        default:
            break;
        }
    }
}
