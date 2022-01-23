#include "../header/TerritoriesClass.h"

Territories::Territories()
{
	territories.resize(0);

	gameType = NULL_GAME;
}

Territories::~Territories()
{
	for (int i = 0; i < territories.size(); i++)
		if (territories[i] != NULL)
			delete territories[i];
}

void Territories::setGameType(int type)
{
	gameType = type;

	// Last territory on Pacific map
	// Will just be easier to have both Europe and Pacific arrays the same size as Global
	territories.resize(TER_MEXICO); 

	switch (gameType)
	{
	case EUROPE_GAME:
	{
		configEurTerrs();
		configEurIslands();
		configEurFacilities();
		break;
	}
	case PACIFIC_GAME:
	{
		configPacTerrs();
		configPacIslands();
		configPacFacilities();
		break;
	}
	case GLOBAL_GAME:
	{
		configEurTerrs();
		configEurIslands();
		configEurFacilities();
		configPacTerrs();
		configPacIslands();
		configPacFacilities();
		globalGameAdj();
		break;
	}
	default:
		break;
	}
}

void Territories::configEurTerrs()
{
	//                                            name,     alphabet, original,     owner,       val, map,        isCoastal
	territories[TER_ALBERTA]      = new Territory(alberta      , 3,   TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_ONTARIO]      = new Territory(ontario      , 122, TURN_UKE,     TURN_UKE,     2 , EUROPE_MAP, true );
	territories[TER_QUEBEC]       = new Territory(quebec       , 131, TURN_UKE,     TURN_UKE,     2 , EUROPE_MAP, true );
	territories[TER_NEWFOUNDLAND] = new Territory(newfoundland , 111, TURN_UKE,     TURN_UKE,     0 , EUROPE_MAP, true );
	territories[TER_NEW_BRUNS]    = new Territory(new_bruns    , 106, TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_GREENLAND]    = new Territory(greenland    , 65,  TURN_USA,     TURN_USA,     0 , EUROPE_MAP, true );
	territories[TER_CENTRAL_USA]  = new Territory(cent_usa     , 32,  TURN_USA,     TURN_USA,     12, EUROPE_MAP, true );
	territories[TER_EASTERN_USA]  = new Territory(east_usa     , 44,  TURN_USA,     TURN_USA,     20, EUROPE_MAP, true );
	territories[TER_SE_MEXICO]    = new Territory(s_mexico     , 157, TURN_USA,     TURN_USA,     1 , EUROPE_MAP, true );
	territories[TER_WEST_INDIES]  = new Territory(w_indies     , 192, TURN_USA,     TURN_USA,     1 , EUROPE_MAP, true );
	territories[TER_CENT_AMERICA] = new Territory(cent_am      , 30,  TURN_USA,     TURN_USA,     1 , EUROPE_MAP, true );
	territories[TER_VENEZUELA]    = new Territory(venezuela    , 185, FULL_NEUTRAL, FULL_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_COLOMBIA]     = new Territory(colombia     , 36,  FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_BRIT_GUIANA]  = new Territory(brit_guiana  , 20,  TURN_UKE,     TURN_UKE,     0 , EUROPE_MAP, true );
	territories[TER_SURINAME]     = new Territory(suriname     , 164, DUTCH_TER,    DUTCH_TER,    0 , EUROPE_MAP, true );
	territories[TER_FRA_GUIANA]   = new Territory(fr_guiana    , 56,  TURN_FRA,     TURN_FRA,     0 , EUROPE_MAP, true );
	territories[TER_ECUADOR]      = new Territory(ecuador      , 45,  FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_PERU]         = new Territory(peru         , 126, FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_BOLIVIA]      = new Territory(bolivia      , 17,  FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, false);
	territories[TER_BRAZIL]       = new Territory(brazil       , 19,  ALLY_NEUTRAL, ALLY_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_PARAGUAY]     = new Territory(paraguay     , 124, FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, false);
	territories[TER_URUGUAY]      = new Territory(uruguay      , 184, FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_ARGENTINA]    = new Territory(argentina    , 12,  FULL_NEUTRAL, FULL_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_CHILE]        = new Territory(chile        , 35,  FULL_NEUTRAL, FULL_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_ICELAND]      = new Territory(iceland      , 72,  TURN_UKE,     TURN_UKE,     0 , EUROPE_MAP, true );
	territories[TER_SCOTLAND]     = new Territory(scotland     , 143, TURN_UKE,     TURN_UKE,     2 , EUROPE_MAP, true );
	territories[TER_EIRE]         = new Territory(eire         , 47,  ALLY_NEUTRAL, ALLY_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_UTD_KINGDOM]  = new Territory(utd_kingdom  , 182, TURN_UKE,     TURN_UKE,     6 , EUROPE_MAP, true );
	territories[TER_DENMARK]      = new Territory(denmark      , 39,  TURN_GER,     TURN_GER,     2 , EUROPE_MAP, true );
	territories[TER_HOLL_BELG]    = new Territory(holland      , 69,  TURN_GER,     TURN_GER,     3 , EUROPE_MAP, true );
	territories[TER_WEST_GERMANY] = new Territory(w_germany    , 195, TURN_GER,     TURN_GER,     5 , EUROPE_MAP, true );
	territories[TER_FRANCE]       = new Territory(france       , 53,  TURN_FRA,     TURN_FRA,     4 , EUROPE_MAP, false);
	territories[TER_SWITZERLAND]  = new Territory(switzerland  , 166, FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, false);
	territories[TER_NORMANDY]     = new Territory(normandy     , 113, TURN_FRA,     TURN_FRA,     2 , EUROPE_MAP, true );
	territories[TER_SOUTH_FRANCE] = new Territory(s_france     , 158, TURN_FRA,     TURN_FRA,     3 , EUROPE_MAP, true );
	territories[TER_SPAIN]        = new Territory(spain        , 161, FULL_NEUTRAL, FULL_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_PORTUGAL]     = new Territory(portugal     , 129, FULL_NEUTRAL, FULL_NEUTRAL, 1 , EUROPE_MAP, true );
	territories[TER_GIBRALTAR]    = new Territory(gibraltar    , 60,  TURN_UKE,     TURN_UKE,     0 , EUROPE_MAP, true );
	territories[TER_SARDINIA]     = new Territory(sardinia     , 141, TURN_ITA,     TURN_ITA,     0 , EUROPE_MAP, true );
	territories[TER_NORWAY]       = new Territory(norway       , 117, TURN_GER,     TURN_GER,     3 , EUROPE_MAP, true );
	territories[TER_SWEDEN]       = new Territory(sweden       , 165, FULL_NEUTRAL, FULL_NEUTRAL, 3 , EUROPE_MAP, true );
	territories[TER_FINLAND]      = new Territory(finland      , 51,  AXIS_NEUTRAL, AXIS_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_NORTH_ITALY]  = new Territory(n_italy      , 114, TURN_ITA,     TURN_ITA,     4 , EUROPE_MAP, true );
	territories[TER_SOUTH_ITALY]  = new Territory(s_italy      , 159, TURN_ITA,     TURN_ITA,     3 , EUROPE_MAP, true );
	territories[TER_SICILY]       = new Territory(sicily       , 149, TURN_ITA,     TURN_ITA,     0 , EUROPE_MAP, true );
	territories[TER_GERMANY]      = new Territory(ter_germany  , 59,  TURN_GER,     TURN_GER,     5 , EUROPE_MAP, true );
	territories[TER_S_GERMANY]    = new Territory(s_germany    , 63,  TURN_GER,     TURN_GER,     4 , EUROPE_MAP, false);
	territories[TER_POLAND]       = new Territory(poland       , 128, TURN_GER,     TURN_GER,     2 , EUROPE_MAP, true );
	territories[TER_SLOV_HUNGARY] = new Territory(slovakia     , 152, TURN_GER,     TURN_GER,     3 , EUROPE_MAP, false);
	territories[TER_YUGOSLAVIA]   = new Territory(yugoslavia   , 200, ALLY_NEUTRAL, ALLY_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_ALBANIA]      = new Territory(albania      , 2,   TURN_ITA,     TURN_ITA,     1 , EUROPE_MAP, true );
	territories[TER_GREECE]       = new Territory(greece       , 64,  ALLY_NEUTRAL, ALLY_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_CRETE]        = new Territory(crete        , 37,  ALLY_NEUTRAL, ALLY_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_ROMANIA]      = new Territory(romania      , 135, TURN_GER,     TURN_GER,     3 , EUROPE_MAP, true );
	territories[TER_BULGARIA]     = new Territory(bulgaria     , 23,  AXIS_NEUTRAL, AXIS_NEUTRAL, 1 , EUROPE_MAP, true );
	territories[TER_BALTIC_STATE] = new Territory(baltic       , 13,  TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, true );
	territories[TER_EAST_POLAND]  = new Territory(e_poland     , 43,  TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_KARELIA]      = new Territory(karelia      , 82,  TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, true );
	territories[TER_VYBORG]       = new Territory(vyborg       , 189, TURN_SOV,     TURN_SOV,     0 , EUROPE_MAP, true );
	territories[TER_NOVGOROD]     = new Territory(novgorod     , 118, TURN_SOV,     TURN_SOV,     2 , EUROPE_MAP, true );
	territories[TER_BELARUS]      = new Territory(belarus      , 14,  TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_WEST_UKRAINE] = new Territory(w_ukraine    , 196, TURN_SOV,     TURN_SOV,     2 , EUROPE_MAP, false);
	territories[TER_BESSARABIA]   = new Territory(bessarabia   , 16,  TURN_SOV,     TURN_SOV,     0 , EUROPE_MAP, true );
	territories[TER_ARCHANGEL]    = new Territory(archangel    , 11,  TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, true );
	territories[TER_SMOLENSK]     = new Territory(smolensk     , 153, TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_BRYANSK]      = new Territory(bryansk      , 22,  TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_UKRAINE]      = new Territory(ukraine      , 179, TURN_SOV,     TURN_SOV,     2 , EUROPE_MAP, true );
	territories[TER_ROSTOV]       = new Territory(rostov       , 136, TURN_SOV,     TURN_SOV,     2 , EUROPE_MAP, true );
	territories[TER_CAUCASUS]     = new Territory(caucasus     , 28,  TURN_SOV,     TURN_SOV,     2 , EUROPE_MAP, true );
	territories[TER_NENETSIA]     = new Territory(nenetsia     , 104, TURN_SOV,     TURN_SOV,     0 , EUROPE_MAP, true );
	territories[TER_VOLOGDA]      = new Territory(vologda      , 188, TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_RUSSIA]       = new Territory(russia       , 137, TURN_SOV,     TURN_SOV,     3 , EUROPE_MAP, false);
	territories[TER_TAMBOV]       = new Territory(tambov       , 169, TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_VOLGOGRAD]    = new Territory(volgograd    , 187, TURN_SOV,     TURN_SOV,     2 , EUROPE_MAP, false);
	territories[TER_URALS]        = new Territory(urals        , 183, TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_NOVOSIBIRSK]  = new Territory(novosibirsk  , 119, TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_SAMARA]       = new Territory(samara       , 139, TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, false);
	territories[TER_KAZAKHSTAN]   = new Territory(kazakhstan   , 83,  TURN_SOV,     TURN_SOV,     1 , EUROPE_MAP, true );
	territories[TER_TURKMENISTAN] = new Territory(turkmenistan , 178, TURN_SOV,     TURN_SOV,     0 , EUROPE_MAP, true );
	territories[TER_MOROCCO]      = new Territory(morocco      , 102, TURN_FRA,     TURN_FRA,     1 , EUROPE_MAP, true );
	territories[TER_ALGERIA]      = new Territory(algeria      , 6,   TURN_FRA,     TURN_FRA,     1 , EUROPE_MAP, true );
	territories[TER_TUNISIA]      = new Territory(tunisia      , 176, TURN_FRA,     TURN_FRA,     1 , EUROPE_MAP, true );
	territories[TER_RIO_DE_ORO]   = new Territory(rio_do_oro   , 134, FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_PORT_GUINEA]  = new Territory(port_guinea  , 130, FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_FRA_W_AFRICA] = new Territory(fr_w_africa  , 58,  TURN_FRA,     TURN_FRA,     1 , EUROPE_MAP, true );
	territories[TER_FRA_C_AFRICA] = new Territory(fr_c_africa  , 54,  TURN_FRA,     TURN_FRA,     1 , EUROPE_MAP, false);
	territories[TER_SIERRA_LEONE] = new Territory(sierra       , 150, FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_LIBERIA]      = new Territory(liberia      , 91,  FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_GOLD_COAST]   = new Territory(gold_coast   , 62,  TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_NIGERIA]      = new Territory(nigeria      , 112, TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_LIBYA]        = new Territory(libya        , 92,  TURN_ITA,     TURN_ITA,     1 , EUROPE_MAP, true );
	territories[TER_MALTA]        = new Territory(malta        , 96,  TURN_UKE,     TURN_UKE,     0 , EUROPE_MAP, true );
	territories[TER_TOBRUK]       = new Territory(tobruk       , 172, TURN_ITA,     TURN_ITA,     0 , EUROPE_MAP, true );
	territories[TER_ALEXANDRIA]   = new Territory(alexandria   , 5,   TURN_UKE,     TURN_UKE,     0 , EUROPE_MAP, true );
	territories[TER_EGYPT]        = new Territory(egypt        , 46,  TURN_UKE,     TURN_UKE,     2 , EUROPE_MAP, true );
	territories[TER_FR_EQ_AFRICA] = new Territory(fr_eq_africa , 55,  TURN_FRA,     TURN_FRA,     1 , EUROPE_MAP, true );
	territories[TER_AN_EGY_SUDAN] = new Territory(anglo_sudan  , 8,   TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_ETHIOPIA]     = new Territory(ethiopia     , 48,  TURN_ITA,     TURN_ITA,     1 , EUROPE_MAP, true );
	territories[TER_BRIT_SOMALI]  = new Territory(brit_somali  , 21,  TURN_UKE,     TURN_UKE,     0 , EUROPE_MAP, true );
	territories[TER_ITAL_SOMALI]  = new Territory(it_somali    , 75,  TURN_ITA,     TURN_ITA,     0 , EUROPE_MAP, true );
	territories[TER_BELG_CONGO]   = new Territory(belg_congo   , 15,  TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_KENYA]        = new Territory(kenya        , 84,  TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_TANGANYIKA]   = new Territory(tanganyika   , 170, TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_ANGOLA]       = new Territory(angola       , 9,   FULL_NEUTRAL, FULL_NEUTRAL, 1 , EUROPE_MAP, true );
	territories[TER_RHODESIA]     = new Territory(rhodesia     , 133, TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, false);
	territories[TER_MOZAMBIQUE]   = new Territory(mozambique   , 103, FULL_NEUTRAL, FULL_NEUTRAL, 1 , EUROPE_MAP, true );
	territories[TER_SW_AFRICA]    = new Territory(s_w_africa   , 156, TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_SOUTH_AFRICA] = new Territory(un_s_africa  , 181, TURN_UKE,     TURN_UKE,     2 , EUROPE_MAP, true );
	territories[TER_MADAGASCAR]   = new Territory(madagascar   , 94,  TURN_FRA,     TURN_FRA,     1 , EUROPE_MAP, true );
	territories[TER_TURKEY]       = new Territory(turkey       , 177, FULL_NEUTRAL, FULL_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_CYPRUS]       = new Territory(cyprus       , 38,  TURN_UKE,     TURN_UKE,     0 , EUROPE_MAP, true );
	territories[TER_SYRIA]        = new Territory(syria        , 167, TURN_FRA,     TURN_FRA,     1 , EUROPE_MAP, true );
	territories[TER_TRANS_JORDAN] = new Territory(jordan       , 173, TURN_UKE,     TURN_UKE,     1 , EUROPE_MAP, true );
	territories[TER_IRAQ]         = new Territory(iraq         , 74,  AXIS_NEUTRAL, AXIS_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_SAUDI_ARABIA] = new Territory(saudi_arabia , 142, FULL_NEUTRAL, FULL_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_NW_PERSIA]    = new Territory(nw_persia    , 116, ALLY_NEUTRAL, ALLY_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_PERSIA]       = new Territory(persia       , 125, ALLY_NEUTRAL, ALLY_NEUTRAL, 2 , EUROPE_MAP, true );
	territories[TER_EAST_PERSIA]  = new Territory(e_persia     , 42,  ALLY_NEUTRAL, ALLY_NEUTRAL, 0 , EUROPE_MAP, true );
	territories[TER_AFGHANISTAN]  = new Territory(afghan       , 0,   FULL_NEUTRAL, FULL_NEUTRAL, 0 , EUROPE_MAP, false);
	territories[TER_WEST_INDIA]   = new Territory(w_india      , 191, TURN_UKE,     TURN_UKE,     2 , EUROPE_MAP, true );
}

void Territories::configEurIslands()
{
	territories[TER_ICELAND]->setIsIsland(true);
	territories[TER_WEST_INDIES]->setIsIsland(true);
	territories[TER_SARDINIA]->setIsIsland(true);
	territories[TER_SICILY]->setIsIsland(true);
	territories[TER_CRETE]->setIsIsland(true);
	territories[TER_CYPRUS]->setIsIsland(true);
	territories[TER_MALTA]->setIsIsland(true);
	territories[TER_MADAGASCAR]->setIsIsland(true);
}

void Territories::configEurFacilities()
{
	// Germany
	territories[TER_GERMANY]->placeIC(MAJOR_IC);
	territories[TER_WEST_GERMANY]->placeIC(MAJOR_IC);
	territories[TER_WEST_GERMANY]->placeAirBase();
	territories[TER_WEST_GERMANY]->placeNavalBase();

	// Soviet Union
	territories[TER_RUSSIA]->placeIC(MAJOR_IC);
	territories[TER_RUSSIA]->placeAirBase();
	territories[TER_NOVGOROD]->placeIC(MINOR_IC);
	territories[TER_NOVGOROD]->placeAirBase();
	territories[TER_NOVGOROD]->placeNavalBase();
	territories[TER_UKRAINE]->placeIC(MINOR_IC);
	territories[TER_VOLGOGRAD]->placeIC(MINOR_IC);

	// United States
	territories[TER_EASTERN_USA]->placeIC(MAJOR_IC);
	territories[TER_EASTERN_USA]->placeAirBase();
	territories[TER_EASTERN_USA]->placeNavalBase();
	territories[TER_CENTRAL_USA]->placeIC(MAJOR_IC);

	// United Kingdom
	territories[TER_UTD_KINGDOM]->placeIC(MAJOR_IC);
	territories[TER_UTD_KINGDOM]->placeAirBase();
	territories[TER_UTD_KINGDOM]->placeNavalBase();
	territories[TER_SCOTLAND]->placeAirBase();
	territories[TER_ICELAND]->placeAirBase();
	territories[TER_QUEBEC]->placeIC(MINOR_IC);
	territories[TER_NEW_BRUNS]->placeNavalBase();
	territories[TER_GIBRALTAR]->placeNavalBase();
	territories[TER_EGYPT]->placeNavalBase();
	territories[TER_SOUTH_AFRICA]->placeIC(MINOR_IC);
	territories[TER_SOUTH_AFRICA]->placeNavalBase();

	// Italy
	territories[TER_SOUTH_ITALY]->placeIC(MINOR_IC);
	territories[TER_SOUTH_ITALY]->placeAirBase();
	territories[TER_SOUTH_ITALY]->placeNavalBase();
	territories[TER_NORTH_ITALY]->placeIC(MAJOR_IC);

	// France
	territories[TER_FRANCE]->placeIC(MAJOR_IC);
	territories[TER_FRANCE]->placeAirBase();
	territories[TER_NORMANDY]->placeIC(MINOR_IC);
	territories[TER_NORMANDY]->placeNavalBase();
	territories[TER_SOUTH_FRANCE]->placeIC(MINOR_IC);
	territories[TER_SOUTH_FRANCE]->placeNavalBase();
}

void Territories::configPacTerrs()
{
	//                                            name,     alphabet, original,     owner,       val, map,     isCoastal, isValidForChina
	territories[TER_EVENKIYSKIY]  = new Territory(evenkiyskiy  , 49,  TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, false);
	territories[TER_YENISEY]      = new Territory(yenisey      , 199, TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, false);
	territories[TER_YAKUT]        = new Territory(yakut        , 198, TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, false);
	territories[TER_BURYATIA]     = new Territory(buryatia     , 25,  TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, false);
	territories[TER_SAKHA]        = new Territory(sakha        , 138, TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, false);
	territories[TER_AMUR]         = new Territory(amur         , 7,   TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, true );
	territories[TER_SIBERIA]      = new Territory(siberia      , 148, TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, true );
	territories[TER_SOV_FAR_EAST] = new Territory(sov_far_east , 160, TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, true );
	territories[TER_TIMGUSKA]     = new Territory(timguska     , 171, TURN_SOV,     TURN_SOV,     1 , PACIFIC_MAP, false);
	territories[TER_OLGIY]        = new Territory(olgiy        , 121, MONGOLIA_TER, MONGOLIA_TER, 0 , PACIFIC_MAP, false);
	territories[TER_DZAVHAN]      = new Territory(dzavhan      , 41,  MONGOLIA_TER, MONGOLIA_TER, 0 , PACIFIC_MAP, false);
	territories[TER_TSAGAAN_OLOM] = new Territory(tsagaan      , 174, MONGOLIA_TER, MONGOLIA_TER, 0 , PACIFIC_MAP, false);
	territories[TER_CNT_MONGOLIA] = new Territory(cent_mongol  , 31,  MONGOLIA_TER, MONGOLIA_TER, 0 , PACIFIC_MAP, false);
	territories[TER_ULAANBAATAR]  = new Territory(ulaanbaatar  , 180, MONGOLIA_TER, MONGOLIA_TER, 0 , PACIFIC_MAP, false);
	territories[TER_BUYANT_UHAA]  = new Territory(buyant       , 26,  MONGOLIA_TER, MONGOLIA_TER, 0 , PACIFIC_MAP, false);
	territories[TER_KANSU]        = new Territory(kansu        , 81,  TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_SUIYUAN]      = new Territory(suiyuan      , 162, TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_CHAHAR]       = new Territory(chahar       , 34,  TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_JEHOL]        = new Territory(jehol        , 79,  TURN_CHN,     TURN_JPN,     1 , PACIFIC_MAP, true , true);
	territories[TER_MANCHURIA]    = new Territory(machuria     , 97,  TURN_CHN,     TURN_JPN,     3 , PACIFIC_MAP, true , true);
	territories[TER_KOREA]        = new Territory(korea        , 87,  TURN_JPN,     TURN_JPN,     3 , PACIFIC_MAP, true );
	territories[TER_TSINGHAI]     = new Territory(tsinghai     , 175, TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_SHENSI]       = new Territory(shensi       , 146, TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_HOPEI]        = new Territory(hopei        , 70,  TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_ANHWE]        = new Territory(anwhe        , 10,  TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_SHANTUNG]     = new Territory(shantung     , 145, TURN_CHN,     TURN_JPN,     2 , PACIFIC_MAP, true , true);
	territories[TER_KIANGSU]      = new Territory(kiangsu      , 86,  TURN_CHN,     TURN_JPN,     3 , PACIFIC_MAP, true , true);
	territories[TER_SIKANG]       = new Territory(sikang       , 151, TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_SZECHWAN]     = new Territory(szechwan     , 168, TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_KWEICHOW]     = new Territory(kweichow     , 90,  TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_HUNAN]        = new Territory(hunan        , 71,  TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_KIANGSI]      = new Territory(kiangsi      , 85,  TURN_CHN,     TURN_JPN,     1 , PACIFIC_MAP, true , true);
	territories[TER_YUNNAN]       = new Territory(yunnan       , 201, TURN_CHN,     TURN_CHN,     1 , PACIFIC_MAP, false, true);
	territories[TER_KWANGSI]      = new Territory(kwangsi      , 88,  TURN_CHN,     TURN_JPN,     1 , PACIFIC_MAP, true , true);
	territories[TER_KWANGTUNG]    = new Territory(kwangtung    , 89,  TURN_UKP,     TURN_UKP,     3 , PACIFIC_MAP, true , true);
	territories[TER_INDIA]        = new Territory(india        , 73,  TURN_UKP,     TURN_UKP,     3 , PACIFIC_MAP, true );
	territories[TER_CEYLON]       = new Territory(ceylon       , 33,  TURN_UKP,     TURN_UKP,     0 , PACIFIC_MAP, true );
	territories[TER_BURMA]        = new Territory(burma        , 24,  TURN_UKP,     TURN_UKP,     1 , PACIFIC_MAP, true , true);
	territories[TER_SHAN_STATE]   = new Territory(shan_state   , 144, TURN_UKP,     TURN_UKP,     1 , PACIFIC_MAP, true );
	territories[TER_SIAM]         = new Territory(siam         , 147, TURN_JPN,     TURN_JPN,     1 , PACIFIC_MAP, true );
	territories[TER_FR_IND_CHINA] = new Territory(fr_in_china  , 57,  TURN_FRA,     TURN_FRA,     2 , PACIFIC_MAP, true );
	territories[TER_MALAYA]       = new Territory(malaya       , 95,  TURN_UKP,     TURN_UKP,     3 , PACIFIC_MAP, true );
	territories[TER_W_AUSTRALIA]  = new Territory(w_australia  , 193, TURN_ANZ,     TURN_ANZ,     1 , PACIFIC_MAP, true );
	territories[TER_N_TERRITORY]  = new Territory(n_territory  , 115, TURN_ANZ,     TURN_ANZ,     1 , PACIFIC_MAP, true );
	territories[TER_S_AUSTRALIA]  = new Territory(s_australia  , 155, TURN_ANZ,     TURN_ANZ,     1 , PACIFIC_MAP, true );
	territories[TER_QUEENSLAND]   = new Territory(queensland   , 132, TURN_ANZ,     TURN_ANZ,     2 , PACIFIC_MAP, true );
	territories[TER_NEW_S_WALES]  = new Territory(n_s_wales    , 109, TURN_ANZ,     TURN_ANZ,     2 , PACIFIC_MAP, true );
	territories[TER_VICTORIA]     = new Territory(victoria     , 186, TURN_ANZ,     TURN_ANZ,     1 , PACIFIC_MAP, true );
	territories[TER_NEW_ZEALAND]  = new Territory(new_zealand  , 110, TURN_ANZ,     TURN_ANZ,     2 , PACIFIC_MAP, true );
	territories[TER_JAPAN]        = new Territory(japan        , 77,  TURN_JPN,     TURN_JPN,     8 , PACIFIC_MAP, true );
	territories[TER_OKINAWA]      = new Territory(okinawa      , 120, TURN_JPN,     TURN_JPN,     1 , PACIFIC_MAP, true );
	territories[TER_IWO_JIMA]     = new Territory(iwo_jima     , 76,  TURN_JPN,     TURN_JPN,     1 , PACIFIC_MAP, true );
	territories[TER_MIDWAY]       = new Territory(midway       , 101, TURN_USA,     TURN_USA,     0 , PACIFIC_MAP, true );
	territories[TER_FORMOSA]      = new Territory(formosa      , 52,  TURN_JPN,     TURN_JPN,     1 , PACIFIC_MAP, true );
	territories[TER_MARIANAS]     = new Territory(marianas     , 98,  TURN_JPN,     TURN_JPN,     0 , PACIFIC_MAP, true );
	territories[TER_WAKE_ISLAND]  = new Territory(wake         , 190, TURN_USA,     TURN_USA,     0 , PACIFIC_MAP, true );
	territories[TER_HAWAII]       = new Territory(hawaii       , 68,  TURN_USA,     TURN_USA,     1 , PACIFIC_MAP, true );
	territories[TER_GUAM]         = new Territory(guam         , 66,  TURN_USA,     TURN_USA,     0 , PACIFIC_MAP, true );
	territories[TER_MARSHALL_ISL] = new Territory(marshall     , 99,  TURN_JPN,     TURN_JPN,     0 , PACIFIC_MAP, true );
	territories[TER_JOHNSTON_ISL] = new Territory(johnston     , 80,  TURN_USA,     TURN_USA,     0 , PACIFIC_MAP, true );
	territories[TER_LINE_ISLANDS] = new Territory(line         , 93,  TURN_USA,     TURN_USA,     0 , PACIFIC_MAP, true );
	territories[TER_GILBERT_ISL]  = new Territory(gilbert      , 61,  TURN_UKP,     TURN_UKP,     0 , PACIFIC_MAP, true );
	territories[TER_FIJI]         = new Territory(fiji         , 50,  TURN_UKP,     TURN_UKP,     0 , PACIFIC_MAP, true );
	territories[TER_SAMOA]        = new Territory(samoa        , 140, TURN_UKP,     TURN_UKP,     0 , PACIFIC_MAP, true );
	territories[TER_NEW_HEBRIDES] = new Territory(hebrides     , 108, TURN_FRA,     TURN_FRA,     0 , PACIFIC_MAP, true );
	territories[TER_SOLOMON_ISL]  = new Territory(solomon      , 154, TURN_ANZ,     TURN_ANZ,     0 , PACIFIC_MAP, true );
	territories[TER_NEW_BRITAIN]  = new Territory(new_britain  , 105, TURN_ANZ,     TURN_ANZ,     0 , PACIFIC_MAP, true );
	territories[TER_NEW_GUINEA]   = new Territory(new_guinea   , 107, TURN_ANZ,     TURN_ANZ,     0 , PACIFIC_MAP, true );
	territories[TER_DUT_N_GUINEA] = new Territory(dut_n_guinea , 40,  DUTCH_TER,    DUTCH_TER,    0 , PACIFIC_MAP, true );
	territories[TER_CAROLINE_ISL] = new Territory(caroline     , 27,  TURN_JPN,     TURN_JPN,     0 , PACIFIC_MAP, true );
	territories[TER_PALAU_ISL]    = new Territory(palau        , 123, TURN_JPN,     TURN_JPN,     0 , PACIFIC_MAP, true );
	territories[TER_PHILIPPINES]  = new Territory(philippines  , 127, TURN_USA,     TURN_USA,     2 , PACIFIC_MAP, true );
	territories[TER_CELEBES]      = new Territory(celebes      , 29,  DUTCH_TER,    DUTCH_TER,    3 , PACIFIC_MAP, true );
	territories[TER_BORNEO]       = new Territory(borneo       , 18,  TURN_UKP,     TURN_UKP,     4 , PACIFIC_MAP, true );
	territories[TER_JAVA]         = new Territory(java         , 78,  DUTCH_TER,    DUTCH_TER,    4 , PACIFIC_MAP, true );
	territories[TER_SUMATRA]      = new Territory(sumatra      , 163, DUTCH_TER,    DUTCH_TER,    4 , PACIFIC_MAP, true );
	territories[TER_HAINAN]       = new Territory(hainan       , 67,  TURN_JPN,     TURN_JPN,     0 , PACIFIC_MAP, true );
	territories[TER_ALASKA]       = new Territory(alaska       , 1,   TURN_USA,     TURN_USA,     2 , PACIFIC_MAP, true );
	territories[TER_ALEUTIAN_ISL] = new Territory(aleutian     , 4,   TURN_USA,     TURN_USA,     0 , PACIFIC_MAP, true );
	territories[TER_W_CANADA]     = new Territory(w_canada     , 194, TURN_UKP,     TURN_UKP,     1 , PACIFIC_MAP, true );
	territories[TER_WESTERN_USA]  = new Territory(west_usa     , 197, TURN_USA,     TURN_USA,     10, PACIFIC_MAP, true );
	territories[TER_MEXICO]       = new Territory(mexico       , 100, TURN_USA,     TURN_USA,     2 , PACIFIC_MAP, true );
}

void Territories::configPacIslands()
{
	// By game definition, I guess Japan isn't an island
	// Nor are Dutch New Guinea and New Guinea - not important since they are worth 0 IPC
	territories[TER_OKINAWA]->setIsIsland(true);
	territories[TER_FORMOSA]->setIsIsland(true);
	territories[TER_HAINAN]->setIsIsland(true);
	territories[TER_CEYLON]->setIsIsland(true);
	territories[TER_SUMATRA]->setIsIsland(true);
	territories[TER_JAVA]->setIsIsland(true);
	territories[TER_BORNEO]->setIsIsland(true);
	territories[TER_CELEBES]->setIsIsland(true);
	territories[TER_PHILIPPINES]->setIsIsland(true);
	territories[TER_GUAM]->setIsIsland(true);
	territories[TER_PALAU_ISL]->setIsIsland(true);
	territories[TER_ALEUTIAN_ISL]->setIsIsland(true);
	territories[TER_IWO_JIMA]->setIsIsland(true);
	territories[TER_MARIANAS]->setIsIsland(true);
	territories[TER_CAROLINE_ISL]->setIsIsland(true);
	territories[TER_NEW_BRITAIN]->setIsIsland(true);
	territories[TER_SOLOMON_ISL]->setIsIsland(true);
	territories[TER_NEW_HEBRIDES]->setIsIsland(true);
	territories[TER_NEW_ZEALAND]->setIsIsland(true);
	territories[TER_GILBERT_ISL]->setIsIsland(true);
	territories[TER_MARSHALL_ISL]->setIsIsland(true);
	territories[TER_WAKE_ISLAND]->setIsIsland(true);
	territories[TER_MIDWAY]->setIsIsland(true);
	territories[TER_HAWAII]->setIsIsland(true);
	territories[TER_JOHNSTON_ISL]->setIsIsland(true);
	territories[TER_LINE_ISLANDS]->setIsIsland(true);
	territories[TER_FIJI]->setIsIsland(true);
	territories[TER_SAMOA]->setIsIsland(true);
}

void Territories::configPacFacilities()
{
	// Japan
	territories[TER_JAPAN]->placeIC(MAJOR_IC);
	territories[TER_JAPAN]->placeAirBase();
	territories[TER_JAPAN]->placeNavalBase();
	territories[TER_CAROLINE_ISL]->placeAirBase();
	territories[TER_CAROLINE_ISL]->placeNavalBase();

	// United States
	territories[TER_WESTERN_USA]->placeIC(MAJOR_IC);
	territories[TER_WESTERN_USA]->placeAirBase();
	territories[TER_WESTERN_USA]->placeNavalBase();
	territories[TER_HAWAII]->placeAirBase();
	territories[TER_HAWAII]->placeNavalBase();
	territories[TER_MIDWAY]->placeAirBase();
	territories[TER_WAKE_ISLAND]->placeAirBase();
	territories[TER_GUAM]->placeAirBase();
	territories[TER_PHILIPPINES]->placeAirBase();
	territories[TER_PHILIPPINES]->placeNavalBase();

	// United Kingdom
	territories[TER_INDIA]->placeIC(MAJOR_IC);
	territories[TER_INDIA]->placeAirBase();
	territories[TER_INDIA]->placeNavalBase();

	// ANZAC
	territories[TER_NEW_S_WALES]->placeIC(MINOR_IC);
	territories[TER_NEW_S_WALES]->placeNavalBase();
	territories[TER_QUEENSLAND]->placeAirBase();
	territories[TER_QUEENSLAND]->placeNavalBase();
	territories[TER_NEW_ZEALAND]->placeAirBase();
	territories[TER_NEW_ZEALAND]->placeNavalBase();
}

void Territories::globalGameAdj()
{
	// United Kingdom territories swap maps
	territories[TER_WEST_INDIA]->setOriginal(TURN_UKP); territories[TER_WEST_INDIA]->setOwner(TURN_UKP);
	territories[TER_WEST_INDIA]->setMap(PACIFIC_MAP);

	territories[TER_W_CANADA]->setOriginal(TURN_UKE); territories[TER_W_CANADA]->setOwner(TURN_UKE);
	territories[TER_W_CANADA]->setMap(EUROPE_MAP);

	// Downgrade United States ICs
	territories[TER_EASTERN_USA]->downgradeIC();
	territories[TER_CENTRAL_USA]->downgradeIC();
	territories[TER_WESTERN_USA]->downgradeIC();
}
