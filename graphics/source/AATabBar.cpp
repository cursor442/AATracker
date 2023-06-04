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
	tbTabWidths.resize(0);
	tbTabWeights.resize(0);
	tbTabStarts.resize(0);

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
	tbTabs[tbTabIdx] = new AATab(tbTabIdx, tbOrient);

	// Configure new tab width
	RectF rect = calcTabWidth(*graphics, text);

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

bool AATabBar::pressTab(int idx)
{
	if (idx < tbTabCnt)
	{
		tbState = idx;
		for (int i = 0; i < tbTabCnt; i++)
			if (i != tbState)
				tbTabs[i]->releaseTab();

		return tbTabs[idx]->pressTab();
	}
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

int AATabBar::getTabState()
{
	return tbState;
}

void AATabBar::configTabDrawTools(int idx)
{
	tbTabs[idx]->configBaseDrawTools(borderPen, borderlessPen, fontFamily, textFormat, centerFormat, baseTextFont,
		textBrush, backBrush, popupBrush);
	tbTabs[idx]->configDrawTools(*grayColor, *grayBrush, clearBrush, tbFont);
}

RectF AATabBar::calcTabWidth(Graphics& graphics, const char* text)
{
	RectF tmpRect;

	switch (tbConfig)
	{
	case TB_CFG_LEFT:
	{
		// Calculate minimum width required
		RectF* bounds = calcTextWidth(graphics, text);

		// Configure tab bounds
		tmpRect.X = bounds->X;
		tmpRect.Y = objBox.Y;
		tmpRect.Width = bounds->Width + 10;
		tmpRect.Height = objBox.Height;
		break;
	}
	case TB_CFG_FILL:
	{
		// Calculate minimum width required
		RectF* bounds = calcTextWidth(graphics, text);

		if (tbTabWidths.size() < tbTabCnt)
		{
			tbTabWidths.resize(tbTabCnt);
			tbTabWeights.resize(tbTabCnt);
			tbTabStarts.resize(tbTabCnt);
		}

		tbTabWidths[tbTabIdx] = bounds->Width;

		// Fill provided tab bar area weighted by text length
		REAL accum = 0;
		for (int i = 0; i < tbTabCnt; i++)
			accum += tbTabWidths[i];

		for (int i = 0; i < tbTabCnt; i++)
			tbTabWeights[i] = tbTabWidths[i] / accum;

		tbTabStarts[0] = objBox.X;
		for (int i = 1; i < tbTabCnt; i++)
			tbTabStarts[i] = floor(tbTabStarts[i - 1] + (objBox.Width * tbTabWeights[i - 1]));

		tmpRect.X = tbTabStarts[tbTabIdx];
		tmpRect.Y = objBox.Y;
		tmpRect.Width = objBox.GetRight() - tmpRect.X;
		tmpRect.Height = objBox.Height;

		updateTabWidths();

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

RectF* AATabBar::calcTextWidth(Graphics& graphics, const char* text)
{
	RectF tmpRect;

	// Calculate minimum width required
	std::wstring w;
	std::copy(text, text + strlen(text), std::back_inserter(w));
	const WCHAR* wtext = w.c_str();

	int len = strlen(text);

	RectF* origin;
	if (tbTabCnt == 1)
	{
		origin = new RectF(objBox);
	}
	else
	{
		REAL tmpX = tbTabs[tbTabIdx - 1]->getObjectBox().GetRight() + 1;
		origin = new RectF(tmpX, objBox.Y, objBox.GetRight() - tmpX, objBox.Height);
	}

	RectF* bounds = new RectF(0, 0, 0, 0);

	graphics.MeasureString(wtext, len, tbFont, *origin, bounds);
	delete origin;

	return bounds;
}

void AATabBar::updateTabWidths(REAL lastX)
{
	RectF tmpRect;

	switch (tbConfig)
	{
	case TB_CFG_LEFT:
	{
		// Adding new tabs does not affect existing ones
		break;
	}
	case TB_CFG_FILL:
	{
		for (int i = 0; i < tbTabCnt - 1; i++)
		{
			tmpRect.X = tbTabStarts[i];
			tmpRect.Y = objBox.Y;
			tmpRect.Width = tbTabStarts[i + 1] - tmpRect.X;
			tmpRect.Height = objBox.Height;

			tbTabs[i]->reconfigTab(tmpRect);
		}
		break;
	}
	case TB_CFG_EVEN:
	{
		for (int i = tbTabIdx - 1; i >= 0; i--)
		{
			tmpRect.Width = objBox.Width / tbTabCnt;
			tmpRect.Height = objBox.Height;
			tmpRect.X = lastX - tmpRect.Width;
			tmpRect.Y = objBox.Y;

			lastX = tmpRect.X;
			tbTabs[i]->reconfigTab(tmpRect);
		}
		break;
	}
	default:
		break;
	}
}

