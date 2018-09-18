#ifndef BERSERKER_H
#define BERSERKER_H

#include "player.h"
  class Berserker: public Player{
	
	public:

	Berserker();

	void addHP(int n);

	int attack(Human *, int);

	int attack(Dwarf *, int);

	int attack(Halfling *, int);

	int attack(Elf *, int);

	int attack(Orc *, int);

	int attack(Merchant *, int);

	int attack(Dragon *, int);

	int attack(Rat *, int);	

	void attackedBy(Enemy *);

	// class: Berserker's destructor
	~Berserker();
  };

#endif
