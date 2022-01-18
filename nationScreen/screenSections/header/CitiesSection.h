#ifndef CITIES_SECTION
#define CITIES_SECTION

#include "../../../graphics/header/Section.h"

class CitiesSection : public Section
{
public:
	CitiesSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~CitiesSection();

	void configureCityBox(RectF&, RectF&, int);
	void configDrawTools(Font*, Font*, Font*, Font*, Font*);

	void updateFormat(int, int, bool);

	void drawCityBox(Graphics*, int, bool, bool, int);

private:

	// Section frame
	AABox6* cityFrame;

	//// Section boxes
	// Capital city boxes
	AABox* berlinBox, * romeBox, * washBox, 
		* londonBox, * parisBox, * moscowBox, 
		* tokyoBox, * calcBox, * sydBox;

	// City boxes
	AABox* warsawBox, * ottawaBox, * cairoBox, * leninBox, * stalinBox, 
		* shangBox, * hongBox, * manilaBox, * honoBox, * sanfranBox;

	// Unique graphics
	Font* capFont, * cityFont;
	Font* hongFont;
	Font* baseSanFranFont, *sanFranFont;

	SolidBrush* berlinBrush, * romeBrush, * washBrush,
		* londonBrush, * parisBrush, * moscowBrush,
		* tokyoBrush, * calcBrush, * sydBrush;

	SolidBrush* warsawBrush, * ottawaBrush, * cairoBrush, * leninBrush, * stalinBrush,
		* shangBrush, * hongBrush, * manilaBrush, * honoBrush, * sanfranBrush;

};

#endif
