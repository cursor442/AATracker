
#include "AA_Tracker.h"

void Game::configResearchScreen()
{
	resBack = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_RES));

	gerIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_GER));
	gerIconMask = CreateBitmapMask(gerIcon, RGB(0, 0, 0));
	sovIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_SOV));
	sovIconMask = CreateBitmapMask(sovIcon, RGB(0, 0, 0));
	jpnIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_JPN));
	jpnIconMask = CreateBitmapMask(jpnIcon, RGB(0, 0, 0));
	usaIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_USA));
	usaIconMask = CreateBitmapMask(usaIcon, RGB(0, 0, 0));
	chnIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_CHN));
	chnIconMask = CreateBitmapMask(chnIcon, RGB(0, 0, 0));
	ukIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_UK));
	ukIconMask = CreateBitmapMask(ukIcon, RGB(0, 0, 0));
	itaIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ITA));
	itaIconMask = CreateBitmapMask(itaIcon, RGB(0, 0, 0));
	anzIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ANZ));
	anzIconMask = CreateBitmapMask(anzIcon, RGB(0, 0, 0));
	fraIcon = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_FRA));
	fraIconMask = CreateBitmapMask(fraIcon, RGB(0, 0, 0));

	GetObject(resBack, sizeof(bmpRes), &bmpRes);

	uint16_t baseX[6], baseY[2], deltaX, deltaY;

	baseX[0] = 230; baseX[1] = 442; baseX[2] = 654; baseX[3] = 866; baseX[4] = 1080; baseX[5] = 1294;
	baseY[0] = 130; baseY[1] = 340;

	deltaX = 70;
	deltaY = 65;

	for (uint16_t j = 0; j < 2; j++)
		for (uint16_t i = 0; i < 6; i++)
		{
			resIconPos[6 * j + i][0][0] = baseX[i];              resIconPos[6 * j + i][0][1] = baseY[j];              // top-left
			resIconPos[6 * j + i][1][0] = baseX[i] + 2 * deltaX; resIconPos[6 * j + i][1][1] = baseY[j];              // top-right
			resIconPos[6 * j + i][2][0] = baseX[i];              resIconPos[6 * j + i][2][1] = baseY[j] + 2 * deltaY; // bottom-left
			resIconPos[6 * j + i][3][0] = baseX[i] + 2 * deltaX; resIconPos[6 * j + i][3][1] = baseY[j] + 2 * deltaY; // bottom-right
			resIconPos[6 * j + i][4][0] = baseX[i] + deltaX;     resIconPos[6 * j + i][4][1] = baseY[j];              // top-mid
			resIconPos[6 * j + i][5][0] = baseX[i] + deltaX;     resIconPos[6 * j + i][5][1] = baseY[j] + 2 * deltaY; // bottom-mid
			resIconPos[6 * j + i][6][0] = baseX[i];              resIconPos[6 * j + i][6][1] = baseY[j] + deltaY;     // mid-left
			resIconPos[6 * j + i][7][0] = baseX[i] + 2 * deltaX; resIconPos[6 * j + i][7][1] = baseY[j] + deltaY;     // mid-right
			resIconPos[6 * j + i][8][0] = baseX[i] + deltaX;     resIconPos[6 * j + i][8][1] = baseY[j] + deltaY;     // mid-mid
		}	

	for (uint16_t i = 0; i < 12; i++)
		resIconOrd[i].resize(0);
}

void Game::addResearchIcon(uint16_t res, uint16_t nat)
{
	if (res != 0)
		resIconOrd[--res].push_back(nat);
}

bool Game::ResearchScreen(HWND& hWnd, HDC& hdc, PAINTSTRUCT& ps)
{
	hideScreen();

	if (researchWnd == NULL)
	{
		researchWnd = CreateWindowExA(
			WS_EX_PALETTEWINDOW,
			"STATIC", (PSTR)NULL,
			WS_CHILD | WS_VISIBLE,
			nationScreenWindow.right - 25, nationScreenWindow.top,
			25, (nationScreenWindow.bottom - nationScreenWindow.top),
			main_Wnd,
			NULL,
			hInst,
			NULL
		);

		hdcCompat = CreateCompatibleDC(hdc);
	}
	else
		ShowWindow(researchWnd, SW_SHOW);

	SelectObject(hdcCompat, resBack);
	BitBlt(hdc, 0, 25, bmpRes.bmWidth, bmpRes.bmHeight, hdcCompat, 0, 0, SRCCOPY);

	uint16_t nat;
	for (size_t n = 0; n < 12; n++)
		for (size_t i = 0; i < resIconOrd[n].size(); i++)
		{
			nat = resIconOrd[n][i];
			selectBitmap(nat, true);
			BitBlt(hdc, resIconPos[n][i][0], resIconPos[n][i][1], 64, 64, hdcCompat, 0, 0, SRCAND);
			selectBitmap(nat, false);
			BitBlt(hdc, resIconPos[n][i][0], resIconPos[n][i][1], 64, 64, hdcCompat, 0, 0, SRCPAINT);
		}

	// I could totally let players drag their markers around
	// But probably won't

	// Could also give initial location some dither
	// But that's too fancy for now

	return true;
}

void Game::hideResearchScreen()
{
	
}

HBITMAP Game::CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent)
{
	HDC hdcMem, hdcMem2;
	HBITMAP hbmMask;
	BITMAP bm;

	GetObject(hbmColour, sizeof(BITMAP), &bm);
	hbmMask = CreateBitmap(bm.bmWidth, bm.bmHeight, 1, 1, NULL);

	hdcMem = CreateCompatibleDC(0);
	hdcMem2 = CreateCompatibleDC(0);

	SelectObject(hdcMem, hbmColour);
	SelectObject(hdcMem2, hbmMask);

	SetBkColor(hdcMem, crTransparent);

	BitBlt(hdcMem2, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

	BitBlt(hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem2, 0, 0, SRCINVERT);

	DeleteDC(hdcMem);
	DeleteDC(hdcMem2);

	return hbmMask;
}

void Game::selectBitmap(uint16_t nat, bool mask)
{
	if (mask == false)
	{
		switch (nat)
		{
		case TURN_GER:
			SelectObject(hdcCompat, gerIcon);
			break;
		case TURN_SOV:
			SelectObject(hdcCompat, sovIcon);
			break;
		case TURN_JPN:
			SelectObject(hdcCompat, jpnIcon);
			break;
		case TURN_USA:
			SelectObject(hdcCompat, usaIcon);
			break;
		case TURN_CHN:
			SelectObject(hdcCompat, chnIcon);
			break;
		case TURN_UKE: case TURN_UKP:
			SelectObject(hdcCompat, ukIcon);
			break;
		case TURN_ITA:
			SelectObject(hdcCompat, itaIcon);
			break;
		case TURN_ANZ:
			SelectObject(hdcCompat, anzIcon);
			break;
		case TURN_FRA:
			SelectObject(hdcCompat, fraIcon);
			break;
		default:
			SelectObject(hdcCompat, gerIcon);
			break;
		}
	}
	else
	{
		switch (nat)
		{
		case TURN_GER:
			SelectObject(hdcCompat, gerIconMask);
			break;
		case TURN_SOV:
			SelectObject(hdcCompat, sovIconMask);
			break;
		case TURN_JPN:
			SelectObject(hdcCompat, jpnIconMask);
			break;
		case TURN_USA:
			SelectObject(hdcCompat, usaIconMask);
			break;
		case TURN_CHN:
			SelectObject(hdcCompat, chnIconMask);
			break;
		case TURN_UKE: case TURN_UKP:
			SelectObject(hdcCompat, ukIconMask);
			break;
		case TURN_ITA:
			SelectObject(hdcCompat, itaIconMask);
			break;
		case TURN_ANZ:
			SelectObject(hdcCompat, anzIconMask);
			break;
		case TURN_FRA:
			SelectObject(hdcCompat, fraIconMask);
			break;
		default:
			SelectObject(hdcCompat, gerIconMask);
			break;
		}
	}
}
