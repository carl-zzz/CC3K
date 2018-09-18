#include "elf.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "shade.h"
#include "troll.h"
#include "drow.h"
#include "vampire.h"
#include "goblin.h"
#include "player.h"
#include "valkyrie.h"
#include "assassin.h"
#include "berserker.h"
#include "god.h"
using namespace std;

Elf::Elf()
{
	HP = 140;
	Atk = 30;
	Def = 10;
	if (rand() % 2 == 0) Gold = 1;
	else Gold = 2;
	DodgeChance = 0;
	setMaxHP(140);
	setHostile(true);
	setDesc("Elf");
	setChar('E');
}


int Elf::attack(Shade *shade, int dmg)
{
	shade->addHP(-2*dmg);
	return 2*dmg;
}


int Elf::attack(Troll *troll, int dmg)
{
	troll->addHP(-2*dmg);
	return 2*dmg;
}


int Elf::attack(Drow *drow, int dmg)
{
	drow->addHP(-2*dmg);
	return 2*dmg;
}


int Elf::attack(Vampire *vampire, int dmg)
{
	vampire->addHP(-2*dmg);
	return 2*dmg;
}


int Elf::attack(Goblin *goblin, int dmg)
{
	goblin->addHP(-2*dmg);
	return 2*dmg;
}


int Elf::attack(Valkyrie *valkyrie, int dmg)
{
	valkyrie->addHP(-dmg);
	return dmg;
}

int Elf::attack(Assassin *assassin, int dmg)
{
	assassin->addHP(-dmg);
	return dmg;
}

int Elf::attack(Berserker *berserker, int dmg)
{
	berserker->addHP(-dmg);
	return dmg;
}

int Elf::attack(God *nomair, int dmg)
{
	nomair->addHP(-dmg);
	return dmg;
}


void Elf::attackedBy(Player *p)
{
	int i = rand() % 100;
	ofstream out;
	out.open("action.txt", ios::app);
	if(dynamic_cast<God *>(p)){
		p->attack(this, 999);
		return;
	}
	out << "    ";
	if (i >= DodgeChance) {
		out << p->getName() << " dealt " << p->attack(this, dmg(p->Atk, Def)) << " damage to " << getDesc() << " (" << HP << " HP). " << endl;
		if (isDead()) {
			p->addGold(dropGold());
			out << "    " << p->getName() << " has slain " << getDesc() << ". " << endl;
		}
	}else {
		out << p->getName() << " missed its attack. " << endl;
	}
	out.close();
}
Elf::~Elf(){}
