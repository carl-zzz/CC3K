#include "berserker.h"
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

Berserker::Berserker()
{
	ORIGINALATK = 30;
	ORIGINALDEF = 15;
	HP = 80;
	Atk = 30;
	Def = 15;
	MP = 10;
	Gold = 0;
	setDesc("Berserker");
	DodgeChance = 50;
	setMaxHP(80);
	maxMP = 10;
}

void Berserker::addHP(int n){
	if(HP + n > getMaxHP()){
		ORIGINALATK -= (getMaxHP() - HP);
		Atk -= (getMaxHP() - HP);
		HP = getMaxHP();
	}else if(HP + n < 0){
		ORIGINALATK += HP;
		Atk += HP;
		HP = 0;
	}else{
		HP += n;
		ORIGINALATK -= n;
		Atk -= n;
	}
}

int Berserker::attack(Human *human, int dmg)
{
	human->addHP(-dmg);
	if(human->isDead()){
		addHP(5);
	}
	return dmg;
}


int Berserker::attack(Dwarf *dwarf, int dmg)
{
	dwarf->addHP(-dmg);
	if(dwarf->isDead()){
		addHP(5);
	}
	return dmg;
}


int Berserker::attack(Halfling *halfling, int dmg)
{
	halfling->addHP(-dmg);
	if(halfling->isDead()){
		addHP(5);
	}
	return dmg;
}


int Berserker::attack(Elf *elf, int dmg)
{
	elf->addHP(-dmg);
	if(elf->isDead()){
		addHP(5);
	}
	return dmg;
}


int Berserker::attack(Orc *orc, int dmg)
{
	orc->addHP(-dmg);
	if(orc->isDead()){
		addHP(5);
	}
	return dmg;
}


int Berserker::attack(Merchant *merchant, int dmg)
{
	merchant->addHP(-dmg);
	if(merchant->isDead()){
		addHP(5);
	}
	return dmg;
}


int Berserker::attack(Rat *rat, int dmg)
{
	rat->addHP(-dmg);
	if(rat->isDead()){
		addHP(5);
	}
	return dmg;
}


int Berserker::attack(Dragon *dragon, int dmg)
{
	dragon->addHP(-dmg);
	if(dragon->isDead()){
		addHP(5);
	}
	return dmg;
}


void Berserker::attackedBy(Enemy *e)
{
	int i = rand() % 100;
	ofstream out;
	out.open("action.txt", ios::app);
	out << "    ";
	if (i >= this->DodgeChance) {
		out << e->getDesc() << " dealt " << e->attack(this, dmg(e->Atk, Def)) << " damage to " << getDesc() << " (" << HP << " HP). " << endl;
		if (isDead()){
			out << "    " << getName() << " has been slain. " << endl;
		}
	}else{
		out << e->getDesc() << " missed its attack. " << endl;
	}
	out.close();
}

Berserker::~Berserker(){}
