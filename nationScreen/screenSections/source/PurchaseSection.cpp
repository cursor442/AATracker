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
	infDButton = NULL;     infUButton = NULL;
	artDButton = NULL;     artUButton = NULL;
	mechDButton = NULL;    mechUButton = NULL;
	tankDButton = NULL;    tankUButton = NULL;
	aaaDButton = NULL;     aaaUButton = NULL;
	fightDButton = NULL;   fightUButton = NULL;
	tactDButton = NULL;    tactUButton = NULL;
	stratDButton = NULL;   stratUButton = NULL;
	battleDButton = NULL;  battleUButton = NULL;
	airccDButton = NULL;   airccUButton = NULL;
	cruiseDButton = NULL;  cruiseUButton = NULL;
	destrDButton = NULL;   destrUButton = NULL;
	subDButton = NULL;     subUButton = NULL;
	transDButton = NULL;   transUButton = NULL;
	majorDButton = NULL;   majorUButton = NULL;
	minorDButton = NULL;   minorUButton = NULL;
	minorUpDButton = NULL; minorUpUButton = NULL;
	airbDButton = NULL;    airbUButton = NULL;
	navbDButton = NULL;    navbUButton = NULL;
	repairDButton = NULL;  repairUButton = NULL;

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

	delete infDButton;     delete infUButton;
	delete artDButton;     delete artUButton;
	delete mechDButton;    delete mechUButton;
	delete tankDButton;    delete tankUButton;
	delete aaaDButton;     delete aaaUButton;
	delete fightDButton;   delete fightUButton;
	delete tactDButton;    delete tactUButton;
	delete stratDButton;   delete stratUButton;
	delete battleDButton;  delete battleUButton;
	delete airccDButton;   delete airccUButton;
	delete cruiseDButton;  delete cruiseUButton;
	delete destrDButton;   delete destrUButton;
	delete subDButton;     delete subUButton;
	delete transDButton;   delete transUButton;
	delete majorDButton;   delete majorUButton;
	delete minorDButton;   delete minorUButton;
	delete minorUpDButton; delete minorUpUButton;
	delete airbDButton;    delete airbUButton;
	delete navbDButton;    delete navbUButton;
	delete repairDButton;  delete repairUButton;
}

void PurchaseSection::configurePurchaseBox(HWND& hWnd, RectF& frame, int layer)
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

	configPurchaseButtons();

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

void PurchaseSection::configPurchaseButtons()
{
	if (infDButton == NULL)
	{
		infDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			infBox->box.Y,                                         // y position 
			infBox->box.Height,                                    // Button width
			infBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_INFDN,                                      // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (infUButton == NULL)
	{
		infUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			infBox->box.Y,                                         // y position 
			infBox->box.Height,                                    // Button width
			infBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_INFUP,                                      // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (artDButton == NULL)
	{
		artDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			artBox->box.Y,                                         // y position 
			artBox->box.Height,                                    // Button width
			artBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_ARTDN,                                      // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (artUButton == NULL)
	{
		artUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			artBox->box.Y,                                         // y position 
			artBox->box.Height,                                    // Button width
			artBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_ARTUP,                                      // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (mechDButton == NULL)
	{
		mechDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			mechBox->box.Y,                                        // y position 
			mechBox->box.Height,                                   // Button width
			mechBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_MECHDN,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (mechUButton == NULL)
	{
		mechUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			mechBox->box.Y,                                        // y position 
			mechBox->box.Height,                                   // Button width
			mechBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_MECHUP,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (tankDButton == NULL)
	{
		tankDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			tankBox->box.Y,                                        // y position 
			tankBox->box.Height,                                   // Button width
			tankBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_TANKDN,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (tankUButton == NULL)
	{
		tankUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			tankBox->box.Y,                                        // y position 
			tankBox->box.Height,                                   // Button width
			tankBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_TANKUP,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (aaaDButton == NULL)
	{
		aaaDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			aaaBox->box.Y,                                         // y position 
			aaaBox->box.Height,                                    // Button width
			aaaBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_AAADN,                                      // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (aaaUButton == NULL)
	{
		aaaUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			aaaBox->box.Y,                                         // y position 
			aaaBox->box.Height,                                    // Button width
			aaaBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_AAAUP,                                      // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (fightDButton == NULL)
	{
		fightDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			fightBox->box.Y,                                       // y position 
			fightBox->box.Height,                                  // Button width
			fightBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_FIGHTDN,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (fightUButton == NULL)
	{
		fightUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			fightBox->box.Y,                                       // y position 
			fightBox->box.Height,                                  // Button width
			fightBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_FIGHTUP,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (tactDButton == NULL)
	{
		tactDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			tactBox->box.Y,                                        // y position 
			tactBox->box.Height,                                   // Button width
			tactBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_TACTDN,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (tactUButton == NULL)
	{
		tactUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			tactBox->box.Y,                                        // y position 
			tactBox->box.Height,                                   // Button width
			tactBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_TACTUP,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (stratDButton == NULL)
	{
		stratDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			stratBox->box.Y,                                       // y position 
			stratBox->box.Height,                                  // Button width
			stratBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_STRATDN,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (stratUButton == NULL)
	{
		stratUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			stratBox->box.Y,                                       // y position 
			stratBox->box.Height,                                  // Button width
			stratBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_STRATUP,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (battleDButton == NULL)
	{
		battleDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			battleBox->box.Y,                                      // y position 
			battleBox->box.Height,                                 // Button width
			battleBox->box.Height,                                 // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_BATTLEDN,                                   // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (battleUButton == NULL)
	{
		battleUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			battleBox->box.Y,                                      // y position 
			battleBox->box.Height,                                 // Button width
			battleBox->box.Height,                                 // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_BATTLEUP,                                   // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (airccDButton == NULL)
	{
		airccDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			airccBox->box.Y,                                       // y position 
			airccBox->box.Height,                                  // Button width
			airccBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_AIRCCDN,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (airccUButton == NULL)
	{
		airccUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			airccBox->box.Y,                                       // y position 
			airccBox->box.Height,                                  // Button width
			airccBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_AIRCCUP,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (cruiseDButton == NULL)
	{
		cruiseDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			cruiseBox->box.Y,                                      // y position 
			cruiseBox->box.Height,                                 // Button width
			cruiseBox->box.Height,                                 // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_CRUISEDN,                                   // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (cruiseUButton == NULL)
	{
		cruiseUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			cruiseBox->box.Y,                                      // y position 
			cruiseBox->box.Height,                                 // Button width
			cruiseBox->box.Height,                                 // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_CRUISEUP,                                   // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (destrDButton == NULL)
	{
		destrDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			destrBox->box.Y,                                       // y position 
			destrBox->box.Height,                                  // Button width
			destrBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_DESTRDN,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (destrUButton == NULL)
	{
		destrUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			destrBox->box.Y,                                       // y position 
			destrBox->box.Height,                                  // Button width
			destrBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_DESTRUP,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (subDButton == NULL)
	{
		subDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			subBox->box.Y,                                         // y position 
			subBox->box.Height,                                    // Button width
			subBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_SUBDN,                                      // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (subUButton == NULL)
	{
		subUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			subBox->box.Y,                                         // y position 
			subBox->box.Height,                                    // Button width
			subBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_SUBUP,                                      // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (transDButton == NULL)
	{
		transDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			transBox->box.Y,                                       // y position 
			transBox->box.Height,                                  // Button width
			transBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_TRANSDN,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (transUButton == NULL)
	{
		transUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			transBox->box.Y,                                       // y position 
			transBox->box.Height,                                  // Button width
			transBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_TRANSUP,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (majorDButton == NULL)
	{
		majorDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			majorBox->box.Y,                                       // y position 
			majorBox->box.Height,                                  // Button width
			majorBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_MAJORDN,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (majorUButton == NULL)
	{
		majorUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			majorBox->box.Y,                                       // y position 
			majorBox->box.Height,                                  // Button width
			majorBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_MAJORUP,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (minorDButton == NULL)
	{
		minorDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			minorBox->box.Y,                                       // y position 
			minorBox->box.Height,                                  // Button width
			minorBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_MINORDN,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (minorUButton == NULL)
	{
		minorUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			minorBox->box.Y,                                       // y position 
			minorBox->box.Height,                                  // Button width
			minorBox->box.Height,                                  // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_MINORUP,                                    // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (minorUpDButton == NULL)
	{
		minorUpDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			minorUpBox->box.Y,                                     // y position 
			minorUpBox->box.Height,                                // Button width
			minorUpBox->box.Height,                                // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_MINORUPDN,                                  // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (minorUpUButton == NULL)
	{
		minorUpUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			minorUpBox->box.Y,                                     // y position 
			minorUpBox->box.Height,                                // Button width
			minorUpBox->box.Height,                                // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_MINORUPUP,                                  // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (airbDButton == NULL)
	{
		airbDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			airbBox->box.Y,                                        // y position 
			airbBox->box.Height,                                   // Button width
			airbBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_AIRBDN,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (airbUButton == NULL)
	{
		airbUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			airbBox->box.Y,                                        // y position 
			airbBox->box.Height,                                   // Button width
			airbBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_AIRBUP,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (navbDButton == NULL)
	{
		navbDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			navbBox->box.Y,                                        // y position 
			navbBox->box.Height,                                   // Button width
			navbBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_NAVBDN,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (navbUButton == NULL)
	{
		navbUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			navbBox->box.Y,                                        // y position 
			navbBox->box.Height,                                   // Button width
			navbBox->box.Height,                                   // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_NAVBUP,                                     // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}

	if (repairDButton == NULL)
	{
		repairDButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"-",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_D_OFFSET,                                 // x position 
			repBox->box.Y,                                         // y position 
			repBox->box.Height,                                    // Button width
			repBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_REPAIRDN,                                   // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
	if (repairUButton == NULL)
	{
		repairUButton = CreateWindow(
			L"BUTTON",                                             // Predefined class; Unicode assumed 
			L"+",                                                  // Button text 
			WS_TABSTOP | WS_CHILD | BS_DEFPUSHBUTTON,              // Styles 
			PURCH_BUTTON_U_OFFSET,                                 // x position 
			repBox->box.Y,                                         // y position 
			repBox->box.Height,                                    // Button width
			repBox->box.Height,                                    // Button height
			*main_Wnd,                                             // Parent window
			(HMENU)IDB_REPAIRUP,                                   // Menu
			(HINSTANCE)GetWindowLongPtr(*main_Wnd, GWLP_HINSTANCE),
			NULL);
	}
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
		hidePurchaseButtons();

		purchaseFrame->drawFrame(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		purchTitleBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		purchHeadBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		infBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		artBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		mechBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tankBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		aaaBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		fightBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tactBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		stratBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		battleBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airccBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		cruiseBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		destrBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		subBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		transBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		majorBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorUpBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airbBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		navbBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		repBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		totBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		infQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		artQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		mechQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tankQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		aaaQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		fightQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tactQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		stratQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		battleQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airccQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		cruiseQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		destrQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		subQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		transQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		majorQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorUpQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airbQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		navbQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		repQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		totQBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		infCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		artCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		mechCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tankCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		aaaCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		fightCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tactCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		stratCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		battleCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airccCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		cruiseCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		destrCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		subCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		transCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		majorCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		minorUpCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		airbCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		navbCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		repCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		totCBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		
	}
	else // Actual graphics
	{
		showPurchaseButtons();

		purchTitleBox->drawFrame(graphics, pen, baseTitleFont, centerFormat, textBrush, tileBrushD, layers);

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
		battleBoxU->drawFrame(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, layers);
		airccBoxU->drawFrame(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, layers);
		cruiseBoxU->drawFrame(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, layers);
		destrBoxU->drawFrame(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, layers);
		subBoxU->drawFrame(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushL, layers);
		transBoxU->drawFrame(graphics, pen, purchFont, purchaseFormat, textBrush, tileBrushD, layers);
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
	ShowWindow(infDButton,     SW_SHOW); ShowWindow(infUButton,     SW_SHOW);
	ShowWindow(artDButton,     SW_SHOW); ShowWindow(artUButton,     SW_SHOW);
	ShowWindow(mechDButton,    SW_SHOW); ShowWindow(mechUButton,    SW_SHOW);
	ShowWindow(tankDButton,    SW_SHOW); ShowWindow(tankUButton,    SW_SHOW);
	ShowWindow(aaaDButton,     SW_SHOW); ShowWindow(aaaUButton,     SW_SHOW);
	ShowWindow(fightDButton,   SW_SHOW); ShowWindow(fightUButton,   SW_SHOW);
	ShowWindow(tactDButton,    SW_SHOW); ShowWindow(tactUButton,    SW_SHOW);
	ShowWindow(stratDButton,   SW_SHOW); ShowWindow(stratUButton,   SW_SHOW);
	ShowWindow(battleDButton,  SW_SHOW); ShowWindow(battleUButton,  SW_SHOW);
	ShowWindow(airccDButton,   SW_SHOW); ShowWindow(airccUButton,   SW_SHOW);
	ShowWindow(cruiseDButton,  SW_SHOW); ShowWindow(cruiseUButton,  SW_SHOW);
	ShowWindow(destrDButton,   SW_SHOW); ShowWindow(destrUButton,   SW_SHOW);
	ShowWindow(subDButton,     SW_SHOW); ShowWindow(subUButton,     SW_SHOW);
	ShowWindow(transDButton,   SW_SHOW); ShowWindow(transUButton,   SW_SHOW);
	ShowWindow(majorDButton,   SW_SHOW); ShowWindow(majorUButton,   SW_SHOW);
	ShowWindow(minorDButton,   SW_SHOW); ShowWindow(minorUButton,   SW_SHOW);
	ShowWindow(minorUpDButton, SW_SHOW); ShowWindow(minorUpUButton, SW_SHOW);
	ShowWindow(airbDButton,    SW_SHOW); ShowWindow(airbUButton,    SW_SHOW);
	ShowWindow(navbDButton,    SW_SHOW); ShowWindow(navbUButton,    SW_SHOW);
	ShowWindow(repairDButton,  SW_SHOW); ShowWindow(repairUButton,  SW_SHOW);
}

void PurchaseSection::hidePurchaseButtons()
{
	ShowWindow(infDButton,     SW_HIDE); ShowWindow(infUButton,     SW_HIDE);
	ShowWindow(artDButton,     SW_HIDE); ShowWindow(artUButton,     SW_HIDE);
	ShowWindow(mechDButton,    SW_HIDE); ShowWindow(mechUButton,    SW_HIDE);
	ShowWindow(tankDButton,    SW_HIDE); ShowWindow(tankUButton,    SW_HIDE);
	ShowWindow(aaaDButton,     SW_HIDE); ShowWindow(aaaUButton,     SW_HIDE);
	ShowWindow(fightDButton,   SW_HIDE); ShowWindow(fightUButton,   SW_HIDE);
	ShowWindow(tactDButton,    SW_HIDE); ShowWindow(tactUButton,    SW_HIDE);
	ShowWindow(stratDButton,   SW_HIDE); ShowWindow(stratUButton,   SW_HIDE);
	ShowWindow(battleDButton,  SW_HIDE); ShowWindow(battleUButton,  SW_HIDE);
	ShowWindow(airccDButton,   SW_HIDE); ShowWindow(airccUButton,   SW_HIDE);
	ShowWindow(cruiseDButton,  SW_HIDE); ShowWindow(cruiseUButton,  SW_HIDE);
	ShowWindow(destrDButton,   SW_HIDE); ShowWindow(destrUButton,   SW_HIDE);
	ShowWindow(subDButton,     SW_HIDE); ShowWindow(subUButton,     SW_HIDE);
	ShowWindow(transDButton,   SW_HIDE); ShowWindow(transUButton,   SW_HIDE);
	ShowWindow(majorDButton,   SW_HIDE); ShowWindow(majorUButton,   SW_HIDE);
	ShowWindow(minorDButton,   SW_HIDE); ShowWindow(minorUButton,   SW_HIDE);
	ShowWindow(minorUpDButton, SW_HIDE); ShowWindow(minorUpUButton, SW_HIDE);
	ShowWindow(airbDButton,    SW_HIDE); ShowWindow(airbUButton,    SW_HIDE);
	ShowWindow(navbDButton,    SW_HIDE); ShowWindow(navbUButton,    SW_HIDE);
	ShowWindow(repairDButton,  SW_HIDE); ShowWindow(repairUButton,  SW_HIDE);
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
