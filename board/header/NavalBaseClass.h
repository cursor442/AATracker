#ifndef NAVAL_BASE_CLASS
#define NAVAL_BASE_CLASS

#define NAVAL_BASE_MAX_DAMAGE 6

class NavalBase
{
public:
	NavalBase();
	~NavalBase();

	void setNavalBaseDamage(int);

	bool damageNavalBase(int);
	bool repairNavalBase(int);

	int getNavalBaseDamage();

private:
	int navalBase_damage;

};

#endif