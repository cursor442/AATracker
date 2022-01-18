#pragma once

#include "framework.h"

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