#include "../header/LogSection.h"

LogSection::LogSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	logFrame = new AABox("Log Section");

	currLogPage = 0;
	logCol = 0;

	logData = NULL;
}

LogSection::~LogSection()
{
	
}

void LogSection::configureLogBox(RectF& frame, int layer, int col, Log* data)
{
	logFrame->config(frame, layer);

	logCol = col;

	logData = data;
}

void LogSection::configDrawTools()
{
	
}

void LogSection::drawLogBox(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		logFrame->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);
	}
	else // Actual graphics
	{

	}
}


