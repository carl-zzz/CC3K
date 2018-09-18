#include "troll.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
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

Troll::Troll()
{
	ORIGINALATK = 25;
	ORIGINALDEF = 15;
	HP = 120;
	Atk = 25;
	Def = 15;
	Gold = 0;
	setDesc("Troll");
	DodgeChance = 50;
	setMaxHP(120);
}

int Troll::attack(Human *human, int dmg)
{
	human->addHP(-dmg);
	return dmg;
}


int Troll::attack(Dwarf *dwarf, int dmg)
{
	dwarf->addHP(-dmg);
	return dmg;
}


int Troll::attack(Halfling *halfling, int dmg)
{
	halfling->addHP(-dmg);
	return dmg;
}


int Troll::attack(Elf *elf, int dmg)
{
	elf->addHP(-dmg);
	return dmg;
}


int Troll::attack(Orc *orc, int dmg)
{
	orc->addHP(-dmg);
	return dmg;
}


int Troll::attack(Merchant *merchant, int dmg)
{
	merchant->addHP(-dmg);
	return dmg;
}


int Troll::attack(Rat *rat, int dmg)
{
	rat->addHP(-dmg);
	return dmg;
}


int Troll::attack(Dragon *dragon, int dmg)
{
	dragon->addHP(-dmg);
	return dmg;
}


void Troll::preTurn()
{
	addHP(TROLL_SELF_HEAL);
}


void Troll::attackedBy(Enemy *e)
{
	int i = rand() % 100;
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	if (i >= this->DodgeChance) {
		cout << e->getDesc() << " dealt " << e->attack(this, dmg(e->Atk, Def)) << " damage to " << getName() << " (" << HP << " HP). " << endl;
		if (isDead()){
			out << "    " << getName() << " has been slain. " << endl;
		}
	}else{
		out << e->getDesc() << " missed its attack. " << endl;
	}
	out.close();
}


Troll::~Troll(){}
