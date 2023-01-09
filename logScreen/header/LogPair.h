#ifndef LOG_PAIR
#define LOG_PAIR

#include "../../game/header/framework.h"
#include "../../game/header/Resource.h"
#include "../../board/header/Territories.h"
#include "../../graphics/header/GraphicsHeader.h"

#define TEXTLEN      240
#define YOFFSET      50
#define CELLHEIGHT   29
#define TURNWIDTH    75
#define TEXTWIDTH    650

// Verbs
#define V_BLANK         -1
#define V_SETUP          0
#define V_WAR            1
#define V_CAPTURE        2
#define V_LIBERATE       3
#define V_RECLAIM        4
#define V_OCCUPY         5
#define V_RESEARCH       6
#define V_NEUTRAL        7
#define V_NEUTRAL_AXIS   8
#define V_NEUTRAL_ALLY   9
#define V_MONGOLIA      10
#define V_CUSTOM        11

// Text box adjustment codes
#define C_NONE      -1
#define C_WAR_SUBJ   0
#define C_WAR_VERB   1
#define C_WAR_TRGT   2
#define C_WAR_AND_   3
#define C_WAR_AND__  4
#define C_WAR_AND    5
#define C_CAP_SUBJ   6
#define C_CAP_VERB   7
#define C_CAP_TRGT   8
#define C_CAP_AND    9
#define C_CAP_FROM   10
#define C_CAP_OBJT   11
#define C_LIB_SUBJ   12
#define C_LIB_FROM   13
#define C_LIB_OBJT   14
#define C_LIB_INDR   15
#define C_REC_SUBJ   16
#define C_REC_FROM   17
#define C_REC_OBJT   18
#define C_OCC_SUBJ   19

class LogPair
{
public:
	LogPair(int, int, bool);
	~LogPair();

	void drawPair(Graphics&, Pen*, Font*, Font*, Font*, StringFormat*, StringFormat*, SolidBrush*);

	void setText(int, int);
	void setText(uint16_t, int, int = TURN_GER, vector<int>* = nullptr, int = TURN_GER);
	bool setText(uint16_t, int, int = TURN_GER, int = TER_ALBERTA, int = TURN_GER, int = TURN_GER, bool = true);
	void setText(uint16_t, WCHAR*);

	void cpy(LogPair *);

	void setTurn(int);
	void setVerb(int);
	void setSubj(int);
	void setTrgt(int);
	void setObjt(int);
	void setIndr(int);
	void setCust(int, char);
	void reconstructText();

	int  getTurn();
	int  getVerb();
	int  getSubj();
	int  getTrgtSize();
	int  getTrgt(int);
	int  getObjt();
	int  getIndr();
	char getCust(int);

	bool getHasSubj();
	bool getHasObjt();

	bool hasTrgt(int);
	void removeTrgt(int);

	bool isSpace(int, int);
	void clear();
	void clear_text();

private:
	RectF* turnPos;
	WCHAR turn[10];
	RectF* textPos;
	WCHAR text[TEXTLEN];
	int text_len;

	int         _turn;
	int         _verb;
	int         _subj;
	vector<int> _trgt;
	int         _objt;
	int         _indr;

	bool        _set;

	void setTurn();

	RectF* textBox0;
	RectF* textBox1;

	SolidBrush* gerBrushP, * sovBrushP, * jpnBrushP,
		* usaBrushP, * chnBrushP, * ukBrushP,
		* itaBrushP, * anzBrushP, * fraBrushP;

	SolidBrush* setBrushColor(int, SolidBrush*);
	void adjustBounds(RectF*, RectF*, int = -1, int = -1);
	void roundBounds(RectF*);

	bool globalGame;
	int text_pos;
	int getAdjNatLen(int, bool = false);
	void addText(Graphics&, const WCHAR*, int, Font*, RectF&, RectF*, StringFormat*, SolidBrush*, bool = false, int = C_NONE, int = TURN_NON);
	bool isSpaceOnLine(Graphics&, const WCHAR*, int, Font*, RectF&, RectF*);

};

#endif
