#include "../header/AATooltip.h"

AATooltip::AATooltip(int id)
{
	ttId  = id;
	ttScr = SCREEN_NONE;
	ttBox = { 0, 0, 0, 0 };
	ttDir = TT_DIR_NULL;

	ttTriBox = NULL;
	ttTextBox = NULL;
	ttBlankBox = NULL;

	borderPen = NULL;
	borderlessPen = NULL;
	fontFamily = NULL;
	textFormat = NULL;
	centerFormat = NULL;
	baseTextFont = NULL;
	textBrush = NULL;
	backBrush = NULL;
	popupBrush = NULL;

	pen = NULL;

	for (int i = 0; i < TT_TEXTLEN; i++)
		ttText[i] = '\0';

	intersections = NO_SECT;
}

AATooltip::~AATooltip()
{
	delete ttTextBox;
	delete ttTriBox;
	delete ttBlankBox;
}

void AATooltip::configBaseDrawTools(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
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

void AATooltip::configTooltip(Graphics* graphics, int screen, RectF& rect, int dir, const char* text, framesList* frames)
{
	ttScr = screen;
	ttBox = rect;
	ttDir = dir;

	ttTextBox = new AABox("Tooltip");
	ttTriBox = new AATri();
	ttBlankBox = new AABox("");

	config(graphics, text, frames);
}

void AATooltip::drawTooltip(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		ttTriBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		ttTextBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
	}
	else // Actual graphics
	{
		ttTriBox->drawTri(graphics, pen, popupBrush, layers);
		ttTextBox->drawBox(graphics, pen, baseTextFont, centerFormat, textBrush, popupBrush, ttText, layers);
	}
}

void AATooltip::hideTooltip(Graphics* graphics, int& sect)
{
	ttTriBox->drawTri(graphics, borderlessPen, backBrush, 99);
	ttBlankBox->drawBox(graphics, borderlessPen, baseTextFont, centerFormat, textBrush, backBrush, L"", 99);

	sect = intersections;
}

int AATooltip::getTooltipId()
{
	return ttId;
}


bool AATooltip::isPointInBox(int xPos, int yPos)
{
	PointF point = PointF((REAL)xPos, (REAL)yPos);

	if (ttBox.Contains(point))
		return true;
	else
		return false;
}

PointF AATooltip::getRectCorner(int corner)
{
	switch (corner)
	{
	case TT_RECT_TL:
		return { ttBox.X, ttBox.Y };
		break;
	case TT_RECT_TR:
		return { ttBox.GetRight(), ttBox.Y };
		break;
	case TT_RECT_BL:
		return { ttBox.X, ttBox.GetBottom() };
		break;
	case TT_RECT_BR:
		return { ttBox.GetRight(), ttBox.GetBottom() };
		break;
	default:
		return { 0, 0 };

	}
}

void AATooltip::config(Graphics* graphics, const char* text, framesList* frames)
{
	RectF rect;
	const PointF origin = { ttBox.X, ttBox.Y };

	PointF p0, p1, p2;

	for (int i = 0; i < TT_TEXTLEN; i++)
	{
		ttText[i] = text[i];
		if (text[i] == '\0')
			break;
	}

	// Determine width and height necessary
	const WCHAR* tmpText;
	int size = MultiByteToWideChar(CP_ACP, 0, text, -1, NULL, 0);
	tmpText = new WCHAR[size];
	MultiByteToWideChar(CP_ACP, 0, text, -1, (LPWSTR)tmpText, size);
	graphics->MeasureString(tmpText, -1, baseTextFont, origin, centerFormat, &rect);
	delete[] tmpText;

	switch (ttDir)
	{
	case TT_DIR_LEFT:
	{
		p0 = { ttBox.X, ttBox.Y + (ttBox.Height / 2) };
		p1 = { p0.X - TT_TRI_SIZE, p0.Y - (TT_TRI_SIZE / 2) };
		p2 = { p0.X - TT_TRI_SIZE, p0.Y + (TT_TRI_SIZE / 2) };
		ttTriBox->config(p0, p1, p2, 3);

		rect.X = ttBox.X - (rect.Width + TT_TRI_SIZE);
		rect.Y = p0.Y - (rect.Height / 2);
		ttTextBox->config(rect, 3);

		ttBlankBox->config(rect, 1);
		break;
	}
	case TT_DIR_RIGHT:
	{
		p0 = { ttBox.GetRight(), ttBox.Y + (ttBox.Height / 2) };
		p1 = { p0.X + TT_TRI_SIZE, p0.Y - (TT_TRI_SIZE / 2) };
		p2 = { p0.X + TT_TRI_SIZE, p0.Y + (TT_TRI_SIZE / 2) };
		ttTriBox->config(p0, p1, p2, 3);

		rect.X = ttBox.GetRight() + TT_TRI_SIZE;
		rect.Y = p0.Y - (rect.Height / 2);
		ttTextBox->config(rect, 3);

		ttBlankBox->config(rect, 1);
		break;
	}
	case TT_DIR_UP:
	{
		p0 = { ttBox.X + (ttBox.Width / 2), ttBox.Y };
		p1 = { p0.X + (TT_TRI_SIZE / 2), p0.Y - TT_TRI_SIZE };
		p2 = { p0.X - (TT_TRI_SIZE / 2), p0.Y - TT_TRI_SIZE };
		ttTriBox->config(p0, p1, p2, 3);

		rect.X = ttBox.X + (ttBox.Width / 2) - (rect.Width / 2);
		rect.Y = p1.Y - rect.Height;
		ttTextBox->config(rect, 3);

		ttBlankBox->config(rect, 1);
		break;
	}
	case TT_DIR_DOWN:
	{
		p0 = { ttBox.X + (ttBox.Width / 2), ttBox.GetBottom() };
		p1 = { p0.X + (TT_TRI_SIZE / 2), p0.Y + TT_TRI_SIZE };
		p2 = { p0.X - (TT_TRI_SIZE / 2), p0.Y + TT_TRI_SIZE };
		ttTriBox->config(p0, p1, p2, 3);

		rect.X = ttBox.X + (ttBox.Width / 2) - (rect.Width / 2);
		rect.Y = p1.Y;
		ttTextBox->config(rect, 3);

		ttBlankBox->config(rect, 1);
		break;
	}
	default:
		break;
	}

	// Determine which frames the tooltip intersects with
	for (int i = 0; i < frames->s[ttScr].f.size(); i++)
	{
		if (rect.IntersectsWith(frames->s[ttScr].f[i]))
		{
			intersections |= frames->s[ttScr].b[i];
		}
	}

}