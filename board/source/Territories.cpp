#include "../header/BoardClass.h"

void Board::configureTerritories()
{
	territories[TER_ALBERTA]      = { TEXT("Alberta, Saskatchewan, Manitoba"), 3  , TURN_UKE,     1 };
	territories[TER_ONTARIO]      = { TEXT("Ontario"),                         121, TURN_UKE,     2 };
	territories[TER_QUEBEC]       = { TEXT("Quebec"),                          130, TURN_UKE,     2 };
	territories[TER_NEWFOUNDLAND] = { TEXT("Newfoundland & Labrador"),         110, TURN_UKE,     0 };
	territories[TER_NEW_BRUNS]    = { TEXT("New Brunswick & Nova Scotia"),     105, TURN_UKE,     1 };
	territories[TER_CENTRAL_USA]  = { TEXT("Central United States"),           32 , TURN_USA,     12 };
	territories[TER_EASTERN_USA]  = { TEXT("Eastern United States"),           44 , TURN_USA,     20 };
	territories[TER_SE_MEXICO]    = { TEXT("Southeast Mexico"),                156, TURN_USA,     1 };
	territories[TER_WEST_INDIES]  = { TEXT("West Indies"),                     191, TURN_USA,     1 };
	territories[TER_CENT_AMERICA] = { TEXT("Central America"),                 30 , TURN_USA,     1 };
	territories[TER_VENEZUELA]    = { TEXT("Venezuela"),                       184, FULL_NEUTRAL, 2 };
	territories[TER_COLOMBIA]     = { TEXT("Colombia"),                        36 , FULL_NEUTRAL, 0 };
	territories[TER_BRIT_GUIANA]  = { TEXT("British Guiana"),                  20 , TURN_UKE,     0 };
	territories[TER_SURINAME]     = { TEXT("Suriname"),                        163, DUTCH_TER,    0 };
	territories[TER_FRA_GUIANA]   = { TEXT("French Guiana"),                   56 , TURN_FRA,     0 };
	territories[TER_ECUADOR]      = { TEXT("Ecuador"),                         45 , FULL_NEUTRAL, 0 };
	territories[TER_PERU]         = { TEXT("Peru"),                            125, FULL_NEUTRAL, 0 };
	territories[TER_BOLIVIA]      = { TEXT("Bolivia"),                         17 , FULL_NEUTRAL, 0 };
	territories[TER_BRAZIL]       = { TEXT("Brazil"),                          19 , ALLY_NEUTRAL, 2 };
	territories[TER_PARAGUAY]     = { TEXT("Paraguay"),                        123, FULL_NEUTRAL, 0 };
	territories[TER_URUGUAY]      = { TEXT("Uruguay"),                         183, FULL_NEUTRAL, 0 };
	territories[TER_ARGENTINA]    = { TEXT("Argentina"),                       12 , FULL_NEUTRAL, 2 };
	territories[TER_CHILE]        = { TEXT("Chile"),                           35 , FULL_NEUTRAL, 2 };
	territories[TER_ICELAND]      = { TEXT("Iceland"),                         71 , TURN_UKE,     0 };
	territories[TER_SCOTLAND]     = { TEXT("Scotland"),                        142, TURN_UKE,     2 };
	territories[TER_EIRE]         = { TEXT("Eire"),                            47 , ALLY_NEUTRAL, 0 };
	territories[TER_UTD_KINGDOM]  = { TEXT("United Kingdom"),                  181, TURN_UKE,     6 };
	territories[TER_DENMARK]      = { TEXT("Denmark"),                         39 , TURN_GER,     2 };
	territories[TER_HOLL_BELG]    = { TEXT("Holland & Belgium"),               68 , TURN_GER,     3 };
	territories[TER_WEST_GERMANY] = { TEXT("Western Germany"),                 194, TURN_GER,     5 };
	territories[TER_FRANCE]       = { TEXT("France"),                          53 , TURN_FRA,     4 };
	territories[TER_SWITZERLAND]  = { TEXT("Switzerland"),                     165, FULL_NEUTRAL, 0 };
	territories[TER_NORMANDY]     = { TEXT("Normandy & Bordeaux"),             112, TURN_FRA,     2 };
	territories[TER_SOUTH_FRANCE] = { TEXT("Southern France"),                 157, TURN_FRA,     3 };
	territories[TER_SPAIN]        = { TEXT("Spain"),                           160, FULL_NEUTRAL, 2 };
	territories[TER_PORTUGAL]     = { TEXT("Portugal"),                        128, FULL_NEUTRAL, 1 };
	territories[TER_GIBRALTAR]    = { TEXT("Gibraltar"),                       60 , TURN_UKE,     0 };
	territories[TER_SARDINIA]     = { TEXT("Sardinia"),                        140, TURN_ITA,     0 };
	territories[TER_NORWAY]       = { TEXT("Norway"),                          116, TURN_GER,     3 };
	territories[TER_SWEDEN]       = { TEXT("Sweden"),                          164, FULL_NEUTRAL, 3 };
	territories[TER_FINLAND]      = { TEXT("Finland"),                         51 , AXIS_NEUTRAL, 2 };
	territories[TER_NORTH_ITALY]  = { TEXT("Northern Italy"),                  113, TURN_ITA,     4 };
	territories[TER_SOUTH_ITALY]  = { TEXT("Southern Italy"),                  158, TURN_ITA,     3 };
	territories[TER_SICILY]       = { TEXT("Sicily"),                          148, TURN_ITA,     0 };
	territories[TER_GERMANY]      = { TEXT("Germany"),                         59 , TURN_GER,     5 };
	territories[TER_S_GERMANY]    = { TEXT("Greater Southern Germany"),        63 , TURN_GER,     4 };
	territories[TER_POLAND]       = { TEXT("Poland"),                          127, TURN_GER,     2 };
	territories[TER_SLOV_HUNGARY] = { TEXT("Slovakia & Hungary"),              151, TURN_GER,     3 };
	territories[TER_YUGOSLAVIA]   = { TEXT("Yugoslavia"),                      199, ALLY_NEUTRAL, 2 };
	territories[TER_ALBANIA]      = { TEXT("Albania"),                         2  , TURN_ITA,     1 };
	territories[TER_GREECE]       = { TEXT("Greece"),                          64 , ALLY_NEUTRAL, 2 };
	territories[TER_CRETE]        = { TEXT("Crete"),                           37 , ALLY_NEUTRAL, 0 };
	territories[TER_ROMANIA]      = { TEXT("Romania"),                         134, TURN_GER,     3 };
	territories[TER_BULGARIA]     = { TEXT("Bulgaria"),                        23 , AXIS_NEUTRAL, 1 };
	territories[TER_BALTIC_STATE] = { TEXT("Baltic States"),                   13 , TURN_SOV,     1 };
	territories[TER_EAST_POLAND]  = { TEXT("Eastern Poland"),                  43 , TURN_SOV,     1 };
	territories[TER_KARELIA]      = { TEXT("Karelia"),                         81 , TURN_SOV,     1 };
	territories[TER_VYBORG]       = { TEXT("Vyborg"),                          188, TURN_SOV,     0 };
	territories[TER_NOVGOROD]     = { TEXT("Novgorod"),                        117, TURN_SOV,     2 };
	territories[TER_BELARUS]      = { TEXT("Belarus"),                         14 , TURN_SOV,     1 };
	territories[TER_WEST_UKRAINE] = { TEXT("Western Ukraine"),                 195, TURN_SOV,     2 };
	territories[TER_BESSARABIA]   = { TEXT("Bessarabia"),                      16 , TURN_SOV,     0 };
	territories[TER_ARCHANGEL]    = { TEXT("Archangel"),                       11 , TURN_SOV,     1 };
	territories[TER_SMOLENSK]     = { TEXT("Smolensk"),                        152, TURN_SOV,     1 };
	territories[TER_BRYANSK]      = { TEXT("Bryansk"),                         22 , TURN_SOV,     1 };
	territories[TER_UKRAINE]      = { TEXT("Ukraine"),                         178, TURN_SOV,     2 };
	territories[TER_ROSTOV]       = { TEXT("Rostov"),                          135, TURN_SOV,     2 };
	territories[TER_CAUCASUS]     = { TEXT("Caucasus"),                        28 , TURN_SOV,     2 };
	territories[TER_NENETSIA]     = { TEXT("Nenetsia"),                        103, TURN_SOV,     0 };
	territories[TER_VOLOGDA]      = { TEXT("Vologda"),                         187, TURN_SOV,     1 };
	territories[TER_RUSSIA]       = { TEXT("Russia"),                          136, TURN_SOV,     3 };
	territories[TER_TAMBOV]       = { TEXT("Tambov"),                          168, TURN_SOV,     1 };
	territories[TER_VOLGOGRAD]    = { TEXT("Volgograd"),                       186, TURN_SOV,     2 };
	territories[TER_URALS]        = { TEXT("Urals"),                           182, TURN_SOV,     1 };
	territories[TER_NOVOSIBIRSK]  = { TEXT("Novosibirsk"),                     118, TURN_SOV,     1 };
	territories[TER_SAMARA]       = { TEXT("Samara"),                          138, TURN_SOV,     1 };
	territories[TER_KAZAKHSTAN]   = { TEXT("Kazakhstan"),                      82 , TURN_SOV,     1 };
	territories[TER_TURKMENISTAN] = { TEXT("Turkmenistan"),                    177, TURN_SOV,     0 };
	territories[TER_MOROCCO]      = { TEXT("Morocco"),                         101, TURN_FRA,     1 };
	territories[TER_ALGERIA]      = { TEXT("Algeria"),                         6  , TURN_FRA,     1 };
	territories[TER_TUNISIA]      = { TEXT("Tunisia"),                         175, TURN_FRA,     1 };
	territories[TER_RIO_DE_ORO]   = { TEXT("Rio de Oro"),                      133, FULL_NEUTRAL, 0 };
	territories[TER_PORT_GUINEA]  = { TEXT("Portuguese Guinea"),               129, FULL_NEUTRAL, 0 };
	territories[TER_FRA_W_AFRICA] = { TEXT("French West Africa"),              58 , TURN_FRA,     1 };
	territories[TER_FRA_C_AFRICA] = { TEXT("French Central Africa"),           54 , TURN_FRA,     1 };
	territories[TER_SIERRA_LEONE] = { TEXT("Sierra Leone"),                    149, FULL_NEUTRAL, 0 };
	territories[TER_LIBERIA]      = { TEXT("Liberia"),                         90 , FULL_NEUTRAL, 0 };
	territories[TER_GOLD_COAST]   = { TEXT("Gold Coast"),                      62 , TURN_UKE,     1 };
	territories[TER_NIGERIA]      = { TEXT("Nigeria"),                         111, TURN_UKE,     1 };
	territories[TER_LIBYA]        = { TEXT("Libya"),                           91 , TURN_ITA,     1 };
	territories[TER_MALTA]        = { TEXT("Malta"),                           95 , TURN_UKE,     0 };
	territories[TER_TOBRUK]       = { TEXT("Tobruk"),                          171, TURN_ITA,     0 };
	territories[TER_ALEXANDRIA]   = { TEXT("Alexandria"),                      5  , TURN_UKE,     0 };
	territories[TER_EGYPT]        = { TEXT("Egypt"),                           46 , TURN_UKE,     2 };
	territories[TER_FR_EQ_AFRICA] = { TEXT("French Equatorial Africa"),        55 , TURN_FRA,     1 };
	territories[TER_AN_EGY_SUDAN] = { TEXT("Anglo-Egyptian Sudan"),            8  , TURN_UKE,     1 };
	territories[TER_ETHIOPIA]     = { TEXT("Ethiopia"),                        48 , TURN_ITA,     1 };
	territories[TER_BRIT_SOMALI]  = { TEXT("British Somaliland"),              21 , TURN_UKE,     0 };
	territories[TER_ITAL_SOMALI]  = { TEXT("Italian Somaliland"),              74 , TURN_ITA,     0 };
	territories[TER_BELG_CONGO]   = { TEXT("Belgian Congo"),                   15 , TURN_UKE,     1 };
	territories[TER_KENYA]        = { TEXT("Kenya"),                           83 , TURN_UKE,     1 };
	territories[TER_TANGANYIKA]   = { TEXT("Tanganyika Territory"),            169, TURN_UKE,     1 };
	territories[TER_ANGOLA]       = { TEXT("Angola"),                          9  , FULL_NEUTRAL, 1 };
	territories[TER_RHODESIA]     = { TEXT("Rhodesia"),                        132, TURN_UKE,     1 };
	territories[TER_MOZAMBIQUE]   = { TEXT("Mozambique"),                      102, FULL_NEUTRAL, 1 };
	territories[TER_SW_AFRICA]    = { TEXT("South West Africa"),               155, TURN_UKE,     1 };
	territories[TER_SOUTH_AFRICA] = { TEXT("Union of South Africa"),           180, TURN_UKE,     2 };
	territories[TER_MADAGASCAR]   = { TEXT("Madagascar"),                      93 , TURN_FRA,     1 };
	territories[TER_TURKEY]       = { TEXT("Turkey"),                          176, FULL_NEUTRAL, 2 };
	territories[TER_CYPRUS]       = { TEXT("Cyprus"),                          38 , TURN_UKE,     0 };
	territories[TER_SYRIA]        = { TEXT("Syria"),                           166, TURN_FRA,     1 };
	territories[TER_TRANS_JORDAN] = { TEXT("Trans-Jordan"),                    172, TURN_UKE,     1 };
	territories[TER_IRAQ]         = { TEXT("Iraq"),                            73 , AXIS_NEUTRAL, 2 };
	territories[TER_SAUDI_ARABIA] = { TEXT("Saudi Arabia"),                    141, FULL_NEUTRAL, 2 };
	territories[TER_NW_PERSIA]    = { TEXT("Northwest Persia"),                115, ALLY_NEUTRAL, 0 };
	territories[TER_PERSIA]       = { TEXT("Persia"),                          124, ALLY_NEUTRAL, 2 };
	territories[TER_EAST_PERSIA]  = { TEXT("Eastern Persia"),                  42 , ALLY_NEUTRAL, 0 };
	territories[TER_AFGHANISTAN]  = { TEXT("Afghanistan"),                     0  , FULL_NEUTRAL, 0 };
	territories[TER_WEST_INDIA]   = { TEXT("West India"),                      190, TURN_UKE,     2 };

	territories[TER_EVENKIYSKIY]  = { TEXT("Evenkiyskiy"),                     49 , TURN_SOV,     1 };
	territories[TER_YENISEY]      = { TEXT("Yenisey"),                         198, TURN_SOV,     1 };
	territories[TER_YAKUT]        = { TEXT("Yakut S.S.R."),                    197, TURN_SOV,     1 };
	territories[TER_BURYATIA]     = { TEXT("Buryatia"),                        25 , TURN_SOV,     1 };
	territories[TER_SAKHA]        = { TEXT("Sakha"),                           137, TURN_SOV,     1 };
	territories[TER_AMUR]         = { TEXT("Amur"),                            7  , TURN_SOV,     1 };
	territories[TER_SIBERIA]      = { TEXT("Siberia"),                         147, TURN_SOV,     1 };
	territories[TER_SOV_FAR_EAST] = { TEXT("Soviet Far East"),                 159, TURN_SOV,     1 };
	territories[TER_TIMGUSKA]     = { TEXT("Timguska"),                        170, TURN_SOV,     1 };
	territories[TER_OLGIY]        = { TEXT("Olgiy"),                           120, MONGOLIA_TER, 0 };
	territories[TER_DZAVHAN]      = { TEXT("Dzavhan"),                         41 , MONGOLIA_TER, 0 };
	territories[TER_TSAGAAN_OLOM] = { TEXT("Tsagaan-Olom"),                    173, MONGOLIA_TER, 0 };
	territories[TER_CNT_MONGOLIA] = { TEXT("Central Mongolia"),                31 , MONGOLIA_TER, 0 };
	territories[TER_ULAANBAATAR]  = { TEXT("Ulaanbaatar"),                     179, MONGOLIA_TER, 0 };
	territories[TER_BUYANT_UHAA]  = { TEXT("Buyant-Uhaa"),                     26 , MONGOLIA_TER, 0 };
	territories[TER_KANSU]        = { TEXT("Kansu"),                           80 , TURN_CHN,     1 };
	territories[TER_SUIYUAN]      = { TEXT("Suiyuan"),                         161, TURN_CHN,     1 };
	territories[TER_CHAHAR]       = { TEXT("Chahar"),                          34 , TURN_CHN,     1 };
	territories[TER_JEHOL]        = { TEXT("Jehol"),                           78 , TURN_JPN,     1 };
	territories[TER_MANCHURIA]    = { TEXT("Manchuria"),                       96 , TURN_JPN,     3 };
	territories[TER_KOREA]        = { TEXT("Korea"),                           86 , TURN_JPN,     3 };
	territories[TER_TSINGHAI]     = { TEXT("Tsinghai"),                        174, TURN_CHN,     1 };
	territories[TER_SHENSI]       = { TEXT("Shensi"),                          145, TURN_CHN,     1 };
	territories[TER_HOPEI]        = { TEXT("Hopei"),                           69 , TURN_CHN,     1 };
	territories[TER_ANHWE]        = { TEXT("Anhwe"),                           10 , TURN_CHN,     1 };
	territories[TER_SHANTUNG]     = { TEXT("Shantung"),                        144, TURN_JPN,     2 };
	territories[TER_KIANGSU]      = { TEXT("Kiangsu"),                         85 , TURN_JPN,     3 };
	territories[TER_SIKANG]       = { TEXT("Sikang"),                          150, TURN_CHN,     1 };
	territories[TER_SZECHWAN]     = { TEXT("Szechwan"),                        167, TURN_CHN,     1 };
	territories[TER_KWEICHOW]     = { TEXT("Kweichow"),                        89 , TURN_CHN,     1 };
	territories[TER_HUNAN]        = { TEXT("Hunan"),                           70 , TURN_CHN,     1 };
	territories[TER_KIANGSI]      = { TEXT("Kiangsi"),                         84 , TURN_JPN,     1 };
	territories[TER_YUNNAN]       = { TEXT("Yunnan"),                          200, TURN_CHN,     1 };
	territories[TER_KWANGSI]      = { TEXT("Kwangsi"),                         87 , TURN_JPN,     1 };
	territories[TER_KWANGTUNG]    = { TEXT("Kwangtung"),                       88 , TURN_UKP,     3 };
	territories[TER_INDIA]        = { TEXT("India"),                           72 , TURN_UKP,     3 };
	territories[TER_CEYLON]       = { TEXT("Ceylon"),                          33 , TURN_UKP,     0 };
	territories[TER_BURMA]        = { TEXT("Burma"),                           24 , TURN_UKP,     1 };
	territories[TER_SHAN_STATE]   = { TEXT("Shan State"),                      143, TURN_UKP,     1 };
	territories[TER_SIAM]         = { TEXT("Siam"),                            146, TURN_JPN,     1 };
	territories[TER_FR_IND_CHINA] = { TEXT("French Indo China"),               57 , TURN_FRA,     2 };
	territories[TER_MALAYA]       = { TEXT("Malaya"),                          94 , TURN_UKP,     3 };
	territories[TER_W_AUSTRALIA]  = { TEXT("Western Australia"),               192, TURN_ANZ,     1 };
	territories[TER_N_TERRITORY]  = { TEXT("Northern Territory"),              114, TURN_ANZ,     1 };
	territories[TER_S_AUSTRALIA]  = { TEXT("South Australia"),                 154, TURN_ANZ,     1 };
	territories[TER_QUEENSLAND]   = { TEXT("Queensland"),                      131, TURN_ANZ,     2 };
	territories[TER_NEW_S_WALES]  = { TEXT("New South Wales"),                 108, TURN_ANZ,     2 };
	territories[TER_VICTORIA]     = { TEXT("Victoria"),                        185, TURN_ANZ,     1 };
	territories[TER_NEW_ZEALAND]  = { TEXT("New Zealand"),                     109, TURN_ANZ,     2 };
	territories[TER_JAPAN]        = { TEXT("Japan"),                           76 , TURN_JPN,     8 };
	territories[TER_OKINAWA]      = { TEXT("Okinawa"),                         119, TURN_JPN,     1 };
	territories[TER_IWO_JIMA]     = { TEXT("Iwo Jima"),                        75 , TURN_JPN,     1 };
	territories[TER_MIDWAY]       = { TEXT("Midway"),                          100, TURN_USA,     0 };
	territories[TER_FORMOSA]      = { TEXT("Formosa"),                         52 , TURN_JPN,     1 };
	territories[TER_MARIANAS]     = { TEXT("Marianas"),                        97 , TURN_JPN,     0 };
	territories[TER_WAKE_ISLAND]  = { TEXT("Wake Island"),                     189, TURN_USA,     0 };
	territories[TER_HAWAII]       = { TEXT("Hawaiian Islands"),                67 , TURN_USA,     1 };
	territories[TER_GUAM]         = { TEXT("Guam"),                            65 , TURN_USA,     0 };
	territories[TER_MARSHALL_ISL] = { TEXT("Marshall Islands"),                98 , TURN_JPN,     0 };
	territories[TER_JOHNSTON_ISL] = { TEXT("Johnston Island"),                 79 , TURN_USA,     0 };
	territories[TER_LINE_ISLANDS] = { TEXT("Line Islands"),                    92 , TURN_USA,     0 };
	territories[TER_GILBERT_ISL]  = { TEXT("Gilbert Islands"),                 61 , TURN_UKP,     0 };
	territories[TER_FIJI]         = { TEXT("Fiji"),                            50 , TURN_UKP,     0 };
	territories[TER_SAMOA]        = { TEXT("Samoa"),                           139, TURN_UKP,     0 };
	territories[TER_NEW_HEBRIDES] = { TEXT("New Hebrides"),                    107, TURN_FRA,     0 };
	territories[TER_SOLOMON_ISL]  = { TEXT("Solomon Islands"),                 153, TURN_ANZ,     0 };
	territories[TER_NEW_BRITAIN]  = { TEXT("New Britain"),                     104, TURN_ANZ,     0 };
	territories[TER_NEW_GUINEA]   = { TEXT("New Guinea"),                      106, TURN_ANZ,     0 };
	territories[TER_DUT_N_GUINEA] = { TEXT("Dutch New Guinea"),                40 , DUTCH_TER,    0 };
	territories[TER_CAROLINE_ISL] = { TEXT("Caroline Islands"),                27 , TURN_JPN,     0 };
	territories[TER_PALAU_ISL]    = { TEXT("Palau Island"),                    122, TURN_JPN,     0 };
	territories[TER_PHILIPPINES]  = { TEXT("Philippines"),                     126, TURN_USA,     2 };
	territories[TER_CELEBES]      = { TEXT("Celebes"),                         29 , DUTCH_TER,    3 };
	territories[TER_BORNEO]       = { TEXT("Borneo"),                          18 , TURN_UKP,     4 };
	territories[TER_JAVA]         = { TEXT("Java"),                            77 , DUTCH_TER,    4 };
	territories[TER_SUMATRA]      = { TEXT("Sumatra"),                         162, DUTCH_TER,    4 };
	territories[TER_HAINAN]       = { TEXT("Hainan"),                          66 , TURN_JPN,     0 };
	territories[TER_ALASKA]       = { TEXT("Alaska"),                          1  , TURN_USA,     2 };
	territories[TER_ALEUTIAN_ISL] = { TEXT("Aleutian Islands"),                4  , TURN_USA,     0 };
	territories[TER_W_CANADA]     = { TEXT("Western Canada"),                  193, TURN_UKP,     1 };
	territories[TER_WEST_USA]     = { TEXT("Western United States"),           196, TURN_USA,     10 };
	territories[TER_MEXICO]       = { TEXT("Mexico"),                          99 , TURN_USA,     2 };

	for (uint16_t i = TER_ALBERTA; i <= TER_MEXICO; i++)
	{
		territories[i].original = territories[i].owner;

		if (territories[i].owner == TURN_GER || territories[i].owner == TURN_ITA || territories[i].owner == TURN_JPN)
			territories[i].side = SIDE_AXIS;
		else if (territories[i].owner == TURN_SOV || territories[i].owner == TURN_USA || territories[i].owner == TURN_CHN || 
			territories[i].owner == TURN_UKE || territories[i].owner == TURN_UKP || territories[i].owner == TURN_ANZ || territories[i].owner == TURN_FRA)
			territories[i].side = SIDE_ALLIES;
		else
			territories[i].side = SIDE_NEUTRAL;
	}

	territories[TER_MANCHURIA].original = TURN_CHN;
	territories[TER_JEHOL].original = TURN_CHN;
	territories[TER_SHANTUNG].original = TURN_CHN;
	territories[TER_KIANGSU].original = TURN_CHN;
	territories[TER_KIANGSI].original = TURN_CHN;
	territories[TER_KWANGSI].original = TURN_CHN;

	if (gameType == GLOBAL_GAME)
	{
		territories[TER_WEST_INDIA].original = TURN_UKP; territories[TER_WEST_INDIA].owner = TURN_UKP;
		territories[TER_W_CANADA].original = TURN_UKE; territories[TER_W_CANADA].owner = TURN_UKE;
	}
}

void Board::setTerritoryOwner(uint16_t ter, uint16_t own)
{
	territories[ter].owner = own;

	if (own == TURN_GER || own == TURN_ITA || own == TURN_JPN)
		territories[ter].side = SIDE_AXIS;
	else if (own == TURN_SOV || own == TURN_USA || own == TURN_CHN || own == TURN_UKE || own == TURN_UKP || own == TURN_ANZ || own == TURN_FRA)
		territories[ter].side = SIDE_ALLIES;
	else
	territories[ter].side = SIDE_NEUTRAL;
}

uint16_t Board::getTerritoryOwner(uint16_t ter)
{
	return territories[ter].owner;
}

void Board::getTerritoryName(uint16_t ter, listTerritory& list)
{
	for (size_t i = 0; i < 32; i++)
		list.name[i] = territories[ter].name[i];

	list.id = ter;
	list.alph = territories[ter].alphabet;
}

uint16_t Board::getTerritoryAlphabet(uint16_t ter)
{
	return territories[ter].alphabet;
}

uint16_t Board::getTerritoryValue(uint16_t ter)
{
	return territories[ter].value;
}

uint16_t Board::getTerritoryOriginal(uint16_t ter)
{
	return territories[ter].original;
}

void Board::transferTerritory(HWND hDlg, int ter, int& own, int &captureAmount, int &prev, bool &isLib, bool& libCap)
{
	int currNat = own;
	prev = territories[ter].owner;
	int orig = territories[ter].original;
	int val = (int)territories[ter].value;

	int transferVal = 0;

	// This is definitely not the best way to do this
	bool isCap = false;
	libCap = false;
	isLib = false;
	switch (ter)
	{
	case TER_GERMANY:
		{
		isCap = true;

		if (whichSide(own) == SIDE_AXIS)
			libCap = true;

		break;
		}
	case TER_RUSSIA:
		{
		isCap = true;

		if (whichSide(own) == SIDE_ALLIES)
			libCap = true;

		break;
		}
	case TER_JAPAN:
		{
		isCap = true;

		if (whichSide(own) == SIDE_AXIS)
			libCap = true;

		break;
		}
	case TER_EASTERN_USA: 
		{
		if (gameType != PACIFIC_GAME)
		{
			isCap = true;

			if (whichSide(own) == SIDE_ALLIES)
				libCap = true;
		}
		break;
		}
	case TER_WEST_USA:
		{
		if (gameType == PACIFIC_GAME)
		{
			isCap = true;

			if (whichSide(own) == SIDE_ALLIES)
				libCap = true;
		}
		break;
		}
	case TER_UTD_KINGDOM:
		{
		isCap = true;

		if (whichSide(own) == SIDE_ALLIES)
			libCap = true;

		break;
		}
	case TER_INDIA:
		{
		isCap = true;

		if (whichSide(own) == SIDE_ALLIES)
			libCap = true;

		break;
		}
	case TER_SOUTH_ITALY:
		{
		isCap = true;

		if (whichSide(own) == SIDE_AXIS)
			libCap = true;

		break;
		}
	case TER_NEW_S_WALES:
		{
		isCap = true;

		if (whichSide(own) == SIDE_ALLIES)
			libCap = true;

		break;
		}
	case TER_FRANCE:
		{
		isCap = true;

		if (whichSide(own) == SIDE_ALLIES)
			libCap = true;

		break;
		}
	default: break;
	}

	// Figure out who gets the added income
	if (isCap && !libCap) // Capturing a capital
		own = own;
	else if (libCap) // Liberating a capital
	{
		own = orig;
		isLib = true;
	}
	else if ((whichSide(own) == whichSide(orig))) // Liberating a territory
	{
		if (nations[orig]->getNationControlsCapital()) // Only liberate if nation has its own capital
		{
			own = orig;
			isLib = true;
		}
		else if (own == orig) // Or if a nation is reclaiming its land regardless of capital
		{
			own = orig;
			isLib = true;
		}
		else
		{
			own = own;
			isLib = false;
		}
	}
	else // Capturing a territory
		own = own;

	// Need to give new owner income first
	nations[own]->addNationIncome(gameTurn, val);

	// Handle capital liberations
	if (libCap)
	{
		switch (own)
		{
		case TURN_GER:
			{
				setNationControlsCapital(TURN_GER, true);
				setCityControl(CITY_BERLIN, SIDE_AXIS, TURN_GER);

				if (isBeforeNation(TURN_GER, currNat))
					nations[TURN_GER]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_GER));
				else
					nations[TURN_GER]->setNationIncome(gameTurn, calcNationIncome(TURN_GER));

				break;
			}
		case TURN_SOV:
			{
				setNationControlsCapital(TURN_SOV, true);
				setCityControl(CITY_MOSCOW, SIDE_ALLIES, TURN_SOV);

				if (isBeforeNation(TURN_SOV, currNat))
					nations[TURN_SOV]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_SOV));
				else
					nations[TURN_SOV]->setNationIncome(gameTurn, calcNationIncome(TURN_SOV));

				break;
			}
		case TURN_JPN:
			{
				setNationControlsCapital(TURN_JPN, true);
				setCityControl(CITY_TOKYO, SIDE_AXIS, TURN_JPN);

				if (isBeforeNation(TURN_JPN, currNat))
					nations[TURN_JPN]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_JPN));
				else
					nations[TURN_JPN]->setNationIncome(gameTurn, calcNationIncome(TURN_JPN));

				break;
			}
		case TURN_USA:
			{
			setNationControlsCapital(TURN_USA, true);
			if (gameType != PACIFIC_GAME)
				setCityControl(CITY_WASH, SIDE_ALLIES, TURN_USA);
			else
				setCityControl(CITY_SANFRAN, SIDE_ALLIES, TURN_USA);

			if (isBeforeNation(TURN_USA, currNat))
				nations[TURN_USA]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_USA));
			else
				nations[TURN_USA]->setNationIncome(gameTurn, calcNationIncome(TURN_USA));

			break;
			}
		case TURN_UKE:
			{
				setNationControlsCapital(TURN_UKE, true);
				setCityControl(CITY_LONDON, SIDE_ALLIES, TURN_UKE);

				if (isBeforeNation(TURN_UKE, currNat))
					nations[TURN_UKE]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_UKE));
				else
					nations[TURN_UKE]->setNationIncome(gameTurn, calcNationIncome(TURN_UKE));

				break;
			}
		case TURN_UKP:
			{
				setNationControlsCapital(TURN_UKP, true);
				setCityControl(CITY_CALC, SIDE_ALLIES, TURN_UKP);

				if (isBeforeNation(TURN_UKP, currNat))
					nations[TURN_UKP]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_UKP));
				else
					nations[TURN_UKP]->setNationIncome(gameTurn, calcNationIncome(TURN_UKP));

				break;
			}
		case TURN_ITA:
			{
				setNationControlsCapital(TURN_ITA, true);
				setCityControl(CITY_ROME, SIDE_AXIS, TURN_ITA);

				if (isBeforeNation(TURN_ITA, currNat))
					nations[TURN_ITA]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_ITA));
				else
					nations[TURN_ITA]->setNationIncome(gameTurn, calcNationIncome(TURN_ITA));

				break;
			}
		case TURN_ANZ:
			{
				setNationControlsCapital(TURN_ANZ, true);
				setCityControl(CITY_SYDNEY, SIDE_ALLIES, TURN_ANZ);

				if (isBeforeNation(TURN_ANZ, currNat))
					nations[TURN_ANZ]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_ANZ));
				else
					nations[TURN_ANZ]->setNationIncome(gameTurn, calcNationIncome(TURN_ANZ));

				break;
			}
		case TURN_FRA:
			{
				setNationControlsCapital(TURN_FRA, true);
				setCityControl(CITY_PARIS, SIDE_ALLIES, TURN_FRA);
				franceLiberated = true;

				if (isBeforeNation(TURN_FRA, currNat))
					nations[TURN_FRA]->setNationIncome(gameTurn + 1, calcNationIncome(TURN_FRA));
				else
					nations[TURN_FRA]->setNationIncome(gameTurn, calcNationIncome(TURN_FRA));

				break;
			}
		default: break;
		}
	}
	// Handle capital captures
	else if (isCap)
	{
		switch (ter)
		{
		case TER_GERMANY:
		{
			if (isBeforeNation(TURN_GER, currNat))
				transferVal = nations[TURN_GER]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_GER]->getNationBank(gameTurn);

			setCityControl(CITY_BERLIN, SIDE_ALLIES, own);

			break;
		}
		case TER_RUSSIA:
		{
			if (isBeforeNation(TURN_SOV, currNat))
				transferVal = nations[TURN_SOV]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_SOV]->getNationBank(gameTurn);

			setCityControl(CITY_MOSCOW, SIDE_AXIS, own);

			break;
		}
		case TER_JAPAN:
		{
			if (isBeforeNation(TURN_JPN, currNat))
				transferVal = nations[TURN_JPN]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_JPN]->getNationBank(gameTurn);

			setCityControl(CITY_TOKYO, SIDE_ALLIES, own);

			break;
		}
		case TER_EASTERN_USA:
		{
			if (isBeforeNation(TURN_USA, currNat))
				transferVal = nations[TURN_USA]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_USA]->getNationBank(gameTurn);

			setCityControl(CITY_WASH, SIDE_AXIS, own);

			break;
		}
		case TER_WEST_USA:
		{
			if (isBeforeNation(TURN_USA, currNat))
				transferVal = nations[TURN_USA]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_USA]->getNationBank(gameTurn);

			setCityControl(CITY_SANFRAN, SIDE_AXIS, own);

			break;
		}
		case TER_UTD_KINGDOM:
		{
			if (isBeforeNation(TURN_UKE, currNat))
				transferVal = nations[TURN_UKE]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_UKE]->getNationBank(gameTurn);

			setCityControl(CITY_LONDON, SIDE_AXIS, own);

			break;
		}
		case TER_INDIA:
		{
			if (isBeforeNation(TURN_UKP, currNat))
				transferVal = nations[TURN_UKP]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_UKP]->getNationBank(gameTurn);

			setCityControl(CITY_CALC, SIDE_AXIS, own);

			break;
		}
		case TER_SOUTH_ITALY:
		{
			if (isBeforeNation(TURN_ITA, currNat))
				transferVal = nations[TURN_ITA]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_ITA]->getNationBank(gameTurn);

			setCityControl(CITY_ROME, SIDE_ALLIES, own);

			break;
		}
		case TER_NEW_S_WALES:
		{
			if (isBeforeNation(TURN_ANZ, currNat))
				transferVal = nations[TURN_ANZ]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_ANZ]->getNationBank(gameTurn);

			setCityControl(CITY_SYDNEY, SIDE_AXIS, own);

			break;
		}
		case TER_FRANCE:
		{
			if (isBeforeNation(TURN_FRA, currNat))
				transferVal = nations[TURN_FRA]->getNationBank(gameTurn + 1);
			else
				transferVal = nations[TURN_FRA]->getNationBank(gameTurn);

			setCityControl(CITY_PARIS, SIDE_AXIS, own);

			break;
		}
		default: break;
		}
	}
	// Handle other territory captures and liberations (if req met)
	else
	{
		switch (ter)
		{
		case TER_ONTARIO:
			setCityControl(CITY_OTTAWA, whichSide(own), own);
			setNAFallen();
			break;
		case TER_POLAND:
			setCityControl(CITY_WARSAW, whichSide(own), own);
			break;
		case TER_NOVGOROD:
			setCityControl(CITY_LENIN, whichSide(own), own);
			break;
		case TER_VOLGOGRAD:
			setCityControl(CITY_STALIN, whichSide(own), own);
			break;
		case TER_EGYPT:
			setCityControl(CITY_CAIRO, whichSide(own), own);
			break;
		case TER_KIANGSU:
			setCityControl(CITY_SHANG, whichSide(own), own);
			break;
		case TER_KWANGTUNG:
			setCityControl(CITY_HONG, whichSide(own), own);
			break;
		case TER_PHILIPPINES:
			setCityControl(CITY_MANILA, whichSide(own), own);
			break;
		case TER_HAWAII:
			setCityControl(CITY_HONO, whichSide(own), own);
			break;
		case TER_W_CANADA: case TER_ALBERTA: case TER_QUEBEC: case TER_NEW_BRUNS:
			setNAFallen();
			break;
		default: break;
		}
	}

	captureAmount = (uint16_t)transferVal;

	// Subtract income from previous owner
	if (isBeforeNation(prev, own))
		nations[prev]->addNationIncome(gameTurn + 1, -1 * val);
	else
		nations[prev]->addNationIncome(gameTurn, -1 * val);

	// Transfer the territory
	setTerritoryOwner(ter, own);
	nations[prev]->addNationTerritories(prev, -1);
	nations[own]->addNationTerritories(own, 1);

	// Update bonuses
	updateBonuses(hDlg, own, false, captureAmount);

	calcNextNationBank(own, gameTurn);

	// check victory



}

//vector<int>& Board::transferTerritory(uint16_t currOwn, uint16_t origOwn)
//{
//
//}

void Board::transferTerritory(HWND hDlg, int currOwn, int origOwn, vector<int> &targets)
{
	int type = gameType;
	int low = (type != PACIFIC_GAME) ? (TER_ALBERTA) : (TER_EVENKIYSKIY);
	int high = (type != EUROPE_GAME) ? (TER_MEXICO) : (TER_WEST_INDIA);

	targets.resize(0);

	// Liberator gives liberated its territories
	for (int i = low; i <= high; i++)
	{
		if (territories[i].owner == currOwn && territories[i].original == origOwn)
		{
			// Transfer the territory
			setTerritoryOwner(i, origOwn);
			nations[currOwn]->addNationTerritories(currOwn, -1);
			nations[origOwn]->addNationTerritories(origOwn, 1);

			int val = territories[i].value;

			// Subtract income from previous owner
			if (isBeforeNation(currOwn, origOwn))
				nations[currOwn]->addNationIncome(gameTurn + 1, -1 * val);
			else
				nations[currOwn]->addNationIncome(gameTurn, -1 * val);

			// Update bonuses, but only if transferring to current nation
			if (origOwn == gameCurrNation)
				updateBonuses(hDlg, origOwn, false, 0);

			calcNextNationBank(origOwn, gameTurn);

			targets.push_back(i);
		}
	}
}

void Board::transferTerritoryAllies(HWND hDlg, uint16_t libNat, vector<vector<int>>& targets)
{
	int type = gameType;
	int low = (type != PACIFIC_GAME) ? (TER_ALBERTA) : (TER_EVENKIYSKIY);
	int high = (type != EUROPE_GAME) ? (TER_MEXICO) : (TER_WEST_INDIA);

	for (int i = 0; i < 10; i++)
		targets[i].resize(0);

	bool currSide = whichSide(libNat);

	// Go through all territories, transfer all territories controlled by allies that originally belonged to
	// liberated nation and adjust economies
	for (int i = low; i <= high; i++)
	{
		// Controlled by same side, originally controlled by liberated nation, not currently controlled by liberated nation
		if (whichSide(territories[i].owner) == currSide && territories[i].original == libNat && territories[i].owner != libNat)
		{
			// Note who the territory is transferred from
			int prevOwn = territories[i].owner;

			// Transfer the territory
			setTerritoryOwner(i, libNat);
			nations[prevOwn]->addNationTerritories(prevOwn, -1);
			nations[libNat]->addNationTerritories(libNat, 1);

			int val = territories[i].value;

			// Subtract income from previous owner
			if (isBeforeNation(prevOwn, libNat))
				nations[prevOwn]->addNationIncome(gameTurn + 1, -1 * val);
			else
				nations[prevOwn]->addNationIncome(gameTurn, -1 * val);

			// Update bonuses only if transferring to current nation
			if (libNat == gameCurrNation)
				updateBonuses(hDlg, libNat, false, 0);

			calcNextNationBank(libNat, gameTurn);

			targets[prevOwn].push_back(i);
		}
	}
}

uint16_t Board::calcNationIncome(uint16_t nat)
{
	uint16_t tot = 0;
	uint16_t low = TER_ALBERTA;
	uint16_t high = TER_MEXICO;

	if (gameType == EUROPE_GAME)
		high = TER_WEST_INDIA;
	else if (gameType == PACIFIC_GAME)
		low = TER_EVENKIYSKIY;

	for (uint16_t i = low; i <= high; i++)
		if (territories[i].owner == nat)
			tot += territories[i].value;

	return tot;
}