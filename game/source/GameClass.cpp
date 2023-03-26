#include "../header/AA_Tracker.h"
#include "../header/GameClass.h"

Game::Game()
{
	setupGDI();
}

Game::~Game()
{
	delete gameBoard;

	destroyGraphScreen();
	destroyLogScreen();

	DeleteObject(hFont);
	DeleteObject(hBrush);
	DeleteObject(hBrushP); DeleteObject(hBrushS);
	DeleteObject(hPen);

	DeleteObject(descrFont);  DeleteObject(descrBFont);
	DeleteObject(normalFont);
	DeleteObject(headerFont); 

	DeleteObject(borderless); DeleteObject(bordered);
	
	DeleteObject(gerBrushP); DeleteObject(gerBrushS); DeleteObject(gerBrushF);
	DeleteObject(sovBrushP); DeleteObject(sovBrushS); DeleteObject(sovBrushF);
	DeleteObject(jpnBrushP); DeleteObject(jpnBrushS); DeleteObject(jpnBrushF);
	DeleteObject(usaBrushP); DeleteObject(usaBrushS); DeleteObject(usaBrushF);
	DeleteObject(chnBrushP); DeleteObject(chnBrushS); DeleteObject(chnBrushF);
	DeleteObject(ukBrushP);  DeleteObject(ukBrushS);  DeleteObject(ukBrushF);
	DeleteObject(itaBrushP); DeleteObject(itaBrushS); DeleteObject(itaBrushF);
	DeleteObject(anzBrushP); DeleteObject(anzBrushS); DeleteObject(anzBrushF);
	DeleteObject(fraBrushP); DeleteObject(fraBrushS); DeleteObject(fraBrushF);

	DeleteObject(tileBrush);
	DeleteObject(tileDBrush);

	//// Graphics
	delete gfx;

	DeleteObject(graphics);
	DeleteObject(debugGrid);
	// Fonts
	DeleteObject(calibriFamily);
	DeleteObject(logTextFont); DeleteObject(logTurnFont);

	///////////////////////////////////////////////////////////////////////////
	//// Nation Screen
	///////////////////////////////////////////////////////////////////////////

	// Sections
	DeleteObject(nameSection);
	DeleteObject(phaseSection);
	DeleteObject(warSection);
	DeleteObject(citiesSection);
	DeleteObject(statusSection);
	DeleteObject(purchaseSection);
	DeleteObject(neutralSection);
	DeleteObject(miniSpreadSection);
	DeleteObject(warchestSection);
	DeleteObject(bonusSection);

	// Buttons
	DeleteObject(occupyNeutralButton);
	DeleteObject(attackMongoliaButton);
	DeleteObject(attackJapanButton);
	DeleteObject(attackSovietButton);

	// Tabs
	DeleteObject(nationScreenTabs);
	DeleteObject(purchaseSectionTabs);
	DeleteObject(ukEconomyTabs);

	///////////////////////////////////////////////////////////////////////////
	//// Spreadsheet Screen
	///////////////////////////////////////////////////////////////////////////

	for (int i = 0; i <= TURN_FRA; i++)
		if (nationSpreads[i] != NULL)
			delete nationSpreads[i];

	DeleteObject(spreadAxis); DeleteObject(spreadAllies);

	///////////////////////////////////////////////////////////////////////////
	//// Graph Screen
	///////////////////////////////////////////////////////////////////////////

	DeleteObject(graphSelect);
	DeleteObject(gerGraph); DeleteObject(sovGraph); DeleteObject(jpnGraph);
	DeleteObject(usaGraph); DeleteObject(chnGraph); DeleteObject(ukGraph);
	DeleteObject(itaGraph); DeleteObject(anzGraph); DeleteObject(fraGraph);

	///////////////////////////////////////////////////////////////////////////
	//// Log Screen
	///////////////////////////////////////////////////////////////////////////

	if (logScreenTabs != NULL)
	{
		DeleteObject(logScreenTabs);
		DeleteObject(customLogButton);
	}

	///////////////////////////////////////////////////////////////////////////
	//// Research Screen
	///////////////////////////////////////////////////////////////////////////

	DeleteObject(researchWnd);
	DeleteDC(hdcCompat);
	DeleteObject(resBack);
	DeleteObject(gerIcon); DeleteObject(gerIconMask);
	DeleteObject(sovIcon); DeleteObject(sovIconMask);
	DeleteObject(jpnIcon); DeleteObject(jpnIconMask);
	DeleteObject(usaIcon); DeleteObject(usaIconMask);
	DeleteObject(chnIcon); DeleteObject(chnIconMask);
	DeleteObject(ukIcon ); DeleteObject(ukIconMask );
	DeleteObject(itaIcon); DeleteObject(itaIconMask);
	DeleteObject(anzIcon); DeleteObject(anzIconMask);
	DeleteObject(fraIcon); DeleteObject(fraIconMask);

	destroyGDI();
}

void Game::resetGameControls()
{
	whichScreen = NATION_SCREEN;

	// Nation Screen
	nsSection = ALL_SECT;

	nsPhase = ALL_PHASE;
	nsUnit = PURCH_TITLE;
	nsNeut = NEUT_ALL;
	nsTurn = SPREAD_ALL_ROWS;
	nsCol = SPREAD_ALL_COLS;

	currButton = BB_ID_NULL;

	purchaseTab = TAB_PURCH;

	nsUKToggle = false;
	warchestRotate = false;
	nsWC = WC_ALL;
	nsBonusRow = BONS_ALL;
	lockPhase = false;

	neutralSection->resetNeutralBox();
	miniSpreadSection->resetMiniSpreadText();
	warchestSection->resetWarchestBox();
	bonusSection->resetBonusBox();

	// Spread Screen

	// Graph Screen
	currGraph = BLNK_GRAPH; currGraphNats = GRAPH_NON;
	updateNatGraph = 10; whichUpdateNatGraph = false;
	doUpdateGraph = false;

	// Log Screen

	// Debug
	dbg_boundbox = false;
	dbg_layers = 99;
	dbg_sections = false;
	dbg_grid = 0;
	debugSwitches();
}

void Game::deleteBoard()
{
	delete gameBoard;
	gameBoard = new Board;

	success = false;

	nsSection = ALL_SECT;
	lockPhase = false;

	whichScreen = MAIN_SCREEN;
	lastScreen = MAIN_SCREEN;
	TabCtrl_SetCurSel(nationScreenTabs, TAB_MAIN);
	TabCtrl_SetCurSel(purchaseSectionTabs, TAB_PURCH);
	TabCtrl_SetCurSel(logScreenTabs, 0);

	n = 0;
	k = 0;
	numResDice[0] = 0; numResDice[1] = 0; currResDie = 0;

	destroySpreadScreen();
	destroyGraphScreen();
	destroyLogScreen();
	graphConfigured = false;

	// Debug
	dbg_boundbox = false;
	dbg_sections = false;
}

void Game::resetBoard()
{
	// Nation 
	currUKButton = false;  currUKButtonToggled = false;

	currGraph = BLNK_GRAPH; currGraphNats = GRAPH_NON;
	updateNatGraph = 10; whichUpdateNatGraph = false;
	doUpdateGraph = false;

	currBrush = true;

	// Debug
	dbg_boundbox = false;
	dbg_sections = false;
}

bool Game::doSaveGame(HWND hWnd, Board& gameBoard)
{
	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	DWORD resLen = MAX_PATH;

	ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = (LPWSTR)fileName;
	ofn.nMaxFile = resLen;
	ofn.lpstrDefExt = L"txt";
	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;

	if (GetSaveFileName(&ofn))
	{		
		HANDLE hFile;
		hFile = CreateFile(ofn.lpstrFile, GENERIC_WRITE, 0, NULL,
			CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		
		if (hFile != INVALID_HANDLE_VALUE)
		{
			uint16_t turn = gameBoard.getGameTurn();

			// Code to save game data
			// It will become quite long

			// Game Config Section
			DWORD bytesWritten = 0;
			{
				char type_[33] = "TYPE:                          \n";
				//strncpy_s(str, head, strlen(head));
				if (gameBoard.getGameType() == EUROPE_GAME)
				{
					type_[6] = 'E'; type_[7] = 'U'; type_[8] = 'R';
				}
				else if (gameBoard.getGameType() == PACIFIC_GAME)
				{
					type_[6] = 'P'; type_[7] = 'A'; type_[8] = 'C';
				}
				else
				{
					type_[6] = 'G'; type_[7] = 'L'; type_[8] = 'O';
				}
				WriteFile(hFile, type_, (DWORD)32, &bytesWritten, NULL);
			}
			{
				char res_[33] = "RESEARCH:                      \n";
				if (gameBoard.getGameResearch() == TRUE)
					res_[10] = 'Y';
				else
					res_[10] = 'N';
				WriteFile(hFile, res_, (DWORD)32, &bytesWritten, NULL);
			}
			// Turn number, current nation, current phase
			{
				char turn_[33] = "TURN:                          \n";
				char* tmp = uint2char(turn + 1);

				turn_[6] = tmp[0]; turn_[7] = tmp[1]; turn_[8] = tmp[2];

				turn_[10] = uint2char_(gameBoard.getGameCurrNation());
				turn_[12] = uint2char_(gameBoard.getGameTurnPhase());
				WriteFile(hFile, turn_, (DWORD)32, &bytesWritten, NULL);
			}

			// Nation Status Section
			uint16_t idx = gameBoard.getGameType() - 114;
			for (uint16_t i = 0; i < saveNations[idx].size(); i++)
			{
				// Nation name
				{
					char nat_[33] = "NAT:                           \n";
					nat_[5] = gameBoard.getNationName(saveNations[idx][i])[0];
					nat_[6] = gameBoard.getNationName(saveNations[idx][i])[1];
					nat_[7] = gameBoard.getNationName(saveNations[idx][i])[2];

					WriteFile(hFile, nat_, (DWORD)32, &bytesWritten, NULL);
				}
				// Nation still controls capital
				{
					char cap_[33] = " CAP:                          \n";

					if (gameBoard.getNationControlsCapital(saveNations[idx][i]))
						cap_[7] = 'Y';
					else
						cap_[7] = 'N';

					WriteFile(hFile, cap_, (DWORD)32, &bytesWritten, NULL);
				}

				uint16_t adj = (isBeforeNation(saveNations[idx][i], gameBoard.getGameCurrNation())) ? (2) : (1);

				// Nation bank (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char bank_[33] = " BANK:                         \n";

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						char* tmp = uint2char(gameBoard.getNationBank(saveNations[idx][i], 6*j+m));
						bank_[7 + 4 * m] = tmp[0]; bank_[8 + 4 * m] = tmp[1]; bank_[9 + 4 * m] = tmp[2];
					}
					WriteFile(hFile, bank_, (DWORD)32, &bytesWritten, NULL);
				}
				// Nation income (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char incm_[33] = " INCM:                         \n";

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						char* tmp = uint2char(gameBoard.getNationIncome(saveNations[idx][i], 6 * j + m));
						incm_[7 + 4 * m] = tmp[0]; incm_[8 + 4 * m] = tmp[1]; incm_[9 + 4 * m] = tmp[2];
					}
					WriteFile(hFile, incm_, (DWORD)32, &bytesWritten, NULL);
				}
				// Nation bonus (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char bns_[33] = " BNS:                          \n";

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						char* tmp = uint2char(gameBoard.getNationBonus(saveNations[idx][i], 6 * j + m));
						bns_[7 + 4 * m] = tmp[0]; bns_[8 + 4 * m] = tmp[1]; bns_[9 + 4 * m] = tmp[2];
					}
					WriteFile(hFile, bns_, (DWORD)32, &bytesWritten, NULL);
				}
				// Nation penalty (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char pnlt_[33] = " PNLT:                         \n";

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						char* tmp = uint2char(gameBoard.getNationPenalty(saveNations[idx][i], 6 * j + m));
						pnlt_[7 + 4 * m] = tmp[0]; pnlt_[8 + 4 * m] = tmp[1]; pnlt_[9 + 4 * m] = tmp[2];
					}
					WriteFile(hFile, pnlt_, (DWORD)32, &bytesWritten, NULL);
				}
				// Nation expenses (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char xpns_[33] = " XPNS:                         \n";

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						char* tmp = uint2char(gameBoard.getNationExpenses(saveNations[idx][i], 6 * j + m));
						xpns_[7 + 4 * m] = tmp[0]; xpns_[8 + 4 * m] = tmp[1]; xpns_[9 + 4 * m] = tmp[2];
					}
					WriteFile(hFile, xpns_, (DWORD)32, &bytesWritten, NULL);
				}
				// Nation territories (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char terr_[33] = " TERR:                         \n";

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						char* tmp = uint2char(gameBoard.getNationTerritories(saveNations[idx][i], 6 * j + m));
						terr_[7 + 4 * m] = tmp[0]; terr_[8 + 4 * m] = tmp[1]; terr_[9 + 4 * m] = tmp[2];
					}
					WriteFile(hFile, terr_, (DWORD)32, &bytesWritten, NULL);
				}

				// Purchase history
				{
					char hist_[33] = " HIST:                         \n";

					for (uint16_t j = 0; j < 6; j++)
					{
						char* tmp = uint2char(gameBoard.getPurchases(saveNations[idx][i], j));
						hist_[7 + 4 * j] = tmp[0]; hist_[8 + 4 * j] = tmp[1]; hist_[9 + 4 * j] = tmp[2];
					}
					WriteFile(hFile, hist_, (DWORD)32, &bytesWritten, NULL);

					for (uint16_t j = 6; j < 12; j++)
					{
						char* tmp = uint2char(gameBoard.getPurchases(saveNations[idx][i], j));
						hist_[4 * j - 17] = tmp[0]; hist_[4 * j - 16] = tmp[1]; hist_[4 * j - 15] = tmp[2];
					}
					WriteFile(hFile, hist_, (DWORD)32, &bytesWritten, NULL);

					for (uint16_t j = 12; j < 18; j++)
					{
						char* tmp = uint2char(gameBoard.getPurchases(saveNations[idx][i], j));
						hist_[4 * j - 41] = tmp[0]; hist_[4 * j - 40] = tmp[1]; hist_[4 * j - 39] = tmp[2];
					} 
					WriteFile(hFile, hist_, (DWORD)32, &bytesWritten, NULL);

					for (uint16_t j = 7; j < 31; j++)
						hist_[j] = ' ';

					for (uint16_t j = 18; j < 20; j++)
					{
						char* tmp = uint2char(gameBoard.getPurchases(saveNations[idx][i], j));
						hist_[4 * j - 65] = tmp[0]; hist_[4 * j - 64] = tmp[1]; hist_[4 * j - 63] = tmp[2];
					}
					WriteFile(hFile, hist_, (DWORD)32, &bytesWritten, NULL);
				}
				// Research
				if (gameBoard.getGameResearch() == true)
				{
					char res_[33] = " RES:                          \n";
					res_[6] = uint2char_(gameBoard.getFailures(saveNations[idx][i]) / 100); 
					res_[7] = uint2char_(gameBoard.getFailures((saveNations[idx][i]) % 100) / 10);
					res_[8] = uint2char_(gameBoard.getFailures(saveNations[idx][i]) % 10);

					res_[10] = uint2char_(gameBoard.getCount(saveNations[idx][i]) / 10);
					res_[11] = uint2char_(gameBoard.getCount(saveNations[idx][i]) % 10);

					for (size_t res = 1; res < 13; res++)
					{
						if (gameBoard.getResearch(saveNations[idx][i], res) == true)
							res_[12 + res] = 'Y';
						else
							res_[12 + res] = 'N';
					}

					WriteFile(hFile, res_, (DWORD)32, &bytesWritten, NULL);
				}
			}

			// War matrix
			{{
					char wars_[33] = "WARS:                          \n";
					WriteFile(hFile, wars_, (DWORD)32, &bytesWritten, NULL);

					wars_[0] = ' '; wars_[1] = ' '; wars_[2] = ' '; wars_[3] = ' '; wars_[4] = ' ';
					for (uint16_t i = 0; i < 10; i++)
					{
						for (uint16_t j = 0; j < 10; j++)
						{
							if (gameBoard.getAtWarWith(i, j) == true)
								wars_[j + 1] = 'Y';
							else
								wars_[j + 1] = 'N';
						}

						WriteFile(hFile, wars_, (DWORD)32, &bytesWritten, NULL);
					}
			}}

			// Territories
			{
				char ters_[33] = "TERRITORIES:                   \n";
				WriteFile(hFile, ters_, (DWORD)32, &bytesWritten, NULL);

				uint16_t low = (gameBoard.getGameType() != PACIFIC_GAME) ? (TER_ALBERTA) : (TER_EVENKIYSKIY);
				uint16_t high = (gameBoard.getGameType() != EUROPE_GAME) ? (TER_MEXICO) : (TER_WEST_INDIA);

				uint16_t lines = ((high - low + 1) / 10) + (((high - low + 1) % 10 == 0) ? (0) : (1));

				uint16_t terr = low;
				for (uint16_t i = 0; i < lines; i++)
				{
					for (uint16_t i = 0; i < 30; i++)
						ters_[i] = ' ';

					uint16_t lim = (i == lines - 1) ? ((high - low + 1) % 10) : (10);
					for (uint16_t j = 0; j < lim; j++)
					{
						uint16_t nat = gameBoard.getTerritoryOwner(low++);

						ters_[j * 3 + 1] = uint2char_(nat / 10); 
						ters_[j * 3 + 2] = uint2char_(nat % 10);
					}
					WriteFile(hFile, ters_, (DWORD)32, &bytesWritten, NULL);
				}
			}

			// City control
			{
				char city_[33] = "CITIES:                        \n";
				WriteFile(hFile, city_, (DWORD)32, &bytesWritten, NULL);

				city_[0] = ' '; city_[1] = ' '; city_[2] = ' '; city_[3] = ' '; city_[4] = ' ';
				city_[5] = ' '; city_[6] = ' ';
				for (uint16_t i = CITY_BERLIN; i <= CITY_SANFRAN; i++)
				{
					if (gameBoard.getCityControl(i) == SIDE_AXIS)
						city_[i + 1] = 'X';
					else
						city_[i + 1] = 'Y';
				}

				WriteFile(hFile, city_, (DWORD)32, &bytesWritten, NULL);
			}

			// Victory Cities
			{
				char city_[33] = " AXIS EUR:                     \n";
				uint16_t val = gameBoard.getNumVicCities(VIC_AXIS_EUR);
				city_[11] = uint2char_(val / 10); city_[12] = uint2char_(val % 10);
				WriteFile(hFile, city_, (DWORD)32, &bytesWritten, NULL);

				city_[6] = 'P'; city_[7] = 'A'; city_[8] = 'C';
				val = gameBoard.getNumVicCities(VIC_AXIS_PAC);
				city_[11] = uint2char_(val / 10); city_[12] = uint2char_(val % 10);
				WriteFile(hFile, city_, (DWORD)32, &bytesWritten, NULL);

				city_[1] = 'A'; city_[2] = 'L'; city_[3] = 'L'; city_[4] = 'Y';
				city_[6] = 'E'; city_[7] = 'U'; city_[8] = 'R';
				val = gameBoard.getNumVicCities(VIC_ALLIES_EUR);
				city_[11] = uint2char_(val / 10); city_[12] = uint2char_(val % 10);
				WriteFile(hFile, city_, (DWORD)32, &bytesWritten, NULL);

				city_[6] = 'P'; city_[7] = 'A'; city_[8] = 'C';
				val = gameBoard.getNumVicCities(VIC_ALLIES_PAC);
				city_[11] = uint2char_(val / 10); city_[12] = uint2char_(val % 10);
				WriteFile(hFile, city_, (DWORD)32, &bytesWritten, NULL);
			}
			{
				// Victory Cities (turn by turn)
				for (int j = 0; j <= (turn + 1) / 6; j++) // 6 per line
				{
					char city_[33] = " HIST:                         \n";

					int cond = (j == (turn + 1) / 6) ? ((turn + 1) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						char* tmp = uint2char(gameBoard.getNumVicCities(SIDE_AXIS, 6 * j + m));
						city_[7 + 3 * m] = tmp[1]; city_[8 + 3 * m] = tmp[2];
					}
					WriteFile(hFile, city_, (DWORD)32, &bytesWritten, NULL);
				}
				for (int j = 0; j <= (turn + 1) / 6; j++) // 6 per line
				{
					char city_[33] = " HIST:                         \n";

					int cond = (j == (turn + 1) / 6) ? ((turn + 1) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						char* tmp = uint2char(gameBoard.getNumVicCities(SIDE_ALLIES, 6 * j + m));
						city_[7 + 3 * m] = tmp[1]; city_[8 + 3 * m] = tmp[2];
					}
					WriteFile(hFile, city_, (DWORD)32, &bytesWritten, NULL);
				}
			}
			{
				char vic_[33] = "VICTORY:                       \n";
				WriteFile(hFile, vic_, (DWORD)32, &bytesWritten, NULL);

				char dly_[33] = " AXIS EUR DLY:  ,              \n";
				if (gameBoard.getVicDly(VIC_AXIS_EUR).vicDly == true)
				{
					dly_[15] = 'Y';
					dly_[18] = uint2char_(gameBoard.getVicDly(VIC_AXIS_EUR).nat / 10); 
					dly_[19] = uint2char_(gameBoard.getVicDly(VIC_AXIS_EUR).nat % 10);
				}
				else
				{
					dly_[15] = 'N'; dly_[16] = ' ';
				}
				WriteFile(hFile, dly_, (DWORD)32, &bytesWritten, NULL);

				dly_[2] = 'L'; dly_[3] = 'L'; dly_[4] = 'Y';
				if (gameBoard.getVicDly(VIC_ALLIES_EUR).vicDly == true)
				{
					dly_[15] = 'Y';
					dly_[18] = uint2char_(gameBoard.getVicDly(VIC_ALLIES_EUR).nat / 10);
					dly_[19] = uint2char_(gameBoard.getVicDly(VIC_ALLIES_EUR).nat % 10);
				}
				else
				{
					dly_[15] = 'N'; dly_[16] = ' ';
				}
				WriteFile(hFile, dly_, (DWORD)32, &bytesWritten, NULL);

				dly_[2] = 'X'; dly_[3] = 'I'; dly_[4] = 'S';
				dly_[6] = 'P'; dly_[7] = 'A'; dly_[8] = 'C';
				if (gameBoard.getVicDly(VIC_AXIS_PAC).vicDly == true)
				{
					dly_[15] = 'Y';
					dly_[18] = uint2char_(gameBoard.getVicDly(VIC_AXIS_PAC).nat / 10);
					dly_[19] = uint2char_(gameBoard.getVicDly(VIC_AXIS_PAC).nat % 10);
				}
				else
				{
					dly_[15] = 'N'; dly_[16] = ' ';
				}
				WriteFile(hFile, dly_, (DWORD)32, &bytesWritten, NULL);
			}
			{
				char cond_[33] = " LND:                          \n";
				if (gameBoard.getLondonFallen() == true)
					cond_[6] = 'Y';
				else
					cond_[6] = 'N';
				WriteFile(hFile, cond_, (DWORD)32, &bytesWritten, NULL);

				cond_[1] = 'N'; cond_[2] = 'A'; cond_[3] = 'F';
				if (gameBoard.getNAFallen() == true)
					cond_[6] = 'Y';
				else
					cond_[6] = 'N';
				WriteFile(hFile, cond_, (DWORD)32, &bytesWritten, NULL);

				cond_[1] = 'J'; cond_[2] = 'P'; cond_[3] = 'N';
				if (gameBoard.getJPNDeclaredWarOnUK() == true)
					cond_[6] = 'Y';
				else
					cond_[6] = 'N';
				WriteFile(hFile, cond_, (DWORD)32, &bytesWritten, NULL);

				cond_[1] = 'U'; cond_[2] = 'S'; cond_[3] = 'A';
				if (gameBoard.getDeclaredWarOnUSA() == true)
					cond_[6] = 'Y';
				else
					cond_[6] = 'N';
				WriteFile(hFile, cond_, (DWORD)32, &bytesWritten, NULL);

				cond_[1] = 'F'; cond_[2] = 'R'; cond_[3] = 'A';
				if (gameBoard.getFranceLiberated() == true)
					cond_[6] = 'Y';
				else
					cond_[6] = 'N';
				WriteFile(hFile, cond_, (DWORD)32, &bytesWritten, NULL);

				cond_[1] = 'S'; cond_[2] = 'O'; cond_[3] = 'V';
				if (gameBoard.getSovControlGer() == true)
					cond_[6] = 'Y';
				else
					cond_[6] = 'N';
				WriteFile(hFile, cond_, (DWORD)32, &bytesWritten, NULL);

				cond_[1] = 'U'; cond_[2] = 'S'; cond_[3] = 'A';
				if (gameBoard.getUSABonus() == true)
					cond_[6] = 'Y';
				else
					cond_[6] = 'N';
				WriteFile(hFile, cond_, (DWORD)32, &bytesWritten, NULL);

				cond_[1] = 'F'; cond_[2] = 'R'; cond_[3] = 'A';
				if (gameBoard.getFRABonus() == true)
					cond_[6] = 'Y';
				else
					cond_[6] = 'N';
				WriteFile(hFile, cond_, (DWORD)32, &bytesWritten, NULL);
			}

			// Misc
			{
				char misc_[33] = "MISC:                          \n";
				WriteFile(hFile, misc_, (DWORD)32, &bytesWritten, NULL);

				misc_[0] = ' '; misc_[1] = 'C'; misc_[2] = 'U'; misc_[3] = 'B';
				if (currUKButton == true)
					misc_[6] = 'Y';
				else
					misc_[6] = 'N';
				WriteFile(hFile, misc_, (DWORD)32, &bytesWritten, NULL);

				misc_[1] = 'T'; misc_[2] = 'O'; misc_[3] = 'G';
				if (currUKButtonToggled == true)
					misc_[6] = 'Y';
				else
					misc_[6] = 'N';
				WriteFile(hFile, misc_, (DWORD)32, &bytesWritten, NULL);

				misc_[1] = 'N'; misc_[2] = 'E'; misc_[3] = 'U';
				if (gameBoard.getNeutralLean() == SIDE_AXIS)
					misc_[6] = 'X';
				else if (gameBoard.getNeutralLean() == SIDE_ALLIES)
					misc_[6] = 'Y';
				else
					misc_[6] = 'N';
				WriteFile(hFile, misc_, (DWORD)32, &bytesWritten, NULL);

				misc_[1] = 'M'; misc_[2] = 'O'; misc_[3] = 'N';
				if (gameBoard.getMongoliaLean() == true)
					misc_[6] = 'Y';
				else
					misc_[6] = 'N';
				WriteFile(hFile, misc_, (DWORD)32, &bytesWritten, NULL);
			}

			// Log
			{
				char log_[33] = "LOG:                           \n";
				WriteFile(hFile, log_, (DWORD)32, &bytesWritten, NULL);

				log_[0] = ' '; log_[1] = 'I'; log_[2] = 'D'; log_[3] = 'X'; log_[4] = ':';

				int page_ = gameLog->getCurrPage();
				char* tmp = uint2char(page_);
				log_[5] = tmp[0]; log_[6] = tmp[1]; log_[7] = tmp[2];

				int col_ = gameLog->getCurrCol();
				tmp = uint2char(col_);
				log_[9] = tmp[0]; log_[10] = tmp[1]; log_[11] = tmp[2];

				int row_ = gameLog->getCurrRow();
				tmp = uint2char(row_);
				log_[13] = tmp[0]; log_[14] = tmp[1]; log_[15] = tmp[2];

				int turn_ = gameLog->getCurrTurn();
				tmp = uint2char(turn_);
				log_[17] = tmp[0]; log_[18] = tmp[1]; log_[19] = tmp[2];

				int nat_ = gameLog->getCurrNat();
				tmp = uint2char(nat_);
				log_[21] = tmp[0]; log_[22] = tmp[1]; log_[23] = tmp[2];

				WriteFile(hFile, log_, (DWORD)32, &bytesWritten, NULL);

				// The existence of Craig Smith is endlessly amusing to me
				{
					for (int j = 0; j < 31; j++)
						log_[j] = ' ';

					if (gameLog->getTrgtEx())
						log_[1] = 'Y';
					else
						log_[1] = 'N';

					if (gameLog->getResEx())
						log_[2] = 'Y';
					else
						log_[2] = 'N';

					if (gameLog->getOccEx())
						log_[3] = 'Y';
					else
						log_[3] = 'N';

					for (int j = 0; j < 10; j++)
					{
						int idx = j + 5;
						if (gameLog->getCapEx(j))
							log_[idx] = 'Y';
						else
							log_[idx] = 'N';
					}

					for (int j = 0; j < 10; j++)
					{
						int idx = j + 16;
						if (gameLog->getRecEx(j))
							log_[idx] = 'Y';
						else
							log_[idx] = 'N';
					}

					WriteFile(hFile, log_, (DWORD)32, &bytesWritten, NULL);

					if (log_[1] == 'Y')
					{
						char idx_[33] = "                               \n";
						int p_, c_, r_;
						gameLog->getTrgtPos(p_, c_, r_);
						tmp = uint2char(p_);
						idx_[1] = tmp[0]; idx_[2] = tmp[1]; idx_[3] = tmp[2];
						tmp = uint2char(c_);
						idx_[5] = tmp[0]; idx_[6] = tmp[1]; idx_[7] = tmp[2];
						tmp = uint2char(r_);
						idx_[9] = tmp[0]; idx_[10] = tmp[1]; idx_[11] = tmp[2];

						WriteFile(hFile, idx_, (DWORD)32, &bytesWritten, NULL);
					}

					if (log_[2] == 'Y')
					{
						char idx_[33] = "                               \n";
						int p_, c_, r_;
						gameLog->getResPos(p_, c_, r_);
						tmp = uint2char(p_);
						idx_[1] = tmp[0]; idx_[2] = tmp[1]; idx_[3] = tmp[2];
						tmp = uint2char(c_);
						idx_[5] = tmp[0]; idx_[6] = tmp[1]; idx_[7] = tmp[2];
						tmp = uint2char(r_);
						idx_[9] = tmp[0]; idx_[10] = tmp[1]; idx_[11] = tmp[2];

						WriteFile(hFile, idx_, (DWORD)32, &bytesWritten, NULL);
					}

					if (log_[3] == 'Y')
					{
						char idx_[33] = "                               \n";
						int p_, c_, r_;
						gameLog->getOccPos(p_, c_, r_);
						tmp = uint2char(p_);
						idx_[1] = tmp[0]; idx_[2] = tmp[1]; idx_[3] = tmp[2];
						tmp = uint2char(c_);
						idx_[5] = tmp[0]; idx_[6] = tmp[1]; idx_[7] = tmp[2];
						tmp = uint2char(r_);
						idx_[9] = tmp[0]; idx_[10] = tmp[1]; idx_[11] = tmp[2];

						WriteFile(hFile, idx_, (DWORD)32, &bytesWritten, NULL);
					}

					for (int j = 0; j < 10; j++)
					{
						int idx = j + 5;
						if (log_[idx] == 'Y')
						{
							char idx_[33] = "                               \n";
							int p_, c_, r_;
							gameLog->getCapPos(j, p_, c_, r_);
							tmp = uint2char(p_);
							idx_[1] = tmp[0]; idx_[2] = tmp[1]; idx_[3] = tmp[2];
							tmp = uint2char(c_);
							idx_[5] = tmp[0]; idx_[6] = tmp[1]; idx_[7] = tmp[2];
							tmp = uint2char(r_);
							idx_[9] = tmp[0]; idx_[10] = tmp[1]; idx_[11] = tmp[2];

							WriteFile(hFile, idx_, (DWORD)32, &bytesWritten, NULL);
						}
					}

					for (int j = 0; j < 10; j++)
					{
						int idx = j + 16;
						if (log_[idx] == 'Y')
						{
							char idx_[33] = "                               \n";
							int p_, c_, r_;
							gameLog->getRecPos(j, p_, c_, r_);
							tmp = uint2char(p_);
							idx_[1] = tmp[0]; idx_[2] = tmp[1]; idx_[3] = tmp[2];
							tmp = uint2char(c_);
							idx_[5] = tmp[0]; idx_[6] = tmp[1]; idx_[7] = tmp[2];
							tmp = uint2char(r_);
							idx_[9] = tmp[0]; idx_[10] = tmp[1]; idx_[11] = tmp[2];

							WriteFile(hFile, idx_, (DWORD)32, &bytesWritten, NULL);
						}
					}
				}
				{
					char lib_[86]; 
					lib_[84] = '\n';

					for (int j = 0; j < 31; j++)
						log_[j] = ' ';

					for (int j = 0; j < 10; j++)
					{
						for (int k = 0; k < 84; k++)
							lib_[k] = ' ';

						int p_, c_, r_;
						int idx = 1;
						for (int k = 0; k < 10; k++)
						{
							if (gameLog->getLibEx(j, k))
								log_[idx] = 'Y';
							else
								log_[idx] = 'N';
							idx++;
						}
						WriteFile(hFile, log_, (DWORD)32, &bytesWritten, NULL);
						idx = 1;

						int idx_ = 0;
						for (int k = 0; k < 10; k++)
						{
							if (log_[idx] == 'Y')
							{
								gameLog->getLibPos(j, k, p_, c_, r_);
								tmp = uint2char(p_);
								lib_[idx_ + 1] = tmp[0]; lib_[idx_ + 2] = tmp[1]; lib_[idx_ + 3] = tmp[2];
								tmp = uint2char(c_);
								lib_[idx_ + 5] = tmp[0]; lib_[idx_ + 6] = tmp[1]; lib_[idx_ + 7] = tmp[2];
								tmp = uint2char(r_);
								lib_[idx_ + 9] = tmp[0]; lib_[idx_ + 10] = tmp[1]; lib_[idx_ + 11] = tmp[2];

								idx_ += 12;
							}
							idx++;
						}

						if (idx_ != 0)
							WriteFile(hFile, lib_, (DWORD)85, &bytesWritten, NULL);
					}

					for (int k = 0; k < 31; k++)
						log_[k] = ' ';
				}

				for (int j = 0; j <= page_; j++)
					for (int k = 0; k <= (j == page_ ? col_ : 1); k++)
						for (int n = 0; n <= ((j == page_ && k == col_) ? row_ - 1 : ROWS - 1); n++)
						{
							char text_[33] = "                               \n";

							char* tmp = uint2char(gameLog->getTurn(j, k, n));
							text_[1] = tmp[0]; text_[2] = tmp[1]; text_[3] = tmp[2];

							tmp = int2char(gameLog->getVerb(j, k, n));
							text_[5] = tmp[0]; text_[6] = tmp[1]; text_[7] = tmp[2];

							if (gameLog->getVerb(j, k, n) != V_CUSTOM)
							{
								tmp = int2char(gameLog->getSubj(j, k, n));
								text_[9] = tmp[0]; text_[10] = tmp[1]; text_[11] = tmp[2];

								tmp = int2char(gameLog->getObjt(j, k, n));
								text_[13] = tmp[0]; text_[14] = tmp[1]; text_[15] = tmp[2];

								tmp = int2char(gameLog->getIndr(j, k, n));
								text_[17] = tmp[0]; text_[18] = tmp[1]; text_[19] = tmp[2];

								tmp = uint2char(gameLog->getTrgtSize(j, k, n));
								text_[21] = tmp[0]; text_[22] = tmp[1]; text_[23] = tmp[2];

								WriteFile(hFile, text_, (DWORD)32, &bytesWritten, NULL);

								int loops = 0;
								if (gameLog->getTrgtSize(j, k, n) != 0)
								{
									loops = (gameLog->getTrgtSize(j, k, n) / 6) + 1;
									if (gameLog->getTrgtSize(j, k, n) % 6 == 0)
										loops--;
								}
								for (int q = 0; q < loops; q++)
								{
									char trgt_[33] = "                               \n";

									int len = (q == loops - 1) ? (gameLog->getTrgtSize(j, k, n) - (q * 6)) : 6;
									int idx = 1;
									for (int w = 0; w < len; w++)
									{
										tmp = uint2char(gameLog->getTrgt(j, k, n, w + q * 6));
										trgt_[idx] = tmp[0]; trgt_[idx + 1] = tmp[1]; trgt_[idx + 2] = tmp[2];

										idx += 4;
									}

									WriteFile(hFile, trgt_, (DWORD)32, &bytesWritten, NULL);
								}
							}
							else // Custom log entry
							{
								char cust_[TEXTLEN];

								for (int q = 0; q < TEXTLEN; q++)
									cust_[q] = '\0';

								int len = 0;
								for (int q = 0; q < TEXTLEN; q++)
								{
									cust_[q] = gameLog->getCust(j, k, n, q);

									if (cust_[q] == '\0')
									{
										cust_[q] = '\n';
										len = q + 1;
										break;
									}
								}
								
								tmp = uint2char(len);
								text_[9] = tmp[0]; text_[10] = tmp[1]; text_[11] = tmp[2];

								WriteFile(hFile, text_, (DWORD)32, &bytesWritten, NULL);
								WriteFile(hFile, cust_, (DWORD)len, &bytesWritten, NULL);
							}
						}
			}

			CloseHandle(hFile);
		}
	}
	return true;
}

void Game::doLoadGame(HWND hWnd, Board& gameBoard)
{
	success = false;

	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	DWORD resLen = MAX_PATH;

	ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = (LPWSTR)fileName;
	ofn.nMaxFile = resLen;
	ofn.lpstrDefExt = L"txt";
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

	if (GetOpenFileName(&ofn))
	{
		HANDLE hFile;
		hFile = CreateFile(ofn.lpstrFile, GENERIC_READ, FILE_SHARE_READ, NULL,
			OPEN_EXISTING, 0, NULL);

		if (hFile != INVALID_HANDLE_VALUE)
		{
			// Code to load game data
			// It will also become quite long
			DWORD bytesRead = 0;
			char str[33];

			// Game Type
			success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
			if (str[6] == 'E')
				gameBoard.setGameType(EUROPE_GAME);
			else if (str[6] == 'P')
				gameBoard.setGameType(PACIFIC_GAME);
			else
				gameBoard.setGameType(GLOBAL_GAME);

			// Game Research
			success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
			if (str[10] == 'Y')
				gameBoard.setGameResearch(TRUE);
			else
				gameBoard.setGameResearch(FALSE);

			// Turn number, current nation, current phase
			{
				char tmp[4]; tmp[3] = '\0';
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				tmp[0] = str[6]; tmp[1] = str[7]; tmp[2] = str[8];
				gameBoard.setGameTurn(char2uint(tmp, 3) - 1);
				gameBoard.setGameCurrNation(char2uint_(str[10]));
				gameBoard.setGameTurnPhase(char2uint_(str[12]));
			}

			// Nation Status Section
			uint16_t idx = gameBoard.getGameType() - 114;
			for (uint16_t i = 0; i < saveNations[idx].size(); i++)
			{
				// Ignore nation name
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

				// Nation controls capital
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

				if (str[7] == 'Y')
					gameBoard.setNationControlsCapital(saveNations[idx][i], true);
				else
					gameBoard.setNationControlsCapital(saveNations[idx][i], false);

				uint16_t turn = gameBoard.getGameTurn();
				uint16_t adj = (isBeforeNation(saveNations[idx][i], gameBoard.getGameCurrNation())) ? (2) : (1);

				// Nation bank (turn by turn)
				gameBoard.setNationSize(saveNations[idx][i], turn + adj);
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char tmp[4];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						tmp[0] = str[7 + 4 * m]; tmp[1] = str[8 + 4 * m]; tmp[2] = str[9 + 4 * m];
						gameBoard.setNationBank(saveNations[idx][i], 6 * j + m, char2uint(tmp, 3));
					}
				}
				// Nation income (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char tmp[4];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						tmp[0] = str[7 + 4 * m]; tmp[1] = str[8 + 4 * m]; tmp[2] = str[9 + 4 * m];
						gameBoard.setNationIncome(saveNations[idx][i], 6 * j + m, char2uint(tmp, 3));
					}
				}
				// Nation bonus (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char tmp[4];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						tmp[0] = str[7 + 4 * m]; tmp[1] = str[8 + 4 * m]; tmp[2] = str[9 + 4 * m];
						gameBoard.setNationBonus(saveNations[idx][i], 6 * j + m, char2uint(tmp, 3));
					}
				}
				// Nation penalty (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char tmp[4];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						tmp[0] = str[7 + 4 * m]; tmp[1] = str[8 + 4 * m]; tmp[2] = str[9 + 4 * m];
						gameBoard.setNationPenalty(saveNations[idx][i], 6 * j + m, char2uint(tmp, 3));
					}
				}
				// Nation expenses (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char tmp[4];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						tmp[0] = str[7 + 4 * m]; tmp[1] = str[8 + 4 * m]; tmp[2] = str[9 + 4 * m];
						gameBoard.setNationExpenses(saveNations[idx][i], 6 * j + m, char2uint(tmp, 3));
					}
				}
				// Nation territories (turn by turn)
				for (int j = 0; j <= (turn + adj) / 6; j++) // 6 per line
				{
					char tmp[4];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					int cond = (j == (turn + adj) / 6) ? ((turn + adj) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						tmp[0] = str[7 + 4 * m]; tmp[1] = str[8 + 4 * m]; tmp[2] = str[9 + 4 * m];
						gameBoard.setNationTerritories(saveNations[idx][i], 6 * j + m, char2uint(tmp, 3));
					}
				}

				// Purchase history
				{
					char tmp[4];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					for (uint16_t j = 0; j < 6; j++)
					{
						tmp[0] = str[7 + 4 * j]; tmp[1] = str[8 + 4 * j]; tmp[2] = str[9 + 4 * j];
						gameBoard.setPurchases(saveNations[idx][i], j, char2uint(tmp, 3));
					}

					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
					for (uint16_t j = 6; j < 12; j++)
					{
						tmp[0] = str[4 * j - 17]; tmp[1] = str[4 * j - 16]; tmp[2] = str[4 * j - 15];
						gameBoard.setPurchases(saveNations[idx][i], j, char2uint(tmp, 3));
					}

					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
					for (uint16_t j = 12; j < 18; j++)
					{
						tmp[0] = str[4 * j - 41]; tmp[1] = str[4 * j - 40]; tmp[2] = str[4 * j - 39];
						gameBoard.setPurchases(saveNations[idx][i], j, char2uint(tmp, 3));
					}

					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
					for (uint16_t j = 18; j < 20; j++)
					{
						tmp[0] = str[4 * j - 65]; tmp[1] = str[4 * j - 64]; tmp[2] = str[4 * j - 63];
						gameBoard.setPurchases(saveNations[idx][i], j, char2uint(tmp, 3));
					}
				}
				// Research
				if (gameBoard.getGameResearch() == true)
				{
					char tmp[4];
					Research tmp_res;

					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					tmp[0] = str[6]; tmp[1] = str[7]; tmp[2] = str[8];
					tmp_res.setFailures(char2uint(tmp, 3));

					for (size_t res = 1; res < 13; res++)
						if (str[12 + res] == 'Y')
						{
							tmp_res.setResearch(res);
							addResearchIcon(res, saveNations[idx][i]);
						}

					gameBoard.setResearch(saveNations[idx][i], tmp_res);
				}
			}

			// War matrix
			{{
				// Remove header
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

				for (uint16_t i = 0; i < 10; i++)
					{
						success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
						for (uint16_t j = 0; j < 10; j++)
						{
							if (str[j + 1] == 'Y')
								gameBoard.setWarMatrix(i, j, true);
							else
								gameBoard.setWarMatrix(i, j, false);
						}
					}
			}}

			// Territories
			{
				// Remove header
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

				uint16_t low = (gameBoard.getGameType() != PACIFIC_GAME) ? (TER_ALBERTA) : (TER_EVENKIYSKIY);
				uint16_t high = (gameBoard.getGameType() != EUROPE_GAME) ? (TER_MEXICO) : (TER_WEST_INDIA);

				uint16_t lines = ((high - low + 1) / 10) + (((high - low + 1) % 10 == 0) ? (0) : (1));

				char tmp[3]; tmp[2] = '\0';

				uint16_t terr = low;
				for (uint16_t i = 0; i < lines; i++)
				{
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
					uint16_t lim = (i == lines - 1) ? ((high - low + 1) % 10) : (10);
					for (uint16_t j = 0; j < lim; j++)
					{
						tmp[0] = str[j * 3 + 1];
						tmp[1] = str[j * 3 + 2];

						gameBoard.setTerritoryOwner(terr++, char2uint(tmp, 2));
					}
				}				
			}

			// City control
			{
				// Remove header
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

				for (uint16_t i = CITY_BERLIN; i <= CITY_SANFRAN; i++)
				{
					if (str[i + 1] == 'X')
						gameBoard.setCityControl(i, SIDE_AXIS);
					else
						gameBoard.setCityControl(i, SIDE_ALLIES);
				}
			}

			// Victory Cities
			{
				char tmp[3];
				tmp[2] = '\0';

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				tmp[0] = str[11]; tmp[1] = str[12];
				gameBoard.setNumVicCities(VIC_AXIS_EUR, char2uint(tmp, 2));

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				tmp[0] = str[11]; tmp[1] = str[12];
				gameBoard.setNumVicCities(VIC_AXIS_PAC, char2uint(tmp, 2));

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				tmp[0] = str[11]; tmp[1] = str[12];
				gameBoard.setNumVicCities(VIC_ALLIES_EUR, char2uint(tmp, 2));

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				tmp[0] = str[11]; tmp[1] = str[12];
				gameBoard.setNumVicCities(VIC_ALLIES_PAC, char2uint(tmp, 2));
			}
			{
				// Victory Cities (turn by turn)
				uint16_t turn = gameBoard.getGameTurn();
				for (int j = 0; j <= (turn + 1) / 6; j++) // 6 per line
				{
					char tmp[3];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					int cond = (j == (turn + 1) / 6) ? ((turn + 1) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						tmp[0] = str[7 + 3 * m]; tmp[1] = str[8 + 3 * m];
						gameBoard.setNumVicCities(SIDE_AXIS, 6 * j + m, char2uint(tmp, 2));
					}
				}
				for (int j = 0; j <= (turn + 1) / 6; j++) // 6 per line
				{
					char tmp[3];
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					int cond = (j == (turn + 1) / 6) ? ((turn + 1) % 6) : (5);
					for (int m = 0; m <= cond; m++)
					{
						tmp[0] = str[7 + 3 * m]; tmp[1] = str[8 + 3 * m];
						gameBoard.setNumVicCities(SIDE_ALLIES, 6 * j + m, char2uint(tmp, 2));
					}
				}
			}
			{
				char tmp[3];
				tmp[2] = '\0';
				vicDlyEur dly;

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[15] == 'Y')
				{
					dly.vicDly = true;
					tmp[0] = str[18]; tmp[1] = str[19];
					dly.nat = char2uint(tmp, 2);
				}
				else
					dly.vicDly = false;
				gameBoard.setVicDly(VIC_AXIS_EUR, dly);

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[15] == 'Y')
				{
					dly.vicDly = true;
					tmp[0] = str[18]; tmp[1] = str[19];
					dly.nat = char2uint(tmp, 2);
				}
				else
					dly.vicDly = false;
				gameBoard.setVicDly(VIC_ALLIES_EUR, dly);

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[15] == 'Y')
				{
					dly.vicDly = true;
					tmp[0] = str[18]; tmp[1] = str[19];
					dly.nat = char2uint(tmp, 2);
				}
				else
					dly.vicDly = false;
				gameBoard.setVicDly(VIC_AXIS_PAC, dly);
			}
			{
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.setLondonFallen();

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.setNAFallen();

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.setJPNDeclaredWarOnUK();

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.setDeclaredWarOnUSA();

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.setFranceLiberated();

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.setSovControlGer();

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.getUSABonus();

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.getFRABonus();
			}

			// Misc
			{
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					currUKButton = true;
				else
					currUKButton = false;

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					currUKButtonToggled = true;
				else
					currUKButtonToggled = false;

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'X')
					gameBoard.setNeutralLean(SIDE_AXIS);
				else if (str[6] == 'Y')
					gameBoard.setNeutralLean(SIDE_ALLIES);
				else
					gameBoard.setNeutralLean(SIDE_NEUTRAL);

				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				if (str[6] == 'Y')
					gameBoard.setMongoliaLean(SIDE_NEUTRAL); // This is wrong now
			}

			// Log
			{
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);
				success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

				char tmp[4];

				tmp[0] = str[5]; tmp[1] = str[6]; tmp[2] = str[7];
				gameLog->setCurrPage(char2uint(tmp, 3));
				int page_ = char2uint(tmp, 3);

				tmp[0] = str[9]; tmp[1] = str[10]; tmp[2] = str[11];
				gameLog->setCurrCol(char2uint(tmp, 3));
				int col_ = char2uint(tmp, 3);

				tmp[0] = str[13]; tmp[1] = str[14]; tmp[2] = str[15];
				gameLog->setCurrRow(char2uint(tmp, 3));
				int row_ = char2uint(tmp, 3);

				tmp[0] = str[17]; tmp[1] = str[18]; tmp[2] = str[19];
				gameLog->setCurrTurn(char2uint(tmp, 3));
				int turn_ = char2uint(tmp, 3);

				tmp[0] = str[21]; tmp[1] = str[22]; tmp[2] = str[23];
				gameLog->setCurrNat(char2uint(tmp, 3));
				int nat_ = char2uint(tmp, 3);

				// His name is just "Craig Smith."
				{
					success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

					if (str[1] == 'Y')
						gameLog->setTrgtEx(true);
					else
						gameLog->setTrgtEx(false);

					if (str[2] == 'Y')
						gameLog->setResEx(true);
					else
						gameLog->setResEx(false);

					if (str[3] == 'Y')
						gameLog->setOccEx(true);
					else
						gameLog->setOccEx(false);

					for (int j = 0; j < 10; j++)
					{
						int idx = j + 5;
						if (str[idx] == 'Y')
							gameLog->setCapEx(j, true);
						else
							gameLog->setCapEx(j, false);
					}

					for (int j = 0; j < 10; j++)
					{
						int idx = j + 16;
						if (str[idx] == 'Y')
							gameLog->setRecEx(j, true);
						else
							gameLog->setRecEx(j, false);
					}

					if (str[1] == 'Y')
					{
						char text[33];
						success = ReadFile(hFile, text, (DWORD)32, &bytesRead, NULL);
						int p_, c_, r_;
						
						tmp[0] = text[1]; tmp[1] = text[2]; tmp[2] = text[3];
						p_ = char2uint(tmp, 3);
						tmp[0] = text[5]; tmp[1] = text[6]; tmp[2] = text[7];
						c_ = char2uint(tmp, 3);
						tmp[0] = text[9]; tmp[1] = text[10]; tmp[2] = text[11];
						r_ = char2uint(tmp, 3);
						gameLog->setTrgtPos(p_, c_, r_);
					}

					if (str[2] == 'Y')
					{
						char text[33];
						success = ReadFile(hFile, text, (DWORD)32, &bytesRead, NULL);
						int p_, c_, r_;

						tmp[0] = text[1]; tmp[1] = text[2]; tmp[2] = text[3];
						p_ = char2uint(tmp, 3);
						tmp[0] = text[5]; tmp[1] = text[6]; tmp[2] = text[7];
						c_ = char2uint(tmp, 3);
						tmp[0] = text[9]; tmp[1] = text[10]; tmp[2] = text[11];
						r_ = char2uint(tmp, 3);
						gameLog->setResPos(p_, c_, r_);
					}

					if (str[3] == 'Y')
					{
						char text[33];
						success = ReadFile(hFile, text, (DWORD)32, &bytesRead, NULL);
						int p_, c_, r_;

						tmp[0] = text[1]; tmp[1] = text[2]; tmp[2] = text[3];
						p_ = char2uint(tmp, 3);
						tmp[0] = text[5]; tmp[1] = text[6]; tmp[2] = text[7];
						c_ = char2uint(tmp, 3);
						tmp[0] = text[9]; tmp[1] = text[10]; tmp[2] = text[11];
						r_ = char2uint(tmp, 3);
						gameLog->setOccPos(p_, c_, r_);
					}

					for (int j = 0; j < 10; j++)
					{
						int idx = j + 5;
						if (str[idx] == 'Y')
						{
							char text[33];
							success = ReadFile(hFile, text, (DWORD)32, &bytesRead, NULL);
							int p_, c_, r_;

							tmp[0] = text[1]; tmp[1] = text[2]; tmp[2] = text[3];
							p_ = char2uint(tmp, 3);
							tmp[0] = text[5]; tmp[1] = text[6]; tmp[2] = text[7];
							c_ = char2uint(tmp, 3);
							tmp[0] = text[9]; tmp[1] = text[10]; tmp[2] = text[11];
							r_ = char2uint(tmp, 3);
							gameLog->setCapPos(j, p_, c_, r_);
						}
					}

					for (int j = 0; j < 10; j++)
					{
						int idx = j + 16;
						if (str[idx] == 'Y')
						{
							char text[33];
							success = ReadFile(hFile, text, (DWORD)32, &bytesRead, NULL);
							int p_, c_, r_;

							tmp[0] = text[1]; tmp[1] = text[2]; tmp[2] = text[3];
							p_ = char2uint(tmp, 3);
							tmp[0] = text[5]; tmp[1] = text[6]; tmp[2] = text[7];
							c_ = char2uint(tmp, 3);
							tmp[0] = text[9]; tmp[1] = text[10]; tmp[2] = text[11];
							r_ = char2uint(tmp, 3);
							gameLog->setRecPos(j, p_, c_, r_);
						}
					}
				}
				{
					char lib_[86];

					for (int j = 0; j < 10; j++)
					{
						success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

						int p_, c_, r_;
						int idx = 1;
						bool hasLibs = false;
						for (int k = 0; k < 10; k++)
						{
							if (str[idx] == 'Y')
							{
								gameLog->setLibEx(j, k, true);
								hasLibs = true;
							}
							else
								gameLog->setLibEx(j, k, false);
							idx++;
						}

						if (hasLibs)
						{
							success = ReadFile(hFile, lib_, (DWORD)85, &bytesRead, NULL);

							idx = 1;

							int idx_ = 0;
							for (int k = 0; k < 10; k++)
							{
								if (str[idx] == 'Y')
								{
									tmp[0] = lib_[idx_ + 1]; tmp[1] = lib_[idx_ + 2]; tmp[2] = lib_[idx_ + 3];
									p_ = char2uint(tmp, 3);
									tmp[0] = lib_[idx_ + 5]; tmp[1] = lib_[idx_ + 6]; tmp[2] = lib_[idx_ + 7];
									c_ = char2uint(tmp, 3);
									tmp[0] = lib_[idx_ + 9]; tmp[1] = lib_[idx_ + 10]; tmp[2] = lib_[idx_ + 11];
									r_ = char2uint(tmp, 3);

									gameLog->setLibPos(j, k, p_, c_, r_);

									idx_ += 12;
								}
								idx++;
							}
						}
					}
				}

				for (int j = 1; j <= page_; j++)
				{
					int p = j + 1;
					addLogTab(p);
				}
				if (col_ == 1 && row_ >= ROWS - 5)
				{
					int p = page_ + 2;
					addLogTab(p);
				}

				for (int j = 0; j <= page_; j++)
					for (int k = 0; k <= (j == page_ ? col_ : 1); k++)
						for (int n = 0; n <= ((j == page_ && k == col_) ? row_ - 1 : ROWS - 1); n++)
						{
							success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

							tmp[0] = str[1]; tmp[1] = str[2]; tmp[2] = str[3];
							gameLog->setTurn(j, k, n, char2uint(tmp, 3));

							tmp[0] = str[5]; tmp[1] = str[6]; tmp[2] = str[7];
							gameLog->setVerb(j, k, n, char2int(tmp, 3));

							if (char2uint(tmp, 3) != V_CUSTOM)
							{

								tmp[0] = str[9]; tmp[1] = str[10]; tmp[2] = str[11];
								gameLog->setSubj(j, k, n, char2int(tmp, 3));

								tmp[0] = str[13]; tmp[1] = str[14]; tmp[2] = str[15];
								gameLog->setObjt(j, k, n, char2int(tmp, 3));

								tmp[0] = str[17]; tmp[1] = str[18]; tmp[2] = str[19];
								gameLog->setIndr(j, k, n, char2int(tmp, 3));

								tmp[0] = str[21]; tmp[1] = str[22]; tmp[2] = str[23];
								int trgtSize = char2uint(tmp, 3);

								int loops = 0;
								if (trgtSize != 0)
								{
									loops = (trgtSize / 6) + 1;
									if (trgtSize % 6 == 0)
										loops--;
								}
								for (int q = 0; q < loops; q++)
								{
									success = ReadFile(hFile, str, (DWORD)32, &bytesRead, NULL);

									int len = (q == loops - 1) ? (trgtSize - (q * 6)) : 6;
									int idx = 1;
									for (int w = 0; w < len; w++)
									{
										tmp[0] = str[idx]; tmp[1] = str[idx + 1]; tmp[2] = str[idx + 2];
										gameLog->setTrgt(j, k, n, char2uint(tmp, 3));

										idx += 4;
									}
								}
							}
							else // Custom log entry
							{
								char cust_[TEXTLEN];

								tmp[0] = str[9]; tmp[1] = str[10]; tmp[2] = str[11];
								int len = char2uint(tmp, 3);

								success = ReadFile(hFile, cust_, (DWORD)len, &bytesRead, NULL);

								for (int q = 0; q < TEXTLEN; q++)
								{
									gameLog->setCust(j, k, n, q, cust_[q]);

									int q1 = q + 1;
									if (q1 < TEXTLEN)
										if (cust_[q1] == '\n')
											break;
								}
							}

							gameLog->reconstructText(j, k, n);
						}
			}

			CloseHandle(hFile);
			success = true;
		}
	}
}

void Game::setMainWnd(HWND& wnd)
{
	main_Wnd = wnd;
	SetClassLongPtr(main_Wnd, GCLP_HBRBACKGROUND, (LONG_PTR)backBrush0);
}

HWND Game::getMainWnd()
{
	return main_Wnd;
}

void Game::hideScreen()
{
	if (lastScreen != whichScreen)
	{
		switch (lastScreen)
		{
		case NATION_SCREEN:
			hideNationScreen();
			break;
		case SPREAD0_SCREEN:
		case SPREAD1_SCREEN:
			hideSpreadScreen();
			break;
		case GRAPH_SCREEN:
			hideGraphScreen();
			break;
		case LOG_SCREEN:
			hideLogScreen();
		case RES_SCREEN:
			hideResearchScreen();
			break;
		case REF_SCREEN:

		default:
			hideNationScreen();
			break;
		}

		lastScreen = whichScreen;
	}

	if (whichScreen == MAIN_SCREEN)
		ShowWindow(nationScreenTabs, SW_HIDE);	

	if (whichScreen != LOG_SCREEN)
		ShowWindow(logScreenTabs, SW_HIDE);
}

void Game::configGraphics(HDC& hdc)
{	
	// Convert main window RECT to RectF for use with GDIplus
	GetClientRect(main_Wnd, &nationScreenRect);

	 nationScreenWindow = nationScreenRect;

	// TEMP
	nationScreenWindow0.X = nationScreenRect.left;
	nationScreenWindow0.Width = nationScreenRect.right - nationScreenRect.left;
	nationScreenWindow0.Y = nationScreenRect.top;
	nationScreenWindow0.Height = nationScreenRect.bottom - nationScreenRect.top;

	gfx = new AAGraphics(main_Wnd, nationScreenWindow0);
	gfx->config(hdc);
	gfx->buttons->configScreenFrames(&screenFrames);
	gfx->tooltips->configScreenFrames(&screenFrames);

	// Fonts
	logTextFont = new Font(calibriFamily, TEXTFONT_S, FontStyleRegular, UnitPixel);
	logTurnFont = new Font(calibriFamily, TURNFONT_S, FontStyleRegular, UnitPixel);

	/// Brushes
	backBrush0 = CreateSolidBrush(RGB(240, 240, 240));

	debugGrid = new DebugGrid(nationScreenWindow0, 0, gfx->blackPen1, gfx->blackPen2, gfx->blackPen4);
}

void Game::configGameScreens()
{
	configNationScreen();
	configSpreadScreen();
	configGraphScreen();
	configLogScreen();
	configResearchScreen();

	gfx->buttons->configScreenFrames(&screenFrames);
	gfx->tooltips->configScreenFrames(&screenFrames);
}

void Game::setupGDI()
{
	GdiplusStartupInput gdiplusStartupInput;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

void Game::destroyGDI()
{
	GdiplusShutdown(gdiplusToken);
}




void Game::configSpread(Board& gameBoard)
{
	//uint16_t idx = gameBoard.getGameType() - 114;
	//for (uint16_t i = 0; i < saveNations[idx].size(); i++)
	//{
	//	uint16_t nat = saveNations[idx][i];
	//
	//	// Main spreadsheet
	//	if (nationSpreads[nat] == NULL)
	//		nationSpreads[nat] = new Spreadsheet(10);
	//
	//	// Last 5 turns spreadsheet
	//	if (miniSpreads[nat] == NULL)
	//		miniSpreads[nat] = new Spreadsheet(5);


		//miniSpreads[nat]->setCellText(1, BANK_POS, gameBoard.getNationBank(nat, 0));
		//miniSpreads[nat]->setCellText(2, BANK_POS, gameBoard.getNationBank(nat, 1));
		//miniSpreads[nat]->setCellText(1, INCM_POS, gameBoard.getNationIncome(nat, 0));
		//miniSpreads[nat]->setCellText(1, BONS_POS, gameBoard.getNationBonus(nat, 0));
		//miniSpreads[nat]->setCellText(1, PNLT_POS, gameBoard.getNationPenalty(nat, 0));
		//miniSpreads[nat]->setCellText(1, XPNS_POS, gameBoard.getNationExpenses(nat, 0));
	//}
}

