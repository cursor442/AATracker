#include "../header/LogClass.h"
#include "../header/LogTerrs.h"

Log::Log(int type, RECT logPane)
{
	pane = logPane;

	globalGame = (type == GLOBAL_GAME);

	logBox.resize(1);
	logBox[0].resize(1);
	logBox[0][0].resize(ROWS);

	currPage = 0;
	currCol = 0;

	for (int i = 0; i < logBox.size(); i++)
		for (int j = 0; j < logBox[i].size(); j++)
			for (int k = 0; k < logBox[i][j].size(); k++)
				logBox[i][j][k] = new LogPair(logPane.left + 10, k, globalGame);

	vector<int> target;
	target.resize(0);

	logBox[0][0][0]->setText(0, V_SETUP);
	logBox[0][0][1]->setText(0, V_NEUTRAL);

	if (type == EUROPE_GAME)
	{
		target.resize(2); target[0] = TURN_UKE; target[1] = TURN_FRA;
		logBox[0][0][2]->setText(0, V_WAR, TURN_GER, &target);
		logBox[0][0][3]->setText(0, V_WAR, TURN_ITA, &target);
		currRow = 4;
	}
	else if (type == PACIFIC_GAME)
	{
		target.resize(1); target[0] = TURN_CHN;
		logBox[0][0][2]->setText(0, V_WAR, TURN_JPN, &target);
		currRow = 3;
	}
	else
	{
		target.resize(3); target[0] = TURN_UKE; target[1] = TURN_ANZ; target[2] = TURN_FRA;
		logBox[0][0][2]->setText(0, V_WAR, TURN_GER, &target);
		logBox[0][0][3]->setText(0, V_WAR, TURN_ITA, &target);
		target.resize(1); target[0] = TURN_CHN;
		logBox[0][0][4]->setText(0, V_WAR, TURN_JPN, &target);
		currRow = 5;
	}

	target.resize(0);

	currTurn = 1; currNat = 0;
	tgtEx = false; occEx = false; resEx = false;
	tgtPos.page = 0; tgtPos.col = 0; tgtPos.row = 0;
	for (int i = 0; i < 10; i++)
	{
		capEx[i] = false;
		capPos[i].page = 0; capPos[i].col = 0; capPos[i].row = 0;

		for (int j = 0; j < 10; j++)
		{
			libEx[i][j] = false;
			libPos[i][j].page = 0; libPos[i][j].col = 0; libPos[i][j].row = 0;
		}
	}
	occPos.page = 0; occPos.col = 0; occPos.row = 0;
	resPos.page = 0; resPos.col = 0; resPos.row = 0;

	newPage = false;

	configDrawTools();
}

Log::~Log()
{
	for (int i = 0; i < logBox.size(); i++)
		for (int j = 0; j < logBox[i].size(); j++)
			for (int k = 0; k < logBox[i][j].size(); k++)
				delete logBox[i][j][k];

	delete fontFamily;
	delete turnFont; delete textFont; delete boldFont;

	delete textBrush;

	delete paneBrush; delete backBrush;

	delete linePen; 
}

void Log::configDrawTools()
{
	fontFamily = new FontFamily(L"Calibri");
	turnFont = new Font(fontFamily, TURNFONT_S, FontStyleRegular, UnitPixel);
	textFont = new Font(fontFamily, TEXTFONT_S, FontStyleRegular, UnitPixel);
	boldFont = new Font(fontFamily, TEXTFONT_S, FontStyleBold, UnitPixel);

	turnFormat.SetAlignment(StringAlignmentNear);
	textFormat.SetAlignment(StringAlignmentNear);
	turnFormat.SetLineAlignment(StringAlignmentCenter);
	textFormat.SetLineAlignment(StringAlignmentNear);

	textBrush = new SolidBrush(Color(255, 0, 0, 0));

	paneBrush = new SolidBrush(Color(212, 212, 212));
	backBrush = new SolidBrush(Color(240, 240, 240));

	linePen = new Pen(Color(255, 0, 0, 0));
}

void Log::addLogText(int turn, int verb, int nat, int tgt, int object, int indirect)
{
	bool isOcc = false;

	if (turn != currTurn || nat != currNat)
	{
		tgtEx = false; occEx = false; resEx = false;
		tgtPos.page = 0; tgtPos.col = 0; tgtPos.row = 0;
		for (int i = 0; i < 10; i++)
		{
			capEx[i] = false;
			capPos[i].page = 0; capPos[i].col = 0; capPos[i].row = 0;
			
			for (int j = 0; j < 10; j++)
			{
				libEx[i][j] = false;
				libPos[i][j].page = 0; libPos[i][j].col = 0; libPos[i][j].row = 0;
			}

			recEx[i] = false;
			recPos[i].page = 0; recPos[i].col = 0; recPos[i].row = 0;
		}
		occPos.page = 0; occPos.col = 0; occPos.row = 0;
		resPos.page = 0; resPos.col = 0; resPos.row = 0;
	}

	if (verb == V_OCCUPY) // Friendly neutral
		isOcc = true;
	else if (verb != V_RESEARCH) // Non-friendly neutral
		for (int i = 0; i < 44; i++)
			if (tgt == neutrals[i])
			{
				isOcc = true;
				break;
			}

	switch (verb)
	{
	case V_WAR:
	{
		if (!tgtEx)
		{
			tgtPos.page = currPage; tgtPos.col = currCol; tgtPos.row = currRow;
			tgtEx = true;
			incCell();
		}

		logBox[tgtPos.page][tgtPos.col][tgtPos.row]->setText(turn, verb, nat, tgt);

		break;
	}
	case V_CAPTURE:
	{
		if (!isOcc) // Capture
		{
			if (!capEx[object])
			{
				capPos[object].page = currPage; capPos[object].col = currCol; capPos[object].row = currRow;
				capEx[object] = true;
				incCell();
			}

			if (logBox[capPos[object].page][capPos[object].col][capPos[object].row]->isSpace(V_CAPTURE, tgt))
				logBox[capPos[object].page][capPos[object].col][capPos[object].row]->setText(turn, V_CAPTURE, nat, tgt, object);
			else
			{
				shiftCells(capPos[object].page, capPos[object].col, capPos[object].row, V_CAPTURE, object, indirect);
				logBox[capPos[object].page][capPos[object].col][capPos[object].row]->setText(turn, V_CAPTURE, nat, tgt, object);
			}
		}
		else // Occupy
		{
			if (!occEx)
			{
				occPos.page = currPage; occPos.col = currCol; occPos.row = currRow;
				occEx = true;
				incCell();
			}

			if (logBox[occPos.page][occPos.col][occPos.row]->isSpace(V_CAPTURE, tgt))
				logBox[occPos.page][occPos.col][occPos.row]->setText(turn, V_OCCUPY, nat, tgt);
			else
			{
				shiftCells(occPos.page, occPos.col, occPos.row, V_CAPTURE, object, indirect);
				logBox[occPos.page][occPos.col][occPos.row]->setText(turn, V_OCCUPY, nat, tgt);
			}
		}

		break;
	}
	case V_LIBERATE:
	{
		if (!libEx[object][indirect])
		{
			libPos[object][indirect].page = currPage; 
			libPos[object][indirect].col = currCol; 
			libPos[object][indirect].row = currRow;
			libEx[object][indirect] = true;
			incCell();
		}

		int obj = object;
		int ind = indirect;

		if (logBox[libPos[obj][ind].page][libPos[obj][ind].col][libPos[obj][ind].row]->isSpace(V_LIBERATE, tgt))
			logBox[libPos[obj][ind].page][libPos[obj][ind].col][libPos[obj][ind].row]->setText(turn, V_LIBERATE, nat, tgt, object, indirect);
		else
		{
			shiftCells(libPos[obj][ind].page, libPos[obj][ind].col, libPos[obj][ind].row, V_LIBERATE, object, indirect);
			logBox[libPos[obj][ind].page][libPos[obj][ind].col][libPos[obj][ind].row]->setText(turn, V_LIBERATE, nat, tgt, object, indirect);
		}

		break;
	}
	case V_RECLAIM:
	{
			if (!recEx[object])
			{
				recPos[object].page = currPage; recPos[object].col = currCol; recPos[object].row = currRow;
				recEx[object] = true;
				incCell();
			}

			if (logBox[recPos[object].page][recPos[object].col][recPos[object].row]->isSpace(V_RECLAIM, tgt))
				logBox[recPos[object].page][recPos[object].col][recPos[object].row]->setText(turn, V_RECLAIM, nat, tgt, object);
			else
			{
				shiftCells(recPos[object].page, recPos[object].col, recPos[object].row, V_RECLAIM, object, indirect);
				logBox[recPos[object].page][recPos[object].col][recPos[object].row]->setText(turn, V_RECLAIM, nat, tgt, object);
			}

		break;
	}
	case V_OCCUPY:
	{
		if (!occEx)
		{
			occPos.page = currPage; occPos.col = currCol; occPos.row = currRow;
			occEx = true;
			incCell();
		}

		if (logBox[occPos.page][occPos.col][occPos.row]->isSpace(V_OCCUPY, tgt))
			logBox[occPos.page][occPos.col][occPos.row]->setText(turn, V_OCCUPY, nat, tgt);
		else
		{
			shiftCells(occPos.page, occPos.col, occPos.row, V_OCCUPY, object, indirect);
			logBox[occPos.page][occPos.col][occPos.row]->setText(turn, V_OCCUPY, nat, tgt);
		}

		break;
	}
	case V_RESEARCH:
	{
		if (!resEx)
		{
			resPos.page = currPage; resPos.col = currCol; resPos.row = currRow;
			resEx = true;
			incCell();
		}

		if (logBox[resPos.page][resPos.col][resPos.row]->isSpace(V_RESEARCH, tgt))
			logBox[resPos.page][resPos.col][resPos.row]->setText(turn, V_RESEARCH, nat, tgt);
		else
		{
			shiftCells(resPos.page, resPos.col, resPos.row, V_RESEARCH, object, indirect);
			logBox[resPos.page][resPos.col][resPos.row]->setText(turn, V_RESEARCH, nat, tgt);
		}

		break;
	}
	case V_NEUTRAL_AXIS: case V_NEUTRAL_ALLY: case V_MONGOLIA:
	{
		logBox[currPage][currCol][currRow]->setText(turn, verb, TURN_NON, TURN_NON);
		incCell();
		break;
	}
	default: break;
	}

	currTurn = turn;
	currNat = nat;
}

void Log::addLogText(int nat, vector<int>& targets, int object)
{
	// This one is only for post-liberations from third party allies to the liberated
	// Don't need to track the position since it can only happen once and all at once

	for (int i = 0; i < targets.size(); i++)
	{
		if (logBox[currPage][currCol][currRow]->isSpace(V_RECLAIM, targets[i]))
			logBox[currPage][currCol][currRow]->setText(currTurn, V_RECLAIM, nat, targets[i], object);
		else
		{
			incCell();
			logBox[currPage][currCol][currRow]->setText(currTurn, V_RECLAIM, nat, targets[i], object);
		}
	}
}

void Log::addLogText(uint16_t t, WCHAR* cust)
{
	logBox[currPage][currCol][currRow]->setText(t, cust);

	incCell();
}

void Log::drawPage(HDC hdc, uint16_t page)
{
	Graphics graphics(hdc);

	for (int j = 0; j < logBox[page].size(); j++)
		for (int k = 0; k < logBox[page][j].size(); k++)
			logBox[page][j][k]->drawPair(graphics, linePen, turnFont, textFont, boldFont, &turnFormat, &textFormat, textBrush);
}

void Log::addCol()
{
	int page = 0;

	if (currCol == 0)
	{
		page = currPage;

		logBox[page].resize(2);
		logBox[page][1].resize(ROWS);

		for (int k = 0; k < ROWS; k++)
			logBox[page][1][k] = new LogPair((pane.right - pane.left) / 2 + 10, k, globalGame);
	}
	else
	{
		page = currPage + 2;
		newPage = true;

		logBox.resize(page);
		page--;
		logBox[page].resize(1);
		logBox[page][0].resize(ROWS);

		for (int k = 0; k < ROWS; k++)
			logBox[page][0][k] = new LogPair(pane.left + 10, k, globalGame);
	}
}

void Log::setCurrPage(int val)
{
	currPage = val;

	if (logBox.size() < ++val)
		logBox.resize(val);
}

void Log::setCurrCol(int val)
{
	currCol = val;

	for (int i = 0; i <= currPage; i++)
	{
		logBox[i].resize(2);
		logBox[i][0].resize(ROWS);
		logBox[i][1].resize(ROWS);

		if (i == currPage && val == 0)
			logBox[i].resize(1);
	}
}

void Log::setCurrRow(int val)
{
	currRow = val;

	if (val >= ROWS - 5)
	{
		if (currCol == 0)
		{
			logBox[currPage].resize(2);
			logBox[currPage][1].resize(ROWS);
		}
		else
		{
			int temp = currPage + 2;
			logBox.resize(temp);
			logBox[--temp].resize(1);
			logBox[temp][0].resize(ROWS);
		}
	}

	for (int i = 0; i < logBox.size(); i++)
	{
		// Col 0
		{
			for (int k = 0; k < ROWS; k++)
				logBox[i][0][k] = new LogPair(pane.left + 10, k, globalGame);
		}

		// Col 1
		if (logBox[i].size() == 2)
		{
			for (int k = 0; k < ROWS; k++)
				logBox[i][1][k] = new LogPair((pane.right - pane.left) / 2 + 10, k, globalGame);
		}
	}
}

void Log::setCurrTurn(int turn)
{
	currTurn = turn;
}

void Log::setCurrNat(int nat)
{
	currNat = nat;
}

void Log::setTrgtEx(bool val)
{
	tgtEx = val;
}

void Log::setTrgtPos(int page, int col, int row)
{
	tgtPos.page = page;
	tgtPos.col = col;
	tgtPos.row = row;
}

void Log::setResEx(bool val)
{
	resEx = val;
}

void Log::setResPos(int page, int col, int row)
{
	resPos.page = page;
	resPos.col = col;
	resPos.row = row;
}

void Log::setOccEx(bool val)
{
	occEx = val;
}

void Log::setOccPos(int page, int col, int row)
{
	occPos.page = page;
	occPos.col = col;
	occPos.row = row;
}

void Log::setCapEx(int nat, bool val)
{
	capEx[nat] = val;
}

void Log::setCapPos(int nat, int page, int col, int row)
{
	capPos[nat].page = page;
	capPos[nat].col = col;
	capPos[nat].row = row;
}

void Log::setLibEx(int obj, int ind, bool val)
{
	libEx[obj][ind] = val;
}

void Log::setLibPos(int obj, int ind, int page, int col, int row)
{
	libPos[obj][ind].page = page;
	libPos[obj][ind].col = col;
	libPos[obj][ind].row = row;
}

void Log::setRecEx(int nat, bool val)
{
	recEx[nat] = val;
}

void Log::setRecPos(int nat, int page, int col, int row)
{
	recPos[nat].page = page;
	recPos[nat].col = col;
	recPos[nat].row = row;
}

void Log::setTurn(int page, int col, int row, int val)
{
	logBox[page][col][row]->setTurn(val);
}

void Log::setVerb(int page, int col, int row, int val)
{
	logBox[page][col][row]->setVerb(val);
}

void Log::setSubj(int page, int col, int row, int val)
{
	logBox[page][col][row]->setSubj(val);
}

void Log::setTrgt(int page, int col, int row, int val)
{
	logBox[page][col][row]->setTrgt(val);
}

void Log::setObjt(int page, int col, int row, int val)
{
	logBox[page][col][row]->setObjt(val);
}

void Log::setIndr(int page, int col, int row, int val)
{
	logBox[page][col][row]->setIndr(val);
}

void Log::setCust(int page, int col, int row, int idx, char c)
{
	logBox[page][col][row]->setCust(idx, c);
}

void Log::reconstructText(int page, int col, int row)
{
	logBox[page][col][row]->reconstructText();
}

int Log::getCurrPage()
{
	return currPage;
}

int Log::getCurrCol()
{
	return currCol;
}

int Log::getCurrRow()
{
	return currRow;
}

int Log::getCurrTurn()
{
	return currTurn;
}

int Log::getCurrNat()
{
	return currNat;
}

bool Log::getTrgtEx()
{
	return tgtEx;
}

void Log::getTrgtPos(int& page, int& col, int& row)
{
	page = tgtPos.page;
	col = tgtPos.col;
	row = tgtPos.row;
}

bool Log::getResEx()
{
	return resEx;
}

void Log::getResPos(int& page, int& col, int& row)
{
	page = resPos.page;
	col = resPos.col;
	row = resPos.row;
}

bool Log::getOccEx()
{
	return occEx;
}

void Log::getOccPos(int& page, int& col, int& row)
{
	page = occPos.page;
	col = occPos.col;
	row = occPos.row;
}

bool Log::getCapEx(int nat)
{
	return capEx[nat];
}

void Log::getCapPos(int nat, int& page, int& col, int& row)
{
	page = capPos[nat].page;
	col = capPos[nat].col;
	row = capPos[nat].row;
}

bool Log::getLibEx(int obj, int ind)
{
	return libEx[obj][ind];
}

void Log::getLibPos(int obj, int ind, int& page, int& col, int& row)
{
	page = libPos[obj][ind].page;
	col =  libPos[obj][ind].col;
	row =  libPos[obj][ind].row;
}

bool Log::getRecEx(int nat)
{
	return recEx[nat];
}

void Log::getRecPos(int nat, int& page, int& col, int& row)
{
	page = recPos[nat].page;
	col  = recPos[nat].col;
	row  = recPos[nat].row;
}

int Log::getTurn(int page, int col, int row)
{
	return logBox[page][col][row]->getTurn();
}

int Log::getVerb(int page, int col, int row)
{
	return logBox[page][col][row]->getVerb();
}

int Log::getSubj(int page, int col, int row)
{
	return logBox[page][col][row]->getSubj();
}

int Log::getTrgtSize(int page, int col, int row)
{
	return logBox[page][col][row]->getTrgtSize();
}

int Log::getTrgt(int page, int col, int row, int idx)
{
	return logBox[page][col][row]->getTrgt(idx);
}

int Log::getObjt(int page, int col, int row)
{
	return logBox[page][col][row]->getObjt();
}

int Log::getIndr(int page, int col, int row)
{
	return logBox[page][col][row]->getIndr();
}

char Log::getCust(int page, int col, int row, int idx)
{
	return logBox[page][col][row]->getCust(idx);
}

void Log::incCell()
{
	currRow++;
	if (currRow == ROWS)
	{
		currRow = 0;

		if (currCol == 0)
			currCol++;
		else
		{
			currCol = 0;
			currPage++;
		}
	}
	else if (currRow > ROWS - 5) // Set up nex page/col
		addCol();
}

void Log::decCell()
{
	currRow--;
	if (currRow == -1)
	{
		currRow = ROWS - 1;

		if (currCol == 1)
			currCol--;
		else
		{
			currCol = 1;
			currPage--;
		}
	}
}

void Log::shiftCells(int page, int col, int row, int verb, int object, int indirect)
{
	int shifts = 0;
	int adj = 0;
	int pageIdx0 = currPage, colIdx0 = currCol, rowIdx0 = currRow;
	int pageIdx1 = currPage, colIdx1 = currCol, rowIdx1 = currRow - 1;
	bool newPage = false;
	bool newCol = false;

	if (page != currPage) // Page adjustment needed
	{
		adj = (currPage - page) * 2 * ROWS;
		newPage = true;

		if (col == 0 && currCol == 1) // Column adjustment
		{
			adj += ROWS;
			newCol = true;
		}
		else if (col == 1 && currCol == 0) // Column adjustment
		{
			adj -= ROWS;
			newCol = true;
		}
	}
	else if (col != currCol) // Column adjustment needed
	{
		adj = ROWS;
		newCol = true;
	}

	if (rowIdx0 == 0) // Ensure source index wraps
	{
		rowIdx1 = ROWS - 1;

		if (colIdx1 == 1)
		{
			colIdx1 = 0;
		}
		else
		{
			colIdx1 = 1;
			pageIdx1--;
		}
	}

	shifts = rowIdx0 + adj - row - 1;

	for (int i = 0; i < shifts; i++)
	{
		int tempVerb = logBox[pageIdx1][colIdx1][rowIdx1]->getVerb();
		int tempObjt = logBox[pageIdx1][colIdx1][rowIdx1]->getObjt();
		int tempIndr = logBox[pageIdx1][colIdx1][rowIdx1]->getIndr();
		switch (tempVerb)
		{
		case V_CAPTURE:
		{
			if (capPos[tempObjt].row == rowIdx1) // Only adjust indices to the current position
			{
				capPos[tempObjt].page = pageIdx0; capPos[tempObjt].col = colIdx0; capPos[tempObjt].row = rowIdx0;
			}

			break;
		}
		case V_LIBERATE:
		{
			if (libPos[tempObjt][tempIndr].row == rowIdx1) // Only adjust indices to the current position
			{
				libPos[tempObjt][tempIndr].page = pageIdx0; libPos[tempObjt][tempIndr].col = colIdx0; libPos[tempObjt][tempIndr].row = rowIdx0;
			}

			break;
		}
		case V_RECLAIM:
		{
			if (recPos[tempObjt].row == rowIdx1) // Only adjust indices to the current position
			{
				recPos[tempObjt].page = pageIdx0; recPos[tempObjt].col = colIdx0; recPos[tempObjt].row = rowIdx0;
			}

			break;
		}
		case V_OCCUPY:
		{
			if (occPos.row == rowIdx1)
			{
				occPos.page = pageIdx0; occPos.col = colIdx0; occPos.row = rowIdx0;
			}

			break;
		}
		case V_RESEARCH:
		{
			resPos.page = pageIdx0; resPos.col = colIdx0; resPos.row = rowIdx0;

			break;
		}
		default:
			break;
		}

		logBox[pageIdx0][colIdx0][rowIdx0]->cpy(logBox[pageIdx1][colIdx1][rowIdx1]);
		logBox[pageIdx1][colIdx1][rowIdx1]->clear();

		pageIdx0 = pageIdx1; colIdx0 = colIdx1; rowIdx0 = rowIdx1;

		if (rowIdx1 == 0)
		{
			rowIdx1 = ROWS - 1;

			if (colIdx1 == 0)
			{
				colIdx1 = 1;
				pageIdx1--;
			}
			else
				colIdx1 = 0;
		}
		else
		{
			rowIdx1--;
		}
	}

	switch (verb)
	{
	case V_CAPTURE:
	{
		capPos[object].page = currPage;

		if (row == ROWS - 1)
		{
			capPos[object].row = 0;

			if (col == 0)
				capPos[object].col = 1;
			else
			{
				capPos[object].col = 0;
				capPos[object].page++;
			}
		}
		else
		{
			capPos[object].row++;
		}

		break;
	}
	case V_LIBERATE:
	{
		libPos[object][indirect].page = currPage;

		if (row == ROWS - 1)
		{
			libPos[object][indirect].row = 0;

			if (col == 0)
				libPos[object][indirect].col = 1;
			else
			{
				libPos[object][indirect].col = 0;
				libPos[object][indirect].page++;
			}
		}
		else
		{
			libPos[object][indirect].row++;
		}

		break;
	}
	case V_RECLAIM:
	{
		recPos[object].page = currPage;

		if (row == ROWS - 1)
		{
			recPos[object].row = 0;

			if (col == 0)
				recPos[object].col = 1;
			else
			{
				recPos[object].col = 0;
				recPos[object].page++;
			}
		}
		else
		{
			recPos[object].row++;
		}

		break;
	}
	case V_OCCUPY:
	{
		occPos.page = currPage;

		if (row == ROWS - 1)
		{
			occPos.row = 0;

			if (col == 0)
				occPos.col = 1;
			else
			{
				occPos.col = 0;
				occPos.page++;
			}
		}
		else
		{
			occPos.row++;
		}

		break;
	}
	case V_RESEARCH:
	{
		resPos.page = currPage;

		if (row == ROWS - 1)
		{
			resPos.row = 0;

			if (col == 0)
				resPos.col = 1;
			else
			{
				resPos.col = 0;
				resPos.page++;
			}
		}
		else
		{
			resPos.row++;
		}

		break;
	}
	default:
		break;
	}

	incCell();
}

void Log::shiftCellsBack(int page, int col, int row)
{
	// If this box was a saved index, either adjust back or clear
	int oldSubj = logBox[page][col][row]->getSubj();
	int oldVerb = logBox[page][col][row]->getVerb();
	int oldObjt = logBox[page][col][row]->getObjt();
	int oldIndr = logBox[page][col][row]->getIndr();
	int prevPage, prevCol, prevRow;
	if (row != 0)
	{
		prevPage = page;
		prevCol = col;
		prevRow = row - 1;
	}
	else
	{
		if (col != 0)
		{
			prevPage = page;
			prevCol = 0;
		}
		else
		{
			prevPage = page - 1;
			prevCol = 1;
		}
		prevRow = ROWS - 1;
	}
	switch (oldVerb)
	{
	case V_CAPTURE:
	{
		if (capPos[oldObjt].page == page && capPos[oldObjt].col == col && capPos[oldObjt].row == row)
		{
			if (logBox[prevPage][prevCol][prevRow]->getSubj() == oldSubj && logBox[prevPage][prevCol][prevRow]->getVerb() == oldVerb &&
				logBox[prevPage][prevCol][prevRow]->getObjt() == oldObjt)
			{
				capPos[oldObjt].page = prevPage; capPos[oldObjt].col = prevCol; capPos[oldObjt].row = prevRow;
			}
			else
			{
				capEx[oldObjt] = false;
			}
		}
		break;
	}
	case V_LIBERATE:
	{
		if (libPos[oldObjt][oldIndr].page == page && libPos[oldObjt][oldIndr].col == col && libPos[oldObjt][oldIndr].row == row)
		{
			if (logBox[prevPage][prevCol][prevRow]->getSubj() == oldSubj && logBox[prevPage][prevCol][prevRow]->getVerb() == oldVerb &&
				logBox[prevPage][prevCol][prevRow]->getObjt() == oldObjt && logBox[prevPage][prevCol][prevRow]->getObjt() == oldIndr)
			{
				libPos[oldObjt][oldIndr].page == prevPage && libPos[oldObjt][oldIndr].col == prevCol && libPos[oldObjt][oldIndr].row == prevRow;
			}
			else
			{
				libEx[oldObjt][oldIndr] = false;
			}
		}
		break;
	}
	case V_RECLAIM:
	{
		if (recPos[oldObjt].page == page && recPos[oldObjt].col == col && recPos[oldObjt].row == row)
		{
			if (logBox[prevPage][prevCol][prevRow]->getSubj() == oldSubj && logBox[prevPage][prevCol][prevRow]->getVerb() == oldVerb &&
				logBox[prevPage][prevCol][prevRow]->getObjt() == oldObjt)
			{
				recPos[oldObjt].page == prevPage && recPos[oldObjt].col == prevCol && recPos[oldObjt].row == prevRow;
			}
			else
			{
				recEx[oldObjt] = false;
			}
		}
		break;
	}
	case V_OCCUPY:
	{
		if (occPos.page == page && occPos.col == col && occPos.row == row)
		{
			if (logBox[prevPage][prevCol][prevRow]->getSubj() == oldSubj && logBox[prevPage][prevCol][prevRow]->getVerb() == oldVerb)
			{
				occPos.page == prevPage && occPos.col == prevCol && occPos.row == prevRow;
			}
			else
			{
				occEx = false;
			}
		}
		break;
	}
	case V_RESEARCH:
	{
		if (resPos.page == page && resPos.col == col && resPos.row == row)
		{
			if (logBox[prevPage][prevCol][prevRow]->getSubj() == oldSubj && logBox[prevPage][prevCol][prevRow]->getVerb() == oldVerb)
			{
				resPos.page == prevPage && resPos.col == prevCol && resPos.row == prevRow;
			}
			else
			{
				resEx = false;
			}
		}
		break;
	}
	default:
		break;
	}
	
	// Clear the base cell
	logBox[page][col][row]->clear();

	int shifts = 0;
	int adj = 0;
	int pageIdx0 = page, colIdx0 = col, rowIdx0 = row;
	int pageIdx1 = page, colIdx1 = col, rowIdx1 = row + 1;

	if (page != currPage) // Page adjustment needed
	{
		adj = (currPage - page) * 2 * ROWS;

		if (col == 0 && currCol == 1) // Column adjustment
		{
			adj += ROWS;
		}
		else if (col == 1 && currCol == 0) // Column adjustment
		{
			adj -= ROWS;
		}
	}
	else if (col != currCol) // Column adjustment needed
	{
		adj = ROWS;
	}

	if (rowIdx0 == ROWS - 1) // Ensure source index wraps
	{
		rowIdx1 = 0;

		if (colIdx1 == 1)
		{
			colIdx1 = 0;
			pageIdx1++;
		}
		else
		{
			colIdx1 = 0;
		}
	}

	shifts = currRow - rowIdx0 + adj - 1;

	for (int i = 0; i < shifts; i++)
	{
		int tempVerb = logBox[pageIdx1][colIdx1][rowIdx1]->getVerb();
		int tempObjt = logBox[pageIdx1][colIdx1][rowIdx1]->getObjt();
		int tempIndr = logBox[pageIdx1][colIdx1][rowIdx1]->getIndr();
		switch (tempVerb)
		{
		case V_CAPTURE:
		{
			if (capPos[tempObjt].row == rowIdx1) // Only adjust indices to the current position
			{
				capPos[tempObjt].page = pageIdx0; capPos[tempObjt].col = colIdx0; capPos[tempObjt].row = rowIdx0;
			}

			break;
		}
		case V_LIBERATE:
		{
			if (libPos[tempObjt][tempIndr].row == rowIdx1) // Only adjust indices to the current position
			{
				libPos[tempObjt][tempIndr].page = pageIdx0; libPos[tempObjt][tempIndr].col = colIdx0; libPos[tempObjt][tempIndr].row = rowIdx0;
			}

			break;
		}
		case V_RECLAIM:
		{
			if (recPos[tempObjt].row == rowIdx1) // Only adjust indices to the current position
			{
				recPos[tempObjt].page = pageIdx0; recPos[tempObjt].col = colIdx0; recPos[tempObjt].row = rowIdx0;
			}

			break;
		}
		case V_OCCUPY:
		{
			if (occPos.row == rowIdx1)
			{
				occPos.page = pageIdx0; occPos.col = colIdx0; occPos.row = rowIdx0;
			}

			break;
		}
		case V_RESEARCH:
		{
			if (resPos.row == rowIdx1)
			{
				resPos.page = pageIdx0; resPos.col = colIdx0; resPos.row = rowIdx0;
			}

			break;
		}
		default:
			break;
		}

		logBox[pageIdx0][colIdx0][rowIdx0]->cpy(logBox[pageIdx1][colIdx1][rowIdx1]);
		logBox[pageIdx1][colIdx1][rowIdx1]->clear();

		pageIdx0 = pageIdx1; colIdx0 = colIdx1; rowIdx0 = rowIdx1;

		if (rowIdx1 == ROWS - 1)
		{
			rowIdx1 = 0;

			if (colIdx1 == 1)
			{
				colIdx1 = 0;
				pageIdx1++;
			}
			else
				colIdx1 = 1;
		}
		else
		{
			rowIdx1++;
		}
	}

	decCell();
}

void Log::adjustLog(int currOwn, int origOwn, vector<int> &targets)
{
	for (int i = 0; i < 10; i++)
	{
		if (capEx[i]) // At least one territory captured from a particular nation
		{
			// Also have to look back at logs immediately previous in the case of a shift
			bool cont = true;

			int p = capPos[i].page;
			int c = capPos[i].col;
			int r = capPos[i].row;
			int t0 = logBox[p][c][r]->getTurn();

			while (cont)
			{
				if (anyInList(targets, p, c, r)) // This log contains at least one territory in the list
				{
					int size = logBox[p][c][r]->getTrgtSize();

					for (int j = 0; j < size; j++)
					{
						int trgt = logBox[p][c][r]->getTrgt(j);
						int turn = logBox[p][c][r]->getTurn();

						if (isInList(targets, trgt))
						{
							logBox[p][c][r]->removeTrgt(trgt);
							j--; size--; // Adjust loop index

							addLogText(turn, V_LIBERATE, currOwn, trgt, i, origOwn);

							removeFromList(targets, trgt);
						}
					}

					size = logBox[p][c][r]->getTrgtSize(); // Delete box if all targets have been removed from it
					if (size == 0)
					{
						shiftCellsBack(p, c, r);
					}
				}

				if (r == 0)
				{
					r = ROWS - 1;

					if (c == 0)
					{
						c = 1;
						p--;
					}
					else
						c = 0;
				}
				else
					r--;

				int t = logBox[p][c][r]->getTurn();
				int v = logBox[p][c][r]->getVerb();
				int s = logBox[p][c][r]->getSubj();
				int o = logBox[p][c][r]->getObjt();
				if (t == t0 && v == V_CAPTURE && s == currOwn && o == i)
					cont = true; // Current log was a shift of the previous one
				else
					cont = false; // Previous log is something else, move on
			}
		}
	}

	// Whatever is left was captured on a previous turn
	for (int i = 0; i < targets.size(); i++)
		addLogText(currTurn, V_LIBERATE, currOwn, targets[i], currOwn, origOwn);
}

void Log::adjustLogAllies(int libNat, vector<vector<int>>& targets)
{
	for (int i = 0; i < 10; i++)
	{
		if (targets[i].size() > 0) // At least one territory reclaimed from allied nation
		{
			addLogText(libNat, targets[i], i);
			incCell();
		}
	}
}

bool Log::isInList(vector<int> targets, int trgt)
{
	for (int i = 0; i < targets.size(); i++)
		if (targets[i] == trgt)
			return true;

	return false;
}

bool Log::allInList(vector<int> targets, int p, int c, int r)
{
	int size = logBox[p][c][r]->getTrgtSize();

	for (int i = 0; i < size; i++)
	{
		int trgt = logBox[p][c][r]->getTrgt(i);

		if (!isInList(targets, trgt))
			return false;
	}

	return true;
}

bool Log::anyInList(vector<int> targets, int p, int c, int r)
{
	int size = logBox[p][c][r]->getTrgtSize();

	for (int i = 0; i < size; i++)
	{
		int trgt = logBox[p][c][r]->getTrgt(i);

		if (isInList(targets, trgt))
			return true;
	}

	return false;
}

void Log::removeFromList(vector<int>& targets, int trgt)
{
	for (int i = 0; i < targets.size(); i++)
	{
		if (targets[i] == trgt)
			targets.erase(targets.begin() + i);
	}
}

void Log::removeFromList(vector<int>& targets, int p, int c, int r)
{
	int size = logBox[p][c][r]->getTrgtSize();

	for (int i = 0; i < size; i++)
	{
		int trgt = logBox[p][c][r]->getTrgt(i);

		for (int j = 0; j < targets.size(); j++)
			if (targets[j] == trgt)
				targets.erase(targets.begin() + j);
	}
}

int Log::getNewPage()
{
	if (newPage)
	{
		newPage = false;
		return logBox.size();
	}
	else
		return 0;
}
