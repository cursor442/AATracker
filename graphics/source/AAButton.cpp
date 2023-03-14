#include "../header/AAButton.h"

AAButton::AAButton(int id)
	:AAGraphicsObject(id)
{
	bbState = BB_UP;

	bbTextBox = NULL;
	bbBlankBox = NULL;

	hdcCompat = NULL;
	tmpBitmap = NULL;
	tmpBitmapMask = NULL;
	bbBitmap = NULL;

	bbCenterBrush = NULL;
	clearBrush = NULL;

	buttonFont = NULL;

	for (int i = 0; i < BB_TOP_LINES; i++)
	{
		bbTopColor[i] = NULL;
	}

	for (int i = 0; i < BB_BOT_LINES; i++)
	{
		bbBotColor[i] = NULL;
	}

	for (int i = 0; i < BB_LEFT_LINES; i++)
	{
		bbLeftColor[i] = NULL;
	}

	for (int i = 0; i < BB_RIGHT_LINES; i++)
	{
		bbRightColor[i] = NULL;
	}
}

AAButton::~AAButton()
{
	delete bbTextBox;
	delete bbBlankBox;

	DeleteDC(hdcCompat);
	delete tmpBitmap;
	delete tmpBitmapMask;
	delete bbBitmap;
}

void AAButton::configButton(Graphics* graphics, int screen, RectF& rect, const char* text, framesList* frames)
{
	configObject(graphics, screen, rect, text, frames);

	bbTextBox = new AABox("Button");
	bbBlankBox = new AABox("");

	bbBitmap = new Bitmap(rect.Width, rect.Height, PixelFormat32bppARGB);

	config(graphics, text, frames);
}

void AAButton::configDrawTools(vector<Color*>& cGray, vector<SolidBrush*>& bGray, SolidBrush* b0, Font* f0)
{
	bbCenterBrush = bGray[240];
	clearBrush = b0;

	buttonFont = f0;

	bbTopColor[0] = cGray[102];
	bbTopColor[1] = cGray[225];
	bbTopColor[2] = cGray[255]; // 245

	bbBotColor[0] = cGray[173];
	bbBotColor[1] = cGray[91 ];
	bbBotColor[2] = cGray[118];
	bbBotColor[3] = cGray[185];

	bbLeftColor[0] = cGray[102]; // 118
	bbLeftColor[1] = cGray[225]; // 255
	bbLeftColor[2] = cGray[255];

	bbRightColor[0] = cGray[82 ];
	bbRightColor[1] = cGray[137];
	bbRightColor[2] = cGray[92 ];
	bbRightColor[3] = cGray[168];
	bbRightColor[4] = cGray[232];
}

void AAButton::drawButton(Graphics* graphics, HDC& hdc, bool dbg_boundbox, bool dbg_sections, int layers)
{
	drawObject(graphics, dbg_boundbox, dbg_sections, layers);

	hdcCompat = CreateCompatibleDC(hdc);

	if (dbg_sections) // Show box names
	{
		//bbTextBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
	}
	else // Actual graphics
	{
		//CompositingMode currCompositingMode = graphics->GetCompositingMode();
		//InterpolationMode currInterpolationMode = graphics->GetInterpolationMode();
		//PixelOffsetMode currPixelOffsetMode = graphics->GetPixelOffsetMode();

		//graphics->SetCompositingMode(CompositingModeSourceCopy);
		//graphics->SetInterpolationMode(InterpolationModeNearestNeighbor);
		//graphics->SetPixelOffsetMode(PixelOffsetModeHalf);

		//Status test = graphics->DrawImage(bbBitmap, objBox.X, objBox.Y);
		//SelectObject(hdcCompat, tmpBitmap);
		//BitBlt(hdc, objBox.X, objBox.Y, 152, 27, hdcCompat, 0, 0, SRCAND);
		//SelectObject(hdcCompat, tmpBitmapMask);
		//BitBlt(hdc, objBox.X, objBox.Y, 152, 27, hdcCompat, 0, 0, SRCPAINT);

		//graphics->SetCompositingMode(currCompositingMode);
		//graphics->SetInterpolationMode(currInterpolationMode);
		//graphics->SetPixelOffsetMode(currPixelOffsetMode);
		//
		//TextRenderingHint currTextRenderingHint = graphics->GetTextRenderingHint();
		//CompositingQuality currCompositingQuality = graphics->GetCompositingQuality();

		//graphics->SetTextRenderingHint(TextRenderingHintAntiAlias);
		//graphics->SetCompositingQuality(CompositingQualityHighSpeed);

		bbTextBox->drawBox(graphics, borderlessPen, buttonFont, centerFormat, textBrush, bbCenterBrush, objText, layers);

		//graphics->SetTextRenderingHint(currTextRenderingHint);
		//graphics->SetCompositingQuality(currCompositingQuality);
	}
}

void AAButton::hideButton(Graphics* graphics, int& sect)
{
	hideObject(graphics, sect);

	bbBlankBox->drawBox(graphics, borderlessPen, baseTextFont, centerFormat, textBrush, backBrush, L"", 99);
}

bool AAButton::pressButton()
{
	if (bbState == BB_UP)
	{
		bbState = BB_DN;
		return true;
	}
	else
		return false;
}

bool AAButton::releaseButton()
{
	if (bbState == BB_DN)
	{
		bbState = BB_UP;
		return true;
	}
	else
		return false;
}

int AAButton::getButtonId()
{
	return getObjectId();
}


void AAButton::config(Graphics* graphics, const char* text, framesList* frames)
{
	for (int i = 0; i < GRAPHICS_TEXTLEN; i++)
	{
		objText[i] = text[i];
		if (text[i] == '\0')
			break;
	}

	// Determine which frames the tooltip intersects with
	for (int i = 0; i < frames->s[objScr].f.size(); i++)
	{
		if (objBox.IntersectsWith(frames->s[objScr].f[i]))
		{
			intersections |= frames->s[objScr].b[i];
		}
	}

	//tmpBitmap = new HBITMAP(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_NEXTPHASE_UP)));
	//tmpBitmapMask = new HBITMAP(CreateBitmapMask(*tmpBitmap, RGB(0, 0, 0)));

	//BITMAP bmpInfo;
	//GetObject(tmpBitmap, sizeof(BITMAP), &bmpInfo);
	//int cxBitmap = bmpInfo.bmWidth;
	//int cyBitmap = bmpInfo.bmHeight;
	//void* bits = bmpInfo.bmBits;
	//
	//Bitmap bitmap(cxBitmap, cyBitmap, cxBitmap * 4, PixelFormat32bppARGB, (BYTE*)bits);
	//graphics->DrawImage(&bitmap, 0, 0);

	//bool hello = true;

	bbTextBox->config(objBox, 99);
	//bbTextBox->shrink(4);
	//bbTextBox->shrinkX(10);

	// Configure the graphics components
	//Graphics* mem = Graphics::FromImage(bbBitmap);
	//mem->FillRectangle(bbCenterBrush, (FLOAT)0, (FLOAT)0, objBox.Width, objBox.Height);

	// BB_LEFT_LINES
	//for (int y = 0; y < objBox.Height; y++)
	//	for (int x = 0; x < BB_LEFT_LINES; x++)
	//		bbBitmap->SetPixel(x, y, *bbLeftColor[x]);
	//
	//// BB_RIGHT_LINES
	//for (int y = 0; y < objBox.Height; y++)
	//	for (int x = 0; x < BB_RIGHT_LINES; x++)
	//		bbBitmap->SetPixel(objBox.Width - x, y, *bbRightColor[x]);
	//
	//// BB_TOP_LINES
	//for (int y = 0; y < BB_TOP_LINES; y++)
	//	for (int x = 0; x < objBox.Width; x++)
	//	{
	//		if ((x > (y - 1)) && (x < (objBox.Width - (y + 2))))
	//			bbBitmap->SetPixel(x, y, *bbTopColor[y]);
	//	}
	//
	//// BB_BOT_LINES
	//for (int y = 0; y < BB_BOT_LINES; y++)
	//	for (int x = 0; x < objBox.Width; x++)
	//	{
	//		if ((x > (y - 1)) && (x < (objBox.Width - y)))
	//			bbBitmap->SetPixel(x, objBox.Height - y, *bbBotColor[y]);
	//	}
}

HBITMAP AAButton::CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent)
{
	HDC hdcMem, hdcMem2;
	HBITMAP hbmMask;
	BITMAP bm;

	GetObject(hbmColour, sizeof(BITMAP), &bm);
	hbmMask = CreateBitmap(bm.bmWidth, bm.bmHeight, 1, 1, NULL);

	hdcMem = CreateCompatibleDC(0);
	hdcMem2 = CreateCompatibleDC(0);

	SelectObject(hdcMem, hbmColour);
	SelectObject(hdcMem2, hbmMask);

	SetBkColor(hdcMem, crTransparent);

	BitBlt(hdcMem2, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

	BitBlt(hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem2, 0, 0, SRCINVERT);

	DeleteDC(hdcMem);
	DeleteDC(hdcMem2);

	return hbmMask;
}