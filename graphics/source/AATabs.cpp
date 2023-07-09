#include "../header/AATabs.h"

AATabs::AATabs(HWND hWnd, RectF rect)
{
	currPoint = { 0,0 };

	activeTabs.resize(0);
	inactiveTabs.resize(0);

	windowRect = rect;

	borderPen = NULL;
	borderlessPen = NULL;
	fontFamily = NULL;
	textFormat = NULL;
	centerFormat = NULL;
	baseTextFont = NULL;
	textBrush = NULL;
	backBrush = NULL;

	clearBrush = NULL;

	leftFormat = NULL;
	rightFormat = NULL;

	tabFont = NULL;
	tabFont_s = NULL;

	grayColors = NULL;
	grayBrushes = NULL;

	currIdx = TB_ID_NULL;
	lastIdx = TB_ID_NULL;

	currId = TB_ID_NULL;
	lastId = TB_ID_NULL;

	nextTabId = TB_ID_BASE;
}

AATabs::~AATabs()
{
	for (int i = 0; i < activeTabs.size(); i++)
		delete activeTabs[i];

	for (int i = 0; i < inactiveTabs.size(); i++)
		delete inactiveTabs[i];
}

void AATabs::configBaseDrawTools(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, SolidBrush* b0, SolidBrush* b1)
{
	borderPen = p0;
	borderlessPen = p1;

	fontFamily = ff;
	textFormat = sf0;
	centerFormat = sf1;
	baseTextFont = f0;

	textBrush = b0;
	backBrush = b1;
}

void AATabs::configDrawTools(vector<Color*>& cGray, vector<SolidBrush*>& bGray, SolidBrush* b0, StringFormat* sf0, StringFormat* sf1, Font* f0, Font* f1)
{
	clearBrush = b0;

	leftFormat = sf0;
	rightFormat = sf1;

	tabFont = f0;
	tabFont_s = f1;

	grayColors = &cGray;
	grayBrushes = &bGray;
}

void AATabs::addTab(Graphics* graphics, int id, const char* text, void (*tbFunc)(HWND&))
{
	convIdToIdx(id);

	if (currIdx != TB_ID_NULL)
		activeTabs[currIdx]->addTab(graphics, text, tbFunc);
}

void AATabs::addTab(Graphics* graphics, int id, const char* text, void (*tbFunc)(HWND&, int))
{
	convIdToIdx(id);

	if (currIdx != TB_ID_NULL)
		activeTabs[currIdx]->addTab(graphics, text, tbFunc);
}

int AATabs::checkForTab(HWND& hWnd, LPARAM lParam, bool& clickTab, int& tbTabIdx)
{
	GetCursorPos(&currPoint);
	ScreenToClient(hWnd, &currPoint);

	// Is the mouse even over the window?
	bool inWind = true;
	if (currPoint.x < windowRect.GetLeft() || currPoint.x > windowRect.GetRight() ||
		currPoint.y < windowRect.GetTop() || currPoint.y > windowRect.GetBottom())
		inWind = false;

	clickTab = false;

	int tbTab = TB_ID_NULL;
	tbTabIdx = TB_ID_NULL;

	if (inWind)
	{
		// Identify the current Tab the mouse is over
		tbTab = isPointInTabBox(currPoint.x, currPoint.y);

		// Click event is over an active Tab
		if (tbTab != TB_ID_NULL)
		{
			clickTab = true;
			tbTabIdx = whichTabBox(tbTab, currPoint.x, currPoint.y);
		}
	}

	return tbTab;
}

void AATabs::drawTab(int id, Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	convIdToIdx(id);

	if (currIdx != TB_ID_NULL)
		activeTabs[currIdx]->drawTab(graphics, dbg_boundbox, dbg_sections, layers);
}

void AATabs::hideTab(int id, Graphics* graphics)
{
	convIdToIdx(id);

	if (currIdx != TB_ID_NULL)
		activeTabs[currIdx]->hideTab(graphics);
}

void AATabs::hideAllTabs(Graphics* graphics)
{
	for (int i = 0; i < activeTabs.size(); i++)
		activeTabs[i]->hideTab(graphics);
}

bool AATabs::pressTab(int barId, int tabId)
{
	convIdToIdx(barId);

	if (currIdx != TB_ID_NULL)
		return activeTabs[currIdx]->pressTab(tabId);

	return false;
}

bool AATabs::pressTab(HWND hWnd, int barId, int tabId)
{
	convIdToIdx(barId);

	if (currIdx != TB_ID_NULL && tabId != TB_ID_NULL)
		return activeTabs[currIdx]->pressTab(hWnd, tabId);

	return false;
}

bool AATabs::releaseTab(int barId, int tabId)
{
	convIdToIdx(barId);

	if (currIdx != TB_ID_NULL)
		return activeTabs[currIdx]->releaseTab(tabId);

	return false;
}

int AATabs::createTabId()
{
	return nextTabId++;
}

void AATabs::setTabFuncId(int barId, int tabId, int funcId)
{
	convIdToIdx(barId);

	if (currIdx != TB_ID_NULL)
		return activeTabs[currIdx]->setTabFuncId(tabId, funcId);
}

int AATabs::getTabScreen(int id)
{
	convIdToIdx(id);

	if (currIdx != TB_ID_NULL)
		return activeTabs[currIdx]->getObjectScreen();

	return NULL;
}

int AATabs::getTabSection(int id)
{
	convIdToIdx(id);

	if (currIdx != TB_ID_NULL)
		return activeTabs[currIdx]->getObjectSection();

	return NULL;
}

bool AATabs::registerTab(Graphics* graphics, int id, int screen, int cfg, int ort, RectF& rect, const char* text, bool font_s, bool unique)
{
	// Extra bool is only there because apparently function pointer parameters can be matched against the first bool

	// Ensure that there is no duplicate id
	for (int i = 0; i < activeTabs.size(); i++)
		if (activeTabs[i]->getTabId() == id)
			return false;

	for (int i = 0; i < inactiveTabs.size(); i++)
		if (inactiveTabs[i]->getTabId() == id)
			return false;

	StringFormat* sf = NULL;
	switch (ort)
	{
	case TB_ORT_UP:
		sf = centerFormat;
		break;
	case TB_ORT_DN:
		sf = centerFormat;
		break;
	case TB_ORT_LEFT:
		sf = leftFormat;
		break;
	case TB_ORT_RIGHT:
		sf = rightFormat;
		break;
	default:
		break;
	}

	// New Tabs should be inactive by default
	inactiveTabs.resize(inactiveTabs.size() + 1);
	inactiveTabs[inactiveTabs.size() - 1] = new AATabBar(id, cfg, ort);
	inactiveTabs[inactiveTabs.size() - 1]->configBaseDrawTools(borderPen, borderlessPen, fontFamily,
		textFormat, sf, baseTextFont, textBrush, backBrush);
	if (!font_s)
		inactiveTabs[inactiveTabs.size() - 1]->configDrawTools(grayColors, grayBrushes, clearBrush, tabFont);
	else
		inactiveTabs[inactiveTabs.size() - 1]->configDrawTools(grayColors, grayBrushes, clearBrush, tabFont_s);

	// Round box off for convenience
	rect.X = round(rect.X);
	rect.Y = round(rect.Y);
	rect.Width = round(rect.Width);
	rect.Height = round(rect.Height);
	inactiveTabs[inactiveTabs.size() - 1]->configTabBar(graphics, screen, rect);

	return true;
}

bool AATabs::registerTab(Graphics* graphics, int id, int screen, int cfg, int ort, RectF& rect, const char* text, void (*bbFunc)(HWND&), bool font_s)
{
	if (registerTab(graphics, id, screen, cfg, ort, rect, text, font_s, true))
	{
		inactiveTabs[inactiveTabs.size() - 1]->configTabBar(graphics, screen, rect);
		return true;
	}
	else
		return false;
}

bool AATabs::activateTab(int id)
{
	// Ensure id exists and is inactive
	for (int i = 0; i < inactiveTabs.size(); i++)
		if (inactiveTabs[i]->getTabId() == id)
		{
			activeTabs.resize(activeTabs.size() + 1);
			activeTabs[activeTabs.size() - 1] = inactiveTabs[i];

			inactiveTabs.erase(inactiveTabs.begin() + i);
			return true;
		}

	return false;
}

bool AATabs::deactivateTab(int id)
{
	currId = TB_ID_NULL;
	currIdx = TB_ID_NULL;
	lastId = TB_ID_NULL;
	lastIdx = TB_ID_NULL;

	// Ensure id exists and is active
	for (int i = 0; i < activeTabs.size(); i++)
		if (activeTabs[i]->getTabId() == id)
		{
			inactiveTabs.resize(inactiveTabs.size() + 1);
			inactiveTabs[inactiveTabs.size() - 1] = activeTabs[i];

			activeTabs.erase(activeTabs.begin() + i);
			return true;
		}

	return false;
}

int AATabs::isPointInTabBox(int xPos, int yPos)
{
	int tempIdx = TB_ID_NULL;

	if (activeTabs.size() > 0) // There are active Tabs on this screen
	{
		// Only search active Tabs
		for (int i = 0; i < activeTabs.size(); i++)
		{
			// Active Tabs are not allowed to overlap
			// Only identify the first Tab containing the point
			if (activeTabs[i]->isPointInBox(xPos, yPos))
				return activeTabs[i]->getTabId();
		}

		// Point is not on any active Tab
		return TB_ID_NULL;
	}
	else // No active Tabs in this sector
		return TB_ID_NULL;
}

int AATabs::whichTabBox(int id, int xPos, int yPos)
{
	convIdToIdx(id);

	int tbTabIdx = activeTabs[currIdx]->whichTabContainsPoint(xPos, yPos);

	return tbTabIdx;
}

int AATabs::getTabState(int id)
{
	convIdToIdx(id);

	if (currIdx != TB_ID_NULL)
		return activeTabs[currIdx]->getTabState();
	else
	{
		convIdToIdxInactive(id);

		if (currIdx != TB_ID_NULL)
			return inactiveTabs[currIdx]->getTabState();
		else
			return TB_ID_NULL;
	}
}

void AATabs::convIdToIdx(int id)
{
	int idx = TB_ID_NULL;

	if (currId != id || (currIdx == TB_ID_NULL && id != TB_ID_NULL))
	{
		if (lastId != id || (lastIdx == TB_ID_NULL && id != TB_ID_NULL))
		{
			for (int i = 0; i < activeTabs.size(); i++)
				if (activeTabs[i]->getTabId() == id)
				{
					idx = i;
					break;
				}
		}
		else
			idx = lastIdx;

		lastId = currId;
		lastIdx = currIdx;
	}
	else
		idx = currIdx;

	currId = id;
	currIdx = idx;
}

void AATabs::convIdToIdxInactive(int id)
{
	int idx = TB_ID_NULL;

	if (currId != id || (currIdx == TB_ID_NULL && id != TB_ID_NULL))
	{
		if (lastId != id || (lastIdx == TB_ID_NULL && id != TB_ID_NULL))
		{
			for (int i = 0; i < inactiveTabs.size(); i++)
				if (inactiveTabs[i]->getTabId() == id)
				{
					idx = i;
					break;
				}
		}
		else
			idx = lastIdx;

		lastId = currId;
		lastIdx = currIdx;
	}
	else
		idx = currIdx;

	currId = id;
	currIdx = idx;
}
