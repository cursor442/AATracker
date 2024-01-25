#include "../../game/header/AA_Tracker.h"

void quickConv(int, char*, char*);

void Game::LogScreen(HDC& hdc, UINT _page)
{
	hideScreen(true);

	int page = 0;
	page = gameLog->getNewPage();

	for (int i = nextPage; i <= page; i++)
		addLogTab(i);

	showTabBar(nationScreenTabs);
	showTabBar(logScreenTabs);
	showButton(customLogButton);

	gameLog->drawPage(hdc, (int)_page);

	for (int i = 0; i < logSections.size(); i++)
	{
		logSections[i]->drawLogBox(graphics, dbg);
	}
}

void Game::addLogTab(int page)
{
	char str[8] = "Page  \0";
	quickConv(page, &str[5], &str[6]);

	gfx->tabs->activateTab(logScreenTabs);
	gfx->tabs->addTab(graphics, logScreenTabs, str, logScreenHandlePageTab);
	gfx->tabs->setTabFuncId(logScreenTabs, page - 1, page - 1);
	gfx->tabs->hideTab(logScreenTabs, graphics);
	gfx->tabs->deactivateTab(logScreenTabs);

	nextPage = page + 1;
}

void Game::hideLogScreen()
{
	hideTabBar(logScreenTabs);
	hideButton(customLogButton);
}

void Game::destroyLogScreen(bool destroyTabBar)
{
	if (gameLog != NULL)
		delete gameLog;
	gameLog = NULL;

	hideLogScreen();

	nextPage = 2;

	// Only totally delete the log screen tab bar if closing application
	// Otherwise just delete all tabs aside from the first
	if (logScreenTabs != TB_ID_NULL)
	{
		if (destroyTabBar)
		{
			gfx->tabs->deleteTabBar(logScreenTabs);
			logScreenTabs = TB_ID_NULL;
		}
		else
		{
			int cnt = gfx->tabs->getTabBarTabs(logScreenTabs);
			if (cnt > 1)
			{
				for (int i = cnt - 1; i > 0; i--)
				{
					gfx->tabs->deleteTab(graphics, logScreenTabs, i);
				}
			}
		}
	}
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
