#ifndef ORC_H
#define ORC_H

#include "enemy.h"

  class Orc: public Enemy{
 	
	public:

	Orc();

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
 
	~Orc();
  };

#endif
