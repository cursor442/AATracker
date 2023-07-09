#include "../../game/header/AA_Tracker.h"

bool Game::NationScreen(HDC& hdc, PAINTSTRUCT& ps)
{
    hideScreen();

    if (nsSection == NO_SECT)
    {
        // Do nothing
    }
    else if (nsSection == ALL_SECT) // Only run once per nation if at all
    {
            // Turn phase indicators
        drawPhaseFrame(hdc);
        drawPhaseFrameButtons(hdc, true);
        
            // Name frame section
        drawNameFrame(hdc);

            // Status frame section
        drawStatusFrame(hdc);

            // War with frame section
        drawWarFrame(hdc);

            // Cities frame section
        drawCitiesFrame(hdc);

            // Purchases section
        {
            if (purchaseTab == TAB_PURCH)
            {
                drawPurchaseFrame(hdc);
                drawPurchaseFrameButtons(true);
            }
            else if (purchaseTab == TAB_NEUTRAL)
            {
                //hidePurchaseFrameButtons();
                drawNeutralBox(hdc);
            }
            else if (purchaseTab == TAB_COMB)
            {
                //hidePurchaseFrameButtons();
                drawCombinedArms(hdc);
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

        showTabBar(nationScreenTabs);
        showTabBar(purchaseSectionTabs);
    }
    else
    {
        if ((nsSection & PHASE_SECT) != 0)
        {
            drawPhaseFrame(hdc);
            drawPhaseFrameButtons(hdc);
        }
        
        if ((nsSection & NAME_SECT) != 0)
            drawNameFrame(hdc);

        if ((nsSection & STAT_SECT) != 0)
            drawStatusFrame(hdc);

        if ((nsSection & WAR_SECT) != 0)
            drawWarFrame(hdc);

        if ((nsSection & CITY_SECT) != 0)
            drawCitiesFrame(hdc);

        if ((nsSection & PURCH_SECT) != 0)
        {
            if (purchaseTab == TAB_PURCH)
            {
                drawPurchaseFrame(hdc);
                drawPurchaseFrameButtons();
            }
            else if (purchaseTab == TAB_NEUTRAL)
            {
                hidePurchaseFrameButtons();
                drawNeutralBox(hdc);
            }
            else if (purchaseTab == TAB_COMB)
            {
                hidePurchaseFrameButtons();
                drawCombinedArms(hdc);
            }
            showTabBar(purchaseSectionTabs);
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
    hideNameFrame();
    hideStatusFrame();
    hidePhaseFrame();
    hidePhaseFrameButtons();
    hideWarFrame();
    hideCitiesFrame();

    if (purchaseTab == TAB_PURCH)
    {
        hidePurchaseFrame();
        hidePurchaseFrameButtons();
    }
    else if (purchaseTab == TAB_NEUTRAL)
        hideNeutralBox();
    else if (purchaseTab == TAB_COMB)
        hideCombinedArms();
    hideTabBar(purchaseSectionTabs);
    
    hideMiniSpread();
    hideTabBar(ukEconomyTabs);
    hideWarchestFrame();
    hideBonusFrame();
}
