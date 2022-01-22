#include "../header/AirBaseClass.h"

AirBase::AirBase()
{
	airBase_damage = 0;
}

AirBase::~AirBase()
{

}

void AirBase::setAirBaseDamage(int dmg)
{
	if (dmg <= AIR_BASE_MAX_DAMAGE)
		airBase_damage = dmg;
}

bool AirBase::damageAirBase(int amt)
{
	if (airBase_damage + amt <= AIR_BASE_MAX_DAMAGE)
	{
		airBase_damage += amt;
		return true;
	}
	else
	{
		airBase_damage = AIR_BASE_MAX_DAMAGE;
		return false;
	}
}

bool AirBase::repairAirBase(int amt)
{
	if (airBase_damage - amt >= 0)
	{
		airBase_damage -= amt;
		return true;
	}
	else
	{
		airBase_damage = 0;
		return false;
	}
}

int AirBase::getAirBaseDamage()
{
	return airBase_damage;
}
