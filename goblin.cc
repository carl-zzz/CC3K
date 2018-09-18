#include "goblin.h"
#include <fstream>
#include <iostream>
#include <math.h>
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

Goblin::Goblin()
{
	ORIGINALATK = 15;
	ORIGINALDEF = 20;
	HP = 110;
	Atk = 15;
	Def = 20;
	Gold = 0;
	setDesc("Goblin");
	DodgeChance = 50;
	setMaxHP(110);
}

int Goblin::attack(Human *human, int dmg)
{
	human->addHP(-dmg);
	if (human->isDead()) addGold(GOBLIN_GOLD_STEAL);
	return dmg;
}


int Goblin::attack(Dwarf *dwarf, int dmg)
{
	dwarf->addHP(-dmg);
	if (dwarf->isDead()) addGold(GOBLIN_GOLD_STEAL);
	return dmg;
}


int Goblin::attack(Halfling *halfling, int dmg)
{
	halfling->addHP(-dmg);
	if (halfling->isDead()) addGold(GOBLIN_GOLD_STEAL);
	return dmg;
}


int Goblin::attack(Elf *elf, int dmg)
{
	elf->addHP(-dmg);
	if (elf->isDead()) addGold(GOBLIN_GOLD_STEAL);
	return dmg;
}


int Goblin::attack(Orc *orc, int dmg)
{
	orc->addHP(-dmg);
	if (orc->isDead()) addGold(GOBLIN_GOLD_STEAL);
	return dmg;
}


int Goblin::attack(Merchant *merchant, int dmg)
{
	merchant->addHP(-dmg);
	if (merchant->isDead()) addGold(GOBLIN_GOLD_STEAL);
	return dmg;
}


int Goblin::attack(Rat *rat, int dmg)
{
	rat->addHP(-dmg);
	if (rat->isDead()) addGold(GOBLIN_GOLD_STEAL);
	return dmg;
}


int Goblin::attack(Dragon *dragon, int dmg)
{
	dragon->addHP(-dmg);
	if (dragon->isDead()) addGold(GOBLIN_GOLD_STEAL);
	return dmg;
}


void Goblin::attackedBy(Enemy *e)
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


Goblin::~Goblin(){}
