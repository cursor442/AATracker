#include "../header/StatusSection.h"

StatusSection::StatusSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	statusFrame = new AABox("Status Section");

	axisBox = new AABox("Axis");
	alliesBox = new AABox("Allies");

	wcsncpy_s(axis, L"Axis control   /  cities and  /  of their own capitals.", ARRAYSIZE(axis));
	wcsncpy_s(axisG, L"Axis control   /8 cities in Europe,  /6 cities in the Pacific,\n\tand  /3 of their own capitals.", ARRAYSIZE(axisG));
	wcsncpy_s(allies, L"Allies control  /  Axis capitals and  /  of their own.", ARRAYSIZE(allies));

	statusFormat = NULL;
	statusFont = NULL;
}

StatusSection::~StatusSection()
{
	delete statusFrame;
}

void StatusSection::configureStatusBox(RectF& frame, int layer)
{
	statusFrame->config(frame, layer);

	axisBox->config(statusFrame->box, layer + 1);
	axisBox->box.Height = 2 * frame.Height / 3;

	alliesBox->config(statusFrame->box, layer + 1);
	alliesBox->box.Y = axisBox->box.GetBottom();
	alliesBox->box.Height = frame.GetBottom() - alliesBox->box.Y;

}

void StatusSection::configDrawTools(StringFormat* sf0,Font* f0)
{
	statusFormat = sf0;

	statusFont = f0;
}

void StatusSection::updateStatusText(int axisCap, int axisEur, int axisPac, int allyCap, int gameType)
{
	if (gameType == GLOBAL_GAME)
	{
		if (axisEur > 9)
		{
			axisG[13] = int2char_(axisEur / 10);
			axisG[14] = int2char_(axisEur % 10);
		}
		else
		{
			axisG[13] = ' ';
			axisG[14] = int2char_(axisEur);
		}
		axisG[36] = int2char_(axisPac);
		axisG[68] = int2char_(axisCap);
		allies[15] = int2char_(3 - axisCap);
		allies[17] = '3';
		allies[39] = '4';
	}
	else if (gameType == EUROPE_GAME)
	{
		if (axisEur > 9)
		{
			axis[13] = int2char_(axisEur / 10);
			axis[14] = int2char_(axisEur % 10);
		}
		else
		{
			axisG[13] = ' ';
			axis[14] = int2char_(axisEur);
		}
		axis[16] = '8';
		axis[29] = int2char_(axisCap);
		axis[31] = '2';
		allies[15] = int2char_(2 - axisCap);
		allies[17] = '2';
		allies[39] = '4';
	}
	else if (gameType == PACIFIC_GAME)
	{
		axis[14] = int2char_(axisPac);
		axis[16] = '6';
		axis[29] = int2char_(axisCap);
		axis[31] = '1';
		allies[15] = int2char_(1 - axisCap);
		allies[17] = '1';
		allies[39] = '3';
	}

	allies[37] = int2char_(allyCap);
}

void StatusSection::drawStatusBox(Graphics* graphics, int gameType, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		statusFrame->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		axisBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		alliesBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		
	}
	else // Actual graphics
	{
		if (gameType == GLOBAL_GAME)
			axisBox->drawBox(graphics, pen, statusFont, statusFormat, textBrush, backBrush, axisG, layers);
		else
			axisBox->drawBox(graphics, pen, statusFont, statusFormat, textBrush, backBrush, axis, layers);
		alliesBox->drawBox(graphics, pen, statusFont, statusFormat, textBrush, backBrush, allies, layers);
	}
}
