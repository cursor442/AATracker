// AA Tracker.cpp : Defines the entry point for the application.
//

#include "../header/AA_Tracker.h"
#include "../../nationScreen/header/NationScreenWrappers.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK NewGameWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK CustomLogWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

Game* game = new Game;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, game->szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_AATRACKER, game->szWindowClass, MAX_LOADSTRING);
    game->MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!game->InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_AATRACKER));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM Game::MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_AATRACKER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_AATRACKER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL Game::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   // Get size of monitor
   screenResX = GetSystemMetrics(SM_CXSCREEN);
   screenResY = GetSystemMetrics(SM_CYSCREEN);

   // Cap at 1080p for now
   if (screenResX > MAX_RES_X)
       screenResX = MAX_RES_X;
   if (screenResY > MAX_RES_Y)
       screenResY = MAX_RES_Y;

   // Main Window
   main_Wnd = CreateWindowW(
       szWindowClass, 
       szTitle, 
       //WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME,
       WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX,
       //CW_USEDEFAULT, 0,
       -7, 0, 
       //CW_USEDEFAULT, 0, 
       //GetSystemMetrics(SM_CXSCREEN) + 14, GetSystemMetrics(SM_CYSCREEN) - 33,
       screenResX, screenResY,
       nullptr, 
       nullptr, 
       hInstance, 
       nullptr);

   if (!main_Wnd)
   {
      return FALSE;
   }

   SetClassLongPtr(main_Wnd, GCLP_HBRBACKGROUND, (LONG_PTR)backBrush0);

   //ShowWindow(main_Wnd, SW_MAXIMIZE);
   ShowWindow(main_Wnd, SW_SHOW);
   UpdateWindow(main_Wnd);
   main_Menu = GetMenu(main_Wnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HWND temp;

    HMENU hMenu;
    hMenu = GetMenu(hWnd);

    switch (message)
    {
    case WM_CREATE:
        {
            CheckMenuItem(hMenu, IDM_DBG_GRID_OFF, MF_CHECKED);
            CheckMenuItem(hMenu, IDM_DBG_LAYERS_ALL, MF_CHECKED);
        }
        break;
    case WM_GETMINMAXINFO:
        {
            LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
            lpMMI->ptMaxTrackSize.x = game->screenResX;
            lpMMI->ptMaxTrackSize.y = game->screenResY;
        }
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);

            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
            {
                DialogBox(game->hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            }
            case IDM_NEWGAME:
            {
                if (game->gameBoard->ready)
                {
                    int msgboxID = MessageBox(hWnd, L"Creating a new game will delete\nthe current game without saving.\nContinue?",
                        L"Create New Game", MB_ICONEXCLAMATION | MB_YESNO);

                    if (msgboxID == IDNO)
                        break;
                }

                temp = game->getMainWnd();
                game->deleteBoard();
                game->setMainWnd(temp);
                DialogBox(game->hInst, MAKEINTRESOURCE(IDD_NEWGAMEBOX), hWnd, NewGameWrapper);
                if (game->success)
                {
                    game->resetGameControls();
                    game->configGameScreens();
                    game->configSpread(*game->gameBoard);
                    game->initSpreadsheets();
                }
                RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                break;
            }
            case IDM_LOADGAME:
            {
                if (game->gameBoard->ready)
                {
                    int msgboxID = MessageBox(NULL, L"Loading a new game will delete\nthe current game without saving.\nContinue?",
                        L"Load New Game", MB_ICONEXCLAMATION | MB_YESNO);

                    if (msgboxID == IDNO)
                        break;
                }

                temp = game->getMainWnd();
                game->deleteBoard();
                game->setMainWnd(temp);
                game->configGameScreens();
                game->doLoadGame(hWnd, *game->gameBoard);
                if (game->success)
                {
                    game->whichScreen = NATION_SCREEN;
                    game->resetBoard();
                    game->configSpread(*game->gameBoard);
                    game->loadMiniSpreads();
                    game->loadSpreadsheets();
                    game->configGameScreens();
                }
                CheckMenuItem(hMenu, IDM_DBG_BOUNDBOX, MF_UNCHECKED);
                RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                break;
            }
            case IDM_SAVEGAME:
            {
                if (game->gameBoard->ready) // Can't save if there is no game
                    game->doSaveGame(hWnd, *game->gameBoard);
                break;
            }
            case IDB_INFUP:    case IDB_INFDN:    case IDB_ARTUP:  case IDB_ARTDN:  case IDB_MECHUP:  case IDB_MECHDN:  case IDB_TANKUP:  case IDB_TANKDN:  case IDB_AAAUP:case IDB_AAADN:case IDB_FIGHTUP:case IDB_FIGHTDN: case IDB_TACTUP: case IDB_TACTDN: case IDB_STRATUP:case IDB_STRATDN:
            case IDB_BATTLEUP: case IDB_BATTLEDN: case IDB_AIRCCUP:case IDB_AIRCCDN:case IDB_CRUISEUP:case IDB_CRUISEDN:case IDB_DESTRUP: case IDB_DESTRDN: case IDB_SUBUP:case IDB_SUBDN:case IDB_TRANSUP:case IDB_TRANSDN: case IDB_MAJORUP:case IDB_MAJORDN:case IDB_MINORUP:case IDB_MINORDN:
            case IDB_MINORUPUP:case IDB_MINORUPDN:case IDB_AIRBUP: case IDB_AIRBDN: case IDB_NAVBUP:  case IDB_NAVBDN:  case IDB_REPAIRUP:case IDB_REPAIRDN:
            {
                game->purchaseButton(hWnd, wmId);
                break;
            }
            case IDM_DBG_BOUNDBOX:
            {
                if (!game->dbg_boundbox)
                {
                    game->dbg_boundbox = true;
                    game->nsSection = ALL_SECT;
                }
                else
                {
                    game->dbg_boundbox = false;
                    game->nsSection = ALL_SECT;
                }
                game->debugSwitches();
                RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                break;
            }
            case IDM_DBG_GRID_OFF:
            {
                if (game->dbg_grid != 0)
                {
                    game->dbg_grid = 0;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_GRID_DIV2:
            {
                if (game->dbg_grid != 2)
                {
                    game->dbg_grid = 2;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_GRID_DIV3:
            {
                if (game->dbg_grid != 3)
                {
                    game->dbg_grid = 3;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_GRID_DIV4:
            {
                if (game->dbg_grid != 4)
                {
                    game->dbg_grid = 4;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_GRID_DIV5:
            {
                if (game->dbg_grid != 5)
                {
                    game->dbg_grid = 5;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_GRID_DIV8:
            {
                if (game->dbg_grid != 8)
                {
                    game->dbg_grid = 8;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_LAYERS_ALL:
            {
                if (game->dbg_layers != 99)
                {
                    game->dbg_layers = 99;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_LAYERS_0:
            {
                if (game->dbg_layers != 0)
                {
                    game->dbg_layers = 0;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_LAYERS_1:
            {
                if (game->dbg_layers != 1)
                {
                    game->dbg_layers = 1;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_LAYERS_2:
            {
                if (game->dbg_layers != 2)
                {
                    game->dbg_layers = 2;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_LAYERS_3:
            {
                if (game->dbg_layers != 3)
                {
                    game->dbg_layers = 3;
                    game->nsSection = ALL_SECT;
                    game->debugSwitches();
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                }
                break;
            }
            case IDM_DBG_SECTIONS:
            {
                if (!game->dbg_sections)
                {
                    game->dbg_sections = true;
                    game->nsSection = ALL_SECT;
                }
                else
                {
                    game->dbg_sections = false;
                    game->nsSection = ALL_SECT;
                }
                game->debugSwitches();
                RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                break;
            }
            case IDC_GRAPHSELECT:
            {
                if (game->graphSelectHandler(message, wParam, lParam) != game->getCurrGraph())
                    RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
                break;
            }
            case IDB_GERGRAPH: case IDB_SOVGRAPH: case IDB_JPNGRAPH: case IDB_USAGRAPH: case IDB_CHNGRAPH:
            case IDB_UKGRAPH:  case IDB_ITAGRAPH: case IDB_ANZGRAPH: case IDB_FRAGRAPH:
            {
                game->graphSelectNation(message, wParam, lParam, wmId);
                game->doUpdateGraph = true;
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
                break;
            }
            case IDB_CUSTLOG:
            {
                DialogBox(game->hInst, MAKEINTRESOURCE(IDD_CUSTLOGBOX), hWnd, CustomLogWrapper);
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
                break;
            }
            case IDM_EXIT:
            {
                delete game;
                DestroyWindow(hWnd);
                break;
            }
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }

            break;
        }
    case WM_NOTIFY:
    {
        switch (((LPNMHDR)lParam)->code)
        {
            case TCN_SELCHANGE:
            {
                int log = TabCtrl_GetCurSel(game->logScreenTabs);

                switch (game->gfx->tabs->getTabState(game->nationScreenTabs))
                {
                case TAB_MAIN:
                {
                    break;
                }
                case TAB_SPREAD_AXIS:
                    break;
                case TAB_SPREAD_ALLIES:
                    break;
                case TAB_GRAPH:
                    break;
                case TAB_LOG:
                    game->whichScreen = LOG_SCREEN;
                    game->whichTab = log;
                    RedrawWindow(hWnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE);
                    break;
                case TAB_RESEARCH:
                    break;
                case TAB_REFERENCE:
                    break;
                }
                break;
            }
        }
        break;
    }
    case WM_VSCROLL:
    {/*
        int xDelta = 0;
        int yDelta;     // yDelta = new_pos - current_pos 
        int yNewPos;    // new position 

        switch (LOWORD(wParam))
        {
            // User clicked the scroll bar shaft above the scroll box. 
        case SB_PAGEUP:
            yNewPos = yCurrentScroll - 50;
            break;

            // User clicked the scroll bar shaft below the scroll box. 
        case SB_PAGEDOWN:
            yNewPos = yCurrentScroll + 50;
            break;

            // User clicked the top arrow. 
        case SB_LINEUP:
            yNewPos = yCurrentScroll - 5;
            break;

            // User clicked the bottom arrow. 
        case SB_LINEDOWN:
            yNewPos = yCurrentScroll + 5;
            break;

            // User dragged the scroll box. 
        case SB_THUMBPOSITION:
            yNewPos = HIWORD(wParam);
            break;

        default:
            yNewPos = yCurrentScroll;*/
    }
        break;
    case WM_MOUSEMOVE:
    {
        game->handleMouseMove(hWnd, lParam);
        break;
    }
    case WM_LBUTTONDOWN:
    {
        game->handleMouseLeftDown(hWnd, lParam);
        break;
    }
    case WM_LBUTTONUP:
    {
        game->handleMouseLeftUp(hWnd, lParam);
        break;
    }
    case WM_TIMER:
    {
        switch (wParam)
        {
        case TT_SAMPLE_TIMER_ID:
        {
            game->gfx->tooltips->updateCurrPoint(hWnd, lParam, game->activeTooltip, game->deactivateTooltip);
            

            if (game->deactivateTooltip)
                RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
            break;
        }
        case TT_HOVER_TIMER_ID: // Tooltip hover timer
        {
            KillTimer(hWnd, TT_HOVER_TIMER_ID);

            game->activeTooltip = true;
            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);            
            break;
        }
        }
        break;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        game->graphics = new Graphics(hdc);

        if (game->gfx == NULL)
        {
            game->configGraphics(hdc);
            game->configGameScreens();
        }

        // Hide tooltip if necessary
        game->hideTooltip(hWnd, lParam);
        
        // Draw debug grid if enabled
        if (game->dbg_grid != 0)
            game->debugGrid->drawGrid(game->graphics, game->dbg_grid);

        // Main draw function
        switch (game->whichScreen)
        {
        case MAIN_SCREEN:
            game->MainScreen(hdc, ps, *game->gameBoard);
            break;
        case NATION_SCREEN:
            game->NationScreen(hdc, ps);
            game->nsSection = NO_SECT;
            break;
        case SPREAD0_SCREEN:
            game->configSpreadScreen();
            game->SpreadScreen(hWnd, hdc, ps, SIDE_AXIS);
            break;
        case SPREAD1_SCREEN:
            game->configSpreadScreen();
            game->SpreadScreen(hWnd, hdc, ps, SIDE_ALLIES);
            break;
        case GRAPH_SCREEN:
            game->configGraphScreen();
            game->GraphScreen(hdc);
            game->doUpdateGraph = false;
            break;
        case LOG_SCREEN:
            game->configLogScreen();
            game->LogScreen(hdc, game->whichTab);
            break;
        case RES_SCREEN:
            game->ResearchScreen(hWnd, hdc, ps);
            break;
        case REF_SCREEN:
            game->ReferenceScreen(hWnd, hdc, ps);
            break;
            break;
        default:
            game->MainScreen(hdc, ps, *game->gameBoard);
            break;
        }

        // Draw nation screen tabs
        if (game->whichScreen != MAIN_SCREEN)
            game->showTabBar(game->nationScreenTabs);

        // Draw tooltip if active
        game->drawTooltip(hWnd, lParam);

        delete game->graphics;
        EndPaint(hWnd, &ps);
    }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK NewGameWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->NewGame(hDlg, message, wParam, lParam, *game->gameBoard);
}

INT_PTR CALLBACK DeclareWarWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->DeclareWar(hDlg, message, wParam, lParam, *game->gameBoard);
}

INT_PTR CALLBACK CaptureTerritoryWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->CaptureTerritory(hDlg, message, wParam, lParam);
}

INT_PTR CALLBACK ResearchWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->ResearchF(hDlg, message, wParam, lParam);
}

INT_PTR CALLBACK ResearchResWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->ResearchRes(hDlg, message, wParam, lParam);
}

INT_PTR CALLBACK ResearchUKWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->ResearchUK(hDlg, message, wParam, lParam);
}

INT_PTR CALLBACK WarBondWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->WarBonds(hDlg, message, wParam, lParam);
}

INT_PTR CALLBACK CustomLogWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->CustomLog(hDlg, message, wParam, lParam);
}

INT_PTR CALLBACK OccupyNeutralWrapper(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    return game->OccupyNeutral(hDlg, message, wParam, lParam);
}