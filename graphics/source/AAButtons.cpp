#include "../header/AAButtons.h"

AAButtons::AAButtons(HWND hWnd, RectF rect)
{
	currPoint = { 0,0 };
	currButton = BB_ID_NULL;

	activeButtons.resize(0);
	inactiveButtons.resize(0);

	for (int i = 0; i < BB_GRID_SIZE; i++)
		for (int j = 0; j < BB_GRID_SIZE; j++)
			activeButtonGrid[i][j].resize(0);

	windowRect = rect;

	screenFrames = NULL;

	// Start the mouse position sample timer
	SetTimer(hWnd, BB_SAMPLE_TIMER_ID, BB_SAMPLE_TIMEOUT, NULL);

	borderPen = NULL;
	borderlessPen = NULL;
	fontFamily = NULL;
	textFormat = NULL;
	centerFormat = NULL;
	baseTextFont = NULL;
	textBrush = NULL;
	backBrush = NULL;

	clearBrush = NULL;

	buttonFont = NULL;

	grayColors = NULL;
	grayBrushes = NULL;

	currIdx = BB_ID_NULL;
	lastIdx = BB_ID_NULL;
}

AAButtons::~AAButtons()
{
	for (int i = 0; i < activeButtons.size(); i++)
		delete activeButtons[i];

	for (int i = 0; i < inactiveButtons.size(); i++)
		delete inactiveButtons[i];
}

void AAButtons::configBaseDrawTools(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
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

void AAButtons::configDrawTools(vector<Color*>& cGray, vector<SolidBrush*>& bGray, SolidBrush* b0, Font* f0)
{
	clearBrush = b0;

	buttonFont = f0;

	grayColors = &cGray;
	grayBrushes = &bGray;
}

void AAButtons::configScreenFrames(framesList* frames)
{
	screenFrames = frames;
}

void AAButtons::updateCurrPoint(HWND& hWnd, LPARAM lParam, bool& activeButton, bool& deactivateButton)
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
		// Identify the current Button the mouse is over
		int ttIdx = isPointInButtonBox(xGrid, yGrid, currPoint.x, currPoint.y);

		// Has the current Button changed?
		if (ttIdx != currButton)
		{
			currButton = ttIdx;

			// Kill the current timer if it exists
			KillTimer(hWnd, BB_HOVER_TIMER_ID);

			// Erase the current Button if it is active
			if (activeButton)
			{
				activeButton = false;
				deactivateButton = true;
			}

			// Start a hover timer if over an active Button
			if (ttIdx != BB_ID_NULL)
				SetTimer(hWnd, BB_HOVER_TIMER_ID, BB_HOVER_TIMEOUT, NULL);
		}
	}

	// Reset the sample timer
	SetTimer(hWnd, BB_SAMPLE_TIMER_ID, BB_SAMPLE_TIMEOUT, NULL);
}

void AAButtons::drawButton(int idx, Graphics* graphics, HDC& hdc, bool dbg_boundbox, bool dbg_sections, int layers)
{
	currIdx = idx;

	if (currIdx != BB_ID_NULL)
	{
		activeButtons[currIdx]->drawButton(graphics, hdc, dbg_boundbox, dbg_sections, layers);
		lastIdx = currIdx;
	}
}

void AAButtons::hideButton(HWND& hWnd, LPARAM lParam, Graphics* graphics, int& sect)
{
	if (lastIdx != BB_ID_NULL)
		activeButtons[lastIdx]->hideButton(graphics, sect);
}

bool AAButtons::registerButton(Graphics* graphics, int id, int screen, RectF& rect, const char* text)
{
	// Ensure that there is no duplicate id
	for (int i = 0; i < activeButtons.size(); i++)
		if (activeButtons[i]->getButtonId() == id)
			return false;

	for (int i = 0; i < inactiveButtons.size(); i++)
		if (inactiveButtons[i]->getButtonId() == id)
			return false;

	// New Buttons should be inactive by default
	inactiveButtons.resize(inactiveButtons.size() + 1);
	inactiveButtons[inactiveButtons.size() - 1] = new AAButton(id);
	inactiveButtons[inactiveButtons.size() - 1]->configBaseDrawTools(borderPen, borderlessPen, fontFamily,
		textFormat, centerFormat, baseTextFont, textBrush, backBrush);
	inactiveButtons[inactiveButtons.size() - 1]->configDrawTools(*grayColors, *grayBrushes, clearBrush, buttonFont);
	inactiveButtons[inactiveButtons.size() - 1]->configButton(graphics, screen, rect, text, screenFrames);

	return true;
}

bool AAButtons::activateButton(int id)
{
	// Ensure id exists and is inactive
	for (int i = 0; i < inactiveButtons.size(); i++)
		if (inactiveButtons[i]->getButtonId() == id)
		{
			activeButtons.resize(activeButtons.size() + 1);
			activeButtons[activeButtons.size() - 1] = inactiveButtons[i];
			updateButtonGrid(id, BB_GRID_ADD);

			inactiveButtons.erase(inactiveButtons.begin() + i);
			return true;
		}

	return false;
}

bool AAButtons::deactivateButton(int id)
{
	// Ensure id exists and is active
	for (int i = 0; i < activeButtons.size(); i++)
		if (activeButtons[i]->getButtonId() == id)
		{
			inactiveButtons.resize(inactiveButtons.size() + 1);
			inactiveButtons[inactiveButtons.size() - 1] = activeButtons[i];
			updateButtonGrid(id, BB_GRID_SUB);

			activeButtons.erase(activeButtons.begin() + i);
			return true;
		}

	return false;
}

int AAButtons::isPointInButtonBox(int xGrid, int yGrid, int xPos, int yPos)
{
	if (activeButtonGrid[xGrid][yGrid].size() > 0) // There are active Buttons in this sector
	{
		// Only search active Buttons
		for (int i = 0; i < activeButtonGrid[xGrid][yGrid].size(); i++)
		{
			// Map id to check to an index in the active Button list
			int currId = activeButtonGrid[xGrid][yGrid][i];
			currIdx = BB_ID_NULL;
			for (int j = 0; j < activeButtons.size(); j++)
				if (activeButtons[j]->getButtonId() == currId)
				{
					currIdx = j;
					break;
				}

			// Active Buttons are not allowed to overlap
			// Only identify the first Button containing the point
			if (activeButtons[currIdx]->isPointInBox(xPos, yPos))
				return currId;
		}

		// Point is not on any active Button
		currIdx = BB_ID_NULL;
		return BB_ID_NULL;
	}
	else // No active Buttons in this sector
	{
		currIdx = BB_ID_NULL;
		return BB_ID_NULL;
	}
}

void AAButtons::updateButtonGrid(int id, bool dir)
{
	int idx = 0;
	PointF tl, br;
	int tl_x, tl_y;
	int br_x, br_y;

	if (dir == BB_GRID_ADD) // Adding to the Button grid
	{
		// Match the id to the location in the vector
		for (int i = 0; i < activeButtons.size(); i++)
			if (activeButtons[i]->getButtonId() == id)
			{
				idx = i;
				break;
			}

		// Get the significant corners of the Button's rectangle
		tl = activeButtons[idx]->getRectCorner(GRAPHICS_RECT_TL);
		br = activeButtons[idx]->getRectCorner(GRAPHICS_RECT_BR);

		// Get the grid indexes for each corner
		tl_x = getGridIdx(tl.X, windowRect.GetRight());
		tl_y = getGridIdx(tl.Y, windowRect.GetBottom());
		br_x = getGridIdx(tl.X, windowRect.GetRight());
		br_y = getGridIdx(tl.Y, windowRect.GetBottom());

		// Add the id to each grid square covered by the Button
		for (int i = tl_x; i <= br_x; i++)
			for (int j = tl_y; j <= br_y; j++)
				if (i < BB_GRID_SIZE && j < BB_GRID_SIZE)
					activeButtonGrid[i][j].push_back(id);
	}
	else // Removing from the Button grid
	{
		for (int i = 0; i < BB_GRID_SIZE; i++)
			for (int j = 0; j < BB_GRID_SIZE; j++)
				for (int k = 0; k < activeButtonGrid[i][j].size(); k++)
					if (activeButtonGrid[i][j][k] == id)
						activeButtonGrid[i][j].erase(activeButtonGrid[i][j].begin() + k);
	}
}

// Over-engineering at its finest
int AAButtons::getGridIdx(int val, int lim)
{
	int idx = -1;
	int tmp = val * BB_GRID_SIZE;

	if (tmp == 0)
		return 0;
	else if (tmp % lim == 0) // Maximum value of bin
		return ((tmp - 1) / lim);
	else
		return (tmp / lim);
}
