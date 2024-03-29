#include "../header/CitiesSection.h"

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

void CitiesSection::drawCityBox(Graphics* graphics, int gameType, int city, DBG& dbg)
{
	if (dbg.boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg.sections) // Show box names
	{
		cityFrame->drawBox6(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, dbg.layers, true);

		berlinBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		romeBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		washBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		londonBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		parisBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		moscowBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		tokyoBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		calcBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		sydBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);

		warsawBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		ottawaBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		cairoBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		leninBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		stalinBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		shangBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		hongBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		manilaBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		honoBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, dbg.layers);
		sanfranBox->drawFrameFill(graphics, borderPen, baseSanFranFont, centerFormat, textBrush, backBrush, dbg.layers);
	}
	else // Actual graphics
	{
		if (gameType == EUROPE_GAME)
		{
			if (city == CITY_ALL)
			{
				tokyoBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, jpnBrushF, L"", dbg.layers);
				calcBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", dbg.layers);
				sydBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, anzBrushF, L"", dbg.layers);

				shangBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, jpnBrushF, L"", dbg.layers);
				hongBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", dbg.layers);
				manilaBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, usaBrushF, L"", dbg.layers);
				honoBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, usaBrushF, L"", dbg.layers);
			}
		}
		else
		{
			if (city == CITY_TOKYO || city == CITY_ALL)
				tokyoBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, tokyoBrush, dbg.layers);
			if (city == CITY_CALC || city == CITY_ALL)
				calcBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, calcBrush, dbg.layers);
			if (city == CITY_SYDNEY || city == CITY_ALL)
				sydBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, sydBrush, dbg.layers);

			if (city == CITY_SHANG || city == CITY_ALL)
				shangBox->drawFrameFill(graphics, pen, cityFont, centerFormat, textBrush, shangBrush, dbg.layers);
			if (city == CITY_HONG || city == CITY_ALL)
				hongBox->drawFrameFill(graphics, pen, hongFont, centerFormat, textBrush, hongBrush, dbg.layers);
			if (city == CITY_MANILA || city == CITY_ALL)
				manilaBox->drawFrameFill(graphics, pen, cityFont, centerFormat, textBrush, manilaBrush, dbg.layers);
			if (city == CITY_HONO || city == CITY_ALL)
				honoBox->drawFrameFill(graphics, pen, cityFont, centerFormat, textBrush, honoBrush, dbg.layers);
		}

		if (gameType == PACIFIC_GAME)
		{
			if (city == CITY_ALL)
			{
				berlinBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, gerBrushF, L"", dbg.layers);
				romeBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, itaBrushF, L"", dbg.layers);
				londonBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", dbg.layers);
				parisBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, fraBrushF, L"", dbg.layers);
				moscowBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, sovBrushF, L"", dbg.layers);

				warsawBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, gerBrushF, L"", dbg.layers);
				ottawaBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", dbg.layers);
				cairoBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, ukBrushF, L"", dbg.layers);
				leninBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, sovBrushF, L"", dbg.layers);
				stalinBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, sovBrushF, L"", dbg.layers);
			}
		}
		else
		{
			if (city == CITY_BERLIN || city == CITY_ALL)
				berlinBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, berlinBrush, dbg.layers);
			if (city == CITY_ROME || city == CITY_ALL)
				romeBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, romeBrush, dbg.layers);
			if (city == CITY_LONDON || city == CITY_ALL)
				londonBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, londonBrush, dbg.layers);
			if (city == CITY_PARIS || city == CITY_ALL)
				parisBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, parisBrush, dbg.layers);
			if (city == CITY_MOSCOW || city == CITY_ALL)
				moscowBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, moscowBrush, dbg.layers);

			if (city == CITY_WARSAW || city == CITY_ALL)
				warsawBox->drawFrameFill(graphics, pen, cityFont, centerFormat, textBrush, warsawBrush, dbg.layers);
			if (city == CITY_OTTAWA || city == CITY_ALL)
				ottawaBox->drawFrameFill(graphics, pen, cityFont, centerFormat, textBrush, ottawaBrush, dbg.layers);
			if (city == CITY_CAIRO || city == CITY_ALL)
				cairoBox->drawFrameFill(graphics, pen, cityFont, centerFormat, textBrush, cairoBrush, dbg.layers);
			if (city == CITY_LENIN || city == CITY_ALL)
				leninBox->drawFrameFill(graphics, pen, cityFont, centerFormat, textBrush, leninBrush, dbg.layers);
			if (city == CITY_STALIN || city == CITY_ALL)
				stalinBox->drawFrameFill(graphics, pen, cityFont, centerFormat, textBrush, stalinBrush, dbg.layers);
		}

		if (gameType == EUROPE_GAME)
		{
			if (city == CITY_WASH || city == CITY_ALL)
				washBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, washBrush, dbg.layers);
			if (city == CITY_ALL)
				sanfranBox->drawBox(graphics, pen, sanFranFont, centerFormat, textBrush, usaBrushF, L"", dbg.layers);
		}
		else if (gameType == PACIFIC_GAME)
		{
			if (city == CITY_ALL)
				washBox->drawBox(graphics, pen, cityFont, centerFormat, textBrush, sanfranBrush, L"San Francisco", dbg.layers);
			if (city == CITY_SANFRAN || city == CITY_ALL)
				sanfranBox->drawBox(graphics, pen, sanFranFont, centerFormat, textBrush, usaBrushF, L"", dbg.layers);
		}
		else if (gameType == GLOBAL_GAME)
		{
			if (city == CITY_WASH || city == CITY_ALL)
				washBox->drawFrameFill(graphics, pen, capFont, centerFormat, textBrush, washBrush, dbg.layers);
			if (city == CITY_SANFRAN || city == CITY_ALL)
				sanfranBox->drawFrameFill(graphics, pen, sanFranFont, centerFormat, textBrush, sanfranBrush, dbg.layers);
		}		
	}
}

