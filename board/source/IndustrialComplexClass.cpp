#include "../header/IndustrialComplexClass.h"

IndustrialComplex::IndustrialComplex(int type)
{
	IC_type = type;

	IC_damage = 0;

	IC_max_capacity = MINOR_IC_CAPCITY;
	if (IC_type == MINOR_IC)
		IC_max_capacity = MINOR_IC_CAPCITY;
	else if (IC_type == MAJOR_IC)
		IC_max_capacity = MAJOR_IC_CAPCITY;
}

IndustrialComplex::~IndustrialComplex()
{

}

void IndustrialComplex::setICType(int type)
{
	IC_type = type;
}

void IndustrialComplex::setICDamage(int dmg)
{
	if (IC_damage <= (IC_max_capacity * 2))
		IC_damage = dmg;
}

bool IndustrialComplex::damageIC(int amt)
{
	if (IC_damage + amt <= (IC_max_capacity * 2))
	{
		IC_damage += amt;
		return true;
	}
	else
	{
		IC_damage = (IC_max_capacity * 2);
		return false;
	}
}

bool IndustrialComplex::repairIC(int amt)
{
	if (IC_damage - amt <= 0)
	{
		IC_damage -= amt;
		return true;
	}
	else
	{
		IC_damage = 0;
		return false;
	}
}

bool IndustrialComplex::upgradeIC()
{
	if (IC_type == MINOR_IC && IC_damage == 0)
	{
		IC_type = MAJOR_IC;
		IC_max_capacity = MAJOR_IC_CAPCITY;
		return true;
	}
	else
		return false;
}

int IndustrialComplex::getICType()
{
	return IC_type;
}

int IndustrialComplex::getICDamage()
{
	return IC_damage;
}

int IndustrialComplex::getICCapacity()
{
	return (IC_damage <= IC_max_capacity) ? (IC_max_capacity - IC_damage) : 0;
}
