#ifndef LOG_CLASS
#define LOG_CLASS

#include "../../game/header/framework.h"
#include "../../game/header/Resource.h"
#include "LogPair.h"
#include "../../graphics/header/GraphicsHeader.h"

#define LOG_ROWS      25
#define LOG_COLS       2

struct idxLog {
	int page;
	int col;
	int row;
};

class Log
{
public:
	Log(int, RECT);
	~Log();

	void addLogText(int, int, int, int, int = TURN_GER, int = TURN_GER);
	void addLogText(int, vector<int>&, int);
	void addLogText(uint16_t, WCHAR*);
	void drawPage(HDC, uint16_t);

	void addCol();

	void setCurrPage(int);
	void setCurrCol(int);
	void setCurrRow(int);
	void setCurrTurn(int);
	void setCurrNat(int);
	void setTrgtEx(bool);
	void setTrgtPos(int, int, int);
	void setResEx(bool);
	void setResPos(int, int, int);
	void setOccEx(bool);
	void setOccPos(int, int, int);
	void setCapEx(int, bool);
	void setCapPos(int, int, int, int);
	void setLibEx(int, int, bool);
	void setLibPos(int, int, int, int, int);
	void setRecEx(int, bool);
	void setRecPos(int, int, int, int);
	void setTurn(int, int, int, int);
	void setVerb(int, int, int, int);
	void setSubj(int, int, int, int);
	void setTrgt(int, int, int, int);
	void setObjt(int, int, int, int);
	void setIndr(int, int, int, int);
	void setCust(int, int, int, int, char);
	void reconstructText(int, int, int);

	int  getCurrPage();
	int  getCurrCol();
	int  getCurrRow();
	int  getCurrTurn();
	int  getCurrNat();
	bool getTrgtEx();
	void getTrgtPos(int&, int&, int&);
	bool getResEx();
	void getResPos(int&, int&, int&);
	bool getOccEx();
	void getOccPos(int&, int&, int&);
	bool getCapEx(int);
	void getCapPos(int, int&, int&, int&);
	bool getLibEx(int, int);
	void getLibPos(int, int, int&, int&, int&);
	bool getRecEx(int);
	void getRecPos(int, int&, int&, int&);
	int  getTurn(int, int, int);
	int  getVerb(int, int, int);
	int  getSubj(int, int, int);
	int  getTrgtSize(int, int, int);
	int  getTrgt(int, int, int, int);
	int  getObjt(int, int, int);
	int  getIndr(int, int, int);
	char getCust(int, int, int, int);

	void adjustLog(int, int, vector<int>&);
	void adjustLogAllies(int, vector<vector<int>>&);

	int  getNewPage();

private:

	RECT pane;
	
	vector<vector<vector<LogPair*>>> logBox;

	int currPage;
	int currCol;
	int currRow;

	int currTurn, currNat;
	bool tgtEx, capEx[10], occEx, libEx[10][10], recEx[10], resEx;
	idxLog tgtPos, capPos[10], occPos, libPos[10][10], recPos[10], resPos;

	bool newPage;

	bool globalGame;

	void configDrawTools();
	void incCell();
	void decCell();

	void shiftCells(int, int, int, int, int, int);
	void shiftCellsBack(int, int, int);

	bool isInList(vector<int>, int);
	bool allInList(vector<int>, int, int, int);
	bool anyInList(vector<int>, int, int, int);

	void removeFromList(vector<int>&, int);
	void removeFromList(vector<int>&, int, int, int);

	FontFamily* fontFamily;
	Font* turnFont, *textFont, *boldFont;
	StringFormat turnFormat, textFormat;
	SolidBrush* textBrush;
	SolidBrush* paneBrush, *backBrush;

	Pen* linePen;

};

#endif
