#ifndef RESEARCH_CLASS
#define RESEARCH_CLASS

#include "../../game/header/framework.h"

class Research 
{
public:
	Research();

	void setResearch(uint16_t);
	void setResearch(Research&);
	void setFailures(uint16_t);

	bool     getResearch(uint16_t);
	uint16_t getFailures();
	uint16_t getCount();

private:
	uint16_t failures, count;
	bool techs[12];

};

#endif
