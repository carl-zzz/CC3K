#include "assassin.h"
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

Assassin::Assassin()
{
	ORIGINALATK = 20;
	ORIGINALDEF = 10;
	HP = 20;
	Atk = 20;
	Def = 10;
	Gold = 0;
	setDesc("Assassin");
	DodgeChance = 90;
	setMaxHP(20);
}

void Assassin::addHP(int n){
	if(HP + n <= 0){
		if(HP > 1){		
			HP = 1;
		}else{
			HP = 0;
		}
	}else if(HP + n > getMaxHP()){
		HP = getMaxHP();
	}else{
		HP += n;
	}
}


int Assassin::attack(Human *human, int dmg)
{
	human->addHP(-dmg);
	return dmg;
}


int Assassin::attack(Dwarf *dwarf, int dmg)
{
	dwarf->addHP(-dmg);
	return dmg;
}


int Assassin::attack(Halfling *halfling, int dmg)
{
	halfling->addHP(-dmg);
	return dmg;
}


int Assassin::attack(Elf *elf, int dmg)
{
	elf->addHP(-dmg);
	return dmg;
}


int Assassin::attack(Orc *orc, int dmg)
{
	orc->addHP(-dmg);
	return dmg;
}


int Assassin::attack(Merchant *merchant, int dmg)
{
	merchant->addHP(-dmg);
	return dmg;
}


int Assassin::attack(Rat *rat, int dmg)
{
	rat->addHP(-dmg);
	return dmg;
}


int Assassin::attack(Dragon *dragon, int dmg)
{
	dragon->addHP(-dmg);
	return dmg;
}


void Assassin::attackedBy(Enemy *e)
{
	int i = rand() % 100;
	ofstream out;
	out.open("action.txt", ios::app);
	if (i >= this->DodgeChance) {
		out << "    " << e->getDesc() << " dealt " << e->attack(this, dmg(e->Atk, Def)) << " damage to " << getName() << " (" << HP << " HP). ";
		if (isDead()){
			out << "    " << getName() << " has been slain. " << endl;
		}
		else out << endl;
	}else{
		int n = rand() % 3;
		out << "    ";
		if(n == 0){
			out << getName() << " skillfully dodged " << e->getDesc() << "'s attack. " << endl;
		}else if(n == 1){
			out << getName() << " nimbly sidestepped " << e->getDesc() << "'s attack. " << endl;
		}else if(n == 2){
			out << getName() << " is moving too fast. " << e->getDesc() << "'s attack missed. " << endl;
		}
	}
	out.close();
}

Assassin::~Assassin(){}
