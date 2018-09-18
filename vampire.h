#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "player.h"

  class Vampire: public Player{
	
	static const int VAMPIRE_LIFE_STEAL = 5;

	public:

	// initialize a new player whose race is shade, and set the given board
	Vampire();

	int attack(Human *, int);

	int attack(Dwarf *, int);

	int attack(Halfling *, int);

	int attack(Elf *, int);

	int attack(Orc *, int);

	int attack(Merchant *, int);

	int attack(Dragon *, int);

	int attack(Rat *, int);	

	void attackedBy(Enemy *);

	// class: Shade's destructor
	~Vampire();
  };

#endif
