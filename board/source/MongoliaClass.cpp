#include "../header/MongoliaClass.h"

Mongolia::Mongolia(WCHAR* n, int a, int orig, int own, int v, int m, bool coast, bool chn)
	:Territory(n, a, orig, own, v, m, coast, chn)
{
	mongoliaLean = FULL_NEUTRAL;
}

Mongolia::~Mongolia()
{
	
}

void Mongolia::setOwner(int own)
{
	if (own <= TURN_FRA) // Owned by a nation
		owner = own;
	else // Neutral lean change
		mongoliaLean = own;
}

int Mongolia::getOwner()
{
	if (owner <= TURN_FRA) // Owned by a nation
		return owner;
	else // Still neutral, return the lean
		return mongoliaLean;		
}
