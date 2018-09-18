#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "player.h"
  class Assassin: public Player{
	
	public:
	Assassin();

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

	// class: Assassin's destructor
	~Assassin();
  };

#endif
