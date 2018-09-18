#include "rat.h"
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

Rat::Rat()
{
	HP = 1;
	Atk = 1;
	Def = 1;
	if (rand() % 2 == 0) Gold = 1;
	else Gold = 2;
	DodgeChance = 0;
	setMaxHP(1);
	setHostile(true);
	setDesc("Rat");
	setChar('R');
}

int Rat::attack(Shade *shade, int dmg)
{
	shade->addHP(-dmg);
	return dmg;
}


int Rat::attack(Troll *troll, int dmg)
{
	troll->addHP(-dmg);
	return dmg;
}


int Rat::attack(Drow *drow, int dmg)
{
	drow->addHP(-dmg);
	return dmg;
}


int Rat::attack(Vampire *vampire, int dmg)
{
	vampire->addHP(-dmg);
	return dmg;
}


int Rat::attack(Goblin *goblin, int dmg)
{
	goblin->addHP(-dmg);
	return dmg;
}


int Rat::attack(Valkyrie *valkyrie, int dmg)
{
	valkyrie->addHP(-dmg);
	return dmg;
}

int Rat::attack(Assassin *assassin, int dmg)
{
	assassin->addHP(-dmg);
	return dmg;
}

int Rat::attack(Berserker *berserker, int dmg)
{
	berserker->addHP(-dmg);
	return dmg;
}

int Rat::attack(God *nomair, int dmg)
{
	nomair->addHP(-dmg);
	return dmg;
}


void Rat::attackedBy(Player *p)
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
Rat::~Rat(){}
