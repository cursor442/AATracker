#include "../header/AATab.h"

AATab::AATab(int id)
	:AAGraphicsObject(id)
{
	tbState = TB_DN;
	isDrawn = false;

	tbText->resize(0);

	for (int i = 0; i < TB_TOP_LAYERS; i++)
	{
		tbUpTopLine[i] = NULL;
		tbDnTopLine[i] = NULL;
		tbTopPen[i] = NULL;
	}
	for (int i = 0; i < TB_BOT_LAYERS; i++)
	{
		tbUpBotLine[i] = NULL;
		tbDnBotLine[i] = NULL;
		tbBotPen[i] = NULL;
	}
	for (int i = 0; i < TB_LEFT_LAYERS; i++)
	{
		tbUpLeftLine[i] = NULL;
		tbDnLeftLine[i] = NULL;
		tbLeftPen[i] = NULL;
	}
	for (int i = 0; i < TB_RIGHT_LAYERS; i++)
	{
		tbUpRightLine[i] = NULL;
		tbDnRightLine[i] = NULL;
		tbRightPen[i] = NULL;
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
	for (int i = 0; i < TB_TOP_LAYERS; i++)
	{
		delete tbUpTopLine[i];
		delete tbDnTopLine[i];
		delete tbTopPen[i];
	}
	for (int i = 0; i < TB_BOT_LAYERS; i++)
	{
		delete tbUpBotLine[i];
		delete tbDnBotLine[i];
		delete tbBotPen[i];
	}
	for (int i = 0; i < TB_LEFT_LAYERS; i++)
	{
		delete tbUpLeftLine[i];
		delete tbDnLeftLine[i];
		delete tbLeftPen[i];
	}
	for (int i = 0; i < TB_RIGHT_LAYERS; i++)
	{
		delete tbUpRightLine[i];
		delete tbDnRightLine[i];
		delete tbRightPen[i];
	}

	delete tbUpTextBox;
	delete tbDnTextBox;

	delete tbBlankBox;
}

void AATab::configTab(Graphics* graphics, int screen, RectF& rect, const char* text)
{
	// Prevent overlap between tabs
	rect.Width -= 1;

	configObject(graphics, screen, NULL, rect);

	for (int i = 0; i < TB_TOP_LAYERS; i++)
	{
		tbUpTopLine[i] = new AALine();
		tbDnTopLine[i] = new AALine();
	}
	for (int i = 0; i < TB_BOT_LAYERS; i++)
	{
		tbUpBotLine[i] = new AALine();
		tbDnBotLine[i] = new AALine();
	}
	for (int i = 0; i < TB_LEFT_LAYERS; i++)
	{
		tbUpLeftLine[i] = new AALine();
		tbDnLeftLine[i] = new AALine();
	}
	for (int i = 0; i < TB_RIGHT_LAYERS; i++)
	{
		tbUpRightLine[i] = new AALine();
		tbDnRightLine[i] = new AALine();
	}

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

void AATab::reconfigTab(RectF& rect)
{
	// Prevent overlap between tabs
	rect.Width -= 1;
	
	setObjectBox(rect);
	configGraphics();
}

void AATab::configDrawTools(vector<Color*>& cGray, vector<SolidBrush*>& bGray, SolidBrush* b0, Font* f0)
{
	tbCenterBrush = bGray[240];

	tbTopPen[0] = new Pen(bGray[255], 1);
	tbTopPen[1] = new Pen(bGray[227], 1);
	tbTopPen[2] = new Pen(bGray[255], 1);
	tbTopPen[3] = new Pen(bGray[105], 1);
	tbTopPen[4] = new Pen(bGray[240], 1);
	tbTopPen[5] = new Pen(bGray[240], 1);
	tbTopPen[6] = new Pen(bGray[240], 1);
	tbTopPen[7] = new Pen(bGray[240], 1);

	tbBotPen[0] = new Pen(bGray[160], 1);
	tbBotPen[1] = new Pen(bGray[105], 1);

	tbLeftPen[0] = new Pen(bGray[255], 1);
	tbLeftPen[1] = new Pen(bGray[227], 1);

	tbRightPen[0] = new Pen(bGray[160], 1);
	tbRightPen[1] = new Pen(bGray[105], 1);

	clearBrush = b0;

	tbFont = f0;
}

void AATab::setTabFuncId(int val)
{
	tbFuncId = val;
	hasFuncId = true;
}

void AATab::setTabState(bool state)
{
	tbState = state;
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
				for (int i = 0; i < TB_TOP_LAYERS; i++)
					tbUpTopLine[i]->drawLine(graphics, tbTopPen[i], layers);
				
				//for (int i = 0; i < TB_BOT_LAYERS; i++)
					//tbUpBotLine[i]->drawLine(graphics, tbBotPen[i], layers);
				
				for (int i = 0; i < TB_LEFT_LAYERS; i++)
					tbUpLeftLine[i]->drawLine(graphics, tbLeftPen[i], layers);
				
				for (int i = 0; i < TB_RIGHT_LAYERS; i++)
					tbUpRightLine[i]->drawLine(graphics, tbRightPen[i], layers);

				tbUpTextBox->drawBox(graphics, borderlessPen, tbFont, centerFormat, textBrush, tbCenterBrush, objText, layers);
			}
			else if (tbState == TB_DN)
			{
				for (int i = 0; i < TB_TOP_LAYERS; i++)
					tbDnTopLine[i]->drawLine(graphics, tbTopPen[i], layers);

				for (int i = 0; i < TB_BOT_LAYERS; i++)
					tbDnBotLine[i]->drawLine(graphics, tbBotPen[i], layers);

				for (int i = 0; i < TB_LEFT_LAYERS; i++)
					tbDnLeftLine[i]->drawLine(graphics, tbLeftPen[i], layers);

				for (int i = 0; i < TB_RIGHT_LAYERS; i++)
					tbDnRightLine[i]->drawLine(graphics, tbRightPen[i], layers);

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

bool AATab::pressTab()
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

bool AATab::pressTab(HWND hWnd)
{
	if (tbState == TB_DN)
	{
		tbState = TB_UP;
		isDrawn = false;
		executeTab(hWnd);
		return true;
	}
	else
		return false;
}

bool AATab::releaseTab()
{
	if (tbState == TB_UP)
	{
		tbState = TB_DN;
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

	configGraphics();
}

void AATab::configGraphics()
{
	tbBlankBox->config(objBox, 99);

	// Up state graphics
	tbUpTextBox->config(objBox, 99);
	tbUpTextBox->shrink(2);
	tbUpTextBox->expand(2, -2);

	tbUpTopLine[0]->config({ objBox.X, objBox.Y }, { objBox.GetRight() + 2, objBox.Y }, 99);
	tbUpTopLine[0]->shrink(2);
	tbUpTopLine[1]->config({ objBox.X, objBox.Y + 1 }, { objBox.GetRight() + 2, objBox.Y + 1 }, 99);
	tbUpTopLine[1]->shrink(2);
	tbUpTopLine[2]->config({ objBox.X, objBox.Y + 1 }, { objBox.X + 1, objBox.Y + 1 }, 99);
	tbUpTopLine[3]->config({ objBox.GetRight() + 1, objBox.Y + 1 }, { objBox.GetRight() + 2, objBox.Y + 1 }, 99);
	tbUpTopLine[4]->config({ objBox.X, objBox.Y }, { objBox.X, objBox.Y + 1 }, 99);
	tbUpTopLine[5]->config({ objBox.GetRight() + 2, objBox.Y }, { objBox.GetRight() + 2, objBox.Y + 1 }, 99);
	tbUpTopLine[6]->config({ objBox.X, objBox.Y }, { objBox.X + 1, objBox.Y }, 99);
	tbUpTopLine[7]->config({ objBox.GetRight() + 1, objBox.Y }, { objBox.GetRight() + 2, objBox.Y }, 99);

	tbUpBotLine[0]->config({ objBox.X, objBox.GetBottom() - 1 }, { objBox.GetRight() + 2, objBox.GetBottom() - 1 }, 99);
	tbUpBotLine[0]->shrink(2);
	tbUpBotLine[1]->config({ objBox.X, objBox.GetBottom() }, { objBox.GetRight() + 2, objBox.GetBottom() }, 99);
	tbUpBotLine[1]->shrink(2);

	tbUpLeftLine[0]->config({ objBox.X, objBox.Y }, { objBox.X, objBox.GetBottom() }, 99);
	tbUpLeftLine[0]->shrink(1);
	tbUpLeftLine[0]->nudge(1);
	tbUpLeftLine[0]->contract(0, 1);
	tbUpLeftLine[1]->config({ objBox.X + 1, objBox.Y }, { objBox.X + 1, objBox.GetBottom() }, 99);
	tbUpLeftLine[1]->shrink(1);
	tbUpLeftLine[1]->nudge(1);
	tbUpLeftLine[1]->contract(0, 1);

	tbUpRightLine[0]->config({ objBox.GetRight() + 1, objBox.Y }, { objBox.GetRight() + 1, objBox.GetBottom() }, 99);
	tbUpRightLine[0]->shrink(1);
	tbUpRightLine[0]->nudge(1);
	tbUpRightLine[0]->contract(0, 1);
	tbUpRightLine[1]->config({ objBox.GetRight() + 2, objBox.Y }, { objBox.GetRight() + 2, objBox.GetBottom() }, 99);
	tbUpRightLine[1]->shrink(1);
	tbUpRightLine[1]->nudge(1);
	tbUpRightLine[1]->contract(0, 1);

	// Down state graphics
	tbDnTextBox->config(objBox, 99);
	tbDnTextBox->shrink(2);
	tbDnTextBox->nudge(0, 2);
	tbDnTextBox->contract(-1, 2);

	tbDnTopLine[0]->config({ objBox.X, objBox.Y + 2 }, { objBox.GetRight(), objBox.Y + 2 }, 99);
	tbDnTopLine[0]->shrink(2);
	tbDnTopLine[1]->config({ objBox.X, objBox.Y + 3 }, { objBox.GetRight(), objBox.Y + 3 }, 99);
	tbDnTopLine[1]->shrink(2);
	tbDnTopLine[2]->config({ objBox.X, objBox.Y + 3 }, { objBox.X + 1, objBox.Y + 3 }, 99);
	tbDnTopLine[3]->config({ objBox.GetRight() - 1, objBox.Y + 3 }, { objBox.GetRight(), objBox.Y + 3 }, 99);
	tbDnTopLine[4]->config({ objBox.X, objBox.Y + 2 }, { objBox.X, objBox.Y + 3 }, 99);
	tbDnTopLine[5]->config({ objBox.GetRight(), objBox.Y + 2}, {objBox.GetRight(), objBox.Y + 3}, 99);
	tbDnTopLine[6]->config({ objBox.X, objBox.Y + 2 }, { objBox.X + 1, objBox.Y + 2 }, 99);
	tbDnTopLine[7]->config({ objBox.GetRight() - 1, objBox.Y + 2 }, { objBox.GetRight(), objBox.Y + 2 }, 99);

	tbDnBotLine[0]->config({ objBox.X, objBox.GetBottom() - 2 }, { objBox.GetRight(), objBox.GetBottom() - 2 }, 99);
	tbDnBotLine[0]->shrink(2);
	tbDnBotLine[1]->config({ objBox.X, objBox.GetBottom() - 1 }, { objBox.GetRight(), objBox.GetBottom() - 1 }, 99);
	tbDnBotLine[1]->shrink(2);

	tbDnLeftLine[0]->config({ objBox.X, objBox.Y + 2 }, { objBox.X, objBox.GetBottom() - 1 }, 99);
	tbDnLeftLine[0]->shrink(1);
	tbDnLeftLine[0]->nudge(1);
	tbDnLeftLine[1]->config({ objBox.X + 1, objBox.Y + 2 }, { objBox.X + 1, objBox.GetBottom() - 1 }, 99);
	tbDnLeftLine[1]->shrink(1);
	tbDnLeftLine[1]->nudge(1);

	tbDnRightLine[0]->config({ objBox.GetRight() - 1, objBox.Y + 2 }, { objBox.GetRight() - 1, objBox.GetBottom() - 1 }, 99);
	tbDnRightLine[0]->shrink(1);
	tbDnRightLine[0]->nudge(1);
	tbDnRightLine[1]->config({ objBox.GetRight(), objBox.Y + 2 }, { objBox.GetRight(), objBox.GetBottom() - 1 }, 99);
	tbDnRightLine[1]->shrink(1);
	tbDnRightLine[1]->nudge(1);
}
