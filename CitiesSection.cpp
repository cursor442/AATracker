#include "CitiesSection.h"

CitiesSection::CitiesSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	cityFrame = new AABox6("City Section");

	berlinBox = new AABox("Berlin");
	romeBox = new AABox("Rome");
	washBox = new AABox("Washington");
	londonBox = new AABox("London");
	parisBox = new AABox("Paris");
	moscowBox = new AABox("Moscow");
	tokyoBox = new AABox("Tokyo");
	calcBox = new AABox("Calcutta");
	sydBox = new AABox("Sydney");

	warsawBox = new AABox("Warsaw");
	ottawaBox = new AABox("Ottawa");
	cairoBox = new AABox("Cairo");
	leninBox = new AABox("Leningrad");
	stalinBox = new AABox("Stalingrad");
	shangBox = new AABox("Shanghai");
	hongBox = new AABox("Hong Kong");
	manilaBox = new AABox("Manila");
	honoBox = new AABox("Honolulu");
	sanfranBox = new AABox("San Francisco");

	capFont = NULL;
	cityFont = NULL;
	hongFont = NULL;
	baseSanFranFont = NULL;
	sanFranFont = NULL;

	berlinBrush	= NULL;
	romeBrush	= NULL;
	washBrush	= NULL;
	londonBrush	= NULL;
	parisBrush	= NULL;
	moscowBrush	= NULL;
	tokyoBrush	= NULL;
	calcBrush	= NULL;
	sydBrush	= NULL;

	warsawBrush	 = NULL;
	ottawaBrush	 = NULL;
	cairoBrush	 = NULL;
	leninBrush	 = NULL;
	stalinBrush	 = NULL;
	shangBrush	 = NULL;
	hongBrush	 = NULL;
	manilaBrush	 = NULL;
	honoBrush	 = NULL;
	sanfranBrush = NULL;
}

CitiesSection::~CitiesSection()
{
	delete cityFrame;

	delete berlinBox;
	delete romeBox;
	delete washBox;
	delete londonBox;
	delete parisBox;
	delete moscowBox;
	delete tokyoBox;
	delete calcBox;
	delete sydBox;

	delete warsawBox;
	delete ottawaBox;
	delete cairoBox;
	delete leninBox;
	delete stalinBox;
	delete shangBox;
	delete hongBox;
	delete manilaBox;
	delete honoBox;
	delete sanfranBox;
}

void CitiesSection::configureCityBox(RectF& frameL, RectF& frameR, int layer)
{
	cityFrame->config({frameL.X, frameL.Y},
		{frameL.X, frameL.GetBottom()},
		{frameR.GetRight(), frameR.GetBottom()},
		{frameR.GetRight(), frameR.Y},
		{frameR.X, frameR.Y},
		{frameL.GetRight(), frameL.Y},
		frameL, frameR,	layer);


	berlinBox->config(frameL, layer + 1);
	berlinBox->box.Width = frameL.Width / 3;
	berlinBox->box.Height = frameL.Height / 3;

	romeBox->config(berlinBox->box, layer + 1);
	romeBox->box.X = berlinBox->box.GetRight();

	tokyoBox->config(romeBox->box, layer + 1);
	tokyoBox->box.X = romeBox->box.GetRight();
	tokyoBox->box.Width = frameL.GetRight() - tokyoBox->box.X;

	londonBox->config(berlinBox->box, layer + 1);
	londonBox->box.Y = berlinBox->box.GetBottom();

	moscowBox->config(londonBox->box, layer + 1);
	moscowBox->box.Y = londonBox->box.GetBottom();
	moscowBox->box.Height = frameL.GetBottom() - moscowBox->box.Y;

	washBox->config(romeBox->box, layer + 1);
	washBox->box.X = londonBox->box.GetRight();
	washBox->box.Y = romeBox->box.GetBottom();

	parisBox->config(washBox->box, layer + 1);
	parisBox->box.X = moscowBox->box.GetRight();
	parisBox->box.Y = washBox->box.GetBottom();

	calcBox->config(tokyoBox->box, layer + 1);
	calcBox->box.Y = tokyoBox->box.GetBottom();

	sydBox->config(calcBox->box, layer + 1);
	sydBox->box.Y = calcBox->box.GetBottom();
	sydBox->box.Height = moscowBox->box.Height;

	cairoBox->config(frameR, layer + 1);
	cairoBox->box.Width = frameR.Width / 2;
	cairoBox->box.Height = frameR.Height / 5;

	hongBox->config(cairoBox->box, layer + 1);
	hongBox->box.X = cairoBox->box.GetRight();
	hongBox->box.Width = frameR.GetRight() - hongBox->box.X;

	leninBox->config(cairoBox->box, layer + 1);
	leninBox->box.Y = cairoBox->box.GetBottom();

	honoBox->config(hongBox->box, layer + 1);
	honoBox->box.Y = hongBox->box.GetBottom();

	ottawaBox->config(leninBox->box, layer + 1);
	ottawaBox->box.Y = leninBox->box.GetBottom();

	manilaBox->config(honoBox->box, layer + 1);
	manilaBox->box.Y = honoBox->box.GetBottom();

	stalinBox->config(ottawaBox->box, layer + 1);
	stalinBox->box.Y = ottawaBox->box.GetBottom();

	shangBox->config(manilaBox->box, layer + 1);
	shangBox->box.Y = manilaBox->box.GetBottom();

	warsawBox->config(stalinBox->box, layer + 1);
	warsawBox->box.Y = stalinBox->box.GetBottom();
	warsawBox->box.Height = frameR.GetBottom() - warsawBox->box.Y;

	sanfranBox->config(shangBox->box, layer + 1);
	sanfranBox->box.Y = shangBox->box.GetBottom();
	sanfranBox->box.Height = frameR.GetBottom() - sanfranBox->box.Y;
}

void CitiesSection::configDrawTools(Font* f0, Font* f1, Font* f2, Font* f3, Font* f4)
{
	capFont = f0;
	cityFont = f1;
	hongFont = f2;
	baseSanFranFont = f3;
	sanFranFont = f4;
}

void CitiesSection::updateFormat(int city, int own, bool thisSide)
{
	SolidBrush* tmp = NULL;
	switch (own)
	{
	case TURN_GER:
	{
		if (thisSide)
			tmp = gerBrushP;
		else
			tmp = gerBrushF;
		break;
	}
	case TURN_SOV:
	{
		if (thisSide)
			tmp = sovBrushP;
		else
			tmp = sovBrushF;
		break;
	}
	case TURN_JPN:
	{
		if (thisSide)
			tmp = jpnBrushP;
		else
			tmp = jpnBrushF;
		break;
	}
	case TURN_USA:
	{
		if (thisSide)
			tmp = usaBrushP;
		else
			tmp = usaBrushF;
		break;
	}
	case TURN_CHN:
	{
		if (thisSide)
			tmp = chnBrushP;
		else
			tmp = chnBrushF;
		break;
	}
	case TURN_UKE: case TURN_UKP:
	{
		if (thisSide)
			tmp = ukBrushP;
		else
			tmp = ukBrushF;
		break;
	}
	case TURN_ITA:
	{
		if (thisSide)
			tmp = itaBrushP;
		else
			tmp = itaBrushF;
		break;
	}
	case TURN_ANZ:
	{
		if (thisSide)
			tmp = anzBrushP;
		else
			tmp = anzBrushF;
		break;
	}
	case TURN_FRA:
	{
		if (thisSide)
			tmp = fraBrushP;
		else
			tmp = fraBrushF;
		break;
	}
	default: break;
	}

	switch (city)
	{
	case CITY_BERLIN:
	{
		berlinBrush = tmp;
		break;
	}
	case CITY_MOSCOW:
	{
		moscowBrush = tmp;
		break;
	}
	case CITY_TOKYO:
	{
		tokyoBrush = tmp;
		break;
	}
	case CITY_WASH:
	{
		washBrush = tmp;
		break;
	}
	case CITY_SANFRAN:
	{
		sanfranBrush = tmp;
		break;
	}
	case CITY_LONDON:
	{
		londonBrush = tmp;
		break;
	}
	case CITY_CALC:
	{
		calcBrush = tmp;
		break;
	}
	case CITY_ROME:
	{
		romeBrush = tmp;
		break;
	}
	case CITY_SYDNEY:
	{
		sydBrush = tmp;
		break;
	}
	case CITY_PARIS:
	{
		parisBrush = tmp;
		break;
	}
	case CITY_OTTAWA:
	{
		ottawaBrush = tmp;
		break;
	}
	case CITY_WARSAW:
	{
		warsawBrush = tmp;
		break;
	}
	case CITY_LENIN:
	{
		leninBrush = tmp;
		break;
	}
	case CITY_STALIN:
	{
		stalinBrush = tmp;
		break;
	}
	case CITY_CAIRO:
	{
		cairoBrush = tmp;
		break;
	}
	case CITY_SHANG:
	{
		shangBrush = tmp;
		break;
	}
	case CITY_HONG:
	{
		hongBrush = tmp;
		break;
	}
	case CITY_MANILA:
	{
		manilaBrush = tmp;
		break;
	}
	case CITY_HONO:
	{
		honoBrush = tmp;
		break;
	}
	default: break;
	}
}

void CitiesSection::drawCityBox(Graphics* graphics, int gameType, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		cityFrame->drawBox6(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers, true);

		berlinBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		romeBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		washBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		londonBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		parisBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		moscowBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		tokyoBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		calcBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		sydBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);

		warsawBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		ottawaBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		cairoBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		leninBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		stalinBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		shangBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		hongBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		manilaBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		honoBox->drawFrame(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		sanfranBox->drawFrame(graphics, borderPen, baseSanFranFont, centerFormat, textBrush, backBrush, layers);
	}
	else // Actual graphics
	{
		if (gameType == EUROPE_GAME)
		{
			tokyoBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, jpnBrushF, L"", layers);
			calcBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", layers);
			sydBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, anzBrushF, L"", layers);

			shangBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, jpnBrushF, L"", layers);
			hongBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", layers);
			manilaBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, usaBrushF, L"", layers);
			honoBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, usaBrushF, L"", layers);
		}
		else
		{
			tokyoBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, tokyoBrush, layers);
			calcBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, calcBrush, layers);
			sydBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, sydBrush, layers);

			shangBox->drawFrame(graphics, pen, cityFont, centerFormat, textBrush, shangBrush, layers);
			hongBox->drawFrame(graphics, pen, hongFont, centerFormat, textBrush, hongBrush, layers);
			manilaBox->drawFrame(graphics, pen, cityFont, centerFormat, textBrush, manilaBrush, layers);
			honoBox->drawFrame(graphics, pen, cityFont, centerFormat, textBrush, honoBrush, layers);
		}

		if (gameType == PACIFIC_GAME)
		{
			berlinBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, gerBrushF, L"", layers);
			romeBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, itaBrushF, L"", layers);
			londonBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", layers);
			parisBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, fraBrushF, L"", layers);
			moscowBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, sovBrushF, L"", layers);

			warsawBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, gerBrushF, L"", layers);
			ottawaBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", layers);
			cairoBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", layers);
			leninBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, sovBrushF, L"", layers);
			stalinBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, sovBrushF, L"", layers);
		}
		else
		{
			berlinBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, berlinBrush, layers);
			romeBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, romeBrush, layers);
			londonBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, londonBrush, layers);
			parisBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, parisBrush, layers);
			moscowBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, moscowBrush, layers);

			warsawBox->drawFrame(graphics, pen, cityFont, centerFormat, textBrush, warsawBrush, layers);
			ottawaBox->drawFrame(graphics, pen, cityFont, centerFormat, textBrush, ottawaBrush, layers);
			cairoBox->drawFrame(graphics, pen, cityFont, centerFormat, textBrush, cairoBrush, layers);
			leninBox->drawFrame(graphics, pen, cityFont, centerFormat, textBrush, leninBrush, layers);
			stalinBox->drawFrame(graphics, pen, cityFont, centerFormat, textBrush, stalinBrush, layers);
		}

		if (gameType == EUROPE_GAME)
		{
			washBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, washBrush, layers);
			sanfranBox->drawBox(graphics, pen, sanFranFont, centerFormat, textBrush, usaBrushF, L"", layers);
		}
		else if (gameType == PACIFIC_GAME)
		{
			washBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, sanfranBrush, L"San Francisco", layers);
			sanfranBox->drawBox(graphics, pen, sanFranFont, centerFormat, textBrush, usaBrushF, L"", layers);
		}
		else if (gameType == GLOBAL_GAME)
		{
			washBox->drawFrame(graphics, pen, capFont, centerFormat, textBrush, washBrush, layers);
			sanfranBox->drawFrame(graphics, pen, sanFranFont, centerFormat, textBrush, sanfranBrush, layers);
		}		
	}
}

