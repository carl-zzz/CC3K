#ifndef TROLL_H
#define TROLL_H

#include "player.h"
  class Troll: public Player{
	
	static const int TROLL_SELF_HEAL = 5;

	public:

	// initialize a new player whose race is shade, and set the given board
	Troll();

	int attack(Human *, int);

	int attack(Dwarf *, int);

	int attack(Halfling *, int);

	int attack(Elf *, int);

	int attack(Orc *, int);

	int attack(Merchant *, int);

	int attack(Dragon *, int);

	int attack(Rat *, int);	

	void preTurn();

	void attackedBy(Enemy *);

	// class: Shade's destructor
	~Troll();
  };

#endif
