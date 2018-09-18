#include "drow.h"
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

Drow::Drow()
{
	ORIGINALATK = 25;
	ORIGINALDEF = 15;
	HP = 150;
	Atk = 25;
	Def = 15;
	Gold = 0;
	setDesc("Drow");
	DodgeChance = 50;
	setMaxHP(150);
}

int Drow::attack(Human *human, int dmg)
{
	human->addHP(-dmg);
	return dmg;
}


int Drow::attack(Dwarf *dwarf, int dmg)
{
	dwarf->addHP(-dmg);
	return dmg;
}


int Drow::attack(Halfling *halfling, int dmg)
{
	halfling->addHP(-dmg);
	return dmg;
}


int Drow::attack(Elf *elf, int dmg)
{
	elf->addHP(-dmg);
	return dmg;
}


int Drow::attack(Orc *orc, int dmg)
{
	orc->addHP(-dmg);
	return dmg;
}


int Drow::attack(Merchant *merchant, int dmg)
{
	merchant->addHP(-dmg);
	return dmg;
}


int Drow::attack(Rat *rat, int dmg)
{
	rat->addHP(-dmg);
	return dmg;
}


int Drow::attack(Dragon *dragon, int dmg)
{
	dragon->addHP(-dmg);
	return dmg;
}


void Drow::attackedBy(Enemy *e)
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

Drow::~Drow(){}
