#ifndef MONGOLIA_CLASS
#define MONGOLIA_CLASS

#include "TerritoryClass.h"

class Mongolia : public Territory
{
public:

	Mongolia(WCHAR*, int, int, int, int, int, bool, bool = false);
	~Mongolia();

	void setOwner(int);
	int  getOwner();

private:
	int mongoliaLean;

};

#endif