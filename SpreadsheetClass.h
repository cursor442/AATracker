#ifndef SPREADSHEET_CLASS
#define SPREADSHEET_CLASS

#include "Resource.h"

struct spreadLine {
	WCHAR text[XPNS_POS][SPREAD_TEXTLEN];
};

class Spreadsheet
{
public:
	Spreadsheet(int);
	~Spreadsheet();

	void setSpreadText(int, int, int, int, int, int);
	void setSpreadText(int, int, int);

	void setSpreadSize(int);
	void incSpreadSize();

	WCHAR* getSpreadText(int, int);
	WCHAR* getMiniSpreadText(int, int);

	int getMiniIndex();
	int getSpreadSize();

private:
	void scrollMiniSpread();

	vector<spreadLine> spreadText;
	spreadLine miniText[SPREAD_ROWS];
	int spreadPtr;
	int miniIdx;
};

#endif
