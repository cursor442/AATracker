
#include "SpreadsheetClass.h"

Spreadsheet::Spreadsheet(int initSize)
{
	spreadText.resize(initSize);
	
	for (int i = 0; i < initSize; i++) // Initialize positions of spreadsheet to blanks
		for (int j = 0; j < XPNS_POS; j++)
			spreadText[i].text[j][0] = '\0';

	miniIdx = 1;
	spreadPtr = 1;
	for (int i = 0; i < SPREAD_ROWS; i++)
		for (int j = 0; j < XPNS_POS; j++)
			miniText[i].text[j][0] = '\0';
}

Spreadsheet::~Spreadsheet()
{

}

void Spreadsheet::setSpreadText(int turn, int bank, int incm, int bons, int pnlt, int xpns)
{
	if (turn == spreadText.size()) // Program should crash if it tries to increase turns by more than one at a time
	{
		spreadText.resize(spreadText.size() + 1);
		scrollMiniSpread();
	}

	setSpreadText(turn, BANK_POS, bank);
	setSpreadText(turn, INCM_POS, incm);
	setSpreadText(turn, BONS_POS, bons);
	setSpreadText(turn, PNLT_POS, pnlt);
	setSpreadText(turn, XPNS_POS, xpns);
}

void Spreadsheet::setSpreadText(int turn, int col, int val)
{
	col -= BANK_POS;

	if (turn < spreadText.size())
	{
		if (val > 999)
		{
			spreadText[turn].text[col][0] = uint2char_(val / 1000);
			spreadText[turn].text[col][1] = uint2char_((val % 1000) / 100);
			spreadText[turn].text[col][2] = uint2char_((val % 100) / 10);
			spreadText[turn].text[col][3] = uint2char_(val % 10);
			spreadText[turn].text[col][4] = '\0';
		}
		else if (val > 99)
		{
			spreadText[turn].text[col][0] = uint2char_(val / 100);
			spreadText[turn].text[col][1] = uint2char_((val % 100) / 10);
			spreadText[turn].text[col][2] = uint2char_(val % 10);
			spreadText[turn].text[col][3] = '\0';
		}
		else if (val > 9)
		{
			spreadText[turn].text[col][0] = uint2char_(val / 10);
			spreadText[turn].text[col][1] = uint2char_(val % 10);
			spreadText[turn].text[col][2] = '\0';
		}
		else if (val >= 0)
		{
			spreadText[turn].text[col][0] = uint2char_(val);
			spreadText[turn].text[col][1] = '\0';
		}
		else
		{
			spreadText[turn].text[col][0] = '\0';
		}
	}	

	if (turn >= miniIdx && turn < (miniIdx + SPREAD_ROWS))
	{
		int adjTurn = turn - miniIdx;
		wcsncpy_s(miniText[adjTurn].text[col], spreadText[turn].text[col], SPREAD_TEXTLEN);
	}
}

void Spreadsheet::setSpreadSize(int size)
{
	spreadText.resize(size);
}

void Spreadsheet::incSpreadSize()
{
	spreadText.resize(spreadText.size() + 1);
}

WCHAR* Spreadsheet::getSpreadText(int row, int col)
{
	if (row < spreadText.size())
		return spreadText[row].text[col];
	else
	{
		WCHAR tmp[2] = L"\0";
		return tmp;
	}
}

WCHAR* Spreadsheet::getMiniSpreadText(int row, int col)
{
	if (row < SPREAD_ROWS)
		return miniText[row].text[col];
	else
	{
		WCHAR tmp[2] = L"\0";
		return tmp;
	}
}

int Spreadsheet::getMiniIndex()
{
	return miniIdx;
}

int Spreadsheet::getSpreadSize()
{
	return spreadText.size();
}

void Spreadsheet::scrollMiniSpread()
{
	if (spreadPtr < (SPREAD_ROWS - 1))
	{
		spreadPtr++;// No need to scroll
	}
	else // Need to free up bottom row
	{
		for (int i = 0; i < (SPREAD_ROWS - 1); i++)
			for (int j = 0; j < SPREAD_COLS; j++)
				wcsncpy_s(miniText[i].text[j], miniText[i + 1].text[j], SPREAD_TEXTLEN);

		miniIdx++;
		spreadPtr++;
	}
}
