#include "../header/AA_Tracker.h"

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// Message handler for new game box.
INT_PTR CALLBACK Game::NewGame(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam, Board& gameBoard)
{
    TCHAR    ListItem[32];
    TCHAR    A[32];

    TCHAR gameTypes[4][32] =
    {
        TEXT("Select a Game Type"), TEXT("Europe 1940"), TEXT("Pacific 1940"),
        TEXT("Global 1940")
    };
    uint16_t types[4] = { IDM_SELECTGAME, IDM_EUROPEGAME, IDM_PACIFICGAME, IDM_GLOBALGAME };

    for (n = 0; n < 32; n++)
        ListItem[n] = '\0';

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        if (gameBoard.ready)
        {
            MessageBox(hDlg,
                L"Remember to save your game\nbefore making a new one!",
                L"Warning",
                MB_OK);
        }

        // Set the default push button to "Cancel." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDCANCEL,
            (LPARAM)0);

        HWND gameTypeMenu;
        gameTypeMenu = GetDlgItem(hDlg, IDC_NEWGAMETYPE);

        memset(&A, 0, sizeof(A));
        for (n = 0; n <= 3; n++)
        {
            wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)gameTypes[n]);
            SendMessage(gameTypeMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
            SendMessage(gameTypeMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
        }

        success = true;
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_NEWGAMETYPE) // New Game Type
        {
            WPARAM ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);
 
            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex, (LPARAM)ListItem);

            for (k = 0; k <= 3; k++)
            {
                if (_tcscmp(ListItem, gameTypes[k]) == 0)
                    break;
            }
        }
        else if (LOWORD(wParam) == IDC_RESEARCHGAME) // New Game Research
        {
            if (IsDlgButtonChecked(hDlg, IDC_RESEARCHGAME))
                CheckDlgButton(hDlg, IDC_RESEARCHGAME, BST_UNCHECKED);
            else 
                CheckDlgButton(hDlg, IDC_RESEARCHGAME, BST_CHECKED);          
        }

        switch (wParam)
        {
        case IDOK:
            if (types[k] == IDM_SELECTGAME)
            {
                MessageBox(hDlg,
                    L"Please select a game type.",
                    L"Error",
                    MB_OK);
                return FALSE;
            }

            int gameType;
            switch (types[k])
            {
            case IDM_EUROPEGAME:
                gameType = EUROPE_GAME;
                break;
            case IDM_PACIFICGAME:
                gameType = PACIFIC_GAME;
                break;
            case IDM_GLOBALGAME:
                gameType = GLOBAL_GAME;
                break;
            default:
                gameType = GLOBAL_GAME;
                break;
            }

            gameBoard.setGameType(gameType);
            gameBoard.setGameResearch(IsDlgButtonChecked(hDlg, IDC_RESEARCHGAME));

            EndDialog(hDlg, TRUE);
            success = true;
            return TRUE;

        case IDCANCEL:
            EndDialog(hDlg, TRUE);
            success = false;
            whichScreen = MAIN_SCREEN;
            hideScreen();
            return TRUE;
        }
        return 0;

        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Game::DeclareWar(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam, Board& gameBoard)
{
    int currNat = gameBoard.getGameCurrNation();
    int currTurn = gameBoard.getGameTurn();
    int whichUK = TURN_UKE;
    if (gameBoard.getGameType() == PACIFIC_GAME)
        int whichUK = TURN_UKP;

    TCHAR    ListItem[32];
    TCHAR    A[32];
    WPARAM ItemIndex;
    
    TCHAR warNations[11][16] =
    {
        TEXT("Germany"), TEXT("Soviet Union"), TEXT("Japan"),
        TEXT("United States"), TEXT("China"), TEXT("United Kingdom"), TEXT(" "),
        TEXT("Italy"), TEXT("ANZAC"), TEXT("France"), TEXT("Select a target")
    };

    for (n = 0; n < 32; n++)
        ListItem[n] = '\0';

    int cnt = 0;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the default push button to "Cancel." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDCANCEL,
            (LPARAM)0);

        HWND declareWarMenu;
        declareWarMenu = GetDlgItem(hDlg, IDC_DECLAREWAR);

        memset(&A, 0, sizeof(A));

        wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)warNations[10]);
        SendMessage(declareWarMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
        SendMessage(declareWarMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

        for (n = 0; n < 10; n++)
        {
            if (gameBoard.canDeclareWarOn(currNat, n) && n != 6)
            {
                wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)warNations[n]);
                SendMessage(declareWarMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
                SendMessage(declareWarMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
                cnt++;
            }
        }

        if (cnt == 0)
        {
            MessageBox(hDlg,
                L"Cannot declare war yet!",
                L"Error",
                MB_OK);
            EndDialog(hDlg, TRUE);
            return (INT_PTR)FALSE;
        }
        else
            return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_DECLAREWAR)
        {
            ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);

            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex, (LPARAM)ListItem);

            for (k = 0; k < 10; k++)
            {
                if (_tcscmp(ListItem, warNations[k]) == 0)
                    break;
            }
        }

        switch (wParam)
        {
        case IDOK:
            if (whichSide(currNat) == SIDE_AXIS)
            {
                if (k == TURN_USA)
                    if (gameBoard.isAtWar(TURN_USA))
                        gameBoard.setDeclaredWarOnUSA();

                gameBoard.setAtWarWith(currNat, k);
                if (((k == whichUK) || (k == TURN_ANZ)) && currNat == TURN_JPN)
                {
                    gameBoard.setJPNDeclaredWarOnUK();
                    if (k == whichUK)
                    {
                        gameBoard.setAtWarWith(TURN_JPN, whichUK);
                        gameBoard.setAtWarWith(TURN_JPN, TURN_ANZ);
                        gameBoard.setAtWarWith(TURN_JPN, DUTCH_TER);
                    }
                    else if (k == TURN_ANZ)
                    {
                        gameBoard.setAtWarWith(TURN_JPN, TURN_UKE);
                        gameBoard.setAtWarWith(TURN_JPN, TURN_UKP);
                        gameBoard.setAtWarWith(TURN_JPN, DUTCH_TER);
                    }
                }
            }
            else
            {
                gameBoard.setAtWarWith(k, currNat);
                if (((currNat == whichUK) || (currNat == TURN_ANZ)) && k == TURN_JPN)
                {
                    if (currNat == whichUK)
                    {
                        gameBoard.setAtWarWith(k, TURN_ANZ);
                        gameBoard.setAtWarWith(k, DUTCH_TER);
                    }
                    else if (currNat == TURN_ANZ)
                    {
                        gameBoard.setAtWarWith(TURN_JPN, TURN_UKE);
                        gameBoard.setAtWarWith(TURN_JPN, TURN_UKP);
                        gameBoard.setAtWarWith(TURN_JPN, DUTCH_TER);
                    }
                }
            }

            if (k == 10)
            {
                MessageBox(hDlg,
                    L"Please select a target.",
                    L"Error",
                    MB_OK);
                return FALSE;
            }

            // No need for popups, will be used in CI phase
            gameBoard.updateBonuses(hDlg, currNat, false, 0);
            updateSpreadsheet(currNat, currTurn, BONS_POS);
            nsWar = WAR_SECT_NON;
            nsWarTgt = k;
            nsTurn = currTurn;
            nsCol = BONS_POS;
            nsBonusRow = BONS_UPD;
            nsSection = PHASE_SECT | WAR_SECT | SPREAD_SECT | BONUS_SECT;

            gameLog->addLogText(currTurn, V_WAR, currNat, k);

            EndDialog(hDlg, TRUE);
            return TRUE;

        case IDCANCEL:
            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        return 0;

        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Game::CaptureTerritory(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    WCHAR  ListItem[TERRITORY_NAMELEN];
    WCHAR  A[TERRITORY_NAMELEN];
    WPARAM ItemIndex;

    int currNat = gameBoard->getGameCurrNation();
    int currSide = whichSide(currNat);
    int currTurn = gameBoard->getGameTurn();
    int type = gameBoard->getGameType();
    vector<listTerritory> validTerritories;
    vector<listTerritory> alphabetizedTerritories;
    vector<int> wars;

    int subjNat;
    bool isLib = false, isLibCap = false;
    int prev = 0;

    // Whose territories are valid?
    for (int i = 0; i <= DUTCH_TER; i++)
    {
        if (whichSide(currNat) == SIDE_AXIS)
        {
            if (gameBoard->getAtWarWith(currNat, i) == true)
                wars.push_back(i);
        }
        else
        {
            if (gameBoard->getAtWarWith(i, currNat) == true)
                wars.push_back(i);
        }
    }

    int low = (type != PACIFIC_GAME) ? (TER_ALBERTA) : (TER_EVENKIYSKIY);
    int high = (type != EUROPE_GAME) ? (TER_MEXICO) : (TER_WEST_INDIA);
    int idx = 0;
    int min = 201;

    if (wars.size() > 0)
    {
        // Add neutral territories which lean the other way
        if (currSide == SIDE_AXIS)
            wars.push_back(ALLY_NEUTRAL);
        else if (currSide == SIDE_ALLIES)
            wars.push_back(AXIS_NEUTRAL);

        // Make a list
        listTerritory temp;
        for (int i = low; i <= high; i++)
        {
            for (int j = 0; j < wars.size(); j++)
            {
                if (gameBoard->getTerritoryOwner(i) == wars[j])
                {
                    if (currNat == TURN_CHN)
                    {
                        if (gameBoard->getTerritoryValidForChina(i))
                        {
                            gameBoard->getTerritoryName(i, temp);
                            validTerritories.push_back(temp);
                            break;
                        }
                    }
                    else
                    {
                        gameBoard->getTerritoryName(i, temp);
                        validTerritories.push_back(temp);
                        break;
                    }
                }
            }
        }

        // Alphabetize the list
        if (validTerritories.size() > 0)
        {
            alphabetizedTerritories.resize(validTerritories.size());

            for (int i = 0; i < alphabetizedTerritories.size(); i++)
            {
                // Find the minimum
                min = 201;
                for (int j = 0; j < validTerritories.size(); j++)
                {
                    if (validTerritories[j].alph <= min)
                    {
                        min = validTerritories[j].alph;
                        idx = j;
                    }
                }

                // Assign to alphabetized list
                alphabetizedTerritories[i] = validTerritories[idx];
                validTerritories.erase(validTerritories.begin() + idx);
            }
        }        
    }

    for (n = 0; n < TERRITORY_NAMELEN; n++)
        ListItem[n] = '\0';
    
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the default push button to "Cancel." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDCANCEL,
            (LPARAM)0);
    
        HWND captureTerritoryMenu;
        captureTerritoryMenu = GetDlgItem(hDlg, IDC_CAPTURETER);
    
        memset(&A, 0, sizeof(A));
    
        if (alphabetizedTerritories.size() > 0)
        {
            k = 0;
            wcscpy_s(A, sizeof(A) / sizeof(WCHAR), (WCHAR*)alphabetizedTerritories[0].name.t);
            for (n = 0; n < alphabetizedTerritories.size(); n++)
            {
                wcscpy_s(A, sizeof(A) / sizeof(WCHAR), (WCHAR*)alphabetizedTerritories[n].name.t);
                SendMessage(captureTerritoryMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
                SendMessage(captureTerritoryMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
            }
            return (INT_PTR)TRUE;
        }
        else
        {
            MessageBox(hDlg,
                L"No valid territories remaining.",
                L"Error",
                MB_OK);
            EndDialog(hDlg, TRUE);
            return (INT_PTR)FALSE;
        }        
    
    case WM_COMMAND:
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_CAPTURETER)
        {
            ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);
    
            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex, (LPARAM)ListItem);
    
            for (k = 0; k < alphabetizedTerritories.size(); k++)
            {
                if (_tcscmp(ListItem, alphabetizedTerritories[k].name.t) == 0)
                    break;
            }
        }
    
        switch (wParam)
        {
        case IDC_UKE_CAPTURESEL:
        {
            captButtonUKE = true;
            CheckDlgButton(hDlg, IDC_UKE_CAPTURESEL, BST_CHECKED);
            captButtonUKP = false;
            CheckDlgButton(hDlg, IDC_UKP_CAPTURESEL, BST_UNCHECKED);
            return TRUE;
        }
        case IDC_UKP_CAPTURESEL:
        {
            captButtonUKE = false;
            CheckDlgButton(hDlg, IDC_UKE_CAPTURESEL, BST_UNCHECKED);
            captButtonUKP = true;
            CheckDlgButton(hDlg, IDC_UKP_CAPTURESEL, BST_CHECKED);
            return TRUE;
        }
        case IDOK:
        {
            // Global UK must select which economy territory is added to
            if (!captButtonUKE && !captButtonUKP && type == GLOBAL_GAME && currNat == TURN_UKE)
            {
                MessageBox(hDlg,
                    L"Select economy to add territory to.",
                    L"Error",
                    MB_OK);
                return (INT_PTR)FALSE;
            }
            else if (type == GLOBAL_GAME && currNat == TURN_UKE)
            {
                if (captButtonUKE)
                    subjNat = currNat;
                else
                {
                    currNat = TURN_UKP;
                    subjNat = TURN_UKP;
                }
            }
            else            
                subjNat = currNat;

            gameBoard->transferTerritory(hDlg, alphabetizedTerritories[k].id, currNat, captureAmount, prev, isLib, isLibCap);

            if (prev < DUTCH_TER)
            {
                if (isBeforeNation(prev, currNat))
                    updateSpreadsheet(prev, currTurn + 1, true);
                else
                    updateSpreadsheet(prev, currTurn, true);
            }
            updateSpreadsheet(currNat, currTurn, true);

            if (!isLib)
                gameLog->addLogText(currTurn, V_CAPTURE, currNat, alphabetizedTerritories[k].id, prev);
            else
            {
                if (subjNat != currNat)
                {
                    if ((subjNat == TURN_UKE && currNat == TURN_UKP) || (subjNat == TURN_UKP && currNat == TURN_UKE))
                        gameLog->addLogText(currTurn, V_RECLAIM, subjNat, alphabetizedTerritories[k].id, prev, currNat);
                    else
                        gameLog->addLogText(currTurn, V_LIBERATE, subjNat, alphabetizedTerritories[k].id, prev, currNat);
                }
                else
                    gameLog->addLogText(currTurn, V_RECLAIM, subjNat, alphabetizedTerritories[k].id, prev, currNat);
            }

            if (isLibCap)
            {
                vector<vector<int>> targets;
                targets.resize(10);

                // Distribute any territories captured this turn by current nation to liberated ally
                // Removes their captures from the log, changes them to liberations
                gameBoard->transferTerritory(hDlg, subjNat, currNat, targets[0]);

                if (subjNat != currNat && targets[0].size() > 0)
                    gameLog->adjustLog(subjNat, currNat, targets[0]);

                // Distribute any territories controlled by allies to liberated nation
                // Does not affect past logs
                gameBoard->transferTerritoryAllies(hDlg, currNat, targets);

                bool empty = true;
                for (int i = 0; i <= TURN_FRA; i++)
                    if (targets[i].size() > 0)
                    {
                        empty = false;

                        if (isBeforeNation(i, currNat))
                            updateSpreadsheet(i, currTurn + 1, true);
                        else
                            updateSpreadsheet(i, currTurn, true);

                        nsWC |= 1 << i;
                    }

                if (!empty)
                {
                    gameLog->adjustLogAllies(currNat, targets);

                    updateSpreadsheet(currNat, currTurn, true);
                }

            }

            nsCity = getTerCity(alphabetizedTerritories[k].id);
            nsTurn = SPREAD_ALL_ROWS;
            nsCol = SPREAD_ALL_COLS;
            nsWC |= 1 << prev;
            nsBonusRow = BONS_UPD;
            nsSection = STAT_SECT | CITY_SECT | SPREAD_SECT | CHEST_SECT | BONUS_SECT;

            if (gameBoard->getNeutralTerrUpdateSize() != 0 && purchaseTab == TAB_NEUTRAL)
            {
                nsNeut = NEUT_UPD;
                nsSection |= PURCH_SECT;
            }

            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        case IDCANCEL:
            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        return 0;
    
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Game::ResearchF(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR  ListItem[3];
    TCHAR  A[3];
    WPARAM ItemIndex;
    
    int currNat = gameBoard->getGameCurrNation();
    int currTurn = gameBoard->getGameTurn();

    int max_res = gameBoard->getNationBank(currNat, currTurn) / RESEARCH_COST;

    TCHAR numDice[72][3] = { L" 1", L" 2", L" 3", L" 4", L" 5", L" 6", L" 7", L" 8", L" 9", L"10",
                             L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20",
                             L"21", L"22", L"23", L"24", L"25", L"26", L"27", L"28", L"29", L"30",
                             L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40",
                             L"41", L"42", L"43", L"44", L"45", L"46", L"47", L"48", L"49", L"50",
                             L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59", L"60",
                             L"61", L"62", L"63", L"64", L"65", L"66", L"67", L"68", L"69", L"70",
                             L"71", L"72" };

    ListItem[2] = '\0';
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the default push button to "Cancel." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDCANCEL,
            (LPARAM)0);
    
        HWND numDiceMenu;
        numDiceMenu = GetDlgItem(hDlg, IDC_RESEARCHNUM);
    
        memset(&A, 0, sizeof(A));
    
        if (max_res > 0 && gameBoard->getCount(currNat) != 12)
        {
            k = 0;
            wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)numDice[0]);
            for (n = 0; n < max_res; n++)
            {
                wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)numDice[n]);
                SendMessage(numDiceMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
                SendMessage(numDiceMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
            }
            return (INT_PTR)TRUE;
        }
        else if (gameBoard->getCount(currNat) == 12)
        {
            MessageBox(hDlg,
                L"All technologies already researched.",
                L"Error",
                MB_OK);

            numResDice[0] = 0;
            numResDice[1] = 0;

            EndDialog(hDlg, TRUE);
            return (INT_PTR)FALSE;
        }
        else
        {
            MessageBox(hDlg,
                L"Cannot afford any dice.",
                L"Error",
                MB_OK);

            numResDice[0] = 0;
            numResDice[1] = 0;

            EndDialog(hDlg, TRUE);
            return (INT_PTR)FALSE;
        }
    
    case WM_COMMAND:
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_RESEARCHNUM)
        {
            ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);

            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex, (LPARAM)ListItem);

            for (k = 0; k < max_res; k++)
            {
                if (_tcscmp(ListItem, numDice[k]) == 0)
                    break;
            }
        }
    
        switch (wParam)
        {
        case IDB_RESEARCHGO:
            numResDice[0] = k + 1;
            numResDice[1] = 0;

            EndDialog(hDlg, TRUE);
            return TRUE;
    
        case IDCANCEL:
            numResDice[0] = 0;
            numResDice[1] = 0;

            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        return 0;
    
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Game::ResearchRes(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR  ListItem[32];
    TCHAR  A[32];
    TCHAR B[3];
    WPARAM ItemIndex;

    int currNat = gameBoard->getGameCurrNation();
    int currTurn = gameBoard->getGameTurn();

    TCHAR numDice[72][3] = { L" 1", L" 2", L" 3", L" 4", L" 5", L" 6", L" 7", L" 8", L" 9", L"10",
                             L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20",
                             L"21", L"22", L"23", L"24", L"25", L"26", L"27", L"28", L"29", L"30",
                             L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40",
                             L"41", L"42", L"43", L"44", L"45", L"46", L"47", L"48", L"49", L"50",
                             L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59", L"60",
                             L"61", L"62", L"63", L"64", L"65", L"66", L"67", L"68", L"69", L"70",
                             L"71", L"72" };

    TCHAR outcomes[13][32] = { L"Failure", L"Advanced Artillery", L"Rockets", L"Paratroopers", 
                               L"Increased Factory Production", L"War Bonds", L"Improved Mechanized Infantry", 
                               L"Super Submarines", L"Jet Fighters", L"Improved Shipyards", L"Radar", 
                               L"Long-Range Aircraft", L"Heavy Bombers" };

    vector<int> valIdx = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    for (int i = 12; i > 0; i--)
    {
        if (gameBoard->getResearch(currNat, i) == true)
            valIdx.erase(valIdx.begin() + i);
    }

    for (n = 0; n < 32; n++)
        ListItem[n] = '\0';

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the default push button to "Cancel." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDCANCEL,
            (LPARAM)0);

        HWND resRollNumDisp;
        resRollNumDisp = GetDlgItem(hDlg, IDC_RESEARCHRESNUM);
        wcscpy_s(B, sizeof(B) / sizeof(TCHAR), (TCHAR*)numDice[currResDie]);
        SetDlgItemText(hDlg, IDC_RESEARCHRESNUM, B);

        HWND resMenu;
        resMenu = GetDlgItem(hDlg, IDC_RESEARCHRES);
        
        memset(&A, 0, sizeof(A));
        
        k = 0;
        wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)outcomes[0]);
        for (n = 0; n < valIdx.size(); n++)
        {
            wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)outcomes[valIdx[n]]);
            SendMessage(resMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
            SendMessage(resMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
        }
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_RESEARCHRES)
        {
            ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);
        
            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex, (LPARAM)ListItem);
        
            for (k = 0; k < valIdx.size(); k++)
            {
                if (_tcscmp(ListItem, outcomes[valIdx[k]]) == 0)
                    break;
            }
        }

        switch (wParam)
        {
        case IDOK:
            gameBoard->setResearch(currNat, valIdx[k]);
            if (valIdx[k] != 0)
                gameLog->addLogText(currTurn, V_RESEARCH, currNat, valIdx[k]);
            addResearchIcon(valIdx[k], currNat);

            // If Improved Shipyards, update the text
            purchaseSection->updatePurchaseText(true);

            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        return 0;

        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Game::ResearchUK(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR  ListItem[2][3];
    TCHAR  A[2][3];
    WPARAM ItemIndex[2];
    
    uint16_t currNat = gameBoard->getGameCurrNation();
    uint16_t currTurn = gameBoard->getGameTurn();
    uint16_t gameType = gameBoard->getGameType();

    uint16_t max_uke = gameBoard->getNationBank(TURN_UKE, currTurn) / RESEARCH_COST;
    uint16_t max_ukp = gameBoard->getNationBank(TURN_UKP, currTurn) / RESEARCH_COST;
    uint16_t max_res = max_uke + max_ukp;
    uint16_t min_uke = 0;

    HWND numDiceMenu, ukeDiceMenu;
    numDiceMenu = GetDlgItem(hDlg, IDC_RESEARCHNUM);
    ukeDiceMenu = GetDlgItem(hDlg, IDC_UKRESEARCHSPLIT);

    TCHAR numDice[73][3] = { L" 0",
                             L" 1", L" 2", L" 3", L" 4", L" 5", L" 6", L" 7", L" 8", L" 9", L"10",
                             L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20",
                             L"21", L"22", L"23", L"24", L"25", L"26", L"27", L"28", L"29", L"30",
                             L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40",
                             L"41", L"42", L"43", L"44", L"45", L"46", L"47", L"48", L"49", L"50",
                             L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59", L"60",
                             L"61", L"62", L"63", L"64", L"65", L"66", L"67", L"68", L"69", L"70",
                             L"71", L"72" };

    ListItem[0][2] = '\0';
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the default push button to "Cancel." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDCANCEL,
            (LPARAM)0);
    
        memset(&A[0], 0, sizeof(A[0]));
    
        if (max_res > 0 && gameBoard->getCount(currNat) != 12)
        {
            k = 0;
            wcscpy_s(A[0], sizeof(A[0]) / sizeof(TCHAR), (TCHAR*)numDice[0]);
            for (n = 0; n < max_res + 1; n++)
            {
                wcscpy_s(A[0], sizeof(A[0]) / sizeof(TCHAR), (TCHAR*)numDice[n]);
                SendMessage(numDiceMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A[0]);
                SendMessage(numDiceMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
            }
            return (INT_PTR)TRUE;
        }
        else if (gameBoard->getCount(currNat) == 12)
        {
            MessageBox(hDlg,
                L"All technologies already researched.",
                L"Error",
                MB_OK);

            numResDice[0] = 0;
            numResDice[1] = 0;

            EndDialog(hDlg, TRUE);
            return (INT_PTR)FALSE;
        }
        else
        {
            MessageBox(hDlg,
                L"Cannot afford any dice.",
                L"Error",
                MB_OK);

            numResDice[0] = 0;
            numResDice[1] = 0;

            EndDialog(hDlg, TRUE);
            return (INT_PTR)FALSE;
        }
    
    case WM_COMMAND:
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_RESEARCHNUM)
        {
            ItemIndex[0] = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);

            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex[0], (LPARAM)ListItem[0]);

            for (k = 0; k < max_res; k++)
            {
                if (_tcscmp(ListItem[0], numDice[k]) == 0)
                    break;
            }

            memset(&A[1], 0, sizeof(A[1]));

            if (max_res > 0)
            {
                min_uke = (k - max_ukp >= 0) ? (k - max_ukp) : (0);
                max_uke = (k >= max_uke) ? (max_uke) : (k);

                for (n = 0; n < max_res; n++)
                    SendMessage(ukeDiceMenu, (UINT)CB_DELETESTRING, (WPARAM)0, (LPARAM)A[1]);

                wcscpy_s(A[1], sizeof(A[1]) / sizeof(TCHAR), (TCHAR*)numDice[0]);
                for (n = min_uke; n < max_uke + 1; n++)
                {
                    wcscpy_s(A[1], sizeof(A[1]) / sizeof(TCHAR), (TCHAR*)numDice[n]);
                    SendMessage(ukeDiceMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A[1]);
                    SendMessage(ukeDiceMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
                }
                return (INT_PTR)TRUE;
            }
        }
        else if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_UKRESEARCHSPLIT)
        {
            ItemIndex[1] = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);

            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex[1], (LPARAM)ListItem[1]);

            min_uke = (k - max_ukp >= 0) ? (k - max_ukp) : (0);
            for (u = 0; u < max_uke + 1; u++)
            {
                if (_tcscmp(ListItem[1], numDice[u + min_uke]) == 0)
                    break;
            }
        }
        switch (wParam)
        {
        case IDB_RESEARCHGO:
            if (k == 0)
            {
                MessageBox(hDlg,
                    L"Attempting to buy zero dice!",
                    L"Error",
                    MB_OK);

                numResDice[0] = 0;
                numResDice[1] = 0;

                return (INT_PTR)FALSE;
            }

            min_uke = (k - max_ukp >= 0) ? (k - max_ukp) : (0);
            numResDice[0] = u + min_uke;
            numResDice[1] = k - (u + min_uke);

            EndDialog(hDlg, TRUE);
            return TRUE;
    
        case IDCANCEL:
            numResDice[0] = 0;
            numResDice[1] = 0;

            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        return 0;
    
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Game::WarBonds(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR  ListItem[3];
    TCHAR  A[3];
    WPARAM ItemIndex;

    uint16_t currNat = gameBoard->getGameCurrNation();
    uint16_t currTurn = gameBoard->getGameTurn();
    uint16_t max_res = gameBoard->getNationBank(currNat, currTurn) / 5;

    TCHAR numIPCs[6][3] = { L" 1", L" 2", L" 3", L" 4", L" 5", L" 6" };

    ListItem[2] = '\0';
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the default push button to "Ok." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDOK,
            (LPARAM)0);

        HWND bondAmt;
        bondAmt = GetDlgItem(hDlg, IDC_WARBONDNUM);

        memset(&A, 0, sizeof(A));

        k = 0;
        wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)numIPCs[0]);
        for (n = 0; n < 6; n++)
        {
            wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)numIPCs[n]);
            SendMessage(bondAmt, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
            SendMessage(bondAmt, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
        }
        return (INT_PTR)TRUE;
        

    case WM_COMMAND:
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_WARBONDNUM)
        {
            ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);

            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex, (LPARAM)ListItem);

            for (k = 0; k < 6; k++)
            {
                if (_tcscmp(ListItem, numIPCs[k]) == 0)
                    break;
            }
        }

        switch (wParam)
        {
        case IDOK:
            bondAmount = k + 1;

            gameBoard->addNationBonus(currNat, currTurn, bondAmount);
            gameBoard->addNationBank(currNat, currTurn + 1, bondAmount);

            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        return 0;

        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Game::CustomLog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    WCHAR custLogText[TEXTLEN], tmpText[TEXTLEN];
    WORD lineCount, custLen;
    int idx = 0;

    for (int i = 0; i < TEXTLEN; i++)
    {
        tmpText[i] = '\0';
        custLogText[i] = '\0';
    }

    HWND custText = NULL;

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the default push button to "Cancel." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDCANCEL,
            (LPARAM)0);

        custText = CreateWindow(
            L"EDIT",
            NULL,
            WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL,
            12, 48, 488, 36,
            hDlg,
            (HMENU)IDE_CUSTLOG,
            (HINSTANCE)GetWindowLongPtr(hDlg, GWLP_HINSTANCE),
            NULL);

            return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (wParam)
        {
        case IDOK:
        {
            lineCount = (WORD)SendDlgItemMessage(hDlg,
                IDE_CUSTLOG,
                EM_GETLINECOUNT,
                (WPARAM)0,
                (LPARAM)0);

            for (int i = 0; i < lineCount; i++)
            {
                custLen = (WORD)SendDlgItemMessage(hDlg,
                    IDE_CUSTLOG,
                    EM_LINELENGTH,
                    (WPARAM)i,
                    (LPARAM)0);

                // Put the number of characters into first word of buffer. 
                *((LPWORD)tmpText) = custLen;

                // Get the characters. 
                SendDlgItemMessage(hDlg,
                    IDE_CUSTLOG,
                    EM_GETLINE,
                    (WPARAM)i,
                    (LPARAM)tmpText);

                for (int j = 0; j < custLen; j++)
                {
                    if (idx + j < TEXTLEN)
                        custLogText[idx + j] = tmpText[j];
                    tmpText[j] = '\0';
                }
                idx += custLen;
            }

            if (idx >= TEXTLEN)
            {
                MessageBox(hDlg,
                    L"Too many characters.",
                    L"Error",
                    MB_OK);

                return (INT_PTR)FALSE;
            }
            else if (idx == 0)
            {
                MessageBox(hDlg,
                    L"No log entry.",
                    L"Error",
                    MB_OK);

                return (INT_PTR)FALSE;
            }
            else
            {
                if (idx < TEXTLEN && idx >= 0)
                    custLogText[idx] = '\0';

                // Send to log
                gameLog->addLogText(gameBoard->getGameTurn(), &custLogText[0]);

                EndDialog(hDlg, TRUE);
                return TRUE;
            }
        }
        case IDCANCEL:
            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        return 0;

        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Game::OccupyNeutral(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    WCHAR  ListItem[TERRITORY_NAMELEN]; 
    WCHAR  A[TERRITORY_NAMELEN];
    WPARAM ItemIndex;

    for (int i = 0; i < TERRITORY_NAMELEN; i++)
        ListItem[i] = '\0';

    int currNat = gameBoard->getGameCurrNation();
    int currTurn = gameBoard->getGameTurn();
    vector<listTerritory> validNeutrals;

    // Which territories are valid?
    // UKP and ANZAC can occupy Dutch territories
    if (currNat == TURN_UKE || currNat == TURN_ANZ)
        gameBoard->getNeutralTerrs(validNeutrals, whichSide(currNat), true);
    else
        gameBoard->getNeutralTerrs(validNeutrals, whichSide(currNat));

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        // Set the default push button to "Cancel." 
        SendMessage(hDlg,
            DM_SETDEFID,
            (WPARAM)IDCANCEL,
            (LPARAM)0);

        HWND occupyNeutralMenu;
        occupyNeutralMenu = GetDlgItem(hDlg, IDC_OCCUPYNEUT);

        memset(&A, 0, sizeof(A));

        if (validNeutrals.size() > 0)
        {
            k = 0;
            wcscpy_s(A, sizeof(A) / sizeof(WCHAR), (WCHAR*)validNeutrals[0].name.t);
            for (n = 0; n < validNeutrals.size(); n++)
            {
                wcscpy_s(A, sizeof(A) / sizeof(WCHAR), (WCHAR*)validNeutrals[n].name.t);
                SendMessage(occupyNeutralMenu, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
                SendMessage(occupyNeutralMenu, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
            }
            return (INT_PTR)TRUE;
        }
        else
        {
            MessageBox(hDlg,
                L"No valid territories remaining.",
                L"Error",
                MB_OK);
            EndDialog(hDlg, TRUE);
            return (INT_PTR)FALSE;
        }

    case WM_COMMAND:
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_CAPTURETER)
        {
            ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);

            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex, (LPARAM)ListItem);

            for (k = 0; k < validNeutrals.size(); k++)
            {
                if (_tcscmp(ListItem, validNeutrals[k].name.t) == 0)
                    break;
            }
        }

        switch (wParam)
        {
        case IDOK:
        {
            gameBoard->transferTerritory(hDlg, validNeutrals[k].id, currNat);

            updateSpreadsheet(currNat, currTurn, true);

            gameLog->addLogText(currTurn, V_OCCUPY, currNat, validNeutrals[k].id);

            nsSection = ((purchaseTab == TAB_NEUTRAL) ? PURCH_SECT : NO_SECT) | SPREAD_SECT;
            nsNeut = NEUT_UPD;
            nsCol = SPREAD_ALL_COLS;
            nsTurn = SPREAD_ALL_ROWS;

            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        case IDCANCEL:
            EndDialog(hDlg, TRUE);
            return TRUE;
        }
        return 0;

        break;
    }
    return (INT_PTR)FALSE;
}