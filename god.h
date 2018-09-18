#ifndef GOD_H
#define GOD_H

#include "player.h"
  class God: public Player{
	
	public:
	God();
	
	void addHP(int n);
	void addDef(int n);
	void addAtk(int n);

	int attack(Human *, int);

	int attack(Dwarf *, int);

	int attack(Halfling *, int);

	int attack(Elf *, int);

	int attack(Orc *, int);

	int attack(Merchant *, int);

	int attack(Dragon *, int);

	int attack(Rat *, int);	

	void attackedBy(Enemy *);

	// class: God's destructor
	~God();
  };

#endif
