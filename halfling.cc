#include <fstream>
#include "halfling.h"
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

Halfling::Halfling()
{
	HP = 100;
	Atk = 15;
	Def = 20;
	if (rand() % 2 == 0) Gold = 1;
	else Gold = 2;
	DodgeChance = 50;
	setMaxHP(100);
	setHostile(true);
	setDesc("Halfling");
	setChar('L');
}


int Halfling::attack(Shade *shade, int dmg)
{
	shade->addHP(-dmg);
	return dmg;
}


int Halfling::attack(Troll *troll, int dmg)
{
	troll->addHP(-dmg);
	return dmg;
}


int Halfling::attack(Drow *drow, int dmg)
{
	drow->addHP(-dmg);
	return dmg;
}


int Halfling::attack(Vampire *vampire, int dmg)
{
	vampire->addHP(-dmg);
	return dmg;
}


int Halfling::attack(Goblin *goblin, int dmg)
{
	goblin->addHP(-dmg);
	return dmg;
}


int Halfling::attack(Valkyrie *valkyrie, int dmg)
{
	valkyrie->addHP(-dmg);
	return dmg;
}


int Halfling::attack(Assassin *assassin, int dmg)
{
	assassin->addHP(-dmg);
	return dmg;
}

int Halfling::attack(Berserker *berserker, int dmg)
{
	berserker->addHP(-dmg);
	return dmg;
}

int Halfling::attack(God *nomair, int dmg)
{
	nomair->addHP(-dmg);
	return dmg;
}


void Halfling::attackedBy(Player *p)
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

Halfling::~Halfling(){}
