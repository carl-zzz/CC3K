#ifndef SKILL_H
#define SKILL_H
#include "item.h"
#include "player.h"
#include "enemy.h"

class Skill: public Item{
	const int id;	

	public:
	static const int HEAL = 0;				//'Nuff said
	static const int DIVSTRIKE = 1;		//valkyrie's main attack
	static int AMT[2];
	static int COST[2];

	virtual void useOn(Player *p);
	virtual bool useOn(Player *p, Enemy *e);

	bool isTargetted();

	Skill(const int id);
	~Skill();
	//static const int 
};

#endif
