#include "../header/AATab.h"

AATab::AATab(int id)
	:AAGraphicsObject(id)
{
	tbState = TB_UP;
	isDrawn = false;

	tbText->resize(0);

	for (int i = 0; i < TB_UP_LAYERS; i++)
	{
		tbUpBox[i] = NULL;
		tbUpBorderPen[i] = NULL;
	}
	for (int i = 0; i < TB_DN_LAYERS; i++)
	{
		tbDnBox[i] = NULL;
		tbDnBorderPen[i] = NULL;
	}

	tbUpTextBox = NULL;
	tbDnTextBox = NULL;

	tbBlankBox = NULL;

	tbCenterBrush = NULL;
	clearBrush = NULL;

	tbFont = NULL;

	tbFuncId = NULL;
	hasFuncId = false;
	tbFunction0 = NULL;
}

AATab::~AATab()
{
	for (int i = 0; i < TB_UP_LAYERS; i++)
	{
		delete tbUpBox[i];
		delete tbUpBorderPen[i];
	}
	for (int i = 0; i < TB_DN_LAYERS; i++)
	{
		delete tbDnBox[i];
		delete tbDnBorderPen[i];
	}

	delete tbUpTextBox;
	delete tbDnTextBox;

	delete tbBlankBox;
}

void AATab::configTab(Graphics* graphics, int screen, RectF& rect, const char* text)
{
	configObject(graphics, screen, NULL, rect);

	for (int i = 0; i < TB_UP_LAYERS; i++)
		tbUpBox[i] = new AABox("");
	for (int i = 0; i < TB_DN_LAYERS; i++)
		tbDnBox[i] = new AABox("");

	tbUpTextBox = new AABox("Tab");
	tbDnTextBox = new AABox("Tab");

	tbBlankBox = new AABox("");

	config(text);
}

void AATab::configTab(Graphics* graphics, int screen, RectF& rect, const char* text, void (*tbFunc)(HWND&))
{
	configTab(graphics, screen, rect, text);

	tbFunction0 = tbFunc;
}

void AATab::configDrawTools(vector<Color*>& cGray, vector<SolidBrush*>& bGray, SolidBrush* b0, Font* f0)
{
	tbCenterBrush = bGray[240];

	tbUpBorderPen[0] = new Pen(bGray[100], 1);
	tbUpBorderPen[1] = new Pen(bGray[105], 1);
	tbUpBorderPen[2] = new Pen(bGray[255], 1);
	tbUpBorderPen[3] = new Pen(bGray[160], 1);
	tbUpBorderPen[4] = new Pen(bGray[227], 1);

	tbDnBorderPen[0] = new Pen(bGray[100], 1);
	tbDnBorderPen[1] = new Pen(bGray[160], 1);

	clearBrush = b0;

	tbFont = f0;
}

void AATab::setTabFuncId(int val)
{
	tbFuncId = val;
	hasFuncId = true;
}

void AATab::drawTab(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	drawObject(graphics, dbg_boundbox, dbg_sections, layers);

	if (dbg_sections) // Show box names
	{
		tbBlankBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, layers);
	}
	else // Actual graphics
	{
		if (!isDrawn)
		{
			if (tbState == TB_UP)
			{
				tbUpBox[0]->drawFrame(graphics, tbUpBorderPen[0], baseTextFont, centerFormat, textBrush, layers);
				tbUpBox[1]->drawFrame(graphics, tbUpBorderPen[1], baseTextFont, centerFormat, textBrush, layers);
				tbUpBox[2]->drawFrame(graphics, tbUpBorderPen[2], baseTextFont, centerFormat, textBrush, layers);
				tbUpBox[3]->drawFrame(graphics, tbUpBorderPen[3], baseTextFont, centerFormat, textBrush, layers);
				tbUpBox[4]->drawFrame(graphics, tbUpBorderPen[4], baseTextFont, centerFormat, textBrush, layers);

				tbUpTextBox->drawBox(graphics, borderlessPen, tbFont, centerFormat, textBrush, tbCenterBrush, objText, layers);
			}
			else if (tbState == TB_DN)
			{
				tbDnBox[0]->drawFrame(graphics, tbDnBorderPen[0], baseTextFont, centerFormat, textBrush, layers);
				tbDnBox[1]->drawFrame(graphics, tbDnBorderPen[1], baseTextFont, centerFormat, textBrush, layers);

				tbDnTextBox->drawBox(graphics, borderlessPen, tbFont, centerFormat, textBrush, tbCenterBrush, objText, layers);
			}

			isDrawn = true;
		}
	}
}

void AATab::hideTab(Graphics* graphics)
{
	isDrawn = false;
	tbBlankBox->drawBox(graphics, borderlessPen, baseTextFont, centerFormat, textBrush, backBrush, L"", 99);
}

bool AATab::pressTab(HWND hWnd)
{
	if (tbState == TB_UP)
	{
		tbState = TB_DN;
		isDrawn = false;
		executeTab(hWnd);
		return true;
	}
	else
		return false;
}

bool AATab::releaseTab()
{
	if (tbState == TB_DN)
	{
		tbState = TB_UP;
		isDrawn = false;
		return true;
	}
	else
		return false;
}

void AATab::executeTab(HWND hWnd)
{
	if (!hasFuncId)
		tbFunction0(hWnd);
}

int AATab::getTabId()
{
	return getObjectId();
}

void AATab::config(const char* text)
{
	for (int i = 0; i < GRAPHICS_TEXTLEN; i++)
	{
		objText[i] = text[i];
		if (text[i] == '\0')
			break;
	}

	tbBlankBox->config(objBox, 99);

	// Up state graphics
	tbUpBox[0]->config(objBox, 99);
	tbUpBox[1]->config(objBox, 99);
	tbUpBox[1]->shrink(1);
	tbUpBox[2]->config(objBox, 99);
	tbUpBox[2]->shrink(1);
	tbUpBox[2]->contract(1);
	tbUpBox[3]->config(objBox, 99);
	tbUpBox[3]->shrink(2);
	tbUpBox[4]->config(objBox, 99);
	tbUpBox[4]->shrink(2);
	tbUpBox[4]->contract(1);

	tbUpTextBox->config(objBox, 99);
	tbUpTextBox->shrink(3);
	tbUpTextBox->contract(0, -2);
	tbUpTextBox->nudge(0, -1);

	// Down state graphics
	tbDnBox[0]->config(objBox, 99);
	tbDnBox[1]->config(objBox, 99);
	tbDnBox[1]->shrink(1);

	tbDnTextBox->config(objBox, 99);
	tbDnTextBox->shrink(2);

}
