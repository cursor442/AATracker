#include "../../game/header/AA_Tracker.h"

// Full configuration of the log screen
// Cannot be split
// Should only be called once
void Game::configLogScreen()
{
	uint16_t type = gameBoard->getGameType();

	if (screenFrames.s.size() < (LOG_SCREEN + 1))
		screenFrames.s.resize((LOG_SCREEN + 1));

	if (gameLog == NULL)
		gameLog = new Log(type, nationScreenWindow);

	// Log sections
	{
		if (logSections.size() == 0)
		{
			logSections.resize(LOG_COLS);
			logFrame.resize(LOG_COLS);
			for (int i = 0; i < LOG_COLS; i++)
				logSections[i] = NULL;
		}

		for (int i = 0; i < logSections.size(); i++)
		{
			if (logSections[i] == NULL)
			{
				logSections[i] = new LogSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
					gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
				logSections[i]->configDrawTools();

				logFrame[i] = nationScreenWindow0;
				logFrame[i].Width *= (1 / (REAL)logSections.size());
				logFrame[i].Inflate(-24, -36);
				logFrame[i].X += (i * (nationScreenWindow0.Width / logSections.size()));
				logSections[i]->configureLogBox(logFrame[i], 1, i, gameLog);

				if (screenFrames.s[LOG_SCREEN].f.size() < (i + 1))
				{
					screenFrames.s[LOG_SCREEN].f.resize(i + 1);
					screenFrames.s[LOG_SCREEN].b.resize(i + 1);
				}
				screenFrames.s[LOG_SCREEN].f[i] = logFrame[i];
				screenFrames.s[LOG_SCREEN].b[i] = LOG_LEFT_SECT << i;
			}
		}
	}

	// Config Tabs
	if (logScreenTabs == TB_ID_NULL)
	{
		logScreenTabs = gfx->tabs->createTabId();

		RectF rect = { 0, 24, 750, 24 };

		gfx->tabs->registerTab(graphics, logScreenTabs, LOG_SCREEN, TB_CFG_LEFT, TB_ORT_UP, rect, "Log Screen Tabs", false, false);
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
		gfx->buttons->registerButton(graphics, customLogButton, LOG_SCREEN, LOG_LEFT_SECT_IDX, rect, "Custom Log Entry", logScreenHandleCustomEntry);
	}
}