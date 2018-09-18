#ifndef ELF_H
#define ELF_H

#include "enemy.h"

  class Elf: public Enemy{
 	
	public:

	Elf();

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
 
	~Elf();
  };

#endif
