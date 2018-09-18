#include "vampire.h"
#include <fstream>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "rat.h"
#include "enemy.h"
using namespace std;

Vampire::Vampire()
{
	ORIGINALATK = 25;
	ORIGINALDEF = 25;
	HP = 50;
	Atk = 25;
	Def = 25;
	Gold = 0;
	setDesc("Vampire");
	DodgeChance = 50;
	setMaxHP(-1);
}


int Vampire::attack(Human *human, int dmg)
{
	human->addHP(-dmg);
	addHP(VAMPIRE_LIFE_STEAL);
	return dmg;
}


int Vampire::attack(Dwarf *dwarf, int dmg)
{
	dwarf->addHP(-dmg);
	addHP(-VAMPIRE_LIFE_STEAL);
	return dmg;
}


int Vampire::attack(Halfling *halfling, int dmg)
{
	halfling->addHP(-dmg);
	addHP(VAMPIRE_LIFE_STEAL);
	return dmg;
}


int Vampire::attack(Elf *elf, int dmg)
{
	elf->addHP(-dmg);
	addHP(VAMPIRE_LIFE_STEAL);
	return dmg;
}


int Vampire::attack(Orc *orc, int dmg)
{
	orc->addHP(-dmg);
	addHP(VAMPIRE_LIFE_STEAL);
	return dmg;
}


int Vampire::attack(Merchant *merchant, int dmg)
{
	merchant->addHP(-dmg);
	addHP(VAMPIRE_LIFE_STEAL);
	return dmg;
}


int Vampire::attack(Rat *rat, int dmg)
{
	rat->addHP(-dmg);
	addHP(VAMPIRE_LIFE_STEAL);
	return dmg;
}


int Vampire::attack(Dragon *dragon, int dmg)
{
	dragon->addHP(-dmg);
	addHP(VAMPIRE_LIFE_STEAL);
	return dmg;
}


void Vampire::attackedBy(Enemy *e)
{
	int i = rand() % 100;
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	if (i >= this->DodgeChance) {
		out << e->getDesc() << " dealt " << e->attack(this, dmg(e->Atk, Def)) << " damage to " << getName() << " (" << HP << " HP). " << endl;
		if (isDead()){
			out << "    " << getName() << " has been slain. " << endl;
		}
	}else{
		out << e->getDesc() << " missed its attack. " << endl;
	}
	out.close();
}


Vampire::~Vampire(){}
