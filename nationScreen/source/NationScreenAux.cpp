#include "../../game/header/AA_Tracker.h"

void Game::valConv(HDC& hdc, RECT& box, uint16_t val)
{
	char str[4];
	str[3] = '\0';

	str[0] = ' ';
	str[1] = ' ';
	if (val > 99)
	{
		str[0] = uint2char_(val / 100);
		str[1] = '0';
	}
	if (val > 9)
		str[1] = uint2char_((val % 100) / 10);
	str[2] = uint2char_(val % 10);

	DrawTextA(hdc, str, -1, &box, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}

void Game::ukConv(HDC& hdc, RECT& box, uint16_t valE, uint16_t valP)
{
	char str[8];
	str[3] = '/';
	str[7] = '\0';

	str[0] = ' ';
	str[1] = ' ';
	if (valE > 99)
	{
		str[0] = uint2char_(valE / 100);
		str[1] = '0';
	}
	if (valE > 9)
		str[1] = uint2char_((valE % 100) / 10);
	str[2] = uint2char_(valE % 10);

	str[4] = ' ';
	str[5] = ' ';
	if (valP > 99)
	{
		str[4] = uint2char_(valP / 100);
		str[5] = '0';
	}
	if (valP > 9)
		str[5] = uint2char_((valP % 100) / 10);
	str[6] = uint2char_(valP % 10);

	DrawTextA(hdc, str, -1, &box, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}

void Game::purchConv(HDC& hdc, RECT& box, uint16_t val)
{
	if (val > 9)
	{
		char str[3];
		str[2] = '\0';

		str[0] = uint2char_((val % 100) / 10);
		str[1] = uint2char_(val % 10);

		DrawTextA(hdc, str, -1, &box, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
	else
	{
		char str[2];
		str[1] = '\0';

		str[0] = uint2char_(val % 10);

		DrawTextA(hdc, str, -1, &box, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
}

void Game::bonusConv(HDC& hdc, RECT& box, uint16_t val)
{
	char str[6] = "  Met";
	str[5] = '\0';

	str[0] = uint2char_(val);

	DrawTextA(hdc, str, -1, &box, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}

void Game::swapBrush(HDC& hdc)
{
    if (currBrush) // Primary brush
        hBrush = (HBRUSH)SelectObject(hdc, hBrushS);
    else
        hBrush = (HBRUSH)SelectObject(hdc, hBrushP);

    currBrush = !currBrush;
}

void Game::resetBrush(HDC& hdc)
{
    hBrush = (HBRUSH)SelectObject(hdc, hBrushP);
    currBrush = true;
}

int Game::getCityOwn(int city, bool& sameSide)
{
	int ter = TER_NONE;
	switch (city)
	{
	case CITY_BERLIN:
		ter = TER_GERMANY;
		break;
	case CITY_MOSCOW:
		ter = TER_RUSSIA;
		break;
	case CITY_TOKYO:
		ter = TER_JAPAN;
		break;
	case CITY_WASH:
		ter = TER_EASTERN_USA;
		break;
	case CITY_SANFRAN:
		ter = TER_WESTERN_USA;
		break;
	case CITY_LONDON:
		ter = TER_UTD_KINGDOM;
		break;
	case CITY_CALC:
		ter = TER_INDIA;
		break;
	case CITY_ROME:
		ter = TER_SOUTH_ITALY;
		break;
	case CITY_SYDNEY:
		ter = TER_NEW_S_WALES;
		break;
	case CITY_PARIS:
		ter = TER_FRANCE;
		break;
	case CITY_OTTAWA:
		ter = TER_ONTARIO;
		break;
	case CITY_WARSAW:
		ter = TER_POLAND;
		break;
	case CITY_LENIN:
		ter = TER_NOVGOROD;
		break;
	case CITY_STALIN:
		ter = TER_VOLGOGRAD;
		break;
	case CITY_CAIRO:
		ter = TER_EGYPT;
		break;
	case CITY_SHANG:
		ter = TER_KIANGSU;
		break;
	case CITY_HONG:
		ter = TER_KWANGTUNG;
		break;
	case CITY_MANILA:
		ter = TER_PHILIPPINES;
		break;
	case CITY_HONO:
		ter = TER_HAWAII;
		break;
	default: break;
	}

	int own = gameBoard->getTerritoryOwner(ter);
	int side = whichSide(own);
	int currSide = whichSide(gameBoard->getGameCurrNation());

	sameSide = (side == currSide);
	return own;
}

int Game::getTerCity(int ter)
{
	int city = CITY_NONE;

	switch (ter)
	{
	case TER_GERMANY:
		city = CITY_BERLIN;
		break;
	case TER_RUSSIA:
		city = CITY_MOSCOW;
		break;
	case TER_JAPAN:
		city = CITY_TOKYO;
		break;
	case TER_EASTERN_USA:
		city = CITY_WASH;
		break;
	case TER_WESTERN_USA:
		city = CITY_SANFRAN;
		break;
	case TER_UTD_KINGDOM:
		city = CITY_LONDON;
		break;
	case TER_INDIA:
		city = CITY_CALC;
		break;
	case TER_SOUTH_ITALY:
		city = CITY_ROME;
		break;
	case TER_NEW_S_WALES:
		city = CITY_SYDNEY;
		break;
	case TER_FRANCE:
		city = CITY_PARIS;
		break;
	case TER_ONTARIO:
		city = CITY_OTTAWA;
		break;
	case TER_POLAND:
		city = CITY_WARSAW;
		break;
	case TER_NOVGOROD:
		city = CITY_LENIN;
		break;
	case TER_VOLGOGRAD:
		city = CITY_STALIN;
		break;
	case TER_EGYPT:
		city = CITY_CAIRO;
		break;
	case TER_KIANGSU:
		city = CITY_SHANG;
		break;
	case TER_KWANGTUNG:
		city = CITY_HONG;
		break;
	case TER_PHILIPPINES:
		city = CITY_MANILA;
		break;
	case TER_HAWAII:
		city = CITY_HONO;
		break;
	default: break;
	}

	return city;
}
