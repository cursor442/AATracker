#include "../header/AATab.h"

AATab::AATab(int id, int ort)
	:AAGraphicsObject(id)
{
	tbOrient = ort;
	tbState = TB_DN;
	tbLast = false;
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
	tbFunction1 = NULL;

	tbOrientVert = (tbOrient == TB_ORT_LEFT || tbOrient == TB_ORT_RIGHT);
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
	if (!tbOrientVert)
		rect.Width = round(rect.Width);
	else
		rect.Height = round(rect.Height);

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

void AATab::configTab(Graphics* graphics, int screen, RectF& rect, const char* text, void (*tbFunc)(HWND&, int))
{
	configTab(graphics, screen, rect, text);

	tbFunction1 = tbFunc;
}

void AATab::reconfigTab(RectF& rect)
{
	// Prevent overlap between tabs
	if (!tbOrientVert)
		rect.Width = round(rect.Width);
	else
		rect.Height = round(rect.Height);
	
	setObjectBox(rect);
	configGraphics();
}

void AATab::configDrawTools(vector<Color*>& cGray, vector<SolidBrush*>& bGray, SolidBrush* b0, Font* f0)
{
	tbCenterBrush = bGray[240];

	switch (tbOrient)
	{
	case TB_ORT_UP:
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
		break;
	case TB_ORT_DN:

		break;
	case TB_ORT_LEFT:
		tbTopPen[0] = new Pen(bGray[105], 1);
		tbTopPen[1] = new Pen(bGray[160], 1);
		tbTopPen[2] = new Pen(bGray[105], 1);
		tbTopPen[3] = new Pen(bGray[255], 1);
		tbTopPen[4] = new Pen(bGray[240], 1);
		tbTopPen[5] = new Pen(bGray[240], 1);
		tbTopPen[6] = new Pen(bGray[240], 1);
		tbTopPen[7] = new Pen(bGray[240], 1);

		tbBotPen[0] = new Pen(bGray[160], 1);
		tbBotPen[1] = new Pen(bGray[105], 1);

		tbLeftPen[0] = new Pen(bGray[160], 1);
		tbLeftPen[1] = new Pen(bGray[105], 1);

		tbRightPen[0] = new Pen(bGray[255], 1);
		tbRightPen[1] = new Pen(bGray[227], 1);
		break;
	case TB_ORT_RIGHT:
		tbTopPen[0] = new Pen(bGray[105], 1);
		tbTopPen[1] = new Pen(bGray[160], 1);
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
		break;
	default:
		break;
	}

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

void AATab::drawTab(Graphics* graphics, DBG& dbg)
{
	drawObject(graphics, dbg);

	if (dbg.sections) // Show box names
	{
		tbBlankBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, dbg.layers);
	}
	else // Actual graphics
	{
		if (!isDrawn)
		{
			int angle = 0;
			if (tbOrient == TB_ORT_LEFT)
				angle = 180;

			if (tbState == TB_UP)
			{
				tbUpTextBox->drawBox(graphics, borderlessPen, tbFont, centerFormat, textBrush, tbCenterBrush, objText, dbg.layers, angle);

				for (int i = 0; i < TB_TOP_LAYERS; i++)
					tbUpTopLine[i]->drawLine(graphics, tbTopPen[i], dbg.layers);
				
				//for (int i = 0; i < TB_BOT_LAYERS; i++)
					//tbUpBotLine[i]->drawLine(graphics, tbBotPen[i], dbg.layers);
				
				for (int i = 0; i < TB_LEFT_LAYERS; i++)
					tbUpLeftLine[i]->drawLine(graphics, tbLeftPen[i], dbg.layers);
				
				for (int i = 0; i < TB_RIGHT_LAYERS; i++)
					tbUpRightLine[i]->drawLine(graphics, tbRightPen[i], dbg.layers);
			}
			else if (tbState == TB_DN)
			{
				hideTab(graphics);

				tbDnTextBox->drawBox(graphics, borderlessPen, tbFont, centerFormat, textBrush, tbCenterBrush, objText, dbg.layers, angle);

				for (int i = 0; i < TB_TOP_LAYERS; i++)
					tbDnTopLine[i]->drawLine(graphics, tbTopPen[i], dbg.layers);

				for (int i = 0; i < TB_BOT_LAYERS; i++)
					tbDnBotLine[i]->drawLine(graphics, tbBotPen[i], dbg.layers);

				for (int i = 0; i < TB_LEFT_LAYERS; i++)
					tbDnLeftLine[i]->drawLine(graphics, tbLeftPen[i], dbg.layers);

				for (int i = 0; i < TB_RIGHT_LAYERS; i++)
					tbDnRightLine[i]->drawLine(graphics, tbRightPen[i], dbg.layers);
			}

			isDrawn = true;
		}
	}
}

void AATab::hideTab(Graphics* graphics)
{
	isDrawn = false;

	if (tbLast)
	{
		switch (tbOrient)
		{
		case TB_ORT_UP:
			tbBlankBox->expand(2, 0);
			break;
		case TB_ORT_DN:

			break;
		case TB_ORT_LEFT:
			tbBlankBox->expand(0, 2);
			break;
		case TB_ORT_RIGHT:
			tbBlankBox->expand(0, 2);
			break;
		default:
			break;
		}
	}

	tbBlankBox->drawBox(graphics, borderlessPen, baseTextFont, centerFormat, textBrush, backBrush, L"", 99);

	if (tbLast)
	{
		switch (tbOrient)
		{
		case TB_ORT_UP:
			tbBlankBox->expand(-2, 0);
			break;
		case TB_ORT_DN:

			break;
		case TB_ORT_LEFT:
			tbBlankBox->expand(0, -2);
			break;
		case TB_ORT_RIGHT:
			tbBlankBox->expand(0, -2);
			break;
		default:
			break;
		}
	}
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

void AATab::setTabLast(bool val)
{
	tbLast = val;
}

void AATab::setIsDrawn(bool val)
{
	isDrawn = val;
}

void AATab::executeTab(HWND hWnd)
{
	if (!hasFuncId)
		tbFunction0(hWnd);
	else
		tbFunction1(hWnd, tbFuncId);
}

int AATab::getTabId()
{
	return getObjectId();
}

int AATab::getTabOrient()
{
	return tbOrient;
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
	
	switch (tbOrient)
	{
	case TB_ORT_UP:
		configGraphicsUp();
		break;
	case TB_ORT_DN:
		configGraphicsDown();
		break;
	case TB_ORT_LEFT:
		configGraphicsLeft();
		break;
	case TB_ORT_RIGHT:
		configGraphicsRight();
		break;
	default:
		break;
	}
}

void AATab::configGraphicsUp()
{
	// Up state graphics
	tbUpTextBox->config(objBox, 99);
	tbUpTextBox->shrink(2);
	tbUpTextBox->expand(3, -2);

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
	tbDnTopLine[5]->config({ objBox.GetRight(), objBox.Y + 2 }, { objBox.GetRight(), objBox.Y + 3 }, 99);
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

void AATab::configGraphicsDown()
{

}

void AATab::configGraphicsLeft()
{
	tbBlankBox->expand(0, 1);

	// Up state graphics
	tbUpTextBox->config(objBox, 99);
	tbUpTextBox->shrink(2);
	tbUpTextBox->expand(2, 4);
	tbUpTextBox->nudge(0, 0);

	tbUpTopLine[0]->config({ objBox.X, objBox.Y }, { objBox.X, objBox.GetBottom() + 2 }, 99);
	tbUpTopLine[0]->shrink(2);
	tbUpTopLine[1]->config({ objBox.X + 1, objBox.Y }, { objBox.X + 1, objBox.GetBottom() + 2 }, 99);
	tbUpTopLine[1]->shrink(2);
	tbUpTopLine[2]->config({ objBox.X + 1, objBox.GetBottom() + 1 }, { objBox.X + 1, objBox.GetBottom() + 2 }, 99);
	tbUpTopLine[3]->config({ objBox.X + 1, objBox.Y }, { objBox.X + 1, objBox.Y + 1 }, 99);
	tbUpTopLine[4]->config({ objBox.X + 1, objBox.Y }, { objBox.X, objBox.Y }, 99);
	tbUpTopLine[5]->config({ objBox.X + 1, objBox.GetBottom() + 2 }, { objBox.X, objBox.GetBottom() + 2 }, 99);
	tbUpTopLine[6]->config({ objBox.X, objBox.Y }, { objBox.X, objBox.Y + 1 }, 99);
	tbUpTopLine[7]->config({ objBox.X, objBox.GetBottom() + 1 }, { objBox.X, objBox.GetBottom() + 2 }, 99);

	tbUpBotLine[0]->config({ objBox.GetRight() - 1, objBox.Y}, {objBox.GetRight() - 1, objBox.GetBottom() + 2}, 99);
	tbUpBotLine[0]->shrink(2);
	tbUpBotLine[1]->config({ objBox.GetRight(), objBox.Y}, {objBox.GetRight(), objBox.GetBottom() + 2}, 99);
	tbUpBotLine[1]->shrink(2);

	tbUpLeftLine[0]->config({ objBox.X, objBox.GetBottom() + 1 }, { objBox.GetRight(), objBox.GetBottom() + 1 }, 99);
	tbUpLeftLine[0]->shrink(1);
	tbUpLeftLine[0]->contract(-1, 0);
	tbUpLeftLine[1]->config({ objBox.X, objBox.GetBottom() + 2 }, { objBox.GetRight(), objBox.GetBottom() + 2 }, 99);
	tbUpLeftLine[1]->shrink(1);
	tbUpLeftLine[1]->contract(-1, 0);
	
	tbUpRightLine[0]->config({ objBox.X, objBox.Y }, { objBox.GetRight(), objBox.Y }, 99);
	tbUpRightLine[0]->shrink(1);
	tbUpRightLine[0]->contract(-1, 0);
	tbUpRightLine[1]->config({ objBox.X, objBox.Y + 1 }, { objBox.GetRight(), objBox.Y + 1 }, 99);
	tbUpRightLine[1]->shrink(1);
	tbUpRightLine[1]->contract(-1, 0);

	// Down state graphics
	tbDnTextBox->config(objBox, 99);
	tbDnTextBox->shrink(2);
	tbDnTextBox->contract(0, 0);
	tbDnTextBox->nudge(-1, 0);

	tbDnTopLine[0]->config({ objBox.X + 2, objBox.Y }, { objBox.X + 2, objBox.GetBottom() }, 99);
	tbDnTopLine[0]->shrink(2);
	tbDnTopLine[1]->config({ objBox.X + 3, objBox.Y }, { objBox.X + 3, objBox.GetBottom() }, 99);
	tbDnTopLine[1]->shrink(2);
	tbDnTopLine[2]->config({ objBox.X + 3, objBox.GetBottom() - 1 }, { objBox.X + 3, objBox.GetBottom() }, 99);
	tbDnTopLine[3]->config({ objBox.X + 3, objBox.Y }, { objBox.X + 3, objBox.Y + 1 }, 99);
	tbDnTopLine[4]->config({ objBox.X + 3, objBox.Y }, { objBox.X + 2, objBox.Y }, 99);
	tbDnTopLine[5]->config({ objBox.X + 3, objBox.GetBottom() }, { objBox.X + 2, objBox.GetBottom() }, 99);
	tbDnTopLine[6]->config({ objBox.X + 2, objBox.Y }, { objBox.X + 2, objBox.Y + 1 }, 99);
	tbDnTopLine[7]->config({ objBox.X + 2, objBox.GetBottom() - 1 }, { objBox.X + 2, objBox.GetBottom() }, 99);

	tbDnBotLine[0]->config({ objBox.GetRight() - 2, objBox.Y }, { objBox.GetRight() - 2, objBox.GetBottom() }, 99);
	tbDnBotLine[0]->shrink(2);
	tbDnBotLine[1]->config({ objBox.GetRight() - 1, objBox.Y }, { objBox.GetRight() - 1, objBox.GetBottom() }, 99);
	tbDnBotLine[1]->shrink(2);

	tbDnLeftLine[0]->config({ objBox.X + 2, objBox.GetBottom() - 1 }, { objBox.GetRight() - 1, objBox.GetBottom() - 1 }, 99);
	tbDnLeftLine[0]->shrink(1);
	tbDnLeftLine[0]->nudge(1);
	tbDnLeftLine[1]->config({ objBox.X + 2, objBox.GetBottom() }, { objBox.GetRight() - 1, objBox.GetBottom() }, 99);
	tbDnLeftLine[1]->shrink(1);
	tbDnLeftLine[1]->nudge(1);
	
	tbDnRightLine[0]->config({ objBox.X + 2, objBox.Y }, { objBox.GetRight() - 1, objBox.Y }, 99);
	tbDnRightLine[0]->shrink(1);
	tbDnRightLine[0]->nudge(1);
	tbDnRightLine[1]->config({ objBox.X + 2, objBox.Y + 1 }, { objBox.GetRight() - 1, objBox.Y + 1 }, 99);
	tbDnRightLine[1]->shrink(1);
	tbDnRightLine[1]->nudge(1);
}

void AATab::configGraphicsRight()
{
	tbBlankBox->expand(0, 1);
	tbBlankBox->nudge(1, 0);

	// Up state graphics
	tbUpTextBox->config(objBox, 99);
	tbUpTextBox->shrink(2);
	tbUpTextBox->expand(2, 4);
	tbUpTextBox->nudge(-1, 0);

	tbUpTopLine[0]->config({ objBox.GetRight(), objBox.Y }, { objBox.GetRight(), objBox.GetBottom() + 2 }, 99);
	tbUpTopLine[0]->shrink(2);
	tbUpTopLine[1]->config({ objBox.GetRight() - 1, objBox.Y }, { objBox.GetRight() - 1, objBox.GetBottom() + 2 }, 99);
	tbUpTopLine[1]->shrink(2);
	tbUpTopLine[2]->config({ objBox.GetRight() - 1, objBox.Y }, { objBox.GetRight() - 1, objBox.Y + 1 }, 99);
	tbUpTopLine[3]->config({ objBox.GetRight() - 1, objBox.GetBottom() + 1 }, { objBox.GetRight() - 1, objBox.GetBottom() + 2 }, 99);
	tbUpTopLine[4]->config({ objBox.GetRight() - 1, objBox.Y }, { objBox.GetRight(), objBox.Y }, 99);
	tbUpTopLine[5]->config({ objBox.GetRight() - 1, objBox.GetBottom() + 2 }, { objBox.GetRight(), objBox.GetBottom() + 2 }, 99);
	tbUpTopLine[6]->config({ objBox.GetRight(), objBox.Y }, { objBox.GetRight(), objBox.Y + 1 }, 99);
	tbUpTopLine[7]->config({ objBox.GetRight(), objBox.GetBottom() + 1 }, { objBox.GetRight(), objBox.GetBottom() + 2 }, 99);

	tbUpBotLine[0]->config({ objBox.X + 1, objBox.Y }, { objBox.X + 1, objBox.GetBottom() + 2 }, 99);
	tbUpBotLine[0]->shrink(2);
	tbUpBotLine[1]->config({ objBox.X, objBox.Y }, { objBox.X, objBox.GetBottom() + 2 }, 99);
	tbUpBotLine[1]->shrink(2);

	tbUpLeftLine[0]->config({ objBox.X, objBox.Y }, { objBox.GetRight(), objBox.Y }, 99);
	tbUpLeftLine[0]->shrink(1);
	tbUpLeftLine[0]->nudge(-1);
	tbUpLeftLine[0]->contract(-1, 0);
	tbUpLeftLine[1]->config({ objBox.X, objBox.Y + 1 }, { objBox.GetRight(), objBox.Y + 1 }, 99);
	tbUpLeftLine[1]->shrink(1);
	tbUpLeftLine[1]->nudge(-1);
	tbUpLeftLine[1]->contract(-1, 0);

	tbUpRightLine[0]->config({ objBox.X, objBox.GetBottom() + 1 }, { objBox.GetRight(), objBox.GetBottom() + 1 }, 99);
	tbUpRightLine[0]->shrink(1);
	tbUpRightLine[0]->nudge(-1);
	tbUpRightLine[0]->contract(-1, 0);
	tbUpRightLine[1]->config({ objBox.X, objBox.GetBottom() + 2 }, { objBox.GetRight(), objBox.GetBottom() + 2 }, 99);
	tbUpRightLine[1]->shrink(1);
	tbUpRightLine[1]->nudge(-1);
	tbUpRightLine[1]->contract(-1, 0);

	// Down state graphics
	tbDnTextBox->config(objBox, 99);
	tbDnTextBox->shrink(2);
	tbDnTextBox->contract(2, -1);

	tbDnTopLine[0]->config({ objBox.GetRight() - 2, objBox.Y }, { objBox.GetRight() - 2, objBox.GetBottom() }, 99);
	tbDnTopLine[0]->shrink(2);
	tbDnTopLine[1]->config({ objBox.GetRight() - 3, objBox.Y }, { objBox.GetRight() - 3, objBox.GetBottom() }, 99);
	tbDnTopLine[1]->shrink(2);
	tbDnTopLine[2]->config({ objBox.GetRight() - 3, objBox.Y }, { objBox.GetRight() - 3, objBox.Y + 1 }, 99);
	tbDnTopLine[3]->config({ objBox.GetRight() - 3, objBox.GetBottom() - 1 }, { objBox.GetRight() - 3, objBox.GetBottom() }, 99);
	tbDnTopLine[4]->config({ objBox.GetRight() - 3, objBox.Y }, { objBox.GetRight() - 2, objBox.Y }, 99);
	tbDnTopLine[5]->config({ objBox.GetRight() - 3, objBox.GetBottom() }, { objBox.GetRight() - 2, objBox.GetBottom() }, 99);
	tbDnTopLine[6]->config({ objBox.GetRight() - 2, objBox.Y }, { objBox.GetRight() - 2, objBox.Y + 1 }, 99);
	tbDnTopLine[7]->config({ objBox.GetRight() - 2, objBox.GetBottom() - 1 }, { objBox.GetRight() - 2, objBox.GetBottom() }, 99);

	tbDnBotLine[0]->config({ objBox.X + 2, objBox.Y }, { objBox.X + 2, objBox.GetBottom() }, 99);
	tbDnBotLine[0]->shrink(2);
	tbDnBotLine[1]->config({ objBox.X + 1, objBox.Y }, { objBox.X + 1, objBox.GetBottom() }, 99);
	tbDnBotLine[1]->shrink(2);

	tbDnLeftLine[0]->config({ objBox.X + 1, objBox.Y }, { objBox.GetRight() - 2, objBox.Y }, 99);
	tbDnLeftLine[0]->shrink(1);
	tbDnLeftLine[0]->nudge(-1);
	tbDnLeftLine[1]->config({ objBox.X + 1, objBox.Y + 1 }, { objBox.GetRight() - 2, objBox.Y + 1 }, 99);
	tbDnLeftLine[1]->shrink(1);
	tbDnLeftLine[1]->nudge(-1);

	tbDnRightLine[0]->config({ objBox.X + 1, objBox.GetBottom() - 1 }, { objBox.GetRight() - 2, objBox.GetBottom() - 1 }, 99);
	tbDnRightLine[0]->shrink(1);
	tbDnRightLine[0]->nudge(-1);
	tbDnRightLine[1]->config({ objBox.X + 1, objBox.GetBottom() }, { objBox.GetRight() - 2, objBox.GetBottom() }, 99);
	tbDnRightLine[1]->shrink(1);
	tbDnRightLine[1]->nudge(-1);
}
