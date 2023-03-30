#include "../header/AAButton.h"

AAButton::AAButton(int id)
	:AAGraphicsObject(id)
{
	bbState = BB_UP;
	isDrawn = false;

	for (int i = 0; i < BB_UP_LAYERS; i++)
	{
		bbUpBox[i] = NULL;
		bbUpBorderPen[i] = NULL;
	}
	for (int i = 0; i < BB_DN_LAYERS; i++)
	{
		bbDnBox[i] = NULL;
		bbDnBorderPen[i] = NULL;
	}

	bbUpTextBox = NULL;
	bbDnTextBox = NULL;

	bbBlankBox = NULL;

	bbCenterBrush = NULL;
	clearBrush = NULL;

	bbFont = NULL;

	bbFuncId = NULL;
	hasFuncId = false;
	bbFunction0 = NULL;
	bbFunction1 = NULL;
}

AAButton::~AAButton()
{
	for (int i = 0; i < BB_UP_LAYERS; i++)
	{
		delete bbUpBox[i];
		delete bbUpBorderPen[i];
	}
	for (int i = 0; i < BB_DN_LAYERS; i++)
	{
		delete bbDnBox[i];
		delete bbDnBorderPen[i];
	}

	delete bbUpTextBox;
	delete bbDnTextBox;

	delete bbBlankBox;
}

void AAButton::configButton(Graphics* graphics, int screen, RectF& rect, const char* text, framesList* frames)
{
	configObject(graphics, screen, rect, text, frames);

	for (int i = 0; i < BB_UP_LAYERS; i++)
		bbUpBox[i] = new AABox("");
	for (int i = 0; i < BB_DN_LAYERS; i++)
		bbDnBox[i] = new AABox("");

	bbUpTextBox = new AABox("Button");
	bbDnTextBox = new AABox("Button");

	bbBlankBox = new AABox("");

	config(text, frames);
}

void AAButton::configButton(Graphics* graphics, int screen, RectF& rect, const char* text, framesList* frames, void (*bbFunc)(HWND&))
{
	configObject(graphics, screen, rect, text, frames);

	configButton(graphics, screen, rect, text, frames);

	bbFunction0 = bbFunc;
}

void AAButton::configButton(Graphics* graphics, int screen, RectF& rect, const char* text, framesList* frames, void (*bbFunc)(HWND&, int))
{
	configObject(graphics, screen, rect, text, frames);

	configButton(graphics, screen, rect, text, frames);

	bbFunction1 = bbFunc;
}

void AAButton::configDrawTools(vector<Color*>& cGray, vector<SolidBrush*>& bGray, SolidBrush* b0, Font* f0)
{
	bbCenterBrush = bGray[240];

	bbUpBorderPen[0] = new Pen(bGray[100], 1);
	bbUpBorderPen[1] = new Pen(bGray[105], 1);
	bbUpBorderPen[2] = new Pen(bGray[255], 1);
	bbUpBorderPen[3] = new Pen(bGray[160], 1);
	bbUpBorderPen[4] = new Pen(bGray[227], 1);

	bbDnBorderPen[0] = new Pen(bGray[100], 1);
	bbDnBorderPen[1] = new Pen(bGray[160], 1);

	clearBrush = b0;

	bbFont = f0;
}

void AAButton::setButtonFuncId(int val)
{
	bbFuncId = val;
	hasFuncId = true;
}

void AAButton::drawButton(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	drawObject(graphics, dbg_boundbox, dbg_sections, layers);

	if (dbg_sections) // Show box names
	{
		bbBlankBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, layers);
	}
	else // Actual graphics
	{
		if (!isDrawn)
		{
			if (bbState == BB_UP)
			{
				bbUpBox[0]->drawFrame(graphics, bbUpBorderPen[0], baseTextFont, centerFormat, textBrush, layers);
				bbUpBox[1]->drawFrame(graphics, bbUpBorderPen[1], baseTextFont, centerFormat, textBrush, layers);
				bbUpBox[2]->drawFrame(graphics, bbUpBorderPen[2], baseTextFont, centerFormat, textBrush, layers);
				bbUpBox[3]->drawFrame(graphics, bbUpBorderPen[3], baseTextFont, centerFormat, textBrush, layers);
				bbUpBox[4]->drawFrame(graphics, bbUpBorderPen[4], baseTextFont, centerFormat, textBrush, layers);

				bbUpTextBox->drawBox(graphics, borderlessPen, bbFont, centerFormat, textBrush, bbCenterBrush, objText, layers);
			}
			else if (bbState == BB_DN)
			{
				bbDnBox[0]->drawFrame(graphics, bbDnBorderPen[0], baseTextFont, centerFormat, textBrush, layers);
				bbDnBox[1]->drawFrame(graphics, bbDnBorderPen[1], baseTextFont, centerFormat, textBrush, layers);

				bbDnTextBox->drawBox(graphics, borderlessPen, bbFont, centerFormat, textBrush, bbCenterBrush, objText, layers);
			}

			isDrawn = true;
		}
	}
}

void AAButton::hideButton(Graphics* graphics)
{
	isDrawn = false;
	bbBlankBox->drawBox(graphics, borderlessPen, baseTextFont, centerFormat, textBrush, backBrush, L"", 99);
}

bool AAButton::pressButton()
{
	if (bbState == BB_UP)
	{
		bbState = BB_DN;
		isDrawn = false;
		return true;
	}
	else
		return false;
}

bool AAButton::releaseButton()
{
	if (bbState == BB_DN)
	{
		bbState = BB_UP;
		isDrawn = false;
		return true;
	}
	else
		return false;
}

void AAButton::executeButton(HWND hWnd)
{
	if (!hasFuncId)
		bbFunction0(hWnd);
	else
		bbFunction1(hWnd, bbFuncId);
}

void AAButton::executeButton(HWND hWnd, int val)
{
	bbFunction1(hWnd, val);
}

int AAButton::getButtonId()
{
	return getObjectId();
}

void AAButton::config(const char* text, framesList* frames)
{
	for (int i = 0; i < GRAPHICS_TEXTLEN; i++)
	{
		objText[i] = text[i];
		if (text[i] == '\0')
			break;
	}

	// Determine which frames the tooltip intersects with
	for (int i = 0; i < frames->s[objScr].f.size(); i++)
	{
		if (objBox.IntersectsWith(frames->s[objScr].f[i]))
		{
			intersections |= frames->s[objScr].b[i];
		}
	}

	bbBlankBox->config(objBox, 99);

	// Up state graphics
	bbUpBox[0]->config(objBox, 99);
	bbUpBox[1]->config(objBox, 99);
	bbUpBox[1]->shrink(1);
	bbUpBox[2]->config(objBox, 99);
	bbUpBox[2]->shrink(1);
	bbUpBox[2]->contract(1);
	bbUpBox[3]->config(objBox, 99);
	bbUpBox[3]->shrink(2);
	bbUpBox[4]->config(objBox, 99);
	bbUpBox[4]->shrink(2);
	bbUpBox[4]->contract(1);

	bbUpTextBox->config(objBox, 99);
	bbUpTextBox->shrink(3);
	bbUpTextBox->contract(0, -2);
	bbUpTextBox->nudge(0, -1);

	// Down state graphics
	bbDnBox[0]->config(objBox, 99);
	bbDnBox[1]->config(objBox, 99);
	bbDnBox[1]->shrink(1);

	bbDnTextBox->config(objBox, 99);
	bbDnTextBox->shrink(2);

}