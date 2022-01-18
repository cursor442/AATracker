#include "Resource.h"

#ifndef WAR_MATRIX
#define WAR_MATRIX

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
