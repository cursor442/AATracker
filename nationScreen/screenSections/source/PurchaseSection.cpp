#include "../header/PurchaseSection.h"

PurchaseSection::PurchaseSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	purchaseFrame = new AABox("Purchase Section");

	purchTitleBox = new AABox("Purchase New Units");
	purchHeadBox = new AABox("Header");
	infBox = new AABox("Infantry");
	artBox = new AABox("Artillery");
	mechBox = new AABox("Mechanized");
	tankBox = new AABox("Tank");
	aaaBox = new AABox("AAA");
	fightBox = new AABox("Fighter");
	tactBox = new AABox("Tactical");
	stratBox = new AABox("Strategic");
	battleBox = new AABox("Battleship");
	airccBox = new AABox("Aircraft");
	cruiseBox = new AABox("Cruiser");
	destrBox = new AABox("Destroyer");
	subBox = new AABox("Submarine");
	transBox = new AABox("Transport");
	majorBox = new AABox("Major");
	minorBox = new AABox("Minor");
	minorUpBox = new AABox("Upgrade");
	airbBox = new AABox("Air");
	navbBox = new AABox("Naval");
	repBox = new AABox("Repair");
	totBox = new AABox("Total");

	infQBox = new AABox("I");
	artQBox = new AABox("A");
	mechQBox = new AABox("M");
	tankQBox = new AABox("T");
	aaaQBox = new AABox("A");
	fightQBox = new AABox("F");
	tactQBox = new AABox("T");
	stratQBox = new AABox("S");
	battleQBox = new AABox("B");
	airccQBox = new AABox("A");
	cruiseQBox = new AABox("C");
	destrQBox = new AABox("D");
	subQBox = new AABox("S");
	transQBox = new AABox("T");
	majorQBox = new AABox("M");
	minorQBox = new AABox("M");
	minorUpQBox = new AABox("U");
	airbQBox = new AABox("A");
	navbQBox = new AABox("N");
	repQBox = new AABox("R");
	totQBox = new AABox("T");

	infCBox = new AABox("I");
	artCBox = new AABox("A");
	mechCBox = new AABox("M");
	tankCBox = new AABox("T");
	aaaCBox = new AABox("A");
	fightCBox = new AABox("F");
	tactCBox = new AABox("T");
	stratCBox = new AABox("S");
	battleCBox = new AABox("B");
	airccCBox = new AABox("A");
	cruiseCBox = new AABox("C");
	destrCBox = new AABox("D");
	subCBox = new AABox("S");
	transCBox = new AABox("T");
	majorCBox = new AABox("M");
	minorCBox = new AABox("M");
	minorUpCBox = new AABox("U");
	airbCBox = new AABox("A");
	navbCBox = new AABox("N");
	repCBox = new AABox("R");
	totCBox = new AABox("T");

	battleBoxU = new AABox("  17"); 
	airccBoxU = new AABox("  13"); 
	cruiseBoxU = new AABox("   9"); 
	destrBoxU = new AABox("   7");
	subBoxU = new AABox("   5"); 
	transBoxU = new AABox("   6");

	titleP0 = NULL; titleP1 = NULL;

	main_Wnd = NULL;

	buttons = NULL;
	showButton = NULL;
	hideButton = NULL;

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

	WCHAR head[]    = L" Unit Stats:\tCost\tAttack\tDefense\tMove\tQuantity\tCost";
	WCHAR inf[]     = L" Infantry\t   3\t     1\t      2\t     1";
	WCHAR art[]     = L" Artillery\t   4\t     2\t      2\t     1";
	WCHAR mech[]    = L" Mechanized Infantry\t   4\t     1\t      2\t     2";
	WCHAR tank[]    = L" Tank\t   6\t     3\t      3\t     2";
	WCHAR aaa[]     = L" AAA\t   5\t\t      1\t     1";
	WCHAR fight[]   = L" Fighter\t  10\t     3\t      4\t     4";
	WCHAR tact[]    = L" Tactical Bomber\t  11\t     3\t      3\t     4";
	WCHAR strat[]   = L" Strategic Bomber\t  12\t     4\t      1\t     6";
	WCHAR battle[]  = L" Battleship\t  20\t     4\t      4\t     2";
	WCHAR aircc[]   = L" Aircraft Carrier\t  16\t\t      2\t     2";
	WCHAR cruise[]  = L" Cruiser\t  12\t     3\t      3\t     2";
	WCHAR destr[]   = L" Destroyer\t   8\t     2\t      2\t     2";
	WCHAR sub[]     = L" Submarine\t   6\t     2\t      1\t     2";
	WCHAR trans[]   = L" Transport\t   7\t\t\t     2";
	WCHAR major[]   = L" Major Industrial Complex\t  30";
	WCHAR minor[]   = L" Minor Industrial Complex\t  12";
	WCHAR minorUp[] = L"     Upgrade Minor IC\t  20";
	WCHAR airb[]    = L" Air Base\t  15";
	WCHAR navb[]    = L" Naval Base\t  15";
	WCHAR rep[]     = L" Repairs\t   1";
	WCHAR tot[]     = L" Total:";

	wcsncpy_s(purchHeadText, head, ARRAYSIZE(head));
	wcsncpy_s(infText, inf, ARRAYSIZE(inf));
	wcsncpy_s(artText, art, ARRAYSIZE(art));
	wcsncpy_s(mechText, mech, ARRAYSIZE(mech));
	wcsncpy_s(tankText, tank, ARRAYSIZE(tank));
	wcsncpy_s(aaaText, aaa, ARRAYSIZE(aaa));
	wcsncpy_s(fightText, fight, ARRAYSIZE(fight));
	wcsncpy_s(tactText, tact, ARRAYSIZE(tact));
	wcsncpy_s(stratText, strat, ARRAYSIZE(strat));
	wcsncpy_s(battleText, battle, ARRAYSIZE(battle));
	wcsncpy_s(airccText, aircc, ARRAYSIZE(aircc));
	wcsncpy_s(cruiseText, cruise, ARRAYSIZE(cruise));
	wcsncpy_s(destrText, destr, ARRAYSIZE(destr));
	wcsncpy_s(subText, sub, ARRAYSIZE(sub));
	wcsncpy_s(transText, trans, ARRAYSIZE(trans));
	wcsncpy_s(majorText, major, ARRAYSIZE(major));
	wcsncpy_s(minorText, minor, ARRAYSIZE(minor));
	wcsncpy_s(minorUpText, minorUp, ARRAYSIZE(minorUp));
	wcsncpy_s(airbText, airb, ARRAYSIZE(airb));
	wcsncpy_s(navbText, navb, ARRAYSIZE(navb));
	wcsncpy_s(repText, rep, ARRAYSIZE(rep));
	wcsncpy_s(totText, tot, ARRAYSIZE(tot));

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
	delete purchHeadBox;
	delete infBox;
	delete artBox;
	delete mechBox;
	delete tankBox;
	delete aaaBox;
	delete fightBox;
	delete tactBox;
	delete stratBox;
	delete battleBox;
	delete airccBox;
	delete cruiseBox;
	delete destrBox;
	delete subBox;
	delete transBox;
	delete majorBox;
	delete minorBox;
	delete minorUpBox;
	delete airbBox;
	delete navbBox;
	delete repBox;
	delete totBox;

	delete infQBox;
	delete artQBox;
	delete mechQBox;
	delete tankQBox;
	delete aaaQBox;
	delete fightQBox;
	delete tactQBox;
	delete stratQBox;
	delete battleQBox;
	delete airccQBox;
	delete cruiseQBox;
	delete destrQBox;
	delete subQBox;
	delete transQBox;
	delete majorQBox;
	delete minorQBox;
	delete minorUpQBox;
	delete airbQBox;
	delete navbQBox;
	delete repQBox;
	delete totQBox;

	delete infCBox;
	delete artCBox;
	delete mechCBox;
	delete tankCBox;
	delete aaaCBox;
	delete fightCBox;
	delete tactCBox;
	delete stratCBox;
	delete battleCBox;
	delete airccCBox;
	delete cruiseCBox;
	delete destrCBox;
	delete subCBox;
	delete transCBox;
	delete majorCBox;
	delete minorCBox;
	delete minorUpCBox;
	delete airbCBox;
	delete navbCBox;
	delete repCBox;
	delete totCBox;

	delete battleBoxU;
	delete airccBoxU;
	delete cruiseBoxU;
	delete destrBoxU;
	delete subBoxU;
	delete transBoxU;

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

	purchHeadBox->config(purchTitleBox->box, layer + 1);
	purchHeadBox->box.Y = purchTitleBox->box.GetBottom();
	purchHeadBox->box.Height = frame.Height / 25;

	infBox->config(purchHeadBox->box, layer + 1);
	infBox->box.Y = purchHeadBox->box.GetBottom();

	artBox->config(infBox->box, layer + 1);
	artBox->box.Y = infBox->box.GetBottom();

	mechBox->config(artBox->box, layer + 1);
	mechBox->box.Y = artBox->box.GetBottom();

	tankBox->config(mechBox->box, layer + 1);
	tankBox->box.Y = mechBox->box.GetBottom();

	aaaBox->config(tankBox->box, layer + 1);
	aaaBox->box.Y = tankBox->box.GetBottom();

	fightBox->config(aaaBox->box, layer + 1);
	fightBox->box.Y = aaaBox->box.GetBottom();

	tactBox->config(fightBox->box, layer + 1);
	tactBox->box.Y = fightBox->box.GetBottom();

	stratBox->config(tactBox->box, layer + 1);
	stratBox->box.Y = tactBox->box.GetBottom();

	battleBox->config(stratBox->box, layer + 1);
	battleBox->box.Y = stratBox->box.GetBottom();

	airccBox->config(battleBox->box, layer + 1);
	airccBox->box.Y = battleBox->box.GetBottom();

	cruiseBox->config(airccBox->box, layer + 1);
	cruiseBox->box.Y = airccBox->box.GetBottom();

	destrBox->config(cruiseBox->box, layer + 1);
	destrBox->box.Y = cruiseBox->box.GetBottom();

	subBox->config(destrBox->box, layer + 1);
	subBox->box.Y = destrBox->box.GetBottom();

	transBox->config(subBox->box, layer + 1);
	transBox->box.Y = subBox->box.GetBottom();

	majorBox->config(transBox->box, layer + 1);
	majorBox->box.Y = transBox->box.GetBottom();

	minorBox->config(majorBox->box, layer + 1);
	minorBox->box.Y = majorBox->box.GetBottom();

	minorUpBox->config(minorBox->box, layer + 1);
	minorUpBox->box.Y = minorBox->box.GetBottom();

	airbBox->config(minorUpBox->box, layer + 1);
	airbBox->box.Y = minorUpBox->box.GetBottom();

	navbBox->config(airbBox->box, layer + 1);
	navbBox->box.Y = airbBox->box.GetBottom();

	repBox->config(navbBox->box, layer + 1);
	repBox->box.Y = navbBox->box.GetBottom();

	totBox->config(repBox->box, layer + 1);
	totBox->box.Y = repBox->box.GetBottom();
	totBox->box.Height = frame.GetBottom() - totBox->box.Y;

	configPurchaseButtons(graphics, buttons, purchaseButton);

	infQBox->config(infBox->box, layer + 2);
	infQBox->box.X = PURCH_BUTTON_D_OFFSET + infBox->box.Height + 1;
	infQBox->box.Width = PURCH_BUTTON_U_OFFSET - infQBox->box.X - 1;

	artQBox->config(infQBox->box, layer + 2);
	artQBox->box.Y = infQBox->box.GetBottom();

	mechQBox->config(artQBox->box, layer + 2);
	mechQBox->box.Y = artQBox->box.GetBottom();

	tankQBox->config(mechQBox->box, layer + 2);
	tankQBox->box.Y = mechQBox->box.GetBottom();

	aaaQBox->config(tankQBox->box, layer + 2);
	aaaQBox->box.Y = tankQBox->box.GetBottom();

	fightQBox->config(aaaQBox->box, layer + 2);
	fightQBox->box.Y = aaaQBox->box.GetBottom();

	tactQBox->config(fightQBox->box, layer + 2);
	tactQBox->box.Y = fightQBox->box.GetBottom();

	stratQBox->config(tactQBox->box, layer + 2);
	stratQBox->box.Y = tactQBox->box.GetBottom();

	battleQBox->config(stratQBox->box, layer + 2);
	battleQBox->box.Y = stratQBox->box.GetBottom();

	airccQBox->config(battleQBox->box, layer + 2);
	airccQBox->box.Y = battleQBox->box.GetBottom();

	cruiseQBox->config(airccQBox->box, layer + 2);
	cruiseQBox->box.Y = airccQBox->box.GetBottom();

	destrQBox->config(cruiseQBox->box, layer + 2);
	destrQBox->box.Y = cruiseQBox->box.GetBottom();

	subQBox->config(destrQBox->box, layer + 2);
	subQBox->box.Y = destrQBox->box.GetBottom();

	transQBox->config(subQBox->box, layer + 2);
	transQBox->box.Y = subQBox->box.GetBottom();

	majorQBox->config(transQBox->box, layer + 2);
	majorQBox->box.Y = transQBox->box.GetBottom();

	minorQBox->config(majorQBox->box, layer + 2);
	minorQBox->box.Y = majorQBox->box.GetBottom();

	minorUpQBox->config(minorQBox->box, layer + 2);
	minorUpQBox->box.Y = minorQBox->box.GetBottom();

	airbQBox->config(minorUpQBox->box, layer + 2);
	airbQBox->box.Y = minorUpQBox->box.GetBottom();

	navbQBox->config(airbQBox->box, layer + 2);
	navbQBox->box.Y = airbQBox->box.GetBottom();

	repQBox->config(navbQBox->box, layer + 2);
	repQBox->box.Y = navbQBox->box.GetBottom();

	totQBox->config(repQBox->box, layer + 2);
	totQBox->box.Y = repQBox->box.GetBottom();
	totQBox->box.Height = purchaseFrame->box.GetBottom() - totQBox->box.Y;

	infCBox->config(infBox->box, layer + 2);
	infCBox->box.X = PURCH_BUTTON_U_OFFSET + infBox->box.Height + 1;
	infCBox->box.Width = purchaseFrame->box.GetRight() - infCBox->box.X - 1;

	artCBox->config(infCBox->box, layer + 2);
	artCBox->box.Y = infCBox->box.GetBottom();

	mechCBox->config(artCBox->box, layer + 2);
	mechCBox->box.Y = artCBox->box.GetBottom();

	tankCBox->config(mechCBox->box, layer + 2);
	tankCBox->box.Y = mechCBox->box.GetBottom();

	aaaCBox->config(tankCBox->box, layer + 2);
	aaaCBox->box.Y = tankCBox->box.GetBottom();

	fightCBox->config(aaaCBox->box, layer + 2);
	fightCBox->box.Y = aaaCBox->box.GetBottom();

	tactCBox->config(fightCBox->box, layer + 2);
	tactCBox->box.Y = fightCBox->box.GetBottom();

	stratCBox->config(tactCBox->box, layer + 2);
	stratCBox->box.Y = tactCBox->box.GetBottom();

	battleCBox->config(stratCBox->box, layer + 2);
	battleCBox->box.Y = stratCBox->box.GetBottom();

	airccCBox->config(battleCBox->box, layer + 2);
	airccCBox->box.Y = battleCBox->box.GetBottom();

	cruiseCBox->config(airccCBox->box, layer + 2);
	cruiseCBox->box.Y = airccCBox->box.GetBottom();

	destrCBox->config(cruiseCBox->box, layer + 2);
	destrCBox->box.Y = cruiseCBox->box.GetBottom();

	subCBox->config(destrCBox->box, layer + 2);
	subCBox->box.Y = destrCBox->box.GetBottom();

	transCBox->config(subCBox->box, layer + 2);
	transCBox->box.Y = subCBox->box.GetBottom();

	majorCBox->config(transCBox->box, layer + 2);
	majorCBox->box.Y = transCBox->box.GetBottom();

	minorCBox->config(majorCBox->box, layer + 2);
	minorCBox->box.Y = majorCBox->box.GetBottom();

	minorUpCBox->config(minorCBox->box, layer + 2);
	minorUpCBox->box.Y = minorCBox->box.GetBottom();

	airbCBox->config(minorUpCBox->box, layer + 2);
	airbCBox->box.Y = minorUpCBox->box.GetBottom();

	navbCBox->config(airbCBox->box, layer + 2);
	navbCBox->box.Y = airbCBox->box.GetBottom();

	repCBox->config(navbCBox->box, layer + 2);
	repCBox->box.Y = navbCBox->box.GetBottom();

	totCBox->config(repCBox->box, layer + 2);
	totCBox->box.Y = repCBox->box.GetBottom();
	totCBox->box.Height = purchaseFrame->box.GetBottom() - totCBox->box.Y;

	REAL firstTabOffset;
	REAL tabStops[6];
	purchaseFormat->GetTabStops(6, &firstTabOffset, tabStops);

	REAL X = purchaseFrame->box.X + firstTabOffset + tabStops[0];

	battleBoxU->config(battleBox->box, layer + 2);
	battleBoxU->box.X = X;
	battleBoxU->box.Width = tabStops[1];

	airccBoxU->config(airccBox->box, layer + 2);
	airccBoxU->box.X = X;
	airccBoxU->box.Width = tabStops[1];

	cruiseBoxU->config(cruiseBox->box, layer + 2);
	cruiseBoxU->box.X = X;
	cruiseBoxU->box.Width = tabStops[1];

	destrBoxU->config(destrBox->box, layer + 2);
	destrBoxU->box.X = X;
	destrBoxU->box.Width = tabStops[1];

	subBoxU->config(subBox->box, layer + 2);
	subBoxU->box.X = X;
	subBoxU->box.Width = tabStops[1];

	transBoxU->config(transBox->box, layer + 2);
	transBoxU->box.X = X;
	transBoxU->box.Width = tabStops[1];
}

void PurchaseSection::configPurchaseButtons(Graphics* graphics, AAButtons* btns, void (*purchaseButton)(HWND&, int))
{
	buttons = btns;

	if (infDButton == BB_ID_NULL)
	{
		infDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, infBox->box.Y, infBox->box.Height, infBox->box.Height };
		buttons->registerButton(graphics, infDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(infDButton);
		buttons->setButtonFuncId(infDButton, IDB_INFDN);
		buttons->setButtonValInt(infDButton, PURCH_INF);
		buttons->deactivateButton(infDButton);
	}
	if (infUButton == BB_ID_NULL)
	{
		infUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, infBox->box.Y, infBox->box.Height, infBox->box.Height };
		buttons->registerButton(graphics, infUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(infUButton);
		buttons->setButtonFuncId(infUButton, IDB_INFUP);
		buttons->setButtonValInt(infUButton, PURCH_INF);
		buttons->deactivateButton(infUButton);
	}

	if (artDButton == BB_ID_NULL)
	{
		artDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, artBox->box.Y, artBox->box.Height, artBox->box.Height };
		buttons->registerButton(graphics, artDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(artDButton);
		buttons->setButtonFuncId(artDButton, IDB_ARTDN);
		buttons->setButtonValInt(artDButton, PURCH_ART);
		buttons->deactivateButton(artDButton);
	}
	if (artUButton == BB_ID_NULL)
	{
		artUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, artBox->box.Y, artBox->box.Height, artBox->box.Height };
		buttons->registerButton(graphics, artUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(artUButton);
		buttons->setButtonFuncId(artUButton, IDB_ARTUP);
		buttons->setButtonValInt(artUButton, PURCH_ART);
		buttons->deactivateButton(artUButton);
	}

	if (mechDButton == BB_ID_NULL)
	{
		mechDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, mechBox->box.Y, mechBox->box.Height, mechBox->box.Height };
		buttons->registerButton(graphics, mechDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(mechDButton);
		buttons->setButtonFuncId(mechDButton, IDB_MECHDN);
		buttons->setButtonValInt(mechDButton, PURCH_MECH);
		buttons->deactivateButton(mechDButton);
	}
	if (mechUButton == BB_ID_NULL)
	{
		mechUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, mechBox->box.Y, mechBox->box.Height, mechBox->box.Height };
		buttons->registerButton(graphics, mechUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(mechUButton);
		buttons->setButtonFuncId(mechUButton, IDB_MECHUP);
		buttons->setButtonValInt(mechUButton, PURCH_MECH);
		buttons->deactivateButton(mechUButton);
	}

	if (tankDButton == BB_ID_NULL)
	{
		tankDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, tankBox->box.Y, tankBox->box.Height, tankBox->box.Height };
		buttons->registerButton(graphics, tankDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(tankDButton);
		buttons->setButtonFuncId(tankDButton, IDB_TANKDN);
		buttons->setButtonValInt(tankDButton, PURCH_TANK);
		buttons->deactivateButton(tankDButton);
	}
	if (tankUButton == BB_ID_NULL)
	{
		tankUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, tankBox->box.Y, tankBox->box.Height, tankBox->box.Height };
		buttons->registerButton(graphics, tankUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(tankUButton);
		buttons->setButtonFuncId(tankUButton, IDB_TANKUP);
		buttons->setButtonValInt(tankUButton, PURCH_TANK);
		buttons->deactivateButton(tankUButton);
	}

	if (aaaDButton == BB_ID_NULL)
	{
		aaaDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, aaaBox->box.Y, aaaBox->box.Height, aaaBox->box.Height };
		buttons->registerButton(graphics, aaaDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(aaaDButton);
		buttons->setButtonFuncId(aaaDButton, IDB_AAADN);
		buttons->setButtonValInt(aaaDButton, PURCH_AAA);
		buttons->deactivateButton(aaaDButton);
	}
	if (aaaUButton == BB_ID_NULL)
	{
		aaaUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, aaaBox->box.Y, aaaBox->box.Height, aaaBox->box.Height };
		buttons->registerButton(graphics, aaaUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(aaaUButton);
		buttons->setButtonFuncId(aaaUButton, IDB_AAAUP);
		buttons->setButtonValInt(aaaUButton, PURCH_AAA);
		buttons->deactivateButton(aaaUButton);
	}

	if (fightDButton == BB_ID_NULL)
	{
		fightDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, fightBox->box.Y, fightBox->box.Height, fightBox->box.Height };
		buttons->registerButton(graphics, fightDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(fightDButton);
		buttons->setButtonFuncId(fightDButton, IDB_FIGHTDN);
		buttons->setButtonValInt(fightDButton, PURCH_FIGHT);
		buttons->deactivateButton(fightDButton);
	}
	if (fightUButton == BB_ID_NULL)
	{
		fightUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, fightBox->box.Y, fightBox->box.Height, fightBox->box.Height };
		buttons->registerButton(graphics, fightUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(fightUButton);
		buttons->setButtonFuncId(fightUButton, IDB_FIGHTUP);
		buttons->setButtonValInt(fightUButton, PURCH_FIGHT);
		buttons->deactivateButton(fightUButton);
	}

	if (tactDButton == BB_ID_NULL)
	{
		tactDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, tactBox->box.Y, tactBox->box.Height, tactBox->box.Height };
		buttons->registerButton(graphics, tactDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(tactDButton);
		buttons->setButtonFuncId(tactDButton, IDB_TACTDN);
		buttons->setButtonValInt(tactDButton, PURCH_TACT);
		buttons->deactivateButton(tactDButton);
	}
	if (tactUButton == BB_ID_NULL)
	{
		tactUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, tactBox->box.Y, tactBox->box.Height, tactBox->box.Height };
		buttons->registerButton(graphics, tactUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(tactUButton);
		buttons->setButtonFuncId(tactUButton, IDB_TACTUP);
		buttons->setButtonValInt(tactUButton, PURCH_TACT);
		buttons->deactivateButton(tactUButton);
	}

	if (stratDButton == BB_ID_NULL)
	{
		stratDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, stratBox->box.Y, stratBox->box.Height, stratBox->box.Height };
		buttons->registerButton(graphics, stratDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(stratDButton);
		buttons->setButtonFuncId(stratDButton, IDB_STRATDN);
		buttons->setButtonValInt(stratDButton, PURCH_STRAT);
		buttons->deactivateButton(stratDButton);
	}
	if (stratUButton == BB_ID_NULL)
	{
		stratUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, stratBox->box.Y, stratBox->box.Height, stratBox->box.Height };
		buttons->registerButton(graphics, stratUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(stratUButton);
		buttons->setButtonFuncId(stratUButton, IDB_STRATUP);
		buttons->setButtonValInt(stratUButton, PURCH_STRAT);
		buttons->deactivateButton(stratUButton);
	}

	if (battleDButton == BB_ID_NULL)
	{
		battleDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, battleBox->box.Y, battleBox->box.Height, battleBox->box.Height };
		buttons->registerButton(graphics, battleDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(battleDButton);
		buttons->setButtonFuncId(battleDButton, IDB_BATTLEDN);
		buttons->setButtonValInt(battleDButton, PURCH_BATTLE);
		buttons->deactivateButton(battleDButton);
	}
	if (battleUButton == BB_ID_NULL)
	{
		battleUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, battleBox->box.Y, battleBox->box.Height, battleBox->box.Height };
		buttons->registerButton(graphics, battleUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(battleUButton);
		buttons->setButtonFuncId(battleUButton, IDB_BATTLEUP);
		buttons->setButtonValInt(battleUButton, PURCH_BATTLE);
		buttons->deactivateButton(battleUButton);
	}

	if (airccDButton == BB_ID_NULL)
	{
		airccDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, airccBox->box.Y, airccBox->box.Height, airccBox->box.Height };
		buttons->registerButton(graphics, airccDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(airccDButton);
		buttons->setButtonFuncId(airccDButton, IDB_AIRCCDN);
		buttons->setButtonValInt(airccDButton, PURCH_AIRCC);
		buttons->deactivateButton(airccDButton);
	}
	if (airccUButton == BB_ID_NULL)
	{
		airccUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, airccBox->box.Y, airccBox->box.Height, airccBox->box.Height };
		buttons->registerButton(graphics, airccUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(airccUButton);
		buttons->setButtonFuncId(airccUButton, IDB_AIRCCUP);
		buttons->setButtonValInt(airccUButton, PURCH_AIRCC);
		buttons->deactivateButton(airccUButton);
	}

	if (cruiseDButton == BB_ID_NULL)
	{
		cruiseDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, cruiseBox->box.Y, cruiseBox->box.Height, cruiseBox->box.Height };
		buttons->registerButton(graphics, cruiseDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(cruiseDButton);
		buttons->setButtonFuncId(cruiseDButton, IDB_CRUISEDN);
		buttons->setButtonValInt(cruiseDButton, PURCH_CRUISE);
		buttons->deactivateButton(cruiseDButton);
	}
	if (cruiseUButton == BB_ID_NULL)
	{
		cruiseUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, cruiseBox->box.Y, cruiseBox->box.Height, cruiseBox->box.Height };
		buttons->registerButton(graphics, cruiseUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(cruiseUButton);
		buttons->setButtonFuncId(cruiseUButton, IDB_CRUISEUP);
		buttons->setButtonValInt(cruiseUButton, PURCH_CRUISE);
		buttons->deactivateButton(cruiseUButton);
	}

	if (destrDButton == BB_ID_NULL)
	{
		destrDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, destrBox->box.Y, destrBox->box.Height, destrBox->box.Height };
		buttons->registerButton(graphics, destrDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(destrDButton);
		buttons->setButtonFuncId(destrDButton, IDB_DESTRDN);
		buttons->setButtonValInt(destrDButton, PURCH_DESTR);
		buttons->deactivateButton(destrDButton);
	}
	if (destrUButton == BB_ID_NULL)
	{
		destrUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, destrBox->box.Y, destrBox->box.Height, destrBox->box.Height };
		buttons->registerButton(graphics, destrUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(destrUButton);
		buttons->setButtonFuncId(destrUButton, IDB_DESTRUP);
		buttons->setButtonValInt(destrUButton, PURCH_DESTR);
		buttons->deactivateButton(destrUButton);
	}

	if (subDButton == BB_ID_NULL)
	{
		subDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, subBox->box.Y, subBox->box.Height, subBox->box.Height };
		buttons->registerButton(graphics, subDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(subDButton);
		buttons->setButtonFuncId(subDButton, IDB_SUBDN);
		buttons->setButtonValInt(subDButton, PURCH_SUB);
		buttons->deactivateButton(subDButton);
	}
	if (subUButton == BB_ID_NULL)
	{
		subUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, subBox->box.Y, subBox->box.Height, subBox->box.Height };
		buttons->registerButton(graphics, subUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(subUButton);
		buttons->setButtonFuncId(subUButton, IDB_SUBUP);
		buttons->setButtonValInt(subUButton, PURCH_SUB);
		buttons->deactivateButton(subUButton);
	}

	if (transDButton == BB_ID_NULL)
	{
		transDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, transBox->box.Y, transBox->box.Height, transBox->box.Height };
		buttons->registerButton(graphics, transDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(transDButton);
		buttons->setButtonFuncId(transDButton, IDB_TRANSDN);
		buttons->setButtonValInt(transDButton, PURCH_TRANS);
		buttons->deactivateButton(transDButton);
	}
	if (transUButton == BB_ID_NULL)
	{
		transUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, transBox->box.Y, transBox->box.Height, transBox->box.Height };
		buttons->registerButton(graphics, transUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(transUButton);
		buttons->setButtonFuncId(transUButton, IDB_TRANSUP);
		buttons->setButtonValInt(transUButton, PURCH_TRANS);
		buttons->deactivateButton(transUButton);
	}

	if (majorDButton == BB_ID_NULL)
	{
		majorDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, majorBox->box.Y, majorBox->box.Height, majorBox->box.Height };
		buttons->registerButton(graphics, majorDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(majorDButton);
		buttons->setButtonFuncId(majorDButton, IDB_MAJORDN);
		buttons->setButtonValInt(majorDButton, PURCH_MAJOR);
		buttons->deactivateButton(majorDButton);
	}
	if (majorUButton == BB_ID_NULL)
	{
		majorUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, majorBox->box.Y, majorBox->box.Height, majorBox->box.Height };
		buttons->registerButton(graphics, majorUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(majorUButton);
		buttons->setButtonFuncId(majorUButton, IDB_MAJORUP);
		buttons->setButtonValInt(majorUButton, PURCH_MAJOR);
		buttons->deactivateButton(majorUButton);
	}

	if (minorDButton == BB_ID_NULL)
	{
		minorDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, minorBox->box.Y, minorBox->box.Height, minorBox->box.Height };
		buttons->registerButton(graphics, minorDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(minorDButton);
		buttons->setButtonFuncId(minorDButton, IDB_MINORDN);
		buttons->setButtonValInt(minorDButton, PURCH_MINOR);
		buttons->deactivateButton(minorDButton);
	}
	if (minorUButton == BB_ID_NULL)
	{
		minorUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, minorBox->box.Y, minorBox->box.Height, minorBox->box.Height };
		buttons->registerButton(graphics, minorUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(minorUButton);
		buttons->setButtonFuncId(minorUButton, IDB_MINORUP);
		buttons->setButtonValInt(minorUButton, PURCH_MINOR);
		buttons->deactivateButton(minorUButton);
	}

	if (minorUpDButton == BB_ID_NULL)
	{
		minorUpDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, minorUpBox->box.Y, minorUpBox->box.Height, minorUpBox->box.Height };
		buttons->registerButton(graphics, minorUpDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(minorUpDButton);
		buttons->setButtonFuncId(minorUpDButton, IDB_MINORUPDN);
		buttons->setButtonValInt(minorUpDButton, PURCH_MINORUP);
		buttons->deactivateButton(minorUpDButton);
	}
	if (minorUpUButton == BB_ID_NULL)
	{
		minorUpUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, minorUpBox->box.Y, minorUpBox->box.Height, minorUpBox->box.Height };
		buttons->registerButton(graphics, minorUpUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(minorUpUButton);
		buttons->setButtonFuncId(minorUpUButton, IDB_MINORUPUP);
		buttons->setButtonValInt(minorUpUButton, PURCH_MINORUP);
		buttons->deactivateButton(minorUpUButton);
	}

	if (airbDButton == BB_ID_NULL)
	{
		airbDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, airbBox->box.Y, airbBox->box.Height, airbBox->box.Height };
		buttons->registerButton(graphics, airbDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(airbDButton);
		buttons->setButtonFuncId(airbDButton, IDB_AIRBDN);
		buttons->setButtonValInt(airbDButton, PURCH_AIRB);
		buttons->deactivateButton(airbDButton);
	}
	if (airbUButton == BB_ID_NULL)
	{
		airbUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, airbBox->box.Y, airbBox->box.Height, airbBox->box.Height };
		buttons->registerButton(graphics, airbUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(airbUButton);
		buttons->setButtonFuncId(airbUButton, IDB_AIRBUP);
		buttons->setButtonValInt(airbUButton, PURCH_AIRB);
		buttons->deactivateButton(airbUButton);
	}

	if (navbDButton == BB_ID_NULL)
	{
		navbDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, navbBox->box.Y, navbBox->box.Height, navbBox->box.Height };
		buttons->registerButton(graphics, navbDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(navbDButton);
		buttons->setButtonFuncId(navbDButton, IDB_NAVBDN);
		buttons->setButtonValInt(navbDButton, PURCH_NAVB);
		buttons->deactivateButton(navbDButton);
	}
	if (navbUButton == BB_ID_NULL)
	{
		navbUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, navbBox->box.Y, navbBox->box.Height, navbBox->box.Height };
		buttons->registerButton(graphics, navbUButton, NATION_SCREEN, PURCH_SECT, rect, "+", purchaseButton);
		buttons->activateButton(navbUButton);
		buttons->setButtonFuncId(navbUButton, IDB_NAVBUP);
		buttons->setButtonValInt(navbUButton, PURCH_NAVB);
		buttons->deactivateButton(navbUButton);
	}

	if (repairDButton == BB_ID_NULL)
	{
		repairDButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_D_OFFSET, repBox->box.Y, repBox->box.Height, repBox->box.Height };
		buttons->registerButton(graphics, repairDButton, NATION_SCREEN, PURCH_SECT, rect, "-", purchaseButton);
		buttons->activateButton(repairDButton);
		buttons->setButtonFuncId(repairDButton, IDB_REPAIRDN);
		buttons->setButtonValInt(repairDButton, PURCH_REP);
		buttons->deactivateButton(repairDButton);
	}
	if (repairUButton == BB_ID_NULL)
	{
		repairUButton = buttons->createButtonId();

		RectF rect = { PURCH_BUTTON_U_OFFSET, repBox->box.Y, repBox->box.Height, repBox->box.Height };
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
	WCHAR cruise0[] = L" Cruiser\t  12\t     3\t      3\t     2";
	WCHAR cruise1[] = L" Cruiser\t   9\t     3\t      3\t     2";

	if (shipRes)
	{
		battleText[14] = '1';
		battleText[15] = '7';
		airccText[21] = '3';
		wcsncpy_s(cruiseText, cruise1, ARRAYSIZE(cruise1));
		destrText[14] = '7';
		subText[14] = '5';
		transText[14] = '6';
	}
	else
	{
		battleText[14] = '2';
		battleText[15] = '0';
		airccText[21] = '6';
		wcsncpy_s(cruiseText, cruise0, ARRAYSIZE(cruise0));
		destrText[14] = '8';
		subText[14] = '6';
		transText[14] = '7';
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

		purchHeadBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		infBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		artBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		mechBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tankBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		aaaBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		fightBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tactBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		stratBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		battleBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airccBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		cruiseBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		destrBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		subBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		transBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		majorBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorUpBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airbBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		navbBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		repBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		totBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		infQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		artQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		mechQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tankQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		aaaQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		fightQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tactQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		stratQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		battleQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airccQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		cruiseQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		destrQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		subQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		transQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		majorQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorUpQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airbQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		navbQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		repQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		totQBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		infCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		artCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		mechCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tankCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		aaaCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		fightCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tactCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		stratCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		battleCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airccCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		cruiseCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		destrCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		subCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		transCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		majorCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorUpCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airbCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		navbCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		repCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		totCBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		hidePurchaseButtons();		
	}
	else // Actual graphics
	{
		purchTitleBox->drawFrameFill(graphics, pen, baseTitleFont, centerFormat, textBrush, tileBrushD, layers);

		purchHeadBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, purchHeadText, layers);
		infBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, infText, layers);
		artBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, artText, layers);
		mechBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, mechText, layers);
		tankBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, tankText, layers);
		aaaBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, aaaText, layers);
		fightBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, fightText, layers);
		tactBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, tactText, layers);
		stratBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, stratText, layers);
		battleBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, battleText, layers);
		airccBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, airccText, layers);
		cruiseBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, cruiseText, layers);
		destrBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, destrText, layers);
		subBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, subText,layers);
		transBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, transText, layers);
		majorBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, majorText, layers);
		minorBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, minorText, layers);
		minorUpBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, minorUpText, layers);
		airbBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, airbText, layers);
		navbBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, navbText, layers);
		repBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, repText, layers);
		totBox->drawBox(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, totText, layers);

		graphics->DrawLine(backPen, *titleP0, *titleP1);

		infQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, infQ, layers);
		artQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, artQ, layers);
		mechQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, mechQ, layers);
		tankQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, tankQ, layers);
		aaaQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, aaaQ, layers);
		fightQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, fightQ, layers);
		tactQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, tactQ, layers);
		stratQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, stratQ, layers);
		battleQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, battleQ, layers);
		airccQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, airccQ, layers);
		cruiseQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, cruiseQ, layers);
		destrQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, destrQ, layers);
		subQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, subQ, layers);
		transQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, transQ, layers);
		majorQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, majorQ, layers);
		minorQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, minorQ, layers);
		minorUpQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, minorUpQ, layers);
		airbQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, airbQ, layers);
		navbQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, navbQ, layers);
		repQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, repQ, layers);
		totQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, totQ, layers);

		infCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, infC, layers);
		artCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, artC, layers);
		mechCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, mechC, layers);
		tankCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, tankC, layers);
		aaaCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, aaaC, layers);
		fightCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, fightC, layers);
		tactCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, tactC, layers);
		stratCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, stratC, layers);
		battleCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, battleC, layers);
		airccCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, airccC, layers);
		cruiseCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, cruiseC, layers);
		destrCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, destrC, layers);
		subCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, subC, layers);
		transCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, transC, layers);
		majorCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, majorC, layers);
		minorCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, minorC, layers);
		minorUpCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, minorUpC, layers);
		airbCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, airbC, layers);
		navbCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, navbC, layers);
		repCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, repC, layers);
		totCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, clearBrush, totC, layers);
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
		battleBoxU->drawFrameFill(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, layers);
		airccBoxU->drawFrameFill(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, layers);
		cruiseBoxU->drawFrameFill(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, layers);
		destrBoxU->drawFrameFill(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, layers);
		subBoxU->drawFrameFill(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, layers);
		transBoxU->drawFrameFill(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, layers);
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
			infQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, infQ, layers);
			infCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, infC, layers);
			break;
		}
		case PURCH_ART:
		{
			artQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, artQ, layers);
			artCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, artC, layers);
			break;
		}
		case PURCH_MECH:
		{
			mechQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, mechQ, layers);
			mechCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, mechC, layers);
			break;
		}
		case PURCH_TANK:
		{
			tankQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, tankQ, layers);
			tankCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, tankC, layers);
			break;
		}
		case PURCH_AAA:
		{
			aaaQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, aaaQ, layers);
			aaaCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, aaaC, layers);
			break;
		}
		case PURCH_FIGHT:
		{
			fightQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, fightQ, layers);
			fightCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, fightC, layers);
			break;
		}
		case PURCH_TACT:
		{
			tactQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, tactQ, layers);
			tactCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, tactC, layers);
			break;
		}
		case PURCH_STRAT:
		{
			stratQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, stratQ, layers);
			stratCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, stratC, layers);
			break;
		}
		case PURCH_BATTLE:
		{
			battleQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, battleQ, layers);
			battleCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, battleC, layers);
			break;
		}
		case PURCH_AIRCC:
		{
			airccQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, airccQ, layers);
			airccCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, airccC, layers);
			break;
		}
		case PURCH_CRUISE:
		{
			cruiseQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, cruiseQ, layers);
			cruiseCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, cruiseC, layers);
			break;
		}
		case PURCH_DESTR:
		{
			destrQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, destrQ, layers);
			destrCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, destrC, layers);
			break;
		}
		case PURCH_SUB:
		{
			subQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, subQ, layers);
			subCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, subC, layers);
			break;
		}
		case PURCH_TRANS:
		{
			transQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, transQ, layers);
			transCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, transC, layers);
			break;
		}
		case PURCH_MAJOR:
		{
			majorQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, majorQ, layers);
			majorCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, majorC, layers);
			break;
		}
		case PURCH_MINOR:
		{
			minorQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, minorQ, layers);
			minorCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, minorC, layers);
			break;
		}
		case PURCH_MINORUP:
		{
			minorUpQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, minorUpQ, layers);
			minorUpCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, minorUpC, layers);
			break;
		}
		case PURCH_AIRB:
		{
			airbQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, airbQ, layers);
			airbCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, airbC, layers);
			break;
		}
		case PURCH_NAVB:
		{
			navbQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, navbQ, layers);
			navbCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, navbC, layers);
			break;
		}
		case PURCH_REP:
		{
			repQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, repQ, layers);
			repCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, repC, layers);
			break;
		}
		case PURCH_ALL:
		{
			infQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, infQ, layers);
			infCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, infC, layers);
			artQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, artQ, layers);
			artCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, artC, layers);
			mechQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, mechQ, layers);
			mechCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, mechC, layers);
			tankQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, tankQ, layers);
			tankCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, tankC, layers);
			aaaQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, aaaQ, layers);
			aaaCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, aaaC, layers);
			fightQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, fightQ, layers);
			fightCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, fightC, layers);
			tactQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, tactQ, layers);
			tactCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, tactC, layers);
			stratQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, stratQ, layers);
			stratCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, stratC, layers);
			battleQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, battleQ, layers);
			battleCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, battleC, layers);
			airccQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, airccQ, layers);
			airccCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, airccC, layers);
			cruiseQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, cruiseQ, layers);
			cruiseCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, cruiseC, layers);
			destrQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, destrQ, layers);
			destrCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, destrC, layers);
			subQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, subQ, layers);
			subCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, subC, layers);
			transQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, transQ, layers);
			transCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, transC, layers);
			majorQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, majorQ, layers);
			majorCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, majorC, layers);
			minorQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, minorQ, layers);
			minorCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, minorC, layers);
			minorUpQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, minorUpQ, layers);
			minorUpCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, minorUpC, layers);
			airbQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, airbQ, layers);
			airbCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, airbC, layers);
			navbQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, navbQ, layers);
			navbCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, navbC, layers);
			repQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, repQ, layers);
			repCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushL, repC, layers);
			break;
		}
		default:
			break;
		}

		totQBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, totQ, layers);
		totCBox->drawBox(graphics, pen, costFont, centerFormat, textBrush, tileBrushD, totC, layers);
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
		tmp = purchHeadBox;
		break;
	case PURCH_INF:
		tmp = infBox;
		break;
	case PURCH_ART:
		tmp = artBox;
		break;
	case PURCH_MECH:
		tmp = mechBox;
		break;
	case PURCH_TANK:
		tmp = tankBox;
		break;
	case PURCH_AAA:
		tmp = aaaBox;
		break;
	case PURCH_FIGHT:
		tmp = fightBox;
		break;
	case PURCH_TACT:
		tmp = tactBox;
		break;
	case PURCH_STRAT:
		tmp = stratBox;
		break;
	case PURCH_BATTLE:
		tmp = battleBox;
		break;
	case PURCH_AIRCC:
		tmp = airccBox;
		break;
	case PURCH_CRUISE:
		tmp = cruiseBox;
		break;
	case PURCH_DESTR:
		tmp = destrBox;
		break;
	case PURCH_SUB:
		tmp = subBox;
		break;
	case PURCH_TRANS:
		tmp = transBox;
		break;
	case PURCH_MAJOR:
		tmp = majorBox;
		break;
	case PURCH_MINOR:
		tmp = minorBox;
		break;
	case PURCH_MINORUP:
		tmp = minorUpBox;
		break;
	case PURCH_AIRB:
		tmp = airbBox;
		break;
	case PURCH_NAVB:
		tmp = navbBox;
		break;
	case PURCH_REP:
		tmp = repBox;
		break;
	case PURCH_TOT:
		tmp = totBox;
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
