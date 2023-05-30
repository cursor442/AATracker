#include "../../game/header/AA_Tracker.h"

void Game::drawTooltip(HWND& hWnd, LPARAM lParam)
{
	if (activeTooltip)
		gfx->tooltips->drawTooltip(hWnd, lParam, graphics, dbg_boundbox, dbg_sections, dbg_layers);
}

void Game::hideTooltip(HWND& hWnd, LPARAM lParam)
{
    if (deactivateTooltip)
    {
        deactivateTooltip = false;

        int section;
        gfx->tooltips->hideTooltip(hWnd, lParam, graphics, section);

        switch (whichScreen)
        {
        case MAIN_SCREEN:
            
            break;
        case NATION_SCREEN:
            nsSection |= section;
            if (nsSection & PHASE_SECT)
                nsPhase = ALL_PHASE;
            break;
        case SPREAD0_SCREEN:
            
            break;
        case SPREAD1_SCREEN:
            
            break;
        case GRAPH_SCREEN:
            
            break;
        case LOG_SCREEN:
            
            break;
        case RES_SCREEN:
            
            break;
        case REF_SCREEN:

            break;
        default:
            break;
        }
    }
}

void Game::showTabBar(int tab)
{
    gfx->tabs->activateTab(tab);
    gfx->tabs->drawTab(tab, graphics, dbg_boundbox, dbg_sections, dbg_layers);
}

void Game::hideTabBar(int tab)
{
    gfx->tabs->hideTab(tab, graphics);
    gfx->tabs->deactivateTab(tab);
}

void Game::showButton(HWND& button)
{
    ShowWindow(button, SW_SHOW);
    gfx->tooltips->activateTooltip((int)button);
}

void Game::showButton(int button, bool tt)
{
    gfx->buttons->activateButton(button);
    gfx->buttons->drawButton(button, graphics, dbg_boundbox, dbg_sections, dbg_layers);

    if (tt)
        gfx->tooltips->activateTooltip(button);
}

void Game::hideButton(HWND& button)
{
    ShowWindow(button, SW_HIDE);
    gfx->tooltips->deactivateTooltip((int)button);
}

void Game::hideButton(int button, bool tt)
{
    gfx->buttons->hideButton(button, graphics);
    gfx->buttons->deactivateButton(button);

    if (tt)
        gfx->tooltips->deactivateTooltip(button);
}