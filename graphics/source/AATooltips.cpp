#include "../header/AATooltips.h"

AATooltips::AATooltips(HWND hWnd, RectF rect)
{
	currPoint = { 0,0 };
	currTooltip = TT_ID_NULL;

	activeTooltips.resize(0);
	inactiveTooltips.resize(0);

	for (int i = 0; i < TT_GRID_SIZE; i++)
		for (int j = 0; j < TT_GRID_SIZE; j++)
			activeTooltipGrid[i][j].resize(0);

	windowRect = rect;

	screenFrames = NULL;

	// Start the mouse position sample timer
	SetTimer(hWnd, TT_SAMPLE_TIMER_ID, TT_SAMPLE_TIMEOUT, NULL);

	borderPen = NULL;
	borderlessPen = NULL;
	fontFamily = NULL;
	textFormat = NULL;
	centerFormat = NULL;
	baseTextFont = NULL;
	textBrush = NULL;
	backBrush = NULL;
	popupBrush = NULL;

	currIdx = TT_ID_NULL;
	lastIdx = TT_ID_NULL;
}

AATooltips::~AATooltips()
{
	for (int i = 0; i < activeTooltips.size(); i++)
		delete activeTooltips[i];

	for (int i = 0; i < inactiveTooltips.size(); i++)
		delete inactiveTooltips[i];
}

void AATooltips::configBaseDrawTools(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
{
	borderPen = p0;
	borderlessPen = p1;

	fontFamily = ff;
	textFormat = sf0;
	centerFormat = sf1;
	baseTextFont = f0;

	textBrush = b0;
	backBrush = b1;
	popupBrush = b2;
}

void AATooltips::configScreenFrames(framesList* frames)
{
	screenFrames = frames;
}

void AATooltips::updateCurrPoint(HWND& hWnd, LPARAM lParam, bool& activeTooltip, bool& deactivateTooltip)
{
	GetCursorPos(&currPoint);
	ScreenToClient(hWnd, &currPoint);

	int xGrid = getGridIdx(currPoint.x, windowRect.GetRight());
	int yGrid = getGridIdx(currPoint.y, windowRect.GetBottom());

	// Is the mouse even over the window?
	bool inWind = true;
	if (currPoint.x < windowRect.GetLeft() || currPoint.x > windowRect.GetRight() ||
		currPoint.y < windowRect.GetTop() || currPoint.y > windowRect.GetBottom())
		inWind = false;

	if (inWind)
	{
		// Identify the current tooltip the mouse is over
		int ttIdx = isPointInTooltipBox(xGrid, yGrid, currPoint.x, currPoint.y);

		// Has the current tooltip changed?
		if (ttIdx != currTooltip)
		{
			currTooltip = ttIdx;

			// Kill the current timer if it exists
			KillTimer(hWnd, TT_HOVER_TIMER_ID);

			// Erase the current tooltip if it is active
			if (activeTooltip)
			{
				activeTooltip = false;
				deactivateTooltip = true;
			}

			// Start a hover timer if over an active tooltip
			if (ttIdx != TT_ID_NULL)
				SetTimer(hWnd, TT_HOVER_TIMER_ID, TT_HOVER_TIMEOUT, NULL);
		}
	}

	// Reset the sample timer
	SetTimer(hWnd, TT_SAMPLE_TIMER_ID, TT_SAMPLE_TIMEOUT, NULL);
}

void AATooltips::drawTooltip(HWND& hWnd, LPARAM lParam, Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (currIdx != TT_ID_NULL)
	{
		activeTooltips[currIdx]->drawTooltip(graphics, dbg_boundbox, dbg_sections, layers);
		lastIdx = currIdx;
	}
}

void AATooltips::hideTooltip(HWND& hWnd, LPARAM lParam, Graphics* graphics, int& sect)
{
	if (lastIdx != TT_ID_NULL)
		activeTooltips[lastIdx]->hideTooltip(graphics, sect);
}

bool AATooltips::registerTooltip(Graphics* graphics, int id, int screen, RectF& rect, int dir, const char* text)
{
	// Ensure that there is no duplicate id
	for (int i = 0; i < activeTooltips.size(); i++)
		if (activeTooltips[i]->getTooltipId() == id)
			return false;

	for (int i = 0; i < inactiveTooltips.size(); i++)
		if (inactiveTooltips[i]->getTooltipId() == id)
			return false;

	// New tooltips should be inactive by default
	inactiveTooltips.resize(inactiveTooltips.size() + 1);
	inactiveTooltips[inactiveTooltips.size() - 1] = new AATooltip(id);
	inactiveTooltips[inactiveTooltips.size() - 1]->configBaseDrawTools(borderPen, borderlessPen, fontFamily,
		textFormat, centerFormat, baseTextFont, textBrush, backBrush, popupBrush);
	inactiveTooltips[inactiveTooltips.size() - 1]->configTooltip(graphics, screen, rect, dir, text, screenFrames);

	return true;
}

bool AATooltips::activateTooltip(int id)
{
	// Ensure id exists and is inactive
	for (int i = 0; i < inactiveTooltips.size(); i++)
		if (inactiveTooltips[i]->getTooltipId() == id)
		{
			activeTooltips.resize(activeTooltips.size() + 1);
			activeTooltips[activeTooltips.size() - 1] = inactiveTooltips[i];
			updateTooltipGrid(id, TT_GRID_ADD);

			inactiveTooltips.erase(inactiveTooltips.begin() + i);
			return true;
		}

	return false;
}

bool AATooltips::deactivateTooltip(int id)
{
	// Ensure id exists and is active
	for (int i = 0; i < activeTooltips.size(); i++)
		if (activeTooltips[i]->getTooltipId() == id)
		{
			inactiveTooltips.resize(inactiveTooltips.size() + 1);
			inactiveTooltips[inactiveTooltips.size() - 1] = activeTooltips[i];
			updateTooltipGrid(id, TT_GRID_SUB);

			activeTooltips.erase(activeTooltips.begin() + i);
			return true;
		}

	return false;
}

int AATooltips::isPointInTooltipBox(int xGrid, int yGrid, int xPos, int yPos)
{
	if (activeTooltipGrid[xGrid][yGrid].size() > 0) // There are active tooltips in this sector
	{
		// Only search active tooltips
		for (int i = 0; i < activeTooltipGrid[xGrid][yGrid].size(); i++)
		{
			// Map id to check to an index in the active tooltip list
			int currId = activeTooltipGrid[xGrid][yGrid][i];
			currIdx = TT_ID_NULL;
			for (int j = 0; j < activeTooltips.size(); j++)
				if (activeTooltips[j]->getTooltipId() == currId)
				{
					currIdx = j;
					break;
				}

			// Active tooltips are not allowed to overlap
			// Only identify the first tooltip containing the point
			if (activeTooltips[currIdx]->isPointInBox(xPos, yPos))
				return currId;
		}

		// Point is not on any active tooltip
		currIdx = TT_ID_NULL;
		return TT_ID_NULL;
	}
	else // No active tooltips in this sector
	{
		currIdx = TT_ID_NULL;
		return TT_ID_NULL;
	}
}

void AATooltips::updateTooltipGrid(int id, bool dir)
{
	int idx = 0;
	PointF tl, br;
	int tl_x, tl_y;
	int br_x, br_y;

	if (dir == TT_GRID_ADD) // Adding to the tooltip grid
	{
		// Match the id to the location in the vector
		for (int i = 0; i < activeTooltips.size(); i++)
			if (activeTooltips[i]->getTooltipId() == id)
			{
				idx = i;
				break;
			}

		// Get the significant corners of the tooltip's rectangle
		tl = activeTooltips[idx]->getRectCorner(TT_RECT_TL);
		br = activeTooltips[idx]->getRectCorner(TT_RECT_BR);

		// Get the grid indexes for each corner
		tl_x = getGridIdx(tl.X, windowRect.GetRight());
		tl_y = getGridIdx(tl.Y, windowRect.GetBottom());
		br_x = getGridIdx(tl.X, windowRect.GetRight());
		br_y = getGridIdx(tl.Y, windowRect.GetBottom());

		// Add the id to each grid square covered by the tooltip
		for (int i = tl_x; i <= br_x; i++)
			for (int j = tl_y; j <= br_y; j++)
				if (i < TT_GRID_SIZE && j < TT_GRID_SIZE)
					activeTooltipGrid[i][j].push_back(id);
	}
	else // Removing from the tooltip grid
	{
		for (int i = 0; i < TT_GRID_SIZE; i++)
			for (int j = 0; j < TT_GRID_SIZE; j++)
				for (int k = 0; k < activeTooltipGrid[i][j].size(); k++)
					if (activeTooltipGrid[i][j][k] == id)
						activeTooltipGrid[i][j].erase(activeTooltipGrid[i][j].begin() + k);
	}
}

// Over-engineering at its finest
int AATooltips::getGridIdx(int val, int lim)
{
	int idx = -1;
	int tmp = val * TT_GRID_SIZE;

	if (tmp == 0)
		return 0;
	else if (tmp % lim == 0) // Maximum value of bin
		return ((tmp - 1) / lim);
	else
		return (tmp / lim);
}
