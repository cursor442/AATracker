
#ifndef TERRITORIES_H
#define TERRITORIES_H

struct territory {
	TCHAR    name[32];
	uint16_t alphabet;
	uint16_t owner;
	uint16_t value;
	uint16_t original;
	uint16_t side;
};

struct listTerritory {
	TCHAR    name[32];
	uint16_t id;
	uint16_t alph;
};

// Europe map territories
// North America
#define TER_ALBERTA      0
#define TER_ONTARIO      1
#define TER_QUEBEC       2
#define TER_NEWFOUNDLAND 3
#define TER_NEW_BRUNS    4
#define TER_CENTRAL_USA  5
#define TER_EASTERN_USA  6
#define TER_SE_MEXICO    7
#define TER_WEST_INDIES  8
#define TER_CENT_AMERICA 9

// South America
#define TER_VENEZUELA    10
#define TER_COLOMBIA     11
#define TER_BRIT_GUIANA  12
#define TER_SURINAME     13
#define TER_FRA_GUIANA   14
#define TER_ECUADOR      15
#define TER_PERU         16
#define TER_BOLIVIA      17
#define TER_BRAZIL       18
#define TER_PARAGUAY     19
#define TER_URUGUAY      20
#define TER_ARGENTINA    21
#define TER_CHILE        22

// Europe
#define TER_ICELAND      23
#define TER_SCOTLAND     24
#define TER_EIRE         25
#define TER_UTD_KINGDOM  26
#define TER_DENMARK      27
#define TER_HOLL_BELG    28
#define TER_WEST_GERMANY 29
#define TER_FRANCE       30
#define TER_SWITZERLAND  31
#define TER_NORMANDY     32
#define TER_SOUTH_FRANCE 33
#define TER_SPAIN        34
#define TER_PORTUGAL     35
#define TER_GIBRALTAR    36
#define TER_SARDINIA     37
#define TER_NORWAY       38
#define TER_SWEDEN       39
#define TER_FINLAND      40
#define TER_NORTH_ITALY  41
#define TER_SOUTH_ITALY  42
#define TER_SICILY       43
#define TER_GERMANY      44
#define TER_S_GERMANY    45
#define TER_POLAND       46
#define TER_SLOV_HUNGARY 47
#define TER_YUGOSLAVIA   48
#define TER_ALBANIA      49
#define TER_GREECE       50
#define TER_CRETE        51
#define TER_ROMANIA      52
#define TER_BULGARIA     53
#define TER_BALTIC_STATE 54
#define TER_EAST_POLAND  55
#define TER_KARELIA      56
#define TER_VYBORG       57
#define TER_NOVGOROD     58
#define TER_BELARUS      59
#define TER_WEST_UKRAINE 60
#define TER_BESSARABIA   61
#define TER_ARCHANGEL    62
#define TER_SMOLENSK     63
#define TER_BRYANSK      64
#define TER_UKRAINE      65
#define TER_ROSTOV       66
#define TER_CAUCASUS     67
#define TER_NENETSIA     68
#define TER_VOLOGDA      69
#define TER_RUSSIA       70
#define TER_TAMBOV       71
#define TER_VOLGOGRAD    72
#define TER_URALS        73
#define TER_NOVOSIBIRSK  74
#define TER_SAMARA       75
#define TER_KAZAKHSTAN   76
#define TER_TURKMENISTAN 77

// Africa
#define TER_MOROCCO      78
#define TER_ALGERIA      79
#define TER_TUNISIA      80
#define TER_RIO_DE_ORO   81
#define TER_PORT_GUINEA  82
#define TER_FRA_W_AFRICA 83
#define TER_FRA_C_AFRICA 84
#define TER_SIERRA_LEONE 85
#define TER_LIBERIA      86
#define TER_GOLD_COAST   87
#define TER_NIGERIA      88
#define TER_LIBYA        89
#define TER_MALTA        90
#define TER_TOBRUK       91
#define TER_ALEXANDRIA   92
#define TER_EGYPT        93
#define TER_FR_EQ_AFRICA 94
#define TER_AN_EGY_SUDAN 95
#define TER_ETHIOPIA     96
#define TER_BRIT_SOMALI  97
#define TER_ITAL_SOMALI  98
#define TER_BELG_CONGO   99
#define TER_KENYA        100
#define TER_TANGANYIKA   101
#define TER_ANGOLA       102
#define TER_RHODESIA     103
#define TER_MOZAMBIQUE   104
#define TER_SW_AFRICA    105
#define TER_SOUTH_AFRICA 106
#define TER_MADAGASCAR   107

// Middle East
#define TER_TURKEY       108
#define TER_CYPRUS       109
#define TER_SYRIA        110
#define TER_TRANS_JORDAN 111
#define TER_IRAQ         112
#define TER_SAUDI_ARABIA 113
#define TER_NW_PERSIA    114
#define TER_PERSIA       115
#define TER_EAST_PERSIA  116
#define TER_AFGHANISTAN  117
#define TER_WEST_INDIA   118

//// Pacific Map territories
// Asia
#define TER_EVENKIYSKIY  119
#define TER_YENISEY      120
#define TER_YAKUT        121
#define TER_BURYATIA     122
#define TER_SAKHA        123
#define TER_AMUR         124
#define TER_SIBERIA      125
#define TER_SOV_FAR_EAST 126
#define TER_TIMGUSKA     127
#define TER_OLGIY        128
#define TER_DZAVHAN      129
#define TER_TSAGAAN_OLOM 130
#define TER_CNT_MONGOLIA 131
#define TER_ULAANBAATAR  132
#define TER_BUYANT_UHAA  133
#define TER_KANSU        134
#define TER_SUIYUAN      135
#define TER_CHAHAR       136
#define TER_JEHOL        137
#define TER_MANCHURIA    138
#define TER_KOREA        139
#define TER_TSINGHAI     140
#define TER_SHENSI       141
#define TER_HOPEI        142
#define TER_ANHWE        143
#define TER_SHANTUNG     144
#define TER_KIANGSU      145
#define TER_SIKANG       146
#define TER_SZECHWAN     147
#define TER_KWEICHOW     148
#define TER_HUNAN        149
#define TER_KIANGSI      150
#define TER_YUNNAN       151
#define TER_KWANGSI      152
#define TER_KWANGTUNG    153
#define TER_INDIA        154
#define TER_CEYLON       155
#define TER_BURMA        156
#define TER_SHAN_STATE   157
#define TER_SIAM         158
#define TER_FR_IND_CHINA 159
#define TER_MALAYA       160

// Australia and New Zealand
#define TER_W_AUSTRALIA  161
#define TER_N_TERRITORY  162
#define TER_S_AUSTRALIA  163
#define TER_QUEENSLAND   164
#define TER_NEW_S_WALES  165
#define TER_VICTORIA     166
#define TER_NEW_ZEALAND  167

// Pacific
#define TER_JAPAN        168
#define TER_OKINAWA      169
#define TER_IWO_JIMA     170
#define TER_MIDWAY       171
#define TER_FORMOSA      172
#define TER_MARIANAS     173
#define TER_WAKE_ISLAND  174
#define TER_HAWAII       175
#define TER_GUAM         176
#define TER_MARSHALL_ISL 177
#define TER_JOHNSTON_ISL 178
#define TER_LINE_ISLANDS 179
#define TER_GILBERT_ISL  180
#define TER_FIJI         181
#define TER_SAMOA        182
#define TER_NEW_HEBRIDES 183
#define TER_SOLOMON_ISL  184
#define TER_NEW_BRITAIN  185
#define TER_NEW_GUINEA   186
#define TER_DUT_N_GUINEA 187
#define TER_CAROLINE_ISL 188
#define TER_PALAU_ISL    189
#define TER_PHILIPPINES  190
#define TER_CELEBES      191
#define TER_BORNEO       192
#define TER_JAVA         193
#define TER_SUMATRA      194
#define TER_HAINAN       195

// North America 
#define TER_ALASKA       196
#define TER_ALEUTIAN_ISL 197
#define TER_W_CANADA     198
#define TER_WEST_USA     199
#define TER_MEXICO       200

#endif
