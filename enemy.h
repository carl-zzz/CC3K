#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

	class Player;
	class Shade;
	class Drow;
	class Vampire;
	class Troll;
	class Goblin;
	class Valkyrie;
	class Assassin;
	class Berserker;
	class God;

  class Enemy: public Character{
 	
	bool hostile;

	public:

	Enemy();
	virtual int attack(Shade *, int) = 0;
	virtual int attack(Drow *, int) = 0;
	virtual int attack(Vampire *, int) = 0;
	virtual int attack(Troll *, int) = 0;
	virtual int attack(Goblin *, int) = 0;
	virtual int attack(Valkyrie *, int) = 0;
	virtual int attack(Assassin *, int) = 0;
	virtual int attack(Berserker *, int) = 0;
	virtual int attack(God *, int) = 0;

	virtual void attackedBy(Player *) = 0;
	int dropGold();
 	bool isHostile();
	void setHostile(bool);
	virtual ~Enemy();
  };

#endif
