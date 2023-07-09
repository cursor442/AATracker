#include "../../game/header/AA_Tracker.h"

void quickConv(int, char*, char*);

void Game::configLogScreen()
{
	uint16_t type = gameBoard->getGameType();

	if (gameLog == NULL)
		gameLog = new Log(type, nationScreenWindow);

	// Config Tabs
	if (logScreenTabs == TB_ID_NULL)
	{
		logScreenTabs = gfx->tabs->createTabId();

		RectF rect = { 0, 24, 750, 24 };

		gfx->tabs->registerTab(graphics, logScreenTabs, NATION_SCREEN, TB_CFG_LEFT, TB_ORT_UP, rect, "Log Screen Tabs", false, false);
		gfx->tabs->activateTab(logScreenTabs);
		gfx->tabs->addTab(graphics, logScreenTabs, "Page 1", logScreenHandlePageTab);
		gfx->tabs->setTabFuncId(logScreenTabs, 0, 0);
		gfx->tabs->deactivateTab(logScreenTabs);
	}

	// Config custom log button
	if (customLogButton == BB_ID_NULL)
	{
		customLogButton = gfx->buttons->createButtonId();

		RectF rect = { TURNWIDTH + TEXTWIDTH + 5 - 128, 2, 164, 24 };
		gfx->buttons->registerButton(graphics, customLogButton, NATION_SCREEN, PHASE_SECT, rect, "Custom Log Entry", logScreenHandleCustomEntry);
	}
}

void Game::LogScreen(HDC& hdc, UINT _page)
{
	hideScreen();

	showTabBar(logScreenTabs);
	showButton(customLogButton);

	gameLog->drawPage(hdc, (int)_page);

	int page = 0;
	page = gameLog->getNewPage();

	for (int i = nextPage; i <= page; i++)
		addLogTab(i);
}

void Game::addLogTab(int page)
{
	char str[8] = "Page  \0";
	quickConv(page, &str[5], &str[6]);

	gfx->tabs->activateTab(logScreenTabs);
	gfx->tabs->addTab(graphics, logScreenTabs, str, logScreenHandlePageTab);
	gfx->tabs->setTabFuncId(logScreenTabs, page - 1, page - 1);
	gfx->tabs->deactivateTab(logScreenTabs);

	nextPage = page + 1;
}

void Game::hideLogScreen()
{
	hideTabBar(logScreenTabs);
	hideButton(customLogButton);
}

void Game::destroyLogScreen()
{
	if (gameLog != NULL)
		delete gameLog;
	gameLog = NULL;

	hideLogScreen();

	nextPage = 2;
}


void quickConv(int page, char* c0, char* c1)
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
