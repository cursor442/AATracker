#include "../header/AATabBar.h"

AATabBar::AATabBar(int id, int cfg, int ort)
	:AAGraphicsObject(id)
{
	tbConfig = cfg;
	tbOrient = ort;
	tbTabCnt = 0;
	tbTabIdx = -1;
	tbState = 0;
	isDrawn = false;

	tbTabs.resize(0);

	tbBlankBox = NULL;

	grayColor = NULL;
	grayBrush = NULL;

	clearBrush = NULL;

	tbFont = NULL;
}

AATabBar::~AATabBar()
{
	for (int i = 0; i < tbTabs.size(); i++)
		delete tbTabs[i];

	delete tbBlankBox;
}

void AATabBar::configTabBar(Graphics* graphics, int screen, RectF& rect)
{
	configObject(graphics, screen, NULL, rect);

	tbBlankBox = new AABox("");
}

void AATabBar::configDrawTools(vector<Color*>* cGray, vector<SolidBrush*>* bGray, SolidBrush* b0, Font* f0)
{
	grayColor = cGray;
	grayBrush = bGray;

	clearBrush = b0;

	tbFont = f0;
}

void AATabBar::addTab(Graphics* graphics, const char* text, void (*tbFunc)(HWND&))
{
	tbTabIdx++;
	tbTabCnt++;
	tbTabs.resize(tbTabCnt);
	tbTabs[tbTabIdx] = new AATab(tbTabIdx);

	// Configure new tab width
	RectF rect = calcTabWidth(text);

	tbTabs[tbTabIdx]->configTab(graphics, objScr, rect, text, tbFunc);
	configTabDrawTools(tbTabIdx);

	// Set tab state of the first tab
	// Only valid when creating the first tab
	if (tbTabIdx == 0)
		tbTabs[tbTabIdx]->setTabState(TB_UP);
}

void AATabBar::setTabFuncId(int idx, int val)
{
	if (idx < tbTabCnt)
		tbTabs[idx]->setTabFuncId(val);
}

void AATabBar::drawTab(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
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
			for (int i = tbTabCnt - 1; i >= 0; i--)
				tbTabs[i]->drawTab(graphics, dbg_boundbox, dbg_sections, layers);

			isDrawn = true;
		}
	}
}

void AATabBar::hideTab(Graphics* graphics)
{
	isDrawn = false;
	tbBlankBox->drawBox(graphics, borderlessPen, baseTextFont, centerFormat, textBrush, backBrush, L"", 99);

	for (int i = 0; i < tbTabCnt; i++)
		tbTabs[i]->hideTab(graphics);
}

bool AATabBar::pressTab(HWND hWnd, int idx)
{
	if (idx < tbTabCnt)
	{
		tbState = idx;
		for (int i = 0; i < tbTabCnt; i++)
			if (i != tbState)
				tbTabs[i]->releaseTab();

		return tbTabs[idx]->pressTab(hWnd);
	}
}

bool AATabBar::releaseTab(int idx)
{
	if (idx < tbTabCnt)
		return tbTabs[idx]->releaseTab();
}

int AATabBar::getTabId()
{
	return getObjectId();
}

int AATabBar::whichTabContainsPoint(int xPos, int yPos)
{
	RectF tmpBox;
	PointF point = PointF((REAL)xPos, (REAL)yPos);

	for (int i = 0; i < tbTabCnt; i++)
	{
		tmpBox = tbTabs[i]->getObjectBox();

		if (tmpBox.Contains(point))
			return i;
	}

	return -1;
}

void AATabBar::configTabDrawTools(int idx)
{
	tbTabs[idx]->configBaseDrawTools(borderPen, borderlessPen, fontFamily, textFormat, centerFormat, baseTextFont,
		textBrush, backBrush, popupBrush);
	tbTabs[idx]->configDrawTools(*grayColor, *grayBrush, clearBrush, tbFont);
}

RectF AATabBar::calcTabWidth(const char* text)
{
	RectF tmpRect;

	switch (tbConfig)
	{
	case TB_CFG_LEFT:
	{

		break;
	}
	case TB_CFG_FILL:
	{

		break;
	}
	case TB_CFG_EVEN:
	{
		tmpRect.Width = objBox.Width / tbTabCnt;
		tmpRect.Height = objBox.Height;
		tmpRect.X = objBox.GetRight() - tmpRect.Width;
		tmpRect.Y = objBox.Y;

		updateTabWidths(tmpRect.X);
		break;
	}
	default:
		break;
	}

	return tmpRect;
}

void AATabBar::updateTabWidths(REAL lastX)
{
	RectF tmpRect;

	for (int i = tbTabIdx - 1; i >= 0; i--)
	{
		switch (tbConfig)
		{
		case TB_CFG_LEFT:
		{

			break;
		}
		case TB_CFG_FILL:
		{

			break;
		}
		case TB_CFG_EVEN:
		{
			tmpRect.Width = objBox.Width / tbTabCnt;
			tmpRect.Height = objBox.Height;
			tmpRect.X = lastX - tmpRect.Width;
			tmpRect.Y = objBox.Y;

			lastX = tmpRect.X;
			tbTabs[i]->reconfigTab(tmpRect);
			break;
		}
		default:
			break;
		}
	}
}

