#include "WarMatrix.h"

WarMatrix::WarMatrix()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			warMatrix[i][j] = false;
	warMatrix[TURN_GER][TURN_UKE] = true;
	warMatrix[TURN_GER][TURN_UKP] = true;
	warMatrix[TURN_GER][TURN_ANZ] = true;
	warMatrix[TURN_GER][TURN_FRA] = true;
	warMatrix[TURN_JPN][TURN_CHN] = true;
	warMatrix[TURN_ITA][TURN_UKE] = true;
	warMatrix[TURN_ITA][TURN_UKP] = true;
	warMatrix[TURN_ITA][TURN_ANZ] = true;
	warMatrix[TURN_ITA][TURN_FRA] = true;

	gameType = NULL_GAME;
}

WarMatrix::~WarMatrix()
{

}

void WarMatrix::setGameType(int type)
{
	gameType = type;
}

void WarMatrix::setWarMatrix(int axis, int ally, bool val)
{
	warMatrix[axis][ally] = val;
}

void WarMatrix::setAtWarWith(int axis, int ally)
{
	warMatrix[axis][ally] = true;
}

bool WarMatrix::getAtWarWith(int axis, int ally)
{
	return warMatrix[axis][ally];
}