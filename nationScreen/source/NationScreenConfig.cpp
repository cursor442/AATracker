#include "../../game/header/AA_Tracker.h"

// Full configuration of the nation screen
// Cannot be split
// Should only be called once
void Game::configNationScreen()
{
	int gameType = gameBoard->getGameType();

	if (screenFrames.s.size() < (NATION_SCREEN + 1))
		screenFrames.s.resize((NATION_SCREEN + 1));
	
	// Tabs section

	if (nationScreenTabs == TB_ID_NULL)
	{
		nationScreenTabs = gfx->tabs->createTabId();
		
		RectF rect = { 0, 0, 700, 23 };
		gfx->tabs->registerTab(graphics, nationScreenTabs, NATION_SCREEN, TB_CFG_EVEN, TB_ORT_UP, rect, "Nation Screen Tabs", true, false);

		gfx->tabs->activateTab(nationScreenTabs);
		gfx->tabs->addTab(graphics, nationScreenTabs, "Main", nationScreenHandleMainScreenTab);
		gfx->tabs->addTab(graphics, nationScreenTabs, "Axis Spread", nationScreenHandleAxisSpreadScreenTab);
		gfx->tabs->addTab(graphics, nationScreenTabs, "Allies Spread", nationScreenHandleAlliesSpreadScreenTab);
		gfx->tabs->addTab(graphics, nationScreenTabs, "Graphs", nationScreenHandleGraphScreenTab);
		gfx->tabs->addTab(graphics, nationScreenTabs, "Game Log", nationScreenHandleLogScreenTab);
		gfx->tabs->addTab(graphics, nationScreenTabs, "Research", nationScreenHandleResearchScreenTab);
		gfx->tabs->addTab(graphics, nationScreenTabs, "Reference", nationScreenHandleReferenceScreenTab);
		gfx->tabs->deactivateTab(nationScreenTabs);
	}
	
	// Name section
	if (nameSection == NULL)
	{
		nameSection = new NameSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		nameSection->configDrawTools(gfx->font64_b, gfx->font24);

		nameFrame = nationScreenWindow0;
		nameFrame.Inflate(0, -24);
		nameFrame.Width += 6;
		nameFrame.Height += 36;
		nameFrame.Width -= (14 * nationScreenWindow0.Width / 20);
		nameFrame.Height -= (7 * nationScreenWindow0.Height / 8);
		nameSection->configureNameBox(nameFrame, 1);

		if (screenFrames.s[NATION_SCREEN].f.size() < (NAME_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(NAME_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(NAME_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[NAME_SECT_IDX] = nameFrame;
		screenFrames.s[NATION_SCREEN].b[NAME_SECT_IDX] = NAME_SECT;
	}

	// Turn phase section
	if (phaseSection == NULL)
	{
		phaseSection = new PhaseSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		phaseSection->configDrawTools(gfx->font18);
		phaseSection->configBrushes0(gfx->resBrushP, gfx->purchBrushP, gfx->cmBrushP, gfx->ccBrushP, gfx->ncBrushP, gfx->mobBrushP, gfx->incBrushP);
		phaseSection->configBrushes1(gfx->resBrushS, gfx->purchBrushS, gfx->cmBrushS, gfx->ccBrushS, gfx->ncBrushS, gfx->mobBrushS, gfx->incBrushS);

		phaseFrame = nationScreenWindow0;
		phaseFrame.X = (3 * nationScreenWindow0.Width / 8);
		phaseFrame.Width = (nationScreenWindow0.Width / 2) - phaseFrame.X;
		phaseFrame.Height = nationScreenWindow0.Height / 4;
		phaseFrame.Inflate(-18, -24);
		phaseFrame.X += 6;
		phaseSection->configurePhaseBox(phaseFrame, 1);

		if (screenFrames.s[NATION_SCREEN].f.size() < (PHASE_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(PHASE_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(PHASE_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[PHASE_SECT_IDX] = phaseFrame;
		screenFrames.s[NATION_SCREEN].b[PHASE_SECT_IDX] = PHASE_SECT;
	}

	// War with section
	if (warSection == NULL)
	{
		warSection = new WarSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		warSection->configDrawTools(gfx->redBrush, gfx->font20_b, gfx->font12_b);
		warSection->configNationBrushesP(gfx->gerBrushP, gfx->sovBrushP, gfx->jpnBrushP, gfx->usaBrushP, gfx->chnBrushP, gfx->ukBrushP, 
			gfx->itaBrushP, gfx->anzBrushP, gfx->fraBrushP);
		warSection->configNationBrushesF(gfx->gerBrushF, gfx->sovBrushF, gfx->jpnBrushF, gfx->usaBrushF, gfx->chnBrushF, gfx->ukBrushF,
			gfx->itaBrushF, gfx->anzBrushF, gfx->fraBrushF);

		warFrame = phaseFrame;
		warFrame.Y = phaseFrame.GetBottom() + 12;
		warFrame.Height = (3 * nationScreenWindow0.Height / 8) - warFrame.Y - 36;
		warSection->configureWarBox(warFrame, 1);

		if (screenFrames.s[NATION_SCREEN].f.size() < (WAR_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(WAR_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(WAR_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[WAR_SECT_IDX] = warFrame;
		screenFrames.s[NATION_SCREEN].b[WAR_SECT_IDX] = WAR_SECT;
	}

	// Cities section
	if (citiesSection == NULL)
	{
		citiesSection = new CitiesSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		citiesSection->configDrawTools(gfx->font20_b, gfx->font18_b, gfx->font16_b, gfx->font14, gfx->font14_b);
		citiesSection->configNationBrushesP(gfx->gerBrushP, gfx->sovBrushP, gfx->jpnBrushP, gfx->usaBrushP, gfx->chnBrushP, gfx->ukBrushP,
			gfx->itaBrushP, gfx->anzBrushP, gfx->fraBrushP);
		citiesSection->configNationBrushesF(gfx->gerBrushF, gfx->sovBrushF, gfx->jpnBrushF, gfx->usaBrushF, gfx->chnBrushF, gfx->ukBrushF,
			gfx->itaBrushF, gfx->anzBrushF, gfx->fraBrushF);

		cityFrame = nationScreenWindow0;
		cityFrame.Width = phaseFrame.GetLeft() + 12;
		cityFrame.Inflate(-24, -24);
		//cityFrame.Y = phaseFrame.GetBottom();
		cityFrame.Y = phaseSection->getBoxEdge(MN_PHASE, BOX_TOP);
		cityFrame.Height = warFrame.GetBottom() - cityFrame.Y;

		cityFrameR = cityFrame;
		cityFrameR.X = cityFrame.X + (2 * cityFrame.Width / 3);
		cityFrameR.Width = cityFrame.GetRight() - cityFrameR.X;

		cityFrameL.X = cityFrame.X;
		cityFrameL.Width = cityFrameR.X - cityFrameL.X;
		cityFrameL.Y = cityFrame.Y + (2 * cityFrame.Height / 5);
		cityFrameL.Height = cityFrame.GetBottom() - cityFrameL.Y;

		citiesSection->configureCityBox(cityFrameL, cityFrameR, 1);

		if (screenFrames.s[NATION_SCREEN].f.size() < (CITY_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(CITY_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(CITY_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[CITY_SECT_IDX] = cityFrame;
		screenFrames.s[NATION_SCREEN].b[CITY_SECT_IDX] = CITY_SECT;

	}

	// Game status section
	if (statusSection == NULL)
	{
		statusSection = new StatusSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		statusSection->configDrawTools(gfx->leftTopFormat, gfx->font17);

		statusFrame = cityFrameL;
		statusFrame.X -= 5;
		statusFrame.Width += 50;
		statusFrame.Y = cityFrameR.Y;
		statusFrame.Height = cityFrameL.Y - cityFrameR.Y;
		statusSection->configureStatusBox(statusFrame, 1);

		if (screenFrames.s[NATION_SCREEN].f.size() < (STAT_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(STAT_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(STAT_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[STAT_SECT_IDX] = statusFrame;
		screenFrames.s[NATION_SCREEN].b[STAT_SECT_IDX] = STAT_SECT;
	}
	
	// Purchase section
	if (purchaseSection == NULL)
	{
		purchaseSection = new PurchaseSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		purchaseSection->configDrawTools(gfx->backPen, gfx->purchaseFormat, gfx->font18_b, gfx->font18, gfx->tileBrushL, gfx->tileBrushD, gfx->clearBrush);

		purchaseFrame = nationScreenWindow0;
		purchaseFrame.Width = 2 * nationScreenWindow0.Width / 5 + 48;
		purchaseFrame.Y = cityFrame.GetBottom();
		purchaseFrame.Height = nationScreenWindow0.GetBottom() - purchaseFrame.Y;
		purchaseFrame.Inflate(-24, -24);
		purchaseSection->configurePurchaseBox(graphics, main_Wnd, purchaseFrame, gfx->buttons, purchaseButton, 1);
		purchaseSection->configPurchaseBoxFunctions(showButton, hideButton);

		if (screenFrames.s[NATION_SCREEN].f.size() < (PURCH_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(PURCH_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(PURCH_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[PURCH_SECT_IDX] = purchaseFrame;
		screenFrames.s[NATION_SCREEN].b[PURCH_SECT_IDX] = PURCH_SECT;
	}

	// Purchase section tabs
	if (purchaseSectionTabs == NULL)
	{
		purchaseSectionTabs = CreateWindow(
			WC_TABCONTROL,
			L"",
			WS_CHILD | WS_CLIPSIBLINGS | TCS_FLATBUTTONS | TCS_RAGGEDRIGHT |
			TCS_MULTILINE | TCS_RIGHT | TCS_VERTICAL,
			purchaseFrame.GetRight() + 1,
			purchaseFrame.Y + 12,
			24,
			purchaseSection->getBoxEdge(PURCH_MINOR, BOX_BOTTOM) - (purchaseFrame.Y + 12),
			main_Wnd,
			NULL,
			hInst,
			NULL);

		TCITEM tie;
		TCHAR achTemp[20];
		achTemp[0] = '\0';

		tie.mask = TCIF_TEXT | TCIF_IMAGE;
		tie.iImage = -1;
		tie.pszText = achTemp;

		// Purchase tab
		wcsncpy_s(achTemp, L"Purchase", 9);
		tie.pszText = achTemp;
		if (TabCtrl_InsertItem(purchaseSectionTabs, TAB_PURCH, &tie) == -1)
			DestroyWindow(purchaseSectionTabs);

		// Combined Arms
		wcsncpy_s(achTemp, L"Combined Arms", 14);
		tie.pszText = achTemp;
		if (TabCtrl_InsertItem(purchaseSectionTabs, TAB_COMB, &tie) == -1)
			DestroyWindow(purchaseSectionTabs);

		// Neutral territories
		wcsncpy_s(achTemp, L"Neutral Territories", 20);
		tie.pszText = achTemp;
		if (TabCtrl_InsertItem(purchaseSectionTabs, TAB_NEUTRAL, &tie) == -1)
			DestroyWindow(purchaseSectionTabs);
	}

	// Neutral territories section
	if (neutralSection == NULL)
	{
		neutralSection = new NeutralSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		neutralSection->configNationBrushesP(gfx->gerBrushP, gfx->sovBrushP, gfx->jpnBrushP, gfx->usaBrushP, gfx->chnBrushP, gfx->ukBrushP,
			gfx->itaBrushP, gfx->anzBrushP, gfx->fraBrushP);
		neutralSection->configDrawTools(gfx->tileBrushL, gfx->neutBrush, gfx->axisBrush, gfx->allyBrush, gfx->font18_b, gfx->font20_b);

		neutralFrame = purchaseFrame;
		neutralSection->configureNeutralBox(neutralFrame, 1);
		
	}

	// Mini spreadsheet section
	if (miniSpreadSection == NULL)
	{
		miniSpreadSection = new MiniSpreadSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		miniSpreadSection->configDrawTools(gfx->font20_b, gfx->font20);
		miniSpreadSection->configNationBrushesP(gfx->gerBrushP, gfx->sovBrushP, gfx->jpnBrushP, gfx->usaBrushP, gfx->chnBrushP, gfx->ukBrushP,
			gfx->itaBrushP, gfx->anzBrushP, gfx->fraBrushP);
		miniSpreadSection->configNationBrushesS(gfx->gerBrushS, gfx->sovBrushS, gfx->jpnBrushS, gfx->usaBrushS, gfx->chnBrushS, gfx->ukBrushS,
			gfx->itaBrushS, gfx->anzBrushS, gfx->fraBrushS);

		miniSpreadFrame = nationScreenWindow0;
		miniSpreadFrame.X = phaseFrame.GetRight();
		miniSpreadFrame.Width = nationScreenWindow0.Width - miniSpreadFrame.X;
		miniSpreadFrame.Inflate(-24, -24);
		miniSpreadFrame.Height = cityFrame.GetBottom() - miniSpreadFrame.Y;
		miniSpreadSection->configureMiniSpread(miniSpreadFrame, 1);

		if (screenFrames.s[NATION_SCREEN].f.size() < (SPREAD_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(SPREAD_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(SPREAD_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[SPREAD_SECT_IDX] = miniSpreadFrame;
		screenFrames.s[NATION_SCREEN].b[SPREAD_SECT_IDX] = SPREAD_SECT;
	}

	// UK Global economy tabs
	if (ukEconomyTabs == NULL)
	{
		ukEconomyTabs = CreateWindow(
			WC_TABCONTROL,
			L"",
			WS_CHILD | WS_CLIPSIBLINGS | TCS_FLATBUTTONS |
			TCS_MULTILINE | TCS_VERTICAL | TCS_TABS,
			miniSpreadFrame.X - 20,
			miniSpreadFrame.Y + 2,
			20,
			miniSpreadFrame.Height - 5,
			main_Wnd,
			NULL,
			hInst,
			NULL);

		TCITEM tie;
		TCHAR achTemp[22];
		achTemp[0] = '\0';

		tie.mask = TCIF_TEXT | TCIF_IMAGE;
		tie.iImage = -1;
		tie.pszText = achTemp;

		// Europe tab
		wcsncpy_s(achTemp, L"      Europe      ", 19);
		tie.pszText = achTemp;
		if (TabCtrl_InsertItem(ukEconomyTabs, TAB_UKE, &tie) == -1)
			DestroyWindow(ukEconomyTabs);

		// Pacific tab
		wcsncpy_s(achTemp, L"       Pacific      ", 21);
		tie.pszText = achTemp;
		if (TabCtrl_InsertItem(ukEconomyTabs, TAB_UKP, &tie) == -1)
			DestroyWindow(ukEconomyTabs);
	}

	// Warchest section
	if (warchestSection == NULL)
	{
		warchestSection = new WarchestSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		warchestSection->configDrawTools(gfx->font18_b);
		warchestSection->configNationBrushesP(gfx->gerBrushP, gfx->sovBrushP, gfx->jpnBrushP, gfx->usaBrushP, gfx->chnBrushP, gfx->ukBrushP,
			gfx->itaBrushP, gfx->anzBrushP, gfx->fraBrushP);
		warchestSection->configNationBrushesS(gfx->gerBrushS, gfx->sovBrushS, gfx->jpnBrushS, gfx->usaBrushS, gfx->chnBrushS, gfx->ukBrushS,
			gfx->itaBrushS, gfx->anzBrushS, gfx->fraBrushS);
		warchestSection->configNationBrushesF(gfx->gerBrushF, gfx->sovBrushF, gfx->jpnBrushF, gfx->usaBrushF, gfx->chnBrushF, gfx->ukBrushF,
			gfx->itaBrushF, gfx->anzBrushF, gfx->fraBrushF);

		warchestFrame = miniSpreadFrame;
		warchestFrame.Y = miniSpreadFrame.GetBottom() + 24;
		warchestFrame.Height = (nationScreenWindow0.Height / 2) - warchestFrame.Y - 12;
		warchestSection->configureWarchestBox(warchestFrame, miniSpreadFrame, 1);

		if (screenFrames.s[NATION_SCREEN].f.size() < (CHEST_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(CHEST_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(CHEST_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[CHEST_SECT_IDX] = warchestFrame;
		screenFrames.s[NATION_SCREEN].b[CHEST_SECT_IDX] = CHEST_SECT;
	}

	// Bonus section
	if (bonusSection == NULL)
	{
		bonusSection = new BonusSection(gfx->blackPen1, gfx->borderlessPen, gfx->calibriFamily, gfx->leftCenterFormat, gfx->centerFormat,
			gfx->font16, gfx->font24_b, gfx->textBrush, gfx->backBrush, gfx->paneBrush);
		bonusSection->configDrawTools(gfx->font20_b);
		bonusSection->configNationBrushesP(gfx->gerBrushP, gfx->sovBrushP, gfx->jpnBrushP, gfx->usaBrushP, gfx->chnBrushP, gfx->ukBrushP,
			gfx->itaBrushP, gfx->anzBrushP, gfx->fraBrushP);
		bonusSection->configNationBrushesS(gfx->gerBrushS, gfx->sovBrushS, gfx->jpnBrushS, gfx->usaBrushS, gfx->chnBrushS, gfx->ukBrushS,
			gfx->itaBrushS, gfx->anzBrushS, gfx->fraBrushS);
		bonusSection->configNationBrushesF(gfx->gerBrushF, gfx->sovBrushF, gfx->jpnBrushF, gfx->usaBrushF, gfx->chnBrushF, gfx->ukBrushF,
			gfx->itaBrushF, gfx->anzBrushF, gfx->fraBrushF);

		bonusFrame = miniSpreadFrame;
		bonusFrame.Y = warchestFrame.GetBottom();
		bonusFrame.Height = nationScreenWindow0.Height - bonusFrame.Y;
		bonusFrame.Inflate(0, -24);
		bonusSection->configureBonusBox(bonusFrame, 1);

		if (screenFrames.s[NATION_SCREEN].f.size() < (BONUS_SECT_IDX + 1))
		{
			screenFrames.s[NATION_SCREEN].f.resize(BONUS_SECT_IDX + 1);
			screenFrames.s[NATION_SCREEN].b.resize(BONUS_SECT_IDX + 1);
		}
		screenFrames.s[NATION_SCREEN].f[BONUS_SECT_IDX] = bonusFrame;
		screenFrames.s[NATION_SCREEN].b[BONUS_SECT_IDX] = BONUS_SECT;
	}
	
	// Buttons section 
	{
		REAL buttonLeft = (REAL)nameFrame.GetRight();
		REAL buttonWidth = cityFrameR.GetRight() - buttonLeft;

		REAL purchBoxTop = phaseSection->getBoxEdge(PR_PHASE, BOX_TOP);
		REAL purchBoxHeight = phaseSection->getBoxEdge(PR_PHASE, BOX_HEIGHT);
		REAL cmBoxTop = phaseSection->getBoxEdge(CM_PHASE, BOX_TOP);
		REAL cmBoxHeight = phaseSection->getBoxEdge(CM_PHASE, BOX_HEIGHT);
		REAL ccBoxTop = phaseSection->getBoxEdge(CC_PHASE, BOX_TOP);
		REAL ccBoxHeight = phaseSection->getBoxEdge(CC_PHASE, BOX_HEIGHT);
		REAL ncBoxTop = phaseSection->getBoxEdge(NC_PHASE, BOX_TOP);
		REAL ncBoxHeight = phaseSection->getBoxEdge(NC_PHASE, BOX_HEIGHT);

		REAL specialButtonLeft0 = (REAL)cityFrameR.X - 24;
		REAL specialButtonLeft1 = (REAL)(cityFrameR.X + (cityFrameR.Width / 2));
		REAL specialButtonWidth0 = (REAL)(specialButtonLeft1 - specialButtonLeft0);
		REAL specialButtonWidth1 = (REAL)(phaseSection->getBoxEdge(NC_PHASE, BOX_LEFT) - specialButtonLeft1);

		if (nextPhaseButton == BB_ID_NULL)
		{
			nextPhaseButton = gfx->buttons->createButtonId();

			RectF rect = { buttonLeft, purchBoxTop, buttonWidth, purchBoxHeight };
			gfx->buttons->registerButton(graphics, nextPhaseButton, NATION_SCREEN, PHASE_SECT, rect, "Next Phase", nationScreenHandleNextPhase);
			gfx->tooltips->registerTooltip(graphics, nextPhaseButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_LEFT, "Proceed to the next phase");
		}

		if (researchButton == BB_ID_NULL)
		{
			researchButton = gfx->buttons->createButtonId();
			
			RectF rect = { buttonLeft, cmBoxTop, buttonWidth, cmBoxHeight };
			gfx->buttons->registerButton(graphics, researchButton, NATION_SCREEN, PHASE_SECT, rect, "Research Dice", nationScreenHandleResearch);
			gfx->tooltips->registerTooltip(graphics, researchButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_LEFT, "Enter results of research rolls");
		}

		if (declareWarButton == BB_ID_NULL)
		{
			declareWarButton = gfx->buttons->createButtonId();

			RectF rect = { buttonLeft, cmBoxTop, buttonWidth, cmBoxHeight };
			gfx->buttons->registerButton(graphics, declareWarButton, NATION_SCREEN, PHASE_SECT, rect, "Declare War", nationScreenHandleDeclareWar);
			gfx->tooltips->registerTooltip(graphics, declareWarButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_LEFT, "Declare war on another player");
		}
		
		if (captureTerritoryButton == BB_ID_NULL)
		{
			captureTerritoryButton = gfx->buttons->createButtonId();

			RectF rect = { buttonLeft, cmBoxTop, buttonWidth, cmBoxHeight };
			gfx->buttons->registerButton(graphics, captureTerritoryButton, NATION_SCREEN, PHASE_SECT, rect, "Capture Territory", nationScreenHandleCaptureTerritory, BB_SMALL_FONT);
			gfx->tooltips->registerTooltip(graphics, captureTerritoryButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_LEFT, "Territories captured during Conduct Combat phase");
		}

		if (attackNeutralButton == BB_ID_NULL)
		{
			attackNeutralButton = gfx->buttons->createButtonId();

			RectF rect = { buttonLeft, ccBoxTop, buttonWidth, ccBoxHeight };
			gfx->buttons->registerButton(graphics, attackNeutralButton, NATION_SCREEN, PHASE_SECT, rect, "Attack Neutral", nationScreenHandleAttackNeutral);
			gfx->tooltips->registerTooltip(graphics, attackNeutralButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_LEFT, "Attack a strict neutral territory\nAll strict neutral territories will become unfriendly");
		}

		if (occupyNeutralButton == BB_ID_NULL)
		{
			occupyNeutralButton = gfx->buttons->createButtonId();

			RectF rect = { buttonLeft, cmBoxTop, buttonWidth, cmBoxHeight };
			gfx->buttons->registerButton(graphics, occupyNeutralButton, NATION_SCREEN, PHASE_SECT, rect, "Occupy Neutral", nationScreenHandleOccupyNeutral);
			gfx->tooltips->registerTooltip(graphics, occupyNeutralButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_LEFT, "Occupy a friendly neutral territory");
		}

		if (attackMongoliaButton == BB_ID_NULL)
		{
			attackMongoliaButton = gfx->buttons->createButtonId();

			RectF rect = { specialButtonLeft0, ncBoxTop, specialButtonWidth0, ncBoxHeight };
			gfx->buttons->registerButton(graphics, attackMongoliaButton, NATION_SCREEN, PHASE_SECT, rect, "Attack Mongolia", nationScreenHandleAttackMongolia, BB_SMALL_FONT);
			gfx->tooltips->registerTooltip(graphics, attackMongoliaButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_LEFT, "You are attacking a Mongolian territory\nin your Combat Move phase");
		}

		if (attackJapanButton == BB_ID_NULL)
		{
			attackJapanButton = gfx->buttons->createButtonId();

			RectF rect = { specialButtonLeft1, ncBoxTop, specialButtonWidth1, ncBoxHeight };
			gfx->buttons->registerButton(graphics, attackJapanButton, NATION_SCREEN, PHASE_SECT, rect, "Attack Japan", nationScreenHandleAttackJapan);
			gfx->tooltips->registerTooltip(graphics, attackJapanButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_RIGHT, "You are attacking Korea or any Mongolia-adjactent\nJapanese territory in your Combat Move phase");
		}

		if (attackSovietButton == BB_ID_NULL)
		{
			attackSovietButton = gfx->buttons->createButtonId();

			RectF rect = { buttonLeft - 24, ncBoxTop, buttonWidth + 24, ncBoxHeight };
			gfx->buttons->registerButton(graphics, attackSovietButton, NATION_SCREEN, PHASE_SECT, rect, "Attack Soviet Union", nationScreenHandleAttackSoviet, BB_SMALL_FONT);
			gfx->tooltips->registerTooltip(graphics, attackSovietButton, NATION_SCREEN, PHASE_SECT, rect, TT_DIR_LEFT, "You are attacking a Mongolia-adjactent\nSoviet territory in your Combat Move phase");
		}
	}
}

