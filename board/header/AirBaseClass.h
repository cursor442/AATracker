#ifndef AIR_BASE_CLASS
#define AIR_BASE_CLASS

#define AIR_BASE_MAX_DAMAGE 6

class AirBase
{
public:
	AirBase();
	~AirBase();

	void setAirBaseDamage(int);

	bool damageAirBase(int);
	bool repairAirBase(int);

	int getAirBaseDamage();

private:
	int airBase_damage;

};

#endif