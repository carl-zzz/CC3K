#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"

	class Enemy;
	class Human;
	class Dwarf;
	class Halfling;
	class Elf;
	class Orc;
	class Merchant;
	class Dragon;
	class Rat;
	class Skill;

  class Player: public Character{
	
	std::string Name;
	
	protected:

	int ORIGINALATK;
	int ORIGINALDEF;
	int maxMP;
	int MP;
	public:

	Skill *s1;
	Skill *s2;

	Player();
	virtual int getScore();
	virtual void preTurn();
	virtual void postTurn();

	virtual int attack(Human *, int) = 0;		// the character attacks the given human
	virtual int attack(Dwarf *, int) = 0;		// the character attacks the given dwarf
	virtual int attack(Halfling *, int) = 0;	// the character attacks the given halfling
	virtual int attack(Elf *, int) = 0;		// the character attacks the given elf
	virtual int attack(Orc *, int) = 0;		// the character attacks the given orc
	virtual int attack(Merchant *, int) = 0;	// the character attacks the given merchant
	virtual int attack(Rat *, int) = 0;		// the character attacks the given rat
	virtual int attack(Dragon *, int) = 0;

	virtual void attackedBy(Enemy *) = 0;		// the character is attacked by an enemy

	virtual void learn(Skill *s);

	void addMP(int m);
	int getMP();

	void addGold(const int);
	int getGold();

	void setName(std::string);
	std::string getName();

	void reset();
	~Player();
  };

#endif
