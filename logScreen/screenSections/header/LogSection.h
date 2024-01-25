#ifndef LOG_SECTION
#define LOG_SECTION

#include "../../../graphics/header/Section.h"

#include "../../logScreen/header/LogClass.h"

class LogSection : public Section
{
public:
	LogSection(Pen*, Pen*, FontFamily*, StringFormat*, StringFormat*, Font*, Font*, SolidBrush*, SolidBrush*, SolidBrush*);
	~LogSection();

	void configureLogBox(RectF&, int, int, Log*);
	void configDrawTools();

	void drawLogBox(Graphics*, bool, bool, int);

private:

	// Section frame
	AABox* logFrame;

	// Section boxes

	// Section text

	// Section variables
	int currLogPage;
	int logCol;

	// Section pointers
	Log* logData;

	// Unique graphics

};

#endif
