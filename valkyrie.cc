#include "valkyrie.h"
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
#include "skill.h"
using namespace std;

Valkyrie::Valkyrie()
{
	ORIGINALATK = Atk;
	ORIGINALDEF = Def;
	s1 = new Skill(Skill::DIVSTRIKE);
	HP = 50;
	MP = 50;
	Atk = 10;
	Def = 200;
	Gold = 0;
	setDesc("Valkyrie");
	DodgeChance = 30;
	setMaxHP(150);
	maxMP = MP;
}

int Valkyrie::attack(Human *human, int dmg)
{
	addMP(MPGAIN);
	human->addHP(-dmg);
	return dmg;
}


int Valkyrie::attack(Dwarf *dwarf, int dmg)
{
	addMP(MPGAIN);
	dwarf->addHP(-dmg);
	return dmg;
}


int Valkyrie::attack(Halfling *halfling, int dmg)
{
	addMP(MPGAIN);
	halfling->addHP(-dmg);
	return dmg;
}


int Valkyrie::attack(Elf *elf, int dmg)
{
	addMP(MPGAIN);
	elf->addHP(-dmg);
	return dmg;
}


int Valkyrie::attack(Orc *orc, int dmg)
{
	addMP(MPGAIN);
	orc->addHP(-dmg);
	return dmg;
}


int Valkyrie::attack(Merchant *merchant, int dmg)
{
	addMP(MPGAIN);
	merchant->addHP(-dmg);
	return dmg;
}


int Valkyrie::attack(Rat *rat, int dmg)
{
	addMP(MPGAIN);
	rat->addHP(-dmg);
	return dmg;
}


int Valkyrie::attack(Dragon *dragon, int dmg)
{
	addMP(MPGAIN);
	dragon->addHP(-dmg);
	return dmg;
}


void Valkyrie::attackedBy(Enemy *e)
{
	addMP(1);
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
		cout << e->getDesc() << " missed its attack. " << endl;
	}
	out.close();
}

Valkyrie::~Valkyrie(){}
