#ifndef LOG_TEXT
#define LOG_TEXT

#include "../../board/header/Territories.h"

///////////////////////////////////////////////////////////////////////////
//// Name Section
///////////////////////////////////////////////////////////////////////////

const WCHAR natNames[10][15] = { L"Germany", L"Soviet Union", L"Japan",
	L"United States", L"China", L"United Kingdom", L"United Kingdom",
	L"Italy", L"ANZAC", L"France" };
// Game types
const WCHAR gameTypes[3][13] = { L"Europe 1940", L"Pacific 1940", L"Global 1940" };

///////////////////////////////////////////////////////////////////////////
//// Neutral Section
///////////////////////////////////////////////////////////////////////////

#define NEUTRAL_EUR_S   33
#define NEUTRAL_PAC_S    6

#define NEUTRAL_TEXTLEN 47
#define NEUTRAL_NAMELEN 18

const WCHAR strictNeutral[] = L"Strict Neutral territories have no lean.";
const WCHAR axisNeutral[] = L"Strict Neutral territories are now Pro-Axis.";
const WCHAR allyNeutral[] = L"Strict Neutral territories are now Pro-Allies.";
const WCHAR mongNeutral[] = L"Mongolian Territories are now Pro-Axis.";

const int strictNeutral_len = 41;
const int axisNeutral_len = 45;
const int allyNeutral_len = 47;
const int mongNeutral_len = 40;

// Europe neutrals
const WCHAR eurNeutral[NEUTRAL_EUR_S][NEUTRAL_NAMELEN] = { L"Afghanistan", L"Angola", L"Argentina",
	L"Bolivia", L"Brazil", L"Bulgaria", L"Chile", L"Colombia", L"Crete", L"Eastern Persia",
	L"Ecuador", L"Eire", L"Finland", L"Greece", L"Iraq", L"Liberia", L"Mozambique",
	L"Northwest Persia", L"Paraguay", L"Persia", L"Peru", L"Portugal", L"Portuguese Guinea",
	L"Rio de Oro", L"Saudi Arabia", L"Sierra Leone", L"Spain", L"Sweden", L"Switzerland",
	L"Turkey", L"Uruguay", L"Venezuela", L"Yugoslavia" };
const int eurNeutralPos[NEUTRAL_EUR_S] = { TER_AFGHANISTAN, TER_ANGOLA, TER_ARGENTINA, TER_BOLIVIA, TER_BRAZIL,
	TER_BULGARIA, TER_CHILE, TER_COLOMBIA, TER_CRETE, TER_EAST_PERSIA, TER_ECUADOR, TER_EIRE,
	TER_FINLAND, TER_GREECE, TER_IRAQ, TER_LIBERIA, TER_MOZAMBIQUE, TER_NW_PERSIA, TER_PARAGUAY,
	TER_PERSIA, TER_PERU, TER_PORTUGAL, TER_PORT_GUINEA, TER_RIO_DE_ORO, TER_SAUDI_ARABIA,
	TER_SIERRA_LEONE, TER_SPAIN, TER_SWITZERLAND, TER_TURKEY, TER_URUGUAY, TER_VENEZUELA,
	TER_YUGOSLAVIA };

// Pacific neutrals
const WCHAR pacNeutral[NEUTRAL_PAC_S][NEUTRAL_NAMELEN] = { L"Buyant-Uhaa", L"Central Mongolia", L"Dzavhan",
	L"Olgiy",  L"Tsagaan-Olom", L"Ulaanbaatar",  };
const int pacNeutralPos[NEUTRAL_PAC_S] = { TER_BUYANT_UHAA,  TER_CNT_MONGOLIA,  TER_DZAVHAN,  TER_OLGIY,
	TER_TSAGAAN_OLOM, TER_ULAANBAATAR };

///////////////////////////////////////////////////////////////////////////
//// Log Screen
///////////////////////////////////////////////////////////////////////////

// Nouns
const WCHAR nats[10][20] = { L"Germany ", L"Soviet Union ", L"Japan ",
	L"United States ", L"China ", L"United Kingdom (E) ", L"United Kingdom (P) ",
	L"Italy ", L"ANZAC ", L"France " };
const int nats_len[10] = {8, 13, 6, 14, 6, 19, 19, 6, 6, 7};

// Verbs
const WCHAR setup[] = L"Game Setup.";
const WCHAR war[] = L"Declares War on ";
const WCHAR capture[] = L"Captures ";
const WCHAR liberate[] = L"Liberates ";
const WCHAR reclaim[] = L"Reclaims ";
const WCHAR occupy[] = L"Occupies ";
const WCHAR discover[] = L"Discovers ";
const int setup_len = 11;
const int war_len = 16;
const int capture_len = 9;
const int liberate_len = 10;
const int reclaim_len = 9;
const int occupy_len = 9;
const int discover_len = 10;

// Misc
const WCHAR and_[] = L"and ";
const WCHAR from[] = L"from ";
const WCHAR for_[] = L"for ";
const WCHAR end[] = L".";
const WCHAR com[] = L", ";
const int and_len = 4;
const int from_len = 5;
const int for_len = 4;
const int end_len = 1;
const int com_len = 2;

// Territories
const WCHAR ters[202][33] = {
	L"Alberta, Saskatchewan, Manitoba ", L"Ontario ", L"Quebec ", L"Newfoundland & Labrador ",
L"New Brunswick & Nova Scotia ", L"Greenland ", L"Central United States ", L"Eastern United States ",
L"Southeast Mexico ", L"West Indies ", L"Central America ", L"Venezuela ", L"Colombia ",
L"British Guiana ", L"Suriname ", L"French Guiana ", L"Ecuador ", L"Peru ", L"Bolivia ",
L"Brazil ", L"Paraguay ", L"Uruguay ", L"Argentina ", L"Chile ", L"Iceland ", L"Scotland ",
L"Eire ", L"United Kingdom ", L"Denmark ", L"Holland & Belgium ", L"Western Germany ",
L"France ", L"Switzerland ", L"Normandy & Bordeaux ", L"Southern France ", L"Spain ",
L"Portugal ", L"Gibraltar ", L"Sardinia ", L"Norway ", L"Sweden ", L"Finland ", L"Northern Italy ",
L"Southern Italy ", L"Sicily ", L"Germany ", L"Greater Southern Germany ", L"Poland ",
L"Slovakia & Hungary ", L"Yugoslavia ", L"Albania ", L"Greece ", L"Crete ", L"Romania ",
L"Bulgaria ", L"Baltic States ", L"Eastern Poland ", L"Karelia ", L"Vyborg ", L"Novgorod ",
L"Belarus ", L"Western Ukraine ", L"Bessarabia ", L"Archangel ", L"Smolensk ", L"Bryansk ",
L"Ukraine ", L"Rostov ", L"Caucasus ", L"Nenetsia ", L"Vologda ", L"Russia ", L"Tambov ",
L"Volgograd ", L"Urals ", L"Novosibirsk ", L"Samara ", L"Kazakhstan ", L"Turkmenistan ",
L"Morocco ", L"Algeria ", L"Tunisia ", L"Rio de Oro ", L"Portuguese Guinea ", L"French West Africa ",
L"French Central Africa ", L"Sierra Leone ", L"Liberia ", L"Gold Coast ", L"Nigeria ", L"Libya ",
L"Malta ", L"Tobruk ", L"Alexandria ", L"Egypt ", L"French Equatorial Africa ",
L"Anglo-Egyptian Sudan ", L"Ethiopia ", L"British Somaliland ", L"Italian Somaliland ",
L"Belgian Congo ", L"Kenya ", L"Tanganyika Territory ", L"Angola ", L"Rhodesia ", L"Mozambique ",
L"South West Africa ", L"Union of South Africa ", L"Madagascar ", L"Turkey ", L"Cyprus ",
L"Syria ", L"Trans-Jordan ", L"Iraq ", L"Saudi Arabia ", L"Northwest Persia ", L"Persia ",
L"Eastern Persia ", L"Afghanistan ", L"West India ",

L"Evenkiyskiy ", L"Yenisey ", L"Yakut S.S.R. ", L"Buryatia ", L"Sakha ", L"Amur ", L"Siberia ",
L"Soviet Far East ", L"Timguska ", L"Olgiy ", L"Dzavhan ", L"Tsagaan-Olom ", L"Central Mongolia ",
L"Ulaanbaatar ", L"Buyant-Uhaa ", L"Kansu ", L"Suiyuan ", L"Chahar ", L"Jehol ", L"Manchuria ",
L"Korea ", L"Tsinghai ", L"Shensi ", L"Hopei ", L"Anhwe ", L"Shantung ", L"Kiangsu ",L"Sikang ",
L"Szechwan ", L"Kweichow ", L"Hunan ", L"Kiangsi ", L"Yunnan ", L"Kwangsi ", L"Kwangtung ", L"India ",
L"Ceylon ", L"Burma ", L"Shan State ", L"Siam ", L"French Indo China ", L"Malaya ",
L"Western Australia ", L"Northern Territory ", L"South Australia ", L"Queensland ",
L"New South Wales ", L"Victoria ", L"New Zealand ", L"Japan ", L"Okinawa ", L"Iwo Jima ",
L"Midway ", L"Formosa ", L"Marianas ", L"Wake Island ", L"Hawaiian Islands ", L"Guam ",
L"Marshall Islands ", L"Johnston Island ", L"Line Islands ", L"Gilbert Islands ",
L"Fiji ", L"Samoa ", L"New Hebrides ", L"Solomon Islands ", L"New Britain ", L"New Guinea ",
L"Dutch New Guinea ", L"Caroline Islands ", L"Palau Island ", L"Philippines ", L"Celebes ",
L"Borneo ", L"Java ", L"Sumatra ", L"Hainan ", L"Alaska ", L"Aleutian Islands ", L"Western Canada ",
L"Western United States ", L"Mexico "
};
const int ters_len[202] = { 32, 8, 7, 24, 28, 11, 22, 22, 17, 12, 16, 10, 9, 15, 9, 14, 8, 5, 8, 7,
9, 8, 10, 6, 8, 9, 5, 15, 8, 18, 16, 7, 12, 20, 16, 6, 9, 10, 9, 7, 7, 8, 15, 15, 7, 8, 25, 7, 19,
11, 8, 7, 6, 8, 9, 14, 15, 8, 7, 9, 8, 16, 11, 10, 9, 8, 8, 7, 9, 9, 8, 7, 7, 10, 6, 12, 7, 11, 13,
8, 8, 8, 11, 18, 19, 22, 13, 8, 11, 8, 6, 6, 7, 11, 6, 25, 21, 9, 19, 19, 14, 6, 21, 7, 9, 11, 18,
22, 11, 7, 7, 6, 13, 5, 13, 17, 7, 15, 12, 11, 12, 8, 13, 9, 6, 5, 8, 16, 9, 6, 8, 13, 17, 12, 12,
6, 8, 7, 6, 10, 6, 9, 7, 6, 6, 9, 8, 7, 9, 9, 6, 8, 7, 8, 10, 6, 7, 6, 11, 5, 18, 7, 18, 19, 16,
11, 16, 9, 12, 6, 8, 9, 7, 8, 9, 12, 17, 5, 17, 16, 13, 16, 5, 6, 13, 16, 12, 11, 17, 17, 13, 12,
8, 7, 5, 8, 7, 7, 17, 15, 22, 7
};

const WCHAR ters_com[202][34] = {
	L"Alberta, Saskatchewan, Manitoba, ", L"Ontario, ", L"Quebec, ", L"Newfoundland & Labrador, ",
L"New Brunswick & Nova Scotia, ", L"Greenland, ", L"Central United States, ", L"Eastern United States, ",
L"Southeast Mexico, ", L"West Indies, ", L"Central America, ", L"Venezuela, ", L"Colombia, ",
L"British Guiana, ", L"Suriname, ", L"French Guiana, ", L"Ecuador, ", L"Peru, ", L"Bolivia, ",
L"Brazil, ", L"Paraguay, ", L"Uruguay, ", L"Argentina, ", L"Chile, ", L"Iceland, ", L"Scotland, ",
L"Eire, ", L"United Kingdom, ", L"Denmark, ", L"Holland & Belgium, ", L"Western Germany, ",
L"France, ", L"Switzerland, ", L"Normandy & Bordeaux, ", L"Southern France, ", L"Spain, ",
L"Portugal, ", L"Gibraltar, ", L"Sardinia, ", L"Norway, ", L"Sweden, ", L"Finland, ", L"Northern Italy, ",
L"Southern Italy, ", L"Sicily, ", L"Germany, ", L"Greater Southern Germany, ", L"Poland, ",
L"Slovakia & Hungary, ", L"Yugoslavia, ", L"Albania, ", L"Greece, ", L"Crete, ", L"Romania, ",
L"Bulgaria, ", L"Baltic States, ", L"Eastern Poland, ", L"Karelia, ", L"Vyborg, ", L"Novgorod, ",
L"Belarus, ", L"Western Ukraine, ", L"Bessarabia, ", L"Archangel, ", L"Smolensk, ", L"Bryansk, ",
L"Ukraine, ", L"Rostov, ", L"Caucasus, ", L"Nenetsia, ", L"Vologda, ", L"Russia, ", L"Tambov, ",
L"Volgograd, ", L"Urals, ", L"Novosibirsk, ", L"Samara, ", L"Kazakhstan, ", L"Turkmenistan, ",
L"Morocco, ", L"Algeria, ", L"Tunisia, ", L"Rio de Oro, ", L"Portuguese Guinea, ", L"French West Africa, ",
L"French Central Africa, ", L"Sierra Leone, ", L"Liberia, ", L"Gold Coast, ", L"Nigeria, ", L"Libya, ",
L"Malta, ", L"Tobruk, ", L"Alexandria, ", L"Egypt, ", L"French Equatorial Africa, ",
L"Anglo-Egyptian Sudan, ", L"Ethiopia, ", L"British Somaliland, ", L"Italian Somaliland, ",
L"Belgian Congo, ", L"Kenya, ", L"Tanganyika Territory, ", L"Angola, ", L"Rhodesia, ", L"Mozambique, ",
L"South West Africa, ", L"Union of South Africa, ", L"Madagascar, ", L"Turkey, ", L"Cyprus, ",
L"Syria, ", L"Trans-Jordan, ", L"Iraq, ", L"Saudi Arabia, ", L"Northwest Persia, ", L"Persia, ",
L"Eastern Persia, ", L"Afghanistan, ", L"West India, ",

L"Evenkiyskiy, ", L"Yenisey, ", L"Yakut S.S.R., ", L"Buryatia, ", L"Sakha, ", L"Amur, ", L"Siberia, ",
L"Soviet Far East, ", L"Timguska, ", L"Olgiy, ", L"Dzavhan, ", L"Tsagaan-Olom, ", L"Central Mongolia, ",
L"Ulaanbaatar, ", L"Buyant-Uhaa, ", L"Kansu, ", L"Suiyuan, ", L"Chahar, ", L"Jehol, ", L"Manchuria, ",
L"Korea, ", L"Tsinghai, ", L"Shensi, ", L"Hopei, ", L"Anhwe, ", L"Shantung, ", L"Kiangsu, ",L"Sikang, ",
L"Szechwan, ", L"Kweichow, ", L"Hunan, ", L"Kiangsi, ", L"Yunnan, ", L"Kwangsi, ", L"Kwangtung, ", L"India, ",
L"Ceylon, ", L"Burma, ", L"Shan State, ", L"Siam, ", L"French Indo China, ", L"Malaya, ",
L"Western Australia, ", L"Northern Territory, ", L"South Australia, ", L"Queensland, ",
L"New South Wales, ", L"Victoria, ", L"New Zealand, ", L"Japan, ", L"Okinawa, ", L"Iwo Jima, ",
L"Midway, ", L"Formosa, ", L"Marianas, ", L"Wake Island, ", L"Hawaiian Islands, ", L"Guam, ",
L"Marshall Islands, ", L"Johnston Island, ", L"Line Islands, ", L"Gilbert Islands, ",
L"Fiji, ", L"Samoa, ", L"New Hebrides, ", L"Solomon Islands, ", L"New Britain, ", L"New Guinea, ",
L"Dutch New Guinea, ", L"Caroline Islands, ", L"Palau Island, ", L"Philippines, ", L"Celebes, ",
L"Borneo, ", L"Java, ", L"Sumatra, ", L"Hainan, ", L"Alaska, ", L"Aleutian Islands, ", L"Western Canada, ",
L"Western United States, ", L"Mexico, "
};
const int ters_com_len[202] = { 33, 9, 8, 25, 29, 12, 23, 23, 18, 13, 17, 11, 10, 16, 10, 15, 9, 6, 9,
8, 10, 9, 11, 7, 9, 10, 6, 16, 9, 19, 17, 8, 13, 21, 17, 7, 10, 11, 10, 8, 8, 9, 16, 16, 8, 9, 26,
8, 20, 12, 9, 8, 7, 9, 10, 15, 16, 9, 8, 10, 9, 17, 12, 11, 10, 9, 9, 8, 10, 10, 9, 8, 8, 11, 7,
13, 8, 12, 14, 9, 9, 9, 12, 19, 20, 23, 14, 9, 12, 9, 7, 7, 8, 12, 7, 26, 22, 10, 20, 20, 15, 7, 22,
8, 10, 12, 19, 23, 12, 8, 8, 7, 14, 6, 14, 18, 8, 16, 13, 12, 13, 9, 14, 10, 7, 6, 9, 17, 10, 7, 9,
14, 18, 13, 13, 7, 9, 8, 7, 11, 7, 10, 8, 7, 7, 10, 9, 8, 10, 10, 7, 9, 8, 9, 11, 7, 8, 7, 12, 6,
19, 8, 19, 20, 17, 12, 17, 10, 13, 7, 9, 10, 8, 9, 10, 13, 18, 6, 18, 17, 14, 17, 6, 7, 14, 17, 13,
12, 18, 18, 14, 13, 9, 8, 6, 9, 8, 8, 18, 16, 23, 8
};

const WCHAR techs[13][31] = { L"Failure",
L"Advanced Artillery ", L"Rockets ",
L"Paratroopers ", L"Increased Factory Production ",
L"War Bonds ", L"Improved Mechanized Infantry ",
L"Super Submarines ", L"Jet Fighters ",
L"Improved Shipyards ", L"Radar ",
L"Long-Range Aircraft ", L"Heavy Bombers "
};
const int techs_len[13] = {7, 19, 8, 13, 29, 10, 29, 17, 13, 19, 6, 20, 14};

const WCHAR techs_com[13][32] = { L"Failure",
L"Advanced Artillery, ", L"Rockets, ",
L"Paratroopers, ", L"Increased Factory Production, ",
L"War Bonds, ", L"Improved Mechanized Infantry, ",
L"Super Submarines, ", L"Jet Fighters, ",
L"Improved Shipyards, ", L"Radar, ",
L"Long-Range Aircraft, ", L"Heavy Bombers, "
};
const int techs_com_len[13] = { 7, 20, 9, 14, 30, 11, 30, 18, 14, 20, 7, 21, 15 };

#endif
