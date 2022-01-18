#include "../header/ResearchClass.h"

Research::Research()
{
	failures = 0;
	count = 0;

	for (size_t i = 0; i < 12; i++)
		techs[i] = false;
}

void Research::setResearch(uint16_t idx)
{
	if (idx == 0)
		failures++;
	else
	{
		idx--;
		techs[idx] = true;
		count++;
	}
}

void Research::setResearch(Research &cpy)
{
	this->failures = cpy.failures;
	this->count = cpy.count;

	for (size_t i = 0; i < 12; i++)
		this->techs[i] = cpy.techs[i];
}

void Research::setFailures(uint16_t fails)
{
	failures = fails;
}

bool Research::getResearch(uint16_t idx)
{
	return techs[--idx];
}

uint16_t Research::getFailures()
{
	return failures;
}

uint16_t Research::getCount()
{
	return count;
}
