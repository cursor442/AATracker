#include "../header/PurchaseSection.h"

PurchaseSection::PurchaseSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	purchaseFrame = new AABox("Purchase Section");

	purchTitleBox = new AABox("Purchase New Units");

	purchHeadRow = new PurchaseRow("Header" );
	infRow       = new PurchaseRow("Infantry", "I");
	artRow       = new PurchaseRow("Artillery", "A");
	mechRow      = new PurchaseRow("Mechanized", "M");
	tankRow      = new PurchaseRow("Tank", "T");
	aaaRow       = new PurchaseRow("AAA", "A");
	fightRow     = new PurchaseRow("Fighter", "F");
	tactRow      = new PurchaseRow("Tactical", "T");
	stratRow     = new PurchaseRow("Strategic", "S");
	battleRow    = new PurchaseRow("Battleship", "B");
	airccRow     = new PurchaseRow("Aircraft", "A");
	cruiseRow    = new PurchaseRow("Cruiser", "C");
	destrRow     = new PurchaseRow("Destroyer", "D");
	subRow       = new PurchaseRow("Submarine", "S");
	transRow     = new PurchaseRow("Transport", "T");
	majorRow     = new PurchaseRow("Major", "M");
	minorRow     = new PurchaseRow("Minor", "M");
	minorUpRow   = new PurchaseRow("Upgrade", "U");
	airbRow      = new PurchaseRow("Air", "A");
	navbRow      = new PurchaseRow("Naval", "N");
	repRow       = new PurchaseRow("Repair", "R");
	totRow       = new PurchaseRow("Total", "T");

	titleP0 = NULL; titleP1 = NULL;

	main_Wnd = NULL;

	buttons = NULL;
	showButton = NULL;
	hideButton = NULL;
	hideButtonNoDraw = NULL;

	infDButton     = BB_ID_NULL; infUButton     = BB_ID_NULL;
	artDButton     = BB_ID_NULL; artUButton     = BB_ID_NULL;
	mechDButton    = BB_ID_NULL; mechUButton    = BB_ID_NULL;
	tankDButton    = BB_ID_NULL; tankUButton    = BB_ID_NULL;
	aaaDButton     = BB_ID_NULL; aaaUButton     = BB_ID_NULL;
	fightDButton   = BB_ID_NULL; fightUButton   = BB_ID_NULL;
	tactDButton    = BB_ID_NULL; tactUButton    = BB_ID_NULL;
	stratDButton   = BB_ID_NULL; stratUButton   = BB_ID_NULL;
	battleDButton  = BB_ID_NULL; battleUButton  = BB_ID_NULL;
	airccDButton   = BB_ID_NULL; airccUButton   = BB_ID_NULL;
	cruiseDButton  = BB_ID_NULL; cruiseUButton  = BB_ID_NULL;
	destrDButton   = BB_ID_NULL; destrUButton   = BB_ID_NULL;
	subDButton     = BB_ID_NULL; subUButton     = BB_ID_NULL;
	transDButton   = BB_ID_NULL; transUButton   = BB_ID_NULL;
	majorDButton   = BB_ID_NULL; majorUButton   = BB_ID_NULL;
	minorDButton   = BB_ID_NULL; minorUButton   = BB_ID_NULL;
	minorUpDButton = BB_ID_NULL; minorUpUButton = BB_ID_NULL;
	airbDButton    = BB_ID_NULL; airbUButton    = BB_ID_NULL;
	navbDButton    = BB_ID_NULL; navbUButton    = BB_ID_NULL;
	repairDButton  = BB_ID_NULL; repairUButton  = BB_ID_NULL;

	purchHeadRow->configRowText(" Unit Stats:", "Cost", "Attack", "Defend", "Move");
	purchHeadRow->configQuantTotText("Quantity", "Total");
	infRow->configRowText(" Infantry", "3", "1", "2", "1");
	artRow->configRowText(" Artillery", "4", "2", "2", "1");
	mechRow->configRowText(" Mechanized Infantry", "4", "1", "2", "2");
	tankRow->configRowText(" Tank", "6", "3", "3", "2");
	aaaRow->configRowText(" AAA", "5", " ", "1", "1");
	fightRow->configRowText(" Fighter", "10", "3", "4", "4");
	tactRow->configRowText(" Tactical Bomber", "11", "3", "3", "4");
	stratRow->configRowText(" Strategic Bomber", "12", "4", "1", "6");
	battleRow->configRowText(" Battleship", "20", "4", "4", "2");
	airccRow->configRowText(" Aircraft Carrier", "16", "", "2", "2");
	cruiseRow->configRowText(" Cruiser", "12", "3", "3", "2");
	destrRow->configRowText(" Destroyer", "8", "2", "2", "2");
	subRow->configRowText(" Submarine", "6", "2", "1", "2");
	transRow->configRowText(" Transport", "7", "", "", "2");
	majorRow->configRowText(" Major Industrial Complex", "30", "", "", "");
	minorRow->configRowText(" Minor Industrial Complex", "12", "", "", "");
	minorUpRow->configRowText("     Upgrade Minor IC", "20", "", "", "");
	airbRow->configRowText(" Air Base", "15", "", "", "");
	navbRow->configRowText(" Naval Base", "15", "", "", "");
	repRow->configRowText(" Repairs", "1", "", "", "");
	totRow->configRowText(" Total:", "", "", "", "");

	currUKButton = 0;

	wcsncpy_s(infQ, L"0", 2);
	wcsncpy_s(artQ, L"0", 2);
	wcsncpy_s(mechQ, L"0", 2);
	wcsncpy_s(tankQ, L"0", 2);
	wcsncpy_s(aaaQ, L"0", 2);
	wcsncpy_s(fightQ, L"0", 2);
	wcsncpy_s(tactQ, L"0", 2);
	wcsncpy_s(stratQ, L"0", 2);
	wcsncpy_s(battleQ, L"0", 2);
	wcsncpy_s(airccQ, L"0", 2);
	wcsncpy_s(cruiseQ, L"0", 2);
	wcsncpy_s(destrQ, L"0", 2);
	wcsncpy_s(subQ, L"0", 2);
	wcsncpy_s(transQ, L"0", 2);
	wcsncpy_s(majorQ, L"0", 2);
	wcsncpy_s(minorQ, L"0", 2);
	wcsncpy_s(minorUpQ, L"0", 2);
	wcsncpy_s(airbQ, L"0", 2);
	wcsncpy_s(navbQ, L"0", 2);
	wcsncpy_s(repQ, L"0", 2);
	wcsncpy_s(totQ, L"0", 2);

	wcsncpy_s(infC, L"0", 2);
	wcsncpy_s(artC, L"0", 2);
	wcsncpy_s(mechC, L"0", 2);
	wcsncpy_s(tankC, L"0", 2);
	wcsncpy_s(aaaC, L"0", 2);
	wcsncpy_s(fightC, L"0", 2);
	wcsncpy_s(tactC, L"0", 2);
	wcsncpy_s(stratC, L"0", 2);
	wcsncpy_s(battleC, L"0", 2);
	wcsncpy_s(airccC, L"0", 2);
	wcsncpy_s(cruiseC, L"0", 2);
	wcsncpy_s(destrC, L"0", 2);
	wcsncpy_s(subC, L"0", 2);
	wcsncpy_s(transC, L"0", 2);
	wcsncpy_s(majorC, L"0", 2);
	wcsncpy_s(minorC, L"0", 2);
	wcsncpy_s(minorUpC, L"0", 2);
	wcsncpy_s(airbC, L"0", 2);
	wcsncpy_s(navbC, L"0", 2);
	wcsncpy_s(repC, L"0", 2);
	wcsncpy_s(totC, L"0", 2);

	backPen = NULL;

	purchaseFormat = NULL;
	purchFont = NULL;
	costFont = NULL;

	tileBrushL = NULL;
	tileBrushD = NULL;
	clearBrush = NULL;
}

PurchaseSection::~PurchaseSection()
{
	delete purchaseFrame;

	delete purchTitleBox;

	delete purchHeadRow;
	delete infRow;
	delete artRow;
	delete mechRow;
	delete aaaRow;
	delete fightRow;
	delete tactRow;
	delete stratRow;
	delete battleRow;
	delete airccRow;
	delete cruiseRow;
	delete destrRow;
	delete subRow;
	delete transRow;
	delete majorRow;
	delete minorRow;
	delete minorUpRow;
	delete airbRow;
	delete navbRow;
	delete repRow;
	delete totRow;

	delete titleP0; delete titleP1;
}

void PurchaseSection::configurePurchaseBox(Graphics* graphics, HWND& hWnd, RectF& frame, AAButtons* buttons, void (*purchaseButton)(HWND&, int), int layer)
{
	main_Wnd = &hWnd;
	
	purchaseFrame->config(frame, layer);

	purchTitleBox->config(frame, layer + 1);
	purchTitleBox->box.Height = 2 * frame.Height / 25;

	titleP0 = new PointF(purchTitleBox->box.X, purchTitleBox->box.GetBottom());
	titleP1 = new PointF(purchTitleBox->box.GetRight(), purchTitleBox->box.GetBottom());

	purchHeadRow->configRow(purchTitleBox->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, false, layer + 1);
	purchHeadRow->setRowY(purchTitleBox->box.GetBottom());
	purchHeadRow->setRowHeight(frame.Height / 25);

	infRow->configRow(purchHeadRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	infRow->setRowY(purchHeadRow->bottom());

	artRow->configRow(infRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	artRow->setRowY(infRow->bottom());

	mechRow->configRow(artRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	mechRow->setRowY(artRow->bottom());

	tankRow->configRow(mechRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	tankRow->setRowY(mechRow->bottom());
	
	aaaRow->configRow(tankRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	aaaRow->setRowY(tankRow->bottom());

	fightRow->configRow(aaaRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	fightRow->setRowY(aaaRow->bottom());

	tactRow->configRow(fightRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	tactRow->setRowY(fightRow->bottom());

	stratRow->configRow(tactRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	stratRow->setRowY(tactRow->bottom());

	battleRow->configRow(stratRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	battleRow->setRowY(stratRow->bottom());

	airccRow->configRow(battleRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	airccRow->setRowY(battleRow->bottom());

	cruiseRow->configRow(airccRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	cruiseRow->setRowY(airccRow->bottom());

	destrRow->configRow(cruiseRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	destrRow->setRowY(cruiseRow->bottom());
	
	subRow->configRow(destrRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	subRow->setRowY(destrRow->bottom());

	transRow->configRow(subRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	transRow->setRowY(subRow->bottom());

	majorRow->configRow(transRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	majorRow->setRowY(transRow->bottom());

	minorRow->configRow(majorRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	minorRow->setRowY(majorRow->bottom());
	
	minorUpRow->configRow(minorRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	minorUpRow->setRowY(minorRow->bottom());

	airbRow->configRow(minorUpRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	airbRow->setRowY(minorUpRow->bottom());

	navbRow->configRow(airbRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	navbRow->setRowY(airbRow->bottom());

	repRow->configRow(navbRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, true, layer + 1);
	repRow->setRowY(navbRow->bottom());

	totRow->configRow(repRow->getBox()->box, PURCH_ROW_UNIT_WIDTH, PURCH_ROW_STAT_WIDTH, PURCH_ROW_QUANT_WIDTH, PURCH_ROW_TOTAL_WIDTH, false, layer + 1);
	totRow->setRowY(repRow->bottom());
	totRow->setRowHeight(frame.GetBottom() - totRow->getBox()->box.Y);

	configPurchaseButtons(graphics, buttons, purchaseButton);

	REAL firstTabOffset;
	REAL tabStops[6];
	purchaseFormat->GetTabStops(6, &firstTabOffset, tabStops);

	REAL X = purchaseFrame->box.X + firstTabOffset + tabStops[0];
}

void PurchaseSection::configPurchaseButtons(Graphics* graphics, AAButtons* btns, void (*purchaseButton)(HWND&, int))
{
	buttons = btns;

	if (infDButton == BB_ID_NULL)
	{
		infDButton = buttons->createButtonId();

		RectF rect = { infRow->buttonDownX(), infRow->y(), infRow->height(), infRow->height() };
		buttons->registerButton(graphics, infDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(infDButton);
		buttons->setButtonFuncId(infDButton, IDB_INFDN);
		buttons->setButtonValInt(infDButton, PURCH_INF);
		buttons->deactivateButton(infDButton);
	}
	if (infUButton == BB_ID_NULL)
	{
		infUButton = buttons->createButtonId();

		RectF rect = { infRow->buttonUpX(), infRow->y(), infRow->height(), infRow->height() };
		buttons->registerButton(graphics, infUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(infUButton);
		buttons->setButtonFuncId(infUButton, IDB_INFUP);
		buttons->setButtonValInt(infUButton, PURCH_INF);
		buttons->deactivateButton(infUButton);
	}

	if (artDButton == BB_ID_NULL)
	{
		artDButton = buttons->createButtonId();

		RectF rect = { artRow->buttonDownX(), artRow->y(), artRow->height(), artRow->height() };
		buttons->registerButton(graphics, artDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(artDButton);
		buttons->setButtonFuncId(artDButton, IDB_ARTDN);
		buttons->setButtonValInt(artDButton, PURCH_ART);
		buttons->deactivateButton(artDButton);
	}
	if (artUButton == BB_ID_NULL)
	{
		artUButton = buttons->createButtonId();

		RectF rect = { artRow->buttonUpX(), artRow->y(), artRow->height(), artRow->height() };
		buttons->registerButton(graphics, artUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(artUButton);
		buttons->setButtonFuncId(artUButton, IDB_ARTUP);
		buttons->setButtonValInt(artUButton, PURCH_ART);
		buttons->deactivateButton(artUButton);
	}

	if (mechDButton == BB_ID_NULL)
	{
		mechDButton = buttons->createButtonId();

		RectF rect = { mechRow->buttonDownX(), mechRow->y(), mechRow->height(), mechRow->height() };
		buttons->registerButton(graphics, mechDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(mechDButton);
		buttons->setButtonFuncId(mechDButton, IDB_MECHDN);
		buttons->setButtonValInt(mechDButton, PURCH_MECH);
		buttons->deactivateButton(mechDButton);
	}
	if (mechUButton == BB_ID_NULL)
	{
		mechUButton = buttons->createButtonId();

		RectF rect = { mechRow->buttonUpX(), mechRow->y(), mechRow->height(), mechRow->height() };
		buttons->registerButton(graphics, mechUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(mechUButton);
		buttons->setButtonFuncId(mechUButton, IDB_MECHUP);
		buttons->setButtonValInt(mechUButton, PURCH_MECH);
		buttons->deactivateButton(mechUButton);
	}

	if (tankDButton == BB_ID_NULL)
	{
		tankDButton = buttons->createButtonId();

		RectF rect = { tankRow->buttonDownX(), tankRow->y(), tankRow->height(), tankRow->height() };
		buttons->registerButton(graphics, tankDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(tankDButton);
		buttons->setButtonFuncId(tankDButton, IDB_TANKDN);
		buttons->setButtonValInt(tankDButton, PURCH_TANK);
		buttons->deactivateButton(tankDButton);
	}
	if (tankUButton == BB_ID_NULL)
	{
		tankUButton = buttons->createButtonId();

		RectF rect = { tankRow->buttonUpX(), tankRow->y(), tankRow->height(), tankRow->height() };
		buttons->registerButton(graphics, tankUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(tankUButton);
		buttons->setButtonFuncId(tankUButton, IDB_TANKUP);
		buttons->setButtonValInt(tankUButton, PURCH_TANK);
		buttons->deactivateButton(tankUButton);
	}

	if (aaaDButton == BB_ID_NULL)
	{
		aaaDButton = buttons->createButtonId();

		RectF rect = { aaaRow->buttonDownX(), aaaRow->y(), aaaRow->height(), aaaRow->height() };
		buttons->registerButton(graphics, aaaDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(aaaDButton);
		buttons->setButtonFuncId(aaaDButton, IDB_AAADN);
		buttons->setButtonValInt(aaaDButton, PURCH_AAA);
		buttons->deactivateButton(aaaDButton);
	}
	if (aaaUButton == BB_ID_NULL)
	{
		aaaUButton = buttons->createButtonId();

		RectF rect = { aaaRow->buttonUpX(), aaaRow->y(), aaaRow->height(), aaaRow->height() };
		buttons->registerButton(graphics, aaaUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(aaaUButton);
		buttons->setButtonFuncId(aaaUButton, IDB_AAAUP);
		buttons->setButtonValInt(aaaUButton, PURCH_AAA);
		buttons->deactivateButton(aaaUButton);
	}

	if (fightDButton == BB_ID_NULL)
	{
		fightDButton = buttons->createButtonId();

		RectF rect = { fightRow->buttonDownX(), fightRow->y(), fightRow->height(), fightRow->height() };
		buttons->registerButton(graphics, fightDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(fightDButton);
		buttons->setButtonFuncId(fightDButton, IDB_FIGHTDN);
		buttons->setButtonValInt(fightDButton, PURCH_FIGHT);
		buttons->deactivateButton(fightDButton);
	}
	if (fightUButton == BB_ID_NULL)
	{
		fightUButton = buttons->createButtonId();

		RectF rect = { fightRow->buttonUpX(), fightRow->y(), fightRow->height(), fightRow->height() };
		buttons->registerButton(graphics, fightUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(fightUButton);
		buttons->setButtonFuncId(fightUButton, IDB_FIGHTUP);
		buttons->setButtonValInt(fightUButton, PURCH_FIGHT);
		buttons->deactivateButton(fightUButton);
	}

	if (tactDButton == BB_ID_NULL)
	{
		tactDButton = buttons->createButtonId();

		RectF rect = { tactRow->buttonDownX(), tactRow->y(), tactRow->height(), tactRow->height() };
		buttons->registerButton(graphics, tactDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(tactDButton);
		buttons->setButtonFuncId(tactDButton, IDB_TACTDN);
		buttons->setButtonValInt(tactDButton, PURCH_TACT);
		buttons->deactivateButton(tactDButton);
	}
	if (tactUButton == BB_ID_NULL)
	{
		tactUButton = buttons->createButtonId();

		RectF rect = { tactRow->buttonUpX(), tactRow->y(), tactRow->height(), tactRow->height() };
		buttons->registerButton(graphics, tactUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(tactUButton);
		buttons->setButtonFuncId(tactUButton, IDB_TACTUP);
		buttons->setButtonValInt(tactUButton, PURCH_TACT);
		buttons->deactivateButton(tactUButton);
	}

	if (stratDButton == BB_ID_NULL)
	{
		stratDButton = buttons->createButtonId();

		RectF rect = { stratRow->buttonDownX(), stratRow->y(), stratRow->height(), stratRow->height() };
		buttons->registerButton(graphics, stratDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(stratDButton);
		buttons->setButtonFuncId(stratDButton, IDB_STRATDN);
		buttons->setButtonValInt(stratDButton, PURCH_STRAT);
		buttons->deactivateButton(stratDButton);
	}
	if (stratUButton == BB_ID_NULL)
	{
		stratUButton = buttons->createButtonId();

		RectF rect = { stratRow->buttonUpX(), stratRow->y(), stratRow->height(), stratRow->height() };
		buttons->registerButton(graphics, stratUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(stratUButton);
		buttons->setButtonFuncId(stratUButton, IDB_STRATUP);
		buttons->setButtonValInt(stratUButton, PURCH_STRAT);
		buttons->deactivateButton(stratUButton);
	}

	if (battleDButton == BB_ID_NULL)
	{
		battleDButton = buttons->createButtonId();

		RectF rect = { battleRow->buttonDownX(), battleRow->y(), battleRow->height(), battleRow->height() };
		buttons->registerButton(graphics, battleDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(battleDButton);
		buttons->setButtonFuncId(battleDButton, IDB_BATTLEDN);
		buttons->setButtonValInt(battleDButton, PURCH_BATTLE);
		buttons->deactivateButton(battleDButton);
	}
	if (battleUButton == BB_ID_NULL)
	{
		battleUButton = buttons->createButtonId();

		RectF rect = { battleRow->buttonUpX(), battleRow->y(), battleRow->height(), battleRow->height() };
		buttons->registerButton(graphics, battleUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(battleUButton);
		buttons->setButtonFuncId(battleUButton, IDB_BATTLEUP);
		buttons->setButtonValInt(battleUButton, PURCH_BATTLE);
		buttons->deactivateButton(battleUButton);
	}

	if (airccDButton == BB_ID_NULL)
	{
		airccDButton = buttons->createButtonId();

		RectF rect = { airccRow->buttonDownX(), airccRow->y(), airccRow->height(), airccRow->height() };
		buttons->registerButton(graphics, airccDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(airccDButton);
		buttons->setButtonFuncId(airccDButton, IDB_AIRCCDN);
		buttons->setButtonValInt(airccDButton, PURCH_AIRCC);
		buttons->deactivateButton(airccDButton);
	}
	if (airccUButton == BB_ID_NULL)
	{
		airccUButton = buttons->createButtonId();

		RectF rect = { airccRow->buttonUpX(), airccRow->y(), airccRow->height(), airccRow->height() };
		buttons->registerButton(graphics, airccUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(airccUButton);
		buttons->setButtonFuncId(airccUButton, IDB_AIRCCUP);
		buttons->setButtonValInt(airccUButton, PURCH_AIRCC);
		buttons->deactivateButton(airccUButton);
	}

	if (cruiseDButton == BB_ID_NULL)
	{
		cruiseDButton = buttons->createButtonId();

		RectF rect = { cruiseRow->buttonDownX(), cruiseRow->y(), cruiseRow->height(), cruiseRow->height() };
		buttons->registerButton(graphics, cruiseDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(cruiseDButton);
		buttons->setButtonFuncId(cruiseDButton, IDB_CRUISEDN);
		buttons->setButtonValInt(cruiseDButton, PURCH_CRUISE);
		buttons->deactivateButton(cruiseDButton);
	}
	if (cruiseUButton == BB_ID_NULL)
	{
		cruiseUButton = buttons->createButtonId();

		RectF rect = { cruiseRow->buttonUpX(), cruiseRow->y(), cruiseRow->height(), cruiseRow->height() };
		buttons->registerButton(graphics, cruiseUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(cruiseUButton);
		buttons->setButtonFuncId(cruiseUButton, IDB_CRUISEUP);
		buttons->setButtonValInt(cruiseUButton, PURCH_CRUISE);
		buttons->deactivateButton(cruiseUButton);
	}

	if (destrDButton == BB_ID_NULL)
	{
		destrDButton = buttons->createButtonId();

		RectF rect = { destrRow->buttonDownX(), destrRow->y(), destrRow->height(), destrRow->height() };
		buttons->registerButton(graphics, destrDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(destrDButton);
		buttons->setButtonFuncId(destrDButton, IDB_DESTRDN);
		buttons->setButtonValInt(destrDButton, PURCH_DESTR);
		buttons->deactivateButton(destrDButton);
	}
	if (destrUButton == BB_ID_NULL)
	{
		destrUButton = buttons->createButtonId();

		RectF rect = { destrRow->buttonUpX(), destrRow->y(), destrRow->height(), destrRow->height() };
		buttons->registerButton(graphics, destrUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(destrUButton);
		buttons->setButtonFuncId(destrUButton, IDB_DESTRUP);
		buttons->setButtonValInt(destrUButton, PURCH_DESTR);
		buttons->deactivateButton(destrUButton);
	}

	if (subDButton == BB_ID_NULL)
	{
		subDButton = buttons->createButtonId();

		RectF rect = { subRow->buttonDownX(), subRow->y(), subRow->height(), subRow->height() };
		buttons->registerButton(graphics, subDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(subDButton);
		buttons->setButtonFuncId(subDButton, IDB_SUBDN);
		buttons->setButtonValInt(subDButton, PURCH_SUB);
		buttons->deactivateButton(subDButton);
	}
	if (subUButton == BB_ID_NULL)
	{
		subUButton = buttons->createButtonId();

		RectF rect = { subRow->buttonUpX(), subRow->y(), subRow->height(), subRow->height() };
		buttons->registerButton(graphics, subUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(subUButton);
		buttons->setButtonFuncId(subUButton, IDB_SUBUP);
		buttons->setButtonValInt(subUButton, PURCH_SUB);
		buttons->deactivateButton(subUButton);
	}

	if (transDButton == BB_ID_NULL)
	{
		transDButton = buttons->createButtonId();

		RectF rect = { transRow->buttonDownX(), transRow->y(), transRow->height(), transRow->height() };
		buttons->registerButton(graphics, transDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(transDButton);
		buttons->setButtonFuncId(transDButton, IDB_TRANSDN);
		buttons->setButtonValInt(transDButton, PURCH_TRANS);
		buttons->deactivateButton(transDButton);
	}
	if (transUButton == BB_ID_NULL)
	{
		transUButton = buttons->createButtonId();

		RectF rect = { transRow->buttonUpX(), transRow->y(), transRow->height(), transRow->height() };
		buttons->registerButton(graphics, transUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(transUButton);
		buttons->setButtonFuncId(transUButton, IDB_TRANSUP);
		buttons->setButtonValInt(transUButton, PURCH_TRANS);
		buttons->deactivateButton(transUButton);
	}

	if (majorDButton == BB_ID_NULL)
	{
		majorDButton = buttons->createButtonId();

		RectF rect = { majorRow->buttonDownX(), majorRow->y(), majorRow->height(), majorRow->height() };
		buttons->registerButton(graphics, majorDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(majorDButton);
		buttons->setButtonFuncId(majorDButton, IDB_MAJORDN);
		buttons->setButtonValInt(majorDButton, PURCH_MAJOR);
		buttons->deactivateButton(majorDButton);
	}
	if (majorUButton == BB_ID_NULL)
	{
		majorUButton = buttons->createButtonId();

		RectF rect = { majorRow->buttonUpX(), majorRow->y(), majorRow->height(), majorRow->height() };
		buttons->registerButton(graphics, majorUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(majorUButton);
		buttons->setButtonFuncId(majorUButton, IDB_MAJORUP);
		buttons->setButtonValInt(majorUButton, PURCH_MAJOR);
		buttons->deactivateButton(majorUButton);
	}

	if (minorDButton == BB_ID_NULL)
	{
		minorDButton = buttons->createButtonId();

		RectF rect = { minorRow->buttonDownX(), minorRow->y(), minorRow->height(), minorRow->height() };
		buttons->registerButton(graphics, minorDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(minorDButton);
		buttons->setButtonFuncId(minorDButton, IDB_MINORDN);
		buttons->setButtonValInt(minorDButton, PURCH_MINOR);
		buttons->deactivateButton(minorDButton);
	}
	if (minorUButton == BB_ID_NULL)
	{
		minorUButton = buttons->createButtonId();

		RectF rect = { minorRow->buttonUpX(), minorRow->y(), minorRow->height(), minorRow->height() };
		buttons->registerButton(graphics, minorUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(minorUButton);
		buttons->setButtonFuncId(minorUButton, IDB_MINORUP);
		buttons->setButtonValInt(minorUButton, PURCH_MINOR);
		buttons->deactivateButton(minorUButton);
	}

	if (minorUpDButton == BB_ID_NULL)
	{
		minorUpDButton = buttons->createButtonId();

		RectF rect = { minorUpRow->buttonDownX(), minorUpRow->y(), minorUpRow->height(), minorUpRow->height() };
		buttons->registerButton(graphics, minorUpDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(minorUpDButton);
		buttons->setButtonFuncId(minorUpDButton, IDB_MINORUPDN);
		buttons->setButtonValInt(minorUpDButton, PURCH_MINORUP);
		buttons->deactivateButton(minorUpDButton);
	}
	if (minorUpUButton == BB_ID_NULL)
	{
		minorUpUButton = buttons->createButtonId();

		RectF rect = { minorUpRow->buttonUpX(), minorUpRow->y(), minorUpRow->height(), minorUpRow->height() };
		buttons->registerButton(graphics, minorUpUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(minorUpUButton);
		buttons->setButtonFuncId(minorUpUButton, IDB_MINORUPUP);
		buttons->setButtonValInt(minorUpUButton, PURCH_MINORUP);
		buttons->deactivateButton(minorUpUButton);
	}

	if (airbDButton == BB_ID_NULL)
	{
		airbDButton = buttons->createButtonId();

		RectF rect = { airbRow->buttonDownX(), airbRow->y(), airbRow->height(), airbRow->height() };
		buttons->registerButton(graphics, airbDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(airbDButton);
		buttons->setButtonFuncId(airbDButton, IDB_AIRBDN);
		buttons->setButtonValInt(airbDButton, PURCH_AIRB);
		buttons->deactivateButton(airbDButton);
	}
	if (airbUButton == BB_ID_NULL)
	{
		airbUButton = buttons->createButtonId();

		RectF rect = { airbRow->buttonUpX(), airbRow->y(), airbRow->height(), airbRow->height() };
		buttons->registerButton(graphics, airbUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(airbUButton);
		buttons->setButtonFuncId(airbUButton, IDB_AIRBUP);
		buttons->setButtonValInt(airbUButton, PURCH_AIRB);
		buttons->deactivateButton(airbUButton);
	}

	if (navbDButton == BB_ID_NULL)
	{
		navbDButton = buttons->createButtonId();

		RectF rect = { navbRow->buttonDownX(), navbRow->y(), navbRow->height(), navbRow->height() };
		buttons->registerButton(graphics, navbDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(navbDButton);
		buttons->setButtonFuncId(navbDButton, IDB_NAVBDN);
		buttons->setButtonValInt(navbDButton, PURCH_NAVB);
		buttons->deactivateButton(navbDButton);
	}
	if (navbUButton == BB_ID_NULL)
	{
		navbUButton = buttons->createButtonId();

		RectF rect = { navbRow->buttonUpX(), navbRow->y(), navbRow->height(), navbRow->height() };
		buttons->registerButton(graphics, navbUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(navbUButton);
		buttons->setButtonFuncId(navbUButton, IDB_NAVBUP);
		buttons->setButtonValInt(navbUButton, PURCH_NAVB);
		buttons->deactivateButton(navbUButton);
	}

	if (repairDButton == BB_ID_NULL)
	{
		repairDButton = buttons->createButtonId();

		RectF rect = { repRow->buttonDownX(), repRow->y(), repRow->height(), repRow->height() };
		buttons->registerButton(graphics, repairDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(repairDButton);
		buttons->setButtonFuncId(repairDButton, IDB_REPAIRDN);
		buttons->setButtonValInt(repairDButton, PURCH_REP);
		buttons->deactivateButton(repairDButton);
	}
	if (repairUButton == BB_ID_NULL)
	{
		repairUButton = buttons->createButtonId();

		RectF rect = { repRow->buttonUpX(), repRow->y(), repRow->height(), repRow->height() };
		buttons->registerButton(graphics, repairUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(repairUButton);
		buttons->setButtonFuncId(repairUButton, IDB_REPAIRUP);
		buttons->setButtonValInt(repairUButton, PURCH_REP);
		buttons->deactivateButton(repairUButton);
	}
}

void PurchaseSection::configPurchaseBoxFunctions(void (*func0)(int, bool), void (*func1)(int, bool), void (*func2)(int))
{
	showButton = func0;
	hideButton = func1;
	hideButtonNoDraw = func2;
}

void PurchaseSection::configDrawTools(Pen* p0, StringFormat* sf0, Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
{
	backPen = p0;

	purchaseFormat = sf0;
	purchFont = f0;
	costFont = f1;

	tileBrushL = b0;
	tileBrushD = b1;
	clearBrush = b2;
}

void PurchaseSection::resetPurchaseText()
{
	wcsncpy_s(infQ, L"0", 2);
	wcsncpy_s(artQ, L"0", 2);
	wcsncpy_s(mechQ, L"0", 2);
	wcsncpy_s(tankQ, L"0", 2);
	wcsncpy_s(aaaQ, L"0", 2);
	wcsncpy_s(fightQ, L"0", 2);
	wcsncpy_s(tactQ, L"0", 2);
	wcsncpy_s(stratQ, L"0", 2);
	wcsncpy_s(battleQ, L"0", 2);
	wcsncpy_s(airccQ, L"0", 2);
	wcsncpy_s(cruiseQ, L"0", 2);
	wcsncpy_s(destrQ, L"0", 2);
	wcsncpy_s(subQ, L"0", 2);
	wcsncpy_s(transQ, L"0", 2);
	wcsncpy_s(majorQ, L"0", 2);
	wcsncpy_s(minorQ, L"0", 2);
	wcsncpy_s(minorUpQ, L"0", 2);
	wcsncpy_s(airbQ, L"0", 2);
	wcsncpy_s(navbQ, L"0", 2);
	wcsncpy_s(repQ, L"0", 2);
	wcsncpy_s(totQ, L"0", 2);

	wcsncpy_s(infC, L"0", 2);
	wcsncpy_s(artC, L"0", 2);
	wcsncpy_s(mechC, L"0", 2);
	wcsncpy_s(tankC, L"0", 2);
	wcsncpy_s(aaaC, L"0", 2);
	wcsncpy_s(fightC, L"0", 2);
	wcsncpy_s(tactC, L"0", 2);
	wcsncpy_s(stratC, L"0", 2);
	wcsncpy_s(battleC, L"0", 2);
	wcsncpy_s(airccC, L"0", 2);
	wcsncpy_s(cruiseC, L"0", 2);
	wcsncpy_s(destrC, L"0", 2);
	wcsncpy_s(subC, L"0", 2);
	wcsncpy_s(transC, L"0", 2);
	wcsncpy_s(majorC, L"0", 2);
	wcsncpy_s(minorC, L"0", 2);
	wcsncpy_s(minorUpC, L"0", 2);
	wcsncpy_s(airbC, L"0", 2);
	wcsncpy_s(navbC, L"0", 2);
	wcsncpy_s(repC, L"0", 2);
	wcsncpy_s(totC, L"0", 2);
}

void PurchaseSection::updatePurchaseText(bool shipRes)
{
	if (shipRes)
	{
		battleRow->updatePurchaseText(PURCH_ROW_COST, L"17");
		airccRow->updatePurchaseText(PURCH_ROW_COST, L"13");
		cruiseRow->updatePurchaseText(PURCH_ROW_COST, L"9");
		destrRow->updatePurchaseText(PURCH_ROW_COST, L"7");
		subRow->updatePurchaseText(PURCH_ROW_COST, L"5");
		transRow->updatePurchaseText(PURCH_ROW_COST, L"6");
	}
	else
	{
		battleRow->updatePurchaseText(PURCH_ROW_COST, L"20");
		airccRow->updatePurchaseText(PURCH_ROW_COST, L"16");
		cruiseRow->updatePurchaseText(PURCH_ROW_COST, L"12");
		destrRow->updatePurchaseText(PURCH_ROW_COST, L"8");
		subRow->updatePurchaseText(PURCH_ROW_COST, L"6");
		transRow->updatePurchaseText(PURCH_ROW_COST, L"7");
	}
}

void PurchaseSection::updatePurchaseText(Purchase* purchases, int type)
{
	switch (type)
	{
	case PURCH_INF:
	{
		valConv(infQ, purchases[currUKButton].getVal(IDB_INFDN));
		valConv(infC, purchases[currUKButton].getCost(IDB_INFDN));
		break;
	}
	case PURCH_ART:
	{
		valConv(artQ, purchases[currUKButton].getVal(IDB_ARTDN));
		valConv(artC, purchases[currUKButton].getCost(IDB_ARTDN));
		break;
	}
	case PURCH_MECH:
	{
		valConv(mechQ, purchases[currUKButton].getVal(IDB_MECHDN));
		valConv(mechC, purchases[currUKButton].getCost(IDB_MECHDN));
		break;
	}
	case PURCH_TANK:
	{
		valConv(tankQ, purchases[currUKButton].getVal(IDB_TANKDN));
		valConv(tankC, purchases[currUKButton].getCost(IDB_TANKDN));
		break;
	}
	case PURCH_AAA:
	{
		valConv(aaaQ, purchases[currUKButton].getVal(IDB_AAADN));
		valConv(aaaC, purchases[currUKButton].getCost(IDB_AAADN));
		break;
	}
	case PURCH_FIGHT:
	{
		valConv(fightQ, purchases[currUKButton].getVal(IDB_FIGHTDN));
		valConv(fightC, purchases[currUKButton].getCost(IDB_FIGHTDN));
		break;
	}
	case PURCH_TACT:
	{
		valConv(tactQ, purchases[currUKButton].getVal(IDB_TACTDN));
		valConv(tactC, purchases[currUKButton].getCost(IDB_TACTDN));
		break;
	}
	case PURCH_STRAT:
	{
		valConv(stratQ, purchases[currUKButton].getVal(IDB_STRATDN));
		valConv(stratC, purchases[currUKButton].getCost(IDB_STRATDN));
		break;
	}
	case PURCH_BATTLE:
	{
		valConv(battleQ, purchases[currUKButton].getVal(IDB_BATTLEDN));
		valConv(battleC, purchases[currUKButton].getCost(IDB_BATTLEDN));
		break;
	}
	case PURCH_AIRCC:
	{
		valConv(airccQ, purchases[currUKButton].getVal(IDB_AIRCCDN));
		valConv(airccC, purchases[currUKButton].getCost(IDB_AIRCCDN));
		break;
	}
	case PURCH_CRUISE:
	{
		valConv(cruiseQ, purchases[currUKButton].getVal(IDB_CRUISEDN));
		valConv(cruiseC, purchases[currUKButton].getCost(IDB_CRUISEDN));
		break;
	}
	case PURCH_DESTR:
	{
		valConv(destrQ, purchases[currUKButton].getVal(IDB_DESTRDN));
		valConv(destrC, purchases[currUKButton].getCost(IDB_DESTRDN));
		break;
	}
	case PURCH_SUB:
	{
		valConv(subQ, purchases[currUKButton].getVal(IDB_SUBDN));
		valConv(subC, purchases[currUKButton].getCost(IDB_SUBDN));
		break;
	}
	case PURCH_TRANS:
	{
		valConv(transQ, purchases[currUKButton].getVal(IDB_TRANSDN));
		valConv(transC, purchases[currUKButton].getCost(IDB_TRANSDN));
		break;
	}
	case PURCH_MAJOR:
	{
		valConv(majorQ, purchases[currUKButton].getVal(IDB_MAJORDN));
		valConv(majorC, purchases[currUKButton].getCost(IDB_MAJORDN));
		break;
	}
	case PURCH_MINOR:
	{
		valConv(minorQ, purchases[currUKButton].getVal(IDB_MINORDN));
		valConv(minorC, purchases[currUKButton].getCost(IDB_MINORDN));
		break;
	}
	case PURCH_MINORUP:
	{
		valConv(minorUpQ, purchases[currUKButton].getVal(IDB_MINORUPDN));
		valConv(minorUpC, purchases[currUKButton].getCost(IDB_MINORUPDN));
		break;
	}
	case PURCH_AIRB:
	{
		valConv(airbQ, purchases[currUKButton].getVal(IDB_AIRBDN));
		valConv(airbC, purchases[currUKButton].getCost(IDB_AIRBDN));
		break;
	}
	case PURCH_NAVB:
	{
		valConv(navbQ, purchases[currUKButton].getVal(IDB_NAVBDN));
		valConv(navbC, purchases[currUKButton].getCost(IDB_NAVBDN));
		break;
	}
	case PURCH_REP:
	{
		valConv(repQ, purchases[currUKButton].getVal(IDB_REPAIRDN));
		valConv(repC, purchases[currUKButton].getCost(IDB_REPAIRDN));
		break;
	}
	default:
		break;
	}

	int price;
	valConv(totQ, purchases[currUKButton].getTotQuant());
	purchases[currUKButton].calcPrice(price, 0, 0);
	valConv(totC, price);
}

void PurchaseSection::updatePurchaseText(Purchase* purchases, bool currUK)
{
	currUKButton = currUK ? 1 : 0;

	valConv(infQ, purchases[currUKButton].getVal(IDB_INFDN));
	valConv(infC, purchases[currUKButton].getCost(IDB_INFDN));
	valConv(artQ, purchases[currUKButton].getVal(IDB_ARTDN));
	valConv(artC, purchases[currUKButton].getCost(IDB_ARTDN));
	valConv(mechQ, purchases[currUKButton].getVal(IDB_MECHDN));
	valConv(mechC, purchases[currUKButton].getCost(IDB_MECHDN));
	valConv(tankQ, purchases[currUKButton].getVal(IDB_TANKDN));
	valConv(tankC, purchases[currUKButton].getCost(IDB_TANKDN));
	valConv(aaaQ, purchases[currUKButton].getVal(IDB_AAADN));
	valConv(aaaC, purchases[currUKButton].getCost(IDB_AAADN));
	valConv(fightQ, purchases[currUKButton].getVal(IDB_FIGHTDN));
	valConv(fightC, purchases[currUKButton].getCost(IDB_FIGHTDN));
	valConv(tactQ, purchases[currUKButton].getVal(IDB_TACTDN));
	valConv(tactC, purchases[currUKButton].getCost(IDB_TACTDN));
	valConv(stratQ, purchases[currUKButton].getVal(IDB_STRATDN));
	valConv(stratC, purchases[currUKButton].getCost(IDB_STRATDN));
	valConv(battleQ, purchases[currUKButton].getVal(IDB_BATTLEDN));
	valConv(battleC, purchases[currUKButton].getCost(IDB_BATTLEDN));
	valConv(airccQ, purchases[currUKButton].getVal(IDB_AIRCCDN));
	valConv(airccC, purchases[currUKButton].getCost(IDB_AIRCCDN));
	valConv(cruiseQ, purchases[currUKButton].getVal(IDB_CRUISEDN));
	valConv(cruiseC, purchases[currUKButton].getCost(IDB_CRUISEDN));
	valConv(destrQ, purchases[currUKButton].getVal(IDB_DESTRDN));
	valConv(destrC, purchases[currUKButton].getCost(IDB_DESTRDN));
	valConv(subQ, purchases[currUKButton].getVal(IDB_SUBDN));
	valConv(subC, purchases[currUKButton].getCost(IDB_SUBDN));
	valConv(transQ, purchases[currUKButton].getVal(IDB_TRANSDN));
	valConv(transC, purchases[currUKButton].getCost(IDB_TRANSDN));
	valConv(majorQ, purchases[currUKButton].getVal(IDB_MAJORDN));
	valConv(majorC, purchases[currUKButton].getCost(IDB_MAJORDN));
	valConv(minorQ, purchases[currUKButton].getVal(IDB_MINORDN));
	valConv(minorC, purchases[currUKButton].getCost(IDB_MINORDN));
	valConv(minorUpQ, purchases[currUKButton].getVal(IDB_MINORUPDN));
	valConv(minorUpC, purchases[currUKButton].getCost(IDB_MINORUPDN));
	valConv(airbQ, purchases[currUKButton].getVal(IDB_AIRBDN));
	valConv(airbC, purchases[currUKButton].getCost(IDB_AIRBDN));
	valConv(navbQ, purchases[currUKButton].getVal(IDB_NAVBDN));
	valConv(navbC, purchases[currUKButton].getCost(IDB_NAVBDN));
	valConv(repQ, purchases[currUKButton].getVal(IDB_REPAIRDN));
	valConv(repC, purchases[currUKButton].getCost(IDB_REPAIRDN));

	int price;
	valConv(totQ, purchases[currUKButton].getTotQuant());
	purchases[currUKButton].calcPrice(price, 0, 0);
	valConv(totC, price);
}

void PurchaseSection::drawPurchaseBox(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		purchaseFrame->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		purchTitleBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		purchHeadRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		infRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		artRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		mechRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		tankRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		aaaRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		fightRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		tactRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		stratRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		battleRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		airccRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		cruiseRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		destrRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		subRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		transRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		majorRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		minorRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		minorUpRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		airbRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		navbRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		repRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);
		totRow->drawPurchaseRow(graphics, borderPen, purchFont, baseTextFont, centerFormat, centerFormat, textBrush, backBrush, dbg_sections, layers);

		hidePurchaseButtons();		
	}
	else // Actual graphics
	{
		purchTitleBox->drawFrameFill(graphics, pen, baseTitleFont, centerFormat, textBrush, tileBrushD, layers);

		purchHeadRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		infRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		artRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		mechRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		tankRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		aaaRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		fightRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		tactRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		stratRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		battleRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		airccRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		cruiseRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		destrRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		subRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		transRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		majorRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		minorRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		minorUpRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		airbRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		navbRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);
		repRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, dbg_sections, layers);
		totRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, dbg_sections, layers);

		graphics->DrawLine(backPen, *titleP0, *titleP1);
	}
}

void PurchaseSection::drawPurchaseBox(Graphics* graphics, bool resShips, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (!dbg_sections)
	{
		battleRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_COST, false, L"", dbg_sections, layers);
		airccRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_COST, false, L"", dbg_sections, layers);
		cruiseRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_COST, false, L"", dbg_sections, layers);
		destrRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_COST, false, L"", dbg_sections, layers);
		subRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_COST, false, L"", dbg_sections, layers);
		transRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_COST, false, L"", dbg_sections, layers);
	}
}

void PurchaseSection::drawPurchaseBox(Graphics* graphics, int type, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (!dbg_sections)
	{
		switch (type)
		{
		case PURCH_INF:
		{
			infRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, infQ, dbg_sections, layers);
			infRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, infC, dbg_sections, layers);
			break;
		}
		case PURCH_ART:
		{
			artRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, artQ, dbg_sections, layers);
			artRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, artC, dbg_sections, layers);
			break;
		}
		case PURCH_MECH:
		{
			mechRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, mechQ, dbg_sections, layers);
			mechRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, mechC, dbg_sections, layers);
			break;
		}
		case PURCH_TANK:
		{
			tankRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, tankQ, dbg_sections, layers);
			tankRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, tankC, dbg_sections, layers);
			break;
		}
		case PURCH_AAA:
		{
			aaaRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, aaaQ, dbg_sections, layers);
			aaaRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, aaaC, dbg_sections, layers);
			break;
		}
		case PURCH_FIGHT:
		{
			fightRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, fightQ, dbg_sections, layers);
			fightRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, fightC, dbg_sections, layers);
			break;
		}
		case PURCH_TACT:
		{
			tactRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, tactQ, dbg_sections, layers);
			tactRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, tactC, dbg_sections, layers);
			break;
		}
		case PURCH_STRAT:
		{
			stratRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, stratQ, dbg_sections, layers);
			stratRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, stratC, dbg_sections, layers);
			break;
		}
		case PURCH_BATTLE:
		{
			battleRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, battleQ, dbg_sections, layers);
			battleRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, battleC, dbg_sections, layers);
			break;
		}
		case PURCH_AIRCC:
		{
			airccRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, airccQ, dbg_sections, layers);
			airccRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, airccC, dbg_sections, layers);
			break;
		}
		case PURCH_CRUISE:
		{
			cruiseRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, cruiseQ, dbg_sections, layers);
			cruiseRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, cruiseC, dbg_sections, layers);
			break;
		}
		case PURCH_DESTR:
		{
			destrRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, destrQ, dbg_sections, layers);
			destrRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, destrC, dbg_sections, layers);
			break;
		}
		case PURCH_SUB:
		{
			subRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, subQ, dbg_sections, layers);
			subRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, subC, dbg_sections, layers);
			break;
		}
		case PURCH_TRANS:
		{
			transRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, transQ, dbg_sections, layers);
			transRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, transC, dbg_sections, layers);
			break;
		}
		case PURCH_MAJOR:
		{
			majorRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, majorQ, dbg_sections, layers);
			majorRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, majorC, dbg_sections, layers);
			break;
		}
		case PURCH_MINOR:
		{
			minorRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, minorQ, dbg_sections, layers);
			minorRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, minorC, dbg_sections, layers);
			break;
		}
		case PURCH_MINORUP:
		{
			minorUpRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, minorUpQ, dbg_sections, layers);
			minorUpRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, minorUpC, dbg_sections, layers);
			break;
		}
		case PURCH_AIRB:
		{
			airbRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, airbQ, dbg_sections, layers);
			airbRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, airbC, dbg_sections, layers);
			break;
		}
		case PURCH_NAVB:
		{
			navbRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, navbQ, dbg_sections, layers);
			navbRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, navbC, dbg_sections, layers);
			break;
		}
		case PURCH_REP:
		{
			repRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_QUANT, true, repQ, dbg_sections, layers);
			repRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushL, PURCH_ROW_TOTAL, true, repC, dbg_sections, layers);
			break;
		}
		case PURCH_ALL:
		{
			drawPurchaseBox(graphics, dbg_boundbox, dbg_sections, layers);
			break;
		}
		default:
			break;
		}

		totRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_QUANT, true, totQ, dbg_sections, layers);
		totRow->drawPurchaseRow(graphics, pen, purchFont, costFont, purchaseFormat, centerFormat, textBrush, tileBrushD, PURCH_ROW_TOTAL, true, totC, dbg_sections, layers);
	}
}

void PurchaseSection::drawPurchaseBoxButtons(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_sections) // Show box names
		hidePurchaseButtons();
	else // Actual graphics
		showPurchaseButtons();
}

void PurchaseSection::showPurchaseButtons()
{
	showButton(infDButton,     false); showButton(infUButton,     false);
	showButton(artDButton,     false); showButton(artUButton,     false);
	showButton(mechDButton,    false); showButton(mechUButton,    false);
	showButton(tankDButton,    false); showButton(tankUButton,    false);
	showButton(aaaDButton,     false); showButton(aaaUButton,     false);
	showButton(fightDButton,   false); showButton(fightUButton,   false);
	showButton(tactDButton,    false); showButton(tactUButton,    false);
	showButton(stratDButton,   false); showButton(stratUButton,   false);
	showButton(battleDButton,  false); showButton(battleUButton,  false);
	showButton(airccDButton,   false); showButton(airccUButton,   false);
	showButton(cruiseDButton,  false); showButton(cruiseUButton,  false);
	showButton(destrDButton,   false); showButton(destrUButton,   false);
	showButton(subDButton,     false); showButton(subUButton,     false);
	showButton(transDButton,   false); showButton(transUButton,   false);
	showButton(majorDButton,   false); showButton(majorUButton,   false);
	showButton(minorDButton,   false); showButton(minorUButton,   false);
	showButton(minorUpDButton, false); showButton(minorUpUButton, false);
	showButton(airbDButton,    false); showButton(airbUButton,    false);
	showButton(navbDButton,    false); showButton(navbUButton,    false);
	showButton(repairDButton,  false); showButton(repairUButton,  false);
}

void PurchaseSection::showPurchaseButtons(int id)
{
	switch (id)
	{
	case PURCH_INF:
		showButton(infDButton,     false); showButton(infUButton,     false);
		break;
	case PURCH_ART:
		showButton(artDButton,     false); showButton(artUButton,     false);
		break;
	case PURCH_MECH:
		showButton(mechDButton,    false); showButton(mechUButton,    false);
		break;
	case PURCH_TANK:
		showButton(tankDButton,    false); showButton(tankUButton,    false);
		break;
	case PURCH_AAA:
		showButton(aaaDButton,     false); showButton(aaaUButton,     false);
		break;
	case PURCH_FIGHT:
		showButton(fightDButton,   false); showButton(fightUButton,   false);
		break;
	case PURCH_TACT:
		showButton(tactDButton,    false); showButton(tactUButton,    false);
		break;
	case PURCH_STRAT:
		showButton(stratDButton,   false); showButton(stratUButton,   false);
		break;
	case PURCH_BATTLE:
		showButton(battleDButton,  false); showButton(battleUButton,  false);
		break;
	case PURCH_AIRCC:
		showButton(airccDButton,   false); showButton(airccUButton,   false);
		break;
	case PURCH_CRUISE:
		showButton(cruiseDButton,  false); showButton(cruiseUButton,  false);
		break;
	case PURCH_DESTR:
		showButton(destrDButton,   false); showButton(destrUButton,   false);
		break;
	case PURCH_SUB:
		showButton(subDButton,     false); showButton(subUButton,     false);
		break;
	case PURCH_TRANS:
		showButton(transDButton,   false); showButton(transUButton,   false);
		break;
	case PURCH_MAJOR:
		showButton(majorDButton,   false); showButton(majorUButton,   false);
		break;
	case PURCH_MINOR:
		showButton(minorDButton,   false); showButton(minorUButton,   false);
		break;
	case PURCH_MINORUP:
		showButton(minorUpDButton, false); showButton(minorUpUButton, false);
		break;
	case PURCH_AIRB:
		showButton(airbDButton,    false); showButton(airbUButton,    false);
		break;
	case PURCH_NAVB:
		showButton(navbDButton,    false); showButton(navbUButton,    false);
		break;
	case PURCH_REP:
		showButton(repairDButton,  false); showButton(repairUButton,  false);
		break;
	default:
		break;
	}
}

void PurchaseSection::hidePurchaseButtons(bool draw)
{
	if (draw)
	{
		hideButton(infDButton,     false); hideButton(infUButton,     false);
		hideButton(artDButton,     false); hideButton(artUButton,     false);
		hideButton(mechDButton,    false); hideButton(mechUButton,    false);
		hideButton(tankDButton,    false); hideButton(tankUButton,    false);
		hideButton(aaaDButton,     false); hideButton(aaaUButton,     false);
		hideButton(fightDButton,   false); hideButton(fightUButton,   false);
		hideButton(tactDButton,    false); hideButton(tactUButton,    false);
		hideButton(stratDButton,   false); hideButton(stratUButton,   false);
		hideButton(battleDButton,  false); hideButton(battleUButton,  false);
		hideButton(airccDButton,   false); hideButton(airccUButton,   false);
		hideButton(cruiseDButton,  false); hideButton(cruiseUButton,  false);
		hideButton(destrDButton,   false); hideButton(destrUButton,   false);
		hideButton(subDButton,     false); hideButton(subUButton,     false);
		hideButton(transDButton,   false); hideButton(transUButton,   false);
		hideButton(majorDButton,   false); hideButton(majorUButton,   false);
		hideButton(minorDButton,   false); hideButton(minorUButton,   false);
		hideButton(minorUpDButton, false); hideButton(minorUpUButton, false);
		hideButton(airbDButton,    false); hideButton(airbUButton,    false);
		hideButton(navbDButton,    false); hideButton(navbUButton,    false);
		hideButton(repairDButton,  false); hideButton(repairUButton,  false);
	}
	else
	{
		hideButtonNoDraw(infDButton    ); hideButtonNoDraw(infUButton    );
		hideButtonNoDraw(artDButton    ); hideButtonNoDraw(artUButton    );
		hideButtonNoDraw(mechDButton   ); hideButtonNoDraw(mechUButton   );
		hideButtonNoDraw(tankDButton   ); hideButtonNoDraw(tankUButton   );
		hideButtonNoDraw(aaaDButton    ); hideButtonNoDraw(aaaUButton    );
		hideButtonNoDraw(fightDButton  ); hideButtonNoDraw(fightUButton  );
		hideButtonNoDraw(tactDButton   ); hideButtonNoDraw(tactUButton   );
		hideButtonNoDraw(stratDButton  ); hideButtonNoDraw(stratUButton  );
		hideButtonNoDraw(battleDButton ); hideButtonNoDraw(battleUButton );
		hideButtonNoDraw(airccDButton  ); hideButtonNoDraw(airccUButton  );
		hideButtonNoDraw(cruiseDButton ); hideButtonNoDraw(cruiseUButton );
		hideButtonNoDraw(destrDButton  ); hideButtonNoDraw(destrUButton  );
		hideButtonNoDraw(subDButton    ); hideButtonNoDraw(subUButton    );
		hideButtonNoDraw(transDButton  ); hideButtonNoDraw(transUButton  );
		hideButtonNoDraw(majorDButton  ); hideButtonNoDraw(majorUButton  );
		hideButtonNoDraw(minorDButton  ); hideButtonNoDraw(minorUButton  );
		hideButtonNoDraw(minorUpDButton); hideButtonNoDraw(minorUpUButton);
		hideButtonNoDraw(airbDButton   ); hideButtonNoDraw(airbUButton   );
		hideButtonNoDraw(navbDButton   ); hideButtonNoDraw(navbUButton   );
		hideButtonNoDraw(repairDButton ); hideButtonNoDraw(repairUButton );
	}
}

REAL PurchaseSection::getBoxEdge(int whichBox, int edge)
{
	AABox* tmp = purchaseFrame;

	switch (whichBox)
	{
	case PURCH_TITLE:
		tmp = purchTitleBox;
		break;
	case PURCH_HEAD:
		tmp = purchHeadRow->getBox();
		break;
	case PURCH_INF:
		tmp = infRow->getBox();
		break;
	case PURCH_ART:
		tmp = artRow->getBox();
		break;
	case PURCH_MECH:
		tmp = mechRow->getBox();
		break;
	case PURCH_TANK:
		tmp = tankRow->getBox();
		break;
	case PURCH_AAA:
		tmp = aaaRow->getBox();
		break;
	case PURCH_FIGHT:
		tmp = fightRow->getBox();
		break;
	case PURCH_TACT:
		tmp = tactRow->getBox();
		break;
	case PURCH_STRAT:
		tmp = stratRow->getBox();
		break;
	case PURCH_BATTLE:
		tmp = battleRow->getBox();
		break;
	case PURCH_AIRCC:
		tmp = airccRow->getBox();
		break;
	case PURCH_CRUISE:
		tmp = cruiseRow->getBox();
		break;
	case PURCH_DESTR:
		tmp = destrRow->getBox();
		break;
	case PURCH_SUB:
		tmp = subRow->getBox();
		break;
	case PURCH_TRANS:
		tmp = transRow->getBox();
		break;
	case PURCH_MAJOR:
		tmp = majorRow->getBox();
		break;
	case PURCH_MINOR:
		tmp = minorRow->getBox();
		break;
	case PURCH_MINORUP:
		tmp = minorUpRow->getBox();
		break;
	case PURCH_AIRB:
		tmp = airbRow->getBox();
		break;
	case PURCH_NAVB:
		tmp = navbRow->getBox();
		break;
	case PURCH_REP:
		tmp = repRow->getBox();
		break;
	case PURCH_TOT:
		tmp = totRow->getBox();
		break;
	default:
		tmp = purchaseFrame;
		break;
	}

	switch (edge)
	{
	case BOX_LEFT:
		return tmp->box.GetLeft();
		break;
	case BOX_RIGHT:
		return tmp->box.GetRight();
		break;
	case BOX_TOP:
		return tmp->box.GetTop();
		break;
	case BOX_BOTTOM:
		return tmp->box.GetBottom();
		break;
	case BOX_WIDTH:
		return tmp->box.Width;
		break;
	case BOX_HEIGHT:
		return tmp->box.Height;
		break;
	default:
		return 0;
		break;
	}
}

void PurchaseSection::valConv(WCHAR* c, int val)
{
	if (val > 99)
	{
		c[0] = uint2char_(val / 100);
		c[1] = uint2char_((val % 100) / 10);
		c[2] = uint2char_(val % 10);
		c[3] = '\0';
	}
	else if (val > 9)
	{
		c[0] = uint2char_(val / 10);
		c[1] = uint2char_(val % 10);
		c[2] = '\0';
	}
	else
	{
		c[0] = uint2char_(val);
		c[1] = '\0';
	}
}
