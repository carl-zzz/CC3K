#ifndef DWARF_H
#define DWARF_H
#include "player.h"
#include "enemy.h"

  class Dwarf: public Enemy{
 	
	public:

	Dwarf();

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
 
	~Dwarf();

  };

#endif
