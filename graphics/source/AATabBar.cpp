#include "../header/AATabBar.h"

AATabBar::AATabBar(int id, int cfg)
	:AAGraphicsObject(id)
{
	tbConfig = cfg;
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

void AATabBar::addTab(Graphics* graphics, int screen, RectF& rect, const char* text, void (*tbFunc)(HWND&))
{
	tbTabIdx++;
	tbTabs.resize(tbTabCnt + 1);
	tbTabs[tbTabIdx] = new AATab(tbTabIdx);
	tbTabs[tbTabIdx]->configTab(graphics, screen, rect, text);
	configTabDrawTools(tbTabIdx);
	tbTabCnt++;
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
			for (int i = 0; i < tbTabCnt; i++)
				tbTabs[i]->drawTab(graphics, dbg_boundbox, dbg_sections, layers);

			isDrawn = true;
		}
	}
}

void AATabBar::hideTab(Graphics* graphics)
{
	isDrawn = false;
	tbBlankBox->drawBox(graphics, borderlessPen, baseTextFont, centerFormat, textBrush, backBrush, L"", 99);
}

bool AATabBar::pressTab(HWND hWnd, int idx)
{
	if (idx < tbTabCnt)
		return tbTabs[idx]->pressTab(hWnd);
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

void AATabBar::configTabDrawTools(int idx)
{
	tbTabs[idx]->configBaseDrawTools(borderPen, borderlessPen, fontFamily, textFormat, centerFormat, baseTextFont,
		textBrush, backBrush, popupBrush);
	tbTabs[idx]->configDrawTools(*grayColor, *grayBrush, clearBrush, tbFont);
}

