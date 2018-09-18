#ifndef MERCHANT_H
#define MERCHANT_H
#include "player.h"
#include "enemy.h"

  class Merchant: public Enemy{
 	
	public:

	Merchant();

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
 
	~Merchant();
  };

#endif
