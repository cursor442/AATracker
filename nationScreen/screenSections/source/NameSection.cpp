#include "../header/NameSection.h"

NameSection::NameSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1, 
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	nameFrame = new AABox("Name Section");

	nameBox = new AABox("Nation Name");
	typeBox = new AABox("Type");
	turnBox = new AABox("Turn");

	name[0] = '\0';
	gameType[0] = '\0';
	wcsncpy_s(gameTurn, L"Turn ", 5);
	gameTurn[7] = '\0';

	descrFont = NULL;
	nameFont = NULL;
}

NameSection::~NameSection()
{
	delete nameFrame;

	delete nameBox;
	delete typeBox;
	delete turnBox;
}

void NameSection::configureNameBox(RectF& frame, int layer)
{
	nameFrame->config(frame, layer);

	nameBox->config(nameFrame->box, layer + 1);
	nameBox->box.Height -= 24;

	typeBox->config(nameBox->box, layer + 1);
	typeBox->box.X += nameBox->box.Width / 8;
	typeBox->box.Width = nameBox->box.Width / 2;
	typeBox->box.Y += nameBox->box.Height + 6;
	typeBox->box.Height = (nameFrame->box.GetBottom() - typeBox->box.Y);

	turnBox->config(typeBox->box, layer + 1);
	turnBox->box.X = typeBox->box.GetRight();
	turnBox->box.Width = 96;
}

void NameSection::configDrawTools(Font* f0, Font* f1)
{
	nameFont = f0;
	descrFont = f1;
}

void NameSection::updateNameText(int nat, int type, int turn)
{
	wcsncpy_s(name, natNames[nat], ARRAYSIZE(natNames[nat]));
	wcsncpy_s(gameType, gameTypes[type], ARRAYSIZE(gameTypes[type]));
	turnConv(turn);	
}

void NameSection::drawNameBox(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		nameFrame->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		nameBox->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, backBrush, layers);
		typeBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		turnBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
	}
	else // Actual graphics
	{
		nameBox->drawBox(graphics, pen, nameFont, textFormat, textBrush, backBrush, name, layers);
		typeBox->drawBox(graphics, pen, descrFont, textFormat, textBrush, backBrush, gameType, layers);
		turnBox->drawBox(graphics, pen, descrFont, textFormat, textBrush, backBrush, gameTurn, layers);
	}
}

REAL NameSection::getBoxEdge(int whichBox, int edge)
{
	AABox* tmp = nameFrame;

	switch (whichBox)
	{
	case NAME_BOX:
		tmp = nameBox;
		break;
	case TYPE_BOX:
		tmp = typeBox;
		break;
	case TURN_BOX:
		tmp = turnBox;
		break;
	default:
		tmp = nameFrame;
		break;
	}

	switch (edge)
	{
	case BOX_LEFT:
		return tmp->box.GetLeft();
		break;
	case BOX_RIGHT:
		return tmp->box.GetRight();
		break;
	case BOX_TOP:
		return tmp->box.GetTop();
		break;
	case BOX_BOTTOM:
		return tmp->box.GetBottom();
		break;
	case BOX_WIDTH:
		return tmp->box.Width;
		break;
	case BOX_HEIGHT:
		return tmp->box.Height;
		break;
	default:
		return 0;
		break;
	}
}

void NameSection::turnConv(int turn)
{
	gameTurn[5] = ' ';
	if (turn > 9)
	{
		gameTurn[5] = uint2char_(turn / 10);
	}
	gameTurn[6] = uint2char_(turn % 10);
}