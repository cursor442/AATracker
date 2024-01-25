#include "../../game/header/AA_Tracker.h"

TCHAR graphOpts[NUM_GRAPHS][32] =
{ L"Select a metric to graph",
  L"Nation Bank",        L"Nation Income",          L"Nation Bonus",       L"Nation Territories", 
  L"Side Total Income",  L"Side Total Territories", L"Side Victory Cities",L"Nation Purchases" };

uint16_t xPos = 25;
uint16_t xWidth = 200;
uint16_t boxSize = 16, boxGap = 4;
uint16_t yPos[9] = { 155, 215, 275, 335, 395, 455, 515, 575, 635 };
uint16_t yHeight = 14;
uint16_t lineWidth = 4;

RECT graphPane = { 300, 50, 1511, 706 };

void Game::configGraphScreen()
{
	uint16_t type = gameBoard->getGameType();

	if (!graphConfigured)
	{
		graphs[BLNK_GRAPH] = new Graph(BLNK_GRAPH, graphPane, type);

		if (graphSelect == NULL)
		{
			graphSelect = CreateWindow(
				L"COMBOBOX",                                           // Predefined class; Unicode assumed 
				L"Graph Options",                                      // Button text 
				WS_TABSTOP | WS_VSCROLL | WS_CHILD | BS_GROUPBOX,      // Styles 
				25,                                                    // x position 
				50,                                                    // y position 
				200,                                                   // Combobox width
				196,                                                   // Combobox height
				main_Wnd,                                              // Parent window
				(HMENU)IDC_GRAPHSELECT,                                // Menu.
				(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
				NULL);
		}

		uint16_t idx = 0;

		// Nation checkboxes
		{
			// Germany
			if ((type == EUROPE_GAME || type == GLOBAL_GAME))
			{
				if (gerGraph == NULL)
				{
					gerGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"Germany Graph",                                      // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_GERGRAPH,                                   // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(gerGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_GERGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_GER;
				idx++;
			}
			// Soviet Union
			if ((type == EUROPE_GAME || type == GLOBAL_GAME))
			{
				if (sovGraph == NULL)
				{
					sovGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"Soviet Graph",                                       // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_SOVGRAPH,                                   // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(sovGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_SOVGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_SOV;
				idx++;
			}
			// Japan
			if ((type == PACIFIC_GAME || type == GLOBAL_GAME))
			{
				if (jpnGraph == NULL)
				{
					jpnGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"Japan Graph",                                        // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_JPNGRAPH,                                   // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(jpnGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_JPNGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_JPN;
				idx++;
			}
			// United States
			{
				if (usaGraph == NULL)
				{
					usaGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"United States Graph",                                // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_USAGRAPH,                                   // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(usaGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_USAGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_USA;
				idx++;
			}
			// China
			if ((type == PACIFIC_GAME || type == GLOBAL_GAME))
			{
				if (chnGraph == NULL)
				{
					chnGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"China Graph",                                        // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_CHNGRAPH,                                   // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(chnGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_CHNGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_CHN;
				idx++;
			}
			// United Kingdom
			{
				if (ukGraph == NULL)
				{
					ukGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"United Kingdom Graph",                               // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_UKGRAPH,                                    // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(ukGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_UKGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_UKE + GRAPH_UKP;
				idx++;
			}
			// Italy
			if ((type == EUROPE_GAME || type == GLOBAL_GAME))
			{
				if (itaGraph == NULL)
				{
					itaGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"Italy Graph",                                        // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_ITAGRAPH,                                   // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(itaGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_ITAGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_ITA;
				idx++;
			}
			// ANZAC
			if ((type == PACIFIC_GAME || type == GLOBAL_GAME))
			{
				if (anzGraph == NULL)
				{
					anzGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"ANZAC Graph",                                        // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_ANZGRAPH,                                   // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(anzGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_ANZGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_ANZ;
				idx++;
			}
			// France
			if ((type == EUROPE_GAME || type == GLOBAL_GAME))
			{
				if (fraGraph == NULL)
				{
					fraGraph = CreateWindow(
						L"BUTTON",                                             // Predefined class; Unicode assumed 
						L"France Graph",                                       // Button text 
						WS_TABSTOP | WS_CHILD | BS_CHECKBOX,                   // Styles 
						xPos,                                                  // x position 
						yPos[idx],                                             // y position 
						boxSize,                                               // Checkbox width
						boxSize,                                               // Checkbox height
						main_Wnd,                                              // Parent window
						(HMENU)IDB_FRAGRAPH,                                   // Menu.
						(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
						NULL);
				}
				else
					SetWindowPos(fraGraph, main_Wnd, xPos, yPos[idx], boxSize, boxSize, SWP_NOZORDER);

				CheckDlgButton(main_Wnd, IDB_FRAGRAPH, BST_CHECKED);
				currGraphNats += GRAPH_FRA;
			}
		}

		for (uint16_t idx = 0; idx < 9; idx++)
		{
			checkLines[idx].left = xPos;
			checkLines[idx].top = yPos[idx] + boxSize + boxGap;
			checkLines[idx].right = checkLines[idx].left + xWidth;
			checkLines[idx].bottom = checkLines[idx].top + lineWidth;

			checkNations[idx].left = xPos + boxSize + boxGap;
			checkNations[idx].top = yPos[idx] - yHeight;
			checkNations[idx].right = checkLines[idx].right;
			checkNations[idx].bottom = yPos[idx] + boxSize;
		}

        TCHAR  ListItem[32];
        TCHAR  A[32];
		{
			for (n = 0; n < 32; n++)
				ListItem[n] = '\0';

			memset(&A, 0, sizeof(A));

			k = 0;
			wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)graphOpts[0]);
			for (n = 0; n < NUM_GRAPHS; n++)
			{
				wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)graphOpts[n]);
				SendMessage(graphSelect, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
				SendMessage(graphSelect, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
			}
		}

		graphConfigured = true;
	}
	else
	{
		if (graphs[currGraph] == NULL)
			graphs[currGraph] = new Graph(currGraph, graphPane, type);
	}
}

void Game::GraphScreen(HDC& hdc)
{
	uint16_t type = gameBoard->getGameType();
	uint16_t idx = 0;

	if (!doUpdateGraph)
	{
		hideScreen();

		graphs[currGraph]->drawGraph(hdc, *gameBoard, currGraphNats);
	}
	else
		graphs[currGraph]->updateGraph(hdc, updateNatGraph, whichUpdateNatGraph, currGraphNats);

	if (!dbg.boundbox)
		hPen = (HPEN)SelectObject(hdc, borderless);
	else
		hPen = (HPEN)SelectObject(hdc, bordered);
	hFont = (HFONT)SelectObject(hdc, descrFont);

	SetBkMode(hdc, TRANSPARENT);

	ShowWindow(graphSelect, SW_SHOW);

	// Nation checkboxes
	{
		// Germany
		if (type == EUROPE_GAME || type == GLOBAL_GAME)
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"Germany", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_GER) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, gerBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, gerBrushF);
			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(gerGraph, SW_SHOW);

			idx++;
		}
		// Soviet Union
		if (type == EUROPE_GAME || type == GLOBAL_GAME)
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"Soviet Union", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_SOV) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, sovBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, sovBrushF);

			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(sovGraph, SW_SHOW);

			idx++;
		}
		// Japan
		if (type == PACIFIC_GAME || type == GLOBAL_GAME)
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"Japan", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_JPN) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, jpnBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, jpnBrushF);

			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(jpnGraph, SW_SHOW);

			idx++;
		}
		// United States
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"United States", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_USA) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, usaBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, usaBrushF);

			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(usaGraph, SW_SHOW);

			idx++;
		}
		// China
		if (type == PACIFIC_GAME || type == GLOBAL_GAME)
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"China", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_CHN) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, chnBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, chnBrushF);

			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(chnGraph, SW_SHOW);

			idx++;
		}
		// United Kingdom
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"United Kingdom", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_UKE) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, ukBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, ukBrushF);

			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(ukGraph, SW_SHOW);

			idx++;
		}
		// Italy
		if (type == EUROPE_GAME || type == GLOBAL_GAME)
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"Italy", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_ITA) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, itaBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, itaBrushF);

			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(itaGraph, SW_SHOW);

			idx++;
		}
		// ANZAC
		if (type == PACIFIC_GAME || type == GLOBAL_GAME)
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"ANZAC", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_ANZ) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, anzBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, anzBrushF);

			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(anzGraph, SW_SHOW);

			idx++;
		}
		// France
		if (type == EUROPE_GAME || type == GLOBAL_GAME)
		{
			hBrush = (HBRUSH)SelectObject(hdc, backBrush0);

			Rectangle(hdc, checkNations[idx].left, checkNations[idx].top, checkNations[idx].right, checkNations[idx].bottom);
			DrawText(hdc, L"France", -1, &checkNations[idx], DT_LEFT | DT_SINGLELINE);

			if ((currGraphNats & GRAPH_FRA) != 0)
				hBrush = (HBRUSH)SelectObject(hdc, fraBrushP);
			else
				hBrush = (HBRUSH)SelectObject(hdc, fraBrushF);

			Rectangle(hdc, checkLines[idx].left, checkLines[idx].top, checkLines[idx].right, checkLines[idx].bottom);

			ShowWindow(fraGraph, SW_SHOW);
		}
	}
}

uint16_t Game::graphSelectHandler(UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR  ListItem[32];
    WPARAM ItemIndex;

	uint16_t prevGraph = currGraph;

	for (n = 0; n < 32; n++)
		ListItem[n] = '\0';

    if (message == WM_COMMAND)
    {
        if (HIWORD(wParam) == CBN_SELCHANGE && LOWORD(wParam) == IDC_GRAPHSELECT)
        {
            ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
                (WPARAM)0, (LPARAM)0);

            (TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
                (WPARAM)ItemIndex, (LPARAM)ListItem);

            for (k = 0; k < NUM_GRAPHS; k++)
            {
                if (_tcscmp(ListItem, graphOpts[k]) == 0)
                    break;
            }

            currGraph = k;
        }
    }

	return prevGraph;
}

uint16_t Game::getCurrGraph()
{
	return currGraph;
}

void Game::graphSelectNation(UINT message, WPARAM wParam, LPARAM lParam, uint16_t wmId)
{
	switch (wmId)
	{
	case IDB_GERGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_GERGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_GERGRAPH, BST_UNCHECKED);
			currGraphNats -= GRAPH_GER;

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_GERGRAPH, BST_CHECKED);
			currGraphNats += GRAPH_GER;

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_GER;
	}
	break;
	case IDB_SOVGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_SOVGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_SOVGRAPH, BST_UNCHECKED);
			currGraphNats -= GRAPH_SOV;

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_SOVGRAPH, BST_CHECKED);
			currGraphNats += GRAPH_SOV;

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_SOV;
	}
	break;
	case IDB_JPNGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_JPNGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_JPNGRAPH, BST_UNCHECKED);
			currGraphNats -= GRAPH_JPN;

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_JPNGRAPH, BST_CHECKED);
			currGraphNats += GRAPH_JPN;

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_JPN;
	}
	break;
	case IDB_USAGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_USAGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_USAGRAPH, BST_UNCHECKED);
			currGraphNats -= GRAPH_USA;

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_USAGRAPH, BST_CHECKED);
			currGraphNats += GRAPH_USA;

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_USA;
	}
	break;
	case IDB_CHNGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_CHNGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_CHNGRAPH, BST_UNCHECKED);
			currGraphNats -= GRAPH_CHN;

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_CHNGRAPH, BST_CHECKED);
			currGraphNats += GRAPH_CHN;

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_CHN;
	}
	break;
	case IDB_UKGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_UKGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_UKGRAPH, BST_UNCHECKED);
			currGraphNats -= (GRAPH_UKE + GRAPH_UKP);

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_UKGRAPH, BST_CHECKED);
			currGraphNats += (GRAPH_UKE + GRAPH_UKP);

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_UKE;
	}
	break;
	case IDB_ITAGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_ITAGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_ITAGRAPH, BST_UNCHECKED);
			currGraphNats -= GRAPH_ITA;

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_ITAGRAPH, BST_CHECKED);
			currGraphNats += GRAPH_ITA;

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_ITA;
	}
	break;
	case IDB_ANZGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_ANZGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_ANZGRAPH, BST_UNCHECKED);
			currGraphNats -= GRAPH_ANZ;

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_ANZGRAPH, BST_CHECKED);
			currGraphNats += GRAPH_ANZ;

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_ANZ;
	}
	break;
	case IDB_FRAGRAPH:
	{
		if (IsDlgButtonChecked(main_Wnd, IDB_FRAGRAPH))
		{
			CheckDlgButton(main_Wnd, IDB_FRAGRAPH, BST_UNCHECKED);
			currGraphNats -= GRAPH_FRA;

			whichUpdateNatGraph = false;
		}
		else
		{
			CheckDlgButton(main_Wnd, IDB_FRAGRAPH, BST_CHECKED);
			currGraphNats += GRAPH_FRA;

			whichUpdateNatGraph = true;
		}

		updateNatGraph = TURN_FRA;
	}
	break;
	default:
		break;
	}
}

void Game::hideGraphScreen()
{
	ShowWindow(graphSelect, SW_HIDE);

	ShowWindow(gerGraph, SW_HIDE); ShowWindow(sovGraph, SW_HIDE); ShowWindow(jpnGraph, SW_HIDE);
	ShowWindow(usaGraph, SW_HIDE); ShowWindow(chnGraph, SW_HIDE); ShowWindow(ukGraph, SW_HIDE);
	ShowWindow(itaGraph, SW_HIDE); ShowWindow(anzGraph, SW_HIDE); ShowWindow(fraGraph, SW_HIDE);
}

void Game::destroyGraphScreen()
{
	for (int i = 0; i < NUM_GRAPHS; i++)
	{
		if (graphs[i] != NULL)
		{
			delete graphs[i];
			graphs[i] = NULL;
		}
	}

	ShowWindow(graphSelect, SW_HIDE);
	ShowWindow(gerGraph, SW_HIDE); ShowWindow(sovGraph, SW_HIDE); ShowWindow(jpnGraph, SW_HIDE);
	ShowWindow(usaGraph, SW_HIDE); ShowWindow(chnGraph, SW_HIDE); ShowWindow(ukGraph, SW_HIDE);
	ShowWindow(itaGraph, SW_HIDE); ShowWindow(anzGraph, SW_HIDE); ShowWindow(fraGraph, SW_HIDE);

	DeleteObject(graphSelect);

	graphSelect = NULL;
}

