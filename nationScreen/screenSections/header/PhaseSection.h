#ifndef PHASE_SECTION
#define PHASE_SECTION

#include "../../../graphics/header/Section.h"

class PhaseSection : public Section
{
public:
	PhaseSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~PhaseSection();

	void configurePhaseBox(RectF&, int);
	void configDrawTools(Font*);
	void configBrushes0(SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*);
	void configBrushes1(SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*, SolidBrush*);

	void drawPhaseBox(Graphics*, int, bool, bool, bool, int);

	REAL getBoxEdge(int, int);

private:

	// Section frame
	AABox* phaseFrame;

	// Section boxes
	AABox* resBox;
	AABox* purchBox;
	AABox* cmBox;
	AABox* ccBox;
	AABox* ncBox;
	AABox* mobBox;
	AABox* incBox;

	// Section variables

	// Unique graphics
	Font* phaseFont;

	SolidBrush* resBrushP, * purchBrushP, * cmBrushP,
		* ccBrushP, * ncBrushP, * mobBrushP, * incBrushP;
	SolidBrush* resBrushS, * purchBrushS, * cmBrushS,
		* ccBrushS, * ncBrushS, * mobBrushS, * incBrushS;

};

#endif
