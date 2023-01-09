#include "../header/LogPair.h"
#include "../header/LogText.h"

LogPair::LogPair(int left, int top, bool global)
{
	turnPos = new RectF(left, YOFFSET + (top * CELLHEIGHT), TURNWIDTH, CELLHEIGHT);
	textPos = new RectF(left + TURNWIDTH, YOFFSET + (top * CELLHEIGHT), TEXTWIDTH, CELLHEIGHT);

	textBox0 = new RectF(textPos->X + 3, textPos->Y, TEXTWIDTH, CELLHEIGHT / 2);
	textBox1 = new RectF(textPos->X + 3, textPos->X + (CELLHEIGHT / 2), TEXTWIDTH, CELLHEIGHT / 2);

	for (int i = 0; i < 10; i++)
		turn[i] = '\0';

	text[0] = ' ';
	for (int i = 1; i < TEXTLEN; i++)
		text[i] = '\0';
	text_len = 0;

	_turn = 0;
	_verb = V_BLANK;
	_subj = TURN_NON;
	_trgt.resize(0);
	_objt = TURN_NON;
	_indr = TURN_NON;

	_set = false;

	gerBrushP = new SolidBrush(Color(77,  93,  83));  // 
	sovBrushP = new SolidBrush(Color(255, 26,  0));	  // 
	jpnBrushP = new SolidBrush(Color(188, 0,   45));  // 
	usaBrushP = new SolidBrush(Color(107, 142, 35));  // 
	chnBrushP = new SolidBrush(Color(0,   0,   149)); // 
	ukBrushP  = new SolidBrush(Color(196, 188, 115)); // 240, 230, 140
	itaBrushP = new SolidBrush(Color(0,   140, 69));  // 
	anzBrushP = new SolidBrush(Color(47,  87,  21));  // 
	fraBrushP = new SolidBrush(Color(0,   114, 187)); // 

	globalGame = global;
	text_pos = 0;
}

LogPair::~LogPair()
{
	delete turnPos;
	delete textPos;

	delete textBox0; delete textBox1;

	delete gerBrushP; delete sovBrushP; delete jpnBrushP;
	delete usaBrushP; delete chnBrushP; delete ukBrushP;
	delete itaBrushP; delete anzBrushP; delete fraBrushP;
}

void LogPair::drawPair(Graphics& graphics, Pen* pen, Font* turnFont, Font* textFont, Font* boldFont, StringFormat* sf0, StringFormat* sf1, SolidBrush* brush)
{
	graphics.DrawRectangle(pen, *turnPos);
	graphics.DrawRectangle(pen, *textPos);

	graphics.DrawString(turn, -1, turnFont, *turnPos, sf0, brush);

	// Make much more complicated so we can have COLORFUL fonts!
	delete textBox0; delete textBox1;
	textBox0 = new RectF(textPos->X + 3, textPos->Y, TEXTWIDTH - 3, CELLHEIGHT / 2);
	textBox1 = new RectF(textPos->X + 3, textPos->Y + (CELLHEIGHT / 2), TEXTWIDTH - 3, CELLHEIGHT / 2);
	RectF* bounds = new RectF(0, 0, 0, 0);

	int subjLen = getAdjNatLen(_subj);
	RectF* whichBox = textBox0;
	text_pos = 0;
	switch (_verb)
	{
	case V_SETUP: 
	{
		graphics.DrawString(setup, setup_len, textFont, *textBox0, sf1, brush);
		break;
	}
	case V_CUSTOM:
	{
		graphics.DrawString(text, -1, textFont, *textPos, sf1, brush);
		break;
	}
	case V_WAR:
	{
		// Subject
		subjLen = getAdjNatLen(_subj, true);
		graphics.DrawString(nats[_subj], subjLen, boldFont, *textBox0, sf1, setBrushColor(_subj, brush));
		graphics.MeasureString(nats[_subj], subjLen, boldFont, *textBox0, bounds);
		adjustBounds(whichBox, bounds, C_WAR_SUBJ);

		// Declares War on
		graphics.DrawString(war, war_len, textFont, *textBox0, sf1, brush);
		graphics.MeasureString(war, war_len, boldFont, *textBox0, bounds);
		adjustBounds(whichBox, bounds, C_WAR_VERB);

		// No need to check for new lines, can't declare war on that many nations
		for (int i = 0; i < _trgt.size(); i++)
		{
			// Targets
			int trgt_len = getAdjNatLen(_trgt[i], true); // Cut out the Europe/Pacific indicator for UK
			graphics.DrawString(nats[_trgt[i]], trgt_len, boldFont, *textBox0, sf1, setBrushColor(_trgt[i], brush));
			graphics.MeasureString(nats[_trgt[i]], trgt_len, boldFont, *textBox0, bounds);
			adjustBounds(whichBox, bounds, C_WAR_TRGT, _trgt[i]);

			bool hadComma = false;

			if (i < _trgt.size() - 1 && _trgt.size() > 2)
			{
				// comma
				hadComma = true;
				graphics.DrawString(com, com_len, textFont, *textBox0, sf1, brush);
				graphics.MeasureString(com, com_len, textFont, *textBox0, bounds);
				adjustBounds(whichBox, bounds);
			}
			if (i == _trgt.size() - 2 && _trgt.size() > 1)
			{
				// and
				if (hadComma)
					adjustBounds(whichBox, bounds, C_WAR_AND_);
				else
					adjustBounds(whichBox, bounds, C_WAR_AND__);
				graphics.DrawString(and_, and_len, textFont, *textBox0, sf1, brush);
				graphics.MeasureString(and_, and_len, textFont, *textBox0, bounds);
				adjustBounds(whichBox, bounds, C_WAR_AND);
			}

			// period
			if (i == _trgt.size() - 1)
				graphics.DrawString(end, end_len, textFont, *textBox0, sf1, brush);
		}
		break;
	}
	case V_CAPTURE:
	{
		// Subject
		addText(graphics, nats[_subj], subjLen, boldFont, *whichBox, bounds, sf1, setBrushColor(_subj, brush), true, C_CAP_SUBJ);

		// Captures
		addText(graphics, capture, capture_len, textFont, *whichBox, bounds, sf1, brush);

		// Targets
		for (int i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				addText(graphics, ters_com[_trgt[i]], ters_com_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);
			else // Doesn't need a comma
				addText(graphics, ters[_trgt[i]], ters_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);
			
			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Second to last in a list, needs an and
				addText(graphics, and_, and_len, textFont, *whichBox, bounds, sf1, brush);
		}

		// From
		addText(graphics, from, from_len, textFont, *whichBox, bounds, sf1, brush, true, C_CAP_FROM);

		// Object
		addText(graphics, nats[_objt], nats_len[_objt], boldFont, *whichBox, bounds, sf1, setBrushColor(_objt, brush), true, C_CAP_OBJT);

		// End
		graphics.DrawString(end, end_len, textFont, *whichBox, sf1, brush);
		break;
	}
	case V_LIBERATE:
	{
		// Subject
		addText(graphics, nats[_subj], subjLen, boldFont, *whichBox, bounds, sf1, setBrushColor(_subj, brush), true, C_LIB_SUBJ);

		// Liberates
		addText(graphics, liberate, liberate_len, textFont, *whichBox, bounds, sf1, brush);

		// Targets
		for (int i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				addText(graphics, ters_com[_trgt[i]], ters_com_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);
			else // Doesn't need a comma
				addText(graphics, ters[_trgt[i]], ters_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);

			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Second to last in a list, needs an and
				addText(graphics, and_, and_len, textFont, *whichBox, bounds, sf1, brush);
		}

		// From
		addText(graphics, from, from_len, textFont, *whichBox, bounds, sf1, brush, true, C_LIB_FROM);

		// Object
		addText(graphics, nats[_objt], nats_len[_objt], boldFont, *whichBox, bounds, sf1, setBrushColor(_objt, brush), true, C_LIB_OBJT);

		// For
		addText(graphics, for_, for_len, textFont, *whichBox, bounds, sf1, brush, true);

		// Indirect Object
		addText(graphics, nats[_indr], nats_len[_indr], boldFont, *whichBox, bounds, sf1, setBrushColor(_indr, brush), true, C_LIB_INDR);

		graphics.DrawString(end, end_len, textFont, *whichBox, sf1, brush);
		break;
	}
	case V_RECLAIM:
	{
		// Subject
		addText(graphics, nats[_subj], subjLen, boldFont, *whichBox, bounds, sf1, setBrushColor(_subj, brush), true, C_REC_SUBJ);

		// Liberates
		addText(graphics, reclaim, reclaim_len, textFont, *whichBox, bounds, sf1, brush);

		// Targets
		for (int i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				addText(graphics, ters_com[_trgt[i]], ters_com_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);
			else // Doesn't need a comma
				addText(graphics, ters[_trgt[i]], ters_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);

			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Second to last in a list, needs an and
				addText(graphics, and_, and_len, textFont, *whichBox, bounds, sf1, brush);
		}

		// From
		addText(graphics, from, from_len, textFont, *whichBox, bounds, sf1, brush, true, C_REC_FROM);

		// Object
		addText(graphics, nats[_objt], nats_len[_objt], boldFont, *whichBox, bounds, sf1, setBrushColor(_objt, brush), true, C_REC_OBJT);

		graphics.DrawString(end, end_len, textFont, *whichBox, sf1, brush);
		break;
	}
	case V_OCCUPY:
	{
		// Subject
		addText(graphics, nats[_subj], subjLen, boldFont, *whichBox, bounds, sf1, setBrushColor(_subj, brush), true, C_OCC_SUBJ);

		// Occupies
		addText(graphics, occupy, occupy_len, textFont, *whichBox, bounds, sf1, brush);

		// Targets
		for (int i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				addText(graphics, ters_com[_trgt[i]], ters_com_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);
			else // Doesn't need a comma
				addText(graphics, ters[_trgt[i]], ters_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);

			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Second to last in a list, needs an and
				addText(graphics, and_, and_len, textFont, *whichBox, bounds, sf1, brush);
		}

		// End
		addText(graphics, end, end_len, textFont, *whichBox, bounds, sf1, brush, true);
		break;
	}
	case V_RESEARCH:
	{
		// Subject
		addText(graphics, nats[_subj], subjLen, boldFont, *whichBox, bounds, sf1, setBrushColor(_subj, brush), true, C_OCC_SUBJ);

		// Discovers
		addText(graphics, discover, discover_len, textFont, *whichBox, bounds, sf1, brush);

		// Targets
		for (int i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				addText(graphics, techs_com[_trgt[i]], techs_com_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);
			else // Doesn't need a comma
				addText(graphics, techs[_trgt[i]], techs_len[_trgt[i]], textFont, *whichBox, bounds, sf1, brush);

			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Second to last in a list, needs an and
				addText(graphics, and_, and_len, textFont, *whichBox, bounds, sf1, brush);
		}

		// End
		addText(graphics, end, end_len, textFont, *whichBox, bounds, sf1, brush, true);
		break;
	}
	case V_NEUTRAL:
	{
		graphics.DrawString(strictNeutral, strictNeutral_len, textFont, *textBox0, sf1, brush);
		break;
	}
	case V_NEUTRAL_AXIS:
	{
		graphics.DrawString(axisNeutral, axisNeutral_len, textFont, *textBox0, sf1, brush);
		break;
	}
	case V_NEUTRAL_ALLY:
	{
		graphics.DrawString(allyNeutral, allyNeutral_len, textFont, *textBox0, sf1, brush);
		break;
	}
	case V_MONGOLIA:
	{
		graphics.DrawString(mongNeutral, mongNeutral_len, textFont, *textBox0, sf1, brush);
		break;
	}
	default:
		break;
	}

	delete bounds;
}

void LogPair::setText(int t, int verb)
{
	setText(t, verb, 0, 0, 0);
}

void LogPair::setText(uint16_t t, int verb, int subject, vector<int>* target, int object)
{
	for (int i = 0; i < target->size(); i++)
		setText(t, verb, subject, (*target)[i], object);
}

bool LogPair::setText(uint16_t t, int verb, int subject, int target, int object, int indir, bool add)
{
	if (!_set)
	{
		_turn = t;
		_verb = verb;
		setTurn();
	}

	int i = 0; int j = 0;
	
	// Filter out start of game
	if (verb == V_SETUP || verb == V_NEUTRAL)
		return true;
	else if (verb == V_NEUTRAL_AXIS || verb == V_NEUTRAL_ALLY || verb == V_MONGOLIA) // Filter out neutral leaning changes
		return true;
	else if (verb == V_CUSTOM) // Filter out custom logs
		return true;
	else if (add)
	{
		if (!_set)
		{
			_subj = subject;
			_objt = object;
			_indr = indir;
		}
		_trgt.push_back(target);
	}

	// Subject
	text_len = getAdjNatLen(subject);

	// Verb
	switch (verb)
	{
	case V_WAR:
	{
		// Can't max out length, no need to calculate length
		break;
	}
	case V_CAPTURE:
	{
		// Captures
		text_len += capture_len;

		// Targets
		for (i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				text_len += ters_com_len[_trgt[i]];
			else // Does not need a comma
				text_len += ters_len[_trgt[i]];
			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Needs an and
				text_len += and_len;
		}

		// From
		text_len += from_len;

		// Object
		text_len += getAdjNatLen(object);
		text_len += end_len;

		break;
	}
	case V_LIBERATE:
	{
		// Liberates
		text_len += liberate_len;

		// Targets
		for (i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				text_len += ters_com_len[_trgt[i]];
			else // Does not need a comma
				text_len += ters_len[_trgt[i]];
			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Needs an and
				text_len += and_len;
		}

		// Object
		if (_objt != _subj)
		{
			text_len += from_len;
			text_len += getAdjNatLen(object);
		}

		// Indirect object
		text_len += for_len;
		text_len += getAdjNatLen(indir);

		text_len += end_len;
		break;
	}
	case V_RECLAIM:
	{
		// Reclaims
		text_len += reclaim_len;

		// Targets
		for (i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				text_len += ters_com_len[_trgt[i]];
			else // Does not need a comma
				text_len += ters_len[_trgt[i]];
			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Needs an and
				text_len += and_len;
		}

		// Object
		if (_objt != _subj)
		{
			text_len += from_len;
			text_len += getAdjNatLen(object);
		}

		text_len += end_len;
		break;
	}
	case V_OCCUPY:
	{
		// Occupies
		text_len += occupy_len;

		// Targets
		for (i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				text_len += ters_com_len[_trgt[i]];
			else // Does not need a comma
				text_len += ters_len[_trgt[i]];
			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Needs an and
				text_len += and_len;
		}

		text_len += end_len;
		break;
	}
	case V_RESEARCH:
	{
		// Discovers
		text_len += discover_len;

		// Targets
		for (i = 0; i < _trgt.size(); i++)
		{
			if (i < _trgt.size() - 1 && _trgt.size() > 2) // Needs a comma
				text_len += techs_com_len[_trgt[i]];
			else // Does not need a comma
				text_len += techs_len[_trgt[i]];
			if (i == _trgt.size() - 2 && _trgt.size() > 1) // Needs an and
				text_len += and_len;
		}

		text_len += end_len;
		break;
	}
	default: break;
	}

	_set = true;
	
	return false;
}

void LogPair::setText(uint16_t t, WCHAR* cust)
{
	_turn = t;
	_verb = V_CUSTOM;

	setTurn();

	int i = 1;

	text[0] = ' ';
	while (cust[i - 1] != '\0')
	{
		text[i] = cust[i - 1];
		i++;
	}
}

void LogPair::cpy(LogPair *src)
{
	for (int i = 0; i < 10; i++)
		this->turn[i] = src->turn[i];

	this->_turn = src->_turn;
	this->_verb = src->_verb;
	this->_subj = src->_subj;
	for (int i = 0; i < src->_trgt.size(); i++)
		this->_trgt.push_back(src->_trgt[i]);
	this->_objt = src->_objt;
	this->_indr = src->_indr;

	if (this->_verb == V_CUSTOM)
		for (int i = 0; i < TEXTLEN; i++)
			this->text[i] = src->text[i];

	this->_set = src->_set;

	this->text_len = src->text_len;
}

void LogPair::setTurn()
{
	uint16_t hund = 0, tens = 0;

	turn[0] = ' ';  turn[1] = 'T'; turn[2] = 'u'; turn[3] = 'r'; turn[4] = 'n'; turn[5] = ' ';
	turn[6] = ' '; turn[7] = ' '; turn[8] = ' ';

	if (_turn > 99)
	{
		turn[6] = uint2char_(_turn / 100);
		turn[7] = uint2char_((_turn % 100) / 10);
		turn[8] = uint2char_(_turn % 10);
	}
	else
	{
		if (_turn > 9)
		{
			turn[6] = uint2char_((_turn % 100) / 10);
			turn[7] = uint2char_(_turn % 10);
		}
		else
			turn[6] = uint2char_(_turn % 10);
	}
}

void LogPair::setTurn(int val)
{
	_turn = val;
}

void LogPair::setVerb(int val)
{
	_verb = val;
}

void LogPair::setSubj(int val)
{
	_subj = val;
}

void LogPair::setTrgt(int val)
{
	_trgt.push_back(val);
}

void LogPair::setObjt(int val)
{
	_objt = val;
}

void LogPair::setIndr(int val)
{
	_indr = val;
}

void LogPair::setCust(int idx, char c)
{
	text[idx] = c;
}

void LogPair::reconstructText()
{
	setText(_turn, _verb, _subj, 0, _objt, _indr, false);
}

int LogPair::getTurn()
{
	return _turn;
}

int LogPair::getVerb()
{
	return _verb;
}

int LogPair::getSubj()
{
	return _subj;
}

int LogPair::getTrgtSize()
{
	return _trgt.size();
}

int LogPair::getTrgt(int idx)
{
	return _trgt[idx];
}

int LogPair::getObjt()
{
	return _objt;
}

int LogPair::getIndr()
{
	return _indr;
}

char LogPair::getCust(int idx)
{
	if (idx < TEXTLEN && _verb == V_CUSTOM)
		return text[idx];
	else return '\0';
}

bool LogPair::getHasSubj()
{
	if (_verb != V_CUSTOM && _verb != V_SETUP)
		return true;
	else
		return false;
}

bool LogPair::getHasObjt()
{
	if (_verb != V_CUSTOM && _verb != V_SETUP)
		if (_verb == V_CAPTURE || _verb == V_LIBERATE)
			return true;
	return false;
}

bool LogPair::hasTrgt(int target)
{
	for (int i = 0; i < _trgt.size(); i++)
		if (_trgt[i] == target)
			return true;

	return false;
}

void LogPair::removeTrgt(int target)
{
	for (int i = 0; i < _trgt.size(); i++)
		if (_trgt[i] == target)
			_trgt.erase(_trgt.begin() + i);

	reconstructText();
}

bool LogPair::isSpace(int verb, int target)
{
	int len = 0;

	switch (verb)
	{
	case V_CAPTURE: case V_LIBERATE: case V_OCCUPY:
	{
		len = ters_len[target];
		break;
	}
	case V_RESEARCH:
	{
		len = techs_len[target];
		break;
	}
	}

	len += 25; // Give it plenty of margin

	if (text_len + len > TEXTLEN)
		return false;

	return true;
}

void LogPair::clear()
{
	for (int i = 0; i < 10; i++)
		turn[i] = '\0';

	text[0] = ' ';
	for (int i = 1; i < TEXTLEN; i++)
		text[i] = '\0';

	_turn = 0;
	_verb = V_BLANK;
	_subj = TURN_NON;
	_trgt.resize(0);
	_objt = TURN_NON;
	_indr = TURN_NON;

	_set = false;

	text_len = 0;
}

void LogPair::clear_text()
{
	for (int i = 0; i < TEXTLEN; i++)
		text[i] = '\0';
}

SolidBrush* LogPair::setBrushColor(int nat, SolidBrush* textBrush)
{
	switch (nat)
	{
	case TURN_GER:
		return gerBrushP;
	case TURN_SOV:
		return sovBrushP;
	case TURN_JPN:
		return jpnBrushP;
	case TURN_USA:
		return usaBrushP;
	case TURN_CHN:
		return chnBrushP;
	case TURN_UKE: case TURN_UKP:
		return ukBrushP;
	case TURN_ITA:
		return itaBrushP;
	case TURN_ANZ:
		return anzBrushP;
	case TURN_FRA:
		return fraBrushP;
	default:
		return textBrush;
	}
}

void LogPair::roundBounds(RectF* bounds)
{
	bounds->X = ceil(bounds->X);
	bounds->Width = ceil(bounds->Width);
}

void LogPair::adjustBounds(RectF* whichBox, RectF* bounds, int adjCode, int trgtId)
{
	bool preAdj = false;

	switch (adjCode)
	{
	case C_WAR_SUBJ: case C_CAP_SUBJ: case C_LIB_SUBJ: case C_REC_SUBJ: case C_OCC_SUBJ:
	{
		whichBox->X -= 3;
		whichBox->Width += 3;

		if (trgtId == TURN_UKE || trgtId == TURN_UKP)
		{
			whichBox->X -= 2;
			whichBox->Width += 2;
		}

		break;
	}
	case C_WAR_VERB:
	{
		whichBox->X += 2;
		whichBox->Width -= 2;
		break;
	}
	case C_WAR_TRGT:
	{
		whichBox->X -= 6;
		whichBox->Width += 6;

		if (trgtId == TURN_UKE || trgtId == TURN_UKP)
		{
			whichBox->X -= 2;
			whichBox->Width += 2;
		}
		if (trgtId == TURN_USA)
		{
			whichBox->X -= 1;
			whichBox->Width += 1;
		}
		break;
	}
	case C_WAR_AND__:
	{
		whichBox->X += 3;
		whichBox->Width -= 3;
		preAdj = true;
		break;
	}
	case C_WAR_AND_:
	{
		whichBox->X -= 3;
		whichBox->Width += 3;
		preAdj = true;
		break;
	}
	case C_WAR_AND:
	{
		whichBox->X += 2;
		whichBox->Width -= 2;
		break;
	}
	case C_CAP_VERB:
	{
		whichBox->X += 1;
		whichBox->Width -= 1;
		break;
	}
	case C_CAP_AND:
	{
		whichBox->X += 2;
		whichBox->Width -= 2;
		break;
	}
	case C_CAP_FROM: case C_LIB_FROM: case C_REC_FROM:
	{
		whichBox->X += 2;
		whichBox->Width -= 2;

		break;
	}
	case C_CAP_OBJT: case C_LIB_INDR: case C_REC_OBJT:
	{
		whichBox->X -= 6;
		whichBox->Width += 6;

		break;
	}
	case C_LIB_OBJT: 
	{
		whichBox->X -= 3;
		whichBox->Width += 3;

		break;
	}
	default:
		break;
	}

	if (!preAdj)
	{
		roundBounds(bounds);
		whichBox->X += bounds->Width;
		whichBox->Width -= bounds->Width;
	}
}

int LogPair::getAdjNatLen(int nat, bool truncUk)
{
	if (nat == TURN_UKE || nat == TURN_UKP)
	{
		if (truncUk || !globalGame)
			return nats_len[nat] - 4;
		else
			return nats_len[nat];
	}
	else
		return nats_len[nat];
}

void LogPair::addText(Graphics& graphics, const WCHAR* str, int len, Font* font, RectF& whichBox, 
	RectF* bounds, StringFormat* sf, SolidBrush* brush, bool print, int adjCode, int trgtId)
{
	for (int i = 0; i < len; i++)
		text[text_pos + i] = str[i];
	text_pos += len;

	if (!isSpaceOnLine(graphics, text, text_pos, font, whichBox, bounds))
	{
		// Delete last entry, print first line, switch to second line, clear text buffer, measure again
		for (int i = 0; i < len; i++)
			text[text_pos - i] = '\0';
		text_pos -= len;

		graphics.DrawString(text, text_pos, font, whichBox, sf, brush);
		adjustBounds(&whichBox, bounds);

		clear_text();
		for (int i = 0; i < len; i++)
			text[i] = str[i];
		text_pos = len;

		whichBox = *textBox1;
		graphics.MeasureString(text, text_pos, font, whichBox, bounds);
	}

	if (print) // Print no matter what
	{
		graphics.DrawString(text, text_pos, font, whichBox, sf, brush);
		adjustBounds(&whichBox, bounds, adjCode, trgtId);
		clear_text();
		text_pos = 0;
	}
}

bool LogPair::isSpaceOnLine(Graphics& graphics, const WCHAR* str, int len, Font* font, RectF& whichBox, RectF* bounds)
{
	graphics.MeasureString(str, len, font, whichBox, bounds);
	if ((bounds->X + bounds->Width) >= (textPos->X + textPos->Width - 10))
		return false;
	else
		return true;
}

