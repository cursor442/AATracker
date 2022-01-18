#include "../header/TerritoryClass.h"

TerritoryClass::TerritoryClass()
{
	gameType = NULL_GAME;
}

TerritoryClass::~TerritoryClass()
{

}

void TerritoryClass::setGameType(int type)
{
	gameType = type;
}