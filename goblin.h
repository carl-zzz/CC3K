#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"
  class Goblin: public Player{

	static const int GOBLIN_GOLD_STEAL = 5;
	
	public:

	// initialize a new player whose race is shade, and set the given board
	Goblin();

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
	~Goblin();
  };

#endif
