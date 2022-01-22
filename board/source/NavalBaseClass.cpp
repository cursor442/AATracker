#include "../header/NavalBaseClass.h"

NavalBase::NavalBase()
{
	navalBase_damage = 0;
}

NavalBase::~NavalBase()
{

}

void NavalBase::setNavalBaseDamage(int dmg)
{
	if (dmg <= NAVAL_BASE_MAX_DAMAGE)
		navalBase_damage = dmg;
}

bool NavalBase::damageNavalBase(int amt)
{
	if (navalBase_damage + amt <= NAVAL_BASE_MAX_DAMAGE)
	{
		navalBase_damage += amt;
		return true;
	}
	else
	{
		navalBase_damage = NAVAL_BASE_MAX_DAMAGE;
		return false;
	}
}

bool NavalBase::repairNavalBase(int amt)
{
	if (navalBase_damage - amt >= 0)
	{
		navalBase_damage -= amt;
		return true;
	}
	else
	{
		navalBase_damage = 0;
		return false;
	}
}

int NavalBase::getNavalBaseDamage()
{
	return navalBase_damage;
}
