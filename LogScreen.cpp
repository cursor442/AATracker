// Handle the log screen of the application

#include "AA_Tracker.h"

void quickConv(int, TCHAR*, TCHAR*);

void Game::configLogScreen()
{
	uint16_t type = gameBoard->getGameType();

	if (gameLog == NULL)
		gameLog = new Log(type, nationScreenWindow);

	// Config tabs
	if (logScreenTabs == NULL)
	{
		logScreenTabs = CreateWindow(
			WC_TABCONTROL,
			L"",
			WS_CHILD | WS_CLIPSIBLINGS,
			0,
			24,
			62, //117, 174, 231, 288, 345, 402, 459, 516, 581
			23,
			main_Wnd,
			NULL,
			hInst,
			NULL);

		TCITEM tie;
		TCHAR achTemp[8];
		for (int i = 0; i < 7; i++)
			achTemp[i] = ' ';
		achTemp[7] = '\0';

		tie.mask = TCIF_TEXT | TCIF_IMAGE;
		tie.iImage = -1;
		tie.pszText = achTemp;

		// Page 1
		achTemp[0] = 'P'; achTemp[1] = 'a'; achTemp[2] = 'g'; achTemp[3] = 'e'; achTemp[4] = ' ';
		achTemp[5] = '1'; achTemp[6] = '\0';
		tie.pszText = achTemp;
		if (TabCtrl_InsertItem(logScreenTabs, 0, &tie) == -1)
			DestroyWindow(logScreenTabs);

		customLogButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"Custom Log Entry",                                   // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			TURNWIDTH + TEXTWIDTH + 5 -128,                        // x position 
			2,                                                     // y position 
			128,                                                   // Button width
			24,                                                    // Button height
			main_Wnd,                                              // Parent window
			(HMENU)IDB_CUSTLOG,                                    // Menu.
			(HINSTANCE)GetWindowLongPtr(main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
}

void Game::LogScreen(HDC& hdc, UINT _page)
{
	hideScreen();

	ShowWindow(logScreenTabs, SW_SHOW);
	ShowWindow(customLogButton, SW_SHOW);

	gameLog->drawPage(hdc, (int)_page);

	int page = 0;
	page = gameLog->getNewPage();

	for (int i = nextPage; i <= page; i++)
		addLogTab(i);
}

void Game::addLogTab(int page)
{
	int p = page - 1;

	TCITEM tie;
	TCHAR achTemp[8];
	for (int i = 0; i < 7; i++)
		achTemp[i] = ' ';
	achTemp[7] = '\0';

	tie.mask = TCIF_TEXT | TCIF_IMAGE;
	tie.iImage = -1;
	tie.pszText = achTemp;

	achTemp[0] = 'P'; achTemp[1] = 'a'; achTemp[2] = 'g'; achTemp[3] = 'e'; achTemp[4] = ' ';
	quickConv(page, &achTemp[5], &achTemp[6]);
	tie.pszText = achTemp;
	if (TabCtrl_InsertItem(logScreenTabs, p, &tie) == -1)
		DestroyWindow(logScreenTabs);

	int rights[11] = {0, 62, 117, 174, 231, 288, 345, 402, 459, 516, 581 };
	MoveWindow(logScreenTabs, 0, 24, rights[page], 23, NULL);

	nextPage = page + 1;
}

void Game::hideLogScreen()
{
	ShowWindow(logScreenTabs, SW_HIDE);
	ShowWindow(customLogButton, SW_HIDE);
}

void Game::destroyLogScreen()
{
	if (gameLog != NULL)
		delete gameLog;
	gameLog = NULL;

	hideLogScreen();

	for (int i = nextPage; i >= 1; i--)
		TabCtrl_DeleteItem(logScreenTabs, i);
	MoveWindow(logScreenTabs, 0, 24, 62, 23, NULL);

	nextPage = 2;
}

void quickConv(int page, TCHAR* c0, TCHAR* c1)
{
	switch (page)
	{
	case 2:
		*c0 = '2'; *c1 = '\0';
		break;
	case 3:
		*c0 = '3'; *c1 = '\0';
		break;
	case 4:
		*c0 = '4'; *c1 = '\0';
		break;
	case 5:
		*c0 = '5'; *c1 = '\0';
		break;
	case 6:
		*c0 = '6'; *c1 = '\0';
		break;
	case 7:
		*c0 = '7'; *c1 = '\0';
		break;
	case 8:
		*c0 = '8'; *c1 = '\0';
		break;
	case 9:
		*c0 = '9'; *c1 = '\0';
		break;
	case 10:
		*c0 = '1'; *c1 = '0';
		break;
	case 11:
		*c0 = '1'; *c1 = '1';
		break;
	case 12:
		*c0 = '1'; *c1 = '2';
		break;
	case 13:
		*c0 = '1'; *c1 = '3';
		break;
	case 14:
		*c0 = '1'; *c1 = '4';
		break;
	case 15:
		*c0 = '1'; *c1 = '5';
		break;
	case 16:
		*c0 = '1'; *c1 = '6';
		break;
	case 17:
		*c0 = '1'; *c1 = '7';
		break;
	case 18:
		*c0 = '1'; *c1 = '8';
		break;
	case 19:
		*c0 = '1'; *c1 = '9';
		break;
	case 20:
		*c0 = '2'; *c1 = '0';
		break;
	default:
		*c0 = '1'; *c1 = ' ';
		break;
	}
}
