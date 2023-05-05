#include "../header/AATooltip.h"

AATooltip::AATooltip(int id)
	:AAGraphicsObject(id)
{
	ttDir = TT_DIR_NULL;

	ttTriBox = NULL;
	ttTextBox = NULL;
	ttBlankBox = NULL;
}

AATooltip::~AATooltip()
{
	delete ttTextBox;
	delete ttTriBox;
	delete ttBlankBox;
}

void AATooltip::configTooltip(Graphics* graphics, int screen, int sect, RectF& rect, int dir, const char* text, framesList* frames)
{
	configObject(graphics, screen, sect, rect, text, frames);

	ttDir = dir;

	ttTextBox = new AABox("Tooltip");
	ttTriBox = new AATri();
	ttBlankBox = new AABox("");

	config(graphics, text, frames);
}

void AATooltip::drawTooltip(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	drawObject(graphics, dbg_boundbox, dbg_sections, layers);

	if (dbg_sections) // Show box names
	{
		ttTriBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		ttTextBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
	}
	else // Actual graphics
	{
		ttTriBox->drawTri(graphics, pen, popupBrush, layers);
		ttTextBox->drawBox(graphics, pen, baseTextFont, centerFormat, textBrush, popupBrush, objText, layers);
	}
}

void AATooltip::hideTooltip(Graphics* graphics, int& sect)
{
	hideObject(graphics, sect);

	ttTriBox->drawTri(graphics, borderlessPen, backBrush, 99);
	ttBlankBox->drawBox(graphics, borderlessPen, baseTextFont, centerFormat, textBrush, backBrush, L"", 99);
}

int AATooltip::getTooltipId()
{
	return getObjectId();
}


void AATooltip::config(Graphics* graphics, const char* text, framesList* frames)
{
	RectF rect;
	const PointF origin = { objBox.X, objBox.Y };

	PointF p0, p1, p2;

	for (int i = 0; i < GRAPHICS_TEXTLEN; i++)
	{
		objText[i] = text[i];
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
		p0 = { objBox.X, objBox.Y + (objBox.Height / 2) };
		p1 = { p0.X - TT_TRI_SIZE, p0.Y - (TT_TRI_SIZE / 2) };
		p2 = { p0.X - TT_TRI_SIZE, p0.Y + (TT_TRI_SIZE / 2) };
		ttTriBox->config(p0, p1, p2, 3);

		rect.X = objBox.X - (rect.Width + TT_TRI_SIZE);
		rect.Y = p0.Y - (rect.Height / 2);
		ttTextBox->config(rect, 3);

		ttBlankBox->config(rect, 1);
		break;
	}
	case TT_DIR_RIGHT:
	{
		p0 = { objBox.GetRight(), objBox.Y + (objBox.Height / 2) };
		p1 = { p0.X + TT_TRI_SIZE, p0.Y - (TT_TRI_SIZE / 2) };
		p2 = { p0.X + TT_TRI_SIZE, p0.Y + (TT_TRI_SIZE / 2) };
		ttTriBox->config(p0, p1, p2, 3);

		rect.X = objBox.GetRight() + TT_TRI_SIZE;
		rect.Y = p0.Y - (rect.Height / 2);
		ttTextBox->config(rect, 3);

		ttBlankBox->config(rect, 1);
		break;
	}
	case TT_DIR_UP:
	{
		p0 = { objBox.X + (objBox.Width / 2), objBox.Y };
		p1 = { p0.X + (TT_TRI_SIZE / 2), p0.Y - TT_TRI_SIZE };
		p2 = { p0.X - (TT_TRI_SIZE / 2), p0.Y - TT_TRI_SIZE };
		ttTriBox->config(p0, p1, p2, 3);

		rect.X = objBox.X + (objBox.Width / 2) - (rect.Width / 2);
		rect.Y = p1.Y - rect.Height;
		ttTextBox->config(rect, 3);

		ttBlankBox->config(rect, 1);
		break;
	}
	case TT_DIR_DOWN:
	{
		p0 = { objBox.X + (objBox.Width / 2), objBox.GetBottom() };
		p1 = { p0.X + (TT_TRI_SIZE / 2), p0.Y + TT_TRI_SIZE };
		p2 = { p0.X - (TT_TRI_SIZE / 2), p0.Y + TT_TRI_SIZE };
		ttTriBox->config(p0, p1, p2, 3);

		rect.X = objBox.X + (objBox.Width / 2) - (rect.Width / 2);
		rect.Y = p1.Y;
		ttTextBox->config(rect, 3);

		ttBlankBox->config(rect, 1);
		break;
	}
	default:
		break;
	}

	// Determine which frames the tooltip intersects with
	for (int i = 0; i < frames->s[objScr].f.size(); i++)
	{
		if (rect.IntersectsWith(frames->s[objScr].f[i]))
		{
			intersections |= frames->s[objScr].b[i];
		}
	}

}