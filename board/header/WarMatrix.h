#ifndef WAR_MATRIX
#define WAR_MATRIX

#include "../../game/header/Resource.h"

class WarMatrix
{
public:
	WarMatrix();
	~WarMatrix();

	void setGameType(int);
	void setWarMatrix(int, int, bool);
	void setAtWarWith(int, int);

	bool getAtWarWith(int, int);

private:
	bool warMatrix[10][10];

	int gameType;
};

#endif
