#include "../header/WarSection.h"

WarSection::WarSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	warFrame = new AABox("War Section");

	warWithBox = new AABox("War");

	warBoxFormat = 0;
	warBoxIgnoreLast = false;
	name0[0] = '\0';
	name1[0] = '\0';
	name2[0] = '\0';
	name3[0] = '\0';

	// Format 4
	warTopBox = new AABox("Top");
	warBotBox = new AABox("Bottom");

	// Format 3
	warTLBox = new AABox("TL");
	warTRBox = new AABox("TR");
	warBLBox = new AABox("BL");
	warBRBox = new AABox("BR");

	// Format 1
	warD1Tri = new AATri();
	warD2Tri = new AATri();
	warD3Tri = new AATri();

	redBrush = NULL;

	gerBrushP = NULL; gerBrushF = NULL;
	sovBrushP = NULL; sovBrushF = NULL;
	jpnBrushP = NULL; jpnBrushF = NULL;
	usaBrushP = NULL; usaBrushF = NULL;
	chnBrushP = NULL; chnBrushF = NULL;
	ukBrushP  = NULL; ukBrushF  = NULL;
	itaBrushP = NULL; itaBrushF = NULL;
	anzBrushP = NULL; anzBrushF = NULL;
	fraBrushP = NULL; fraBrushF = NULL;

	// Interchangeable brushes
	warTopBrush = NULL; warBotBrush = NULL;
	warTRBrush = NULL; warTLBrush = NULL; warBLBrush = NULL; warBRBrush = NULL;
	warD1Brush = NULL; warD2Brush = NULL; warD3Brush = NULL;

	headFont = NULL; headFont_s = NULL;

	font0 = NULL; font1 = NULL; font2 = NULL; font3 = NULL;
}

WarSection::~WarSection()
{
	delete warFrame;

	delete warTopBox;
	delete warBotBox;

	delete warTLBox;
	delete warTRBox;
	delete warBLBox;
	delete warBRBox;

	delete warD1Tri;
	delete warD2Tri;
	delete warD3Tri;

}

void WarSection::configureWarBox(RectF& frame, int layer)
{
	warFrame->config(frame, layer);

	warWithBox->config(warFrame->box, layer + 1);
	warWithBox->box.Height = warFrame->box.Height / 3;

	// Format 4
	warTopBox->config(warWithBox->box, layer + 1);
	warTopBox->box.Y = warWithBox->box.GetBottom();

	warBotBox->config(warTopBox->box, layer + 1);
	warBotBox->box.Y = warTopBox->box.GetBottom();
	warBotBox->box.Height = warFrame->box.GetBottom() - warBotBox->box.Y;

	// Format 3
	warTLBox->config(warTopBox->box, layer + 1);
	warTLBox->box.Width /= 2;

	warTRBox->config(warTLBox->box, layer + 1);
	warTRBox->box.X = warTLBox->box.GetRight();
	warTRBox->box.Width = warFrame->box.GetRight() - warTRBox->box.X;

	warBLBox->config(warBotBox->box, layer + 1);
	warBLBox->box.Width /= 2;

	warBRBox->config(warBLBox->box, layer + 1);
	warBRBox->box.X = warBLBox->box.GetRight();
	warBRBox->box.Width = warFrame->box.GetRight() - warBRBox->box.X;

	// Format 1
	warD1Tri->config({ warTLBox->box.X,  warTLBox->box.Y }, 
		{ warTLBox->box.X,  warTLBox->box.GetBottom() }, 
		{ warTLBox->box.X + (warTLBox->box.Width / 2),  warTLBox->box.Y }, layer + 1);
	warD2Tri->config({ warTLBox->box.X,  warTLBox->box.GetBottom() },
		{ warTLBox->box.X + (warTLBox->box.Width / 2),  warTLBox->box.Y },
		{ warTLBox->box.GetRight(),  warTLBox->box.GetBottom() }, layer + 1);
	warD3Tri->config({ warTLBox->box.X + (warTLBox->box.Width / 2),  warTLBox->box.Y },
		{ warTLBox->box.GetRight(),  warTLBox->box.GetBottom() },
		{ warTLBox->box.GetRight(),  warTLBox->box.Y }, layer + 1);
}

void WarSection::configDrawTools(SolidBrush* b0, Font* f0, Font* f1)
{
	redBrush = b0;
	headFont = f0;
	headFont_s = f1;
}

void WarSection::updateFormat(int nat, int type, WarMatrix* warMatrix)
{
	warBoxIgnoreLast = false;
	
	switch (nat)
	{
	case TURN_GER:
	{
		if (type == EUROPE_GAME)
		{
			warTLBrush = ukBrushP;
			warTRBrush = fraBrushP;
			if (warMatrix->getAtWarWith(TURN_GER, TURN_SOV))
				warBLBrush = sovBrushP;
			else
				warBLBrush = sovBrushF;
			if (warMatrix->getAtWarWith(TURN_GER, TURN_USA))
				warBRBrush = usaBrushP;
			else
				warBRBrush = usaBrushF;

			wcsncpy_s(name0, natNames[TURN_UKE], ARRAYSIZE(natNames[TURN_UKE])); font0 = headFont_s;
			wcsncpy_s(name1, natNames[TURN_FRA], ARRAYSIZE(natNames[TURN_FRA])); font1 = headFont;
			wcsncpy_s(name2, natNames[TURN_SOV], ARRAYSIZE(natNames[TURN_SOV])); font2 = headFont_s;
			wcsncpy_s(name3, natNames[TURN_USA], ARRAYSIZE(natNames[TURN_USA])); font3 = headFont_s;
			warBoxFormat = 3;
		}
		else if (type == GLOBAL_GAME)
		{
			warD1Brush = ukBrushP;
			warD2Brush = anzBrushP;
			warD3Brush = fraBrushP;

			if (warMatrix->getAtWarWith(TURN_GER, TURN_SOV))
				warTRBrush = sovBrushP;
			else
				warTRBrush = sovBrushF;
			if (warMatrix->getAtWarWith(TURN_GER, TURN_CHN))
				warBLBrush = chnBrushP;
			else
				warBLBrush = chnBrushF;
			if (warMatrix->getAtWarWith(TURN_GER, TURN_USA))
				warBRBrush = usaBrushP;
			else
				warBRBrush = usaBrushF;

			wcsncpy_s(name1, natNames[TURN_SOV], ARRAYSIZE(natNames[TURN_SOV])); font1 = headFont_s;
			wcsncpy_s(name2, natNames[TURN_CHN], ARRAYSIZE(natNames[TURN_CHN])); font2 = headFont;
			wcsncpy_s(name3, natNames[TURN_USA], ARRAYSIZE(natNames[TURN_USA])); font3 = headFont_s;
			warBoxFormat = 1;
		}
		break;
	}
	case TURN_SOV:
	{
		if (type == EUROPE_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_GER, TURN_SOV))
				warTopBrush = gerBrushP;
			else
				warTopBrush = gerBrushF;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_SOV))
				warBotBrush = itaBrushP;
			else
				warBotBrush = itaBrushF;

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			warBoxFormat = 4;
		}
		else if (type == GLOBAL_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_GER, TURN_SOV))
				warTLBrush = gerBrushP;
			else
				warTLBrush = gerBrushF;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_SOV))
				warTRBrush = itaBrushP;
			else
				warTRBrush = itaBrushF;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_SOV))
				warBLBrush = jpnBrushP;
			else
				warBLBrush = jpnBrushF;

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			wcsncpy_s(name2, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font2 = headFont;
			warBoxFormat = 3;
			warBoxIgnoreLast = true;
		}
		break;
	}
	case TURN_JPN:
	{
		if (type == PACIFIC_GAME)
		{
			warTLBrush = chnBrushP;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_USA))
				warTRBrush = usaBrushP;
			else
				warTRBrush = usaBrushF;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_UKP))
			{
				warBLBrush = ukBrushP;
				warBRBrush = anzBrushP;
			}
			else
			{
				warBLBrush = ukBrushF;
				warBRBrush = anzBrushF;
			}

			wcsncpy_s(name0, natNames[TURN_CHN], ARRAYSIZE(natNames[TURN_CHN])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_USA], ARRAYSIZE(natNames[TURN_USA])); font1 = headFont_s;
			wcsncpy_s(name2, natNames[TURN_UKE], ARRAYSIZE(natNames[TURN_UKE])); font2 = headFont_s;
			wcsncpy_s(name3, natNames[TURN_ANZ], ARRAYSIZE(natNames[TURN_ANZ])); font3 = headFont;
			warBoxFormat = 3;
		}
		else if (type == GLOBAL_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_UKE))
			{
				warD1Brush = ukBrushP;
				warD2Brush = anzBrushP;
			}
			else
			{
				warD1Brush = ukBrushF;
				warD2Brush = anzBrushF;
			}
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_FRA))
				warD3Brush = fraBrushP;
			else
				warD3Brush = fraBrushF;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_SOV))
				warTRBrush = sovBrushP;
			else
				warTRBrush = sovBrushF;
			warBLBrush = chnBrushP;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_USA))
				warBRBrush = usaBrushP;
			else
				warBRBrush = usaBrushF;

			wcsncpy_s(name1, natNames[TURN_SOV], ARRAYSIZE(natNames[TURN_SOV])); font1 = headFont_s;
			wcsncpy_s(name2, natNames[TURN_CHN], ARRAYSIZE(natNames[TURN_CHN])); font2 = headFont;
			wcsncpy_s(name3, natNames[TURN_USA], ARRAYSIZE(natNames[TURN_USA])); font3 = headFont_s;
			warBoxFormat = 1;
		}
		break;
	}
	case TURN_USA:
	{
		if (type == EUROPE_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_GER, TURN_USA))
				warTopBrush = gerBrushP;
			else
				warTopBrush = gerBrushF;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_USA))
				warBotBrush = itaBrushP;
			else
				warBotBrush = itaBrushF;

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			warBoxFormat = 4;
		}
		else if (type == PACIFIC_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_USA))
				warTopBrush = jpnBrushP;
			else
				warTopBrush = jpnBrushF;

			wcsncpy_s(name0, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font0 = headFont;
			warBoxFormat = 4;
			warBoxIgnoreLast = true;
		}
		else if (type == GLOBAL_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_GER, TURN_USA))
				warTLBrush = gerBrushP;
			else
				warTLBrush = gerBrushF;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_USA))
				warTRBrush = itaBrushP;
			else
				warTRBrush = itaBrushF;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_USA))
				warBLBrush = jpnBrushP;
			else
				warBLBrush = jpnBrushF;

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			wcsncpy_s(name2, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font2 = headFont;
			warBoxFormat = 3;
			warBoxIgnoreLast = true;
		}
		break;
	}
	case TURN_CHN:
	{
		if (type == PACIFIC_GAME)
		{
			warTopBrush = jpnBrushP; // Don't need secondary

			wcsncpy_s(name0, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font0 = headFont;
			warBoxFormat = 4;
			warBoxIgnoreLast = true;
		}
		else if (type == GLOBAL_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_GER, TURN_CHN))
				warTLBrush = gerBrushP;
			else
				warTLBrush = gerBrushF;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_CHN))
				warTRBrush = itaBrushP;
			else
				warTRBrush = itaBrushF;
			warBLBrush = jpnBrushP;

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			warBoxFormat = 3;
			warBoxIgnoreLast = true;
		}
		break;
	}
	case TURN_UKE: case TURN_UKP:
	{
		if (type == EUROPE_GAME)
		{
			warTopBrush = gerBrushP; // Don't need secondary
			warBotBrush = itaBrushP; // Don't need secondary

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			warBoxFormat = 4;
		}
		else if (type == PACIFIC_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_UKP))
				warTopBrush = jpnBrushP;
			else
				warTopBrush = jpnBrushF;

			wcsncpy_s(name0, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font0 = headFont;
			warBoxFormat = 4;
			warBoxIgnoreLast = true;
		}
		else if (type == GLOBAL_GAME)
		{
			warTLBrush = gerBrushP;
			warTRBrush = itaBrushP;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_UKE))
				warBLBrush = jpnBrushP;
			else
				warBLBrush = jpnBrushF;

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			wcsncpy_s(name2, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font2 = headFont;
			warBoxFormat = 3;
			warBoxIgnoreLast = true;
		}
		break;
	}
	case TURN_ITA: 
	{
		if (type == EUROPE_GAME)
		{
			warTLBrush = ukBrushP;
			warTRBrush = fraBrushP;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_SOV))
				warBLBrush = sovBrushP;
			else
				warBLBrush = sovBrushF;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_USA))
				warBRBrush = usaBrushP;
			else
				warBRBrush = usaBrushF;

			wcsncpy_s(name0, natNames[TURN_UKE], ARRAYSIZE(natNames[TURN_UKE])); font0 = headFont_s;
			wcsncpy_s(name1, natNames[TURN_FRA], ARRAYSIZE(natNames[TURN_FRA])); font1 = headFont;
			wcsncpy_s(name2, natNames[TURN_SOV], ARRAYSIZE(natNames[TURN_SOV])); font2 = headFont_s;
			wcsncpy_s(name3, natNames[TURN_USA], ARRAYSIZE(natNames[TURN_USA])); font3 = headFont_s;
			warBoxFormat = 3;
		}
		else if (type == GLOBAL_GAME)
		{
			warD1Brush = ukBrushP;
			warD2Brush = anzBrushP;
			warD3Brush = fraBrushP;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_SOV))
				warTRBrush = sovBrushP;
			else
				warTRBrush = sovBrushF;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_CHN))
				warBLBrush = chnBrushP;
			else
				warBLBrush = chnBrushF;
			if (warMatrix->getAtWarWith(TURN_ITA, TURN_USA))
				warBRBrush = usaBrushP;
			else
				warBRBrush = usaBrushF;

			wcsncpy_s(name1, natNames[TURN_SOV], ARRAYSIZE(natNames[TURN_SOV])); font1 = headFont_s;
			wcsncpy_s(name2, natNames[TURN_CHN], ARRAYSIZE(natNames[TURN_CHN])); font2 = headFont;
			wcsncpy_s(name3, natNames[TURN_USA], ARRAYSIZE(natNames[TURN_USA])); font3 = headFont_s;
			warBoxFormat = 1;
		}
		break;
	}
	case TURN_ANZ:
	{
		if (type == PACIFIC_GAME)
		{
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_ANZ))
				warTopBrush = jpnBrushP;
			else
				warTopBrush = jpnBrushF;
			
			wcsncpy_s(name0, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font0 = headFont;
			warBoxFormat = 4;
			warBoxIgnoreLast = true;
		}
		else if (type == GLOBAL_GAME)
		{
			warTLBrush = gerBrushP;
			warTRBrush = itaBrushP;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_ANZ))
				warBLBrush = jpnBrushP;
			else
				warBLBrush = jpnBrushF;

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			wcsncpy_s(name2, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font2 = headFont;
			warBoxFormat = 3;
			warBoxIgnoreLast = true;
		}
		break;
	}
	case TURN_FRA:
	{
		if (type == EUROPE_GAME)
		{
			warTopBrush = gerBrushP; // Don't need secondary
			warBotBrush = itaBrushP; // Don't need secondary

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			warBoxFormat = 4;
		}
		else if (type == GLOBAL_GAME)
		{
			warTLBrush = gerBrushP;
			warTRBrush = itaBrushP;
			if (warMatrix->getAtWarWith(TURN_JPN, TURN_FRA))
				warBLBrush = jpnBrushP;
			else
				warBLBrush = jpnBrushF;

			wcsncpy_s(name0, natNames[TURN_GER], ARRAYSIZE(natNames[TURN_GER])); font0 = headFont;
			wcsncpy_s(name1, natNames[TURN_ITA], ARRAYSIZE(natNames[TURN_ITA])); font1 = headFont;
			wcsncpy_s(name2, natNames[TURN_JPN], ARRAYSIZE(natNames[TURN_JPN])); font2 = headFont;
			warBoxFormat = 3;
			warBoxIgnoreLast = true;
		}
		break;
	}
	default:
		break;
	}
}

void WarSection::drawWarBox(Graphics* graphics, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		warFrame->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);
		warWithBox->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, backBrush, layers);

		switch (warBoxFormat)
		{
		case 1:
		{
			warD1Tri->drawTri(graphics, borderPen, backBrush, layers);
			warD2Tri->drawTri(graphics, borderPen, backBrush, layers);
			warD3Tri->drawTri(graphics, borderPen, backBrush, layers);
			warTRBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			warBLBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			warBRBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			break;
		}
		case 3:
		{
			warTLBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			warTRBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			warBLBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			if (!warBoxIgnoreLast)
				warBRBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			else
				warBRBox->drawBox(graphics, pen, font3, centerFormat, textBrush, backBrush, L"", layers);
			break;
		}
		case 4:
		{
			warTopBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			if (!warBoxIgnoreLast)
				warBotBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
			else
				warBotBox->drawBox(graphics, pen, font3, centerFormat, textBrush, backBrush, L"", layers);
			break;
		}
		default:
			break;
		}

	}
	else // Actual graphics
	{
		warWithBox->drawBox(graphics, pen, headFont, centerFormat, textBrush, redBrush, L"At War With", layers);

		switch (warBoxFormat)
		{
		case 1:
		{
			warD1Tri->drawTri(graphics, pen, warD1Brush, layers);
			warD2Tri->drawTri(graphics, pen, warD2Brush, layers);
			warD3Tri->drawTri(graphics, pen, warD3Brush, layers);
			warTRBox->drawBox(graphics, pen, font1, centerFormat, textBrush, warTRBrush, name1, layers);
			warBLBox->drawBox(graphics, pen, font2, centerFormat, textBrush, warBLBrush, name2, layers);
			warBRBox->drawBox(graphics, pen, font3, centerFormat, textBrush, warBRBrush, name3, layers);
			break;
		}
		case 3:
		{
			warTLBox->drawBox(graphics, pen, font0, centerFormat, textBrush, warTLBrush, name0, layers);
			warTRBox->drawBox(graphics, pen, font1, centerFormat, textBrush, warTRBrush, name1, layers);
			warBLBox->drawBox(graphics, pen, font2, centerFormat, textBrush, warBLBrush, name2, layers);
			if (!warBoxIgnoreLast)
				warBRBox->drawBox(graphics, pen, font3, centerFormat, textBrush, warBRBrush, name3, layers);
			else
				warBRBox->drawBox(graphics, pen, font3, centerFormat, textBrush, backBrush, L"", layers);

			break;
		}
		case 4:
		{
			warTopBox->drawBox(graphics, pen, font0, centerFormat, textBrush, warTopBrush, name0, layers);
			if (!warBoxIgnoreLast)
				warBotBox->drawBox(graphics, pen, font1, centerFormat, textBrush, warBotBrush, name1, layers);
			else
				warBotBox->drawBox(graphics, pen, font3, centerFormat, textBrush, backBrush, L"", layers);
			break;
		}
		default:
			break;
		}
	}
}

