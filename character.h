#ifndef CHARACTER_H
#define CHARACTER_H
#include "object.h"

  class Character: public Object{

	private:

	int maxHP;

	protected:
	

	public:
	
	int HP;				// the health points of a character
	int Atk;			// the attack of a character
	int Def;			// the defense of a character
	int Gold;			// the gold a character holds
	int DodgeChance;  		// the missing chance that a character has
	Character();
	void print();			// print the player's status
	virtual void preTurn();
	virtual void postTurn();
	virtual void addHP(const int);		// add the given amount of HP to the character
	virtual void addAtk(const int);		// add the given amount of attack to the character
	virtual void addDef(const int);		// add the given amount of defense to the character
	virtual bool isDead();			// virtual method to a character's death
	void setMaxHP(const int);	// set the max hp of a character
	int getMaxHP();			// return the maxHP of the character	
	int dmg(int atk, int def); //dmg done by attacker with atk to defender with def
	virtual ~Character();
  };

#endif
