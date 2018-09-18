#ifndef HALFLING_H
#define HALFLING_H

#include "enemy.h"

  class Halfling: public Enemy{
 	
	public:

	Halfling();

	int attack(Shade *, int);

	int attack(Drow *, int);

	int attack(Vampire *, int);

	int attack(Troll *, int);

	int attack(Goblin *, int);

	int attack(Valkyrie *, int);	
	int attack(Assassin *, int);
	int attack(Berserker *, int);
	int attack(God *, int);

	void attackedBy(Player *);
 
	~Halfling();
  };

#endif
