
#include "AA_Tracker.h"

void Game::drawNameFrame(HDC& hdc)
{
    nameSection->updateNameText(gameBoard->getGameCurrNation(), gameBoard->getGameType(), gameBoard->getGameTurn());
    nameSection->drawNameBox(graphics, dbg_boundbox, dbg_sections, dbg_layers);
}

void Game::drawPhaseFrame(HDC& hdc)
{
    int currPhase = gameBoard->getGameTurnPhase();
    int currNat = gameBoard->getGameCurrNation();

    phaseSection->drawPhaseBox(graphics, currPhase, gameBoard->getGameResearch(), dbg_boundbox, dbg_sections, dbg_layers);

    // Action buttons section
    REAL phaseFrameLeft = phaseSection->getBoxEdge(-1, BOX_LEFT);
    REAL purchBoxTop = phaseSection->getBoxEdge(PR_PHASE, BOX_TOP);
    REAL purchBoxHeight = phaseSection->getBoxEdge(PR_PHASE, BOX_HEIGHT);
    REAL cmBoxTop = phaseSection->getBoxEdge(CM_PHASE, BOX_TOP);
    REAL cmBoxHeight = phaseSection->getBoxEdge(CM_PHASE, BOX_HEIGHT);

    SetWindowPos(nextPhaseButton, HWND_TOP,
        phaseFrameLeft - 132, purchBoxTop, 120,
        purchBoxHeight, SWP_SHOWWINDOW | SWP_NOZORDER);

    switch (currPhase)
    {
    case RS_PHASE:
    {
        ShowWindow(declareWarButton, SW_HIDE);
        ShowWindow(captureTerritoryButton, SW_HIDE);

        if (gameBoard->getCount(currNat) != 12)
            SetWindowPos(researchButton, HWND_TOP,
                phaseFrameLeft - 132, cmBoxTop, 120,
                cmBoxHeight, SWP_SHOWWINDOW | SWP_NOZORDER);
        else
            ShowWindow(researchButton, SW_HIDE);
    }
        break;
    case PR_PHASE:
    {
        ShowWindow(researchButton, SW_HIDE);
        ShowWindow(declareWarButton, SW_HIDE);
    }
        break;
    case CM_PHASE:
    {
        ShowWindow(researchButton, SW_HIDE);
        ShowWindow(captureTerritoryButton, SW_HIDE);

        SetWindowPos(declareWarButton, HWND_TOP,
            phaseFrameLeft - 132, cmBoxTop, 120,
            cmBoxHeight, SWP_SHOWWINDOW | SWP_NOZORDER);
    }
        break;
    case CC_PHASE:
    {
        ShowWindow(declareWarButton, SW_HIDE);

        SetWindowPos(captureTerritoryButton, HWND_TOP,
            phaseFrameLeft - 132, cmBoxTop, 120,
            cmBoxHeight, SWP_SHOWWINDOW | SWP_NOZORDER);
    }
        break;
    case NC_PHASE:
    {
        ShowWindow(captureTerritoryButton, SW_HIDE);
        break;
    }
    case CI_PHASE:
        if (gameBoard->getGameCurrNation() == TURN_USA && gameBoard->getGameTurn() == 2)
        {
            ShowWindow(researchButton, SW_HIDE);
            ShowWindow(captureTerritoryButton, SW_HIDE);

            SetWindowPos(declareWarButton, HWND_TOP,
                phaseFrameLeft - 132, cmBoxTop, 120,
                cmBoxHeight, SWP_SHOWWINDOW | SWP_NOZORDER);
        }
        break;
    default: break;
    }
}

void Game::drawWarFrame(HDC& hdc)
{
    int currNat = gameBoard->getGameCurrNation();
    int gameType = gameBoard->getGameType();
    
    warSection->updateFormat(currNat, gameType, gameBoard->getWarMatrix());
    warSection->drawWarBox(graphics, dbg_boundbox, dbg_sections, dbg_layers);
}

void Game::drawCitiesFrame(HDC& hdc)
{
    int currNat = gameBoard->getGameCurrNation();
    int currSide = gameBoard->whichSide(currNat);
    int gameType = gameBoard->getGameType();

    int min = CITY_BERLIN;
    if (gameType == PACIFIC_GAME)
        min = CITY_SHANG;
    int max = CITY_SANFRAN;
    if (gameType == EUROPE_GAME)
        max = CITY_STALIN;
    
    for (int city = min; city <= max; city++)
    {
        bool thisSide;
        int own = getCityOwn(city, thisSide);
        citiesSection->updateFormat(city, own, thisSide);
    }

    citiesSection->drawCityBox(graphics, gameType, dbg_boundbox, dbg_sections, dbg_layers);
}

// Single city
void Game::drawCitiesFrame(HDC& hdc, uint16_t city)
{
    hFont = (HFONT)SelectObject(hdc, headerFont);

    switch (city)
    {
    case CITY_BERLIN:

        break;

    default:
        break;
    }
}

void Game::drawStatusFrame(HDC& hdc)
{
    int gameType = gameBoard->getGameType();
    int axisCap = gameBoard->getNumCapCities(SIDE_AXIS);
    int axisEur = 0;
    int axisPac = 0;
    if (gameType == GLOBAL_GAME)
    {
        axisEur = gameBoard->getNumVicCities(VIC_AXIS_EUR);
        axisPac = gameBoard->getNumVicCities(VIC_AXIS_PAC);
    }
    int allyCap = gameBoard->getNumCapCities(SIDE_ALLIES);

    statusSection->updateStatusText(axisCap, axisEur, axisPac, allyCap, gameType);
    statusSection->drawStatusBox(graphics, gameType, dbg_boundbox, dbg_sections, dbg_layers);
}

void Game::drawPurchaseFrame(HDC& hdc)
{
    int currNat = gameBoard->getGameCurrNation();
    bool resShips = gameBoard->getResearch(currNat, RES_SHIPYARDS);

    if (resShips)
    {
        purchases[0].setHasResearch(true);
        purchases[1].setHasResearch(true);
    }
    else
    {
        purchases[0].setHasResearch(false);
        purchases[1].setHasResearch(false);
    }

    if (nsUKToggle)
    {
        purchaseSection->updatePurchaseText(purchases, currUKButton);
        purchaseSection->drawPurchaseBox(graphics, PURCH_ALL, dbg_boundbox, dbg_sections, dbg_layers);
        nsUKToggle = false;
    }
    else if (nsUnit == PURCH_ALL)
    {
        purchaseSection->updatePurchaseText(purchases, currUKButton);
        purchaseSection->drawPurchaseBox(graphics, PURCH_ALL, dbg_boundbox, dbg_sections, dbg_layers);
        nsUnit = PURCH_TITLE;
    }
    else if (nsUnit == PURCH_TITLE)
    {
        purchaseSection->updatePurchaseText(resShips);
        purchaseSection->drawPurchaseBox(graphics, dbg_boundbox, dbg_sections, dbg_layers);
        ShowWindow(purchaseSectionTabs, SW_SHOW);
    }
    else
    {
        purchaseSection->updatePurchaseText(purchases, nsUnit);
        purchaseSection->drawPurchaseBox(graphics, nsUnit, dbg_boundbox, dbg_sections, dbg_layers);
        nsUnit = PURCH_TITLE;
    }
}

void Game::drawPurchaseCostUpdate(HDC& hdc)
{
    purchaseSection->updatePurchaseText(true);
    purchaseSection->drawPurchaseBox(graphics, true, dbg_boundbox, dbg_sections, dbg_layers);
}

void Game::drawCombinedArms(HDC& hdc)
{
    //hFont = (HFONT)SelectObject(hdc, normalFont);
    //hBrush = (HBRUSH)SelectObject(hdc, tileBrush);

    //Rectangle(hdc, purchaseFrame.left, purchaseFrame.top, purchaseFrame.right, purchaseFrame.bottom);

}

void Game::drawNeutralBox(HDC& hdc)
{
    neutralSection->drawNeutralBox(graphics, dbg_boundbox, dbg_sections, dbg_layers);
}

void Game::drawMiniSpread(HDC& hdc)
{
    int turn = gameBoard->getGameTurn();
    int gameType = gameBoard->getGameType();
    int currNat = gameBoard->getGameCurrNation();
    if (currNat == TURN_UKE && currUKButton)
        currNat = TURN_UKP;
    else if (currNat == TURN_UKP && !currUKButton && gameType == GLOBAL_GAME)
        currNat = TURN_UKE;

    if (nsTurn == SPREAD_ALL_ROWS && nsCol == SPREAD_ALL_COLS)
    {
        miniSpreadSection->updateMiniSpreadText(turn);
        miniSpreadSection->updateMiniSpreadFormat(currNat);
        miniSpreadSection->drawMiniSpread(graphics, nationSpreads[currNat], dbg_boundbox, dbg_sections, dbg_layers);
    }
    else if (nsCol != SPREAD_ALL_COLS)
    {
        miniSpreadSection->drawMiniSpread(graphics, nationSpreads[currNat], nsTurn, nsCol, dbg_boundbox, dbg_sections, dbg_layers);
        miniSpreadSection->drawMiniSpread(graphics, nationSpreads[currNat], nsTurn + 1, BANK_POS, dbg_boundbox, dbg_sections, dbg_layers);
    }
}

void Game::drawUKEconTabs(bool show)
{
    if (show)
        ShowWindow(ukEconomyTabs, SW_SHOW);
    else
        ShowWindow(ukEconomyTabs, SW_HIDE);
}

void Game::drawWarchestFrame(HDC& hdc)
{
    int gameType = gameBoard->getGameType();
    int turn = gameBoard->getGameTurn();
    int currNat = gameBoard->getGameCurrNation();
    int miniIdx = nationSpreads[currNat]->getMiniIndex();

    warchestSection->updateWarchestBrushes(gameType, warchestRotate, miniSpreadSection->getLastLineBrush(miniIdx));

    int bank = 0;
    int incm = 0;
    if (nsWC == WC_ALL)
    {
        int nat = TURN_NON;
        for (int i = 0; i < saveNations[gameType].size(); i++)
        {
            nat = saveNations[gameType][i];
            if (isBeforeNation(nat, currNat))
            {
                bank = gameBoard->getNationBank(nat, turn + 1);
                incm = gameBoard->getNationIncome(nat, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(nat, turn);
                incm = gameBoard->getNationIncome(nat, turn);
            }

            if (gameType == GLOBAL_GAME && nat == TURN_UKE)
                warchestSection->updateWarchestText(nat, bank, incm, true);
            else
                warchestSection->updateWarchestText(nat, bank, incm);
        }

        nsWC = WC_NON;
    }
    else if (nsWC != WC_NON)
    {
        if ((nsWC & WC_GER) != 0)
        {
            if (isBeforeNation(TURN_GER, currNat))
            {
                bank = gameBoard->getNationBank(TURN_GER, turn + 1);
                incm = gameBoard->getNationIncome(TURN_GER, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(TURN_GER, turn);
                incm = gameBoard->getNationIncome(TURN_GER, turn);
            }
            warchestSection->updateWarchestText(TURN_GER, bank, incm);
        }

        if ((nsWC & WC_SOV) != 0)
        {
            if (isBeforeNation(TURN_SOV, currNat))
            {
                bank = gameBoard->getNationBank(TURN_SOV, turn + 1);
                incm = gameBoard->getNationIncome(TURN_SOV, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(TURN_SOV, turn);
                incm = gameBoard->getNationIncome(TURN_SOV, turn);
            }
            warchestSection->updateWarchestText(TURN_SOV, bank, incm);
        }

        if ((nsWC & WC_JPN) != 0)
        {
            if (isBeforeNation(TURN_JPN, currNat))
            {
                bank = gameBoard->getNationBank(TURN_JPN, turn + 1);
                incm = gameBoard->getNationIncome(TURN_JPN, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(TURN_JPN, turn);
                incm = gameBoard->getNationIncome(TURN_JPN, turn);
            }
            warchestSection->updateWarchestText(TURN_JPN, bank, incm);
        }

        if ((nsWC & WC_USA) != 0)
        {
            if (isBeforeNation(TURN_USA, currNat))
            {
                bank = gameBoard->getNationBank(TURN_USA, turn + 1);
                incm = gameBoard->getNationIncome(TURN_USA, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(TURN_USA, turn);
                incm = gameBoard->getNationIncome(TURN_USA, turn);
            }
            warchestSection->updateWarchestText(TURN_USA, bank, incm);
        }

        if ((nsWC & WC_CHN) != 0)
        {
            if (isBeforeNation(TURN_CHN, currNat))
            {
                bank = gameBoard->getNationBank(TURN_CHN, turn + 1);
                incm = gameBoard->getNationIncome(TURN_CHN, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(TURN_CHN, turn);
                incm = gameBoard->getNationIncome(TURN_CHN, turn);
            }
            warchestSection->updateWarchestText(TURN_CHN, bank, incm);
        }

        if (((nsWC & WC_UKE) | (nsWC & WC_UKP)) != 0)
        {
            if (gameType != PACIFIC_GAME)
            {
                if (isBeforeNation(TURN_UKE, currNat))
                {
                    bank = gameBoard->getNationBank(TURN_UKE, turn + 1);
                    incm = gameBoard->getNationIncome(TURN_UKE, turn + 1);
                }
                else
                {
                    bank = gameBoard->getNationBank(TURN_UKE, turn);
                    incm = gameBoard->getNationIncome(TURN_UKE, turn);
                }
                if (gameType == GLOBAL_GAME)
                    warchestSection->updateWarchestText(TURN_UKE, bank, incm, true);
                else
                    warchestSection->updateWarchestText(TURN_UKE, bank, incm);
            }

            if (gameType != EUROPE_GAME)
            {
                if (isBeforeNation(TURN_UKP, currNat))
                {
                    bank = gameBoard->getNationBank(TURN_UKP, turn + 1);
                    incm = gameBoard->getNationIncome(TURN_UKP, turn + 1);
                }
                else
                {
                    bank = gameBoard->getNationBank(TURN_UKP, turn);
                    incm = gameBoard->getNationIncome(TURN_UKP, turn);
                }
                warchestSection->updateWarchestText(TURN_UKP, bank, incm);
            }
        }

        if ((nsWC & WC_ITA) != 0)
        {
            if (isBeforeNation(TURN_ITA, currNat))
            {
                bank = gameBoard->getNationBank(TURN_ITA, turn + 1);
                incm = gameBoard->getNationIncome(TURN_ITA, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(TURN_ITA, turn);
                incm = gameBoard->getNationIncome(TURN_ITA, turn);
            }
            warchestSection->updateWarchestText(TURN_ITA, bank, incm);
        }

        if ((nsWC & WC_ANZ) != 0)
        {
            if (isBeforeNation(TURN_ANZ, currNat))
            {
                bank = gameBoard->getNationBank(TURN_ANZ, turn + 1);
                incm = gameBoard->getNationIncome(TURN_ANZ, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(TURN_ANZ, turn);
                incm = gameBoard->getNationIncome(TURN_ANZ, turn);
            }
            warchestSection->updateWarchestText(TURN_ANZ, bank, incm);
        }

        if ((nsWC & WC_FRA) != 0)
        {
            if (isBeforeNation(TURN_FRA, currNat))
            {
                bank = gameBoard->getNationBank(TURN_FRA, turn + 1);
                incm = gameBoard->getNationIncome(TURN_FRA, turn + 1);
            }
            else
            {
                bank = gameBoard->getNationBank(TURN_FRA, turn);
                incm = gameBoard->getNationIncome(TURN_FRA, turn);
            }
            warchestSection->updateWarchestText(TURN_FRA, bank, incm);
        }

        nsWC = WC_NON;
    }

    warchestSection->drawWarchestBox(graphics, dbg_boundbox, dbg_sections, dbg_layers);

    if (warchestRotate)
        warchestRotate = false;
}

void Game::drawBonusFrame(HDC& hdc)
{
    int gameType = gameBoard->getGameType();
    int currNat = gameBoard->getGameCurrNation();

    vector<bonusTransaction> bonusUpdate;
    bonusUpdate = *gameBoard->getBonusUpdate();

    bonusSection->updateBonusFormat(gameType, currNat);

    if (nsBonusRow == BONS_ALL)
    {
        bonusSection->updateBonusText(gameType, currNat);
        bonusSection->drawBonusBox(graphics, dbg_boundbox, dbg_sections, dbg_layers);
    }
    else if (bonusUpdate.size() > 0)
    {
        for (int i = 0; i < bonusUpdate.size(); i++)
            bonusSection->updateBonusText(gameType, bonusUpdate[i].nat, bonusUpdate[i].bonus, bonusUpdate[i].val, bonusUpdate[i].bin);
        gameBoard->resetBonusUpdate();

        bonusSection->drawBonusBox(graphics, true, dbg_boundbox, dbg_sections, dbg_layers);
    }

    nsBonusRow = BONS_ALL;
}
