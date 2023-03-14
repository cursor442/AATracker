#ifndef AA_TOOLTIP
#define AA_TOOLTIP

#define TT_RECT_TL   0
#define TT_RECT_TR   1
#define TT_RECT_BL   2
#define TT_RECT_BR   3

#define TT_DIR_NULL -1
#define TT_DIR_LEFT  0
#define TT_DIR_RIGHT 1
#define TT_DIR_UP    2
#define TT_DIR_DOWN  3

#define TT_TRI_SIZE  6

#include "AAGraphicsObject.h"

class AATooltip : public AAGraphicsObject
{
public:
	AATooltip(int);
	~AATooltip();

	void configTooltip(Graphics* graphics, int, RectF&, int, const char*, framesList*);

	void drawTooltip(Graphics*, bool, bool, int);
	void hideTooltip(Graphics*, int&);

	int getTooltipId();

private:

	int   ttDir;

	AABox* ttTextBox;
	AATri* ttTriBox;
	AABox* ttBlankBox;

	void config(Graphics*, const char*, framesList*);

};

#endif