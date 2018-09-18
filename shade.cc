#include "shade.h"
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

Shade::Shade()
{
	ORIGINALATK = 25;
	ORIGINALDEF = 25;
	HP = 125;
	Atk = 25;
	Def = 25;
	Gold = 0;
	setDesc("Shade");
	DodgeChance = 50;
	setMaxHP(125);
}

int Shade::getScore(){
	return 1.5 * 2 * getGold();
}

int Shade::attack(Human *human, int dmg)
{
	human->addHP(-dmg);
	return dmg;
}


int Shade::attack(Dwarf *dwarf, int dmg)
{
	dwarf->addHP(-dmg);
	return dmg;
}


int Shade::attack(Halfling *halfling, int dmg)
{
	halfling->addHP(-dmg);
	return dmg;
}


int Shade::attack(Elf *elf, int dmg)
{
	elf->addHP(-dmg);
	return dmg;
}


int Shade::attack(Orc *orc, int dmg)
{
	orc->addHP(-dmg);
	return dmg;
}


int Shade::attack(Merchant *merchant, int dmg)
{
	merchant->addHP(-dmg);
	return dmg;
}


int Shade::attack(Rat *rat, int dmg)
{
	rat->addHP(-dmg);
	return dmg;
}


int Shade::attack(Dragon *dragon, int dmg)
{
	dragon->addHP(-dmg);
	return dmg;
}


void Shade::attackedBy(Enemy *e)
{
	int i = rand() % 100;
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	if (i >= this->DodgeChance) {
		out  << e->getDesc() << " dealt " << e->attack(this, dmg(e->Atk, Def)) << " damage to " << getName() << " (" << HP << " HP). " << endl;
		if (isDead()){
			out << "    " << getName() << " has been slain. " << endl;
		}
	}else{
		out << e->getDesc() << " missed its attack. " << endl;
	}
	out.close();
}

Shade::~Shade(){}
