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

	tbOrientVert = (tbOrient == TB_ORT_LEFT || tbOrient == TB_ORT_RIGHT);
	isTransposed = false;
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
	RectF rect = calcTabWidths(graphics, text);

	tbTabs[tbTabIdx]->configTab(graphics, objScr, rect, text, tbFunc);
	configTabDrawTools(tbTabIdx);

	// Set tab state of the first tab
	// Only valid when creating the first tab
	if (tbTabIdx == 0)
		tbTabs[tbTabIdx]->setTabState(TB_UP);
	else
		tbTabs[tbTabIdx - 1]->setTabLast(false);

	// Tabs are always last when they are added
	tbTabs[tbTabIdx]->setTabLast(true);
}

void AATabBar::addTab(Graphics* graphics, const char* text, void (*tbFunc)(HWND&, int))
{
	tbTabIdx++;
	tbTabCnt++;
	tbTabs.resize(tbTabCnt);
	tbTabs[tbTabIdx] = new AATab(tbTabIdx, tbOrient);

	// Configure new tab width
	RectF rect = calcTabWidths(graphics, text);

	tbTabs[tbTabIdx]->configTab(graphics, objScr, rect, text, tbFunc);
	configTabDrawTools(tbTabIdx);

	// Set tab state of the first tab
	// Only valid when creating the first tab
	if (tbTabIdx == 0)
		tbTabs[tbTabIdx]->setTabState(TB_UP);
	else
		tbTabs[tbTabIdx - 1]->setTabLast(false);

	// Tabs are always last when they are added
	tbTabs[tbTabIdx]->setTabLast(true);
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
			{
				isDrawn = false;
				tbTabs[i]->releaseTab();
				if (i != tbTabIdx)
					tbTabs[i + 1]->setIsDrawn(false);
			}

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
			{
				isDrawn = false;
				tbTabs[i]->releaseTab();
				if (i != tbTabIdx)
					tbTabs[i + 1]->setIsDrawn(false);
			}

		return tbTabs[idx]->pressTab(hWnd);
	}
}

bool AATabBar::releaseTab(int idx)
{
	if (idx < tbTabCnt)
	{
		if (idx != tbTabIdx)
			tbTabs[idx + 1]->setIsDrawn(false);
		return tbTabs[idx]->releaseTab();
	}
}

bool AATabBar::deleteTab(Graphics* graphics, int idx)
{
	if (idx < tbTabCnt)
	{
		if ((idx = tbTabCnt - 1) && idx != 0)
		{
			tbTabs[idx]->hideTab(graphics);

			tbTabCnt--;
			tbTabIdx--;
			
			delete tbTabs[idx];
			tbTabs.resize(tbTabCnt);

			isDrawn = false;

			// If this tab had been selected, select tab 0
			if (idx == tbState)
			{
				tbState = 0;
				tbTabs[0]->pressTab();
			}

			if (tbConfig == TB_CFG_FILL || tbConfig == TB_CFG_EVEN)
			{
				tbTabWidths.resize(tbTabCnt);
				tbTabWeights.resize(tbTabCnt);
				tbTabStarts.resize(tbTabCnt);

				calcTabWidths(graphics);
			}

			return true;
		}
		else
		{
			// Can only delete the last tab in a bar for now
			// Cannot delete the first tab in a bar for now
			return false;
		}
	}
	else
	{
		return false;
	}
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

int AATabBar::getTabCount()
{
	return tbTabCnt;
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

RectF AATabBar::calcTabWidths(Graphics* graphics, const char* text)
{
	RectF tmpRect;

	// Transpose object box if tab bar is vertical
	if (tbOrientVert)
		transposeObjBox();

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
		if (tbTabWidths.size() < tbTabCnt)
		{
			RectF* bounds = calcTextWidth(graphics, text);

			tbTabWidths.resize(tbTabCnt);
			tbTabWeights.resize(tbTabCnt);
			tbTabStarts.resize(tbTabCnt);

			tbTabWidths[tbTabIdx] = bounds->Width;
		}

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
		tmpRect.Width = round(tmpRect.Width);
		tmpRect.Height = objBox.Height;
		tmpRect.X = objBox.GetRight() - tmpRect.Width;
		tmpRect.Y = objBox.Y;

		updateTabWidths(tmpRect.X);
		break;
	}
	default:
		break;
	}

	// Transpose object box if tab bar is vertical
	// Also transpose tab box
	if (tbOrientVert)
	{
		transposeObjBox();
		transposeTabBox(tmpRect);
	}

	return tmpRect;
}

RectF* AATabBar::calcTextWidth(Graphics* graphics, const char* text)
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

	graphics->MeasureString(wtext, len, tbFont, *origin, bounds);
	delete origin;

	// Integer widths only
	bounds->Width = ceil(bounds->Width);

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

			// Transpose tab box if tab bar is vertical
			if (tbOrientVert)
			{
				transposeTabBox(tmpRect);
			}

			tbTabs[i]->reconfigTab(tmpRect);
		}
		break;
	}
	case TB_CFG_EVEN:
	{
		for (int i = tbTabIdx - 1; i >= 0; i--)
		{			
			if (i == 0)
			{
				tmpRect.X = objBox.X;
				tmpRect.Width = lastX - objBox.X - 1;
			}
			else
			{
				tmpRect.Width = objBox.Width / tbTabCnt;
				tmpRect.Width = round(tmpRect.Width);
				tmpRect.X = lastX - tmpRect.Width - 1;
			}
			tmpRect.Height = objBox.Height;
			tmpRect.Y = objBox.Y;

			lastX = tmpRect.X;

			// Transpose tab box if tab bar is vertical
			if (tbOrientVert)
			{
				transposeObjBox();
				transposeTabBox(tmpRect);
				transposeObjBox();
			}

			tbTabs[i]->reconfigTab(tmpRect);
		}
		break;
	}
	default:
		break;
	}
}

void AATabBar::transposeObjBox()
{
	REAL w = objBox.Width;
	REAL h = objBox.Height;

	objBox.Width = h;
	objBox.Height = w;

	isTransposed = !isTransposed;
}

void AATabBar::transposeTabBox(RectF& box)
{
	RectF tmpBox = box;

	box.X = objBox.X;
	box.Y = objBox.Y + (tmpBox.X - objBox.X);
	box.Width = objBox.Width;
	box.Height = tmpBox.Width;
}
