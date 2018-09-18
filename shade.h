#ifndef SHADE_H
#define SHADE_H

#include "player.h"
  class Shade: public Player{
	
	public:

	// initialize a new player whose race is shade, and set the given board
	Shade();

	int getScore();

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
	~Shade();
  };

#endif
