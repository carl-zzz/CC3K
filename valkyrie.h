#ifndef VALKYRIE_H
#define VALKYRIE_H

#include "player.h"
  class Valkyrie: public Player{
	static const int MPGAIN = 3;	

	public:
	Valkyrie();

	int attack(Human *, int);

	int attack(Dwarf *, int);

	int attack(Halfling *, int);

	int attack(Elf *, int);

	int attack(Orc *, int);

	int attack(Merchant *, int);

	int attack(Dragon *, int);

	int attack(Rat *, int);	

	void attackedBy(Enemy *);

	~Valkyrie();
  };

#endif
