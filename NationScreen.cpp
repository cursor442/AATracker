// Draw the nation screen of the application

#include "AA_Tracker.h"

bool Game::NationScreen(HDC& hdc, PAINTSTRUCT& ps)
{
    hideScreen();

    if (nsSection == NO_SECT)
    {
        // Do nothing
    }
    else if (nsSection == ALL_SECT) // Only run once per nation if at all
    {
            // Name frame section
        drawNameFrame(hdc);

            // Status frame section
        drawStatusFrame(hdc);

            // Turn phase indicators
        drawPhaseFrame(hdc);

            // War with frame section
        drawWarFrame(hdc);

            // Cities frame section
        drawCitiesFrame(hdc);

            // Purchases section
        {
            if (purchaseTab == TAB_PURCH)
            {
                drawPurchaseFrame(hdc);
            }
            else if (purchaseTab == TAB_COMB)
            {
                hideNationScreenPurchButtons();
                drawCombinedArms(hdc);
            }
            else if (purchaseTab == TAB_NEUTRAL)
            {
                hideNationScreenPurchButtons();
                drawNeutralBox(hdc);
            }
        }

            // Mini spreadsheet section
        drawMiniSpread(hdc);

        if (gameBoard->getGameCurrNation() == TURN_UKE && gameBoard->getGameType() == GLOBAL_GAME)
            drawUKEconTabs(true);
        else
            drawUKEconTabs(false);

            // Warchest section
        drawWarchestFrame(hdc);

            // Bonus section
        drawBonusFrame(hdc);

        ShowWindow(nationScreenTabs, SW_SHOW);
        ShowWindow(purchaseSectionTabs, SW_SHOW);
    }
    else
    {
        if ((nsSection & NAME_SECT) != 0)
            drawNameFrame(hdc);

        if ((nsSection & STAT_SECT) != 0)
            drawStatusFrame(hdc);

        if ((nsSection & PHASE_SECT) != 0)
            drawPhaseFrame(hdc);

        if ((nsSection & WAR_SECT) != 0)
            drawWarFrame(hdc);

        if ((nsSection & CITY_SECT) != 0)
            drawCitiesFrame(hdc);

        if ((nsSection & CITY1_SECT) != 0)
            drawCitiesFrame(hdc, nsCity);

        if ((nsSection & PURCH_SECT) != 0)
        {
            if (purchaseTab == TAB_PURCH)
            {
                drawPurchaseFrame(hdc);
            }
            else if (purchaseTab == TAB_COMB)
            {
                hideNationScreenPurchButtons();
                drawCombinedArms(hdc);
            }
            else if (purchaseTab == TAB_NEUTRAL)
            {
                hideNationScreenPurchButtons();
                drawNeutralBox(hdc);
            }
        }

        if ((nsSection & PURCHT_SECT) != 0)
            drawPurchaseCostUpdate(hdc);

        if ((nsSection & SPREAD_SECT) != 0)
        {
            drawMiniSpread(hdc);

            if (gameBoard->getGameCurrNation() == TURN_UKE && gameBoard->getGameType() == GLOBAL_GAME)
                drawUKEconTabs(true);
            else
                drawUKEconTabs(false);
        }

        if ((nsSection & CHEST_SECT) != 0)
            drawWarchestFrame(hdc);

        if ((nsSection & BONUS_SECT) != 0)
            drawBonusFrame(hdc);
    }

    return true;
}

void Game::hideNationScreen()
{
    ShowWindow(nextPhaseButton, SW_HIDE);
    ShowWindow(researchButton, SW_HIDE);
    ShowWindow(declareWarButton, SW_HIDE);
    ShowWindow(captureTerritoryButton, SW_HIDE);

    hideNationScreenPurchButtons();

    ShowWindow(purchaseSectionTabs, SW_HIDE);
    ShowWindow(ukEconomyTabs, SW_HIDE);
}

void Game::hideNationScreenPurchButtons()
{
    purchaseSection->hidePurchaseButtons();
}