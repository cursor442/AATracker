#include "Section.h"
#include "WarMatrix.h"
#include "LogText.h"

class WarSection : public Section
{
public:
	WarSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~WarSection();

	void configureWarBox(RectF&, int);
	void configDrawTools(SolidBrush*, Font*, Font*);

	void updateFormat(int, int, WarMatrix*);

	void drawWarBox(Graphics*, bool, bool, int);

private:

	// Section frame
	AABox* warFrame;

	AABox* warWithBox;

	// Section variables
	int  warBoxFormat;
	bool warBoxIgnoreLast;
	WCHAR name0[16];
	WCHAR name1[16];
	WCHAR name2[16];
	WCHAR name3[16];

	// Format 4
	AABox* warTopBox;
	AABox* warBotBox;

	// Format 3
	AABox* warTLBox;
	AABox* warTRBox;
	AABox* warBLBox;
	AABox* warBRBox;

	// Format 1
	AATri* warD1Tri;
	AATri* warD2Tri;
	AATri* warD3Tri;

	// Unique graphics
	SolidBrush* redBrush;

	SolidBrush* warTopBrush, * warBotBrush, 
		* warTRBrush, * warTLBrush, * warBLBrush, * warBRBrush,
		* warD1Brush, * warD2Brush, * warD3Brush;

	Font* headFont, * headFont_s;

	Font* font0, * font1, * font2, * font3;
};