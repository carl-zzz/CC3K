#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"
#include "player.h"
class DragonHoard;

  class Dragon: public Enemy{
 	
	public:

	DragonHoard *dh;

	Dragon();

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
 
	~Dragon();
  };

#endif
