#include "../header/PurchaseRow.h"

PurchaseRow::PurchaseRow(const char* rowDef, const char* boxDef)
{
	rowBox    = new AABox(rowDef);
	
	unitBox   = new AABox(rowDef);
	costBox   = new AABox("Cost");
	attackBox = new AABox("Attack");
	defendBox = new AABox("Defend");
	moveBox   = new AABox("Move");
	quantBox  = new AABox(boxDef);
	totalBox  = new AABox(boxDef);

	hasButton = false;

	unitText[0] = '\0';
	costText[0] = '\0';
	attackText[0] = '\0';
	defendText[0] = '\0';
	moveText[0] = '\0';
	quantText[0] = '0';
	totalText[0] = '0';

	for (int i = 1; i < PURCH_TEXTLEN_T; i++)
	{
		unitText[i] = '\0';
		costText[i] = '\0';
		attackText[i] = '\0';
		defendText[i] = '\0';
		moveText[i] = '\0';
		quantText[i] = '\0';
		totalText[i] = '\0';
	}
}

PurchaseRow::~PurchaseRow()
{
	delete rowBox;
	
	delete unitBox;
	delete costBox;
	delete attackBox;
	delete defendBox;
	delete moveBox;
	delete quantBox;
	delete totalBox;
}

void PurchaseRow::configRow(RectF& box, REAL unitW, REAL statW, REAL quantW, REAL totW, bool button, int layer)
{
	rowBox->config(box, layer);

	unitBox->config(box, layer + 1);
	unitBox->box.Width *= unitW;

	statW /= 4;

	costBox->config(box, layer + 1);
	costBox->box.X = unitBox->box.GetRight();
	costBox->box.Width *= statW;

	attackBox->config(box, layer + 1);
	attackBox->box.X = costBox->box.GetRight();
	attackBox->box.Width *= statW;

	defendBox->config(box, layer + 1);
	defendBox->box.X = attackBox->box.GetRight();
	defendBox->box.Width *= statW;

	moveBox->config(box, layer + 1);
	moveBox->box.X = defendBox->box.GetRight();
	moveBox->box.Width *= statW;

	hasButton = button;

	quantBox->config(box, layer + 1);
	quantBox->box.Width *= quantW;
	if (hasButton)
	{
		quantBox->box.X = moveBox->box.GetRight() + rowBox->box.Height;
		quantBox->box.Width -= 2 * rowBox->box.Height;
	}
	else
		quantBox->box.X = moveBox->box.GetRight();
	
	totalBox->config(box, layer + 1);
	totalBox->box.Width *= totW;
	if (hasButton)
	{
		totalBox->box.X = quantBox->box.GetRight() + rowBox->box.Height;
		totalBox->box.Width == rowBox->box.GetRight() - totalBox->box.X;
	}
	else
		totalBox->box.X = quantBox->box.GetRight();
}

void PurchaseRow::configRowText(const char* unit, const char* cost, const char* attack, const char* defend, const char* move)
{
	for (int i = 0; i < strlen(unit); i++)
		unitText[i] = unit[i];
	for (int i = 0; i < strlen(cost); i++)
		costText[i] = cost[i];
	for (int i = 0; i < strlen(attack); i++)
		attackText[i] = attack[i];
	for (int i = 0; i < strlen(defend); i++)
		defendText[i] = defend[i];
	for (int i = 0; i < strlen(move); i++)
		moveText[i] = move[i];
}

void PurchaseRow::configQuantTotText(const char* quant, const char* tot)
{
	for (int i = 0; i < strlen(quant); i++)
		quantText[i] = quant[i];
	for (int i = 0; i < strlen(tot); i++)
		totalText[i] = tot[i];
}

void PurchaseRow::setRowX(REAL val)
{
	REAL diff = val - rowBox->box.X;

	rowBox->box.X += diff;

	unitBox->box.X += diff;
	costBox->box.X += diff;
	attackBox->box.X += diff;
	defendBox->box.X += diff;
	moveBox->box.X += diff;
	quantBox->box.X += diff;
	totalBox->box.X += diff;
}

void PurchaseRow::setRowY(REAL val)
{
	rowBox->box.Y = val;

	unitBox->box.Y = val;
	costBox->box.Y = val;
	attackBox->box.Y = val;
	defendBox->box.Y = val;
	moveBox->box.Y = val;
	quantBox->box.Y = val;
	totalBox->box.Y = val;
}

void PurchaseRow::setRowHeight(REAL val)
{
	rowBox->box.Height = val;

	unitBox->box.Height = val;
	costBox->box.Height = val;
	attackBox->box.Height = val;
	defendBox->box.Height = val;
	moveBox->box.Height = val;
	quantBox->box.Height = val;
	totalBox->box.Height = val;
}

void PurchaseRow::drawPurchaseRow(Graphics* graphics, Pen* pen, Font* f0, Font* f1, StringFormat* sf0, StringFormat* sf1, Brush* b0, Brush* b1, bool dbg_sections, int layers)
{
	if (dbg_sections) // Show box names
	{
		rowBox->drawFrameFill(graphics, pen, f1, sf0, b0, b1, layers);
		
		unitBox->drawFrameFill(graphics, pen, f1, sf0, b0, b1, layers);
		costBox->drawFrameFill(graphics, pen, f1, sf1, b0, b1, layers);
		attackBox->drawFrameFill(graphics, pen, f1, sf1, b0, b1, layers);
		defendBox->drawFrameFill(graphics, pen, f1, sf1, b0, b1, layers);
		moveBox->drawFrameFill(graphics, pen, f1, sf1, b0, b1, layers);
		quantBox->drawFrameFill(graphics, pen, f1, sf1, b0, b1, layers);
		totalBox->drawFrameFill(graphics, pen, f1, sf1, b0, b1, layers);
	}
	else // Actual graphics
	{
		unitBox->drawBox(graphics, pen, f0, sf0, b0, b1, unitText, layers);
		costBox->drawBox(graphics, pen, f0, sf1, b0, b1, costText, layers);
		attackBox->drawBox(graphics, pen, f0, sf1, b0, b1, attackText, layers);
		defendBox->drawBox(graphics, pen, f0, sf1, b0, b1, defendText, layers);
		moveBox->drawBox(graphics, pen, f0, sf1, b0, b1, moveText, layers);
		quantBox->drawBox(graphics, pen, f1, sf1, b0, b1, quantText, layers);
		totalBox->drawBox(graphics, pen, f1, sf1, b0, b1, totalText, layers);
	}
}

void PurchaseRow::drawPurchaseRow(Graphics* graphics, Pen* pen, Font* f0, Font* f1, StringFormat* sf0, StringFormat* sf1, Brush* b0, Brush* b1, int whichBox, bool updText, const WCHAR* text, bool dbg_sections, int layers)
{
	if (dbg_sections) // Show box names
	{
		drawPurchaseRow(graphics, pen, f0, f1, sf0, sf1, b0, b1, dbg_sections, layers);
	}
	else // Actual graphics
	{
		switch (whichBox)
		{
		case PURCH_ROW_BOX:
			
			break;
		case PURCH_ROW_UNIT:
			if (updText)
				wcsncpy_s(unitText, text, 4);
			unitBox->drawBox(graphics, pen, f0, sf0, b0, b1, unitText, layers);
			break;
		case PURCH_ROW_COST:
			if (updText)
				wcsncpy_s(costText, text, 4);
			costBox->drawBox(graphics, pen, f0, sf1, b0, b1, costText, layers);
			break;
		case PURCH_ROW_ATTACK:
			if (updText)
				wcsncpy_s(attackText, text, 4);
			attackBox->drawBox(graphics, pen, f0, sf1, b0, b1, attackText, layers);
			break;
		case PURCH_ROW_DEFEND:
			if (updText)
				wcsncpy_s(defendText, text, 4);
			defendBox->drawBox(graphics, pen, f0, sf1, b0, b1, defendText, layers);
			break;
		case PURCH_ROW_MOVE:
			if (updText)
				wcsncpy_s(moveText, text, 4);
			moveBox->drawBox(graphics, pen, f0, sf1, b0, b1, moveText, layers);
			break;
		case PURCH_ROW_QUANT:
			if (updText)
				wcsncpy_s(quantText, text, 4);
			quantBox->drawBox(graphics, pen, f1, sf1, b0, b1, quantText, layers);
			break;
		case PURCH_ROW_TOTAL:
			if (updText)
				wcsncpy_s(totalText, text, 4);
			totalBox->drawBox(graphics, pen, f1, sf1, b0, b1, totalText, layers);
			break;
		}
	}
}

void PurchaseRow::updatePurchaseText(int whichBox, const WCHAR* text)
{
	switch (whichBox)
	{
	case PURCH_ROW_BOX:

		break;
	case PURCH_ROW_UNIT:
		wcsncpy_s(unitText, text, 4);
		break;
	case PURCH_ROW_COST:
		wcsncpy_s(costText, text, 4);
		break;
	case PURCH_ROW_ATTACK:
		wcsncpy_s(attackText, text, 4);
		break;
	case PURCH_ROW_DEFEND:
		wcsncpy_s(defendText, text, 4);
		break;
	case PURCH_ROW_MOVE:
		wcsncpy_s(moveText, text, 4);
		break;
	case PURCH_ROW_QUANT:
		wcsncpy_s(quantText, text, 4);
		break;
	case PURCH_ROW_TOTAL:
		wcsncpy_s(totalText, text, 4);
		break;
	}
}

REAL PurchaseRow::y()
{
	return rowBox->box.Y;
}

REAL PurchaseRow::bottom()
{
	return rowBox->box.GetBottom();
}

REAL PurchaseRow::height()
{
	return rowBox->box.Height;
}

REAL PurchaseRow::buttonDownX()
{
	return moveBox->box.GetRight();
}

REAL PurchaseRow::buttonUpX()
{
	return quantBox->box.GetRight();
}

AABox* PurchaseRow::getBox(int box)
{
	switch (box)
	{
	case PURCH_ROW_BOX:
		return rowBox;
	case PURCH_ROW_UNIT:
		return unitBox;
	case PURCH_ROW_COST:
		return costBox;
	case PURCH_ROW_ATTACK:
		return attackBox;
	case PURCH_ROW_DEFEND:
		return defendBox;
	case PURCH_ROW_MOVE:
		return moveBox;
	case PURCH_ROW_QUANT:
		return quantBox;
	case PURCH_ROW_TOTAL:
		return totalBox;
	default:
		return rowBox;
	}
}

