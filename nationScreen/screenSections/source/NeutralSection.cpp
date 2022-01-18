#include "../header/NeutralSection.h"

NeutralSection::NeutralSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	neutralFrame = new AABox("Neutrals Section");

	neutralStatusBox = new AABox("Status");

	for (int i = 0; i < NEUTRAL_COLS; i++)
		for (int j = 0; j < NEUTRAL_ROWS; j++)
			neutralBox[i][j] = new AABox("Neutral");

	WCHAR stat[] = L"Neutral territories are Neutral";

	wcsncpy_s(neutralStatusText, stat, ARRAYSIZE(stat));

}

NeutralSection::~NeutralSection()
{
	delete neutralFrame;

	delete neutralStatusBox;

	for (int i = 0; i < NEUTRAL_COLS; i++)
		for (int j = 0; j < NEUTRAL_ROWS; j++)
			delete neutralBox;
}

void NeutralSection::configureNeutralBox(RectF& frame, int layer)
{
	neutralFrame->config(frame, layer);

	neutralStatusBox->config(neutralFrame->box, layer + 1);
	neutralStatusBox->box.Width = neutralFrame->box.Width / NEUTRAL_COLS;
	neutralStatusBox->box.Height = neutralFrame->box.Height / NEUTRAL_ROWS;
	
	neutralBox[0][0]->config(neutralStatusBox->box, layer + 1);

	for (int i = 1; i < NEUTRAL_COLS; i++)
	{
		neutralBox[i][0]->config(neutralBox[i - 1][0]->box, layer + 1);
		neutralBox[i][0]->box.X = neutralBox[i - 1][0]->box.GetRight();
	}
	neutralBox[NEUTRAL_COLS - 1][0]->box.Width = frame.GetRight() - neutralBox[NEUTRAL_COLS - 1][0]->box.X;

	for (int i = 0; i < NEUTRAL_COLS; i++)
	{
		for (int j = 1; j < NEUTRAL_ROWS; j++)
		{
			neutralBox[i][j]->config(neutralBox[i][j - 1]->box, layer + 1);
			neutralBox[i][j]->box.Y = neutralBox[i][j - 1]->box.GetBottom();
		}

		neutralBox[i][NEUTRAL_ROWS - 1]->box.Height = frame.GetBottom() - neutralBox[i][NEUTRAL_ROWS - 1]->box.Y;
	}
}

void NeutralSection::configDrawTools()
{
	
}

void NeutralSection::drawNeutralBox(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		neutralFrame->drawFrame(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		neutralStatusBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		for (int i = 0; i < NEUTRAL_COLS; i++)
			for (int j = 0; j < NEUTRAL_ROWS; j++)
				if (!(i == 0 && j == 0))
					neutralBox[i][j]->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
	}
	else // Actual graphics
	{
		neutralStatusBox->drawBox(graphics, pen, baseTextFont, textFormat, textBrush, backBrush, neutralStatusText, layers);

		for (int i = 0; i < NEUTRAL_COLS; i++)
			for (int j = 0; j < NEUTRAL_ROWS; j++)
				if (!(i == 0 && j == 0))
					neutralBox[i][j]->drawBox(graphics, pen, baseTextFont, textFormat, textBrush, backBrush, L"", layers);
	}
}