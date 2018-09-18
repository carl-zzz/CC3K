#include "character.h"
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

Character::Character(){}

//attacker's atk, defender's def
int Character::dmg(int atk, int def){
	double temp;
	temp = 100 * atk / (100 + def);
	return (int)ceil(temp);
}

bool Character::isDead(){
	return (HP <= 0);
}

void Character::print()
{
	cout << "HP: " << HP << endl;
	cout << "Atk: " << Atk << endl;
	cout << "Def: " << Def << endl;
	cout << "Action: " << endl; 
	
	fstream f;
	f.open("action.txt",ios::in);
	string s;
	while (getline(f,s)){
	cout << s << endl;
	}
	f.close();
}


void Character::preTurn(){}


void Character::postTurn(){}



// add the given amount of HP to the character
void Character::addHP(const int amt)
{
	HP += amt;
	if(HP < 0){HP = 0;}
	if(getMaxHP() == -1){return;}
	if(HP > getMaxHP()){HP = getMaxHP();}
}


// add the given amount of attack to the character
void Character::addAtk(const int amt)
{
	Atk += amt;
	if(Atk < 0){Atk = 0;}
}// addAtk()


// add the given amount of defense to the character
void Character::addDef(const int amt)
{
	Def += amt;
	if(Def < 0){Def = 0;}
}// addDef(const int amt)


// set the character's max HP to the given number
void Character::setMaxHP(const int maxhp)
{
        maxHP = maxhp;
}// setMaxHP(const int)


// max HP getter
int Character::getMaxHP()
{
        return maxHP;
}// getMaxHP()


// class:Character's destructor
Character::~Character() {}
