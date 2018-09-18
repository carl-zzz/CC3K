#ifndef DROW_H
#define DROW_H

#include "player.h"
  class Drow: public Player{
	
	public:

	// initialize a new player whose race is drow, and set the given board
	Drow();

	int attack(Human *, int);

	int attack(Dwarf *, int);

	int attack(Halfling *, int);

	int attack(Elf *, int);

	int attack(Orc *, int);

	int attack(Merchant *, int);

	int attack(Dragon *, int);

	int attack(Rat *, int);	

	void attackedBy(Enemy *);

	// class: Drow's destructor
	~Drow();
  };

#endif
