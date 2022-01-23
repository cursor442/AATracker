#ifndef INDUSTRIAL_COMPLEX_CLASS
#define INDUSTRIAL_COMPLEX_CLASS

#define NULL_IC          -1
#define MINOR_IC          0
#define MAJOR_IC          1

#define MINOR_IC_CAPCITY  3
#define MAJOR_IC_CAPCITY 10

class IndustrialComplex
{
public:
	IndustrialComplex(int);
	~IndustrialComplex();

	void setICType(int);
	void setICDamage(int);

	bool damageIC(int);
	bool repairIC(int);
	bool upgradeIC();
	bool downgradeIC();

	int getICType();
	int getICDamage();
	int getICCapacity();

private:
	int IC_type;
	int IC_damage;

	int IC_max_capacity;
};

#endif
