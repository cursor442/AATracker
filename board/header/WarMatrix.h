#ifndef WAR_MATRIX
#define WAR_MATRIX

#include "../../game/header/Resource.h"

#define WAR_MATRIX_SIZE 11

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
	bool warMatrix[WAR_MATRIX_SIZE][WAR_MATRIX_SIZE];

	int gameType;
};

#endif
